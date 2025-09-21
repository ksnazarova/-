const int buttonPin = 2;     
const int potPin = A0;       
const int ledPin = 9;        

int potValue = 0;
int ledBrightness = 0;
int savedBrightness = 0;     
bool isLocked = false;       
int currentButtonState;
int lastButtonState = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Система запущена. Поверните потенциометр.");
}

void loop() {
  currentButtonState = digitalRead(buttonPin);

  if (lastButtonState == LOW && currentButtonState == HIGH) {
    isLocked = !isLocked; 

    if (isLocked) {
  
      savedBrightness = ledBrightness;
      Serial.println("Блокировка ВКЛЮЧЕНА. Изменение яркости невозможно!");
    } else {
      Serial.println("Блокировка ОТКЛЮЧЕНА. Яркость снова регулируется.");
    }
    delay(50); 
  }
  lastButtonState = currentButtonState;

  potValue = analogRead(potPin);

  if (!isLocked) {
    ledBrightness = map(potValue, 0, 1023, 0, 255);
  }

  analogWrite(ledPin, ledBrightness);

  if (isLocked) {
   
    Serial.print("Заблокировано! Яркость зафиксирована на: ");
    Serial.println(savedBrightness);
  } else {

    Serial.print("Значение с потенциометра: ");
    Serial.print(potValue);
    Serial.print(" | Яркость светодиода: ");
    Serial.println(ledBrightness);
  }

  delay(200); 
}