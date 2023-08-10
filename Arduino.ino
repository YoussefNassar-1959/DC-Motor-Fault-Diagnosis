#define encoder 15
#define currentSensor 25

unsigned int rpm;
volatile byte pulses;
unsigned long TIME;
unsigned long mesTIME;
unsigned int pulse_per_turn = 20;

float maxError;           // maximum allowed error between measured RPM and healthy RPM
unsigned long startTime;  // start time of the measurement
float healthyRPM;
//depends on the number of slots on the slotted disc


////////////Fitting function parameters

float a;
float b;
float c;
float d;


void count() {
  // counting the number of pulses for calculation of rpm
  pulses++;
}

void setup() {
  //reset all to 0
  rpm = 0;
  pulses = 0;
  TIME = 0;

  maxError = 10.0;  // maximum allowed error between measured RPM and healthy RPM
  startTime = 0;    // start time of the measurement
  healthyRPM = 0.0;

  Serial.begin(115200);
  pinMode(currentSensor, INPUT);
  pinMode(encoder, INPUT);  // setting up encoder pin as input
  //triggering count function everytime the encoder turns from HIGH to LOW
  attachInterrupt(digitalPinToInterrupt(encoder), count, FALLING);

  a = 0.00436;
  b = -0.03971;
  c = 1.068;
  d = 46.51;
}



float healtyRPM(long time) {

  float t = time / 1000;
  float fx = (a*pow(t, 3)) - (b * pow(t, 2)) + (c * t) + d;
  return fx;
}


void loop() {

  float adc = analogRead(currentSensor);     

  if (millis() - TIME >= 100) {  // updating every 0.1 second

    float voltage = (adc / 1024.0) * 5;
    float current = (voltage - 2500) / 100;

    detachInterrupt(digitalPinToInterrupt(encoder));  // turn off trigger
    //calcuate for rpm
    rpm = (60 * 100 / pulse_per_turn) / (millis() - TIME) * pulses;
    TIME = millis();
    pulses = 0;
    Serial.println("CurrentRPM: ");
    Serial.println(rpm);

    healthyRPM = healtyRPM(millis() - startTime); 
    Serial.println("HealthyRPM: ");
    Serial.println(healthyRPM);

    if (millis() - startTime >= 40000) {  ////Reinitiate time interval every 40 secs because it's the working range of the function
      startTime += 40000;
    }

      // calculate error between measured RPM and healthy RPM
  float error = abs(rpm - healthyRPM) / healthyRPM * 100.0;

   if (error <= maxError) {
    Serial.println(" ");
    Serial.print("RPM state");
    Serial.println("HEALTHY!");
  } else {
    Serial.print("RPM state");
    Serial.println("FAULTY!");
  }

  
  }

  //trigger count function everytime the encoder turns from HIGH to LOW
  attachInterrupt(digitalPinToInterrupt(encoder), count, FALLING);


}
