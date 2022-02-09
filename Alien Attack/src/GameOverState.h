//
//  GameOverState.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 17/02/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef __SDL_Game_Programming_Book__GameOverState__
#define __SDL_Game_Programming_Book__GameOverState__

#include <iostream>
#include <vector>
#include "MenuState.h"

class GameObject;

class GameOverState : public MenuState
{
public:
    
    virtual ~GameOverState() {}
    
    virtual void update();
    virtual void render();
    
    virtual bool onEnter();
    virtual bool onExit();
    
    virtual std::string getStateID() const { return s_gameOverID; }
    
    virtual void setCallbacks(const std::vector<Callback>& callbacks);
    
private:
    
    static void s_gameOverToMain();
    static void s_restartPlay();
    
    static const std::string s_gameOverID;
    
    std::vector<GameObject*> m_gameObjects;
};

#endif /* defined(__SDL_Game_Programming_Book__GameOverState__) */
