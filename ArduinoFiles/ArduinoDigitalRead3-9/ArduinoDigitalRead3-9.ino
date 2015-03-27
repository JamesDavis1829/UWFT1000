//Reads digital pins 3-9 and outputs the data

int p3,p4,p5,p6,p7,p8,p9;

void setup() {
  //Begins Serial ouput and sets digital pins to read
  Serial.begin(9600);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  // put your setup code here, to run once:

}

void loop() {
  //Reads pins 3-9
  p3 = digitalRead(3);
  p4 = digitalRead(4);
  p5 = digitalRead(5);
  p6 = digitalRead(6);
  p7 = digitalRead(7);
  p8 = digitalRead(8);
  p9 = digitalRead(9);
  
  //outputs read data
  Serial.print("\nResults\n");
  Serial.print("Pin 3: ");
  Serial.println(p3);
  Serial.print("Pin 4: ");
  Serial.println(p4);
  Serial.print("Pin 5: ");
  Serial.println(p5);
  Serial.print("Pin 6: ");
  Serial.println(p6);
  Serial.print("Pin 7: ");
  Serial.println(p7);
  Serial.print("Pin 8: ");
  Serial.println(p8);
  Serial.print("Pin 9: ");
  Serial.println(p9);
  delay(1500);

}
