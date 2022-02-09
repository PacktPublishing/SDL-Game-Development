//
//  Vector2D.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 27/01/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef __SDL_Game_Programming_Book__Vector2D__
#define __SDL_Game_Programming_Book__Vector2D__

#include <iostream>
#include <math.h>

class Vector2D
{
public:
    Vector2D()
    {
        m_x = 0;
        m_y = 0;
    }
    
    Vector2D(float x, float y): m_x(x), m_y(y) {}
    
    const float getX() { return m_x; }
    const float getY() { return m_y; }
    
    void setX(float x) { m_x = x; }
    void setY(float y) { m_y = y; }
    
    int length() { return sqrt(m_x * m_x + m_y * m_y); }
    
    Vector2D operator+(const Vector2D& v2) const { return Vector2D(m_x + v2.m_x, m_y + v2.m_y); }
    friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
    {
        v1.m_x += v2.m_x;
        v1.m_y += v2.m_y;
        
        return v1;
    }
    
    Vector2D operator-(const Vector2D& v2) const { return Vector2D(m_x - v2.m_x, m_y - v2.m_y); }
    friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
    {
        v1.m_x -= v2.m_x;
        v1.m_y -= v2.m_y;
        
        return v1;
    }

    
    Vector2D operator*(float scalar)
    {
        return Vector2D(m_x * scalar, m_y * scalar);
    }
    
    Vector2D& operator*=(float scalar)
    {
        m_x *= scalar;
        m_y *= scalar;
        
        return *this;
    }
    
    Vector2D operator/(float scalar)
    {
        return Vector2D(m_x / scalar, m_y / scalar);
    }
    
    Vector2D& operator/=(float scalar)
    {
        m_x /= scalar;
        m_y /= scalar;
        
        return *this;
    }

    
    void normalize()
    {
        int l = length();
        if ( l > 0)
        {
            (*this) *= 1 / l;
        }
    }
    
    float m_x;
    float m_y;
};

#endif /* defined(__SDL_Game_Programming_Book__Vector2D__) */
