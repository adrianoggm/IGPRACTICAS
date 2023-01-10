#include "auxiliar.h"
#include "malla.h"
#include "piernabalon.h"

Piernabalon ::Piernabalon(){
  pierna=new Pierna();
  balon= new Esfera(11,10,10);
  balon->setTextura("./text-balon.jpg");
}
void Piernabalon:: dibuja(float rotopiernax,float rotopiernay,float rotopiernaz,float rotorodillaz,float rotopiey,float rotopiez,Tupla3f translacionbalon){
  glPushMatrix();
  /*
    glRotatef(-rotopiernax,1.0,0.0,0.0);
    glRotatef (-rotopiernay,0.0,1.0,0.0);
    glRotatef (-rotopiernaz,0.0,0.0,1.0);
*/
    glPushMatrix();
      glTranslatef(translacionbalon[0],translacionbalon[1],translacionbalon[2]);
      glTranslatef(-32,-67,0);
      //si quisiese rotar el balon lo puedo meter aqui
      balon->draw();
    glPopMatrix();
  glPopMatrix();
  pierna->dibuja(rotopiernax,rotopiernay,rotopiernaz,rotorodillaz,rotopiey,rotopiez);

}
