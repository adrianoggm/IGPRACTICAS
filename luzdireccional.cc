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
  this->posicion=Tupla4f(cos(this->beta)*sin(this->alpha),sin(this->beta)*sin(this->alpha),cos(this->alpha),0.0f);
  this->colorAmbiente=Tupla4f(0.8f,0.8f, 0.8f,1.0f);
  this->colorDifuso= Tupla4f(0.8f,0.8f, 0.8f,1.0f);
  this->Especular= Tupla4f(0.8f,0.8f, 0.8f,1.0f);
}

void LuzDireccional :: variarAnguloAlpha  ( float incremento ){
  this->alpha=(this->alpha+(incremento*PI)/180);
/*  if(this->alpha>=PI){
    this->alpha-=PI;
  }
  if(this->alpha<0){
    this->alpha+=PI;
  }*/
  //aqui igual puede haber algun problema ya que va hasta 180 y no hasta 360 igual con round se puede si lo dejamos como grados
  // printf("alpha %f  \n ,",this->alpha*180/PI);
  this->posicion=Tupla4f(cos(this->beta)*sin(this->alpha),sin(this->beta)*sin(this->alpha),cos(this->alpha),0.0f);
/*  glLightfv(this->id,GL_POSITION,this->posicion);
  glLightfv(this->id,GL_SPECULAR,this->Especular);
  glLightfv(this->id,GL_AMBIENT,this->colorAmbiente);
  glLightfv(this->id,GL_DIFFUSE,this->colorDifuso);
*/
}
void LuzDireccional :: variarAnguloBeta ( float incremento ){
  this->beta=(this->beta+(incremento*PI)/180);
  //printf("beta %f  \n ,",this->beta*180/PI);
  this->posicion=Tupla4f(cos(this->beta)*sin(this->alpha),sin(this->beta)*sin(this->alpha),cos(this->alpha),0.0f);
  /*glLightfv(this->id,GL_POSITION,this->posicion);
  glLightfv(this->id,GL_SPECULAR,this->Especular);
  glLightfv(this->id,GL_AMBIENT,this->colorAmbiente);
  glLightfv(this->id,GL_DIFFUSE,this->colorDifuso);
*/
}
void LuzDireccional :: variarColor ( Tupla4f incremento ){
  this->colorAmbiente=incremento;
  this->colorDifuso=incremento;
  this->Especular=incremento;
}
