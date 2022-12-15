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
}
void Antebrazo::dibuja(float rotoantx,float rotoantz){
  glPushMatrix();
  glRotatef(rotoantx,1.0,0.0,0.0);
  glRotatef(rotoantz,0.0,0.0,1.0);

    glPushMatrix();
      glTranslatef(0,-3,0);//-(radiocodo
      radio->draw();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0,-33,0);//-(radiocodo+alturaradio)
      mano->dibuja();
    glPopMatrix();
    codo->draw();
  glPopMatrix();
}
