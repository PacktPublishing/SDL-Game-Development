////
////  MapLoader.cpp
////  SDL Game Programming Book
////
////  Created by shaun mitchell on 09/03/2013.
////  Copyright (c) 2013 shaun mitchell. All rights reserved.
////
//
//#include <vector>
//#include "MapLoader.h"
//#include "base64.h"
//#include "zlib.h"
//#include "TextureManager.h"
//#include "Game.h"
//
//using namespace std;
//
//Map* MapLoader::loadMap(const char *mapFile)
//{
//    vector<int> decoded;
//    // create a document and load the map xml
//    TiXmlDocument mapDocument;
//    mapDocument.LoadFile(mapFile);
//    
//    Map* pMap = new Map();
//    
//    TiXmlElement* pRoot = mapDocument.RootElement();
//    
//    // print the values
//    std::cout << "Loading map:\n" << "Version: " << pRoot->Attribute("version") << "\n";
//    std::cout << "Width:" << pRoot->Attribute("width") << " - Height:" << pRoot->Attribute("height") << "\n";
//    std::cout << "Tile Width:" << pRoot->Attribute("tilewidth") << " - Tile Height:" << pRoot->Attribute("tileheight") << "\n";
//    
//    //TiXmlElement* pTilesetRoot = 0;
//    for(TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
//    {
//        if(e->Value() == string("tileset"))
//        {
//            parseTextures(e, pMap->getTilesets());
//            
//        }
//    }
//    
//    //parseTextures(pTilesetRoot, pMap->getTilesets());
//    
//    TiXmlElement* pLayersRoot = 0;
//    for(TiXmlElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
//    {
//        if(e->Value() == string("layer"))
//        {
//            pLayersRoot = e;
//            
//        }
//    }
//    
//    TiXmlElement* pDataRoot = 0;
//    for(TiXmlElement* e = pLayersRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
//    {
//        if(e->Value() == string("data"))
//        {
//            pDataRoot = e;
//        }
//    }
//    
//    for(TiXmlNode* e = pDataRoot->FirstChild(); e != NULL; e = e->NextSibling())
//    {
//        TiXmlText* text = e->ToText();
//        string t = text->Value();
//        decoded = base64_decode(t);
//    }
//    
//    parseGridIds(decoded, pMap->getGridIDs());
//    
//    return pMap;
//}
//
//void MapLoader::parseTextures(TiXmlElement* pTilesetRoot, Map::Tilesets *pTextureIDs)
//{
//    Tileset tileset;
//    pTilesetRoot->Attribute("firstgid", &tileset.firstGridID);
//    pTilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
//    pTilesetRoot->Attribute("tileheight", &tileset.tileHeight);
//    pTilesetRoot->Attribute("spacing", &tileset.spacing);
//    pTilesetRoot->Attribute("margin", &tileset.margin);
//    tileset.name = pTilesetRoot->Attribute("name");
//    
//    
//    TheTextureManager::Instance()->load(pTilesetRoot->FirstChildElement()->Attribute("source"), pTilesetRoot->Attribute("name"), TheGame::Instance()->getRenderer());
//    
//    pTextureIDs->push_back(tileset);
//    
//}
//
//void MapLoader::parseGridIds(std::vector<int> layerData, Map::GridIDs *pGridIds)
//{
//    for(int i = 0; i < layerData.size(); i += 4)
//    {
//        pGridIds->push_back(layerData[i] | layerData[i + 1] << 8 | layerData[i + 2] << 16 | layerData[i + 3] << 24);
//    }
//}
