#include "auxiliar.h"
#include "malla.h"
#include "brazo.h"


Brazo::Brazo(){
  hombro= new  Esfera(11,10,3);
  biceps = new Cilindro(11,10,30,3);
  antebrazo=new Antebrazo();
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
