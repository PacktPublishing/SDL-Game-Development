//
//  Turret.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 29/03/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef __SDL_Game_Programming_Book__Turret__
#define __SDL_Game_Programming_Book__Turret__

#include <iostream>
#include "GameObjectFactory.h"
#include "BulletHandler.h"
#include "SoundManager.h"
#include <math.h>
#include "Enemy.h"

class Turret : public Enemy
{
public:
    
    Turret()
    {
        m_dyingTime = 1000;
        m_health = 15;
        m_bulletFiringSpeed = 50;
    }
    
    virtual ~Turret() {}

    virtual void collision()
    {
        m_health -= 1;
        
        if(m_health == 0)
        {
            if(!m_bPlayedDeathSound)
            {
                TheSoundManager::Instance()->playSound("explode", 0);
                
                m_textureID = "largeexplosion";
                m_currentFrame = 0;
                m_numFrames = 9;
                m_width = 60;
                m_height = 60;
                m_bDying = true;
            }
            
        }
    }
    
    virtual void update()
    {
        if(!m_bDying)
        {
            // we want to scroll this object with the rest
            scroll(TheGame::Instance()->getScrollSpeed());
            
            if(m_bulletCounter == m_bulletFiringSpeed)
            {
                TheBulletHandler::Instance()->addEnemyBullet(m_position.getX(), m_position.getY(), 16, 16, "bullet2", 1, Vector2D(-3, -3));
                TheBulletHandler::Instance()->addEnemyBullet(m_position.getX() + 20, m_position.getY(), 16, 16, "bullet2", 1, Vector2D(0, -3));
                TheBulletHandler::Instance()->addEnemyBullet(m_position.getX() + 40, m_position.getY(), 16, 16, "bullet2", 1, Vector2D(3, -3));
                m_bulletCounter = 0;
            }
            
            m_bulletCounter++;
        }
        else
        {
            scroll(TheGame::Instance()->getScrollSpeed());
            doDyingAnimation();
        }
        
    }

};

class TurretCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new Turret();
    }
};


#endif /* defined(__SDL_Game_Programming_Book__Turret__) */
