

#ifndef OBJMANO_H_INCLUDED
#define OBJMANO_H_INCLUDED

#include "auxiliar.h"
#include "malla.h"
#include "cilindro.h"



// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class Mano
{ private:
  Esfera * palma=nullptr;

  public :
  Mano();
  void dibuja();
  };


#endif
