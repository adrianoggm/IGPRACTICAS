// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cuadro.h

//
// #############################################################################

#ifndef Cuadro_H_INCLUDED
#define Cuadro_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cuadro con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class Cuadro : public Malla3D
{
   public:
   Cuadro(float l=1) ;

} ;




#endif
