const int buttonPin = 2;     
const int ledPin = 13;       

int ledState = LOW;          
int lastButtonState = LOW;   
int currentButtonState;      

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);

  Serial.println("Светодиод ВЫКЛЮЧЕН");
}

void loop() {
  currentButtonState = digitalRead(buttonPin);

  if (lastButtonState == LOW && currentButtonState == HIGH) {
  
    ledState = !ledState;
    
    digitalWrite(ledPin, ledState);
    
    if (ledState == HIGH) {
      Serial.println("Светодиод ВКЛЮЧЕН");
    } else {
      Serial.println("Светодиод ВЫКЛЮЧЕН");
    }
  
    delay(50);
  }

  lastButtonState = currentButtonState;
}