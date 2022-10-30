

#include "auxiliar.h"     // includes de OpenGL/glut/glew, windows, y librería std de C++
#include "escena.h"
#include "malla.h" // objetos: Cubo y otros....

//**************************************************************************
// constructor de la escena (no puede usar ordenes de OpenGL)
//**************************************************************************

Escena::Escena()
{
    Front_plane       = 50.0;
    Back_plane        = 2000.0;
    Observer_distance = 4*Front_plane;
    Observer_angle_x  = 0.0 ;
    Observer_angle_y  = 0.0 ;

    ejes.changeAxisSize( 5000 );

    // crear los objetos de la escena....
    // .......completar: ...
    // .....
    piramide= new PiramidePentagonal(150.0,100.0);
    cubo = new Cubo(70.0);
    peon =new ObjRevolucion("./plys/peon.ply",10);


    cilindro=new Cilindro(11,35,100,50);//num_vert_perfil ,const int num_instancias_perf ,const float altura ,const float radio

    //cilindro.draw();


    cono=new Cono(11,35,100,50);//( const int num_vert_perfil ,const int num_instancias_perf,const float altura ,const float radio )


    esfera=new Esfera(11,35,100);//( const int num_vert_perfil ,const int num_instancias_perf,const float altura ,const float radio )


}

//**************************************************************************
// inicialización de la escena (se ejecuta cuando ya se ha creado la ventana, por
// tanto sí puede ejecutar ordenes de OpenGL)
// Principalmemnte, inicializa OpenGL y la transf. de vista y proyección
//**************************************************************************

void Escena::inicializar( int UI_window_width, int UI_window_height )
{
	glClearColor( 1.0, 1.0, 1.0, 1.0 );// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable( GL_DEPTH_TEST );	// se habilita el z-bufer

	Width  = UI_window_width/10;
	Height = UI_window_height/10;
  glEnable (GL_CULL_FACE);
  change_projection( float(UI_window_width)/float(UI_window_height) );
	glViewport( 0, 0, UI_window_width, UI_window_height );
}



// **************************************************************************
//
// función de dibujo de la escena: limpia ventana, fija cámara, dibuja ejes,
// y dibuja los objetos
//
// **************************************************************************

void Escena::dibujar()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
    ejes.draw();
    // COMPLETAR
    //   Dibujar los diferentes elementos de la escena
    // Habrá que tener en esta primera práctica una variable que indique qué objeto se ha de visualizar
    // y hacer
    // cubo->draw()
    // o    piramide->draw()
    /*
    ObjPLY beethoven =ObjPLY("beethoven.ply");
    beethoven.draw();
    */

/*

    glPushMatrix ();
    glTranslatef (-100,0,100);
    // dibujar el primer objeto
    esfera.draw();
    glPopMatrix ();

    glPushMatrix ();
    glTranslatef (100,0,-100);
    cono.draw();
    glPopMatrix ();
    //...
    glPushMatrix ();
    glTranslatef (-100,0,-100);
    cilindro.draw();
    glPopMatrix ();

    glPushMatrix ();
    glTranslatef (0,100,0);
    glScalef(17,17,17);
    peon.draw();
    glPopMatrix ();

    dodge.estadodibujo=2;
    dodge.modo_alambre=true;
        glPushMatrix ();
        glScalef(4,4,4);
        dodge.draw();
       glPopMatrix ();
       */



      if(modoso){
        printf("pintapiramide con solido");


        glPolygonMode(GL_FRONT,GL_FILL);
        piramide->draw();
        cubo->draw();

        glPushMatrix ();
        glTranslatef (-100,0,100);
        // dibujar el primer objeto
        esfera->draw();
        glPopMatrix ();

        glPushMatrix ();
        glTranslatef (100,0,-100);
        cono->draw();
        glPopMatrix ();
        //...
        glPushMatrix ();
        glTranslatef (-100,0,-100);
        cilindro->draw();
        glPopMatrix ();

        glPushMatrix ();
        glTranslatef (0,100,0);
        glScalef(17,17,17);
        peon->draw();
        glPopMatrix ();
        /*
        dodge.estadodibujo=2;
        dodge.modo_alambre=true;
            glPushMatrix ();
            glScalef(4,4,4);
            dodge.draw();
           glPopMatrix ();
           */
      }
      if(modolin){
        printf("pintapiramide con alambre");
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        piramide->draw();
        cubo->draw();
        glPushMatrix ();
        glTranslatef (-100,0,100);
        // dibujar el primer objeto
        esfera->draw();
        glPopMatrix ();

        glPushMatrix ();
        glTranslatef (100,0,-100);
        cono->draw();
        glPopMatrix ();
        //...
        glPushMatrix ();
        glTranslatef (-100,0,-100);
        cilindro->draw();
        glPopMatrix ();

        glPushMatrix ();
        glTranslatef (0,100,0);
        glScalef(17,17,17);
        peon->draw();
        glPopMatrix ();
      }
      if(modovert){
          printf("pintapira con vertices");
          glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
          piramide->draw();
          cubo->draw();
          glPushMatrix ();
          glTranslatef (-100,0,100);
          // dibujar el primer objeto
          esfera->draw();
          glPopMatrix ();

          glPushMatrix ();
          glTranslatef (100,0,-100);
          cono->draw();
          glPopMatrix ();
          //...
          glPushMatrix ();
          glTranslatef (-100,0,-100);
          cilindro->draw();
          glPopMatrix ();

          glPushMatrix ();
          glTranslatef (0,100,0);
          glScalef(17,17,17);
          peon->draw();
          glPopMatrix ();
      }


}

//**************************************************************************
//
// función que se invoca cuando se pulsa una tecla
// Devuelve true si se ha pulsado la tecla para terminar el programa (Q),
// devuelve false en otro caso.
//
//**************************************************************************

bool Escena::teclaPulsada( unsigned char tecla, int x, int y )
{
   using namespace std ;
   cout << "Tecla pulsada: '" << tecla << "'" << endl;
   bool salir=false;
   switch( toupper(tecla) )
   {
      case 'Q' :
         if (modoMenu!=NADA)
            modoMenu=NADA;
         else {
            salir=true ;
         }
         break ;
      case 'O' :
         // ESTAMOS EN MODO SELECCION DE OBJETO
         modoMenu=SELOBJETO;
         break ;
      case 'C' :
          //Estamos si no esta creado creamos el objeto en memoria
          //una vez creado será necesario un mecanismo para ocultar la escena
          //adibujar="cubo";
        if(modoMenu==SELOBJETO){
             FiguraCubooPiramide=1;
             this->dibujar();
        }
        break;
      case 'P':
          //adibujar="piramide";
        if(modoMenu==SELOBJETO){
            FiguraCubooPiramide=2;

            this->dibujar();
        }
        break;

        case 'V' :
         // ESTAMOS EN MODO SELECCION DE MODO DE VISUALIZACION
         modoMenu=SELVISUALIZACION;
         break ;

         case 'S':
             //adibujar="piramide";
           if(modoMenu==SELVISUALIZACION){
              if(modoso){
                modoso=false;
              }
              else{
                modoso=true;
              }
               this->dibujar();
           }
           break ;
         // COMPLETAR con los diferentes opciones de teclado
         case 'L':

           if(modoMenu==SELVISUALIZACION){
              if(modolin){
                modolin=false;
              }
              else{
                modolin=true;
              }
               this->dibujar();
           }
           break ;

           case 'D':

             if(modoMenu==SELVISUALIZACION){
                if(modovert){
                  modovert=false;
                }
                else{
                  modovert=true;
                }
                 this->dibujar();
             }
             break ;
   }
   return salir;
}
//**************************************************************************

void Escena::teclaEspecial( int Tecla1, int x, int y )
{
   switch ( Tecla1 )
   {
	   case GLUT_KEY_LEFT:
         Observer_angle_y-- ;
         break;
	   case GLUT_KEY_RIGHT:
         Observer_angle_y++ ;
         break;
	   case GLUT_KEY_UP:
         Observer_angle_x-- ;
         break;
	   case GLUT_KEY_DOWN:
         Observer_angle_x++ ;
         break;
	   case GLUT_KEY_PAGE_UP:
         Observer_distance *=1.2 ;
         break;
	   case GLUT_KEY_PAGE_DOWN:
         Observer_distance /= 1.2 ;
         break;
	}

	//std::cout << Observer_distance << std::endl;
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//
// ratio_xy : relacción de aspecto del viewport ( == ancho(X) / alto(Y) )
//
//***************************************************************************

void Escena::change_projection( const float ratio_xy )
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   const float wx = float(Height)*ratio_xy ;
   glFrustum( -wx, wx, -Height, Height, Front_plane, Back_plane );
}
//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************

void Escena::redimensionar( int newWidth, int newHeight )
{
   Width  = newWidth/10;
   Height = newHeight/10;
   change_projection( float(newHeight)/float(newWidth) );
   glViewport( 0, 0, newWidth, newHeight );
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void Escena::change_observer()
{
   // posicion del observador
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef( 0.0, 0.0, -Observer_distance );
   glRotatef( Observer_angle_y, 0.0 ,1.0, 0.0 );
   glRotatef( Observer_angle_x, 1.0, 0.0, 0.0 );
}
