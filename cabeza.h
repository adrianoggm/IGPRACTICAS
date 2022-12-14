// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef OBJCABEZA_H_INCLUDED
#define OBJCABEZA_H_INCLUDED

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

class Cabeza
{
  public :
  Cabeza();
  void dibuja(float rotocarax,float rotocaray,float rotocaraz);
  };


#endif
