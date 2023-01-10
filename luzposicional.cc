#include "auxiliar.h"
#include "luzposicional.h"




// *****************************************************************************
//
// Clase ObjLuz(práctica 3)
//
// *****************************************************************************


// *****************************************************************************



LuzPosicional :: LuzPosicional ( const Tupla3f & posicion ) {

  this->posicion=Tupla4f(posicion(0),posicion(1),posicion(2),1.0);
  this->colorAmbiente=Tupla4f(0.7f,0.7f,0.7f,1.0f);
  this->colorDifuso= Tupla4f(0.9f,0.9f,0.9f,1.0f);
  this->Especular= Tupla4f(0.9f,0.9f,0.9f,1.0f);
}
void LuzPosicional :: Incrementarluz ( Tupla4f incremento ) {
     //LAS TECLAS DE LUCES SON  M incrementar y N decrementar
  this->colorAmbiente=this->colorAmbiente+incremento;
  this->colorDifuso= this->colorDifuso+incremento;
  this->Especular= this->Especular+incremento;
}
void LuzPosicional :: CambiarPosicion ( Tupla3f posi) {
     //LAS TECLAS DE LUCES SON  M incrementar y N decrementar
     this->posicion=Tupla4f(posi(0)+posicion(0),posi(1)+posicion(1),posi(2)+posicion(2),1.0);
}
