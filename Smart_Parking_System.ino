#include <LiquidCrystal.h>

#include <Servo.h>



Servo s1, s2;

#define IR_Slot1 7
#define IR_Slot2 8
#define IR_entry 6
#define IR_exit 13

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  s1.attach(10);
  s2.attach(9);
  
  s1.write(0);
  s2.write(0);
  
  pinMode(IR_Slot1, INPUT);
  pinMode(IR_Slot2, INPUT);
  pinMode(IR_entry, INPUT);
  pinMode(IR_exit, INPUT);
  
  lcd.begin(16, 2);
  lcd.print("Smart Parking");
  lcd.setCursor(0,1);
  lcd.print("   System");
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Slot 1 = A  ");
  lcd.setCursor(0,1);
  lcd.print("Slot 2 = A  ");
  delay(2000);
}

void loop()
{
  // Update Slot 1 Status
  if(digitalRead(IR_Slot1) == HIGH)
  {
    lcd.setCursor(0, 0);
    lcd.print("Slot 1 = NA ");
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("Slot 1 = A  ");
  }

  // Update Slot 2 Status
  if(digitalRead(IR_Slot2) == HIGH)
  {
    lcd.setCursor(0, 1);
    lcd.print("Slot 2 = NA ");
  }
  else
  {
    lcd.setCursor(0, 1);
    lcd.print("Slot 2 = A  ");
  }

  // Entry Gate Control
  if(digitalRead(IR_entry) == HIGH)
  {
    delay(200);  // Debounce
    if(digitalRead(IR_entry) == HIGH)
    {
      s1.write(90);
      delay(1000);
      s1.write(0);
    }
  }

  // Exit Gate Control
  if(digitalRead(IR_exit) == HIGH)
  {
    delay(200);  // Debounce
    if(digitalRead(IR_exit) == HIGH)
    {
      s2.write(90);
      delay(1000);
      s2.write(0);
    }
  }
}
