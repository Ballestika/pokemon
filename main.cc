#include <esat/window.h>
#include <esat/draw.h>
#include <esat/sprite.h>
#include <esat/input.h>
#include <esat/time.h>
#include <stdio.h>
#include "structs.h"
#include "map/map.cc"
#include "player/player.cc"
unsigned char fps=60;
double current_time,last_time;


int esat::main(int argc, char **argv) {
  esat::WindowInit(800,600);
  Map map;
  Player player;
  LoadMap(&map);
  LoadPlayer(&player);
  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
    last_time = esat::Time();

    esat::DrawBegin();
    esat::DrawClear(0,0,0);
    PaintMap(map);
    UpdatePlayer(&player);
    PaintPlayer(player);
    esat::DrawEnd();
    
	do{
    current_time = esat::Time();
    }while((current_time-last_time)<=1000.0/fps);
    esat::WindowFrame();
  }
  esat::WindowDestroy();
  return 0;
}