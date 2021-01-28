#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
int count=0;
int frontout = 3;
int backout = 4;
int efrontout = 5;
int ebackout = 0;
int threshold = 100;
Servo inservo;
Servo outservo;
int pos = 0;    // variable to store the servo position
int front;
int efront;
void setup() 
{
  lcd.begin(16,2);
  pinMode(9, OUTPUT);
  inservo.attach(9);
  outservo.attach(10);
}

void open() 
{  
      if(pos<=10)
        { 
          count++;
          lcd.print('Enter');
          for (pos = 0; pos <= 90; pos += 1) 
          {
             inservo.write(pos);              // tell servo to go to position in variable 'pos'
             delay(30);                       // waits 15ms for the servo to reach the position
          }
        
}
    delay(2000);
    lcd.clear();
    int back =analogRead(backout);
    if(back >= threshold)
    {   if(pos>=80)
        {
          for (pos = 90; pos >= 0; pos -= 1) 
          {
             inservo.write(pos);              // tell servo to go to position in variable 'pos'
             delay(30);                       // waits 15ms for the servo to reach the position
          }
          back = 0;
         }
    }
}

void close() 
{   
     if(pos<=10)
        { 
          lcd.print('Exit');
          for (pos = 0; pos <= 90; pos += 1) 
          {
             outservo.write(pos);              // tell servo to go to position in variable 'pos'
             delay(30);                       // waits 15ms for the servo to reach the position
          }
        }
    delay(1000);
    int eback =analogRead(ebackout);
    if(eback >= threshold)
    {   if(pos>=80)
        {
          for (pos = 90; pos >= 0; pos -= 1) 
          {
             outservo.write(pos);      
             delay(30);                     
          }
          eback = 0;
         }
    }
}
void loop()
{   
    front = 0;
    efront = 0;
    front = analogRead(frontout);
    if(front >= threshold)
    {
       if(count<6){
        digitalWrite(0,HIGH);
        delay(2000);
        digitalWrite(0,LOW);
        open();
    }
    else{
      digitalWrite(1,HIGH);
        delay(2000);
        digitalWrite(1,LOW);
    }
    }
    efront = analogRead(efrontout);
    if(efront >= threshold)  
    {
        close();  
    }
}
