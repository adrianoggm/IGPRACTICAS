#include "auxiliar.h"
#include "textura.h"





Textura:: Textura ( std::string archivo){
  jpg :: Imagen * pimg = NULL ;
  pimg = new jpg :: Imagen (archivo);

  width= pimg -> tamX (); // núm. columnas (unsigned)
  heigth = pimg -> tamY (); // núm. filas (unsigned|)
  unsigned char *texels;

  for (unsigned i = 0; i < heigth; i++){
      for (unsigned j = 0; j < width; j++){
        texels = pimg->leerPixel(j, heigth - i - 1);
        //rojo
        data.push_back(*texels);
        texels++;
        //azul
        data.push_back(*texels);
        texels++;
        //verde
        data.push_back(*texels);
        texels++;
      }

}
idtextura= -1;
}

void Textura:: activar(){
  glEnable( GL_TEXTURE_2D );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	if (idtextura == -1){
		glGenTextures(1, &idtextura);
		glBindTexture(GL_TEXTURE_2D, idtextura);
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, heigth,GL_RGB, GL_UNSIGNED_BYTE, data.data());
	}
	glBindTexture(GL_TEXTURE_2D, idtextura);
  	}
