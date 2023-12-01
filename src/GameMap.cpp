#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include "include/const.h"
#include "include/GameMap.h"
#include "include/Event.h"

#define MAP_SIZE_X 20;
#define MAP_SIZE_Y 20;

// MapUnit
MapUnit::MapUnit(u_int16_t t) {
  this->tileId = t;

  // fixed things
  this->maxStack = 10;
  this->entityId = 0;
  this->actionId = 0;
  this->tileId = 0;
  this->stackedThings = {};
}

void MapUnit::stackThing(u_int16_t thingId) {
  if (checkIfCanStack()) {
    this->stackedThings.push(thingId);
  };
};

bool MapUnit::checkIfCanStack() {
  bool haveFreeSlots = this->stackedThings.size() < this->maxStack;
  bool isStackable = this->stackedThings.top() <= 100;
  return haveFreeSlots && isStackable;
};

// GameMap

GameMap::GameMap() {
  this->maxHorizontalSize = 20;
  this->maxVerticalSize = 20;
  this->squares = {};
  this->initializeMap();
};

void GameMap::initializeMap() {
  for (u_int16_t row = 0; row < this->maxHorizontalSize; row++) {
    std::vector<u_char> rowVector = {};
    for (u_int16_t col = 0; col < this->maxVerticalSize; col++) {
      rowVector.push_back('o');
    };
    squares.push_back(rowVector);
  };
};

void GameMap::update(std::vector<Event> events) {
  for (auto itEvent: events) {
    itEvent.execute(this);
  };
};

void GameMap::positionEntity(std::vector<Player> entities, u_char c) {
  for(auto itEntitity : entities) {
    Position position = itEntitity.get_position();
    uint16_t x = position.x;
    uint16_t y = position.y;
    this->squares[x][y] = c;
  };
};

void GameMap::positionEntities() {
  this->positionEntity(this->npcs, '@');
  this->positionEntity(this->players, '*');
  this->positionEntity(this->mobs, 'X');
};

void GameMap::drawFloor() {
  for(auto itRow : this->squares) {
    for(auto itCol : itRow) {
      std::cout << itCol << " - ";
    };
    std::cout << "\n";
  };
};

void GameMap::draw(u_int16_t ratePerSeconds) {
  u_int16_t refreshTime = 1000 / ratePerSeconds;
  this->positionEntities();
  this->drawFloor();
  std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::milliseconds(refreshTime));
  std::cout << "\x1B[2J\x1B[H";
};

void GameMap::addNpc(Player npc) {
  this->npcs.push_back(npc);
};

void GameMap::addPlayer(Player player) {
  this->players.push_back(player);
};

void GameMap::addMob(Player mob) {
  this->mobs.push_back(mob);
};
