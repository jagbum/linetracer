#define motorA_a 3
#define motorA_b 11
#define motorB_a 5
#define motorB_b 6
#define Lpin A0
#define Rpin A1

unsigned char Aspd =0, Bspd = 0;
//boolen m_a_dir = 0, m_b_dir = 0;


void setup() {
  TCCR1B = TCCR1B & 0b11111000 | 0x05;
  TCCR2B = TCCR2B & 0b11111000 | 0x07;

  pinMode(motorA_a, OUTPUT);
  pinMode(motorA_b, OUTPUT);
  pinMode(motorB_a, OUTPUT);
  pinMode(motorB_b, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  start();
}

void right(){
  analogWrite(motorA_a, 90);
  analogWrite(motorA_b, 0);
  analogWrite(motorB_a, 0);
  analogWrite(motorB_b, 30);
}

void left(){
  analogWrite(motorA_a, 0);
  analogWrite(motorA_b, 30);
  analogWrite(motorB_a, 90);
  analogWrite(motorB_b, 0);
}

void straight(){
  analogWrite(motorA_a, 65);
  analogWrite(motorA_b, 0);
  analogWrite(motorB_a, 85);
  analogWrite(motorB_b, 0);
}

void start() {
  int sensorl = analogRead(Lpin);
  int sensorR = analogRead(Rpin);
  if (sensorl < 90 && sensorR < 90) {
    straight();  
  }
  else if(sensorl < 90 && sensorR > 90 ){
    right();
  }
  else if(sensorl > 90 && sensorR < 90 ){
    left();
  }
}
