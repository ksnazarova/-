const int potPin = A0;      
const int ledPin = 13;      

int potValue = 0;            
int ledBrightness = 0;      

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  potValue = analogRead(potPin);
  
  ledBrightness = map(potValue, 0, 1023, 0, 255);
  

  analogWrite(ledPin, ledBrightness);

  Serial.print("Значение с потенциометра: ");
  Serial.print(potValue);
  Serial.print(" | Яркость светодиода: ");
  Serial.println(ledBrightness);

  delay(200);
}