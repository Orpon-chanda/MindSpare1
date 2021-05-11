 void motor(int a, int b){
    if (a >= 0) {
    analogWrite(lmf, a);
    analogWrite(lmb, 0);
  }
  else if (a < 0) {
    a = -a;
    analogWrite(lmb, a);
    analogWrite(lmf, 0);
  }
  if (b >= 0) {
    analogWrite(rmf, b);
    analogWrite(rmb, 0);
  }
  else if (b < 0) {
    b = -b;
    analogWrite(rmb, b);
    analogWrite(rmf, 0);
  }
  return ;
}
