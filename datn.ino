int analogPin = A0; // potentiometer wiper (middle terminal) connected to analog pin 3
// outside leads to ground and +5V
int val = 0;  // variable to store the value read

void setup() {
    Serial.begin(9600);           //  setup serial
    test_me();
}

void loop() {
    Serial.print(analogRead(A0));
    Serial.print(";");
    Serial.print(analogRead(A1));
    Serial.print(";");
    Serial.print(analogRead(A2));
    Serial.print(";");
    Serial.print(analogRead(A3));
    Serial.print(";");
    Serial.print(analogRead(A10));
    Serial.println("");
}
