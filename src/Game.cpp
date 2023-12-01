#include <string>
#include <iostream>
#include <stdio.h>
#include <include/Input.h>
#include "include/const.h"
#include "include/Game.h"

#define TICK_RATE 124

MyFirstGame::MyFirstGame(std::string n) {
  created = true;
  this->worldName = n;
};

void MyFirstGame::init() {
  this->isRunning = true;
  this->map = GameMap();
  Player player = Player("abc", 100);
  this->map.addPlayer(player);
};

/**
 * @brief
 * Main game loop function: Process, Update and Render!
 */
void MyFirstGame::game_loop() {
  while (this->isRunning) {
    std::vector<Event> events = this->event_handler.poll_events();
    this->map.update(events);
    this->map.draw(TICK_RATE);
  };
};

u_int16_t MyFirstGame::run() {
  this->init();
  this->game_loop();
  return 1;
};

bool MyFirstGame::is_running() {
  return this->isRunning;
};
