

#ifndef OBJANTEBRAZ_H_INCLUDED
#define OBJANTEBRAZ_H_INCLUDED

#include "auxiliar.h"
#include "malla.h"
#include "cilindro.h"
#include "esfera.h"
#include "mano.h"



// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class Antebrazo
{
  private:

  Esfera * codo=nullptr;
  Cilindro  *radio=nullptr ;
  Mano *mano=nullptr;

  public :
  Antebrazo();
  void dibuja(float rotoantx,float rotoantz);


  };


#endif
