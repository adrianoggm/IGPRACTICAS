#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "malla.h"
#include "cubo.h"
#include "cilindro.h"
#include "cono.h"
#include "esfera.h"
#include "piramidepentagonal.h"
#include "objply.h"
#include "objrevolucion.h"
#include "luzdireccional.h"
#include "luz.h"
#include "luzposicional.h"
#include "material.h"
#include "tetraedro.h"
#include "jugador.h"
#include "textura.h"
#include "cuadro.h"
#include "camara.h"
typedef enum {NADA, SELOBJETO,SELVISUALIZACION,SELGRADOLIB,ANIMACION,CAMARA} menu;
typedef enum {NADAA,ALPHA,BETA} menuangulo;
class Escena
{

   private:



 // ** PARÁMETROS DE LA CÁMARA (PROVISIONAL)

       // variables que definen la posicion de la camara en coordenadas polares
   GLfloat Observer_distance;
   GLfloat Observer_angle_x;
   GLfloat Observer_angle_y;

   // variables que controlan la ventana y la transformacion de perspectiva
   GLfloat Width, Height, Front_plane, Back_plane;

    // Transformación de cámara
	void change_projection( const float ratio_xy );
	void change_observer();



   void clear_window();

   menu modoMenu=NADA;
   // Objetos de la escena
   Ejes ejes;
   Cubo * cubo = nullptr ; // es importante inicializarlo a 'nullptr'
   PiramidePentagonal * piramide= nullptr ; // es importante inicializarlo a 'nullptr'
   bool modoso=true;
   bool modovert=false;
   bool modolin=false;
   bool modoluces=false;
   bool animacion=false;
   int gradolib;
   ObjPLY dodge =ObjPLY("./plys/big_dodge.ply");
   //OBJETOS DE LA ESCENA
   ObjRevolucion * peon1=nullptr;
   ObjRevolucion * peon=nullptr;
   Cilindro  * cilindro=nullptr;
   Cono * cono= nullptr;
   Esfera * esfera=nullptr;
   menuangulo angulo=NADAA;
   //LUCES DE LA Escena
   LuzPosicional * luzposi=nullptr;
   LuzDireccional * luzdire=nullptr;
   Tupla4f incremento;
   Tetraedro * tetraedro=nullptr;
   Cuadro * cuadro = nullptr ;
   Jugador * jugador1=nullptr;
   float angulopunt=0;
   //PR6
  std::vector<Camara> camaras;
  bool ratonPulsado;
  float x_ant, y_ant;
  int camaraActiva = 0;
   public:

    Escena();
	void inicializar( int UI_window_width, int UI_window_height );
	void redimensionar( int newWidth, int newHeight ) ;

	// Dibujar
	void dibujar() ;

	// Interacción con la escena
	bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
	void teclaEspecial( int Tecla1, int x, int y );
  void ratonMovido(int x, int y);
  void clickRaton(int boton, int status, int x, int y);
  void dibujar_seleccion();
  void procesar_click(int x, int y);

  void AnimacionPuntual();
  void AnimacioncolorDireccional();
};
#endif
