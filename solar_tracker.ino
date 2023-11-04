#include <Servo.h>

Servo servo1, servo2 ;
int servo_1_pos = 90;
int servo_2_pos = 180;


void setup()
{
  servo1.attach(2);
  servo2.attach(3);
  //start calbiration part
  servo1.write(servo_1_pos);
  delay(12);
  servo2.write(servo_2_pos);
  delay(12);
  Serial.begin(9600);
}

void loop()
{
  float  s1 = analogRead(0);
  float  s2 = analogRead(1);
  float  s3 = analogRead(2);
  float  s4 = analogRead(3);
  float  s5 = analogRead(4);

  float S1 = (10000 * ((5 / ((s1 / 1024) * 5)) - 1));
  float S2 = (10000 * ((5 / ((s2 / 1024) * 5)) - 1));
  float S3 = (10000 * ((5 / ((s3 / 1024) * 5)) - 1));
  float S4 = (10000 * ((5 / ((s4 / 1024) * 5)) - 1));


  //vertical move
  if (((S1 - S3) > 200))
  {
    if (servo_1_pos < 120)
    {
      servo_1_pos = servo_1_pos + 1;
      servo1.write(servo_1_pos);
      delay(10);
    }

  }
  else if (((S1 - S3) < (-200)))
  {
    if (servo_1_pos > 0)
    {
      servo_1_pos = servo_1_pos - 1;
      servo1.write(servo_1_pos);
      delay(10);
    }

  }
  //horizontal move 
  
  if (((S2 - S4) > 200))
  {
    if (servo_2_pos > 0)
    {
      servo_2_pos = servo_2_pos - 1;
      servo2.write(servo_2_pos);
      delay(10);
    }

  }
  else if (((S2 - S4) < (-200)))
  {
    if (servo_2_pos < 180)
    {
      servo_2_pos = servo_2_pos + 1;
      servo2.write(servo_2_pos);
      delay(10);
    }
  }

  //Serial.print("voltage:");
  Serial.println((s5/1024)*5);
  
  
}
