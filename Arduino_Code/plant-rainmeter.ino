const int sensorPin = A2; //Pin connected to A2 on the controller
const int ledPin = 2; // Pin connected to the LED
const int buzzerPin = 4; // Pin connected to the piezo buzzer


void setup () {
Serial.begin(9600); //set baud rate for serial monitor for reading
pinMode(ledPin, OUTPUT); //set pin as output
pinMode(buzzerPin, OUTPUT); //set pin as output
//Output format:
Serial.println("\nSoil Moisture/Humidity sensor");
Serial.println("------------------------------");
}

void loop () {
  int anaValue = analogRead(sensorPin); //read sensor value

  if (anaValue > 200){
    digitalWrite(ledPin, HIGH); //LED indicator alarm
    digitalWrite(buzzerPin, HIGH); //buzzer sounds alarm
    delay(1000);  //wait for 1 sec for buzzer to sound and then repeat
    digitalWrite(buzzerPin, LOW);

    Serial.println("\nSensor Value: "+String(anaValue));
    Serial.println("Soil is Dry, Plesae water your Plant!");
    delay(1000); // Wait for 1 second
  }
  else{
    digitalWrite(ledPin, LOW); //turn off LED if reading is below 900
    digitalWrite(buzzerPin, LOW); //turn off buzzer if reading is below 900
    
    Serial.println("Sensor Value: "+String(anaValue));
    Serial.println("Soil is Wet, Good!");
    delay(1000); // Wait for 1 second
  }
}