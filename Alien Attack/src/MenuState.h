//
//  MenuState.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 26/02/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef SDL_Game_Programming_Book_MenuState_h
#define SDL_Game_Programming_Book_MenuState_h

#include "GameState.h"

class MenuState : public GameState
{
public:
    
    virtual ~MenuState() {}
    
protected:
    
    typedef void(*Callback)();
    virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;
    
    std::vector<Callback> m_callbacks;
};


#endif
