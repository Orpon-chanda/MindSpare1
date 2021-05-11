void lcd_check() {
  lcd.clear();
  delay(1);
}

void analog_read() {
  while (1) {
    for (int i = 0; i < 6; i++) {
      s[i] = analogRead(i);
      lcd.setCursor(lcd_cursor1[i], lcd_cursor2[i]);
      lcd.print(s[i]);
    }
    lcd.print(" ");
    delay(150);
    lcd.clear();
  }
}

void sonar_read() {
  while (1) {
    lcd.clear();
    sonar();
    lcd.setCursor(6 , 0);
    lcd.print("Sonar");
    lcd.setCursor(2 , 1);
    lcd.print(sl);
    lcd.setCursor(7 , 1);
    lcd.print(sf);
    lcd.setCursor(12 , 1);
    lcd.print(sr);
    delay(150);
  }
}

void digital_read() {

  while (1) {
    check();
    lcd_check();
    for (int i = 0; i < 6; i++) {
      lcd.setCursor(lcd_cursor3[5 - i], 0);
      lcd.print(s[i]);
    }
    lcd.print(" ");
    delay(150);
    lcd.clear();
  }
}
void break_adj() {
  int list = 200,
      readl();
  readr();
  readf();
  while (1) {

    lcd.setCursor(6 , 0);
    lcd.print("Break");
    lcd.setCursor(7 , 1);
    lcd.print(db);
    if (readr()) {
      delay(200);
      if (db < list) db = db + 10;
    }
    else if (readl()) {
      delay(200);
      lcd.clear();
      if (db > 0) db = db - 10;

    }
    else if (readf()) {
      EEPROM.write(10, db);
      return;
    }

  }
}
void motor_speed() {
  int list = 25,
      readl();
  readr();
  readf();
  while (1) {
    lcd.setCursor(3 , 0);
    lcd.print("Motor_Speed");
    lcd.setCursor(7 , 1);
    lcd.print(m);
    if (readr()) {
      delay(200);
      if (m < list) m++;

    }
    else if (readl()) {
      delay(200);
      if (m  > 1) m --;
    }
    else if (readf()) {
      EEPROM.write(9, m);
      return;
    }
  }
}
void calibration() {
  float list = 0.9;
  while (1) {
    lcd.setCursor(4 , 0);
    lcd.print("Cal Level");
    lcd.setCursor(7 , 1);
    lcd.print(ca, 1);
    if (readr()) {
      delay(200);
      if (ca < list) ca = ca + 0.1;

    }
    else if (readl()) {
      delay(200);
      if (ca  > 0.1) ca = ca - 0.1;
    }
    else if (readf()) {
      EEPROM.put(11, ca);
      return;
    }
  }

}
void turn_delay() {
  int list = 80;
  while (1) {
    lcd.setCursor(3 , 0);
    lcd.print("Trun Delay");
    lcd.setCursor(7 , 1);
    lcd.print(dh);
    if (readr()) {
      delay(200);
      if (dh < list) dh = dh + 5;

    }
    else if (readl()) {
      delay(200);
      lcd.clear();
      if (dh  > 4) dh = dh - 5;
    }
    else if (readf()) {
      EEPROM.write(12, dh);
      return;
    }
  }

}

void color_maj() {
  while (1) {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("Color");
    color();
    if (rr < bb && rr < gg) {
      lcd.setCursor(6, 1);
      lcd.print("RED");
    }
    else if (gg < bb && gg < rr) {
      lcd.setCursor(5, 1);
      lcd.print("GREEN");
    }
    else {
      lcd.setCursor(6, 1);
      lcd.print("BLUE");
    }
    delay(100);
  }
}
