//dinda(Ndaisna_)
 

#include <Keypad.h>

#define ROW_NUM     4 // four rows
#define COLUMN_NUM  3 // three columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte pin_rows[ROW_NUM] = {18, 19, 5, 23};
byte pin_column[COLUMN_NUM] = {26, 25, 17};  


Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

void setup() {
  Serial.begin(115200);

  
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
  }
} 
