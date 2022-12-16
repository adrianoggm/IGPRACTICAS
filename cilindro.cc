#include "auxiliar.h"
#include "objrevolucion.h"
#include "cilindro.h"



// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)

Cilindro::Cilindro() {};

Cilindro::Cilindro ( const int num_vert_perfil ,const int num_instancias_perf ,const float altura ,
const float radio ){

    std::vector<Tupla3f>perfil;
     perfil.push_back(Tupla3f(0.0f,altura,0.0f));//POLO 
    for(int i=0;i<(num_vert_perfil);i++){
      perfil.push_back(Tupla3f(radio,(-altura*i/(num_vert_perfil-1))+altura,0.0f));
    }
    perfil.push_back(Tupla3f(0.0f,0.0f,0.0f));//POLO
    /*
    for(int i=0;i<perfil.size();i++){
        printf("%f  ,",perfil[i][0]);
        printf("%f  ,",perfil[i][1]);
        printf(" %f \n",perfil[i][2]);
      }
      printf("PUNTOS PERFIL  \n");
    */
    crearMalla(perfil,num_instancias_perf,100);

};
