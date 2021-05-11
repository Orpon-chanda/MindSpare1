void wall() {
  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
  digitalWrite(blue, HIGH);
  while (sum == 0) {
    check();
    sonar();
    if (sf < 10 && sf > 0) {
      motor(-5 * spl, -5 * spr);
      delay(50);
      motor(-8 * spl, 8 * spr);
      delay(300);
      motor(5 * spl, -5 * spr);
      delay(50);
      motor(5 * spl, 5 * spr);
      sf = sr = sl = 0;
    }
    else if (sr < 10 && sr > 0) motor(0, 5 * spr);
    else if (sl < 10 && sl > 0) motor(5 * spl, 0);
    else motor(5 * spl, 5 * spr);
  }
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
}
