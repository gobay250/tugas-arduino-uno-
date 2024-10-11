#include <Servo.h>

Servo myServo;   // Membuat objek Servo
int potPin = A0; // Pin analog di mana potensiometer terhubung
int servoPin = 9; // Pin PWM di mana servo terhubung
int potValue = 0; // Nilai yang terbaca dari potensiometer
float voltage = 0; // Tegangan yang terbaca dari potensiometer

void setup() {
  myServo.attach(servoPin);   // Menyambungkan servo ke pin yang sesuai
  Serial.begin(9600);         // Memulai komunikasi serial
}

void loop() {
  // Membaca nilai potensiometer (0-1023)
  potValue = analogRead(potPin);

  // Mengonversi nilai potensiometer (0-1023) menjadi sudut servo (0-180)
  int servoAngle = map(potValue, 0, 1023, 0, 180);
  
  // Menggerakkan servo ke sudut yang dihitung
  myServo.write(servoAngle);
  
  // Menghitung tegangan dari nilai potensiometer
  voltage = potValue * (5.0 / 1023.0);

  // Menampilkan nilai potensiometer, sudut servo, dan tegangan di Serial Monitor
  Serial.print("Pot Value: ");
  Serial.print(potValue);
  Serial.print(" -> Servo Angle: ");
  Serial.print(servoAngle);
  Serial.print(" -> Voltage: ");
  Serial.println(voltage, 2); // 2 decimal places for voltage
  
  // Delay sebentar untuk memperlancar pembacaan
  delay(100);
}
