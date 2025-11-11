#include <SoftwareSerial.h>

SoftwareSerial ReyaxLoRa(5, 4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  delay(2000);

  ReyaxLoRa.begin(9600);

  Serial.println();
  Serial.println("Serial monitor settings : ");
  Serial.println("- End Char : Newline");
  Serial.println("- Baud Rate : 115200");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (ReyaxLoRa.available()) Serial.println(ReyaxLoRa.readString());
  if (Serial.available()) ReyaxLoRa.print(Serial.readString());
}

/*AT
AT+OPMODE=1
AT+BAND=915000000
AT+ADDRESS=1*/
