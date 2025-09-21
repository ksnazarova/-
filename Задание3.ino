const int buttonPin = 2;
const int ledPin = 13;

int buttonState = 0;

void setup() {

const int buttonPin = 2;
const int ledPin = 13;

int buttonState = 0;

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Кнопка НАЖАТА"); 
  } else { 
    digitalWrite(ledPin, LOW); 
    Serial.println("Кнопка ОТЖАТА");  
  }
  
  delay(100);                   
}
