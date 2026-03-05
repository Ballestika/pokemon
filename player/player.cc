#include <esat/window.h>
#include <esat/draw.h>
#include <esat/sprite.h>
#include <esat/input.h>
#include <esat/time.h>
#include <stdio.h>
#include "structs.h"
#include <stdlib.h>


void MoveUp(Player** player)
{
    (*player)->pos = {(*player)->pos.x, (*player)->pos.y - 1};
    (*player)->sprite = ((*player)->moves+1)->sprite;
}

void MoveDown(Player** player)
{
    (*player)->pos = {(*player)->pos.x, (*player)->pos.y + 1};
    (*player)->sprite = ((*player)->moves+2)->sprite;
}

void MoveLeft(Player** player)
{
    (*player)->pos = {(*player)->pos.x - 1, (*player)->pos.y};
    (*player)->sprite = ((*player)->moves+3)->sprite;
}

void MoveRight(Player** player)
{
    (*player)->pos = {(*player)->pos.x + 1, (*player)->pos.y};
    (*player)->sprite = ((*player)->moves)->sprite;
}

void UpdatePlayer(Player* player)
{
    if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Up))
    {
        player->dir = UP;
        MoveUp(&player);
    }
    if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Down))
    {
        player->dir = DOWN;
        MoveDown(&player);
    }
    if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Left))
    {
        player->dir = LEFT;
        MoveLeft(&player);
    }
    if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Right))
    {
        player->dir = RIGHT;
        MoveRight(&player);
    }
}

void PaintPlayer(Player player)
{
    esat::DrawSprite((player.moves+1)->sprite, player.pos.x, player.pos.y);
}

void LoadPlayerSprites(Moves **moves)
{
    esat::SpriteHandle sheet = esat::SpriteFromFile("C:/Users/ballestaca/Desarrollo/pokemon/pokemon/assets/player.png");
    for(int i = 0; i<4; i++)
    {   
        switch(i)
        {
            case 0:
                (*moves+i)->dir = RIGHT;
                break;
            case 1:
                (*moves+i)->dir = UP;
                break;
            case 2:
                (*moves+i)->dir = DOWN;
                break;
            case 3:
                (*moves+i)->dir = LEFT;
                break;
        }
        for(int j = 0; j<3; j++)
        {
            *((*moves+i)->sprite+j) = esat::SubSprite(sheet, i*19, j*26, 19, 26);
        }
    }
}

void LoadPlayer(Player* player)
{
    player->pos = {10 * 16, 10 * 16};
    player->moves = (Moves*) malloc(4 * sizeof(Moves));
    for(int i = 0; i<4; i++)
    {
        (player->moves+i)->sprite = (esat::SpriteHandle*) malloc(3 * sizeof(esat::SpriteHandle));
    }
    player->sprite = esat::SpriteFromFile("C:/Users/ballestaca/Desarrollo/pokemon/pokemon/assets/pokeball.png");
    LoadPlayerSprites(&(player->moves));
}