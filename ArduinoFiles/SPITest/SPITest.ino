#include <SPI.h>

const byte READ = 0x10;
const byte NO_OP = 0x00;
const byte SET_ZERO = 0x70;

int bytesToRead = 16;
unsigned int distance;
byte byteReadUpper = 0x00;
byte byteReadLower = 0x00;
//SCK on pin 13
//MOSI on pin 11
//MISO on pin 12
//CSB on pin 10

void setup() {
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  pinMode(11,INPUT);
  pinMode(12,OUTPUT);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE1);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  SPI.transfer(SET_ZERO);

}

void loop() {
  delay(100);
  SPI.transfer(READ);
  /*for (int x = 0; x < bytesToRead; x++)
  {
    byteRead = byteRead + SPI.transfer(NO_OP);
    byteRead << 1;
  }*/
  digitalWrite(13,LOW);
  byteReadUpper = shiftIn(12,13,MSBFIRST);
  byteReadLower = shiftIn(12,13,MSBFIRST);
  Serial.println(byteReadUpper);
  Serial.println(byteReadLower);
  Serial.println(digitalRead(4));
  Serial.println(digitalRead(3));
  delay(1000);

}

