#include "auxiliar.h"
#include "malla.h"
#include "antebrazo.h"
#include "cilindro.h"
#include "esfera.h"
#include "mano.h"

Antebrazo::Antebrazo(){
  codo= new  Esfera(11,10,3);
  radio = new Cilindro(11,10,30,3);
  mano=new Mano();
  Tupla4f ambiente_yellowplast(	0.0,	0.0,	0.0, 1.0);
  Tupla4f especular_yellowplast(	0.5	,0.5,	0.0, 1.0);
  Tupla4f difuso_yellowplast(	0.60	,0.60,	0.50, 1.0);
  //yellow plastic			.25
  Material yellowplast = Material(ambiente_yellowplast,especular_yellowplast,difuso_yellowplast,0.25);
  codo->setMaterial(yellowplast);
  radio->setTextura("./text-madera.jpg");
  radio->setMaterial(yellowplast);
  codo->setTextura("./text-madera.jpg");
}
void Antebrazo::dibuja(float rotoantx,float rotoantz){
  glPushMatrix();
  glRotatef(rotoantx,1.0,0.0,0.0);
  glRotatef(rotoantz,0.0,0.0,1.0);

    glPushMatrix();
      glTranslatef(0,-33,0);//-(radiocodo
      radio->draw();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0,-37,0);//-(radiocodo+alturaradio)
      mano->dibuja();
    glPopMatrix();
    codo->draw();
  glPopMatrix();
}
