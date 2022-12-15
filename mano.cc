#include "auxiliar.h"
#include "malla.h"
#include "mano.h"

Mano::Mano(){

  palma=new Esfera(11,10,4);
}
void Mano::dibuja(){
  glPushMatrix();
    palma->draw();
  glPopMatrix();
}
