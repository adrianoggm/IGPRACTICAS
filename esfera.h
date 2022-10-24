// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef OBJESFERA_H_INCLUDED
#define OBJESFERA_H_INCLUDED

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

class Esfera : public ObjRevolucion
{
public :
Esfera();
Esfera ( const int num_vert_perfil ,const int num_instancias_perf ,const float radio );
} ;


#endif
