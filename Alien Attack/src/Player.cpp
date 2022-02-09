//
//  Player.cpp
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 12/01/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#include "Player.h"
#include "Game.h"
#include "InputHandler.h"
#include "TileLayer.h"
#include "BulletHandler.h"
#include "SoundManager.h"

using namespace std;

Player::Player() :  ShooterObject(),
m_invulnerable(false),
m_invulnerableTime(200),
m_invulnerableCounter(0)
{
}

void Player::collision()
{
    // if the player is not invulnerable then set to dying and change values for death animation tile sheet
    if(!m_invulnerable && !TheGame::Instance()->getLevelComplete())
    {
        m_textureID = "largeexplosion";
        m_currentFrame = 0;
        m_numFrames = 9;
        m_width = 60;
        m_height = 60;
        m_bDying = true;
    }
}

void Player::load(std::unique_ptr<LoaderParams> const &pParams)
{
    // inherited load function
    ShooterObject::load(std::move(pParams));
    
    // can set up the players inherited values here
    
    // set up bullets
    m_bulletFiringSpeed = 13;
    m_moveSpeed = 3;
    
    // we want to be able to fire instantly
    m_bulletCounter = m_bulletFiringSpeed;
    
    // time it takes for death explosion
    m_dyingTime = 100;
}

void Player::draw()
{
    // player has no special drawing requirements
    ShooterObject::draw();
}

void Player::handleAnimation()
{
    // if the player is invulnerable we can flash its alpha to let people know
    if(m_invulnerable)
    {
        // invulnerability is finished, set values back
        if(m_invulnerableCounter == m_invulnerableTime)
        {
            m_invulnerable = false;
            m_invulnerableCounter = 0;
            m_alpha = 255;
        }
        else // otherwise, flash the alpha on and off
        {
            if(m_alpha == 255)
            {
                m_alpha = 0;
            }
            else
            {
                m_alpha = 255;
            }
        }
        
        // increment our counter
        m_invulnerableCounter++;
    }
    
    // if the player is not dead then we can change the angle with the velocity to give the impression of a moving helicopter
    if(!m_bDead)
    {
        if(m_velocity.getX() < 0)
        {
            m_angle = -10.0;
        }
        else if(m_velocity.getX() > 0)
        {
            m_angle = 10.0;
        }
        else
        {
            m_angle = 0.0;
        }
    }
    
    // our standard animation code - for helicopter propellors
    m_currentFrame = int(((SDL_GetTicks() / (100)) % m_numFrames));
}

void Player::update()
{
    if(TheGame::Instance()->getLevelComplete())
    {
        if(m_position.getX() >= TheGame::Instance()->getGameWidth())
        {
            TheGame::Instance()->setCurrentLevel(TheGame::Instance()->getCurrentLevel() + 1);
        }
        else
        {
            m_velocity.setY(0);
            m_velocity.setX(3);
            ShooterObject::update();
            handleAnimation();
        }
    }
    else
    {
        // if the player is not doing its death animation then update it normally
        if(!m_bDying)
        {
            // reset velocity
            m_velocity.setX(0);
            m_velocity.setY(0);
            
            // get input
            handleInput();
            
            // do normal position += velocity update
            ShooterObject::update();
            
            // update the animation
            handleAnimation();
        }
        else // if the player is doing the death animation
        {
            m_currentFrame = int(((SDL_GetTicks() / (100)) % m_numFrames));
            
            // if the death animation has completed
            if(m_dyingCounter == m_dyingTime)
            {
                // ressurect the player
                ressurect();
            }
            m_dyingCounter++;
        }
    }
}

void Player::ressurect()
{
    TheGame::Instance()->setPlayerLives(TheGame::Instance()->getPlayerLives() - 1);
    
    m_position.setX(10);
    m_position.setY(200);
    m_bDying = false;
    
    m_textureID = "player";
    
    m_currentFrame = 0;
    m_numFrames = 5;
    m_width = 101;
    m_height = 46;
    
    m_dyingCounter = 0;
    m_invulnerable = true;
}

void Player::clean()
{
    ShooterObject::clean();
}

void Player::handleInput()
{
    if(!m_bDead)
    {
        // handle keys
        if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) && m_position.getY() > 0)
        {
            m_velocity.setY(-m_moveSpeed);
        }
        else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN) && (m_position.getY() + m_height) < TheGame::Instance()->getGameHeight() - 10)
        {
            m_velocity.setY(m_moveSpeed);
        }
        
        if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && m_position.getX() > 0)
        {
            m_velocity.setX(-m_moveSpeed);
        }
        else if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT) && (m_position.getX() + m_width) < TheGame::Instance()->getGameWidth())
        {
            m_velocity.setX(m_moveSpeed);
        }
        
        if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
        {
            if(m_bulletCounter == m_bulletFiringSpeed)
            {
                TheSoundManager::Instance()->playSound("shoot", 0);
                TheBulletHandler::Instance()->addPlayerBullet(m_position.getX() + 90, m_position.getY() + 12, 11, 11, "bullet1", 1, Vector2D(10,0));
                m_bulletCounter = 0;
            }
            
            m_bulletCounter++;
        }
        else
        {
            m_bulletCounter = m_bulletFiringSpeed;
        }
        // */
        
        /* handle joysticks /
        if(TheInputHandler::Instance()->joysticksInitialised())
        {
            if(TheInputHandler::Instance()->getButtonState(0, 2))
            {
                if(m_bulletCounter == m_bulletFiringSpeed)
                {
                    TheSoundManager::Instance()->playSound("shoot", 0);
                    TheBulletHandler::Instance()->addPlayerBullet(m_position.getX() + 90, m_position.getY() + 12, 11, 11, "bullet1", 1, Vector2D(10,0));
                    m_bulletCounter = 0;
                }
                
                m_bulletCounter++;
            }
            else
            {
                m_bulletCounter = m_bulletFiringSpeed;
            }
            
            if((TheInputHandler::Instance()->getAxisX(0, 1) > 0 && (m_position.getX() + m_width) < TheGame::Instance()->getGameWidth()) || (TheInputHandler::Instance()->getAxisX(0, 1) < 0 && m_position.getX() > 0))
            {
                m_velocity.setX(m_moveSpeed * TheInputHandler::Instance()->getAxisX(0, 1));
            }
            
            if((TheInputHandler::Instance()->getAxisY(0, 1) > 0 && (m_position.getY() + m_height) < TheGame::Instance()->getGameHeight() - 10 ) || (TheInputHandler::Instance()->getAxisY(0, 1) < 0 && m_position.getY() > 0))
            {
                m_velocity.setY(m_moveSpeed * TheInputHandler::Instance()->getAxisY(0, 1));
            }
        }
        //*/
        
    }
}