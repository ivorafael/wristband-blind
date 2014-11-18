//#define LED1 A6
//#define LED2 A7

#define SENSOR1 2
#define SENSOR2 3

#define L293D_1   6
#define MOTOR1_E1 8
#define MOTOR1_E2 7

#define L293D_2   12
#define MOTOR2_E1 10
#define MOTOR2_E2 11

void setup() {
//  pinMode(LED1, OUTPUT);      
//  pinMode(LED2, OUTPUT);      
//  pinMode(13, OUTPUT);
  pinMode(SENSOR1, INPUT);
  pinMode(SENSOR2, INPUT);

  pinMode(MOTOR1_E1,OUTPUT);
  pinMode(MOTOR1_E2,OUTPUT);
  pinMode(L293D_1,OUTPUT);

  pinMode(MOTOR2_E1,OUTPUT);
  pinMode(MOTOR2_E2,OUTPUT);
  pinMode(L293D_2,OUTPUT);

  setMotors();

  notifyByMotor(L293D_1);
//  notifyByLed(LED1);

  notifyByMotor(L293D_2);
//  notifyByLed(LED2);

  delay(200);

//  clearNotifications(LED1, L293D_1);
//  clearNotifications(LED2, L293D_2);
  clearNotifications(L293D_1);
  clearNotifications(L293D_2);
}

void loop(){

  setMotors();

  if(hasObstacle(SENSOR1)) {
    notifyByMotor(L293D_1);
//    notifyByLed(LED1);
  }else{
    clearNotifications(L293D_1);
  }
  

  if(hasObstacle(SENSOR2)) {
    notifyByMotor(L293D_2);
//    notifyByLed(LED2);
  }else{
    clearNotifications(L293D_2);
  }

}

void setMotors(){
  digitalWrite(MOTOR1_E1, LOW);
  digitalWrite(MOTOR1_E2, HIGH);

  digitalWrite(MOTOR2_E1, LOW);
  digitalWrite(MOTOR2_E2, HIGH);
}

boolean hasObstacle(int sensor){ 
  Serial.println(digitalRead(sensor));
  return !digitalRead(sensor);
}

void notifyByMotor(int motor){
  analogWrite(motor, 75);
}

void notifyByLed(int led){
  digitalWrite(led, HIGH);
}

void clearNotifications(int motor){
//  digitalWrite(led, LOW);
  analogWrite(motor, 0);
}
