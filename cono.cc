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

      perfil.push_back(Tupla3f(at/tan(angulo),(at-altura),0.0f));//-(at-altura)
    }
      perfil.push_back(Tupla3f(0.0,0,0.0f));


    crearMalla(perfil,num_instancias_perf,100);
    //c.clear();
    
};
