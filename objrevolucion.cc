#include "auxiliar.h"
#include "objrevolucion.h"
#include "ply_reader.h"



// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)

ObjRevolucion::ObjRevolucion() {}

ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias) {
   // completar ......(práctica 2)
    //Tupla 3f std vector  vori;
    std::vector<Tupla3f> vori ;
    const float PI=3.14159265358979323846l;
    ply::read_vertices( archivo,vori);

    Tupla3f polosur=Tupla3f(-1,-1,-1);
    Tupla3f polonorte=Tupla3f(-1,-1,-1);

    if(vori[0](0)==0&&vori[0](3)==0){
      polosur=vori[0];
      vori.erase(vori.begin());//v.begin()

    }
    if(vori[vori.size()-1](0)==0&&vori[vori.size()-1](3)==0){
      polonorte=vori[vori.size()-1];
      vori.pop_back();

    }


    /*
	matriz[num_instancias,vori.size()]
	for(i=0;i<num_instancias;i++)
		for(j=0;j<vori.size();j++){
			matriz[i][j]=vori[j](x*cos(2*PI*i/num_instancias),y,z*sen(2*PI*i/num_instancias));
		}
	}

*/
	v.resize(num_instancias*vori.size());
	for(int i=0;i<num_instancias;i++){ //perfil
		for(int j=0;j<vori.size();j++){ // punto del perfil
			v[i+j*num_instancias]=Tupla3f(vori[j][0]*cos(2*PI*i/num_instancias + vori[j][2]*sin(2*PI*i/num_instancias) ),vori[j][1],-vori[j][0]*sin(2*PI*i/num_instancias)+vori[i][2]*cos(2*PI*i/num_instancias));

    }
 	}
  for(int i=0;i<v.size();i++){
    printf("%f  ,",v[i][0]);
    printf("%f  ,",v[i][1]);
    printf("%f \n",v[i][2]);
  }

/*
 	for(int i=0;i<vori.size()-1;i++){
 		for(int j=0;j<num_instancias;j++){
 			int a=j+i*vori.size();
 			int b=vori.size()*(i+1)%num_instancias+j;
 			f.push_back(Tupla3i(a,b,b+1));
 			f.push_back(Tupla3i(a,b+1,a+1));
 		}

 	}
*/
  for(int i=0;i<num_instancias-1;i++){ //perfil
    for(int j=0;j<vori.size()-2;j++){ // punto del perfil
      int a=j+i*vori.size();
 			int b=vori.size()*(i+1)%num_instancias+j;
 			f.push_back(Tupla3i(a,b,b+1));
 			f.push_back(Tupla3i(a,b+1,a+1));
    }
  }
  for(int i=0;i<f.size();i++){
    printf("%d  ,",f[i][0]);
    printf("%d ,",f[i][1]);
    printf("%d \n",f[i][2]);
  }
 	/*
 	if(polosur!=NULL){
 		v.push_back(polosur);

 	}
 	if(polonorte!=NULL){
 		v.push_back(polosnorte);
 		for(int i=vori.size()-1;i<v.size();i+=vori.size()){

 		}
  */

 	}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)


ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias) {


}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias) {
}
