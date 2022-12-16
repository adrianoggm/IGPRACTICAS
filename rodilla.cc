#include "auxiliar.h"
#include "malla.h"
#include "rodilla.h"


Rodilla::Rodilla(){
  tibia=new Tibia();
  pie= new Pie();
}
void Rodilla:: dibuja(float rotorodillaz,float rotopiey,float rotopiez){
  glPushMatrix();
  glRotatef(rotorodillaz,0.0,0.0,1.0);
  glPushMatrix();
  glTranslatef(0,-40,0);//-(radiorotula+alturaperone)
  pie->dibuja(rotopiey,rotopiez);
  glPopMatrix();

  tibia->dibuja();
  glPopMatrix();
}
