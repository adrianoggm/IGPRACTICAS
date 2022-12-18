
#ifndef OBJJUGADOR_H_INCLUDED
#define OBJJUGADOR_H_INCLUDED

#include "auxiliar.h"
#include "malla.h"
#include "cilindro.h"
#include "esfera.h"
#include "brazo.h"
#include "pierna.h"
#include "piernabalon.h"
#include "cabeza.h"


// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class Jugador
{
  private:
    Cabeza * cabeza=nullptr;
    Cilindro  *tronco=nullptr ;
    Brazo *  brazodch=nullptr;
    Brazo *  brazoizq=nullptr;
    Pierna * piernaizq = nullptr;
    Piernabalon * piernadch=nullptr;

    float rotobrazodx=0;
    float rotobrazodz=0;
    float rotoantbrazodz=0;

    float rotobrazoizx=0;
    float rotobrazoizy=0;
    float rotoantbrazoiz=0;


    float rotopiernady=0;
    float rotopiernadz=0;
    float rotorodilladz=0;
    float rotopiedz=0;
    Tupla3f desplazamiento=Tupla3f (0.0f,0.0f,0.0f);

    int n_iteraciones_bucle=0;
    int n_iteraciones=0;
    float incremento=0;
    int n_iteraciones_carga;
    int n_iteraciones_descarga;
    int n_iteraciones_golpeo;
    int n_iteraciones_fin;

  

  public :
  Jugador();
  void dibuja(float rotabraizqx,float rotabraizqy,float rotabraizqz,float rotoantizqx,float rotoantizqz,
  float rotabradchx,float rotabradchy,float rotabradchz,float rotoantdchx,float rotantdchz,
  float rotopiernaizqx,float rotopiernaizqy,float rotopiernaizqz,float rotorodillaizqz,float rotopieizqy,float rotopieizqz,
  float rotopiernadchx,float rotopiernadchy,float rotopiernadchz,float rotorodilladchz,float rotopiedchy,float rotopiedchz,Tupla3f translacionbalon,
  float rotocarax,float rotocaray,float rotocaraz);

  void animacion();
  void setincremento(float increment);
  void draw();
  void setgradolibertad(int gradolib,float increment);
  void resetJugador();
  };



#endif
