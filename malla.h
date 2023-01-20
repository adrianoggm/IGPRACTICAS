// #############################################################################
//
// Informática Gráfica D (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef MALLA3D_H_INCLUDED
#define MALLA3D_H_INCLUDED

#include "auxiliar.h"
#include "material.h"
#include "textura.h"
// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class Malla3D
{
   public:

   // función que dibuja el objeto en modo diferido (usando VBOs)
   void draw() ;
   bool modo_puntos=false;
   bool modo_alambre=false;
   bool modo_solido=true;
   int  estadodibujo=1;
   void calcularNormales();
   void setMaterial(Material m);
   void setTextura(const std::string & archivo);
   void setselec(bool valor);
   void editarcolor(Tupla3f color);
   void drawespecial();
   protected:


   std::vector<Tupla3f> v ;   // tabla de coordenadas de vértices (una tupla por vértice, con tres floats)
   std::vector<Tupla3i> f ; // una terna de 3 enteros por cada cara o triángulo
   // completar P1: tabla de colores
   std::vector<Tupla3f> c; //tabla de colores con el num de la cara y los colores en RGB
   // Completar P1: vbo y método asociado
   std::vector<Tupla3f> l;
   std::vector<Tupla3f> p;
   std::vector<Tupla3f> nv;
   std::vector<Tupla3f> modoseleccion;
   int modo_textura=0;//cilindrica por defecto
   Material material;
   GLuint id_vbo_ver=0;
   GLuint id_vbo_tri=0;
   GLuint id_vbo_nv=0;
   GLuint id_vbo_c=0;
   GLuint id_vbo_l=0;
   GLuint id_vbo_p=0;
   GLuint id_vbo_seleccion=0;
   std::vector<Tupla2f> ct;
   Textura * textura=nullptr;
   virtual void calcularCoordTextura();
   bool seleccion=false;
   void creaVBOseleccion();

} ;


#endif
