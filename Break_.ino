void break1() {
  turn = 0;
  cross = 0;
  k90 = 0;
  k30 = 0;
  digitalWrite(BL, HIGH);
  motor(0 * spl, 0 * spr);
  motor(-10 * spl, -10 * spr);
  delay(db);
  digitalWrite(BL, LOW);
}
void break2() {
  turn = 0;
  cross = 0;
  k90 = 0;
  k30 = 0;
  digitalWrite(BL, HIGH);
  motor(0 * spl, 0 * spr);
  motor(-10 * spl, -10 * spr);
  delay(db-50);
  digitalWrite(BL, LOW);
}
void baz(){
  digitalWrite(bazar, 1);
  delay(50);
  digitalWrite(bazar, 1);
  delay(50);
  
  }
