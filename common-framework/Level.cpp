//
//  Map.cpp
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 09/03/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#include "Level.h"
#include "TextureManager.h"
#include "Game.h"
#include "Layer.h"
#include "TileLayer.h"
#include <math.h>
#include <iostream>

Level::Level()
{
}

Level::~Level()
{
    for(int i = 0; i < m_layers.size(); i++)
    {
        delete m_layers[i];
    }
    
    m_layers.clear();
}

void Level::render()
{
    for(int i = 0; i < m_layers.size(); i++)
    {
        m_layers[i]->render();
    }
}

void Level::update()
{
    
    for(int i = 0; i < m_layers.size(); i++)
    {
        m_layers[i]->update(this);
    }
}