#include <EEPROM.h>
#include<NewPing.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define S0 26
#define S1 24
#define S2 30
#define S3 28
#define sensorOut 32
int vcc = 34;
int gnd = 22;
int rr = 0;
int gg = 0;
int bb = 0;
int s[6];
int sum , data;
int binary[] = {1, 2, 4, 8, 16, 32};
int dt = 15;
int u;
int counter = 0;
int m = 0;
int dh = 0;
int turn = 0, cross = 0, k = 0 ;
long int mi1, mi2, mi3, mi4, mi5, mi6;
int k90 = 0;
int k30 = 0;
int tht = 120;
int trash[] = {0, 0, 0, 0, 0, 0};
int menu = 1;
int db = 0;
float ca = 0.0;
int mode = 0;
//.................................Motor............................//
int lmf = 4, lmb = 5, rmf = 2, rmb = 3;
int spl = 25, spr = 25;
//...................................................................//
//.................................Display............................//
int lcd_cursor1[6] = {0, 5, 10, 0, 5, 10};
int lcd_cursor2[6] = {0, 0, 0, 1, 1, 1};
int lcd_cursor3[6] = {2, 4, 6, 8, 10, 12};
//..................................................................//
//.................................Calibration............................//
int maximum [] = {0, 0, 0, 0, 0, 0};
int minimum [] = {1024, 1024, 1024, 1024, 1024, 1024};
//.......................................................................//
//.................................Light & Button............................//
int button = 10;
int button1 = 11;
int button2 = 12;
int bazzar = 52;
int red = 7;
int blue = 6;
int green = 13;
int BL = 50;
int bazar = 52;
//.........................................................................//
//..................................Sonar..................................//
int trigl = 23;
int trigf = 47;
int trigr = 53;
int echof = 49;
int echor = 51;
int echol = 25;
int sr = 0;
int sl = 0;
int sf = 0;
int cl = 0;
int f = 1, l = 1, r = 1;
NewPing sonarl(trigl, trigl, 50);
NewPing sonarf(trigf, echof, 90);
NewPing sonarr(trigr, trigr, 50);
//...................................................................//
void setup() {
  Serial.begin(9600);
  pinMode(lmf, OUTPUT);
  pinMode(lmb, OUTPUT);
  pinMode(rmf, OUTPUT);
  pinMode(rmb, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(BL, OUTPUT);
  pinMode(bazar, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(echol, INPUT);
  pinMode(echor, INPUT);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  pinMode(vcc, INPUT_PULLUP);
  pinMode(gnd, OUTPUT);
  lcd.init();
  lcd.backlight();

  for (int i = 0; i < 6; i++) trash[i] = EEPROM.read(i) * 5;
  counter = EEPROM.read(8);
  m = EEPROM.read(9);
  db = EEPROM.read(10);
  EEPROM.get(11, ca);
  dh = EEPROM.read(12);
  lcd.setCursor(7, 0);
  lcd.print("SPI");
  lcd.setCursor(4, 1);
  lcd.print("CHECKMATE");
}

void loop() {
  spr = spr = m;
  check();
  debug();
  digitalWrite(bazar, 0);
  digitalWrite(vcc, 1);
  digitalWrite(gnd, 0);
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  int u = switch1();
  if (u != 0) {
    if (u == 1) line_follower();
    else if (u == 2) cal();
    else if (u == 3) analog_read();
    else if (u == 4)digital_read();
    else if (u == 5) motor(10 * spl, 10 * spr);
    else if (u == 6) sonar_read();
    else if (u == 7) color_maj();
  }
  switch2();
  switch3();
  lcd.setCursor(7, 0);
  lcd.print("SPI");
  lcd.setCursor(4, 1);
  lcd.print("CHECKMATE");
  color();
  Serial.print(rr);
  Serial.print(" ");
  Serial.print(gg);
  Serial.print(" ");
  Serial.println(bb);
}
