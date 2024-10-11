// Pin yang digunakan
int potPin = A0;  // Pin analog untuk potensiometer

// Variabel untuk menyimpan nilai potensiometer dan tegangan
int potValue = 0;   
float voltage = 0.0;

void setup() {
  // Inisialisasi komunikasi serial
  Serial.begin(9600);
}

void loop() {
  // Membaca nilai dari potensiometer (0 sampai 1023)
  potValue = analogRead(potPin);

  // Mengonversi nilai potensiometer menjadi tegangan (0V hingga 5V)
  voltage = potValue * (5.0 / 1023.0);

  // Menampilkan nilai tegangan ke Serial Monitor
  Serial.print("Tegangan: ");
  Serial.print(voltage);
  Serial.println(" V");

  // Delay untuk menghindari terlalu seringnya pembacaan
  delay(500);  // Delay 500 ms
}

