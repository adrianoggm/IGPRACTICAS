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
   calcularNormales();

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
     id_vbo_c=CrearVBO(GL_ARRAY_BUFFER,c.size()*sizeof(Tupla3f),c.data());
    id_vbo_l=CrearVBO(GL_ARRAY_BUFFER,l.size()*sizeof(Tupla3f),l.data());
    id_vbo_p=CrearVBO(GL_ARRAY_BUFFER,p.size()*sizeof(Tupla3f),p.data());
   }
   if(id_vbo_nv==0 && nv.size()>0)
   {

     id_vbo_nv=CrearVBO(GL_ARRAY_BUFFER,nv.size()*sizeof(Tupla3f),nv.data());

   }
   // activar buffer
   if ( id_vbo_c!=0 && id_vbo_tri!=0 && id_vbo_ver!=0) {
     GLboolean islight=GL_FALSE;
     glGetBooleanv(GL_LIGHTING,&islight);
    if(islight==GL_TRUE){

       //glEnable(GL_NORMALIZE);
       this->material.aplicar();
       //
       glBindBuffer ( GL_ARRAY_BUFFER,id_vbo_nv);
       glNormalPointer(GL_FLOAT, 0,0);
       glBindBuffer ( GL_ARRAY_BUFFER,0);
       glEnableClientState(GL_NORMAL_ARRAY);

     }
   else{
     GLint polygonMode[2];
     glGetIntegerv(GL_POLYGON_MODE,polygonMode);

     if(polygonMode[0]==GL_POINT){
      glPointSize(	3.0f);
      glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_p );
     //
      glColorPointer( 3, GL_FLOAT, 0, 0); // especifíca puntero a colores
      glBindBuffer ( GL_ARRAY_BUFFER , 0);
      glEnableClientState( GL_COLOR_ARRAY );

     }
     if(polygonMode[0]==GL_LINE){
      glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_l );
       // habilitar uso de array de col.
      glColorPointer( 3, GL_FLOAT, 0, 0); // especifíca puntero a colores
      glBindBuffer ( GL_ARRAY_BUFFER , 0);
      glEnableClientState( GL_COLOR_ARRAY );
    }
    if(polygonMode[0]==GL_FILL){

      glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_c );
      // habilitar uso de array de col.
      glColorPointer( 3, GL_FLOAT, 0, 0); // especifíca puntero a colores
      glBindBuffer ( GL_ARRAY_BUFFER , 0);
      glEnableClientState( GL_COLOR_ARRAY );


      }
  }

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
  glDisableClientState(GL_NORMAL_ARRAY);
  }
}
void Malla3D::calcularNormales(){

    for(int i=0;i<v.size();i++){
      nv.push_back(Tupla3f(0,0,0));
    }
    for(int i=0;i<f.size();i++){
      Tupla3f p=v[f[i](0)];
      Tupla3f q=v[f[i](1)];
      Tupla3f r=v[f[i](2)];
      Tupla3f a= q-p;
      Tupla3f b=r-p;
      Tupla3f m=a.cross(b);
      int e=f[i](0);
      int g=f[i](1);
      int d=f[i](2);
      nv[e]=nv[e]+m;
      nv[g]=nv[g]+m;
      nv[d]=nv[d]+m;

    }
    // inizializo a 0
    //nv.pushback tupla3f (0 0 ,0)
    //

    //for normalizo nv
     for(int i=0;i<nv.size();i++){
      float modulo=sqrt(pow(nv[i](0),2)+pow(nv[i](1),2)+pow(nv[i](2),2));
      nv[i]=nv[i]/modulo;
    }

    //for normalizo nv

}

void Malla3D::setMaterial(Material m){

    this->material=m;
}
/*for(int i=0;i<perfil.size();i++){
  std::vector<Tupla3f> r(perfil.rbegin(),perfil.rend());
  perfil.swap(r);
    //
    //printf("%f  ,",perfil[i][1]);
    //printf(" %f \n",perfil[i][2]);
  }*/
