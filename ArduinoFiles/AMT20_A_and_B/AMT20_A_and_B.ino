/*Reads from the encoder A and B and returns either
 *or negative change
 */

const int A = A4;
const int B = A5;

int ARead,BRead;

void setup() {
  pinMode(A,INPUT);
  pinMode(B,INPUT);
  Serial.begin(9600);

}

void loop() {
  ARead = analogRead(A);
  BRead = analogRead(B);
  
  Serial.print("This is A: ");
  Serial.println(ARead);
  Serial.print("This is B: ");
  Serial.println(BRead);
  delay(1000);

}
