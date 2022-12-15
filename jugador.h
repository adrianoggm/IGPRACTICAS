
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

  public :
  Jugador();
  void dibuja(float rotabraizqx,float rotabraizqy,float rotabraizqz,float rotoantizqx,float rotoantizqz,
  float rotabradchx,float rotabradchy,float rotabradchz,float rotoantdchx,float rotantdchz,
  float rotopiernaizqx,float rotopiernaizqy,float rotopiernaizqz,float rotorodillaizqz,float rotopieizqy,float rotopieizqz,
  float rotopiernadchx,float rotopiernadchy,float rotopiernadchz,float rotorodilladchz,float rotopiedchy,float rotopiedchz,Tupla3f translacionbalon,
  float rotocarax,float rotocaray,float rotocaraz);
  };


#endif
