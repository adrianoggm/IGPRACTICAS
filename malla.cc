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
    creaVBOseleccion();
   }
   if(id_vbo_nv==0 && nv.size()>0)
   {

     id_vbo_nv=CrearVBO(GL_ARRAY_BUFFER,nv.size()*sizeof(Tupla3f),nv.data());

   }
   // activar buffer
  if(seleccion){
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_seleccion );
     // habilitar uso de array de col.
    glColorPointer( 3, GL_FLOAT, 0, 0); // especifíca puntero a colores
    glBindBuffer ( GL_ARRAY_BUFFER , 0);
    glEnableClientState( GL_COLOR_ARRAY );
  }
  else{

   GLint polygonMode[2];
   glGetIntegerv(GL_POLYGON_MODE,polygonMode);

   if(polygonMode[0]==GL_POINT){
     if ( id_vbo_p!=0){
    glPointSize(	3.0f);
    glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_p );
   //
    glColorPointer( 3, GL_FLOAT, 0, 0); // especifíca puntero a colores
    glBindBuffer ( GL_ARRAY_BUFFER , 0);
    glEnableClientState( GL_COLOR_ARRAY );
    }
   }
   if(polygonMode[0]==GL_LINE){
     if ( id_vbo_l!=0){
    glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_l );
     // habilitar uso de array de col.
    glColorPointer( 3, GL_FLOAT, 0, 0); // especifíca puntero a colores
    glBindBuffer ( GL_ARRAY_BUFFER , 0);
    glEnableClientState( GL_COLOR_ARRAY );
  }
  }
  if(polygonMode[0]==GL_FILL){
    if ( id_vbo_c!=0){
      glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_c );
    // habilitar uso de array de col.
      glColorPointer( 3, GL_FLOAT, 0, 0); // especifíca puntero a colores
      glBindBuffer ( GL_ARRAY_BUFFER , 0);
      glEnableClientState( GL_COLOR_ARRAY );
    }

    }
}
    glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_ver );
   // usar como buffer de vertices el actualmente activo
    glVertexPointer ( 3 , GL_FLOAT , 0 , 0 );
    // deactivar buffer: VBO de vértices.
     glBindBuffer ( GL_ARRAY_BUFFER , 0 );
    // habilitar el uso de tabla de vértices
    glEnableClientState ( GL_VERTEX_ARRAY );

    //if(glIsEnabled(GL_LIGHTING)){
		//Habilitar uso de la tablade normales
    glEnable(GL_NORMALIZE);
    //luzdire->activar();
    glShadeModel(GL_SMOOTH);
    //this->material.aplicar();
		glEnableClientState(GL_NORMAL_ARRAY);
		//activar vbo de normales
		glBindBuffer(GL_ARRAY_BUFFER,id_vbo_nv);
		//usar como buffer de normales el actualmente activo
		glNormalPointer(GL_FLOAT,0,0);
		//desactivar el uso de la tabla de normales
		glBindBuffer(GL_ARRAY_BUFFER,0);

    this->material.aplicar();
	//}

  if (textura != nullptr&&!seleccion) {
		textura->activar();
		glEnable( GL_TEXTURE_2D );
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer( 2, GL_FLOAT, 0, ct.data());
	}

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
  if(glIsEnabled(GL_LIGHTING)){
    glDisableClientState(GL_NORMAL_ARRAY);
  }
  if(textura != nullptr&&!seleccion){
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisable( GL_TEXTURE_2D );
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
void Malla3D::calcularCoordTextura(){
  // para hacer overwrite desde obj revolucion y seguir llamandola desde malla

}
void Malla3D::setMaterial(Material m){

    this->material=m;
}

void Malla3D::setTextura(const std::string & archivo){

	if (textura != nullptr)
		delete textura;

	textura = new Textura(archivo);

	calcularCoordTextura();

}

  void Malla3D::creaVBOseleccion(){

    if(id_vbo_seleccion==0)
    {
      Tupla3f colorseleccion=Tupla3f(0.3f,0.3,.3f);//un tipo de gris
      for(int i =0;i<l.size();i++){
          modoseleccion.push_back(colorseleccion);
      }
        id_vbo_seleccion=CrearVBO(GL_ARRAY_BUFFER,modoseleccion.size()*sizeof(Tupla3f),modoseleccion.data());
    }

  }

void Malla3D::setselec(bool valor){

  seleccion=valor;

}
void Malla3D::editarcolor(Tupla3f color){
  c.clear();
  id_vbo_c=0;
  for(int i =0; i<f.size();i++){
    c.push_back(color);
  }

}
void Malla3D::drawespecial()
{
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  glBindBuffer ( GL_ARRAY_BUFFER , id_vbo_seleccion );
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
