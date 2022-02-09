//
//  MenuObject.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 10/02/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef __SDL_Game_Programming_Book__MenuObject__
#define __SDL_Game_Programming_Book__MenuObject__

#include "PlatformerObject.h"
#include "GameObjectFactory.h"

class MenuButton : public PlatformerObject
{
public:
    
    MenuButton();
    
    virtual ~MenuButton() {}
    
    virtual void load(std::unique_ptr<LoaderParams> const &pParams);
    
    virtual void draw();
    virtual void update();
    virtual void clean();
    
    void setCallback(void(*callback)()) { m_callback = callback;}
    int getCallbackID() { return m_callbackID; }

private:
    
    enum button_state
    {
        MOUSE_OUT = 0,
        MOUSE_OVER = 1,
        CLICKED = 2
    };
    
    bool m_bReleased;
    
    int m_callbackID;
    
    void (*m_callback)();
};

class MenuButtonCreator : public BaseCreator
{
    GameObject* createGameObject() const
    {
        return new MenuButton();
    }
};


#endif /* defined(__SDL_Game_Programming_Book__MenuObject__) */
