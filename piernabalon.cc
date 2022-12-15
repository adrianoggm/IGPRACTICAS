#include "auxiliar.h"
#include "malla.h"
#include "pierna.h"

Piernabalon ::Piernabalon(){
  pierna=new Pierna();
  balon=new Esfera();
}
void Piernabalon:: dibuja(float rotopiernax,float rotopiernay,float rotopiernaz,float rotorodillaz,float rotopiey,float rotopiez,Tupla3f translacionbalon){
  glPushMatrix();
    glRotatef(-rotopiernax,1.0,0.0,0.0);
    glRotatef (-rotopiernay,0.0,1.0,0.0);
    glRotatef (-rotopiernaz,0.0,0.0,1.0);
    glPushMatrix();
      glTranslatef(translacionbalon);
      //si quisiese rotar el balon lo puedo meter aqui
      balon.draw();
    glPopMatrix();
  glPopMatrix();
  pierna.dibuja(rotopiernax,rotopiernay,rotopiernaz,rotorodillaz,rotopiey,rotopiez);

}
