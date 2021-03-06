#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial

char auth[] = "yCH5LKQc1FJBrEHGANWbNSyNq5wWmYrX";
char ssid[] = "Min'Laptop";
char pass[] = "12082542";

int MotorPin2 = D2;
int MotorPin3 = D3;

BlynkTimer timer;

void setup() {
  pinMode(MotorPin2, OUTPUT);
  pinMode(MotorPin3, OUTPUT);
  Serial.begin(9600);
  delay(10);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
} 
BLYNK_WRITE(V0) {
   if(param.asInt() == 1){
   digitalWrite(MotorPin2, HIGH);
   digitalWrite(MotorPin3, LOW);
   Blynk.virtualWrite(V4, "collecting");
   Serial.print("  เก็บผ้า\n");
  }
  else{
   digitalWrite(MotorPin2, LOW); 
   digitalWrite(MotorPin3, HIGH); 
   Blynk.virtualWrite(V4, "drying");
   Serial.print("  ตากผ้า\n");
  }
}
