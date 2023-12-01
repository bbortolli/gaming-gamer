#include <string>
#include "const.h"

struct Position {
  int16_t x;
  int16_t y;
  int16_t z;
};

class Command {
  public:
    virtual void execute() = 0;
};

class PlayerMoveCommand : public Command {
  void execute(Player p, u_char k);
};

class Player {
  public:
    Player(std::string n, u_int16_t hp);
    Position get_position();
    u_int16_t get_health_points();
    std::string get_name();

    void move(u_char k);

  private:
    std::string name;
    u_int16_t healthPoints;
    Position pos;

    void set_position(u_int16_t x, u_int16_t y);
    void change_health_points(int16_t delta);
};
