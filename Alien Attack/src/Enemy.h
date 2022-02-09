//
//  Enemy.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 19/01/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef __SDL_Game_Programming_Book__Enemy__
#define __SDL_Game_Programming_Book__Enemy__

#include <iostream>
#include "ShooterObject.h"

// Enemy base class
class Enemy : public ShooterObject
{
public:
    
    virtual std::string type() { return "Enemy"; }
    
protected:
    
    int m_health;
    
    Enemy() : ShooterObject() {}
    virtual ~Enemy() {}
};

#endif /* defined(__SDL_Game_Programming_Book__Enemy__) */
