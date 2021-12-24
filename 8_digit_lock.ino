#include <Keypad.h>
#include <EEPROM.h>
#include <Servo.h>
Servo myservo;
char d,d1,d2,d3,d4,d5,d6,d7,d10,d11,d12,d13,d14,d15,d16,d17;
int c,cpa;
bool cp,np;
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte rowPins[ROWS] = {11,12,14,15}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {16,17,18,19}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup(){
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
myservo.attach(13);
myservo.write(0);
Serial.begin(9600);
Serial.println( "ENTER PASSWORD   ");
d= EEPROM.read(0);
d1= EEPROM.read(1);
d2= EEPROM.read(2);
d3= EEPROM.read(3);
d4= EEPROM.read(4);
d5= EEPROM.read(5);
d6= EEPROM.read(6);
d7= EEPROM.read(7);
}
void loop(){
char key = keypad.getKey();
if (key){
c++;
digitalWrite(c+1,HIGH);
Serial.println(key);
//PRINT CHAR
if(c==1)d10=key;
if(c==2)d11=key;
if(c==3)d12=key;
if(c==4)d13=key;
if(c==5)d14=key;
if(c==6)d15=key;
if(c==7)d16=key;
if(c==8)d17=key;
}
if(c==8&np==0){
c=0;
if(d==d10&d1==d11&d2==d12&d3==d13&d4==d14&d5==d15&d6==d16&d7==d17){
if(cp==0){
Serial.println( "PASSWORD ACCEPTED");
delay(200);
alloff();
delay(200);
allon();
delay(200);
alloff();
delay(200);
for (int i = 0; i <= 180; i += 1) {
myservo.write(i);
delay(5);
}
delay(2000);
for (int i = 180; i>= 0; i -= 1) {
myservo.write(i);
delay(5);
}
}
if(cp==1){
Serial.println( "NEW PASSWORD");
alloff();
delay(100);
allon();
delay(1000);
alloff();
delay(1000);
np=1;
}
d10=d11=d12=d13=0,d14=d15=d16=d17=0;
}else   if(d10=='0'&d11=='0'&d12=='0'&d13=='0',d14=='0'&d15=='0'&d16=='0'&d17=='0'){
delay(50);
alloff();
delay(50);
allon();
delay(50);
alloff();
delay(50);
allon();
delay(50);
alloff();
delay(50);
allon();
delay(50);
alloff();
delay(50);
allon();
delay(50);
alloff();
delay(50);
allon();
delay(50);
alloff();
delay(50);
Serial.println( "OLD PASSWORD");
cp=1;
}else{
Serial.println( "WRONG PASSWORD");
if(cp==1){
cpa++;
}
delay(100);
alloff();
delay(100);
allon();
delay(100);
alloff();
delay(100);
allon();
delay(100);
alloff();
delay(100);
allon();
delay(100);
alloff();
delay(100);
d10=d11=d12=d13=0,d14=d15=d16=d17=0;
}
}
if(cpa==3){
np=0;
cp=0;
cpa=0;
c=0;
d10=d11=d12=d13=d14=d15=d16=d17=0;
alloff();
Serial.println( "ENTER PASSWORD   ");
}
if(c==8&np==1){
d=d10;
d1=d11;
d2=d12;
d3=d13;
d4=d14;
d5=d15;
d6=d16;
d7=d17;
EEPROM.write(0, d);
EEPROM.write(1, d1);
EEPROM.write(2, d2);
EEPROM.write(3, d3);
EEPROM.write(4, d4);
EEPROM.write(5, d5);
EEPROM.write(6, d6);
EEPROM.write(7, d7);
np=0;
cp=0;
c=0;
d10=d11=d12=d13=d14=d15=d16=d17=0;
alloff();
Serial.println( "ENTER PASSWORD   ");
}
}
void allon(){
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
}
void alloff(){
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
}
