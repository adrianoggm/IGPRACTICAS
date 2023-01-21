#include "auxiliar.h"
#include "malla.h"
#include "pie.h"



Pie::Pie()
{
  planta= new Cilindro(7,7,20,4);
  tobillo=new Esfera(7,7,4);//radio
  Material negro (Tupla4f(0.04f,0.04f,0.04f,0.96f),Tupla4f(0.96f,0.96f,0.96f,0.96f),Tupla4f(0.04f,0.04f,0.04f,0.96f),128.f);
  planta->setMaterial(negro);
  //planta->setTextura("./text-madera.jpg");
  tobillo->setMaterial(negro);
  //tobillo->setTextura("./text-madera.jpg");
}
void Pie:: dibuja(float rotopiey,float rotopiez){
  glPushMatrix();
    glRotatef(rotopiez,0.0,0.0,1.0);
    glRotatef(rotopiey,0.0,1.0,0.0);
    glPushMatrix();
      glTranslatef(-4,0,0);//translado en X al cilindro el tam del radio tobillo
      glRotatef(90,0.0,0.0,1.0);
      //glTranslatef(0,20,0);//se genera en el negativo
      planta->draw();
    glPopMatrix();

    tobillo->draw();
  glPopMatrix();
}
