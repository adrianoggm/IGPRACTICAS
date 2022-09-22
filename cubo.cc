#include "auxiliar.h"
#include "malla.h"
#include "cubo.h"

Cubo::Cubo(float lado)
{

   // inicializar la tabla de vértices
   v.resize(8);

   //si dice que tiene al origen por centro luego el 0,0
   //Esto significa que origen pertenece a la intersección de las diagonales del cubo
   //En el caso especial del cubo debido a su paralelismo y composición por cuadrados
   //podemos ver claramente que justo el centro es la mitad en cada una de la dimensiones
   //que hemos definido.
   //Luego la composición de los vertices será en la forma (+-0.5l,+-0.5l,+-0.5,l)
   //podemos observar que el numero de vertices será
   //2^3 =8 del número de posibles vértices a formar.
   const float PROPORCION=0.5;
   v[0]=Tupla3f(+PROPORCION*lado,+PROPORCION*lado,+PROPORCION*lado);
   v[1]=Tupla3f(+PROPORCION*lado,+PROPORCION*lado,-PROPORCION*lado);
   v[2]=Tupla3f(+PROPORCION*lado,-PROPORCION*lado,+PROPORCION*lado);
   v[3]=Tupla3f(+PROPORCION*lado,-PROPORCION*lado,-PROPORCION*lado);
   v[4]=Tupla3f(-PROPORCION*lado,+PROPORCION*lado,+PROPORCION*lado);
   v[5]=Tupla3f(-PROPORCION*lado,+PROPORCION*lado,-PROPORCION*lado);
   v[6]=Tupla3f(-PROPORCION*lado,-PROPORCION*lado,+PROPORCION*lado);
   v[7]=Tupla3f(-PROPORCION*lado,-PROPORCION*lado,-PROPORCION*lado);



   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
   //CARAS TRIANGULOS
   

}
