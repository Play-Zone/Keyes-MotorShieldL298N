int IN1=8;
int IN2=11;
int IN3=12;
int IN4=13;
 
int EN1=9;// enable port 1
int EN2=10;// enable port 2
// digital port 8 and 11 are one group; 12 and 13 are another group 
// digital port 9 and 10 serve as enable terminals of the DC motor 

void setup() {
}

void loop(){
  aa();// the two DC motors:  forward-rotating for 1s; then stop for 1s; last reversal reverse for 1s 
}


void Motor1(boolean reverse){// motor 1 forward-rotating 
  if (reverse) {// forward-rotating (FWD)
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
  }
 
  else {// reversal reverse (REV)
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
  }
}
 
void Motor2(boolean reverse){ // motor 2 rotates 
  if (reverse) { // forward-rotating 
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  }
  else { // reversal reverse 
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
  }
}
 
void aa(){ // forward-rotating for 1s; then stop for 1s; last reversal reverse for 1s

  // forward-rotating 
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH); 
  delay(1000);
 
  // stop for 1s 
  stopMotor(true);
  delay(1000); 
  stopMotor(false);// enable terminals of the motor back to hihg level 
 
  // reversal reverse 
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
 
  delay(1000);
  // stop 
  stopMotor(true);
  delay(1000); 
  stopMotor(false);
}
 
void stopMotor(boolean r) { // motor stops rotating 
  if (r){
    analogWrite(EN1,0);
    analogWrite(EN2,0);
  }
  else  {
    analogWrite(EN1,255); 
    analogWrite(EN2,255);
  }
} 
 
void setup(){
 pinMode(IN1, OUTPUT);  
 pinMode(IN2, OUTPUT); 
 pinMode(IN3, OUTPUT);  
 pinMode(IN4, OUTPUT); 
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
} 



