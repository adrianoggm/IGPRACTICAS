#include "auxiliar.h"
#include "luzposicional.h"




// *****************************************************************************
//
// Clase ObjLuz(práctica 3)
//
// *****************************************************************************


// *****************************************************************************



void LuzPosicional:: LuzPosicional ( const Tupla2f & orientacion ){

  alpha=orientacion(0);
  beta=orientacion(1);

}

void variarAnguloAlpha:: LuzDireccional  ( float incremento ){
  alpha+=incremento;
}
void variarAnguloBeta:: LuzDireccional  ( float incremento ){
  beta+=incremento;
}
