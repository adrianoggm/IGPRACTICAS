#include "auxiliar.h"
#include "objrevolucion.h"
#include "esfera.h"



// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)

Esfera::Esfera() {};

Esfera::Esfera ( const int num_vert_perfil ,const int num_instancias_perf ,const float radio ){
    std::vector<Tupla3f>perfil;
    const float PI=3.14159265358979323846l;
    const float angulo=180/(num_instancias_perf-1);

    
    //vertices del 0 al 4
    for(int i=270;i<450;){
      float degtorad=(i*PI)/180;
      float cosen=cos(degtorad);
      float sen=sin(degtorad);
      perfil.push_back(Tupla3f(radio*cosen,radio*sen,0));
     i+=angulo;
    }
    perfil.push_back(Tupla3f(0.0f,+radio,0.0f));//polonorte
   /* 
    for(int i=0;i<perfil.size();i++){
        printf("%f  ,",perfil[i][0]);
        printf("%f  ,",perfil[i][1]);
        printf(" %f \n",perfil[i][2]);
      }
      printf("PUNTOS PERFIL  \n");*/
   
    crearMalla(perfil,num_instancias_perf);

};
