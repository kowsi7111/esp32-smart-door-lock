#include <Keypad.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Servo.h>

#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLXXXXXXX"
#define BLYNK_TEMPLATE_NAME "Smart Door Lock"
#define BLYNK_AUTH_TOKEN "YourAuthTokenHere"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

#define SERVO_PIN 13
Servo lockServo;

// Correct passcode
String correctCode = "1234";
String enteredCode = "";

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {19, 18, 5, 17};  // Connect to R1, R2, R3, R4
byte colPins[COLS] = {16, 4, 0, 2};    // Connect to C1, C2, C3, C4

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

BLYNK_WRITE(V0) {
  int value = param.asInt();
  if (value == 1) {
    unlockDoor();
    Blynk.virtualWrite(V1, "Door unlocked via app");
  }
}

void unlockDoor() {
  Serial.println("Unlocked!");
  lockServo.write(90); // Open
  delay(5000);
  lockServo.write(0);  // Close again
  Serial.println("Locked");
}

void setup() {
  Serial.begin(115200);
  lockServo.attach(SERVO_PIN);
  lockServo.write(0); // Locked position

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
  char key = keypad.getKey();

  if (key) {
    if (key == '#') {
      if (enteredCode == correctCode) {
        unlockDoor();
        Blynk.virtualWrite(V1, "Correct passcode entered");
      } else {
        Serial.println("Incorrect passcode");
        Blynk.virtualWrite(V1, "Wrong code attempt");
      }
      enteredCode = ""; // reset after attempt
    } else {
      enteredCode += key;
      Serial.print("Pressed: ");
      Serial.println(key);
    }
  }
}
