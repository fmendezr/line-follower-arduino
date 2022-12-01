#define IRSensorRight 11
#define IRSensorLeft 12
#define motorSpeed 180

//Right motor
int enableRightMotor = 6;
int rightMotorPinOne = 7;
int rightMotorPinTwo = 8;

//Left motor
int enableLeftMotor = 5;
int leftMotorPinOne = 9;
int leftMotorPinTwo = 10;

void setup()
{ 
  // put your setup code here, to run once:
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPinOne, OUTPUT);
  pinMode(rightMotorPinTwo, OUTPUT);
  
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPinOne, OUTPUT);
  pinMode(leftMotorPinTwo, OUTPUT);

  pinMode(IRSensorRight, INPUT);
  pinMode(IRSensorLeft, INPUT);
  rotateMotor(0,0);   
}


void loop()
{

  int rightSensorValue = digitalRead(IRSensorRight);
  int leftSensorValue = digitalRead(IRSensorLeft);

  if (rightSensorValue == LOW && IRSensorLeft == LOW)
  {
    rotateMotor(motorSpeed, motorSpeed);
  }
  else if (rightSensorValue == HIGH && IRSensorLeft == LOW )
  {
      rotateMotor(-motorSpeed, motorSpeed); 
  } 
  else if (rightSensorValue == LOW && IRSensorLeft == HIGH )
  {
      rotateMotor(motorSpeed, -motorSpeed); 
  } 
  else 
  {
    rotateMotor(0, 0);
  }
}


void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  
  if (rightMotorSpeed < 0)
  {
    digitalWrite(rightMotorPinOne,LOW);
    digitalWrite(rightMotorPinTwo,HIGH);    
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(rightMotorPinOne,HIGH);
    digitalWrite(rightMotorPinTwo,LOW);      
  }
  else
  {
    digitalWrite(rightMotorPinOne,LOW);
    digitalWrite(rightMotorPinTwo,LOW);      
  }

  if (leftMotorSpeed < 0)
  {
    digitalWrite(leftMotorPinOne,LOW);
    digitalWrite(leftMotorPinTwo,HIGH);    
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(leftMotorPinOne,HIGH);
    digitalWrite(leftMotorPinTwo,LOW);      
  }
  else 
  {
    digitalWrite(leftMotorPinOne,LOW);
    digitalWrite(leftMotorPinTwo,LOW);      
  }
  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));    
}
