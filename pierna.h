

#ifndef OBJPIERNA_H_INCLUDED
#define OBJPIERNA_H_INCLUDED

#include "auxiliar.h"
#include "malla.h"
#include "cilindro.h"
#include "esfera.h"
#include "rodilla.h"


// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class Pierna
  {
  private:
  Rodilla * rodilla=nullptr;
  Cilindro  *femur=nullptr ;
  Esfera *  cadera=nullptr;


  public :
  Pierna();
  void dibuja(float rotopiernax,float rotopiernay,float rotopiernaz,float rotorodillaz,float rotopiey,float rotopiez);
  };


#endif
