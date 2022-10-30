#include "auxiliar.h"
#include "luzdireccional.h"




// *****************************************************************************
//
// Clase ObjLuz(práctica 3)
//
// *****************************************************************************


// *****************************************************************************


LuzDireccional:: LuzDireccional ( const Tupla2f & orientacion ){

  this->alpha=orientacion(0);
  this->beta=orientacion(1);

}

void LuzDireccional :: variarAnguloAlpha  ( float incremento ){
  this->alpha+=incremento;
}
void LuzDireccional :: variarAnguloBeta ( float incremento ){
  this->beta+=incremento;
}
