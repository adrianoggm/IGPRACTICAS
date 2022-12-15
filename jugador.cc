#include "auxiliar.h"
#include "malla.h"
#include "jugador.h"

Jugador::Jugador(){
  tronco= new Cilindro(11,10,58,20);//20 de radio 40 de diametro
  piernaizq = new Pierna()
  piernadch=new  Piernabalon();
  brazoizq=new Brazo();
  brazodch=new Brazo();
  cabeza=new Cabeza();

}
void Jugador::dibuja(float rotabraizqx,float rotabraizqy,float rotabraizqz,float rotoantizqx,float rotoantizqz,
float rotabradchx,float rotabradchy,float rotabradchz,float rotoantdchx,float rotantdchz,
float rotopiernaizqx,float rotopiernaizqy,float rotopiernaizqz,float rotorodillaizqz,float rotopieizqy,float rotopieizqz,
float rotopiernadchx,float rotopiernadchy,float rotopiernadchz,float rotorodilladchz,float rotopiedchy,float rotopiedchz,Tupla3f translacionbalon,
float rotocarax,float rotocaray,float rotocaraz){
  glPushMatrix();
    glTranslatef(0,alturatronco,0);
        tronco->draw();
  glPopMatrix();

    glPushMatrix();
      glTranslatef(0,(58-3),20+3);//altura brazos= altura tronco -radio de hombro anchura es anchura de tronco + radop hombro
      brazoizq->dibuja(rotabraizqx,rotabraizqy,rotabraizqz,rotoantizqx,rotantizqz);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0,(58-3),-23);
      brazodch->dibuja(rotabradchx,rotabradchy,rotabradchz,rotoantdchx,rotantdchz);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0,0,25);
        piernaizq->dibuja(rotopiernaizqx,rotopiernaizqy,rotopiernaizqz,rotorodillaizqz,rotopieizqy,rotopieizqz);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0,0,-25);
        piernadch->dibuja(rotopiernadchx,rotopiernadchy,rotopiernadchz,rotorodilladchz,rotopiedchy,rotopiedchz,translacionbalon);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0,alturatronco,0);
        cabeza->dibuja(rotocarax,rotocaray,rotocaraz);
    glPopMatrix();
}
