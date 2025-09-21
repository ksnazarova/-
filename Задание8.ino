const int redPin = 13;
const int yellowPin = 12;
const int greenPin = 11;

const int buttonPin = 2;

int buttonState = 0;
int lastButtonState = LOW;
bool buttonPressed = false;

const int preparationTime = 5000;  
const int greenTime = 5000;       
const int yellowTime = 1000;       
const int redTime = 5000;         
const int redYellowTime = 1000;   

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
  Serial.println("Светофор по кнопке запущен");
  Serial.println("Ожидание нажатия кнопки...");

  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (lastButtonState == LOW && buttonState == HIGH) {
    buttonPressed = true;
    Serial.println("Кнопка нажата! Начинается цикл светофора через 5 секунд...");
    delay(50);
  }
  
  lastButtonState = buttonState;
  
  if (buttonPressed) {

    Serial.println("Подготовка: 5 секунд до начала переключения");
    for (int i = 5; i > 0; i--) {
      Serial.print("Осталось: ");
      Serial.print(i);
      Serial.println(" сек");
      delay(1000);
    }
    
    Serial.println("ЗЕЛЕНЫЙ МИГАЕТ - приготовьтесь");
    for (int i = 0; i < 6; i++) {
      digitalWrite(greenPin, !digitalRead(greenPin));
      delay(500);
    }
    digitalWrite(greenPin, LOW);
    
    digitalWrite(yellowPin, HIGH);
    Serial.println("ЖЕЛТЫЙ - приготовьтесь");
    delay(yellowTime);
    digitalWrite(yellowPin, LOW);
    
    digitalWrite(redPin, HIGH);
    Serial.println("КРАСНЫЙ - движение запрещено");
    delay(redTime - redYellowTime);
    
    digitalWrite(yellowPin, HIGH);
    Serial.println("КРАСНЫЙ + ЖЕЛТЫЙ - приготовьтесь к движению");
    delay(redYellowTime);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, LOW);

    digitalWrite(greenPin, HIGH);
    Serial.println("ЗЕЛЕНЫЙ - движение разрешено");
    Serial.println("Ожидание следующего нажатия кнопки...");
    
    buttonPressed = false;
  }
}