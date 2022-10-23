// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef OBJCILINDRO_H_INCLUDED
#define OBJCILINDRO_H_INCLUDED

#include "auxiliar.h"
#include "malla.h"
#include "objrevolucion.h"
// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class Cilindro : public ObjRevolucion
{
  public :
  Cilindro();
  Cilindro ( const int num_vert_perfil ,
  const int num_instancias_perf ,
  const float altura ,
  const float radio );
  } ;


#endif
