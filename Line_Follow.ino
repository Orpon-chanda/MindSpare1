void line_follower() {
  while (1) {
    check();
   if (s[0] == 1 && s[5] == 1 && (s[1] == 0 || s[2] == 0 || s[3] == 0 || s[4] == 0)) {
      mi1 = mi2 = millis();
      while (s[0] == 1 && s[5] == 1 && (s[1] == 0 || s[2] == 0 || s[3] == 0 || s[4] == 0)) {
        check();
        mi2 = millis();
        if (mi2 - mi1 >= 50) {
          if (mode == 0) {
            digitalWrite(green, HIGH);
            mode = 1;
          }
          else {
            digitalWrite(green, LOW);
            mode = 0;
          }
          turn = 0;
          cross = 0;
          break;
        }

      }
    }

    
   else if (sum == 0) {
      if (turn == 1) {
        if (k30 != 0) {
          digitalWrite(blue, HIGH);
          break2(); //.......................................Turn == 1, Delay()....................
          motor(10 * spl, -10 * spr);
          delay(10);
          while (s[0] == 0) check();
        }
        else if (k90 != 0) {
          digitalWrite(green, HIGH);
          digitalWrite(bazar, HIGH);
          break1(); //.......................................Turn == 1, Delay()....................
          motor(10 * spl, -10 * spr);
          delay(10);
          while (s[2] == 0 && s[3] == 0) check();
        }
        digitalWrite(green, LOW);
        digitalWrite(blue, LOW);
        digitalWrite(bazar, LOW);
        motor(-10 * spl, 10 * spr);
        delay(dh);
        cross = 0;

        motor(10 * spl, 10 * spr);
      }
      else if (turn == 2) {
        if (k30 != 0) {
          digitalWrite(blue, HIGH);
          break2(); //.......................................Turn == 1, Delay()....................
          motor(-10 * spl, 10 * spr);
          delay(10);
          while (s[5] == 0) check();
        }
        else if (k90 != 0) {
          digitalWrite(green, HIGH);
          digitalWrite(bazar, HIGH);
          break1();  //...........................................Turn == 2, Delay()......................
          motor(-10 * spl, 10 * spr);
          delay(10);
          while (s[2] == 0 && s[3] == 0) check();
        }
        digitalWrite(green, LOW);
        digitalWrite(blue, LOW);
        digitalWrite(bazar, LOW);
        motor(10 * spl, -10 * spr);
        delay(dh);
        cross = 0;
        motor(10 * spl, 10 * spr);
      }
      else if (turn == 0 && k > -4 && k < 4) {
        mi1 = mi2 = millis();
        motor(4* spl, 4 * spr);

        while (sum == 0) {
          check();
          mi2 = millis();
          sr = sonarr.ping_cm();
          if (sr < 20 && sr > 0) wall();
          else if (mi2 - mi1 >= 50) {//....................................  Sum == 0,  Millis(); ................................
            break2();
            motor(-9* spl, 7 * spr);
            while (s[2] == 0 && s[3] == 0) check();
            motor(10 * spl, -10 * spr);
            delay(20);
            break;
          }
        }
      }
    }

    else if (sum == 1 || sum == 2) {
      if (cross == 1) {
        break2();
        cross = 0;
        motor(10 * spl, -10 * spr);
        while (s[0] == 1) check();
        while (s[0] == 0) check();
        while (s[2] == 0 && s[3] == 0) check();
        motor(10 * spl, 10 * spr);
      }
      else if (cross == 2) {
        break1();
        cross = 0;
        motor(-10 * spl, 10 * spr);
        while (s[5] == 1) check();
        while (s[5] == 0) check();
        while (s[2] == 0 && s[3] == 0) check();
        motor(10 * spl, 10 * spr);
      }
      //...........................................................Telateli..............................................//
      if (data == 0b001100) {
        if (k > 0) {
          k = 0;
          motor (-10 * spl, 10 * spr);
          delay(dt);
        }
        else if (k < 0) {
          k = 0;

          motor (10 * spl, -10 * spr);
          delay(dt);
        }
        motor(10 * spl, 10 * spr);
      }

      else if (data == 0b001000)motor(8 * spl, 10 * spr);
      else if (data == 0b000100)  motor(10 * spl, 8 * spr);
      //.........................................................................................Left side
      else if (data == 0b011000) {
        if (k > -2) {
          motor(-10 * spl, 10 * spr);
          delay(dt);
          k = -2;
        }
        motor(5 * spl, 10 * spr);
      }
      else if (data == 0b010000) {
        if (k > -3) {
          motor(-10 * spl, 10 * spr);
          delay(dt);
          k = -3;
        }
        motor(3 * spl, 10 * spr);
      }
      else if (data == 0b110000) {
        if (k > -4) {
          motor(-10 * spl, 10 * spr);
          delay(dt);
          k = -4;
        }
        motor(-3 * spl, 10 * spr);
      }
      else if (data == 0b100000) {
        if (k > -5) {
          motor(-10 * spl, 10 * spr);
          delay(dt);
          k = -5;
        }
        motor(-6 * spl, 10 * spr);
      }
      //...................................................................................Right side
      else if (data == 0b000110) {
        if (k < 2) {
          motor(10 * spl, -10 * spr);
          delay(dt);
          k = 2;
        }
        motor(10 * spl, 5 * spr);
      }
      else if (data == 0b000010) {
        if (k < 3) {
          motor(10 * spl, -10 * spr);
          delay(dt);
          k = 3;
        }
        motor(10 * spl, 3 * spr);
      }
      else if (data == 0b000011) {
        if (k < 4) {
          motor(10 * spl, -10 * spr);
          delay(dt);
          k = 4;
        }
        motor(10 * spl, -3 * spr);
      }
      else if (data == 0b000001) {
        if (k < 5) {
          motor(10 * spl, -10 * spr);
          delay(dt);
          k = 5;
        }
        motor(10 * spl, -6 * spr);
      }

    }
    else if (sum == 3 || sum == 4 || sum == 5) {
     
      if (data == 0b001011 || data == 0b001101) {
        k30 = 1;
        turn = 1;
      }
      else if (data == 0b101100 || data == 0b110100) {
        k30 = 2;
        turn = 2;

      }
       //....................................................................................Right hand rule..........................
      if (data == 0b001111 || data == 0b000111 || data == 0b011111) {
        k90 = 1;
        turn = 1;
        if (counter == 0) {
          mi1 = mi2 = millis();
          while (sum != 6 && sum != 0) {
            check();
            mi2 = millis();
            if (mi2 - mi1 >= 80) {
              cross = 1;
              break;
            }
          }
        }
      }
      //.......................................................................................Left hand rule........................
      else if (data == 0b111100 || data == 0b111110 || data == 0b111000) {
        k90 = 2;
        turn = 2;
      }
      mi3 = millis();
    }
    else if (sum == 6) {   //.........................................................Sum == 6....................................
      turn = 2;
      mi3 = millis();
      mi1 = mi2 = millis();
      while (sum != 0) {
        check();
        mi2 = millis();
        if (mi2 - mi1 >= 100) {   // ....................................................Sum == 6, Millis();...........................
          if (sum == 6) {
            motor(-10 * spl, -10 * spr);
            delay(50);
            motor(0, 0);
            while (sum == 6) check();
            break;
          }
          else {  //..............................................................................Counter cross ....................................
            turn = 0;
            //            if (counter == 0)cross = 0; //SPECIAL  CASE
            break;

          }
        }
      }
    }
    mi4 = millis();
    if (mi4 - mi3 >= 400) {
      turn = 0;
      //     cross = 0;
    }
  }
}
