int switch1 () {
  int t = 0, cl = 0, list = 7;
  readf();
  if (readf() == 1) {
    while (readf() == 1);
    while (1) {
      if (cl != menu) {
        cl = menu;
        if (cl == 1) {
          lcd_check();
          lcd.setCursor(2, 0);
          lcd.print("Line Follwer");
          lcd.setCursor(0, 1);
          lcd.print("C:");
          lcd.setCursor(2, 1);
          lcd.print(counter);
          lcd.setCursor(5, 1);
          lcd.print("M:");
          lcd.setCursor(7, 1);
          lcd.print(m);
          lcd.setCursor(11, 1);
          lcd.print("B:");
          lcd.setCursor(13, 1);
          lcd.print(db);
        }
        else if (cl == 2)  {
          lcd_check();
          lcd.setCursor(3, 0);
          lcd.print("Calibration");
          lcd.setCursor(7, 1);
          lcd.print(ca, 1);
        }
        else if (cl == 3) {
          lcd_check();
          lcd.setCursor(3, 0);
          lcd.print("Analog Read");
        }
        else if (cl == 4) {
          lcd_check();
          lcd.setCursor(3, 0);
          lcd.print("Digital Read");
        }

        else if (cl == 5) {
          lcd_check();
          lcd.setCursor(1, 0);
          lcd.print("Robot Position");
        }
        else if (cl == 6) {
          lcd_check();
          lcd.setCursor(5, 0);
          lcd.print("Sonar");
        }
        else if (cl == 7) {
          lcd.setCursor(5, 0);
          lcd.print("Color");
        }
      }

      if (readr()) {
        delay(200);
        if (menu < list) menu++;

      }
      else if (readl()) {
        delay(200);
        if (menu > 1) menu--;
      }

      else if (readf() == 1) {
        t = 0;
        while(readf() == 1){
        t++;
        if(t >= 10){
          digitalWrite(bazar, 1);
          while(readf() == 1);
          digitalWrite(bazar, 0);
          lcd_check();
          delay(500);
          return list + 1;
        }
      }
        return cl;
      }
    }
  }
  return cl;
}// khgioserhigerlkgerklkblerjgkerjg////


int switch3 () {
  readl();
  int t = 0, cl = -1, list = 4;
  if (readl() == 1) {
    while (readl() ==  1);
    while (1) {

      if (cl != menu) {
        cl = menu;
        if (cl == 1) {
          lcd_check();
          lcd.setCursor(3, 0);
          lcd.print("Motor_Speed");
          if (readf()) {
            lcd_check();
            delay(500);
            return;
          }
        }
        else if (cl == 2)  {
          lcd_check();
          lcd.setCursor(6, 0);
          lcd.print("Break");
        }
        else if (cl == 3)  {
          lcd_check();
          lcd.setCursor(4, 0);
          lcd.print("Cal Level");
        }
        else if (cl == 4)  {
          lcd_check();
          lcd.setCursor(3, 0);
          lcd.print("Trun Delay");
        }
      }
      if (readf() && menu == 1) {
        delay(200);
        motor_speed();
        if (readf()) {
          lcd_check();
          delay(500);
          return;
        }
      }
      else if (readf() && menu == 2 ) {
        delay(200);
        break_adj();
        if (readf()) {
          lcd_check();
          delay(500);
          return;
        }
      }
      else if (readf() && menu == 3 ) {
        delay(200);
        calibration();
        if (readf()) {
          lcd_check();
          delay(500);
          return;
        }
      }
      else if (readf() && menu == 4 ) {
        delay(200);
        turn_delay();
        if (readf()) {
          lcd_check();
          delay(500);
          return;
        }
      }

      else if (readr()) {
        delay(200);
        if (menu  < list) menu++;

      }
      else if (readl()) {
        delay(200);
        if (menu  > 1) menu --;
      }
      //    else if (readf()) {
      //      lcd_check();
      //      delay(1000);
      //      return;
      //  }
    }
  }
  //  return cl;
}

void switch2 () {
  int t = 0, cl = -1, list = 10;
  readr();

  if (readr() == 1) {
    while (readr() == 1);
    while (1) {
      if (cl != counter) {
        cl = counter;
        lcd_check();
        lcd.setCursor(5, 0);
        lcd.print("Counter");
        lcd.setCursor(7, 1);
        lcd.print(cl);
      }

      if (readr()) {
        delay(200);
        if (counter < list) counter++;

      }
      else if (readl()) {
        delay(200);
        if (counter > 0) counter--;
      }

      else if (readf()) {
        lcd_check();
        EEPROM.write(8, counter);
        delay(1000);
        return;
      }
    }
  }
}
// khgioserhigerlkgerklkblerjgkerjg////
