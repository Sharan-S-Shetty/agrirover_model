#include <Servo.h>
Servo servosaw;
Servo servoseed;
Servo servoph;
int angle = 0;
int motor = 0;
#define for_back_speed   100
#define left_ryt_speed   110

#define motor_r_p         10
#define motor_r_m         9
const int fanPin = 13;

char data;


void setup() 
{
   Serial.begin(9600); //9600 baud rate
   Serial.println("Welcome");
   pinMode(motor_r_p, OUTPUT);
   pinMode(motor_r_m, OUTPUT);

   servosaw.attach(A0);
   servoseed.attach(A1);
   servoph.attach(A2);
   pinMode(fanPin, OUTPUT);
   digitalWrite(fanPin, 0);
}

void loop() 
{

   if(  Serial.available()   )
   {
      data = Serial.read();

      if(data == 'F')
      {
         move_forward();
         Serial.println("          --> F");
      }

      else if(data == 'B')
      {
         move_backward();
         Serial.println("          --> B");
      }
      else if(data == 'L')
      {
         move_left();
         Serial.println("          --> L");
      }
      else if(data == 'R')
      {
        move_right();
         Serial.println("          --> R");
      }
      else if(data == 'M')
      {
          motor_start();
         Serial.println("          --> M");
      }
      else if(data == 'N')
      {
          motor_stop();
         Serial.println("          --> M");
      }
      
   }
}

//***************************************

void move_forward()
{
   servoph.write(90);
}

void move_backward()
{
   servoph.write(0);
}


void move_left()

{
   servosaw.write(90);
   delay(500);
   servosaw.write(0);
}
   

void move_right()
{ 
   servoseed.write(90);
   delay(500);
   servoseed.write(0);

}

void motor_start()
{   
    digitalWrite(fanPin, 1); // Turn on the fan
    
}
void motor_stop()
{   
    digitalWrite(fanPin, 0); // Turn on the fan
    
}
