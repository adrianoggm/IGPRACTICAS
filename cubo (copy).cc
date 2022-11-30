#include "auxiliar.h"
#include "malla.h"
#include "cabeza.h"

Cabeza::Cabeza()
{

   // inicializar la tabla de vértices
   cara= new Esfera();
   cuello= new Cilindro();
   /*
   //colores
   c[0]=Tupla3f(1.0f,0.0f,1.0f);
   c[1]=Tupla3f(1.0f,0.0f,1.0f);
   //CARA2
   c[2]=Tupla3f(1.0f,0.0f,1.0f);
   c[3]=Tupla3f(1.0f,0.0f,1.0f);
   //CARA3
   c[4]=Tupla3f(1.0f,0.0f,1.0f);
   c[5]=Tupla3f(1.0f,0.0f,1.0f);
   //CARA4
   c[6]=Tupla3f(1.0f,0.0f,1.0f);
   c[7]=Tupla3f(1.0f,0.0f,1.0f);
   //CARA5
   c[8]=Tupla3f(1.0f,0.0f,1.0f);
   c[9]=Tupla3f(1.0f,0.0f,1.0f);
   //CARA6
   c[10]=Tupla3f(1.0f,0.0f,1.0f);
   c[11]=Tupla3f(1.0f,0.0f,1.0f);
   */
}
void Cabeza::dibuja(rotocarax,rotocaray,rotocaraz){
  glPushMatrix();
  glTranslatef(0,alturacuello,0);
  glRotatef
  glRotatef
  glRotatef
  cara.draw();
  glPopMatrix();

  cuello.draw();
}


Pie::Pie()
{
  planta= new Cilindro();
  tobillo=new Esfera();
}
void Pie:: dibuja(rotopiey,rotopiez){
  glPushMatrix();
    glRotatef
    glRotatef
    glPushMatrix();
      glTranslatef(pieanchura,0,0);
      planta.draw();
    glPopMatrix();

    tobillo.draw();
  glPopMatrix();
}
Tibia{
  rotula= new Cilindro();
  perone=new Esfera();


}
void Tibia:: dibuja(){
  glPushMatrix();
  glTranslatef(0,-(radiorotula+alturaperone),0);
  perone.draw();
  glPopMatrix();

  rotula.draw();
}


Rodilla::Rodilla(){
  tibia=new Tibia();
  pie= new Pie();
}
void Rodilla:: dibuja(rotorodillaz,rotopiey,rotopiez){
  glPushMatrix();
  glTranslatef(0,-(radiorotula+alturaperone),0);
  pie.dibuja(rotopiey,rotopiez);
  glPopMatrix();

  tibia.dibuja();
}
Pierna::Pierna(){
  cadera=new Esfera();
  rodilla=new Rodilla();
  femur=new Cilindro();
}

void Pierna:: dibuja(rotopiernax,rotopiernay,rotopiernaz,rotorodillaz,rotopiey,rotopiez){
  glPushMatrix();
    glRotatef
    glRotatef
    glRotatef
    glPushMatrix();
      glTranslatef(0,-(radiocadera+alturafemur),0);
      femur.draw();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0,-(radiocadera+alturafemur),0);
      rodilla.dibuja(rotorodillaz,rotopiey,rotopiez);
    glPopMatrix();
    rotula.draw();
  glPopMatrix();

}

void Mano::Mano(){

  palma=new Esfera();
}
void Mano::dibuja(){
  glPushMatrix();
    glEscale(1,1.3,1);
    palma.draw();
  glPopMatrix();
}
void Mano::Mano(){

  palma=new Esfera();
}
void Mano::dibuja(){
  glPushMatrix();
    glEscale(1,1.3,1);
    palma.draw();
  glPopMatrix();
}

Antebrazo::Antebrazo(){
  codo= new Esfera();
  radio = new Cilindro();
  mano=new Mano();
}
void Antebrazo::dibujar(rotoantx,rotantz){
  glPushMatrix();
    glRotatef
    glRotatef

    glPushMatrix();
      glTranslatef(0,-(radiocodo+alturaradio),0);
      radio.draw();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0,-(radiocodo+alturaradio),0);
      mano.dibuja()
    glPopMatrix();
    codo.draw();
  glPopMatrix();
}
Brazo::Brazo(){
  hombro= new Esfera();
  biceps = new Cilindro();
  antebrazo=new Antebrazo();
}
void Brazo::dibujar(rotabrax,rotabray,rotabraz,rotoantx,rotantz){
  glPushMatrix();
    glRotatef
    glRotatef
    glRotatef

    glPushMatrix();
      glTranslatef(0,-(radiohombro+alturabiceps),0);
      biceps.draw();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0,-(radiohombro+alturabiceps),0);
      antebrazo.dibuja();
    glPopMatrix();
    hombro.draw();
  glPopMatrix();
}

Jugador::Jugador(){
  tronco= new Cilindro();
  brazoizq
  brazodch=new  Pierna();
  manoizq=new Brazo();
  brazodch=new Brazo();
  cabeza=new Cabeza()
}
