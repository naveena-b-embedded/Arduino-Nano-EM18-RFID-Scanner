#include <SoftwareSerial.h>

SoftwareSerial RFID(2, 3);  // RX = D2, TX = D3 (D3 is not physically connected)

void setup() {
  Serial.begin(9600);
  RFID.begin(9600);

  Serial.println("RFID Scanner Ready");
  Serial.println("Scan your RFID card...");
}

void loop() {
  if (RFID.available()) {
    char c = RFID.read();

    if (c != '\r' && c != '\n') {
      Serial.print(c);
    } else if (c == '\n') {
      Serial.println();
      Serial.println("Scan again...");
    }
  }
}
