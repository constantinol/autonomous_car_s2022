// this is where they start reading the information
const int trigPinRight = A1;
const int echoPinRight = 2;
const int trigPinFront = 3;
const int echoPinFront = 4;
const int trigPinLeft = 5;
const int echoPinLeft = 6;

// variables for ultrasonic sensor
long durationFront; // long refers to 8 byte storage
int distanceFront;
long durationLeft;
int distanceLeft;
long durationRight;
int distanceRight;
const int minFrontDistance = 30;
const int minSideDistance = 20;
const int stuckDistance = 10;

void sensorRead () {
  //Read front sensor value
  digitalWrite(trigPinFront, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinFront, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFront, LOW);
  durationFront = pulseIn(echoPinFront, HIGH);    // measuring if this is high??
  distanceFront = durationFront * 0.034 / 2;      // multiplies it by 0.034 / 2
  //Read left sensor value
  digitalWrite(trigPinLeft, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinLeft, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinLeft, LOW);
  durationLeft = pulseIn(echoPinLeft, HIGH);
  distanceLeft = durationLeft * 0.034 / 2;
  //Read right sensor value
  digitalWrite(trigPinRight, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinRight, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinRight, LOW);
  durationRight = pulseIn(echoPinRight, HIGH);
  distanceRight = durationRight * 0.034 / 2;
}

void setup() {
  pinMode(trigPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);
  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);
  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);
//  irrecv.enableIRIn();  // don't need this yet, it is IR receiver
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   sensorRead ();
      Serial.println(durationFront);
      //Serial.println(distanceLeft);
      //Serial.println(distanceRight);
    delay(500);
    }
