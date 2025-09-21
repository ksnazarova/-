const int redPin = 13;
const int yellowPin = 12;
const int greenPin = 11;

const int greenTime = 5;    
const int yellowTime = 1;    
const int redTime = 5;      
const int redYellowTime = 1; 

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  

  Serial.begin(9600);
  Serial.println("Светофор запущен (режим с выводом времени)");
}

void loop() {

  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  Serial.println("ЗЕЛЕНЫЙ - движение разрешено");
  
  for (int i = greenTime; i > 0; i--) {
    Serial.print("Зеленый: ");
    Serial.print(i);
    Serial.println(" сек");
    delay(1000); 
    
    if (i <= 3) {
      digitalWrite(greenPin, !digitalRead(greenPin)); 
      delay(500);
      digitalWrite(greenPin, !digitalRead(greenPin));
    }
  }

  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
  Serial.println("ЖЕЛТЫЙ - приготовьтесь");
  delay(yellowTime * 1000);

  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, HIGH);
  Serial.println("КРАСНЫЙ - движение запрещено");
  
  for (int i = redTime; i > 0; i--) {
    Serial.print("Красный: ");
    Serial.print(i);
    Serial.println(" сек");

    if (i == 1) {
      digitalWrite(yellowPin, HIGH);
      Serial.println("КРАСНЫЙ + ЖЕЛТЫЙ - приготовьтесь к движению");
    }
    
    delay(1000); 
  }

  digitalWrite(yellowPin, LOW);
  Serial.println("-----------------------------------");
}