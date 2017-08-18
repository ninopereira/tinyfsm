/// Light bulb example
///
/// /// Let's represent a system containing a light bulb and a button
/// Let's use 2 states to represent the state of the light bulb: On_State, Off_State
/// Everytime the button is pressed we change state
///
///     ++++++++++++++                       ++++++++++++++
///     |            | ---button_pressed---> |            |
///     | Off_State  |                       |  On_State  |
///     |            | <---button_pressed--- |            |
///     ++++++++++++++                       ++++++++++++++
///

#include "../../include/tinyfsm.hpp"
#include <iostream>

/// 1. Declare Events
struct ButtonEvent : tinyfsm::Event{};
struct ButtonPressed : ButtonEvent { };

/// 2. Declare the State Machine Class
class LightBulb
: public tinyfsm::Fsm<LightBulb>
{
public:
  /* default reaction for unhandled events */
  void react(tinyfsm::Event const &) { };

  virtual void react(ButtonPressed const &){};
  virtual void entry(void) { };  /* entry actions in some states */
  void         exit(void)  { };  /* no exit actions */
};

/// 3. Declare the States
class Off_State; // forward declaration

class On_State
: public LightBulb
{
    void entry() override {std::cout << " =========  Light bulb is now ON!"<< std::endl;};
    void react(ButtonPressed const &) override {transit<Off_State>();};
};

class Off_State
: public LightBulb
{
    void entry() override{std::cout << " ========= Light bulb is now OFF!" << std::endl;};
    void react(ButtonPressed const &) override {transit<On_State>();};
};

// Define initial state of the fsm
FSM_INITIAL_STATE(LightBulb, Off_State);

// define all finite state machines of your system
// in our case we have only one
typedef tinyfsm::FsmList<LightBulb> fsm_handle;

template<typename E>
void send_event(E const & event)
{
  fsm_handle::template dispatch<E>(event);
}

// Main
int main()
{
    // start the fsm
  fsm_handle::start();

  // declare the events
  ButtonPressed button_pressed;

  while(1)
  {
    char c;
    std::cout << "Button pressed? (y,n): ";
    std::cin >> c;
    switch(c) {
    case 'y':
      std::cout << "Button was pressed" << std::endl;
      send_event(button_pressed);
      break;
    default:
      std::cout << "Nothing happens" << std::endl;
    };
  }
}
