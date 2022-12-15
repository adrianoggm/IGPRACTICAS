

#ifndef OBJRODILLA_H_INCLUDED
#define OBJRODILLA_H_INCLUDED

#include "auxiliar.h"
#include "malla.h"
#include "cilindro.h"
#include "esfera.h"
#include "tibia.h"
#include "pie.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class Rodilla
{
  private:
    Pie * pie=nullptr;
    Tibia *tibia=nullptr ;
  public :
    Rodilla();
    void dibuja(float rotorodillaz,float rotopiey,float rotopiez);
  };


#endif
