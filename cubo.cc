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

   v[0]=Tupla3f(+lado,+lado,+lado);
   v[1]=Tupla3f(+lado,+lado,0);
   v[2]=Tupla3f(+lado,0,+lado);
   v[3]=Tupla3f(+lado,0,0);
   v[4]=Tupla3f(0,+lado,+lado);
   v[5]=Tupla3f(0,+lado,0);
   v[6]=Tupla3f(0,0,+lado);
   v[7]=Tupla3f(0,0,0);


   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
   //CARAS TRIANGULOS,6 CARAS X 2 =12 TRIANGULOS

   f.resize(12);

   //CARA1
   f[0]=Tupla3i(0,3,1);
   f[1]=Tupla3i(0,2,3);
   //CARA2
   f[2]=Tupla3i(0,1,5);
   f[3]=Tupla3i(0,5,4);
   //CARA3
   f[4]=Tupla3i(6,4,7);
   f[5]=Tupla3i(7,4,5);
   //CARA4
   f[6]=Tupla3i(2,6,3);
   f[7]=Tupla3i(3,6,7);
   //CARA5
   f[8]=Tupla3i(0,6,2);
   f[9]=Tupla3i(0,4,6);
   //CARA6
   f[10]=Tupla3i(3,5,1);
   f[11]=Tupla3i(3,7,5);

   c.resize(12);

   //colores
   c[0]=Tupla3f(1.0f,1.0f,0.0f);
   c[1]=Tupla3f(1.0f,1.0f,0.0f);
   //CARA2
   c[2]=Tupla3f(1.0f,1.0f,0.0f);
   c[3]=Tupla3f(1.0f,1.0f,0.0f);
   //CARA3
   c[4]=Tupla3f(1.0f,1.0f,0.0f);
   c[5]=Tupla3f(1.0f,1.0f,0.0f);
   //CARA4
   c[6]=Tupla3f(1.0f,1.0f,0.0f);
   c[7]=Tupla3f(1.0f,1.0f,0.0f);
   //CARA5
   c[8]=Tupla3f(1.0f,1.0f,0.0f);
   c[9]=Tupla3f(1.0f,1.0f,0.0f);
   //CARA6
   c[10]=Tupla3f(1.0f,1.0f,0.0f);
   c[11]=Tupla3f(1.0f,1.0f,0.0f);


   l.push_back(Tupla3f(0.0f,0.0f,1.0f));
   l.push_back(Tupla3f(0.0f,0.0f,1.0f));

   l.push_back(Tupla3f(0.0f,0.0f,1.0f));
   l.push_back(Tupla3f(0.0f,0.0f,1.0f));

   l.push_back(Tupla3f(0.0f,0.0f,1.0f));
   l.push_back(Tupla3f(0.0f,0.0f,1.0f));

   l.push_back(Tupla3f(0.0f,0.0f,1.0f));
   l.push_back(Tupla3f(0.0f,0.0f,1.0f));

   l.push_back(Tupla3f(0.0f,0.0f,1.0f));
   l.push_back(Tupla3f(0.0f,0.0f,1.0f));

   l.push_back(Tupla3f(0.0f,0.0f,1.0f));
   l.push_back(Tupla3f(0.0f,0.0f,1.0f));

   p.push_back(Tupla3f(1.0f,0.0f,0.0f));
   p.push_back(Tupla3f(1.0f,0.0f,0.0f));

   p.push_back(Tupla3f(1.0f,0.0f,0.0f));
   p.push_back(Tupla3f(1.0f,0.0f,0.0f));

   p.push_back(Tupla3f(1.0f,0.0f,0.0f));
   p.push_back(Tupla3f(1.0f,0.0f,0.0f));

   p.push_back(Tupla3f(1.0f,0.0f,0.0f));
   p.push_back(Tupla3f(1.0f,0.0f,0.0f));

   p.push_back(Tupla3f(1.0f,0.0f,0.0f));
   p.push_back(Tupla3f(1.0f,0.0f,0.0f));

   p.push_back(Tupla3f(1.0f,0.0f,0.0f));
   p.push_back(Tupla3f(1.0f,0.0f,0.0f));
   /*
   //colores
   c[0]=Tupla3f(1.0f,0.0f,1.0f);
   c[1]=Tupla3f(1.0f,0.0f,1.0f);
   //CARA2
   c[2]=Tupla3f(1.0f,0.0f,1.0f);
   c[3]=Tupla3f(1.0f,0.0f,1.0f);
   //CARA3
   c[4]=Tupla3f(1.0f,0.0f,1.0f);
   c[5]=Tupla3f(1.0f,0.0f,1.0f);
   //CARA4
   c[6]=Tupla3f(1.0f,0.0f,1.0f);
   c[7]=Tupla3f(1.0f,0.0f,1.0f);
   //CARA5
   c[8]=Tupla3f(1.0f,0.0f,1.0f);
   c[9]=Tupla3f(1.0f,0.0f,1.0f);
   //CARA6
   c[10]=Tupla3f(1.0f,0.0f,1.0f);
   c[11]=Tupla3f(1.0f,0.0f,1.0f);
   */
}
