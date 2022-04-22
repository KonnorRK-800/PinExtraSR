/*
 Blink

 Enciende un led por un segundo, para luego apagarlo en el siguiente segundo, sigiendo esto infinitamente.
 Esta es una especiede refrito del blink original pero adaptado para trabajar con los pines del registro de desplazamiento.

 Escrito el 16 de Marzo de 2022
 por Figueroa Leonel Sebastian, Alias KonnorRK-800.
 
 Este Codigo de ejemplo es de dominio publico.
 
 */


#include <PinExtraSR.h> //incluimos la libreria en cuestion XD.

PinExtra MySR(2,3,4,1); // Creamos la instancia MySR. Parametros del Constructor: PinExtra MySR(PinDedatos, PinDeclock, PinDeEnable, NdeRegistrosEnCascada);  
int pin=0;               //Pin De salida 0 del registro de desplazamiento.

void setup()
{
/*Aqui no hace falta poner los pines 8,9,10 del arduino como salidas porque 
  la libreria lo hace de forma automatica al momento
  de crear la instancia.
*/
}

void loop()
{
  MySR.PinExtraP(pin , HIGH); // el pin 0 del registro se pone en 1 logico.
  delay(1000);                //Esperamos un segundo.
  MySR.PinExtraP(pin, LOW); // el pin 0 del registro se pone en 0 logico.
  delay(1000);              //Volvemos a esperar 1 segundo.
}
