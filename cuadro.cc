#include "auxiliar.h"
#include "malla.h"
#include "cuadro.h"

Cuadro::Cuadro(float lado)
{

   // inicializar la tabla de vértices
   v.resize(4);
   modo_textura=2;
   //si dice que tiene al origen por centro luego el 0,0
   //Esto significa que origen pertenece a la intersección de las diagonales del cubo
   //En el caso especial del cubo debido a su paralelismo y composición por cuadrados
   //podemos ver claramente que justo el centro es la mitad en cada una de la dimensiones
   //que hemos definido.
   //Luego la composición de los vertices será en la forma (+-0.5l,+-0.5l,+-0.5,l)
   //podemos observar que el numero de vertices será
   //2^3 =8 del número de posibles vértices a formar.


   v[0]=Tupla3f(+lado,+lado,0);
   v[1]=Tupla3f(+lado,0,0);
   v[2]=Tupla3f(0,+lado,0);
   v[3]=Tupla3f(0,0,0);


   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
   //CARAS TRIANGULOS,6 CARAS X 2 =12 TRIANGULOS

   f.resize(2);

   //CARA1
   f[0]=Tupla3i(0,2,1);
   f[1]=Tupla3i(1,2,3);
   //CARA2


   c.resize(4);
   c[0]=Tupla3f(0.0f,1.0f,0.0f);
   c[1]=Tupla3f(0.0f,1.0f,0.0f);
   c[2]=Tupla3f(0.0f,1.0f,0.0f);
   c[3]=Tupla3f(0.0f,1.0f,0.0f);


   l.push_back(Tupla3f(0.0f,0.0f,1.0f));
   l.push_back(Tupla3f(0.0f,0.0f,1.0f));
   l.push_back(Tupla3f(0.0f,0.0f,1.0f));
   l.push_back(Tupla3f(0.0f,0.0f,1.0f));



   p.push_back(Tupla3f(1.0f,0.0f,0.0f));
   p.push_back(Tupla3f(1.0f,0.0f,0.0f));
   p.push_back(Tupla3f(1.0f,0.0f,0.0f));
   p.push_back(Tupla3f(1.0f,0.0f,0.0f));


   ct.push_back(Tupla2f(1.f,1.f));//1
   ct.push_back(Tupla2f(1.0f,0.0f));//3
   ct.push_back(Tupla2f(0.f,1.f));//0
   ct.push_back(Tupla2f(0.0f,0.0f));//2


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
