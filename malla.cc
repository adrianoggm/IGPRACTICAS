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
     id_vbo_ver=CrearVBO(GL_ARRAY_BUFFER,v.size()*sizeof(Tupla3f),v.data());
   }
   if(id_vbo_tri==0)
   {
     id_vbo_tri=CrearVBO(GL_ELEMENT_ARRAY_BUFFER,f.size()*sizeof(Tupla3i),f.data());
   }
   if(id_vbo_c==0)
   {
     id_vbo_c=CrearVBO(GL_ARRAY_BUFFER,c.size()*sizeof(Tupla3i),c.data());
    id_vbo_l=CrearVBO(GL_ARRAY_BUFFER,l.size()*sizeof(Tupla3i),l.data());
    id_vbo_p=CrearVBO(GL_ARRAY_BUFFER,p.size()*sizeof(Tupla3i),p.data());
   }
   // activar buffer
   if ( id_vbo_c!=0 && id_vbo_tri!=0 && id_vbo_ver!=0) {


    if(modo_puntos){

      glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_p );
     // habilitar uso de array de col.
      glColorPointer( 3, GL_FLOAT, 0, 0); // especifíca puntero a colores
      glBindBuffer ( GL_ARRAY_BUFFER , 0);
     glEnableClientState( GL_COLOR_ARRAY );


      glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_ver );
     // usar como buffer de vertices el actualmente activo
      glVertexPointer ( 3 , GL_FLOAT , 0 , 0 );
      // deactivar buffer: VBO de vértices.
       glBindBuffer ( GL_ARRAY_BUFFER , 0 );
      // habilitar el uso de tabla de vértices
      glEnableClientState ( GL_VERTEX_ARRAY );
      //
      // activar buffer: VBO de triángulos
      glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER , id_vbo_tri );
      // dibujar con el buffer de índices activo
      //glPolygonMode(GL_FRONT, GL_POINT);
      glDrawElements ( GL_TRIANGLES , 3*f.size() , GL_UNSIGNED_INT , 0 ) ;
      // desactivar buffer: VBO de triángulos
      glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER , 0 );
      // desactivar uso de array de vértices
      glDisableClientState ( GL_VERTEX_ARRAY );
      glDisableClientState ( GL_COLOR_ARRAY );


    }
    if(modo_alambre){

      glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_l );
       // habilitar uso de array de col.
      glColorPointer( 3, GL_FLOAT, 0, 0); // especifíca puntero a colores
      glBindBuffer ( GL_ARRAY_BUFFER , 0);
      glEnableClientState( GL_COLOR_ARRAY );
      glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_ver );
     // usar como buffer de vertices el actualmente activo
      glVertexPointer ( 3 , GL_FLOAT , 0 , 0 );
      // deactivar buffer: VBO de vértices.
       glBindBuffer ( GL_ARRAY_BUFFER , 0 );
      // habilitar el uso de tabla de vértices
      glEnableClientState ( GL_VERTEX_ARRAY );
      //
      // activar buffer: VBO de triángulos
      glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER , id_vbo_tri );
      // dibujar con el buffer de índices activo
      //glPolygonMode(GL_FRONT, GL_POINT);
      glDrawElements ( GL_TRIANGLES , 3*f.size() , GL_UNSIGNED_INT , 0 ) ;
      // desactivar buffer: VBO de triángulos
      glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER , 0 );
      // desactivar uso de array de vértices
      glDisableClientState ( GL_VERTEX_ARRAY );
      glDisableClientState ( GL_COLOR_ARRAY );

  }
  if(modo_solido){
    glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_c );
    // habilitar uso de array de col.
    glColorPointer( 3, GL_FLOAT, 0, 0); // especifíca puntero a colores
    glBindBuffer ( GL_ARRAY_BUFFER , 0);
    glEnableClientState( GL_COLOR_ARRAY );
    glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_ver );
   // usar como buffer de vertices el actualmente activo
    glVertexPointer ( 3 , GL_FLOAT , 0 , 0 );
    // deactivar buffer: VBO de vértices.
     glBindBuffer ( GL_ARRAY_BUFFER , 0 );
    // habilitar el uso de tabla de vértices
    glEnableClientState ( GL_VERTEX_ARRAY );
    //
    // activar buffer: VBO de triángulos
    glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER , id_vbo_tri );
    // dibujar con el buffer de índices activo
    //glPolygonMode(GL_FRONT, GL_POINT);
    glDrawElements ( GL_TRIANGLES , 3*f.size() , GL_UNSIGNED_INT , 0 ) ;
    // desactivar buffer: VBO de triángulos
    glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER , 0 );
    // desactivar uso de array de vértices
    glDisableClientState ( GL_VERTEX_ARRAY );
    glDisableClientState ( GL_COLOR_ARRAY );
  }


  /*glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_ver );
 // usar como buffer de vertices el actualmente activo
  glVertexPointer ( 3 , GL_FLOAT , 0 , 0 );
  // deactivar buffer: VBO de vértices.
   glBindBuffer ( GL_ARRAY_BUFFER , 0 );
  // habilitar el uso de tabla de vértices
  glEnableClientState ( GL_VERTEX_ARRAY );
  //
  // activar buffer: VBO de triángulos
  glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER , id_vbo_tri );
  // dibujar con el buffer de índices activo
  //glPolygonMode(GL_FRONT, GL_POINT);
  glDrawElements ( GL_TRIANGLES , 3*f.size() , GL_UNSIGNED_INT , 0 ) ;
  // desactivar buffer: VBO de triángulos
  glBindBuffer ( GL_ELEMENT_ARRAY_BUFFER , 0 );
  // desactivar uso de array de vértices
  glDisableClientState ( GL_VERTEX_ARRAY );
  glDisableClientState ( GL_COLOR_ARRAY );*/

  }
}
