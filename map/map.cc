#include <esat/window.h>
#include <esat/draw.h>
#include <esat/sprite.h>
#include <esat/input.h>
#include <esat/time.h>
#include <stdio.h>
#include "structs.h"
#include <stdlib.h>

FILE *f;

void LoadTiles(Tile** tiles, int ammount)
{
    if((f=fopen("C:/Users/ballestaca/pokemon/pokemon/map/pokemon.txt","r"))==NULL)
    {
        printf("ERROR");
    }else
    {
        int row = 0;
        int col = 0;
        for(int i = 0; i<ammount && !feof(f); i++)
        {   
            char num = getc(f);
            switch(atoi(&num))
            {
                case 0:
                    ((*tiles+i)->sprite) = esat::SpriteFromFile("C:/Users/ballestaca/pokemon/pokemon/assets/grass.png");
                    break;
                case 1:
                    ((*tiles+i)->sprite) = esat::SpriteFromFile("C:/Users/ballestaca/pokemon/pokemon/assets/grass.png");
                    break;
                default:
                    ((*tiles+i)->sprite) = esat::SpriteFromFile("C:/Users/ballestaca/pokemon/pokemon/assets/grass.png");
                    break;
            }

            ((*tiles+i)->pos) = {(float) col * 16, (float) row * 16};

            col++;
            if(col>=(800/16))
            {
                col = 0;
                row++;
            }
        }
    }
}

void PaintMap(Map map)
{
    Tile *tiles = map.tiles;
    for(int i = 0; i<map.tileAmmount; i++)
    {
        esat::DrawSprite((tiles+i)->sprite, (tiles+i)->pos.x, (tiles+i)->pos.y);
    }
}

void LoadMap(Map* map)
{
    map->tileSize = 16;
    map->tileAmmount = (800/map->tileSize) * (600/map->tileSize);
    map->tiles = (Tile*) malloc((map->tileAmmount) * sizeof(Tile));
    LoadTiles(&(map->tiles), map->tileAmmount);
}