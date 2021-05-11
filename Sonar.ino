void sonar() {
  sf = sonarf.ping_cm();
  sl = sonarl.ping_cm();
  sr = sonarr.ping_cm();
}

int readf() {
  sf = sonarf.ping_cm();
  if (sf < 15 && sf > 0) {
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(blue, LOW);
    return 1;
  }
  else return 0;
}
int readr() {
  sr = sonarr.ping_cm();
  if (sr < 15 && sr > 0) {
    digitalWrite(green, HIGH);
    delay(100);
    digitalWrite(green, LOW);
    return 1;
  }
  else return 0;
}
int readl() {
  sl = sonarl.ping_cm();
  if (sl < 15 && sl > 0) {
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(red, LOW);
    return 1;
  }
  else return 0;
}
