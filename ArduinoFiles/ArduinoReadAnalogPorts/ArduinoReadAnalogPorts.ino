int a0,a1,a2,a3,a4,a5;
void setup() {
  Serial.begin(9600);

}
void loop() {
  //Read all pins for data
  a0 = analogRead(A0);
  a1 = analogRead(A1);
  a2 = analogRead(A2);
  a3 = analogRead(A3);
  a4 = analogRead(A4);
  a5 = analogRead(A5);
  
  //Output pin results
  Serial.print("\n\nResults\n");
  Serial.print("This is pin A0: "); 
  Serial.println(A0);
  Serial.print("This is pin A1: ");
  Serial.println(a1);
  Serial.print("This is pin A2: ");
  Serial.println(a2);
  Serial.print("This is pin A3: ");
  Serial.println(a3);
  Serial.print("This is pin A4: ");
  Serial.println(a4);
  Serial.print("This is pin A5: ");
  Serial.println(a5);
  delay(1500);

}
