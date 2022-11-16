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

ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias,float porcentaje) {
   // completar ......(práctica 2)
    //Tupla 3f std vector  vori;
    std::vector<Tupla3f> vori ;

    ply::read_vertices( archivo,vori);
    crearMalla(vori,num_instancias,porcentaje);

}
// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)


ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias,float porcentaje) {
    std::vector<Tupla3f> vori=archivo;
    crearMalla(vori,num_instancias,porcentaje);
}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias,float porcentaje) {


  float epsilon=0.0001;//Precision del intervalo en el que decimos que es 0
  std::vector<Tupla3f> vori=perfil_original;
  const float PI=3.14159265358979323846l;
  Tupla3f polosur=Tupla3f(-1,-1,-1);
  Tupla3f polonorte=Tupla3f(-1,-1,-1);
  bool tapanorte=true;
  bool tapasur=true;


  if(abs(vori[0](0))<=epsilon){
    polosur=vori[0];
     printf("Polo sur \n");
    vori.erase(vori.begin());//v.begin()
  }
  else{
    //polosur=Tupla3f(0,vori[0](1) ,0);
     tapasur=false;

  }
  if(abs(vori[vori.size()-1](0))<=epsilon){
    printf("Polo norte \n");
    polonorte=vori[vori.size()-1];
    vori.pop_back();
  }
  else{
    //polonorte=Tupla3f(0,vori[vori.size()-1](1) ,0);
    tapanorte=false;
  }
  if(perfil_original[0](1)<perfil_original[perfil_original.size()](1)){
    Tupla3f aux=polonorte;
    polonorte=polosur;
    polosur=aux;
    std::vector<Tupla3f> r(vori.rbegin(),vori.rend());
    vori.swap(r);
  }

  /*
matriz[num_instancias,vori.size()]
for(i=0;i<num_instancias;i++)
  for(j=0;j<vori.size();j++){
    matriz[i][j]=vori[j](x*cos(angulo*i/num_instancias),y,z*sen(angulo*i/num_instancias));
  }
}

*/
v.resize(num_instancias*vori.size());
for(int i=0;i<num_instancias;i++){ //perfil
  for(int j=0;j<vori.size();j++){ // punto del perfil
    float angulo=(360*porcentaje/100*PI)/180;;
    v[i+j*num_instancias]=Tupla3f(vori[j][0]*cos(angulo*i/num_instancias + vori[j][2]*sin(angulo*i/num_instancias)),vori[j][1],-vori[j][0]*sin(angulo*i/num_instancias)+vori[j][2]*cos(angulo*i/num_instancias));

  }
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
    f.push_back(Tupla3i(a,b,b1));
    f.push_back(Tupla3i(a,b1,a1));
  }
}


if(tapasur){
v.push_back(polosur);
  for(int i=0;i<num_instancias;i++){
    f.push_back(Tupla3i(v.size()-1,i,(i+1)%num_instancias));
  }
}
if(tapanorte){
v.push_back(polonorte);
  for(int i=0;i<num_instancias;i++){
    f.push_back(Tupla3i(v.size()-1,(num_instancias)*(vori.size()-1)+(i+1)%num_instancias,(num_instancias)*(vori.size()-1)+i));
  }
  }
  /*
  for(int i=0;i<v.size();i++){
    printf("%f  ,",v[i][0]);
    printf("%f  ,",v[i][1]);
    printf(" %f \n",v[i][2]);
  }

for(int i=0;i<f.size();i++){
  printf("%d  ,",f[i][0]);
  printf("%d ,",f[i][1]);
  printf("%d \n",f[i][2]);
}
printf("EL TAMANO ES %ld \n",vori.size());
*/
for(int i=0;i<f.size();i++){
  c.push_back(Tupla3f(0.5f,0.0f,0.5f));
  p.push_back(Tupla3f(1.0f,0.0f,0.0f));
  l.push_back(Tupla3f(0.0f,0.0f,1.0f));
}

}
