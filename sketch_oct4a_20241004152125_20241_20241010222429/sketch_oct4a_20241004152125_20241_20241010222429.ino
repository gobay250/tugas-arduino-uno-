#include <Servo.h>

Servo myServo;   // Membuat objek Servo
int potPin = A0; // Pin analog untuk potensiometer
int potValue = 0; // Nilai yang terbaca dari potensiometer

void setup() {
  myServo.attach(9);  // Menyambungkan servo ke pin PWM 9
  Serial.begin(9600); // Memulai komunikasi serial
}

void loop() {
  // Membaca nilai potensiometer (0-1023)
  potValue = analogRead(potPin);

  // Mengonversi nilai potensiometer (0-1023) menjadi sudut servo (0-180 derajat)
  int servoAngle = map(potValue, 0, 1023, 0, 180);

  // Menggerakkan servo ke sudut yang dihitung
  myServo.write(servoAngle);

  // Menampilkan nilai potensiometer dan sudut servo di Serial Monitor
  Serial.print("Pot Value: ");
  Serial.print(potValue);
  Serial.print(" -> Servo Angle: ");
  Serial.println(servoAngle);

  // Delay untuk stabilisasi pembacaan
  delay(100);
}
