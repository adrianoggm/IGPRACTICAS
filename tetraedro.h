// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: piramidepentagonal.h

//
// #############################################################################

#ifndef  TETRAEDRO_H_INCLUDED
#define  TETRAEDRO_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Pirámide de base pentagonal con base centrada en el origen

class Tetraedro: public Malla3D
{
   public:
      Tetraedro(float r=0.5);

} ;




#endif
