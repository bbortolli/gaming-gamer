#include <vector>

class Event {
  public:
    void execute(GameMap *gm);
};

class EventHandler {
  public:
    void register_event(Event e);
    std::vector<Event> poll_events();

  private:
    std::vector<Event> events;
};
