const bool COMMON_CATHODE = true; 

const int redPin = 11;
const int greenPin = 12;
const int bluePin = 13;

const int greenTime = 5000;      
const int yellowBlinkTime = 3000; 
const int yellowTime = 1000;       
const int redTime = 5000;          
const int redYellowTime = 1000;    

void setColor(int red, int green, int blue) {
  if (COMMON_CATHODE) {
  
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
  } else {
 
    analogWrite(redPin, 255 - red);
    analogWrite(greenPin, 255 - green);
    analogWrite(bluePin, 255 - blue);
  }
}

void setYellow() {
  setColor(255, 100, 0);

}

void setup() {

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
 
  Serial.begin(9600);
  Serial.println("RGB светофор запущен");
  Serial.println("Желтый цвет: Красный (255) + Зеленый (100)");
}

void loop() {

  setColor(0, 255, 0); 
  Serial.println("ЗЕЛЕНЫЙ - движение разрешено");
  delay(greenTime - yellowBlinkTime);

  Serial.println("ЗЕЛЕНЫЙ МИГАЕТ - приготовьтесь");
  for (int i = 0; i < (yellowBlinkTime / 500); i++) {
    setColor(0, 255, 0); 
    delay(250);
    setColor(0, 0, 0);   
    delay(250);
  }

  setYellow(); 
  Serial.println("ЖЕЛТЫЙ - приготовьтесь");
  delay(yellowTime);
  
  setColor(255, 0, 0); 
  Serial.println("КРАСНЫЙ - движение запрещено");
  delay(redTime - redYellowTime);

  Serial.println("КРАСНЫЙ + ЖЕЛТЫЙ - приготовьтесь к движению");
  unsigned long startTime = millis();
  while (millis() - startTime < redYellowTime) {
   
    setColor(255, 0, 0);
    delay(100);
    setYellow();        
    delay(100);
  }
  
  Serial.println("-----------------------------------");
}