void cal() {
  int i = 0;
  delay(200);
  digitalWrite(blue, HIGH);
  motor(-250, 250);
  for (int c = 0; c < 5000 ; c++)
    for (i = 0; i < 6; i++) {
      (i < 4) ?  s[i] = analogRead(i) : s[i] = analogRead(i + 2);
      maximum[i] = max(maximum[i], s[i]);
      minimum[i] = min(minimum[i], s[i]);
    }
  motor(0, 0);
  for (i = 0; i < 6; i++) {
    trash[i] = (( maximum[i] + minimum[i]) * ca);
    EEPROM.write(i, trash[i] / 5 );
    delay(10);
  }
  digitalWrite(blue, LOW);
  return;
}
