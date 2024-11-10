#define BLYNK_TEMPLATE_ID "TMPLHb6sRI1e" 
#define BLYNK_TEMPLATE_NAME "IOT" 
#define BLYNK_AUTH_TOKEN "H9asnsjHqC0poUYKaC4d-1HcFwgq3PpC" 

#include <WiFi.h> 
#include <WiFiClient.h> 
#include <BlynkSimpleEsp32.h> 
#include <Wire.h> 
#include <HTTPClient.h> 

const int MPU_addr = 0x68; 
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ; 
double x, y, z; 
int minVal = 265; 
int maxVal = 402; 

char auth[] = "H9asnsjHqC0poUYKaC4d-1HcFwgq3PpC"; 
char ssid[] = "iotdata"; 
char pass[] = "12345678"; 

void setup() 
{ 
    Wire.begin(); 
    Wire.beginTransmission(MPU_addr); 
    Wire.write(0x6B); // Power management register
    Wire.write(0); // Wake the MPU-6050
    Wire.endTransmission(true); 
    
    Serial.begin(9600); 
    Blynk.begin(auth, ssid, pass); 
}

void loop() 
{ 
    Wire.beginTransmission(MPU_addr); 
    Wire.write(0x3B); // Start reading at register 0x3B
    Wire.endTransmission(false); 
    Wire.requestFrom(MPU_addr, 14, true); 
    
    AcX = Wire.read() << 8 | Wire.read(); 
    AcY = Wire.read() << 8 | Wire.read(); 
    AcZ = Wire.read() << 8 | Wire.read(); 
    
    int xAng = map(AcX, minVal, maxVal, -90, 90); 
    int yAng = map(AcY, minVal, maxVal, -90, 90); 
    int zAng = map(AcZ, minVal, maxVal, -90, 90); 
    
    x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI); 
    y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI); 
    z = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI); 
    
    Serial.print("AngleX= "); Serial.println(AcX); 
    Serial.print("AngleY= "); Serial.println(AcY); 
    Serial.print("AngleZ= "); Serial.println(AcZ); 
    Serial.println("-----------------------------------------"); 
    
    Blynk.run(); 
    Blynk.virtualWrite(V0, AcX); 
    Blynk.virtualWrite(V1, z); 
    
    upload(AcX, z); 
    delay(10000); 
} 

void upload(float v1, float v2) 
{ 
    HTTPClient http; 
    String url = "https://script.google.com/macros/s/AKfycbyjSZVD6upQ0E7VTugumoFiI0Bd_m_vu8Y6-mImZrAK-0V9oO0wRjnUCt3ga_VcVuiZM/exec?v1=" + 
                 String(v1) + "&v2=" + String(v2); 
    
    http.begin(url.c_str()); 
    http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS); 
    int httpCode = http.GET(); 
    
    Serial.print("HTTP Status Code: "); Serial.println(httpCode); 
    
    if (httpCode > 0) { 
        String payload = http.getString(); 
        Serial.println(payload); 
    } else { 
        Serial.println("HTTP request failed");
    } 
    
    http.end(); 
}
