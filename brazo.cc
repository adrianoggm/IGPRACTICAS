#include "auxiliar.h"
#include "malla.h"
#include "brazo.h"


Brazo::Brazo(){
  hombro= new  Esfera(7,7,3);
  biceps = new Cilindro(7,7,30,3);
  antebrazo=new Antebrazo();
  Tupla4f ambiente_yellowplast(	0.0,	0.0,	0.0, 1.0);
  Tupla4f especular_yellowplast(	0.5	,0.5,	0.0, 1.0);
  Tupla4f difuso_yellowplast(	0.60	,0.60,	0.50, 1.0);
  //yellow plastic			.25
  Material yellowplast = Material(ambiente_yellowplast,especular_yellowplast,difuso_yellowplast,0.25);
  biceps->setMaterial(yellowplast);
  biceps->setTextura("./text-madera.jpg");
  hombro->setMaterial(yellowplast);
  hombro->setTextura("./text-madera.jpg");
}
void Brazo::dibuja(float rotabrax,float rotabray,float rotabraz,float rotoantx,float rotoantz){
  glPushMatrix();
    glRotatef(rotabrax,1.0,0.0,0.0);
    glRotatef(rotabray,0.0,1.0,0.0);
    glRotatef(rotabraz,0.0,0.0,1.0);

    glPushMatrix();
      glTranslatef(0,-33,0);//-radiohombro
      biceps->draw();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0,-33,0);// -(radiohombro + alturabiceps)
      antebrazo->dibuja(rotoantx,rotoantz);
    glPopMatrix();
    hombro->draw();
  glPopMatrix();
}
