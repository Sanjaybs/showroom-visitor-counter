
#include <NewPing.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

long count = 1;
const int colorR = 0;
const int colorG = 0;
const int colorB = 255;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // initialize the serial communications:
  //Serial.begin(9600);
  lcd.setRGB(colorR, colorG, colorB);

  // Print a message to the LCD.

  delay(1000);
}

void loop() {
  //delay(500);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  //Serial.print("Ping: ");
  //Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  //Serial.println("cm");

  if (sonar.ping_cm() >= 30 && sonar.ping_cm() <= 50) {
    Serial.println("Count : ");
    //Serial.println(count++);
    Serial.println(" persons");

    delay(500);
    lcd.setCursor(0, 0);
    lcd.print("Visitors");
    lcd.setCursor(0, 1);
    lcd.print((count++ / 2));
    delay(500);

  }
  else {
    Serial.println(count);

  }
}

