// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef LUZPOSICIONAL_H_INCLUDED
#define LUZPOSICIONAL_H_INCLUDED

#include "auxiliar.h"
#include "luz.h"
// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class  LuzPosicional : public Luz
{

  public :
  LuzPosicional ( const Tupla3f & posicion ) ;

  void Incrementarluz (Tupla4f incremento ) ;
  void CambiarPosicion ( Tupla3f posi) ;
} ;


#endif
