#include "auxiliar.h"
#include "luz.h"




// *****************************************************************************
//
// Clase ObjLuz(práctica 3)
//
// *****************************************************************************


// *****************************************************************************




void Luz:: activar(){



  GLboolean activado=GL_TRUE;
  GLenum idluz;
  for(int j=0;j<luces.size()&& activado==GL_TRUE;j++){
    glGetBooleanv(luces[j],&activado);
    if(activado==GL_FALSE){
      idluz=luces[j];
    }
  }
  if(!activado){
    printf("Para Poder activar esta luz debe previamente liberar con glDisable(GL_LIGHTi) \n ");
  }
  else{
      
      this->id=idluz;
      glEnable (this->id);
      glLightfv(this->id,GL_POSITION,this->posicion);
      glLightfv(this->id,GL_SPECULAR,this->Especular);
      glLightfv(this->id,GL_AMBIENT,this->colorAmbiente);
      glLightfv(this->id,GL_DIFFUSE,this->colorDifuso);

  }

}
