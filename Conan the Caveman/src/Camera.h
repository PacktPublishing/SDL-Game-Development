//
//  Camera.h
//  SDLPlatformer
//
//  Created by shaun mitchell on 13/04/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef __SDLPlatformer__Camera__
#define __SDLPlatformer__Camera__

#include <iostream>
#include "Vector2D.h"

class Camera
{
public:
    
    static Camera* Instance()
    {
        if(s_pCamera == 0)
        {
            s_pCamera = new Camera();
        }
        
        return s_pCamera;
    }
    
    void update(Vector2D velocity);
    
    void setTarget(Vector2D* target) { m_pTarget = target; }
    void setPosition(const Vector2D& position) { m_position = position; }
    
    const Vector2D getPosition() const;
    
    
    
private:
    
    Camera();
    ~Camera();
    
    // the camera's target
    Vector2D* m_pTarget;
    
    // the camera's position
    Vector2D m_position;
    
    static Camera* s_pCamera;
};

typedef Camera TheCamera;

#endif /* defined(__SDLPlatformer__Camera__) */
