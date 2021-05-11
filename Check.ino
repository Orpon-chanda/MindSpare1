
void check() {
  data = 0;
  sum = 0;
  for (int i = 0; i < 6; i++) {
    s[i] = analogRead(i);
    if (s[i] > trash[i]){
      s[i] = 1;
    }
    else s[i] = 0;
    data += s[i] * binary[i];
    sum += s[i];
    
  }
}
