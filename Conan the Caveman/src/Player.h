//
//  Player.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 12/01/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef __SDL_Game_Programming_Book__Player__
#define __SDL_Game_Programming_Book__Player__

#include <iostream>
#include <vector>
#include "PlatformerObject.h"
#include "GameObjectFactory.h"

class Player : public PlatformerObject
{
public:
    
    Player();
    virtual ~Player() {}
    
    virtual void load(std::unique_ptr<LoaderParams> const &pParams);
    
    virtual void draw();
    virtual void update();
    virtual void clean();
    
    virtual void collision();
    
    virtual std::string type() { return "Player"; }
    
private:
    
    // bring the player back if there are lives left
    void ressurect();
    
    // handle any input from the keyboard, mouse, or joystick
    void handleInput();
    
    // handle any animation for the player
    void handleAnimation();
    
    void handleMovement(Vector2D velocity);

    // player can be invulnerable for a time
    int m_bInvulnerable;
    int m_invulnerableTime;
    int m_invulnerableCounter;
    
    bool m_bPressedJump;
};

// for the factory
class PlayerCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new Player();
    }
};


#endif /* defined(__SDL_Game_Programming_Book__Player__) */
