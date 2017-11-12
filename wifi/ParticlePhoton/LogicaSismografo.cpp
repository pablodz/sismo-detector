#include <I2Cdev.h>
#include <MPU6050.h>
#include <HttpClient.h>
#if (I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE) && !defined (PARTICLE)
#include "Wire.h"
#endif
MPU6050 accelgyro;
HttpClient http;
int16_t ax, ay, az;
int16_t gx, gy, gz;
char* valores[1];
int valor;

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

void setup() {

    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
    Serial.begin(38400);
    Serial.println("Initializing I2C devices...");
    accelgyro.initialize();

    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    Serial.println();
    request.hostname = "192.168.1.51";// Local red that host the data
    request.port = 8080;

    // the path including variables for GET
    char thedata[64];
    char *php = "/enviar2.php";
    char *id = "?id=";
    char *x = "&x=";
    char *y = "&y=";
    char *z = "&z=";
    sprintf(thedata, "%s%s%s%s%d%s%d%s%d", php, id, "1",x,gx,y,gy,z,gz);
    request.path = thedata;
    Serial.println("Guardando valores de sensores...");
    Serial.println(thedata);
    // Get request
    http.get(request, response, headers);

    //delay(200);
    //Serial.print("Application>\tResponse status: ");
    Serial.println(response.status);

    //Serial.print("Application>\tHTTP Response Body: ");
    Serial.println(response.body);
  //===========================================================
  Serial.println();
  char thedata2[64]; // La pagina web
  char *php2="/leer.php";
  sprintf(thedata2,"%s",php2);
  Serial.println("La lectura de la pagina web...");
  Serial.println(thedata2);
  http.post(request,response,headers);
  //Serial.print("Application>\tResponse status: ");
  Serial.println(response.status);

  //Serial.print("Application>\tHTTP Response Body: ");

  if ( char*(response.body)=='0')
  {
    valor=0;
  }else{
    valor=1;
  }
  Serial.println(String(valor));

    //===========================================================
    // blink LED to indicate activity
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);

    contador++;
}
