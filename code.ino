

int echoPin = 12; // Echo Pin
int trigPin = 13; // Trigger Pin
int maximumRange = 30; // Maximum range needed
int count = 0; // How mamy cups have been collected
long duration, distance; // Duration used to calculate distance | Distance in cm

void setup() {

    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600); // Starts the serial communication

}

void loop() {

    digitalWrite(trigPin, LOW); // Sets the trigPin on LOW state for 2 micro seconds
    delayMicroseconds(2); // 2 microsecond pause to ensure a clean LOW pulse
    digitalWrite(trigPin, HIGH); // Sets the trigPin on HIGH state for 10 micro seconds
    delayMicroseconds(10); // 10 microsecond pause to ensure a clean HIGH pulse
    digitalWrite(trigPin, LOW); // Sets the trigPin on LOW state

    duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
    distance = duration/58.2; // Calculating the distance

    if (distance < 5) {
        count++; // Adds 1 to the count
        Serial.println(count); // Prints the count
        delay(20); // Waits 20 milliseconds
    }
  
    delay(5);  // Waits 5 milliseconds

}