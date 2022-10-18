#include "auxiliar.h"
#include "malla.h"
#include "piramidepentagonal.h"

PiramidePentagonal::PiramidePentagonal(float h, float r)
{

   // inicializar la tabla de vértices



   const float PI=3.14159265358979323846l;
   const float angulo=360/5;


   //vertices del 0 al 4
   for(int i=0;i<360;){
     float degtorad=(i*PI)/180;
     float cosen=cos(degtorad);
     float sen=sin(degtorad);
     v.push_back(Tupla3f(r*cosen,0,r*sen));
    i+=angulo;
   }
   //vertice 5 ápice superior de la pirámide
   v.push_back(Tupla3f(0,h,0));

   // inicializar la tabla de caras o triángulos:
   f.resize(8);
   //cara inferior compuesta de 3 triangulos
   f[0]=Tupla3i(0,1,2);
   f[1]=Tupla3i(0,2,4);
   f[2]=Tupla3i(2,3,4);
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
   f[3]=Tupla3i(0,5,1);
   f[4]=Tupla3i(1,5,2);
   f[5]=Tupla3i(2,5,3);
   f[6]=Tupla3i(3,5,4);
   f[7]=Tupla3i(4,5,0);



   // inicializar la/s tabla/s de colores

   c.resize(8);

   //colores
   c[0]=Tupla3f(0.0f,1.0f,1.0f);
   c[1]=Tupla3f(0.0f,1.0f,1.0f);
   c[2]=Tupla3f(0.0f,1.0f,1.0f);
   c[3]=Tupla3f(0.0f,1.0f,1.0f);
   c[4]=Tupla3f(0.0f,1.0f,1.0f);
   c[5]=Tupla3f(0.0f,1.0f,1.0f);
   c[6]=Tupla3f(0.0f,1.0f,1.0f);
   c[7]=Tupla3f(0.0f,1.0f,1.0f);



}
