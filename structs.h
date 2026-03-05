#include <esat/draw.h>
#include <esat/sprite.h>
#include <esat/window.h>
#include <esat/draw.h>
#include <esat/sprite.h>
#include <esat/input.h>
#include <esat/time.h>

#ifndef STRUCTS_H
#define STRUCTS_H

struct Tile
{
    esat::SpriteHandle sprite;
    esat::Vec2 pos;
};

struct Map
{
    Tile *tiles;
    int tileAmmount;
    int tileSize;
};

struct Player
{
    esat::SpriteHandle *sprite;
    esat::Vec2 pos;
};

#endif

