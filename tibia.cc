#include "auxiliar.h"
#include "malla.h"
#include "tibia.h"




Tibia::Tibia()
{
  perone=new Cilindro(6,6,35,3);
  rotula=new Esfera(6,6,4);
  Tupla4f ambiente_yellowplast(	0.0,	0.0,	0.0, 1.0);
  Tupla4f especular_yellowplast(	0.5	,0.5,	0.0, 1.0);
  Tupla4f difuso_yellowplast(	0.60	,0.60,	0.50, 1.0);
  //yellow plastic			.25
  Material yellowplast = Material(ambiente_yellowplast,especular_yellowplast,difuso_yellowplast,0.25);
  perone->setMaterial(yellowplast);
  perone->setTextura("./text-madera.jpg");
  rotula->setMaterial(yellowplast);
  rotula->setTextura("./text-madera.jpg");
}

void Tibia:: dibuja(){
  glPushMatrix();
  glTranslatef(0,-39,0);//solo el radio de la rotula
  perone->draw();
  glPopMatrix();

  rotula->draw();
}
