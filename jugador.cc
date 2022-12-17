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
/*  La idea es que cada iteración que se llame a esta función actualize los parametros
    De tal forma que  haga la animación.
    la animación estará compuesta de 3 fases,
      carga pie derecho va hacia atrás(eje z) junto con brazo derecho(eje y) brazo izq y
      descarga pie derecho hacia delante  brazo derecho tmb y izq atras.
      golpeo justo cuando pasa de esta fase de la animación propulsa la bola con una aceleracón cte
*/
  //carga tendremos un total de 56/2 estados lo que lo hace un total de 28 estados
  float angulo_final=56.0;
  float angulo_finaly=10.0;

if(n_iteraciones==0){
   n_iteraciones_carga=15-incremento*15;
   n_iteraciones_descarga=15-incremento*15;
   n_iteraciones_golpeo=10-incremento*15;
   n_iteraciones_fin=15-incremento*15;
}
  //parametros de jugador n_iteraciones=0;
  //for(int i=0; i<56;i++){
  int suma_iteraciones=n_iteraciones_carga+n_iteraciones_descarga+n_iteraciones_golpeo;

    if(n_iteraciones<n_iteraciones_carga){

      rotobrazodx=n_iteraciones_bucle*(45.0/n_iteraciones_carga);
      rotobrazodz=n_iteraciones_bucle*(-25.0/n_iteraciones_carga);
      rotoantbrazodz=n_iteraciones_bucle*(-15.0/n_iteraciones_carga);

      rotobrazoizx=n_iteraciones_bucle*-90.0/n_iteraciones_carga;
      rotobrazoizy=n_iteraciones_bucle*-10.0/n_iteraciones_carga;
      rotoantbrazoiz=n_iteraciones_bucle*-15.0/n_iteraciones_carga;

      rotopiernadz=n_iteraciones_bucle*56.0/n_iteraciones_carga; //descompondremos el movimiento en estos 56 grados
      rotopiernady=n_iteraciones_bucle*angulo_finaly/n_iteraciones_carga;      //basandonos en esos 56 grados dividimos la racion para sacar cuanto sera el incremento
      rotorodilladz=n_iteraciones_bucle*(30.0/n_iteraciones_carga);
      rotopiedz=n_iteraciones_bucle*50.0/n_iteraciones_carga;
      /*
      jugador1->dibuja(-90,-10,0,0,-15,
      45,0,-25,0,-15,
      0,0,0,0,0,0,
      0,10,56,30,0,50,Tupla3f (0,0,0),
      0,0,0)
*/
    }
    else{
      if(n_iteraciones<n_iteraciones_descarga+n_iteraciones_carga){



        rotobrazoizy=n_iteraciones_bucle*(25.0+10.0)/n_iteraciones_descarga;

        rotobrazodx=n_iteraciones_bucle*5.0/n_iteraciones_descarga;
        rotobrazodz=n_iteraciones_bucle*(20.0+25.0)/n_iteraciones_descarga;

        rotopiernadz=n_iteraciones_bucle*-(56.0+15.0)/n_iteraciones_descarga; //descompondremos el movimiento en estos 56 grados
        rotopiernady=n_iteraciones_bucle*-(angulo_finaly+10.0)/n_iteraciones_descarga;      //basandonos en esos 56 grados dividimos la racion para sacar cuanto sera el incremento
        rotorodilladz=n_iteraciones_bucle*-30.0/n_iteraciones_descarga;
        /*
        jugador1->dibuja(-90,25,0,0,-15,
        50,0,20,0,-15,
        0,0,0,0,0,0,
        0,-10,-15,0,0,50,Tupla3f (0,0,0),
        0,0,0);*/
      }
      else{
        if(n_iteraciones<n_iteraciones_descarga+n_iteraciones_carga+n_iteraciones_golpeo){
            desplazamiento=desplazamiento+(Tupla3f(-80.0/n_iteraciones_golpeo,7.0f/n_iteraciones_golpeo,0.0));
            rotopiernadz=n_iteraciones_bucle*-(45.0-15.0)/n_iteraciones_golpeo;
            rotopiernady=n_iteraciones_bucle*(20)/n_iteraciones_golpeo;
          }

      else{
        desplazamiento=desplazamiento+Tupla3f(-140.0/n_iteraciones_fin,9.8/n_iteraciones_fin,0.0);
        rotopiernadz=n_iteraciones_bucle*-(30.0-15.0)/n_iteraciones_fin;

      }

    }
  }
    this->dibuja(rotobrazoizx,rotobrazoizy,0,0,rotoantbrazoiz,
    rotobrazodx,0,rotobrazodz,0,rotoantbrazodz,
    0,0,0,0,0,0,
    0,rotopiernady,rotopiernadz,rotorodilladz,0,rotopiedz,desplazamiento,
    0,0,0);

    n_iteraciones++;
    n_iteraciones_bucle++;
    if(n_iteraciones==n_iteraciones_descarga+n_iteraciones_carga+n_iteraciones_golpeo){
        n_iteraciones_bucle=0;
    }
    if(n_iteraciones==n_iteraciones_descarga+n_iteraciones_carga){
        n_iteraciones_bucle=0;
    }
    if(n_iteraciones==n_iteraciones_carga){
        n_iteraciones_bucle=0;
    }
    if(  n_iteraciones==n_iteraciones_descarga+n_iteraciones_carga+n_iteraciones_golpeo+n_iteraciones_fin){
      rotobrazodx=0.0;
      rotobrazodz=0.0;
      rotoantbrazodz=0.0;

      rotobrazoizx=0.0;
      rotobrazoizy=0.0;
      rotoantbrazoiz=0.0;

      rotopiernadz=0.0; //descompondremos el movimiento en estos 56 grados
      rotopiernady=0.0;    //basandonos en esos 56 grados dividimos la racion para sacar cuanto sera el incremento
      rotorodilladz=0.0;
      rotopiedz=0.0;
      n_iteraciones=0;
      n_iteraciones_bucle=0;
      desplazamiento=Tupla3f(0.0,0.0,0.0);
    }


  //}
}
void Jugador::setincremento(float increment){
  if((incremento+increment)<0.5){
    incremento+=increment;
  }
  else{
    if((incremento+increment)>-0.3){
      incremento+=increment;
    }
  }
}
void Jugador::setgradolibertad(int gradolib,float increment){

}
