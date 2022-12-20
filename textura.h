// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef TEXTURA_H_INCLUDED
#define TEXTURA_H_INCLUDED

#include "auxiliar.h"
#include "jpg_imagen.hpp"

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************



class Textura {

    GLuint idtextura=0;
    std::vector<unsigned char> data;
    int width;
    int heigth;
  public :
    Textura ( std::string archivo );
    void activar();
    Textura();
};



#endif
