void color() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  rr = pulseIn(sensorOut, LOW);
  rr = rr + 100;
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  gg = pulseIn(sensorOut, LOW);
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  bb = pulseIn(sensorOut, LOW); 
  bb = bb + 50;
}
