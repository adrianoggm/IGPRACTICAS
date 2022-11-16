#include "auxiliar.h"
#include "malla.h"
#include "tetraedro.h"

Tetraedro::Tetraedro( float r)
{

   // inicializar la tabla de vértices



   const float PI=3.14159265358979323846l;
   const float angulo=360/3;
   float h=r*1.3;

   //vertices del 0 al 4
   for(int i=0;i<360;){
     float degtorad=(i*PI)/180;
     float cosen=cos(degtorad);
     float sen=sin(degtorad);
     v.push_back(Tupla3f(r*cosen,0,r*sen));
    i+=angulo;
   }
   //vertice 4 ápice superior de la pirámide
   v.push_back(Tupla3f(0,h,0));

   // inicializar la tabla de caras o triángulos:
   f.resize(4);
   //cara inferior compuesta de 3 triangulos
   f[0]=Tupla3i(0,1,3);
   f[1]=Tupla3i(0,2,1);
   f[2]=Tupla3i(0,3,2);
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
   f[3]=Tupla3i(1,2,3);
   //f[4]=Tupla3i(1,5,2);
   //f[5]=Tupla3i(2,5,3);
   //f[6]=Tupla3i(3,5,4);
   //f[7]=Tupla3i(4,5,0);



   // inicializar la/s tabla/s de colores

   c.resize(4);

   //colores
   c[0]=Tupla3f(0.0f,1.0f,1.0f);
   c[1]=Tupla3f(0.0f,1.0f,1.0f);
   c[2]=Tupla3f(0.0f,1.0f,1.0f);
   c[3]=Tupla3f(0.0f,1.0f,1.0f);
   /*c[4]=Tupla3f(0.0f,1.0f,1.0f);
   c[5]=Tupla3f(0.0f,1.0f,1.0f);
   c[6]=Tupla3f(0.0f,1.0f,1.0f);
   c[7]=Tupla3f(0.0f,1.0f,1.0f);
   */


   l.push_back(Tupla3f(0.0f,0.0f,1.0f));
   l.push_back(Tupla3f(0.0f,0.0f,1.0f));

   l.push_back(Tupla3f(0.0f,0.0f,1.0f));
   l.push_back(Tupla3f(0.0f,0.0f,1.0f));



   p.push_back(Tupla3f(1.0f,0.0f,0.0f));
   p.push_back(Tupla3f(1.0f,0.0f,0.0f));

   p.push_back(Tupla3f(1.0f,0.0f,0.0f));
   p.push_back(Tupla3f(1.0f,0.0f,0.0f));



}
