
void setup() {

  randomSeed(analogRead(A6));

  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("******************************************");
  Serial.println("******************************************");
  Serial.println("********** Fuego has been Reset **********");
  Serial.println("******************************************");
  Serial.print("******************") ;
  Serial.print(ver);
  Serial.println("********************");

  ////setup interface

  pinMode(tog1A, INPUT_PULLUP);
  pinMode(tog1B, INPUT_PULLUP);

  pinMode(ch1h, INPUT);
  pinMode(ch1l, INPUT);
  pinMode(ch2h, INPUT);
  pinMode(ch2l, INPUT);

  ////Fin setup interface

  lamp1.begin();
  lamp2.begin();

  Timing1 = Timing;

  Timing2 = Timing;
  pinMode(SS_PIN, INPUT);
  
  //indice = 15;
}
