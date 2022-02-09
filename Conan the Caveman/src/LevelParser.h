//
//  LevelParser.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 10/03/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef __SDL_Game_Programming_Book__LevelParser__
#define __SDL_Game_Programming_Book__LevelParser__

#include <iostream>
#include <vector>
#include "tinyxml.h"

class Level;
struct Tileset;
class Layer;
class TileLayer;

class LevelParser
{
public:
    
    Level* parseLevel(const char* stateFile);
    
private:
    
    void parseTextures(TiXmlElement* pTextureRoot);
    void parseTilesets(TiXmlElement* pTilesetRoot, std::vector<Tileset>* pTilesets);
    void parseObjectLayer(TiXmlElement* pObjectElement, std::vector<Layer*> *pLayers, Level* pLevel);
    void parseTileLayer(TiXmlElement* pTileElement, std::vector<Layer*> *pLayers, const std::vector<Tileset>* pTilesets, std::vector<TileLayer*> *pCollisionLayers);
    
    int m_tileSize;
    int m_width;
    int m_height;
};

#endif /* defined(__SDL_Game_Programming_Book__LevelParser__) */
