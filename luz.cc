#include "auxiliar.h"
#include "luz.h"




// *****************************************************************************
//
// Clase ObjLuz(práctica 3)
//
// *****************************************************************************


// *****************************************************************************




void Luz:: activar(){
  std::vector <bool> lucesLibres={true,true,true,true,true,true,true,true};
  std::vector <GLenum> luces={GL_LIGHT0,GL_LIGHT1,GL_LIGHT2,GL_LIGHT3,GL_LIGHT4,GL_LIGHT5,GL_LIGHT6,GL_LIGHT7};


  bool activado=false;
  GLenum idluz;
  for(int j=0;j<lucesLibres.size()&& !activado;j++){
    if(lucesLibres[j]=true){
      idluz=luces[j];
      activado=true;
    }
  }
  if(!activado){
    printf("Para Poder activar esta luz debe previamente liberar con glDisable(GL_LIGHTi) \n ");
  }
  else{
      glEnable( GL_LIGHTING );
      this->id=idluz;
      glEnable (this->id);
      glLightfv(this->id,GL_POSITION,this->posicion);
      glLightfv(this->id,GL_SPECULAR,this->Especular);
      glLightfv(this->id,GL_AMBIENT,this->colorAmbiente);
      glLightfv(this->id,GL_DIFFUSE,this->colorDifuso);

  }

}
