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

    ply::read_vertices( archivo,vori);
    crearMalla(vori,num_instancias);

}
// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)


ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias) {


}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias) {

  float aumento=30.0;


  std::vector<Tupla3f> vori=perfil_original;
  const float PI=3.14159265358979323846l;
  Tupla3f polosur=Tupla3f(-1,-1,-1);
  Tupla3f polonorte=Tupla3f(-1,-1,-1);

  if(vori[0](1)==0){
    polosur=vori[0];
    vori.erase(vori.begin());//v.begin()

  }
  if(vori[vori.size()-1](1)==0){
    polonorte=vori[vori.size()-1];
    vori.pop_back();

  }
  if(polonorte[2]>polosur[2]){
    Tupla3f aux=polonorte;
    polonorte=polosur;
    polosur=aux;
    std::vector<Tupla3f> r(vori.rbegin(),v.rend());
    vori.swap(r);
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
    v[i+j*num_instancias]=Tupla3f((vori[j][0]*cos(2*PI*i/num_instancias + vori[j][2]*sin(2*PI*i/num_instancias)))*aumento,vori[j][1]*aumento,(-vori[j][0]*sin(2*PI*i/num_instancias)+vori[i][2]*cos(2*PI*i/num_instancias))*aumento);

  }
}
for(int i=0;i<v.size();i++){
  printf("%f  ,",v[i][0]);
  printf("%f  ,",v[i][1]);
  printf(" %f \n",v[i][2]);
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
for(int i=0;i<num_instancias;i++){ //perfil
  for(int j=0;j<vori.size()-1;j++){ // punto del perfil
    int a=i+j*num_instancias;
    int a1=j*num_instancias+(i+1)%num_instancias;
    int b=(num_instancias*((j+1)%vori.size()))+i;
    int b1=(num_instancias*((j+1)%vori.size()))+(i+1)%num_instancias;
    f.push_back(Tupla3i(a,b1,b));
    f.push_back(Tupla3i(a,a1,b1));
  }
}


if(polosur[0]!=-1){
  v.push_back(polosur);
  for(int i=0;i<num_instancias;i++){
    f.push_back(Tupla3i(v.size()-1,i*vori.size()+vori.size(),(i*vori.size()+vori.size()+1)%vori.size()));
  }
}
if(polonorte[0]!=-1){
  v.push_back(polonorte);
  for(int i=0;i<num_instancias;i++){
    f.push_back(Tupla3i(v.size()-1,i*vori.size(),(i*vori.size()+1)%vori.size()));
  }
}
for(int i=0;i<f.size();i++){
  printf("%d  ,",f[i][0]);
  printf("%d ,",f[i][1]);
  printf("%d \n",f[i][2]);
}
printf("EL TAMANO ES %ld \n",vori.size());
for(int i=0;i<f.size();i++){
  c.push_back(Tupla3f(1.0f,0.0f,0.0f));
}
}
