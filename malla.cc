#include "auxiliar.h"
#include "malla.h"

// *****************************************************************************
//
// IG_D Clase Malla3D
//
// *****************************************************************************
// -----------------------------------------------------------------------------
// Función de visualización de la malla,
GLuint CrearVBO ( GLuint tipo_vbo , GLuint tam ,GLvoid * puntero_ram )
{
  GLuint id_vbo ; // resultado: identificador de VBO
  glGenBuffers ( 1 , & id_vbo ); // crear nuevo VBO, obtener identificador
  glBindBuffer ( tipo_vbo , id_vbo ); // activar el VBO usando su identificador
  // esta instrucción hace la transferencia de datos desde RAM hacia GPU
  glBufferData ( tipo_vbo , tam , puntero_ram , GL_STATIC_DRAW );
  glBindBuffer ( tipo_vbo , 0 ); // desactivación del VBO (activar 0)
  return id_vbo ; // devolver el identificador resultado
}

void Malla3D::draw()
{
   // (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   // completar (práctica 1)
   // .....
   if()//si no son =0 es decir no ha empezao esto guay si no cargalos.
    id_vbo_ver=CrearVBO();
    id_vbo_tri=CrearVBO();
    id_vbo_c=CrearVBO();

}
