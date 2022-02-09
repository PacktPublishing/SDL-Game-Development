//
//  Bullet.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 27/03/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef SDL_Game_Programming_Book_Bullet_h
#define SDL_Game_Programming_Book_Bullet_h

#include "ShooterObject.h"
#include "TextureManager.h"
#include "Game.h"
#include <iostream>

class PlayerBullet : public ShooterObject
{
public:
    PlayerBullet() : ShooterObject()
    {
        m_dyingTime = 5;
    }
    
    virtual ~PlayerBullet() {}
    
    virtual std::string type() { return "PlayerBullet"; }
    
    virtual void load(std::unique_ptr<LoaderParams> pParams, Vector2D heading)
    {
        ShooterObject::load(std::move(pParams));
        m_heading = heading;
    }
    
    
    
    virtual void draw()
    {
        ShooterObject::draw();
    }
    
    virtual void collision()
    {
        m_textureID = "smallexplosion";
        m_currentFrame = 0;
        m_numFrames = 2;
        m_width = 20;
        m_height = 20;
        m_bDying = true;
    }
    
    virtual void update()
    {
        if(!m_bDying)
        {
            m_velocity.setX(m_heading.getX());
            m_velocity.setY(m_heading.getY());
            
            ShooterObject::update();
        }
        else
        {
            m_velocity.setX(0);
            m_velocity.setY(0);
            doDyingAnimation();
        }
    }
    
    virtual void clean()
    {
        ShooterObject::clean();
    }
    
private:
    
    Vector2D m_heading;
};

class EnemyBullet : public PlayerBullet
{
public:
    EnemyBullet() : PlayerBullet()
    {
    }
    
    virtual ~EnemyBullet() {}
    
    virtual std::string type() { return "EnemyBullet"; }
};

#endif
