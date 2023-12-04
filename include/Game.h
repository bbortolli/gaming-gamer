#include <string>
#include "GameMap.h"
#include "Event.h"

/**
 * Main Class that handle all game.
 */
class MyFirstGame {

  static bool created;

  public:
    MyFirstGame(std::string n);
    ~MyFirstGame();
    std::string worldName;
    void init();
    void game_loop();
    u_int16_t run();
    bool is_running();

  private:
    bool isRunning;
    GameMap map;
    EventHandler event_handler;
};
