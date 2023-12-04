#include <string>
#include <map>
#include <random>
#include "const.h"
#include "Input.h"
#include "Player.h"

// helpers
int random(u_int16_t start, u_int16_t end) {
  std::random_device rd;  // a seed source for the random number engine
  std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> distrib(start, end);

  return distrib(gen);
};

std::map<unsigned char, Position> keyToDeltaPosition = {
  {'w', {0, -1}},
  {'a', {-1, 0}},
  {'s', {0, 1}},
  {'d', {0, 1}},
  {'q', {-1, -1}},
  {'e', {1, -1}},
  {'z', {-1, 1}},
  {'c', {1, 1}}
};

// PlayerMoveCommand
void PlayerMoveCommand::execute(Player player, unsigned char k) {
  player.move(k);
};

// Player
Player::Player(std::string n, u_int16_t hp) {
  u_int16_t x = random(0, 19);
  u_int16_t y = random(0, 19);
  this->set_position(x, y);
  this->name = n;
  this->healthPoints = hp;
};

Position Player::get_position() {
  return this->pos;
};

u_int16_t Player::get_health_points() {
  return this->healthPoints;
};

std::string Player::get_name() {
  return this->name;
};

void Player::move(unsigned char k) {
  std::string move_chars = "wasdqezc";
  if (move_chars.find(k)) {
    Position delta = keyToDeltaPosition[k];
    u_int16_t nx = this->pos.x + delta.x;
    u_int16_t ny = this->pos.y + delta.y;
    set_position(nx, ny);
  }
};

void Player::set_position(u_int16_t x, u_int16_t y) {
  this->pos.x = x;
  this->pos.y = y;
};

void Player::change_health_points(int16_t dt) {
  this->healthPoints += dt;
};
