const int redPin = 11;
const int greenPin = 12;
const int bluePin = 13;

const int potPin = A0;

void hsvToRgb(float h, float s, float v, int &r, int &g, int &b) {
  
    while (h >= 360.0) h -= 360.0;
    while (h < 0.0) h += 360.0;
   
    s = constrain(s, 0.0, 1.0);
    v = constrain(v, 0.0, 1.0);
    
    int i = int(h / 60.0) % 6;
    float f = (h / 60.0) - i;
    float p = v * (1.0 - s);
    float q = v * (1.0 - s * f);
    float t = v * (1.0 - s * (1.0 - f));
    
    switch (i) {
        case 0: r = v * 255; g = t * 255; b = p * 255; break;
        case 1: r = q * 255; g = v * 255; b = p * 255; break;
        case 2: r = p * 255; g = v * 255; b = t * 255; break;
        case 3: r = p * 255; g = q * 255; b = v * 255; break;
        case 4: r = t * 255; g = p * 255; b = v * 255; break;
        case 5: r = v * 255; g = p * 255; b = q * 255; break;
    }
    
    r = 255 - r;
    g = 255 - g;
    b = 255 - b;
}

void setColor(int r, int g, int b) {
    analogWrite(redPin, r);
    analogWrite(greenPin, g);
    analogWrite(bluePin, b);
}

void setup() {
  
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    
    Serial.begin(9600);
    Serial.println("RGB цветовой круг (общий анод)");
    Serial.println("Поворачивайте потенциометр для смены цвета");
    Serial.println("Hue(°) | R | G | B");
    Serial.println("-------------------");
}

void loop() {
    int potValue = analogRead(potPin);
    
    float hue = map(potValue, 0, 1023, 0, 360);
    
    float saturation = 1.0; 
    float value = 1.0;     
    
    int r, g, b;
    
    hsvToRgb(hue, saturation, value, r, g, b);
    
    setColor(r, g, b);
   
    Serial.print(hue, 1);
    Serial.print("° | ");
    Serial.print(255 - r);
    Serial.print(" | ");
    Serial.print(255 - g);
    Serial.print(" | ");
    Serial.println(255 - b);
    
    delay(100);
}