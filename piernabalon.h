

#ifndef OBJPIERNABALON_H_INCLUDED
#define OBJPIERNABALON_H_INCLUDED

#include "auxiliar.h"
#include "malla.h"
#include "cilindro.h"
#include "esfera.h"
#include "pierna.h"


// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class Piernabalon
{
private:
  Pierna * pierna=nullptr;
  Esfera *  balon=nullptr;
  public :
  Piernabalon();
  void dibuja(float rotopiernax,float rotopiernay,float rotopiernaz,float rotorodillaz,float rotopiey,float rotopiez,Tupla3f translacionbalon);
  };


#endif
