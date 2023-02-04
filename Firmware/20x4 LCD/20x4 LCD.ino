#include <LiquidCrystal.h>

int bad = 0;
int good = 0;
int total = 0;

void LCD_print();

LiquidCrystal lcd(4, 5, 6, 7, 8, 9);

void setup() 
{  
  for(int i=2 ; i<4 ; i++)
  {
    pinMode(i , INPUT);
  }
  lcd.begin(20, 4);
  lcd.print("Working of EEPROM");
  lcd.setCursor(0, 1);
  lcd.print("By Sai Krishna");
  lcd.clear();  
}

void loop() 
{
  if(digitalRead(2))
  {
    good++;
  }
  if(digitalRead(3))
  {
    bad++;
  }
  total = good + bad ;
  LCD_print();
  
}
void LCD_print()
{
  lcd.clear();

  lcd.print("Bad Products : ");
  lcd.print(bad);

  lcd.setCursor(0, 1);
  lcd.print("Good Products : ");
  lcd.print(good);
  
  lcd.setCursor(0, 2);
  lcd.print("Total Products : ");
  lcd.print(total);

  delay(500);
}
