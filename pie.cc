#include "auxiliar.h"
#include "malla.h"
#include "pie.h"



Pie::Pie()
{
  planta= new Cilindro(11,10,20,4);
  tobillo=new Esfera(11,10,4);//radio
}
void Pie:: dibuja(float rotopiey,float rotopiez){
  glPushMatrix();
    glRotatef(rotopiez,0.0,0.0,1.0);
    glRotatef(rotopiey,0.0,1.0,0.0);
    glPushMatrix();
      glTranslatef(4,0,0);//translado en X al cilindro el tam del radio tobillo
      glRotatef(rotoenz90);
      glTranslatef(0,20,0);//se genera en el negativo
      planta.draw();
    glPopMatrix();

    tobillo.draw();
  glPopMatrix();
}
