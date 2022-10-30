#include "auxiliar.h"
#include "luzdireccional.h"




// *****************************************************************************
//
// Clase ObjLuz(práctica 3)
//
// *****************************************************************************


// *****************************************************************************


void LuzDireccional:: LuzDireccional ( const Tupla2f & orientacion ){

  alpha=orientacion(0);
  betha=orientacion(1);

}

void variarAnguloAlpha:: LuzDireccional  ( float incremento ){
  alpha+=incremento;
}
void variarAnguloBeta:: LuzDireccional  ( float incremento ){
  beta+=incremento;
}
