#include "auxiliar.h"
#include "malla.h"
#include "pierna.h"


Pierna::Pierna(){
  cadera=new Esfera(11,10,5);
  rodilla=new Rodilla();
  femur=new Cilindro(11,10,30,5);

}

void Pierna:: dibuja(float rotopiernax,float rotopiernay,float rotopiernaz,float rotorodillaz,float rotopiey,float rotopiez){
  glPushMatrix();
    glRotatef(rotopiernax);
    glRotatef(rotopiernay);
    glRotatef(rotopiernaz);
    glPushMatrix();
      glTranslatef(0,-(5),0);//radio cadera
      femur.draw();
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0,-35,0);//-(radiocadera+alturafemur)
      rodilla.dibuja(rotorodillaz,rotopiey,rotopiez);
    glPopMatrix();

  glPopMatrix();

  cadera.draw();
}
