#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int score = 0;
bool left_pressed = false;
bool right_pressed = false;
bool lefton = false;
bool righton = false;
int leftnote = 16;
int rightnote = 16;
int leftmod = 0;
int rightmod = 0;
int speed = 2;
void setup()
{
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  lcd.begin(16, 2);        
  lcd.clear();
}
void loop() 
{
  uint8_t note_right_first[8] = {0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x00};
  uint8_t note_left_first[8] = {0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00};
  uint8_t note_right_second[8] = {0x00,0x00,0x00,0x03,0x03,0x03,0x00,0x00};
  uint8_t note_left_second[8] = {0x00,0x00,0x03,0x03,0x03,0x00,0x00,0x00};
  uint8_t note_right_third[8] = {0x00,0x00,0x00,0x07,0x07,0x07,0x00,0x00};
  uint8_t note_left_third[8] = {0x00,0x00,0x07,0x07,0x07,0x00,0x00,0x00};
  uint8_t note_right_fourth[8] = {0x00,0x00,0x00,0x0F,0x0F,0x0F,0x00,0x00};
  uint8_t note_left_fourth[8] = {0x00,0x00,0x0F,0x0F,0x0F,0x00,0x00,0x00};
  uint8_t note_right_middle[8] = {0x00,0x00,0x00,0x1F,0x1F,0x1F,0x00,0x00};
  uint8_t note_left_middle[8] = {0x00,0x00,0x1F,0x1F,0x1F,0x00,0x00,0x00};
  uint8_t note_right_fifth[8] = {0x00,0x00,0x00,0x1E,0x1E,0x1E,0x00,0x00};
  uint8_t note_left_fifth[8] = {0x00,0x00,0x1E,0x1E,0x1E,0x00,0x00,0x00};
  uint8_t note_right_sixth[8] = {0x00,0x00,0x00,0x1C,0x1C,0x1C,0x00,0x00};
  uint8_t note_left_sixth[8] = {0x00,0x00,0x1C,0x1C,0x1C,0x00,0x00,0x00};
  uint8_t note_right_seventh[8] = {0x00,0x00,0x00,0x18,0x18,0x18,0x00,0x00};
  uint8_t note_left_seventh[8] = {0x00,0x00,0x18,0x18,0x18,0x00,0x00,0x00};
  uint8_t note_right_eighth[8] = {0x00,0x00,0x00,0x10,0x10,0x10,0x00,0x00};
  uint8_t note_left_eighth[8] = {0x00,0x00,0x10,0x10,0x10,0x00,0x00,0x00};
  while (true)
  {
    lefton = false;
    for(char i=0; i<50; i++)
    {
      base();
    }
    for(char i=0; i<5; i++)
    {
      left();
    }
    for(char i=0; i<9; i++)
    {
      both();
    }
    lcd.clear();
    right();
    lcd.createChar(7, note_left_middle);
    lcd.setCursor(2, 0);
    lcd.write(7);
    base();
    check();
    lefton = true;
    lcd.createChar(7, note_left_fifth);
    base();
    check();
    lcd.createChar(7, note_left_sixth);
    base();
    check();
    lcd.createChar(7, note_left_seventh);
    base();
    check();
    lcd.createChar(7, note_left_eighth);
    base();
    check();
    lcd.clear();
    base();
    check();
    lcd.createChar(7, note_left_first);
    lcd.setCursor(1, 0);
    lcd.write(7);
    base();
    check();
    lcd.createChar(7, note_left_second);
    base();
    check();
    lcd.createChar(7, note_left_third);
    base();
    check();
    lcd.createChar(7, note_left_fourth);
    lefton = false;
    for(char i=0; i<4; i++)
    {
      right();
    }
    lcd.createChar(7, note_right_middle);
    lcd.setCursor(8, 1);
    lcd.write(7);
    righton = true;
    lcd.createChar(8, note_right_fifth);
    base();
    check();
    lcd.createChar(8, note_right_sixth);
    base();
    check();
    lcd.createChar(8, note_right_seventh);
    base();
    check();
    lcd.createChar(8, note_right_eighth);
    base();
    check();
    lcd.clear();
    base();
    check();
    lcd.createChar(8, note_right_first);
    lcd.setCursor(1, 1);
    lcd.write(8);
    base();
    check();
    lcd.createChar(8, note_right_second);
    base();
    check();
    lcd.createChar(8, note_right_third);
    base();
    check();
    lcd.createChar(8, note_right_fourth);
    righton = false;
    leftnote = 16;
    rightnote = 16;
    leftmod = 3;
    rightmod = 3;
    left();
    for(char i=0; i<13; i++)
    {
      both();
    }
    leftnote = 6;
    leftmod = 0;
    both();
    lcd.createChar(7, note_left_middle);
    lcd.setCursor(2, 0);
    lcd.write(7);
    base();
    check();
    lefton = true;
    lcd.createChar(7, note_left_fifth);
    base();
    check();
    lcd.createChar(7, note_left_sixth);
    base();
    check();
    lcd.createChar(7, note_left_seventh);
    base();
    check();
    lcd.createChar(7, note_left_eighth);
    base();
    check();
    lcd.clear();
    base();
    check();
    lcd.createChar(7, note_left_first);
    lcd.setCursor(1, 0);
    lcd.write(7);
    base();
    check();
    lcd.createChar(7, note_left_second);
    base();
    check();
    lcd.createChar(7, note_left_third);
    base();
    check();
    lcd.createChar(7, note_left_fourth);
    leftnote = 1;
    lefton = false;
    rightnote = 6;
    rightmod = 0;
    both();
    lcd.createChar(3, note_right_middle);
    lcd.setCursor(8, 1);
    lcd.write(8);
    base();
    check();
    righton = true;
    lcd.createChar(8, note_right_fifth);
    base();
    check();
    lcd.createChar(8, note_right_sixth);
    base();
    check();
    lcd.createChar(8, note_right_seventh);
    base();
    check();
    lcd.createChar(8, note_right_eighth);
    base();
    check();
    lcd.clear();
    base();
    check();
    lcd.createChar(8, note_right_first);
    lcd.setCursor(1, 1);
    lcd.write(8);
    base();
    check();
    lcd.createChar(8, note_right_second);
    base();
    check();
    lcd.createChar(8, note_right_third);
    base();
    check();
    lcd.createChar(8, note_right_fourth);
    righton = false;
    both();
    lcd.createChar(7, note_left_middle);
    lcd.setCursor(2, 0);
    lcd.write(7);
    base();
    check();
    lefton = true;
    lcd.createChar(7, note_left_fifth);
    base();
    check();
    lcd.createChar(7, note_left_sixth);
    base();
    check();
    lcd.createChar(7, note_left_seventh);
    base();
    check();
    lcd.createChar(7, note_left_eighth);
    base();
    check();
    lcd.clear();
    base();
    check();
    lcd.createChar(7, note_left_first);
    lcd.setCursor(1, 0);
    lcd.write(7);
    base();
    check();
    lcd.createChar(7, note_left_second);
    base();
    check();
    lcd.createChar(7, note_left_third);
    base();
    check();
    lcd.createChar(7, note_left_fourth);
    lefton = false;
    lcd.createChar(8, note_right_middle);
    lcd.setCursor(2, 1);
    lcd.write(8);
    base();
    check();
    righton = true;
    lcd.createChar(8, note_right_fifth);
    base();
    check();
    lcd.createChar(8, note_right_sixth);
    base();
    check();
    lcd.createChar(8, note_right_seventh);
    base();
    check();
    lcd.createChar(8, note_right_eighth);
    base();
    check();
    lcd.clear();
    base();
    check();
    lcd.createChar(8, note_right_first);
    lcd.setCursor(1, 1);
    lcd.write(8);
    base();
    check();
    lcd.createChar(8, note_right_second);
    base();
    check();
    lcd.createChar(8, note_right_third);
    base();
    check();
    lcd.createChar(8, note_right_fourth);
    rightnote = 1;
    righton = false;
    leftnote = 16;
    left();
    left();
    leftmod = 2;
    left();
    rightnote = 16;
    for(char i=0; i<11; i++)
    {
      both();
    }
    lcd.createChar(7, note_left_middle);
    lcd.setCursor(2, 0);
    lcd.write(7);
    base();
    check();
    lefton = true;
    lcd.createChar(7, note_left_fifth);
    base();
    check();
    lcd.createChar(7, note_left_sixth);
    base();
    check();
    lcd.createChar(7, note_left_seventh);
    base();
    check();
    lcd.createChar(7, note_left_eighth);
    base();
    check();
    lcd.clear();
    base();
    check();
    lcd.createChar(7, note_left_first);
    lcd.setCursor(1, 0);
    lcd.write(3);
    base();
    check();
    lcd.createChar(7, note_left_second);
    base();
    check();
    lcd.createChar(7, note_left_third);
    base();
    check();
    lcd.createChar(7, note_left_fourth);
    lefton = false;
    leftnote = 4;
    leftmod = 0;
    both();
    both();
    lcd.createChar(7, note_left_middle);
    lcd.setCursor(2, 0);
    lcd.write(7);
    base();
    check();
    lefton = true;
    lcd.createChar(7, note_left_fifth);
    base();
    check();
    lcd.createChar(7, note_left_sixth);
    base();
    check();
    lcd.createChar(7, note_left_seventh);
    base();
    check();
    lcd.createChar(7, note_left_eighth);
    base();
    check();
    lcd.clear();
    base();
    check();
    lcd.createChar(7, note_left_first);
    lcd.setCursor(1, 0);
    lcd.write(7);
    base();
    check();
    lcd.createChar(7, note_left_second);
    base();
    check();
    lcd.createChar(7, note_left_third);
    base();
    check();
    lcd.createChar(7, note_left_fourth);
    lefton = false;
    right();
    lcd.createChar(8, note_right_middle);
    lcd.setCursor(2, 1);
    lcd.write(8);
    base();
    check();
    righton = true;
    lcd.createChar(8, note_right_fifth);
    base();
    check();
    lcd.createChar(8, note_right_sixth);
    base();
    check();
    lcd.createChar(8, note_right_seventh);
    base();
    check();
    lcd.createChar(8, note_right_eighth);
    base();
    check();
    lcd.clear();
    base();
    check();
    lcd.createChar(8, note_right_first);
    lcd.setCursor(1, 1);
    lcd.write(3);
    base();
    check();
    lcd.createChar(8, note_right_second);
    base();
    check();
    lcd.createChar(8, note_right_third);
    base();
    check();
    lcd.createChar(8, note_right_fourth);
    righton = false;
    rightnote = 16;
    leftnote = 16;
    for(char i=0; i<14; i++)
    {
      both();
    }
    lcd.createChar(8, note_right_middle);
    lcd.createChar(7, note_left_middle);
    lcd.setCursor(2, 1);
    lcd.write(8);
    lcd.setCursor(2, 0);
    lcd.write(7);
    base();
    check();
    righton = true;
    lefton = true;
    lcd.createChar(8, note_right_fifth);
    lcd.createChar(7, note_left_fifth);
    base();
    check();
    lcd.createChar(8, note_right_sixth);
    lcd.createChar(7, note_left_sixth);
    base();
    check();
    lcd.createChar(8, note_right_seventh);
    lcd.createChar(7, note_left_seventh);
    base();
    check();
    lcd.createChar(8, note_right_eighth);
    lcd.createChar(7, note_left_eighth);
    base();
    check();
    lcd.clear();
    base();
    check();
    lcd.createChar(8, note_right_first);
    lcd.setCursor(1, 1);
    lcd.write(8);
    lcd.createChar(7, note_left_first);
    lcd.setCursor(1, 0);
    lcd.write(7);
    base();
    check();
    lcd.createChar(8, note_right_second);
    lcd.createChar(7, note_left_second);
    base();
    check();
    lcd.createChar(8, note_right_third);
    lcd.createChar(8, note_right_third);
    base();
    check();
    lcd.createChar(8, note_right_fourth);
    lcd.createChar(7, note_left_fourth);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(score);
    delay(10000);
    lcd.clear();
    lefton = false;
    righton = false;
    leftnote = 16;
    rightnote = 16;
    leftmod = 0;
    rightmod = 0;
  }
}
void base()
{
  uint8_t base_left_none[8] = {0x00,0x0E,0x11,0x11,0x11,0x0E,0x00,0x00};
  uint8_t base_right_none[8] = {0x00,0x00,0x0E,0x11,0x11,0x11,0x0E,0x00};
  uint8_t base_left_none_pressed[8] = {0x00,0x11,0x00,0x00,0x00,0x11,0x00,0x00};
  uint8_t base_right_none_pressed[8] = {0x00,0x00,0x11,0x00,0x00,0x00,0x11,0x00};
  uint8_t base_left_fail[8] = {0x00,0x0E,0x1F,0x1F,0x1F,0x0E,0x00,0x00};
  uint8_t base_right_fail[8] = {0x00,0x00,0x0E,0x1F,0x1F,0x1F,0x0E,0x00};
  uint8_t base_left_success[8] = {0x00,0x11,0x0E,0x0E,0x0E,0x11,0x00,0x00};
  uint8_t base_right_success[8] = {0x00,0x00,0x11,0x0E,0x0E,0x0E,0x11,0x00};
  if (digitalRead(7) == LOW)
  {
    if (lefton == true)
    {
      lcd.createChar(1, base_left_success);
    }
    else
    {
      lcd.createChar(1, base_left_none_pressed);
    }
    left_pressed = true;
  }
  else
  {
    if (lefton == true)
    {
      lcd.createChar(1, base_left_fail);
    }
    else
    {
      lcd.createChar(1, base_left_none);
    }
  }
  lcd.setCursor(1, 0);
  lcd.write(1);
  if (digitalRead(6) == LOW)
  {
    if (righton == true)
    {
      lcd.createChar(2, base_right_success);
    }
    else
    {
      lcd.createChar(2, base_right_none_pressed);
    }
    right_pressed = true;
  }
  else
  {
    if (righton == true)
    {
      lcd.createChar(2, base_right_fail);
    }
    else
    {
      lcd.createChar(2, base_right_none);
    }
  }
  lcd.setCursor(1, 1);
  lcd.write(2);
}
void check()
{
  if (left_pressed == true)
  {
    if (lefton == true)
    {
      score = score + 1;
    }
    else
    {
      score = score -1;
    }
    left_pressed = false;
  }
  if (right_pressed == true)
  {
    if (righton == true)
    {
      score = score + 1;
    }
    else
    {
      score = score -1;
    }
    right_pressed = false;
  }
}
void left()
{
  uint8_t note_left_first[8] = {0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00};
  uint8_t note_left_second[8] = {0x00,0x00,0x03,0x03,0x03,0x00,0x00,0x00};
  uint8_t note_left_third[8] = {0x00,0x00,0x07,0x07,0x07,0x00,0x00,0x00};
  uint8_t note_left_fourth[8] = {0x00,0x00,0x0F,0x0F,0x0F,0x00,0x00,0x00};
  uint8_t note_left_middle[8] = {0x00,0x00,0x1F,0x1F,0x1F,0x00,0x00,0x00};
  uint8_t note_left_fifth[8] = {0x00,0x00,0x1E,0x1E,0x1E,0x00,0x00,0x00};
  uint8_t note_left_sixth[8] = {0x00,0x00,0x1C,0x1C,0x1C,0x00,0x00,0x00};
  uint8_t note_left_seventh[8] = {0x00,0x00,0x18,0x18,0x18,0x00,0x00,0x00};
  uint8_t note_left_eighth[8] = {0x00,0x00,0x10,0x10,0x10,0x00,0x00,0x00};
  check();
  base();
  lcd.createChar(3, note_left_middle);
  lcd.setCursor(leftnote, 0);
  lcd.write(3);
  lcd.setCursor(leftnote + leftmod, 0);
  lcd.write(3);
  for(char i=0; i<speed; i++)
  {
    base();
  }
  check();
  lcd.createChar(3, note_left_fifth);
  lcd.createChar(4, note_left_first);
  lcd.setCursor(leftnote - 1, 0);
  lcd.write(4);
  lcd.setCursor(leftnote + leftmod - 1, 0);
  lcd.write(4);
  for(char i=0; i<speed; i++)
  {
    base();
  }
  check();
  lcd.createChar(3, note_left_sixth);
  lcd.createChar(4, note_left_second);
  for(char i=0; i<speed; i++)
  {
    base();
  }
  check();
  lcd.createChar(3, note_left_seventh);
  lcd.createChar(4, note_left_third);
  for(char i=0; i<speed; i++)
  {
    base();
  }
  check();
  lcd.createChar(3, note_left_eighth);
  lcd.createChar(4, note_left_fourth);
  for(char i=0; i<speed; i++)
  {
    base();
  }
  check();
  lcd.setCursor(leftnote, 0);
  lcd.print(" ");
  lcd.setCursor(leftnote + leftmod, 0);
  lcd.print(" ");
  leftnote = leftnote - 1;
}
void right()
{
  uint8_t note_right_first[8] = {0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x00};
  uint8_t note_right_second[8] = {0x00,0x00,0x00,0x03,0x03,0x03,0x00,0x00};
  uint8_t note_right_third[8] = {0x00,0x00,0x00,0x07,0x07,0x07,0x00,0x00};
  uint8_t note_right_fourth[8] = {0x00,0x00,0x00,0x0F,0x0F,0x0F,0x00,0x00};
  uint8_t note_right_middle[8] = {0x00,0x00,0x00,0x1F,0x1F,0x1F,0x00,0x00};
  uint8_t note_right_fifth[8] = {0x00,0x00,0x00,0x1E,0x1E,0x1E,0x00,0x00};
  uint8_t note_right_sixth[8] = {0x00,0x00,0x00,0x1C,0x1C,0x1C,0x00,0x00};
  uint8_t note_right_seventh[8] = {0x00,0x00,0x00,0x18,0x18,0x18,0x00,0x00};
  uint8_t note_right_eighth[8] = {0x00,0x00,0x00,0x10,0x10,0x10,0x00,0x00};
  check();
  base();
  lcd.createChar(5, note_right_middle);
  lcd.setCursor(rightnote, 1);
  lcd.write(5);
  lcd.setCursor(rightnote + rightmod, 1);
  lcd.write(5);
  for(char i=0; i<speed; i++)
  {
    base();
  }
  check();
  lcd.createChar(5, note_right_fifth);
  lcd.createChar(6, note_right_first);
  lcd.setCursor(rightnote - 1, 1);
  lcd.write(6);
  lcd.setCursor(rightnote + rightmod - 1, 1);
  lcd.write(6);
  for(char i=0; i<speed; i++)
  {
    base();
  }
  check();
  lcd.createChar(5, note_right_sixth);
  lcd.createChar(6, note_right_second);
  for(char i=0; i<speed; i++)
  {
    base();
  }
  check();
  lcd.createChar(5, note_right_seventh);
  lcd.createChar(6, note_right_third);
  for(char i=0; i<speed; i++)
  {
    base();
  }
  check();
  lcd.createChar(5, note_right_eighth);
  lcd.createChar(6, note_right_fourth);
  for(char i=0; i<speed; i++)
  {
    base();
  }
  check();
  lcd.setCursor(rightnote, 1);
  lcd.print(" ");
  lcd.setCursor(rightnote + rightmod, 1);
  lcd.print(" ");
  rightnote = rightnote - 1;
}
void both()
{
  uint8_t note_right_first[8] = {0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x00};
  uint8_t note_left_first[8] = {0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00};
  uint8_t note_right_second[8] = {0x00,0x00,0x00,0x03,0x03,0x03,0x00,0x00};
  uint8_t note_left_second[8] = {0x00,0x00,0x03,0x03,0x03,0x00,0x00,0x00};
  uint8_t note_right_third[8] = {0x00,0x00,0x00,0x07,0x07,0x07,0x00,0x00};
  uint8_t note_left_third[8] = {0x00,0x00,0x07,0x07,0x07,0x00,0x00,0x00};
  uint8_t note_right_fourth[8] = {0x00,0x00,0x00,0x0F,0x0F,0x0F,0x00,0x00};
  uint8_t note_left_fourth[8] = {0x00,0x00,0x0F,0x0F,0x0F,0x00,0x00,0x00};
  uint8_t note_right_middle[8] = {0x00,0x00,0x00,0x1F,0x1F,0x1F,0x00,0x00};
  uint8_t note_left_middle[8] = {0x00,0x00,0x1F,0x1F,0x1F,0x00,0x00,0x00};
  uint8_t note_right_fifth[8] = {0x00,0x00,0x00,0x1E,0x1E,0x1E,0x00,0x00};
  uint8_t note_left_fifth[8] = {0x00,0x00,0x1E,0x1E,0x1E,0x00,0x00,0x00};
  uint8_t note_right_sixth[8] = {0x00,0x00,0x00,0x1C,0x1C,0x1C,0x00,0x00};
  uint8_t note_left_sixth[8] = {0x00,0x00,0x1C,0x1C,0x1C,0x00,0x00,0x00};
  uint8_t note_right_seventh[8] = {0x00,0x00,0x00,0x18,0x18,0x18,0x00,0x00};
  uint8_t note_left_seventh[8] = {0x00,0x00,0x18,0x18,0x18,0x00,0x00,0x00};
  uint8_t note_right_eighth[8] = {0x00,0x00,0x00,0x10,0x10,0x10,0x00,0x00};
  uint8_t note_left_eighth[8] = {0x00,0x00,0x10,0x10,0x10,0x00,0x00,0x00};
  check();
  base();
  lcd.createChar(3, note_left_middle);
  lcd.setCursor (leftnote, 0);
  lcd.write(3);
  lcd.setCursor(leftnote + leftmod, 0);
  lcd.write(3);
  lcd.createChar(5, note_right_middle);
  lcd.setCursor(rightnote, 1);
  lcd.write(5);
  lcd.setCursor(rightnote + rightmod, 1);
  lcd.write(5);
  for(char i=0; i<speed/2; i++)
  {
    base();
  }
  check();
  lcd.createChar(3, note_left_fifth);
  lcd.createChar(4, note_left_first);
  lcd.setCursor(leftnote - 1, 0);
  lcd.write(4);
  lcd.setCursor(leftnote + leftmod - 1, 0);
  lcd.write(4);
  lcd.createChar(5, note_right_fifth);
  lcd.createChar(6, note_right_first);
  lcd.setCursor(rightnote - 1, 1);
  lcd.write(6);
  lcd.setCursor(rightnote + rightmod - 1, 1);
  lcd.write(6);
  for(char i=0; i<speed/2; i++)
  {
    base();
  }
  check();
  lcd.createChar(3, note_left_sixth);
  lcd.createChar(4, note_left_second);
  lcd.createChar(5, note_right_sixth);
  lcd.createChar(6, note_right_second);
  for(char i=0; i<speed/2; i++)
  {
    base();
  }
  check();
  lcd.createChar(3, note_left_seventh);
  lcd.createChar(4, note_left_third);
  lcd.createChar(5, note_right_seventh);
  lcd.createChar(6, note_right_third);
  for(char i=0; i<speed/2; i++)
  {
    base();
  }
  check();
  lcd.createChar(5, note_left_eighth);
  lcd.createChar(6, note_left_fourth);
  lcd.createChar(5, note_right_eighth);
  lcd.createChar(6, note_right_fourth);
  for(char i=0; i<speed/2; i++)
  {
    base();
  }
  check();
  lcd.setCursor(leftnote, 0);
  lcd.print(" ");
  lcd.setCursor(rightnote, 1);
  lcd.print(" ");
  lcd.setCursor(leftnote + leftmod, 0);
  lcd.print(" ");
  lcd.setCursor(rightnote + rightmod, 1);
  lcd.print(" ");
  rightnote = rightnote - 1;
  leftnote = leftnote - 1;
}