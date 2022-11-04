#include "auxiliar.h"
#include "luz.h"




// *****************************************************************************
//
// Clase ObjLuz(práctica 3)
//
// *****************************************************************************


// *****************************************************************************




void Luz:: activar(){

//
  
  if(!this->activada){
    GLboolean activado=GL_TRUE;
    GLenum idluz;
    for(int j=0;j<luces.size()&&activado==GL_TRUE;j++){
      glGetBooleanv(luces[j],&activado);
      if(activado==GL_FALSE){
        printf("Has podido activarasignar en el if la id  \n %d",j);
        idluz=luces[j];
      }

    }
    if(activado==GL_TRUE){
      printf("Para Poder activar esta luz debe previamente liberar con glDisable(GL_LIGHTi) \n ");
    }
    else{
      printf("Has podido activar \n ");
        this->activada=true;
        this->id=idluz;
        glEnable (this->id);
        glLightfv(this->id,GL_POSITION,this->posicion);
        glLightfv(this->id,GL_SPECULAR,this->Especular);
        glLightfv(this->id,GL_AMBIENT,this->colorAmbiente);
        glLightfv(this->id,GL_DIFFUSE,this->colorDifuso);

    }
  }
  else{
    glEnable (this->id);
    glLightfv(this->id,GL_POSITION,this->posicion);
    glLightfv(this->id,GL_SPECULAR,this->Especular);
    glLightfv(this->id,GL_AMBIENT,this->colorAmbiente);
    glLightfv(this->id,GL_DIFFUSE,this->colorDifuso);
  }


}
