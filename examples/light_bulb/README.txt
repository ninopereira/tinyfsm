The light_bulb implements just one fsm with one event.
It is meant to be the simplest example using the tinyfsm library.

The light bulb example represents a system containing a light bulb and a button.
It uses 2 states to represent the state of the light bulb: On_State, Off_State
Everytime the button is pressed the state changes

     ++++++++++++++                       ++++++++++++++
     |            | ---button_pressed---> |            |
     | Off_State  |                       |  On_State  |
     |            | <---button_pressed--- |            |
     ++++++++++++++                       ++++++++++++++

The main.cpp file contains the class definitions suggested in the documentation (http://digint.ch/tinyfsm/doc/usage.html)

1. Declare Events

2. Declare the State Machine Class

3. Declare the States

4. Define initial state of the fsm

5. Handle to fsm defining the send event command
