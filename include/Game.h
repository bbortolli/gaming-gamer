#include <string>
#include "GameMap.h"
#include "Event.h"

/**
 * Main Class that handle all game.
 */
class MyFirstGame {
  public:
    MyFirstGame(std::string n);
    std::string worldName;
    void init();
    void game_loop();
    u_int16_t run();
    bool is_running();

  private:
    static bool created;
    bool isRunning;
    GameMap map;
    EventHandler event_handler;
};
