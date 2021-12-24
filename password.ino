#include <EEPROM.h>
void setup(){
}
void loop(){
EEPROM.write(0, '1');
EEPROM.write(1, '2');
EEPROM.write(2, '3');
EEPROM.write(3, '4');
EEPROM.write(4, '5');
EEPROM.write(5, '6');
EEPROM.write(6, '7');
EEPROM.write(7, '8');
}
