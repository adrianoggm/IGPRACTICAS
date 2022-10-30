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

}
