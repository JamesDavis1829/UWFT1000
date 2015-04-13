#include <Encoder.h>

Encoder Enc(2,3);

void setup() {
  Serial.begin(9600);
  Enc.write(0);

}

void loop() {
  
  Serial.println(Enc.read());

}
