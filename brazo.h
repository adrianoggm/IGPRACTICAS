
#ifndef OBJBRAZO_H_INCLUDED
#define OBJBRAZO_H_INCLUDED

#include "auxiliar.h"
#include "malla.h"
#include "cilindro.h"
#include "esfera.h"
#include "antebrazo.h"



// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class Brazo
{
  private:
    Esfera * hombro=nullptr;
    Cilindro  *biceps=nullptr ;
    Antebrazo *antebrazo=nullptr;
  public :
  Brazo();
  void dibuja(float rotabrax,float rotabray,float rotabraz,float rotoantx,float rotoantz);
  };


#endif
