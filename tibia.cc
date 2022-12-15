#include "auxiliar.h"
#include "malla.h"
#include "tibia.h"




Tibia::Tibia()
{
  perone=new Cilindro(11,10,35,3);
  rotula=new Esfera(11,10,4);
}

void Tibia:: dibuja(){
  glPushMatrix();
  glTranslatef(0,-39,0);//solo el radio de la rotula
  perone->draw();
  glPopMatrix();

  rotula->draw();
}
