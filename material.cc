#include "auxiliar.h"
#include "material.h"




// *****************************************************************************
//
// Clase ObjLuz(práctica 3)
//
// *****************************************************************************


// *****************************************************************************

Material:: Material ( Tupla4f mdifuso ,Tupla4f mespecular ,Tupla4f mambiente ,float mbrillo ){
  this->difuso=mdifuso;
  this->especular=mespecular;
  this->ambiente=mambiente;
  this->brillo=mbrillo;


}


void Material:: aplicar(){
  glMaterialfv(GL_FRONT,GL_AMBIENT,this->ambiente);
  glMaterialfv(GL_FRONT,GL_DIFFUSE,this->difuso);
  glMaterialfv(GL_FRONT,GL_SPECULAR,this->especular);
  const GLfloat * b = new GLfloat(brillo);
  glMaterialfv(GL_FRONT,GL_SHININESS,b);



}
