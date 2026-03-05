#include <esat/window.h>
#include <esat/draw.h>
#include <esat/sprite.h>
#include <esat/input.h>
#include <esat/time.h>
#include <stdio.h>
#include "structs.h"
#include <stdlib.h>

void LoadPlayerSprites(esat::SpriteHandle **sprites)
{
    esat::SubSprite(esat::SpriteFromFile("C:/Users/ballestaca/Desarrollo/pokemon/pokemon/assets/red.png"), 0, 0, );
}

void LoadPlayer(Player* player)
{
    player->pos = {10 * 16, 10 * 16};
    LoadPlayerSprites(&(player->sprite));
}