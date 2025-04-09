// includes the LiquidCrystal Library
#include <LiquidCrystal.h> 

// includes the LcdBarGraph Library
#include <LcdBarGraph.h>

// Maximum distance we want to ping for (in centimeters).
#define max_distance 200

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 10, 11, 12, 13); 

LcdBarGraph lbg(&lcd, 16, 0, 1); // Creates an LCD Bargraph object.

const int trigPin = 7;
const int echoPin = 6;
long duration;
int distance;

void setup() 
{
	lcd.begin(16,2); // Initializes the interface to the LCD screen
	
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

void loop() 
{
	// Write a pulse to the HC-SR04 Trigger Pin
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	
	// Measure the response from the HC-SR04 Echo Pin
	duration = pulseIn(echoPin, HIGH);
	
	// Determine distance from duration
	// Use 343 metres per second as speed of sound
	distance= duration*0.034/2;
	
	// Prints "Distance: <value>" on the first line of the LCD
	lcd.setCursor(0,0);
	lcd.print("Distance: "); 
	lcd.print(distance);
	lcd.print(" cm");

	// Draws bargraph on the second line of the LCD
	lcd.setCursor(0,1);
	lbg.drawValue(distance, max_distance);
	delay(500);
}