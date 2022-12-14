#include "auxiliar.h"
#include "malla.h"
#include "cabeza.h"



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
Piernabalon ::Piernabalon(){
  pierna=new Pierna();
  balon=new Esfera();
}
void Pierna:: dibuja(rotopiernax,rotopiernay,rotopiernaz,rotorodillaz,rotopiey,rotopiez,translacionbalon){
  glPushMatrix();
    glRotatef -rotopiernax;
    glRotatef -rotopiernay;
    glRotatef -rotopiernaz;
    glPushMatrix();
      glTranslatef(translacionbalon);
      //si quisiese rotar el balon lo puedo meter aqui
      balon.draw();
    glPopMatrix();
  glPopMatrix();
  pierna.dibuja(rotopiernax,rotopiernay,rotopiernaz,rotorodillaz,rotopiey,rotopiez);

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
  piernaizq = new Pierna()
  piernadch=new  Piernabalon();
  brazoizq=new Brazo();
  brazodch=new Brazo();
  cabeza=new Cabeza()
}
void Jugador::dibujar(rotabraizqx,rotabraizqy,rotabraizqz,rotoantizqx,rotantizqz,
rotabradchx,rotabradchy,rotabradchz,rotoantdchx,rotantdchz,
rotopiernaizqx,rotopiernaizqy,rotopiernaizqz,rotorodillaizqz,rotopieizqy,rotopieizqz,
rotopiernadchx,rotopiernadchy,rotopiernadchz,rotorodilladchz,rotopiedchy,rotopiedchz,translacionbalon,
rotocarax,rotocaray,rotocaraz){

      tronco.draw();
    glPushMatrix();
      glTranslatef(0,(alturabrazos),anchurapecho);
      brazoizq.dibuja(rotabraizqx,rotabraizqy,rotabraizqz,rotoantizqx,rotantizqz);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0,(alturabrazos),-anchurapecho);
      brazodch.dibuja(rotabradchx,rotabradchy,rotabradchz,rotoantdchx,rotantdchz);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0,0,anchurapiernas);
        piernaizq.dibuja(rotopiernaizqx,rotopiernaizqy,rotopiernaizqz,rotorodillaizqz,rotopieizqy,rotopieizqz);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0,0,-anchurapiernas);
        piernadch.dibuja(rotopiernadchx,rotopiernadchy,rotopiernadchz,rotorodilladchz,rotopiedchy,rotopiedchz,translacionbalon);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0,alturatronco,0);
        cabeza.dibuja(rotocarax,rotocaray,rotocaraz);
    glPopMatrix();
}




}
