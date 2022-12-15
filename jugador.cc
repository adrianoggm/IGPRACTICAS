#include "auxiliar.h"
#include "malla.h"
#include "jugador.h"

Jugador::Jugador(){
  tronco= new Cilindro(11,10,58,18);//20 de radio 40 de diametro
  piernaizq = new Pierna();
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

        tronco->draw();
  glPopMatrix();

    glPushMatrix();
      glTranslatef(0,(58-3),18+3);//altura brazos= altura tronco -radio de hombro anchura es anchura de tronco + radop hombro
      brazoizq->dibuja(rotabraizqx,rotabraizqy,rotabraizqz,rotoantizqx,rotoantizqz);
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0,(58-3),-21);
      brazodch->dibuja(rotabradchx,rotabradchy,rotabradchz,rotoantdchx,rotantdchz);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0,0,15);
        piernaizq->dibuja(rotopiernaizqx,rotopiernaizqy,rotopiernaizqz,rotorodillaizqz,rotopieizqy,rotopieizqz);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0,0,-15);
        piernadch->dibuja(rotopiernadchx,rotopiernadchy,rotopiernadchz,rotorodilladchz,rotopiedchy,rotopiedchz,translacionbalon);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0,58,0);
        cabeza->dibuja(rotocarax,rotocaray,rotocaraz);
    glPopMatrix();
}
void Jugador::animacion(){
  /*La idea es que cada iteración que se llame a esta función actualize los parametros
    De tal forma que  haga la animación.
    la animación estará compuesta de 3 fases,
      carga pie derecho va hacia atrás(eje z) junto con brazo derecho(eje y) brazo izq y
      descarga pie derecho hacia delante  brazo derecho tmb y izq atras.
      golpeo justo cuando pasa de esta fase de la animación propulsa la bola con una aceleracón cte
  */
  //carga tendremos un total de 56/2 estados lo que lo hace un total de 28 estados
  float angulo_final=56;
  foat incremento =2;
  int n_iteraciones_carga=28;
  //for(int i=0; i<56;i++){

  //}
}
