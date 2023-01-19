#include "auxiliar.h"
#include "malla.h"
#include "cabeza.h"



Cabeza::Cabeza()
{
   cara= new Esfera(11,10,12);//recuerda 10 es el radio
   cuello= new Cilindro(11,10,10,4);//num_vert_perfil ,const int num_instancias_perf ,const float altura ,const float radio;
   //cara->setTextura("./text-lata-1.jpg");
   //cara=ObjPLY("./plys/beethoven.ply");//new Esfera(11,10,12);//recuerda 10 es el radio
   Tupla4f ambiente_pearl(0.25,0.20725,0.20725, 1.0);
   Tupla4f especular_pearl(0.296648,0.296648, 0.296648, 1.0);
   Tupla4f difuso_pearl(	1, 0.829,0.829, 1.0);
   Material pearl = Material(ambiente_pearl,especular_pearl,difuso_pearl,0.088*128);
   cara->setMaterial(pearl);
   cuello->setMaterial(pearl);
   //tronco->setTextura("./text-lata-1.jpg");
}

void Cabeza::dibuja(float rotocarax,float rotocaray,float rotocaraz){
  glPushMatrix();
  glTranslatef(0,17,0); //radiocara+alturacilindro
  glRotatef(rotocarax,1.0,0.0,0.0);
  glRotatef(rotocaray,0.0,1.0,0.0);
  glRotatef(rotocaraz,0.0,0.0,1.0);
  cara->draw();
  glPopMatrix();

  glPushMatrix ();
  //glTranslatef (0,10,0);
    cuello->draw();
  glPopMatrix ();

}
