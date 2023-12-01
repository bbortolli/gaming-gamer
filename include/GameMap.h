#include <vector>
#include <stack>
#include "const.h"
#include "Player.h"

/**
 * MapUnit is each square that all map is built.
 *
 * @param t Tile ID for the image of this floor.
 */

class MapUnit {
  public:
    MapUnit(u_int16_t t);

    /**
     * Add an entity to this unit stack.
     *
     * @param thingId Entity id to be stacked.
     */
    void stackThing(u_int16_t thingId);

  private:
    u_int16_t maxStack;
    u_int16_t entityId;
    u_int16_t actionId;
    u_int16_t tileId;
    std::stack <u_int16_t> stackedThings;

    /**
     * Check if possible to add more entity to the stack.
     *
     * @return boolean if can stack.
     */
    bool checkIfCanStack();
};

class GameMap {
  public:
    GameMap();
    void initializeMap();
    void update(std::vector<Event> events);
    void positionEntity(std::vector<Player> entities, u_char c);
    void positionEntities();
    void drawFloor();
    void draw(u_int16_t ratePerSeconds);
    void addNpc(Player npc);
    void addPlayer(Player player);
    void addMob(Player mob);

  private:
    u_int16_t maxHorizontalSize;
    u_int16_t maxVerticalSize;
    std::vector< std::vector<u_char> > squares;
    std::vector<Player> players;
    std::vector<Player> mobs;
    std::vector<Player> npcs;
};
