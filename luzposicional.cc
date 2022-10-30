#include "auxiliar.h"
#include "luzposicional.h"




// *****************************************************************************
//
// Clase ObjLuz(práctica 3)
//
// *****************************************************************************


// *****************************************************************************



LuzPosicional :: LuzPosicional ( const Tupla3f & posicion ) {

  this->posicion=Tupla4f(posicion(0),posicion(1),posicion(2),10.0);
  this->colorAmbiente=Tupla4f(0.0f,0.0f, 0.0f,1.0f);
  this->colorDifuso= Tupla4f(0.0f,0.0f, 0.0f,1.0f);
  this->Especular= Tupla4f(0.0f,0.0f, 0.0f,1.0f);
}
