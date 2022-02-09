//
//  PlayState.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 09/02/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef SDL_Game_Programming_Book_PlayState_h
#define SDL_Game_Programming_Book_PlayState_h

#include "GameState.h"
#include "CollisionManager.h"
#include "Level.h"
#include <vector>

class GameObject;
class SDLGameObject;
class Level;

class PlayState : public GameState
{
public:
    
    virtual ~PlayState() { delete pLevel; }
    
    virtual void update();
    virtual void render();
    
    virtual bool onEnter();
    virtual bool onExit();
    
    virtual std::string getStateID() const { return s_playID; }
    
private:
    
    static const std::string s_playID;
    
    CollisionManager m_collisionManager;
    
    std::vector<GameObject*> m_gameObjects;
    
    Level* pLevel;
};


#endif
