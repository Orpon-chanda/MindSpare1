
void debug() {
  sonar();
  for (int i = 5; i >= 0; i--) {
    Serial.print(s[i]);
    Serial.print(" ");
  }
  Serial.print(" ");
  Serial.print(sum);
  Serial.print(" ");
  Serial.print(data);
  Serial.print(" ");
  Serial.print(sf);


}
