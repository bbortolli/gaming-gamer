#include <string>
#include <iostream>
#include <stdio.h>
#include "Input.h"
#include "const.h"
#include "Game.h"

#define TICK_RATE 124

bool MyFirstGame::created = false;

MyFirstGame::MyFirstGame(std::string n) {
  MyFirstGame::created = true;
  this->worldName = n;
};

MyFirstGame::~MyFirstGame() {
  MyFirstGame::created = false;
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
    this->map.update();
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
