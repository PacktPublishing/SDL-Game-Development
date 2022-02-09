//
//  CollisionManager.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 28/03/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef __SDL_Game_Programming_Book__CollisionManager__
#define __SDL_Game_Programming_Book__CollisionManager__

#include <iostream>
#include <vector>

class Player;
class GameObject;

class CollisionManager
{
public:
    
    void checkPlayerEnemyCollision(Player* pPlayer, const std::vector<GameObject*> &objects);
};

#endif /* defined(__SDL_Game_Programming_Book__CollisionManager__) */
