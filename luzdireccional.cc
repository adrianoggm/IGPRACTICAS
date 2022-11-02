#include "auxiliar.h"
#include "luzdireccional.h"




// *****************************************************************************
//
// Clase ObjLuz(práctica 3)
//
// *****************************************************************************


// *****************************************************************************


LuzDireccional:: LuzDireccional ( const Tupla2f & orientacion ){

  this->alpha=(orientacion(0)*PI)/180;//eje Y teta
  this->beta=(orientacion(1)*PI)/180;//eje X phi
  //suponemos un vector unitario osea que r será =1
  //si w=0 esta en el infinito es luz direccional
  this->posicion=Tupla4f(cos(beta)*sin(alpha),sin(beta)*sin(alpha),cos(alpha),0.0f);
  this->colorAmbiente=Tupla4f(0.8f,0.8f, 0.8f,0.0f);
  this->colorDifuso= Tupla4f(0.8f,0.8f, 0.8f,0.0f);
  this->Especular= Tupla4f(0.8f,0.8f, 0.8f,0.0f);
}

void LuzDireccional :: variarAnguloAlpha  ( float incremento ){
  this->alpha=(alpha+(incremento*PI)/180);
  //aqui igual puede haber algun problema ya que va hasta 180 y no hasta 360 igual con round se puede si lo dejamos como grados
  this->posicion=Tupla4f(cos(beta)*sin(alpha),sin(beta)*sin(alpha),cos(alpha),0.0f);
}
void LuzDireccional :: variarAnguloBeta ( float incremento ){
  this->beta=(beta+(incremento*PI)/180);
  this->posicion=Tupla4f(cos(beta)*sin(alpha),sin(beta)*sin(alpha),cos(alpha),0.0f);
}
