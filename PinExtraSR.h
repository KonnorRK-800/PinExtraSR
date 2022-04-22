class PinExtra
{
private:

int datos; 		//Creamos la variable interna del pin de datos
int reloj; 		//Creamos la variable interna del pin de reloj
int enable; 		//Creamos la variable interna del pin de enable
int registros;		//Creamos la variable interna que indica el numero de registros de desplazamientos concatenados
byte Salida[8]; 	//Creamos el array con los datos de salida. Este array permite que se conecten hasta 8 registros de desplazamiento, pero si necesita, puede ampliar en 1 el array por cada registro extra que requiera.
const byte bits[8] = {  //Declaramos un array con los bytes que se pueden escribir en cada registro. Estos bytes se usaran al momento de modificar bytes de salida.
 
                0b10000000,
                0b01000000,
                0b00100000,
                0b00010000,
                0b00001000,
                0b00000100,
                0b00000010,
                0b00000001,
                      };

public:
PinExtra(int,int,int,int);
void PinExtraNP(int,int);
void PinExtraP(int,int);
void PrintSR();

};

PinExtra::PinExtra(int _datos,int _reloj, int _enable, int _registros) //Constructor de la clase... Las variables se explican solas �Verdad? 
{
  datos=_datos;			//
  reloj=_reloj;			//
  enable=_enable;		// Pasamos los datos de los parametros del constructor a las variables internas de la funcion.
  registros=_registros;		//

  pinMode(datos,OUTPUT);  //
  pinMode(reloj,OUTPUT);  //Colocamos los pines que conectan el registro de desplazamiento como salidas.
  pinMode(enable,OUTPUT); //
  
  for(int i=0; i<registros; i++)		  //
  { 						  //
    digitalWrite(enable, LOW);                    //
    shiftOut(datos, reloj, LSBFIRST, 0b00000000); // Colocamos todas las salidas de los registros a 0 para evitar valores aleatorios. Y4 con el bucle for lo repetimos tantas veces como registros de desplazamiento tengamos presentes.
    digitalWrite(enable, HIGH);                   //
  }						  //
  
}

void PinExtra::PinExtraNP(int _pin, int _estado) //Funcion para escribir datos de salida en los arrays de memoria, sin enviar los datos a los registros de salida. (en el parametro "estado" solo puedes poner "1" y "0").
{
  int pin=_pin;					// Pasamos los datos de los parametros del constructor a las variables internas de la funcion.
  int estado=_estado;				//

  int RegDeAcceso=0;				//Esta variable indica a que registro se accede. Estos se enumeran de 0 a infinito XD(eso ultimo es broma). Siendo el registro 0, el primero de todos los registros.
  int PinDelReg=pin;				//Esta variable indica que pin del registro al que se accede, se debe modificar luego de realizado el calculo.

  RegDeAcceso=(pin)/8;				//Es la operacion que calcula que registro al que se debe acceder.
  PinDelReg=PinDelReg-8*RegDeAcceso;

  if(estado == 1)
   {
    Salida[RegDeAcceso] = Salida[RegDeAcceso] | bits[PinDelReg];	//Si el parametro de la funcion es 1, modificara el byte, con un 1 en el bit que corresponde al pin del registro de desplazamiento indicado.
   }
  else if (estado == 0)
   {
    Salida[RegDeAcceso] = Salida[RegDeAcceso] & ~bits[PinDelReg];	//Si el parametro de la funcion es 0, modificara el byte, con un 0 en el bit que corresponde al pin del registro de desplazamiento indicado.
   }
}

void PinExtra::PinExtraP(int PIN, int ESTADO) //Funcion Para imprimir el bit de salida en el registro de salida directamente. Cabe aclarar que la posibilidad de modificar el 
{                                  //array de memoria y actualizar la salida estan separadas para poder modificar rapidamente varias salidas a la vez con mayor velocidad,
PinExtraNP(PIN,ESTADO);            //por ejemplo, si quieres modificar 4 salidas a la vez, modificas los 4 bits en el array de memoria (usando la funcion PinExtraNP)
PrintSR();                           //y luego se envian los datos al registro 1 sola vez(con la funcion PrintSR). Asi se impide actualizaciones innecesarias y se puede
}                                  //acelerar la operacion en caso de ser necesario.

void PinExtra::PrintSR()
{
  digitalWrite(enable, LOW);
  
  int count=registros-1;
  for(int i=0; i<registros; i++)
  { 
     shiftOut(datos, reloj, LSBFIRST, Salida[count]);
   count--;
  }

  digitalWrite(enable, HIGH);
}
