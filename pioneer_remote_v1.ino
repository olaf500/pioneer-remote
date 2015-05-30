// Last revision for 3.3V Pioneer unit



int analogInput1 = A3; // All other buttons
int analogInput2 = A4;  // Mode button
int analogOut = A6;
int value1 = 0;
int value2 = 0;

void setup()
{
  pinMode(analogOut, OUTPUT);
  pinMode(analogInput1, INPUT_PULLUP);
  pinMode(analogInput2, INPUT_PULLUP);
  analogFrequency(60000);
  analogWrite(analogOut, 0);
  
  //Serial.begin(9600);
  //Serial.println("Start measurement");
}

void loop()
{
  value1 = analogRead(analogInput1);
  value2 = analogRead(analogInput2);
  //Serial.print("v1:"); Serial.print(value1); Serial.print(" v2:"); Serial.println(value2); 

  if (value2 < 5) { // Mode  1K2
    analogWrite(analogOut, 87);
  } else if (value1 < 5) { // Up  8K
    analogWrite(analogOut, 55);
  } else if (value1 < 20) { // Down  11K25
    analogWrite(analogOut, 47);
  } else if (value1 < 60) { // Vol+  16K
    analogWrite(analogOut, 40);
  } else if (value1 < 340) { // Vol-  24K 
    analogWrite(analogOut, 30);
  } else {
    analogWrite(analogOut, 0);
  }
  
  delay(200);
}
