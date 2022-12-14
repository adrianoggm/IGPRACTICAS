#include "auxiliar.h"
#include "malla.h"
#include "tibia.h"




Tibia{
  rotula=new Cilindro(11,10,35,3);
  perone=new Esfera(11,10,4);
}
void Tibia:: dibuja(){
  glPushMatrix();
  glTranslatef(0,-(3),0);//solo el radio de la rotula
  perone.draw();
  glPopMatrix();

  rotula.draw();
}
