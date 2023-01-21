#include "auxiliar.h"
#include "malla.h"
#include "pierna.h"


Pierna::Pierna(){
  cadera=new Esfera(6,6,5);
  rodilla=new Rodilla();
  femur=new Cilindro(6,6,30,5);
  Tupla4f ambiente_yellowplast(	0.0,	0.0,	0.0, 1.0);
  Tupla4f especular_yellowplast(	0.5	,0.5,	0.0, 1.0);
  Tupla4f difuso_yellowplast(	0.60	,0.60,	0.50, 1.0);
  //yellow plastic			.25
  Material yellowplast = Material(ambiente_yellowplast,especular_yellowplast,difuso_yellowplast,0.25);
  femur->setMaterial(yellowplast);
  femur->setTextura("./text-madera.jpg");
  cadera->setMaterial(yellowplast);
  cadera->setTextura("./text-madera.jpg");

}

void Pierna:: dibuja(float rotopiernax,float rotopiernay,float rotopiernaz,float rotorodillaz,float rotopiey,float rotopiez){
  glPushMatrix();
    glRotatef(rotopiernax,1.0,0.0,0.0);
    glRotatef(rotopiernay,0.0,1.0,0.0);
    glRotatef(rotopiernaz,0.0,0.0,1.0);
    glPushMatrix();
      glTranslatef(0,-(35),0);//radio cadera
      femur->draw();
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0,-35,0);//-(radiocadera+alturafemur)
      rodilla->dibuja(rotorodillaz,rotopiey,rotopiez);
    glPopMatrix();

  glPopMatrix();

  cadera->draw();
}
