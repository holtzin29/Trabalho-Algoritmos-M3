#include "raylib.h"
#include "Bonecos.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGTH 3
#define RADIUS 10.0f
void movimentacao(){

}
void obstaculos(){

}
int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;
  InitWindow(screenWidth, screenHeight, "raylib basic window");
  SetTargetFPS(60);
  while (!WindowShouldClose()) {

   /*
    Objeto pos;
    float dt = GetFrameTime();
    if(IskeyDown (KEW_UP)|| IsKeyDown(KEY_W)){
      pos.y -=SPEED * dt;
      lastPos = UP;

    }
    if(IsKeyDown(KEY_DOWN)|| IsKeyDown(KEY_S)){
      pos.y += SPEED * dt;
      lastPos = DOWN;
    }
    if(IsKeyDown(KEY_LEFT)|| IsKeyDown(KEY_A)){
      pos.x -= SPEED * dt;
      lastPos = LEFT;
      
    }
    if(IsKeyDown(KEY_RIGTH)|| IsKeyDown(KEW_D)){
      pos.x += SPEED * dt;
      lastpos = RIGTH;

    }
*/


    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawCircle(pos,RADIUS,RED);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
