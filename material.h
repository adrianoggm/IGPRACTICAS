// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************



class Material {
  private :
    Tupla4f difuso ;
    Tupla4f especular ;
    Tupla4f ambiente ;
    float brillo ;
  public :
    Material ( Tupla4f mdifuso ,Tupla4f mespecular ,Tupla4f mambiente ,float mbrillo );
    void aplicar();
};



#endif
