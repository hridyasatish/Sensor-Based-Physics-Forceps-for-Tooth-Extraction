#include <SPI.h>  
#include <Wire.h>  
#include <Adafruit_GFX.h>  
#include <Adafruit_SSD1306.h> 
#include <LiquidCrystal.h> 

// Define LCD display pins 
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  

#define SCREEN_WIDTH 128 // OLED display width, in pixels  
#define SCREEN_HEIGHT 64 // OLED display height, in pixels  
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)  
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);  

#define NUMFLAKES     10 // Number of snowflakes in the animation example  
#define LOGO_HEIGHT   16 
#define LOGO_WIDTH    16  

int age1 = 0; 

void setup() {   
  lcd.begin(16, 2); 
  pinMode(8, OUTPUT);  
  digitalWrite(8, LOW);   
  // turn the buzzer off initially     
  pinMode(9, INPUT);     
  pinMode(10, INPUT);  
  
  Serial.begin(9600);  
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64  
    Serial.println(F("SSD1306 allocation failed"));     
    // proceed, loop forever  
  }  
}    

void loop() {   
  if (digitalRead(9) == 1) {  
    Serial.print("1");  
    age1 = age1 + 1;    
    delay(100);  
  }  
  if (digitalRead(10) == 1) {  
    Serial.print("2");  
    age1 = age1 - 1;    
    delay(100);    
    if (age1 <= 0) {  
      age1 = 0;  
    }  
  }  

  int h = analogRead(A0);   
  h = map(h, 0, 1024, 100, 0);   

  if (h > 30 && age1 < 15 && age1 > 0) {  
    digitalWrite(8, HIGH);   // turn the buzzer on (HIGH is the voltage level)      
  }  
  if (h > 50 && age1 >= 15 && age1 < 35) {  
    digitalWrite(8, HIGH);   // turn the buzzer on (HIGH is the voltage level)      
  }  
  if (h > 70 && age1 >= 35) {  
    digitalWrite(8, HIGH);   // turn the buzzer on (HIGH is the voltage level)      
  }  
  if (h <= 10) {  
    digitalWrite(8, LOW);   // turn the buzzer off (LOW is the voltage level)      
  }  

  display.clearDisplay();  
  display.setTextSize(2);             
  display.setTextColor(WHITE);        
  display.setCursor(0, 0);            
  display.print("FORCE: ");  
  display.println(h);   
  display.setCursor(0, 45);             
  display.display();  

  Serial.print("FORCE:");  
  Serial.println(h);  
  display.print("AGE: ");   
  Serial.print("AGE:");   
  Serial.println(age1);  
  delay(100);  

  lcd.clear(); 
  lcd.print(String("FORCE : ") + String(h)); 
  lcd.setCursor(0, 1); 
  lcd.print(String("AGE : ") + String(age1)); 
  delay(100);  
}
