  
const int Motor1Pin1 = 8;
const int Motor1Pin2 = 9;
const int Motor2Pin2 = 10;
const int Motor2Pin1 = 11;

void setup()
{
  Serial.begin(9600);
  pinMode(Motor1Pin1, OUTPUT);   
  pinMode(Motor1Pin2, OUTPUT);   
  pinMode(Motor2Pin1, OUTPUT);   
  pinMode(Motor2Pin2, OUTPUT);
} 
  

void loop()
{
  if(Serial.available()>0)
  {
    char input = Serial.read(); 
    switch(input)
    {
     case 'F' : moveForward();  
     break;
     case 'B' : moveBackward(); 
     break;
     case 'L' : moveLeft(); 
     break;
     case 'R' : moveRight();
     break;
     case 'S' : Stop();
     break;
     default : break;
    }
  } 
  delay(50);
}

void moveBackward(){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, HIGH);
}

void moveForward(){
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, HIGH);
  digitalWrite(Motor2Pin2, LOW);
}

void moveRight(){
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, LOW);
}

void moveLeft(){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, HIGH);
  digitalWrite(Motor2Pin2, LOW);
}

void Stop()
{
  Serial.println("<Robot Name> Stop");
  digitalWrite(Motor1Pin1,LOW);
  digitalWrite(Motor1Pin2,LOW);
  digitalWrite(Motor2Pin1,LOW);
  digitalWrite(Motor2Pin2,LOW);
}
