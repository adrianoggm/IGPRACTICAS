#include "auxiliar.h"
#include "malla.h"
#include "mano.h"

Mano::Mano(){

  palma=new Esfera(7,7,4);
  Tupla4f ambiente_yellowplast(	0.0,	0.0,	0.0, 1.0);
  Tupla4f especular_yellowplast(	0.5	,0.5,	0.0, 1.0);
  Tupla4f difuso_yellowplast(	0.60	,0.60,	0.50, 1.0);
  //yellow plastic			.25
  Material yellowplast = Material(ambiente_yellowplast,especular_yellowplast,difuso_yellowplast,0.25);

  palma->setMaterial(yellowplast);
  palma->setTextura("./text-madera.jpg");
}
void Mano::dibuja(){
  glPushMatrix();
    palma->draw();
  glPopMatrix();
}
