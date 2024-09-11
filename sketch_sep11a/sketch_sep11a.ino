// for loop to ask user how many times they want to flash RGB LED
int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int br = 115200;
int inputCount;
int i; 
int delayTime = 250;
int longPause = 1000;
String prompt = "how many times would you like the light to flash? ";
String userInputReview = "You chose: ";
String success = "Finished count!";
void setup() {
Serial.begin(br);
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
}

void loop() {
Serial.println(prompt);
while(Serial.available()==0){

}
inputCount = Serial.parseInt();
Serial.println(userInputReview + inputCount);
for (i = 1; i <= inputCount; i = i = i + 1){

  // flash red
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  delay(delayTime);

  // flash green
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);
  delay(delayTime);

  // flash blue
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);
  delay(delayTime);

  // LED off
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  delay(longPause);

  Serial.println(i);
  if (i == inputCount){
    Serial.println(success);
  }
}

}
