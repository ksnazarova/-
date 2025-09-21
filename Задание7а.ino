const int redPin = 13;
const int yellowPin = 12;
const int greenPin = 11;

const int greenTime = 5000;     
const int yellowTime = 1000;   
const int redTime = 5000;
const int redYellowTime = 1000; 

void setup() {
  
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Светофор запущен (режим с задержками)");
}

void loop() {
  
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  Serial.println("ЗЕЛЕНЫЙ - движение разрешено");
  delay(greenTime - 3000); 


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

}