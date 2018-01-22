/* Switch.h - Switch manipulation
 * 
 * Author: Márcio Pessoa <marcio.pessoa@sciemon.com>
 * Contributors: none
 * 
 * Change log
 * 2016-02-04
 *         * Improved comments.
 * 
 * 2015-06-07
 *         * on
 *         Added on method.
 *         * off
 *         Added off method.
 * 
 * 2015-02-25
 *         * set
 *         Renamed method from state to set.
 * 
 * 2014-11-21
 *         * Relay
 *         Renamed class from Relay to Switch.
 * 
 * 2014-11-16
 *         * nameWrite
 *         Changed name String type to char. To reduce memory consumption.
 * 
 * 2014-11-01
 *         * nameWrite
 *         added nameWrite method.
 *         * nameRead
 *         added nameRead method.
 * 
 * 2014-09-16
 *         Experimental version.
*/

#ifndef Switch_h
#define Switch_h

#include "Arduino.h"

class Switch
{
  public:
    Switch(byte pin, bool state = LOW, bool inversor = false);
    bool set(bool state = false);
    void on();
    void off();
    bool status();
    bool nameWrite(char *name);
    String nameRead();
  private:
    byte _pin;
    char *_name;
    bool _state;
    bool _inversor;
};

#endif
