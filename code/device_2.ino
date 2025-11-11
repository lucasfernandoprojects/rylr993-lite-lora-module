#include <SoftwareSerial.h>

const int redLed = 2;
const int button = 3;
const int rx_pin = 4;   // LoRa TX -> Arduino RX
const int tx_pin = 5;   // LoRa RX -> Arduino TX
SoftwareSerial ReyaxLoRa(tx_pin, rx_pin); // (TX, RX)

bool ledState = false;
bool lastButtonState = HIGH;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  Serial.begin(115200);
  ReyaxLoRa.begin(9600);

  Serial.println("--- Starting serial communication... ---");
  delay(1000);

  // Initialize LoRa module
  ReyaxLoRa.println("AT");
  delay(200);
  ReyaxLoRa.println("AT+OPMODE=1"); // Use proprietary mode for point-to-point communication
  delay(200);
  ReyaxLoRa.println("AT+BAND=915000000");  // Frequency (set to your region)
  delay(200);
  ReyaxLoRa.println("AT+ADDRESS=2");       // This board's address (unique identifier)
  delay(200);
  
  Serial.println("LoRa initialized!");
}

void loop() {
  // ---- BUTTON SEND ----
  bool buttonState = digitalRead(button);
  if (buttonState == LOW && lastButtonState == HIGH) {
    // Send command to module 1
    Serial.println("Sending LED1 command...");
    ReyaxLoRa.println("AT+SEND=1,4,LED1"); // Send "LED1" (4 chars) to address 1
  }
  lastButtonState = buttonState;

  // ---- RECEIVE MESSAGES ----
  if (ReyaxLoRa.available()) {
    String incoming = ReyaxLoRa.readStringUntil('\n');
    incoming.trim();

    if (incoming.startsWith("+RCV=")) {
      // Format: +RCV=sender,len,message,RSSI,SNR
      int firstComma = incoming.indexOf(',', 5);
      int secondComma = incoming.indexOf(',', firstComma + 1);
      int thirdComma = incoming.indexOf(',', secondComma + 1);

      String sender = incoming.substring(5, firstComma);
      String message = incoming.substring(secondComma + 1, thirdComma);

      Serial.print("Message received from ");
      Serial.print(sender);
      Serial.print(": ");
      Serial.println(message);

      // If message is "LED2" and sender is 1, toggle LED
      if (sender == "1" && message == "LED2") {
        ledState = !ledState;
        digitalWrite(redLed, ledState ? HIGH : LOW);
        Serial.println(ledState ? "LED ON" : "LED OFF");
      }
    }
  }
}
