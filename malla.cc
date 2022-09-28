#include "auxiliar.h"
#include "malla.h"

// *****************************************************************************
//
// IG_D Clase Malla3D
//
// *****************************************************************************
// -----------------------------------------------------------------------------
// Función de uso del VBOs
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
// Función de visualización de la malla,
void Malla3D::draw()
{
   // (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   // completar (práctica 1)
   // .....
   //COMPRUEBO SI NO ESTAN CREADOS LOS ID DE OBJETO DE LOS VBOs
   if(id_vbo_ver==0)
   {
     id_vbo_ver=CrearVBO();
   }
   if(id_vbo_tri==0)
   {
     id_vbo_tri=CrearVBO();
   }
   if(id_vbo_c==0)
   {
     id_vbo_c=CrearVBO();
   }

   //AQUÍ UNA VEZ CREADOS LOS ID y los VBOs activamos
   //cuales son los buffer a usar y cargamos desde la gráfica las tablas
    if(id_vbo_ver!=0)
    {

      // especifícar cual es el VBO que vamos a usar
      glEnableClientState ( GL_VERTEX_ARRAY );
      // especifícar cual es el VBO que vamos a usar
      glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_ver );
      // Usar el buffer activo para vertices
      glVertexPointer(3,GL_FLOAT,0,);
    }
    if(id_vbo_tri!=0)
    {
    //no se hacerlo aún
    // especifícar cual es el VBO que vamos a usar
    glEnableClientState ( GL_NORMAL_ARRAY );
    // especifícar cual es el VBO que vamos a usar
    glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_tri );
    // Usar el buffer activo para vertices
    glNormalPointer(3,GL_FLOAT,0,);//AQUI TIENE QUE REVENTAR NO SE QUE FUNCION DEBE SER
    }
    if ( id_vbo_c != 0 )
    {
      // habilitar uso de array de colores
      glEnableClientState ( GL_COLOR_ARRAY );
      // especifícar cual es el VBO que vamos a usar
      glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_c );
      // Usar el buffer activo para el color
      glColorPointer (4,GL_FLOAT,0,0);
    }


}
