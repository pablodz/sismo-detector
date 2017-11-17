#include <I2Cdev.h>
#include <MPU6050.h>
#include <HttpClient.h>
#include <math.h>
#if (I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE) && !defined (PARTICLE)
#include "Wire.h"
#endif
MPU6050 accelgyro;
HttpClient http;
int16_t ax, ay, az;
int16_t gx, gy, gz;
int estado;
double modulo;
int valor;
String content = "";
char character;
long int contador=0;
//===========================================================
http_header_t headers[] = {
    { "Accept" , "*/*"},
    { NULL, NULL } // NOTE: Always terminate headers will NULL
};
http_request_t request;
http_response_t response;
#define OUTPUT_READABLE_ACCELGYRO
#if defined (PARTICLE)
#define LED_PIN D7 // (Particle is D7)
#else
#define LED_PIN 13 // (Arduino is 13, Teensy is 11, Teensy++ is 6)
#endif

bool blinkState = false;
//===========================================================
// The pins you can use for tone() / noTone() are:
// D0, D1, A0, A1, A4, A5, A6, A7, RX, TX
const char tonePins[] = { D0, D1, A0, A1, A4, A5, A6, A7, RX, TX };

void setup() {
    pinMode(tonePins[4],OUTPUT);
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
    Serial.begin(38400);
    Serial.println("Inicializando comunicación I2C...");
    accelgyro.initialize();

    Serial.println("Enviando instrucciones I2C...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 CONECTADO" : "MPU6050 NO RESPONDE");

    pinMode(LED_PIN, OUTPUT);
}
void prenderAltavoz()
{
  tone(tonePins[4], 900);
}
void apagarAltavoz()
{
  noTone(tonePins[4]);
}

void loop() {

    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    Serial.print("Sismografo v3.1 -Pablo Diaz-Lectura [");
    Serial.print(String(contador));
    Serial.print("]: ");
    request.hostname = "10.101.57.203";// Local red that host the data
    request.port = 8080;
    //===========================================================

    modulo=sqrt(pow(gx,2)+pow(gy,2)+(gz,2));

    if (log10(modulo)>=3)
    {
      estado=2;
       prenderAltavoz();
    }
    else
    {
      estado=0;
    }


    //===========================================================
    // the path including variables for GET
    char thedata[100];
    char *php = "/enviar2.php";
    char *id = "?id=";
    char *x = "&x=";
    char *y = "&y=";
    char *z = "&z=";
    char *e="&e=";
    sprintf(thedata, "%s%s%s%s%d%s%d%s%d%s%i", php, id, "1",x,gx,y,gy,z,gz,e,estado);
    request.path = thedata;
    Serial.println("\n\rGuardando valores de sensores...");
    Serial.println(thedata);
    // Get request
    http.get(request, response, headers);
    //delay(200);
    //===========================================================
      accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
      //===========================================================
    //Serial.print("Application>\tResponse status: ");
    Serial.println(response.status);
    //Serial.print("Application>\tHTTP Response Body: ");
    Serial.println(response.body);
  //===========================================================

  char thedata2[64]; // La pagina web

  char *php2="/leer.php";
  sprintf(thedata2,"%s",php2);
  request.path=thedata2;
  Serial.println("La lectura de la pagina web...");
  Serial.println(thedata2);
  http.get(request,response,headers);
  //===========================================================
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    //===========================================================
  //Serial.print("Application>\tResponse status: ");
  //Serial.println(response.status);
  //Serial.print("Application>\tHTTP Response Body: ");
  content = response.body;
  //content.concat(character);
  //Serial.println(String(character));
  //Serial.print(content);
  //===========================================================
  Serial.print("El valor de content es: ");
  Serial.println(content[0]);
  if (content[0]=='0')
  {

    valor=0;

  }
  else if (content[0]=='1')
  {
    valor=1;
    //prenderAltavoz();
  }else if (content[0]=='2')
  {
    valor=2;
  }
  else if (content[1]=='2')
  {

    valor=2;
  }
  else{
    Serial.print("El valor de content no es 0 ni 1.");
    //noTone(tonePins[4]);
  }
  Serial.println(String(valor));
  if (valor==2)
  {
    //Prender alarma
    Serial.println("\t ALARMA PRENDIDA");
    prenderAltavoz();
  }
  else if (valor==1)
  {
    if (content[1]=='1')
    {
      prenderAltavoz();
    }
  }
  else if (valor==0)
  {
    Serial.println("\t ALARMA APAGADA");
    apagarAltavoz();
    //Apagar alarma
  }
  else
  {
     //noTone(tonePins[4]);
  }

    //===========================================================
    // blink LED to indicate activity
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);


    //===========================================================
    //delay(3000);
      Serial.write(27);       // ESC command
      //Serial.print("[2J");    // clear screen command
      //Serial.write(27);
      Serial.print("[H");     // cursor to home command
      if (contador==1)
      {
        Serial.write(27);
        Serial.print("[2J");    // clear screen command
        Serial.write(27);

      }

  //===========================================================

  //===========================================================

    contador++;
}
