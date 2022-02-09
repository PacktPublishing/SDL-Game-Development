//
//  BulletHandler.cpp
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 28/03/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#include "BulletHandler.h"
#include "Game.h"


BulletHandler* BulletHandler::s_pInstance = new BulletHandler();

BulletHandler::BulletHandler()
{
}

void BulletHandler::addPlayerBullet(int x, int y, int width, int height, std::string textureID, int numFrames, Vector2D heading)
{
    PlayerBullet* pPlayerBullet = new PlayerBullet();
    pPlayerBullet->load(std::unique_ptr<LoaderParams>(new LoaderParams(x, y, width, height, textureID, numFrames)), heading);
    
    m_playerBullets.push_back(pPlayerBullet);
}

void BulletHandler::addEnemyBullet(int x, int y, int width, int height, std::string textureID, int numFrames, Vector2D heading)
{
    EnemyBullet* pEnemyBullet = new EnemyBullet();
    pEnemyBullet->load(std::unique_ptr<LoaderParams>(new LoaderParams(x, y, width, height, textureID, numFrames)), heading);
    
    m_enemyBullets.push_back(pEnemyBullet);
}

void BulletHandler::clearBullets()
{
    m_enemyBullets.clear();
    m_playerBullets.clear();
}

void BulletHandler::updateBullets()
{
    for (std::vector<PlayerBullet*>::iterator p_it = m_playerBullets.begin(); p_it != m_playerBullets.end();)
    {
        if((*p_it)->getPosition().getX() < 0 || (*p_it)->getPosition().getX() > TheGame::Instance()->getGameWidth()
           || (*p_it)->getPosition().getY() < 0 || (*p_it)->getPosition().getY() > TheGame::Instance()->getGameHeight() || (*p_it)->dead())
        {
            delete * p_it;
            p_it = m_playerBullets.erase(p_it);
        }
        else
        {
            (*p_it)->update();
            ++p_it;
        }
    }
    
    for (std::vector<EnemyBullet*>::iterator e_it = m_enemyBullets.begin(); e_it != m_enemyBullets.end();)
    {
        if((*e_it)->getPosition().getX() < 0 || (*e_it)->getPosition().getX() > TheGame::Instance()->getGameWidth()
           || (*e_it)->getPosition().getY() < 0 || (*e_it)->getPosition().getY() > TheGame::Instance()->getGameHeight() || (*e_it)->dead())
        {
            delete * e_it;
            e_it = m_enemyBullets.erase(e_it);
        }
        else
        {
            (*e_it)->update();
            ++e_it;
        }
    }
}

void BulletHandler::drawBullets()
{
    for (int p = 0; p < m_playerBullets.size(); p++)
    {
        m_playerBullets[p]->draw();
    }
    
    for (int e = 0; e < m_enemyBullets.size(); e++)
    {
        m_enemyBullets[e]->draw();
    }
}