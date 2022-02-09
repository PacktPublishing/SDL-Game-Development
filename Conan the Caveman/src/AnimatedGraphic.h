//
//  AnimatedGraphic.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 17/02/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef __SDL_Game_Programming_Book__AnimatedGraphic__
#define __SDL_Game_Programming_Book__AnimatedGraphic__

#include <iostream>
#include "GameObjectFactory.h"
#include "PlatformerObject.h"

class AnimatedGraphic : public PlatformerObject
{
public:
    
    AnimatedGraphic();
    virtual ~AnimatedGraphic() {}
    
    virtual void load(std::unique_ptr<LoaderParams> const &pParams);
    
    virtual void draw();
    virtual void update();
    virtual void clean();
    
private:
    
    int m_animSpeed;
    int m_frameCount;
};

class AnimatedGraphicCreator : public BaseCreator
{
public:
    
    virtual GameObject* createGameObject() const
    {
        return new AnimatedGraphic();
    }
};

#endif /* defined(__SDL_Game_Programming_Book__AnimatedGraphic__) */
