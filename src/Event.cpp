#include "include/Event.h"

void EventHandler::register_event(Event e) {
  this->events.push_back(e);
};

std::vector<Event> EventHandler::poll_events() {
  std::vector<Event> local_events = this->events;
  events.empty();
  return local_events;
}
