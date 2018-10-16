/* Switch.cpp - Switch Manipulation Library
 * 
 */

#include "Arduino.h"
#include "Switch.h"

/* Switch
 * 
 * Description
 *   Define swich object.
 * 
 *   Switch (int pin, boolean state)
 * 
 * Parameters
 *   pin: Arduino switch pin
 *   state: A bool to define initial switch state
 *   inversor: Works on inverse boolean logic
 * 
 * Returns
 *   void
 */
Switch::Switch(byte pin, bool state, bool inversor) {
  _pin = pin;
  _inversor = inversor;
  _state = (_inversor == true) ? not state : state;
  _name = "Power";
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, _state);
}

/* set
 * 
 * Description
 *   Define switch state.
 * 
 *   switch.set(ON)
 * 
 * Parameters
 *   state: A bool to define switch status
 * 
 * Returns
 *   bool
 *     true: If switch state changes
 *     false: If switch state stays untouched
 */
bool Switch::set(bool state) {
  bool change;
  // 
  change = (_state == state) ? false : true;
  change = (_inversor == true) ? not change : change;
  // 
  _state = (_inversor == true) ? not state : state;
  digitalWrite(_pin, _state);
  return change;
}

/* on
 * 
 * Description
 *   Set switch on.
 * 
 *   switch.on(ON)
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void Switch::on() {
  _state = true;
  _state = (_inversor == true) ? !_state : _state;
  digitalWrite(_pin, _state);
}

/* off
 * 
 * Description
 *   Set switch off.
 * 
 *   switch.off(ON)
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   void
 */
void Switch::off() {
  _state = false;
  _state = (_inversor == true) ? !_state : _state;
  digitalWrite(_pin, _state);
}

/* staus
 * 
 * Description
 *   Return switch status.
 * 
 *   switch.status()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   bool: switch status
 */
bool Switch::status() {
  bool state;
  state = (_inversor == true) ? not _state : _state;
  return state;
}

/* nameWrite
 * 
 * Description
 *   Set temperature sensor name.
 * 
 *   switch.nameWrite()
 * 
 * Parameters
 *   String name
 * 
 * Returns
 *   true: if error
 *   false: if no error
 */
bool Switch::nameWrite(char *name) {
  if (strlen(name) > 0) {
    _name = name;
    return false;
  }
  return true;
}

/* nameRead
 * 
 * Description
 *   Return temperature sensor name.
 * 
 *   switch.nameRead()
 * 
 * Parameters
 *   none
 * 
 * Returns
 *   String: Temperature sensor name.
 */
String Switch::nameRead() {
  return String(_name);
}
