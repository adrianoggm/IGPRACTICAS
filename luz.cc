#include "auxiliar.h"
#include "luz.h"




// *****************************************************************************
//
// Clase ObjLuz(práctica 3)
//
// *****************************************************************************


// *****************************************************************************

bool luceslibres[9];
for(int i=0;i<luceslibres.size();i++){
  luceslibres[i]=true;
}


void Luz:: activar(){

  glEnable ( GL_LIGHTING );
  //vector asignadas si no hay alguna no asignada  se la asignamos en caso contrario hacemos un printf("%s\n", ); de que se debe desactivar una luz para poder asignar
  int luzlibre=-1;
  for(int i=0;i<luceslibres.size();i++){
    if(luceslibres[i]=true){
      luzlibre=i;
    }
  }
  if(luzlibre==-1){
    printf("Para Poder activar esta luz debe previamente liberar con glDisable(GL_LIGHTi) \n ")
  }
  else{
    luceslibres[luzlibre]=false;
    glEnable ( "GL_LIGHT"+to_string(luzlibre));
  }
}
