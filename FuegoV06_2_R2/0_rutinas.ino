float _mapf(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void Sensometria() {
  // Read de toggler 
  bool tog1A_state = digitalRead(tog1A);
  bool tog1B_state = digitalRead(tog1B);
  
  if (tog1A_state && !tog1B_state) {
    tog1 = 0;
  } else if (!tog1A_state && tog1B_state) {
    tog1 = 2;
  } else {
    tog1 = 1;
  }

  // Read de potes
  int ch1h_val = analogRead(ch1h);
  int ch1l_val = analogRead(ch1l);
  int ch2h_val = analogRead(ch2h);
  int ch2l_val = analogRead(ch2l);

  // Cambia segun programa
  switch (tog1) {
    case 0:
      randomMin = map(ch1l_val, 0, 1023, 5, 1000);
      randomMax = map(ch1h_val, 0, 1023, 5, 1000);
      randomMin2 = map(ch2l_val, 0, 1023, 5, 1000);
      randomMax2 = map(ch2h_val, 0, 1023, 5, 1000);
      break;
    case 1:
      _pot0 = map(ch1h_val, 0, 1023, 0, 100);
      _pot2 = map(ch2h_val, 0, 1023, 0, 100);
      break;
    case 2:
      prog2L1 = map(ch1h_val, 0, 1023, 0, 100);
      prog2H1 = map(ch1l_val, 0, 1023, 0, 100);
      prog2L2 = map(ch2h_val, 0, 1023, 0, 100);
      prog2H2 = map(ch2l_val, 0, 1023, 0, 100);
      break;
    default:
      _pot0 = map(ch1h_val, 0, 1023, 0, 100);
      _pot1 = map(ch2h_val, 0, 1023, 0, 100);
      _pot2 = map(ch1l_val, 0, 1023, 0, 100);
      _pot3 = map(ch2l_val, 0, 1023, 0, 100);
      break;
  }
}



int pasosset(int _ch) {
  if ((_ch != 1) && (_ch != 2)) {
    Serial.println("ERROR! RANDOMSET MAL LLAMADO");
    return 1;
  }

  int _max = _pot0;
  int _min = _pot1;
  int _tim, _act;
  float _resultado;

  if (_ch == 1) {
    Timing1 = Timingber;
    _tim = Timing1;
    _act = ch1;

    if (tick1) {
      _resultado = _max;
    } else {
      _resultado = _min;
    }

    tick1 = !tick1;
  }

  if (_ch == 2) {
    Timing2 = Timingber;
    _tim = Timing2;
    _act = ch2;

    if (tick2) {
      _resultado = _max;
      rnd2 = _max;
      Serial.print("maxim");
    } else {
      _resultado = _min;
      rnd2 = _min;
      Serial.print("minim");
    }

    tick2 = !tick2;
  }

  if (_resultado < 1) {
    _resultado = 1;
  }

  return _resultado;
}



int Randomset(int _ch) {
  unsigned long _RNDA, _RNDB;
  int _tim, _rnd, _act;
  float _resultado;

  if (_ch == 1) {
    Timing1 = Timing + random(-Randtiming / 2, Randtiming / 2);
    _RNDA = _pot0;
    _RNDB = _pot1;
    _tim = Timing1;
    _act = ch1;
  } else if (_ch == 2) {
    Timing2 = Timing + random(-Randtiming / 2, Randtiming / 2);
    _RNDA = _pot2;
    _RNDB = _pot3;
    _tim = Timing2;
    _act = ch2;
  } else {
    Serial.println("ERROR! RANDOMSET MAL LLAMADO");
    return 1;
  }

  _rnd = _RNDA <= _RNDB ? random(_RNDA, _RNDB) : random(_RNDB, _RNDA);

  if (_ch == 1) {
    rnd1 = _rnd;
  } else if (_ch == 2) {
    rnd2 = _rnd;
  }

  _resultado = (_act <= _rnd) ? ((_rnd - _act) / _tim) : ((_act - _rnd) / _tim);
  _resultado = (_resultado < 1) ? 1 : _resultado;

  return _resultado;
}


void programa1() {
  if (ch1d < 1) {
    ch1new = true;
  }
  if (ch2d < 1) {
    ch2new = true;
  }

  Timing1--;
  Timing2--;

  if (Timing1 <= 0) {
    if (ch1 == rnd1) {
      ch1new = true;
    } else if (ch1 < rnd1) {
      ch1 = min(ch1 + ch1d, rnd1);
    } else if (ch1 > rnd1) {
      ch1 = max(ch1 - ch1d, rnd1);
    }
  }

  if (Timing2 <= 0) {
    if (ch2 == rnd2) {
      ch2new = true;
    } else if (ch2 < rnd2) {
      ch2 = min(ch2 + ch2d, rnd2);
    } else if (ch2 > rnd2) {
      ch2 = max(ch2 - ch2d, rnd2);
    }
  }
}


void vela() {

  unsigned long currentTime = millis();


  // Check if it's time to change the state of the pin
  if (currentTime - previousTime >= delayTime) {
    // Generate a random delay between 1/25 sec and 1 sec
    delayTime = random(randomMin, randomMax);

    // Toggle the state of GPIO 14
    estadoonoff = !estadoonoff;
    // Update the previous time to the current time
    previousTime = millis();
  }
  if (currentTime - previousTime2 >= delayTime2) {
    // Generate a random delay between 1/25 sec and 1 sec
    delayTime2 = random(randomMin2, randomMax2);

    // Toggle the state of GPIO 14
    estadoonoff2 = !estadoonoff2;
    // Update the previous time to the current time
    previousTime2 = millis();
  }



  if (estadoonoff) {
    ch1 = 100;
  } else {
    ch1 = 0;
  }

  if (estadoonoff2) {
    ch1 = 100;
  } else {
    ch1 = 0;
  }
}

 





void VelaOc()
{
  static unsigned long lastRefreshTime = 0;

  if (millis() - lastRefreshTime >= velamilistimer)
  {
    lastRefreshTime += velamilistimer;
    vela();
  }
}
void Luzseran() {

  
}
