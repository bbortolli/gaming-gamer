#include "include/Game.h"

int main(int argc, char* argv[]) {
  MyFirstGame game = MyFirstGame("default");
  unsigned short int r = game.run();
  return r;
};
