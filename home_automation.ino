//initializing values for all the sensors
int pirsensor=0;
int smoke = 0;
int photoresistor=0;
float temp=0;
int dist=0;
int angle=0;
//include the servo motor library, instructions included in Readme file.
#include<Servo.h>
Servo myservo;



long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}


//here we make a setup for all the pin connections done in arduino uno
void setup()
   { 
      myservo.attach(13);
      pinMode(12, OUTPUT);
      pinMode(7, INPUT);
      pinMode(6, OUTPUT);
      pinMode(5, OUTPUT);
      pinMode(4, OUTPUT);
      pinMode(A5, INPUT);
      pinMode(A4, INPUT);
      pinMode(A0, INPUT);
      pinMode(9, OUTPUT);
      Serial.begin(9600);
     }

void loop()
  { //read the pir sensor value which is digital in nature
      pirsensor=digitalRead(7);
      //read the photoresistor value which is analog in nature
      Serial.println(analogRead(A4));
      photoresistor= analogRead(A4);
      //read the smoke sensor value which is analog in nature
      Serial.println(analogRead(A5));
      smoke = analogRead(A5);
      //read the temperature sensor value which is analog in nature
      temp=analogRead(A0);
      Serial.println(analogRead(A0));
    // calculation of distance  
      dist = 0.01723 * readUltrasonicDistance(10, 10);  
  //various conditions upon which the output is given using loops
          { 
            if (pirsensor==HIGH)
                {     //light on
                    digitalWrite(6, HIGH);

                } 
            else 
                {
                    //light off
                     digitalWrite(6, LOW);  
                 }
         }


         { 
            if (photoresistor>=600)
                {    //light off
                    digitalWrite(9, LOW); 
                } 
            else 
                {
                       //light on
                    digitalWrite(9, HIGH);  
                 }
          }


          {
            if (smoke>=90)
                {   
                    //buzzer on
                    digitalWrite(12, HIGH);
                }
            else
                {   //buzzer off
                    
                    digitalWrite(12, LOW);
                }

           }
  
  

     { 
            if (temp>=150)
                {   //fan automatic on n clockwise direction
                    digitalWrite(5, HIGH);
                    digitalWrite(4, LOW);
                } 
            else 
                {
                    digitalWrite(5, LOW);
                    digitalWrite(4, LOW);
                 }
          }
  
  
  
  
          { 
             if (dist<=100)
                {  //gate opens upon anyone arrival to near by place
                    myservo.write(180);
                    delay(2000);
                    myservo.write(90);
                } 
             else 
                {
                    myservo.write(90);
                   
                 }
           }
  
  
  
  
          

  delay(1);
}
