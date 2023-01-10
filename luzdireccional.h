// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef LUZDIRECCIONAL_H_INCLUDED
#define LUZDIRECCIONAL_H_INCLUDED

#include "auxiliar.h"
#include "luz.h"
// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class  LuzDireccional : public Luz
{
  protected :
  const float PI=3.14159265358979323846l;
  float alpha ;
  float beta ;
  public :
// inicializar la fuente de luz
  LuzDireccional ( const Tupla2f & orientacion ) ;
// Cambiar ángulo:
  void variarAnguloAlpha ( float incremento ) ;
  void variarAnguloBeta ( float incremento ) ;
  void variarColor ( Tupla4f incremento );
  /*class LuzPosicional : public Luz {
    public :
    LuzPosicional ( const Tupla3f & posicion ) ;
*/




} ;


#endif
