

#ifndef OBJPIE_H_INCLUDED
#define OBJPIE_H_INCLUDED

#include "auxiliar.h"
#include "malla.h"
#include "cilindro.h"
#include "esfera.h"
// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class Pie
{
  private:
  Cilindro * planta=nullptr;
  Esfera * tobillo=nullptr;
  public :
  Pie();
  void dibuja(float rotopiey,float rotopiez);
  };


#endif
