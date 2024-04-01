///// FUEGO /////

char ver[] = "Verion 8";

/****************

  Lautaro Requena

*  **************

*  **************
    ----------------------    TABLA LOCA DE PINES  ---------------------
    +---------------+-------------------------+-------------------------+
    |               |       CANAL1            |         D6              |
    |               |       CANAL2            |         D9              |
    +   CANALES     +       ZCROSS            +         D2              +
    |               |                         |                         |
    +---------------+-------------------------+-------------------------+
    |               |     # 1 ## 3 ##  0 d11  | 1.A0 2.A1 3.A2 4.A3     |
    +    INPUTS           ###########  1 d12  +  Tog1 D11 y D12         +
    |               |     # 2 ## 4 ##  2 0    |                         |
    +---------------+-------------------------+-------------------------+
    | BTA16 MOC3020 |                         |                         |
    | BT139         |                         |                         |
    +---------------+-------------------------+-------------------------+
**************

*/
// #include "spline.h"
#include "Dimmer.h"


//ver8 SPI
#include <SPI.h>

#define SS_PIN 10 // Slave Select (SS)
#define MOSI_PIN 11 // Master Out Slave In (MOSI)
#define MISO_PIN 12 // Master In Slave Out (MISO)
#define SCK_PIN 13 // Serial Clock (SCK)

#define DATA_SIZE 6 // Tamaño de datos a recibir
#define RESPONSE_SIZE 2 // Tamaño de la respuesta a enviar


int totalcanales = 2;

int Timing = 90;
int Timingber = 90;
int Randtiming = 4;
int Timing1,Timing2;

int ch1h = A0;
int ch1l = A1; //pin de los potes
int ch2h = A2;
int ch2l = A3;


int tog1A = 13;
int tog1B = 10; //Pin de los potes toggler 1

int tog1 = 0; //var toggler1

Dimmer lamp1(6);
Dimmer lamp2(9);

int prog2H1,prog2L1,prog2H2,prog2L2;

float velamax = 44; 
float velamin = 16;

byte _pot0,_pot1,_pot2,_pot3;



bool tick1,tick2;
float Seno;
int eldelay = 2500;
int eldelay2 = 100;


  
int ch1,ch2,rnd1,rnd2;
unsigned long velamilistimer,velamilischeck,velamilis;
float velamilistimer2;
int veldist1,veldist2,indice;
bool ch2new,ch1new,velasentido1,velasentido2;
float ch1d,ch2d;

bool estadoonoff,estadoonoff2;
int perfil = 0;

///////////////para comunicacion SPI
//int slider1,slider2,slider3,slider4;
//bool htmlswitch = false;
//bool gatillado = false;
unsigned long previousTime = 0;
unsigned long delayTime = 0;
unsigned long previousTime2 = 0;
unsigned long delayTime2 = 0;
//fin definicion interfase
int randomMax = 1000;
int randomMin = 50;
int randomMax2 = 1000;
int randomMin2 = 50;


//int receivedData[DATA_SIZE]; // Datos recibidos
//int response[RESPONSE_SIZE] = {1, 2}; // Respuesta a enviar
