

void loop()
{

  //////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////// detector ////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////
//                Serial.print(_pot0);
//                Serial.print("  ");
//                Serial.print(_pot0Log);
//                Serial.print("   ");
//                Serial.print(_pot1);
//                Serial.print("  ");
//                Serial.print(_pot1Log);
//                Serial.print("   ");
//                Serial.print("  ");
//                Serial.print(_pot2);
//                Serial.print("  ");
//                Serial.print(_pot2Log);
//                Serial.print("   ");
//                Serial.print(_pot3);
//                Serial.print("  ");
//                Serial.print(_pot3Log);
//                Serial.print("   ");
//                Serial.print("  ");
//                Serial.print(digitalRead(tog1A));
//                Serial.println(digitalRead(tog1B));
//                
//                Serial.print(ch1);
//                Serial.print("  ");
//               Serial.print(ch2);
////  
//  //              Serial.print(_pot0);
//                Serial.print("  ");
//  //              Serial.print(_pot1);
//                Serial.print("  ");
//                Serial.print("Rand1:");
//                Serial.print(rnd1);
//                Serial.print("  ");  
//                Serial.print(ch1new);
//                  Serial.print("  ");
//                Serial.print(ch1d);
//                 Serial.print("  ");
//                Serial.print("Envia: ");
//               Serial.print(ch1);
//                Serial.print("  ");
//                //Serial.print(dimmer1.getPower());
//  
//  
//                  Serial.print("  ");
//                  Serial.print("  ");
//                                Serial.print("Rand2:");
//                         Serial.print(rnd2);
//                Serial.print("  ");
//                Serial.print(ch2new);
//                  Serial.print("  ");
//               Serial.print(ch2d);
//                Serial.print("  ");
//                 Serial.print("Envia: ");
//                 Serial.print(ch2);
//                Serial.print("  ");
//                //Serial.print(dimmer1.getPower());
//  
//                Serial.println(ch2new);



  ////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Reading de potes:


  Sensometria();
 
  //////////////////////////// random set //////////////////////////////////////////////////////////////


  if (tog1 == 2) {
    if (ch1new) {
     ch1d = Randomset(1);
     ch1new = false; 
    }

    if (ch2new) {
      ch2d = Randomset(2);
      ch2new = false;
     }
  }
if (tog1 == 9) {
   if (ch1new) {
     ch1 = pasosset(1);
     ch1new = false; 
    }

    if (ch2new) {
      ch2 = pasosset(2);
      ch2new = false;
     }  };
  //////////////////////////////////////////////////////////////////////////////////////////////////////
  if (tog1 == 2) {
  //////////////////////////////////// programa uno, randomizer/////////////////////////////////////////

 

   programa1();

   lamp1.set(ch1);
   lamp2.set(ch2);
  }


  if (tog1 == 0) {
  //////////////////////////////////// programa dos, Vela      /////////////////////////////////////////

  if (ch1d >= 0) (ch1d = -1);
  if (ch2d >= 0) (ch2d = -1);
  vela();

    lamp1.set(ch1);
    lamp2.set(ch2);
   // delay(Timing1);
  }



////DIRECTO////
  if (tog1 == 1) {

    ch1 = _pot0;
    ch2 = _pot2;
    lamp1.set(ch1);
    lamp2.set(ch2);
    if (! ch1new)(ch1new  = true);
    if (! ch2new)(ch2new  = true);

  }

}

