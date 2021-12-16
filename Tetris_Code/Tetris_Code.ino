#include <Wire.h> // Include the I2C library (required)
#include <SparkFunSX1509.h> // Include SX1509 library

#define FULL_ON 255
#define FULL_OFF 0

SX1509 s[3];

const byte SX1509_A[3] = {0x3E, 0x3F, 0x70};
const int rows = 7;
const int columns = 5;
int left = 0;
int rotate = 0;
int fall = 0;
unsigned long timeThis, timeLast; //Millis

/*int pannel[ rows ][ columns ] = {
  { 0, 1, 2, 3, 4 },
  {  5, 6, 7, 8, 9 },
  { 10, 11, 12, 13, 14},
  { 15, 16, 17, 18, 19},
  { 20, 21, 22, 23, 24},
  { 25, 26, 27, 28, 29},
  { 30, 31, 32, 33, 34}
  };*/

int pannel[ rows ][ columns ] = {
  { 4, 3, 2, 1, 0 },
  { 9, 8, 7, 6, 5 },
  { 14, 13, 12, 11, 10},
  { 19, 18, 17, 16, 15},
  { 24, 23, 22, 21, 20},
  { 29, 28, 27, 26, 25},
  { 34, 33, 32, 31, 30}

};

uint8_t tetris_map [8] = {
  0x0000,  //0
  0x0000,  //1
  0x0000,  //2
  0x0000,  //3
  0x0000,  //4
  0x0000,  //5
  0x0000,  //6
  0x0000   //7
};

const char piece_T[12] = {
  B00000001 << left,
  B00000011 << left,
  B00000001 << left,

  B00000010,
  B00000111,
  B00000000,

  B00000010,
  B00000011,
  B00000010,

  B00000000,
  B00000111,
  B00000010,
};

void tpanel(uint8_t x, uint8_t y, uint8_t level) {
  // if ((x < 7) && (y < 5)) {
  uint8_t xy = pannel[x][y];
  // s[xy / 16].digitalWrite(xy % 16, level);
  s[xy / 16].analogWrite(xy % 16, level);
  //  }
}

//-----------------------------PRINTMAP---------------------------------
void print_map() {
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < columns; col++) {
      if (tetris_map[row] & 1 << col) {
        tpanel(row, col, FULL_ON);
      } else {
        tpanel(row, col, FULL_OFF);
      }
    }
  }
}
//-----------------------------DOWNFUNCION------------------------------
void down() {
  for (int i = 6; i > 0; i--) {
    tetris_map[i] = tetris_map[i - 1];
  }
  tetris_map[0] = 0;
  print_map();
}
//-----------------------------SETUP-------------------------------------
void setup() {
  Serial.begin(9600);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  
  uint8_t i, x, y;
  for ( i = 0; i < 3; i++) {
    s[i].begin(SX1509_A[i]);
    s[i].clock(INTERNAL_CLOCK_2MHZ, 4);
  }
  for ( i = 0; i < 3; i++) {
    for (uint8_t x = 0; x < 16; x++) {
      // s[i].pinMode(x, OUTPUT); // Set LED pin to OUTPUT
      s[i].pinMode(x, ANALOG_OUTPUT);
      //s[i].digitalWrite(x, HIGH);
    }
  }
  
  print_map();
}
//----------------------------------------------------------------------
void remove_piece() {
  for (int i = 0; i < 3; i++) {
    tetris_map[i + fall-1] &= 0x0000;
  }
}

void add_piece() {
  for (int num = 0; num < 3; num++) {
    tetris_map[num + fall] |= piece_T[num + rotate]; 
  }
}

void loop() {
  int b1 = digitalRead(4);
  int b2 = digitalRead(5);
  int b3 = digitalRead(6);
    
  timeThis = millis(); /*
  if (timeThis - timeLast > 1000) {
    fall = fall + 1;
    timeLast = timeThis;
  }
  remove_piece();
  */
  if (timeThis - timeLast > 1000) {
    left = left + 1;
    timeLast = timeThis;
  add_piece();
  }

 // if (b1 == LOW) {
 //   left = left + 1;
 // }
  
 /* if (b1 == LOW) {
    rotate = rotate + 3;
    delay(150);
  }
  if (rotate == 12) {
    rotate = 0;
  }
  */
  print_map(); 
}
