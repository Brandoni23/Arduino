//ENGR100
//10-11-2018
//2
//Brandon Martinez
//Jordan Habib
const int FANPIN = A1;
const int THERMPIN = A0;
const int LEDPIN = 4;
const int ANGLEPIN = A2;
const int LED2 = 3;
const int LED3 = 5;
const int THEM = A3;
int Thermistor;
int PressureSensor;
int AngleReader;
int Temperature;
void setup() {
  pinMode(FANPIN, OUTPUT);
  pinMode(THERMPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);
  pinMode(ANGLEPIN, INPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(THEM, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (analogRead(ANGLEPIN) > 900) {
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    if (analogRead(THEM) > 600) {
      digitalWrite(LED3, HIGH);
    } else {
      digitalWrite(LED3, LOW);
    }
  }
  if (analogRead(ANGLEPIN) < 200) {
    digitalWrite(LED2, LOW);
    if (analogRead(THERMPIN) < 610) {
      digitalWrite(FANPIN, LOW);
      digitalWrite(LEDPIN, LOW);
    } else {
      digitalWrite(FANPIN, HIGH);
      digitalWrite(LEDPIN, HIGH);
      digitalWrite(LED3, LOW);
    }
  }
  Thermistor = analogRead(THERMPIN);
  AngleReader = analogRead(ANGLEPIN);
  Temperature = analogRead(THEM);
  Serial.println(Temperature);
  delay(100);
}
