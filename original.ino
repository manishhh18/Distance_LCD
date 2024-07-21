#include <LiquidCrystal.h>
int Trigpin =9;
int Echopin =8;
LiquidCrystal LCD(1,2,4,5,6,7);
long Duration;
int DistanceCM, DistanceINCH;

void setup(){
    Serial.begin(9600);
    LCD.begin(16,2);
    pinMode(Trigpin,OUTPUT);
    pinMode(Echopin,INPUT);
}

void loop(){
    digitalWrite(Trigpin,LOW);
    delay(2);

    digitalWrite(Trigpin,HIGH);
    delay(10);
    digitalWrite(Trigpin,LOW);

    Duration = pulseIn(Echopin,HIGH);

    DistanceCM = Duration*0.034/2;
    DistanceINCH = Duration*0.0133/2;

    LCD.setCursor(0,0);
    LCD.print("Distance: ");
    LCD.print(DistanceCM);
    LCD.print("cm");
    delay(10);

    LCD.setCursor(0,1);
    LCD.print("Distance: ");
    LCD.print(DistanceINCH);
    LCD.print("inch");
    delay(10);

}

