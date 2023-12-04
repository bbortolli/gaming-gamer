#include "Game.h"

int main(int argc, char* argv[]) {
  MyFirstGame game = MyFirstGame("default");
  u_int16_t r = game.run();
  return r;
};
