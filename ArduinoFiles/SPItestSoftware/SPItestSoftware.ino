#include <SPI.h>

const byte READ = 0x10;
const byte NO_OP = 0x00;
const byte SET_ZERO = 0x70;

byte byteReadUpper = 0x00;
byte byteReadLower = 0x00;

int MOSI1 = 11;
int MISO1 = 12;
int CSB = 10;
int SCLK = 13;

void setup() {
  Serial.begin(9600);
  pinMode(CSB,OUTPUT);
  pinMode(SCLK,OUTPUT);
  pinMode(MOSI1,OUTPUT);
  pinMode(MISO1,INPUT);

}

void loop() {
  delay(100);
  digitalWrite(SCLK,LOW);
  digitalWrite(CSB,LOW);
  shiftOut(MOSI1,SCLK,MSBFIRST,READ);
  digitalWrite(SCLK,LOW);
  byteReadUpper = shiftIn(MISO1,SCLK,MSBFIRST);
  byteReadLower = shiftIn(MISO1,SCLK,MSBFIRST);
  
  Serial.println(byteReadUpper);
  Serial.println(byteReadLower);
  delay(1000);

}
