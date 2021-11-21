
#define STEP 11
#define DIRECTION 12
#define pinIRLED 5

#define MSR 6

long delay_Micros = 1800; 
long currentMicros = 0; 
long previousMicros = 0;
int stepsTaken = 1;
int stepsReverse = 0;
int delayTime = 1;
int photos = 0;

//setup all the pins and set motor to max microstepping 1/16
void setup()
{
  pinMode(STEP,OUTPUT);
  pinMode(DIRECTION,OUTPUT);
  pinMode(MSR,OUTPUT);
  pinMode(pinIRLED,OUTPUT);
  digitalWrite(MSR, HIGH);
  stepperFWD();
}

//will loop until 73 photos are taken, then will reverse all the way back to signify a full loop.
//finally exits at the end so we dont take extra accidental photos 
void loop()
{
  //after 400 steps we stop and take a break
  if(stepsTaken % 400 != 0){
    motorStep();
  } else{
    motorStep();
    stepsTaken++;
    //trigger photo
    delay(200); 
    takePicture();
	//wait until photo has been complete
    delay(3500); 
    photos++;
  }
  //73 photos is a full circle +1 photo
  if(photos == 73){
     stepperREV();
     stepsReverse = stepsTaken;
     while(stepsReverse != 0){
       motorStep();
       stepsReverse--;
     }
     exit(0);
  }
}

//have the stepper motor take one step
void motorStep(){
  digitalWrite(STEP, HIGH);
  delay(delayTime);
  digitalWrite(STEP, LOW);
  stepsTaken++;
}

//set motor to forward
void stepperFWD(){
  digitalWrite(DIRECTION, HIGH);
}

//change the stepper direction to reverse
void stepperREV(){
  digitalWrite(DIRECTION, LOW);
}


// This camera triggering code comes courtesy of l8ter.com or LUCKYLARRY.CO.UK
// Read the article here http://www.l8ter.com/?p=333
// sets the pulse of the IR signal.
void pulseON(int pulseTime) {
  unsigned long endPulse = micros() + pulseTime;        // create the microseconds to pulse for
  while( micros() < endPulse) {
    digitalWrite(pinIRLED, HIGH);                       // turn IR on
    delayMicroseconds(13);                              // half the clock cycle for 38Khz (26.32×10-6s) - e.g. the 'on' part of our wave
    digitalWrite(pinIRLED, LOW);                        // turn IR off
    delayMicroseconds(13);                              // delay for the other half of the cycle to generate wave/ oscillation
  }
}
void pulseOFF(unsigned long startDelay) {
  unsigned long endDelay = micros() + startDelay;       // create the microseconds to delay for
  while(micros() < endDelay);
}

void takePicture() {
  for (int i=0; i < 2; i++) {
    pulseON(2336);
    pulseOFF(646);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(646);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(646);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(11008);
    pulseON(2336);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(646);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(646);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(11008);
    pulseON(2336);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(646);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1168);
    pulseOFF(621);
    pulseON(1093);
    pulseOFF(696);
    pulseON(572);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(621);
    pulseON(572);
    pulseOFF(1218);
    pulseON(497);
    pulseOFF(1292);
    pulseON(422);
    pulseOFF(1367);
    pulseON(373);
    pulseOFF(11803);
    pulseON(298);
    pulseOFF(2659);
    pulseON(199);
    pulseOFF(1590);
    pulseON(174);
    pulseOFF(1019);
    pulseON(174);
    pulseOFF(1615);
    pulseON(174);
    pulseOFF(1615);
    pulseON(149);
    pulseOFF(1044);
    pulseON(149);
    pulseOFF(1640);
    pulseON(124);
    pulseOFF(1093);
    pulseON(149);
    pulseOFF(1044);
    pulseON(124);
    pulseOFF(1665);
    pulseON(124);
    pulseOFF(1068);
    pulseON(124);
    pulseOFF(1665);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(1093);
    pulseON(99);
    pulseOFF(1118);
    pulseON(99);
    pulseOFF(1093);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(1690);
    pulseON(75);
    pulseOFF(1715);
    pulseON(75);
    pulseOFF(12101);
    pulseON(149);
    pulseOFF(2833);
    pulseON(75);
    pulseOFF(1715);
    pulseON(75);
    pulseOFF(1118);
    pulseON(75);
    pulseOFF(1715);
    pulseON(75);
    pulseOFF(1715);
    pulseON(75);
    pulseOFF(1118);
    pulseON(75);
    pulseOFF(1715);
    pulseON(75);
    pulseOFF(1118);
    pulseON(99);
    pulseOFF(1093);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(1093);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(1093);
    pulseON(99);
    pulseOFF(1118);
    pulseON(99);
    pulseOFF(1093);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(1690);
    pulseON(99);
    pulseOFF(646);
  }
}
