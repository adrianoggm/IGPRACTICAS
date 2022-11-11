// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef LUZ_H_INCLUDED
#define LUZ_H_INCLUDED

#include "auxiliar.h"

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************



class  Luz
{
   public:

   // función que dibuja el objeto en modo diferido (usando VBOs)
   void activar() ;
   GLenum id;
   bool activada=false;
   bool encendida=false;
   //void setMaterial(Material m);
   protected:



   Tupla4f posicion;
   Tupla4f colorDifuso;
   Tupla4f colorAmbiente;
   Tupla4f Especular;

   std::vector <GLenum> luces={GL_LIGHT0,GL_LIGHT1,GL_LIGHT2,GL_LIGHT3,GL_LIGHT4,GL_LIGHT5,GL_LIGHT6,GL_LIGHT7};




} ;



#endif
