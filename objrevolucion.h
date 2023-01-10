// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef OBJREVOLUCION_H_INCLUDED
#define OBJREVOLUCION_H_INCLUDED

#include "auxiliar.h"
#include "malla.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class ObjRevolucion : public Malla3D
{

   public:
       ObjRevolucion();
   ObjRevolucion(const std::string & archivo, int num_instancias,float porcentaje);
   ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias,float porcentaje) ;
protected:
    void crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias,float porcentaje);
    void calcularCoordTextura() override;
    int num_instancias = 0;
    std::vector<Tupla3f> perfil;
    float distanciaVertice(Tupla3f ant, Tupla3f sig);
} ;




#endif
