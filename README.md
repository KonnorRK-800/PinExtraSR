# PinExtraSR
Esta librería permite que puedas concatenar uno o mas registros de desplazamiento para usar sus salidas como si salidas digitales de un Arduino se tratase.
Para poder usarla, debes tener Un registro de desplazamiento compatible como el CD4094 o el 74HC595 y conectar el pin de datos, reloj y latch.

Si usas muchos registros de desplazamiento, puedes concatenarlos para tener hasta 8 registros en cascada (64 salidas digitales extras). La cantidad maxima de registros concatenados puede ampliarse modificando una variable en el codigo, pero no lo recomiendo, ya que mientras mas registros haya, menor sera la velocidad de actualización.

Esto se puede remediar declarando otra instancia (en la que usas otros 3 pines digitales del microcontrolador), en ese caso tendrias como minimo 2 registros de desplazamiento conectados en paralelo.
Tambien es posible declarar 2 instancias con numeros distintos de registros conectados en cascada (esto lo aclaro por las dudas).


Si quieres agradecer la contribucion, puedes donarme medinte  transferencia en paypal con el correo: <leofig81@gmail.com>
