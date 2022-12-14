#include "auxiliar.h"
#include "malla.h"
#include "cabeza.h"



Cabeza::Cabeza()
{
   cara= new Esfera(11,10,10);//recuerda 10 es el radio
   cuello= new Cilindro(11,10,10,4);//num_vert_perfil ,const int num_instancias_perf ,const float altura ,const float radio;
}

void Cabeza::dibuja(float rotocarax,float rotocaray,float rotocaraz){
  glPushMatrix();
  glTranslatef(0,20,0); //radiocara+alturacilindro
  glRotatef(rotocarax);
  glRotatef(rotocaray);
  glRotatef(rotocaraz);
  cara.draw();
  glPopMatrix();

  glPushMatrix ();
  glTranslatef (0,10,0);
    cuello.draw();
  glPopMatrix ();

}
