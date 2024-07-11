#define for_back_speed   100
#define left_ryt_speed   110

#define motor_r_p         10
#define motor_r_m         9
#define motor_l_p         6
#define motor_l_m         5

char data;


void setup() 
{
   Serial.begin(9600); //9600 baud rate
   Serial.println("Welcome");
   pinMode(motor_r_p, OUTPUT);
   pinMode(motor_r_m, OUTPUT);
   pinMode(motor_l_p, OUTPUT);
   pinMode(motor_l_m, OUTPUT);
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
      else if(data == 'S')
      {
          robot_stop();
         Serial.println("          --> S");
      }
      
   }
}

//***************************************

void move_forward()
{
   analogWrite(motor_r_p, 0);
   analogWrite(motor_r_m, for_back_speed);
   analogWrite(motor_l_p, for_back_speed);
   analogWrite(motor_l_m, 0);
}

void move_backward()
{
   analogWrite(motor_r_p, for_back_speed);
   analogWrite(motor_r_m, 0);
   analogWrite(motor_l_p, 0);
   analogWrite(motor_l_m, for_back_speed);
}


void move_left()

{
   analogWrite(motor_r_p, left_ryt_speed);
   analogWrite(motor_r_m, 0);
   analogWrite(motor_l_p, left_ryt_speed);
   analogWrite(motor_l_m, 0);
}
   

void move_right()
{ 
   analogWrite(motor_r_p, 0);
   analogWrite(motor_r_m, left_ryt_speed);
   analogWrite(motor_l_p, 0);
   analogWrite(motor_l_m, left_ryt_speed); 

}

void robot_stop()
{
   analogWrite(motor_r_p, 0);
   analogWrite(motor_r_m, 0);
   analogWrite(motor_l_p, 0);
   analogWrite(motor_l_m, 0);
}
