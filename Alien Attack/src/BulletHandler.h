//
//  BulletHandler.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 28/03/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef __SDL_Game_Programming_Book__BulletHandler__
#define __SDL_Game_Programming_Book__BulletHandler__

#include <iostream>
#include <vector>
#include "Bullet.h"

class BulletHandler
{
public:
    
    static BulletHandler* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new BulletHandler();
            return s_pInstance;
        }
        return s_pInstance;
    }
    
    void addPlayerBullet(int x, int y, int width, int height, std::string textureID, int numFrames, Vector2D heading);
    void addEnemyBullet(int x, int y, int width, int height, std::string textureID, int numFrames, Vector2D heading);
    
    void updateBullets();
    void drawBullets();
    
    void clearBullets();
    
    const std::vector<PlayerBullet*> getPlayerBullets() { return m_playerBullets; }
    const std::vector<EnemyBullet*> getEnemyBullets() { return m_enemyBullets; }
    
private:
    
    BulletHandler();
    ~BulletHandler();
    
    BulletHandler(const BulletHandler&);
    BulletHandler& operator=(const BulletHandler&);
    
    static BulletHandler* s_pInstance;
    
    // in play bullets
    std::vector<PlayerBullet*> m_playerBullets;
    std::vector<EnemyBullet*> m_enemyBullets;
};

typedef BulletHandler TheBulletHandler;

#endif /* defined(__SDL_Game_Programming_Book__BulletHandler__) */
