#include "auxiliar.h"
#include "objrevolucion.h"
#include "cono.h"



// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)

Cono::Cono() {};

Cono::Cono ( const int num_vert_perfil ,const int num_instancias_perf,const float altura ,const float radio ){
    std::vector<Tupla3f>perfil;
    float angulo=atan(altura/radio);
    for(int i=0;i<num_vert_perfil;i++){
      float at=altura*i/(num_vert_perfil-1);
      
      perfil.push_back(Tupla3f(at/tan(angulo),-at,0.0f));//-(at-altura)
    }
      perfil.push_back(Tupla3f(0.0,-altura,0.0f));
    /*for(int i=0;i<perfil.size();i++){
      std::vector<Tupla3f> r(perfil.rbegin(),perfil.rend());
      perfil.swap(r);
        //printf("%f  ,",perfil[i][0]);
        //printf("%f  ,",perfil[i][1]);
        //printf(" %f \n",perfil[i][2]);
      }*/
      //printf("PUNTOS PERFIL  \n");
    crearMalla(perfil,num_instancias_perf);

};
