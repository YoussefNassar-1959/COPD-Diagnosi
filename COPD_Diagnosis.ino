#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
const float SensorOffset = 102.0;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int D2=2;//RED LED
int D3=4; //BUZZER
int D5=3; //yellow led
// the setup routine runs once when you press reset:
void setup()

{
    // initialize serial communication at 9600 bits per second:
  Serial.begin(9600) ;
    // initialize the LCD
    lcd.begin();
  
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D5,OUTPUT);
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  WELCOME TO  ");
   lcd.setCursor(0,1);
  lcd.print("  MAKER.PRO  ");
  delay(2000);
  lcd.clear();
   lcd.setCursor(0,0);
  lcd.print("BLOW The AIR ");
   lcd.setCursor(0,1);
  lcd.print("For Five Seconds");
  delay(2000);
  lcd.clear();
  lcd.print("Start Blowing");
  delay(5000);
  


    // Turn on the blacklight and print a message.

 
}

void loop()
{
  // read the input on analog pin 0:
  float sensorValue = (analogRead(A0)-SensorOffset)/100.0; //Do maths for calibration
  float total =(sensorValue*1000); //pascal
  // print out the value you read:
  //Serial.print("Air Pressure: ");  
  //Serial.print(total,2);
  //Serial.println(" Pa");

  
  lcd.clear();
  lcd.print("Spiromettery ");
  lcd.setCursor(0,1);
  lcd.print(total);
  lcd.print("  pa");
  if(total>6000) //total caliberated value is 6000 in my case
  {
    digitalWrite(D5, HIGH);
        digitalWrite(D3, HIGH);
    delay(1000);
    digitalWrite(D5, LOW);
        digitalWrite(D3, LOW);
    delay(1000);
    digitalWrite(D5, HIGH);
        digitalWrite(D3, HIGH);
    delay(1000);
    digitalWrite(D5, LOW);
        digitalWrite(D3, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("You are Normal 80%");
    lcd.setCursor(0,1);
    lcd.print(total);
    lcd.print("  pa");
    digitalWrite(D5, HIGH);
    delay(10000);
    digitalWrite(D5, LOW);
    
    
    
    }
    else if(total>4580)
    {
        digitalWrite(D5, HIGH);
        digitalWrite(D3, HIGH);
    delay(1000);
    digitalWrite(D5, LOW);
        digitalWrite(D3, LOW);
    delay(1000);
    digitalWrite(D5, HIGH);
        digitalWrite(D3, HIGH);
    delay(1000);
    digitalWrite(D5, LOW);
        digitalWrite(D3, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("You are Normal 80%");
    lcd.setCursor(0,1);
    lcd.print(total);
    lcd.print("  pa");
     digitalWrite(D5, HIGH);
    delay(10000);
         digitalWrite(D5, LOW);
   
    }
    else if (total>3200)
    
    {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("LOW 60% !");
    lcd.setCursor(0,1);
    lcd.print(total);
    lcd.print("  pa");    
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    delay(10000);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    
    }
    
  
  
  delay(100);        // delay in between reads for stability
    
}
