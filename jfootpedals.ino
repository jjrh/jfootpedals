#include <EEPROM.h>
/*
|                 |                   |               |
| Key             | Hexadecimal value | Decimal value |
| KEY_LEFT_CTRL   |              0x80 |           128 |
| KEY_LEFT_SHIFT  |              0x81 |           129 |
| KEY_LEFT_ALT    |              0x82 |           130 |
| KEY_LEFT_GUI    |              0x83 |           131 |
| KEY_RIGHT_CTRL  |              0x84 |           132 |
| KEY_RIGHT_SHIFT |              0x85 |           133 |
| KEY_RIGHT_ALT   |              0x86 |           134 |
| KEY_RIGHT_GUI   |              0x87 |           135 |
| KEY_UP_ARROW    |              0xDA |           218 |
| KEY_DOWN_ARROW  |              0xD9 |           217 |
| KEY_LEFT_ARROW  |              0xD8 |           216 |
| KEY_RIGHT_ARROW |              0xD7 |           215 |
| KEY_BACKSPACE   |              0xB2 |           178 |
| KEY_TAB          |              0xB3 |           179 |
| KEY_RETURN      |              0xB0 |           176 |
| KEY_ESC         |              0xB1 |           177 |
| KEY_INSERT      |              0xD1 |           209 |
| KEY_DELETE      |              0xD4 |           212 |
| KEY_PAGE_UP     |              0xD3 |           211 |
| KEY_PAGE_DOWN   |              0xD6 |           214 |
| KEY_HOME        |              0xD2 |           210 |
| KEY_END         |              0xD5 |           213 |
| KEY_CAPS_LOCK   |              0xC1 |           193 |
| KEY_F1          |              0xC2 |           194 |
| KEY_F2          |              0xC3 |           195 |
| KEY_F3          |              0xC4 |           196 |
| KEY_F4          |              0xC5 |           197 |
| KEY_F5          |              0xC6 |           198 |
| KEY_F6          |              0xC7 |           199 |
| KEY_F7          |              0xC8 |           200 |
| KEY_F8          |              0xC9 |           201 |
| KEY_F9          |              0xCA |           202 |
| KEY_F10         |              0xCB |           203 |
| KEY_F11         |              0xCC |           204 |
| KEY_F12         |              0xCD |           205 |
*/


/* OUTPUT KEYCODES */
int O1 = EEPROM.read(0);
int O2 = EEPROM.read(1);
int O3 = EEPROM.read(2);
int O4 = EEPROM.read(3);

const int p1 = 2;
const int p2 = 3;
const int p3 = 4;
const int p4 = 5;


void setup() { 
  Serial.begin(9600);
  
  pinMode(p1, INPUT);
  pinMode(p2, INPUT);
  pinMode(p3, INPUT);
  pinMode(p4, INPUT);

  
  Keyboard.begin();
}
int last_state1 = LOW;
int last_state2 = LOW;
int last_state3 = LOW;
int last_state4 = LOW;

void loop() {

  int STATE1 = digitalRead(p1);
  if((STATE1 == HIGH) && (last_state1 != HIGH)){
    Serial.print("OUTPUT1:");
    Serial.println(O1);

    Keyboard.press(O1);
    last_state1 = HIGH;
  }
  if((STATE1 == LOW) && (last_state1 != LOW) ){
    Keyboard.release(O1);
    last_state1 = LOW;
    
  }

  int STATE2 = digitalRead(p2);
  if((STATE2 == HIGH) && (last_state2 != HIGH)){
    Serial.print("OUTPUT2:");
    Serial.println(O2);

    Keyboard.press(O2);
    last_state2 = HIGH;
  }
  if((STATE2 == LOW) && (last_state2 != LOW) ){
    Keyboard.release(O2);
    last_state2 = LOW;
    
  }

  int STATE3 = digitalRead(p3);
  if((STATE3 == HIGH) && (last_state3 != HIGH)){
    Serial.print("OUTPUT3:");
    Serial.println(O3);
    
    Keyboard.press(O3);
    last_state3 = HIGH;
  }
  if((STATE3 == LOW) && (last_state3 != LOW) ){
    Keyboard.release(O3);
    last_state3 = LOW;
    
  }

  int STATE4 = digitalRead(p4);
  if((STATE4 == HIGH) && (last_state4 != HIGH)){
    Serial.print("OUTPUT4:");
    Serial.println(O4);
    
    Keyboard.press(O4);
    last_state4 = HIGH;
  }
  if((STATE4 == LOW) && (last_state4 != LOW) ){
    Keyboard.release(O4);
    last_state4 = LOW;
    
  }

  delay(100);
  if(Serial.available() > 0){
    char buffer[256];
    Serial.readBytes(buffer,256);
    String buff = String(buffer);
    int output = buffer[0] - '0';
    String str_keycode = buff.substring(buff.indexOf("+")+1);
    int keycode = str_keycode.toInt();
    write_keycode(output,keycode);
  }


}


void write_keycode(int output, int keycode){
  EEPROM.write(output,keycode);
  print_eeprom();
}

void print_eeprom(){
  
  O1 = EEPROM.read(0);
  O2 = EEPROM.read(1);
  O3 = EEPROM.read(2);
  O4 = EEPROM.read(3);

  Serial.print("OUTPUT1:");
  Serial.print(O1);
  Serial.print(" OUTPUT2:");
  Serial.print(O2);
  Serial.print(" OUTPUT3:");
  Serial.print(O3);
  Serial.print(" OUTPUT4:");
  Serial.println(O4);

  
}

