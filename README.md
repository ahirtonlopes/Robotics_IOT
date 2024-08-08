# Robotics_IOT
This repository contains all the materials, code examples, and resources for the MBA course on Robotics and IoT. The course covers fundamental and advanced topics in robotics, IoT architecture, and their applications in various industries.

Aqui está um exemplo de arquivo README.md para a primeira aula do curso de MBA em Robótica e IoT:

```markdown
# MBA Robotics and IoT - Lesson 1

## Lesson Overview

In this lesson, we will focus on understanding how to declare variables and pins in Arduino. These are fundamental concepts for working with microcontrollers, and they lay the groundwork for more complex projects in robotics and IoT.

### Key Concepts Covered:
- Introduction to Arduino programming
- Declaring variables in Arduino
- Setting up and controlling pins on the Arduino board
- Basic electronic components: LEDs and ultrasonic sensors

## Activities

### Activity 1: Blink an LED

In this activity, you'll learn how to control an LED using an Arduino. The goal is to write a simple program that makes the LED blink on and off at regular intervals.

**Steps:**
1. Connect an LED to pin 13 of the Arduino board.
2. Declare the pin as an output in your Arduino code.
3. Write a loop that turns the LED on and off with a delay in between.

**Code Example:**
```cpp
int ledPin = 13; // Declare pin 13 as the LED pin

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin 13 as an output
}

void loop() {
  digitalWrite(ledPin, HIGH); // Turn the LED on
  delay(1000); // Wait for 1 second
  digitalWrite(ledPin, LOW); // Turn the LED off
  delay(1000); // Wait for 1 second
}
```

### Activity 2: Presence Detection Mechanism Using Ultrasonic Sensor

This activity involves building a simple presence detection system using an ultrasonic sensor. The sensor will measure the distance to an object, and if the object is within a certain range, an LED will light up to indicate its presence.

**Components Needed:**
- Ultrasonic sensor (HC-SR04)
- LED
- Resistors
- Arduino board
- Breadboard and jumper wires

**Steps:**
1. Connect the ultrasonic sensor to the Arduino board (VCC, GND, Trig, and Echo pins).
2. Connect an LED to an available digital pin on the Arduino board.
3. Declare the pins and variables in your Arduino code.
4. Write a program to read the distance from the ultrasonic sensor and turn the LED on if an object is detected within a specified range.

**Code Example:**
```cpp
int trigPin = 9;    // Trigger pin of the ultrasonic sensor
int echoPin = 10;   // Echo pin of the ultrasonic sensor
int ledPin = 13;    // LED pin

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  // Send a pulse from the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the pulse duration from the echo pin
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance based on the duration
  distance = duration * 0.034 / 2; // Distance in cm

  // Display the distance on the serial monitor
  Serial.println(distance);

  // Turn on the LED if the object is within 10 cm
  if (distance < 10) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(100); // Delay before next reading
}
```

## Summary

By the end of this lesson, you should be comfortable with basic Arduino programming, including variable and pin declarations. You'll also have hands-on experience with controlling an LED and creating a simple presence detection system using an ultrasonic sensor.

Feel free to experiment with the code and try adjusting the parameters to see how it affects the behavior of the LED and sensor!

## Additional Resources

- [Arduino Official Documentation](https://www.arduino.cc/reference/en/)
- [Introduction to Ultrasonic Sensors](https://www.electronicshub.org/arduino-ultrasonic-sensor/)

---

This README provides the essential details for the first lesson and the two hands-on activities. You can further customize this template as needed.
```
