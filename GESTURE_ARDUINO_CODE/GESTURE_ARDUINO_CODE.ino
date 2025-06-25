// Define motor pins
const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;
const int en1 = 6;
const int en2 = 7;
char data = 0;            //Variable for storing received data
void  setup()
{
    Serial.begin(9600);   //Sets the baud for serial data transmission                               
   pinMode(13, OUTPUT);  //Sets digital pin  13 as output pin
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
void loop()
{
   if(Serial.available() > 0)      
   {
      data = Serial.read();      
      Serial.println(data);          
         if(data == 'F') {            
         front();  
         Serial.println("going front");
         } 
          else  if(data == 'B') {      
         back();
          Serial.println("going back");
          }

         else  if(data == 'L')  {     
         left();
         Serial.println("going left");
         }
         else  if(data == 'R')  {     
         right();
         Serial.println("going right");
         }
         else if(data == 'S'){
          stop();
          Serial.println("no movement");
         }
   
   }
}

void front(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(en1,150);
  analogWrite(en2,150);
 }

void back(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(en1,150);
  analogWrite(en2,150);
 }

void left(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(en1,150);
  analogWrite(en2,150);

 }
 
void right(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
    analogWrite(en1,150);
  analogWrite(en2,150);
 }

void stop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(en1, 0);
  analogWrite(en2, 0);
}