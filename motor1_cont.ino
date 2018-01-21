#include <avr/interrupt.h>
#include <stdlib.h>
#include <Timer.h>

String x1="",y1="",angleleft="",angleright="";int angle=0;String angle1="";
int x=0,y=0;


int en1 = 9;
int m1f = 30;
int m1b = 31;

float Kp=0.001;
float Kd=1.8;
int rpm = 0;
int count = 0;
int error=0;
int prev_error=0;

float rpm_giv=200;
float pwm =0;
int drive =0;
int t1=0,t2=0,t3=0;
Timer t;

void setup()
{
Serial.begin(115200);
  pinMode(9, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(18, INPUT_PULLUP);
 int tick=t.every(100,reading);
  attachInterrupt(digitalPinToInterrupt(18),runn, RISING);
  pwm=map(rpm_giv,-700,700,-255,255);
}

void reading()
{
  rpm=count/0.5;
  count=0;

  Serial.print("RPM: ");Serial.println(rpm);
  }
void runn()
{
  count++;
//Serial.print("count= ");Serial.println(count);
}

void loop()
{
            rpm_giv= 300;
            pwm=map(rpm_giv,-700,700,-255,255);

        if(pwm>0.0)
        {
          digitalWrite(m1f,1);
          digitalWrite(m1b,0);
        }
        else
        {
          digitalWrite(m1f,0);
          digitalWrite(m1b,1);
        }
        t1=millis();
        error=rpm_giv-rpm;
        pwm=pwm +(Kp*error)+Kd*((error-prev_error));
        analogWrite(en1,pwm);
        Serial.print("error: ");Serial.println(error);
        prev_error=error;
        t2=t1;
        t.update();
        
          
      }
}

  }
  }

            
