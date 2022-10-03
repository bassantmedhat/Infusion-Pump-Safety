int redLED = 2;
int buzz=13;
#define FORCE_SENSOR_PIN A0 // the FSR and 10K pulldown are connected to A0

void setup() {
  pinMode(redLED, OUTPUT);
pinMode(buzz, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  float forceReading = analogRead(FORCE_SENSOR_PIN);

  Serial.print("Force sensor reading = ");
  Serial.println(forceReading); // print the raw analog reading

 if(forceReading>=10 && forceReading<=200){
     digitalWrite(redLED,HIGH);
   // Serial.println(" -> medium squeeze");
     tone(buzz, 1000); // Send 1KHz sound signal...
     delay(1000);        // ...for 1 sec
     noTone(buzz);     // Stop sound...
     delay(1000);        // ...for 1sec
 }
 digitalWrite(redLED,LOW);

  delay(1000);
}
