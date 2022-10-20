#include "auxiliar.h"
#include "objrevolucion.h"
#include "ply_reader.h"



// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)

ObjRevolucion::ObjRevolucion() {}

ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias) {
   // completar ......(práctica 2)
    ply::read_vertices( archivo, this->v);
    if(v[0](0)==0&&v[0](3)==0){
      Tupla3f polosur=v[0];
      v.erase(v.begin());//v.begin()

    }
    if(v[v.size()-1](0)==0&&v[v.size()-1](3)==0){
      Tupla3f polonorte=v[v.size()-1];
      v.pop_back();

    }
}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)


ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias) {


}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias) {
}
