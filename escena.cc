

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
    piramide= new PiramidePentagonal(30.0,25.0);
    cubo = new Cubo(40.0);
    peon =new ObjRevolucion("./plys/peon.ply",10,100);
    tetraedro=new Tetraedro(70);
    jugador1=new Jugador();
    cilindro=new Cilindro(11,35,50,25);//num_vert_perfil ,const int num_instancias_perf ,const float altura ,const float radio

    //cilindro.draw();


    cono=new Cono(11,35,50,25);//( const int num_vert_perfil ,const int num_instancias_perf,const float altura ,const float radio )


    esfera=new Esfera(11,35,25);//( const int num_vert_perfil ,const int num_instancias_perf,const float altura ,const float radio )

    //LUCES Escena
    luzdire=new LuzDireccional(Tupla2f(0.0,0.0));
    luzposi=new LuzPosicional(Tupla3f(40.0f,40.0f,40.f));
    peon1 =new ObjRevolucion("./plys/peon.ply",10,25);

    Tupla4f ambiente_pearl(0.25,0.20725,0.20725, 1.0);
    Tupla4f especular_pearl(0.296648,0.296648, 0.296648, 1.0);
    Tupla4f difuso_pearl(	1, 0.829,0.829, 1.0);
    Tupla4f ambiente_esmerald(0.0215,0.1745,0.0215, 1.0);
    Tupla4f especular_esmerald(0.07568, 	0.61424, 0.07568, 1.0);
    Tupla4f difuso_esmerald(	0.633, 0.727811, 0.633, 1.0);
    Material  esmerald = Material(ambiente_esmerald,especular_esmerald,difuso_esmerald, 128.0*0.6);
    Material pearl = Material(ambiente_pearl,especular_pearl,difuso_pearl,0.088*128);
    Material negro (Tupla4f(0.04f,0.04f,0.04f,0.96f),Tupla4f(0.96f,0.96f,0.96f,0.96f),Tupla4f(0.04f,0.04f,0.04f,0.96f),128.f);
    Material blanco (Tupla4f(0.96f,0.96f,0.96f,0.96f),Tupla4f(0.04f,0.04f,0.04f,0.96f),Tupla4f(0.96f,0.96f,0.96f,0.96f),128.f);
    cilindro->setMaterial(negro);
    cubo->setMaterial(esmerald);
    peon1->setMaterial(pearl);
    peon->setMaterial(negro);
    piramide->setMaterial(negro);
    cono->setMaterial(pearl);

    incremento= Tupla4f(0.1f,0.1f,0.1f,0.1f);//Incremento de las luces posicionales examen

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
    glDisable(GL_LIGHTING);
    ejes.draw();


if(modoluces){
    glEnable( GL_LIGHTING );
    glEnable(GL_NORMALIZE);
    //luzdire->activar();
    glShadeModel(GL_SMOOTH);
    //
    //luzposi->activar();//creo que es porque las declaro como luces negras
    GLfloat lmodel_ambient[] = { 0, 0, 0, 1.0 }; //La pongo como luz negra y asi intento ver porque no funcionan mis luces
    //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
/*
    Tupla4f ambiente_pearl(0.25,0.20725,0.20725, 1.0);
    Tupla4f especular_pearl(0.296648,0.296648, 0.296648, 1.0);
    Tupla4f difuso_pearl(	1, 0.829,0.829, 1.0);
    Tupla4f ambiente_esmerald(0.0215,0.1745,0.0215, 1.0);
    Tupla4f especular_esmerald(0.07568, 	0.61424, 0.07568, 1.0);
    Tupla4f difuso_esmerald(	0.633, 0.727811, 0.633, 1.0);
    Material  esmerald = Material(ambiente_esmerald,especular_esmerald,difuso_esmerald, 128.0*0.6);
    Material pearl = Material(ambiente_pearl,especular_pearl,difuso_pearl,0.088*128);
    Material negro (Tupla4f(0.04f,0.04f,0.04f,0.96f),Tupla4f(0.96f,0.96f,0.96f,0.96f),Tupla4f(0.04f,0.04f,0.04f,0.96f),128.f);
    Material blanco (Tupla4f(0.96f,0.96f,0.96f,0.96f),Tupla4f(0.04f,0.04f,0.04f,0.96f),Tupla4f(0.96f,0.96f,0.96f,0.96f),128.f);
*///1.0f,1.0f,1.0f
    if(luzposi->encendida==true){
      luzposi->activar();

    }
    else{
        glDisable(luzposi->id);
    }

    if(luzdire->encendida==true){
      luzdire->activar();
    }
    else{
          glDisable(luzdire->id);
    }
    glPushMatrix ();

    glScalef(17,17,17);
    glTranslatef (1,1.4,0);
    peon1->draw();
    glPopMatrix ();

    glPushMatrix ();
    glTranslatef (0,0,50);
    glScalef(17,17,17);
    glTranslatef (1,1.4,0);
    peon->draw();
    glPopMatrix ();

    glPushMatrix ();
    glTranslatef (-50,0,0);
    piramide->draw();
    glPopMatrix ();

    glPushMatrix ();
    glTranslatef (-100,0,100);
    cubo->draw();
    glPopMatrix ();

    glPushMatrix ();
    glTranslatef (100,0,50);
    esfera->draw();
    glPopMatrix ();


    glPushMatrix ();
    glTranslatef (100,50,-100);
    cono->draw();
    glPopMatrix ();
    //...
    glPushMatrix ();
    glTranslatef (-100,50,-100);
    cilindro->draw();
    glPopMatrix ();


}
else{
      if(modoso){




        glPolygonMode(GL_FRONT,GL_FILL);
        //piramide->draw();
        jugador1->draw();
        /*
        tetraedro->draw();
        glPushMatrix ();
        glTranslatef (50,0,50);
        cubo->draw();
        glPopMatrix ();

        glPushMatrix ();
        glTranslatef (-100,0,100);
        // dibujar el primer objeto
        esfera->draw();
        glPopMatrix ();

        glPushMatrix ();
        glTranslatef (100,50,-100);
        cono->draw();
        glPopMatrix ();
        //...
        glPushMatrix ();
        glTranslatef (-100,50,-100);
        cilindro->draw();
        glPopMatrix ();

        glPushMatrix ();
        glTranslatef (0,100,0);
        glScalef(17,17,17);
        //dodge.draw();//peon->draw();
        glPopMatrix ();
      */

      }
      if(modolin){

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        //piramide->draw();
        jugador1->draw();
        /*
        tetraedro->draw();

        glPushMatrix ();
        glTranslatef (50,0,50);
        cubo->draw();
        glPopMatrix ();


        glPushMatrix ();
        glTranslatef (-100,0,100);
        // dibujar el primer objeto
        esfera->draw();
        glPopMatrix ();

        glPushMatrix ();
        glTranslatef (100,50,-100);
        cono->draw();
        glPopMatrix ();
        //...
        glPushMatrix ();
        glTranslatef (-100,50,-100);
        cilindro->draw();
        glPopMatrix ();

        glPushMatrix ();
        glTranslatef (0,100,0);
        glScalef(17,17,17);
        //peon->draw();
        //dodge.draw();
        glPopMatrix ();
        */
      }
      if(modovert){

          glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
          //piramide->draw();
          jugador1->draw();
          /*
          tetraedro->draw();
          glPushMatrix ();
          glTranslatef (50,0,50);
          cubo->draw();
          glPopMatrix ();
          glPushMatrix ();
          glTranslatef (-100,0,100);
          // dibujar el primer objeto
          esfera->draw();
          glPopMatrix ();

          glPushMatrix ();
          glTranslatef (100,50,-100);
          cono->draw();
          glPopMatrix ();
          //...
          glPushMatrix ();
          glTranslatef (-100,50,-100);
          cilindro->draw();
          glPopMatrix ();

          glPushMatrix ();
          glTranslatef (0,100,0);
          glScalef(17,17,17);
          //peon->draw();
          //dodge.draw();
          glPopMatrix ();
          */
      }
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

             this->dibujar();
        }
        break;


        case 'V' :
         // ESTAMOS EN MODO SELECCION DE MODO DE VISUALIZACION
         modoMenu=SELVISUALIZACION;
         break ;

         case 'P': //modo puntos

             if(modoMenu==SELVISUALIZACION){
               modoluces=false;
               glDisable ( GL_LIGHTING );
                if(modovert){
                  modovert=false;
                }
                else{
                  modovert=true;
                }
                 this->dibujar();
             }
             break ;
         case 'S'://modo solido
             //adibujar="piramide";
           if(modoMenu==SELVISUALIZACION){
             modoluces=false;
             glDisable ( GL_LIGHTING );
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
         case 'L'://modo lineas

           if(modoMenu==SELVISUALIZACION){
             modoluces=false;
             glDisable ( GL_LIGHTING );
              if(modolin){
                modolin=false;
              }
              else{
                modolin=true;
              }
               this->dibujar();
           }
           break ;

           case 'T': //modo luces

             if(modoMenu==SELVISUALIZACION){

                modoluces=true;
                this->dibujar();
             }
             break ;

             case '0': //modo luces

               if(modoMenu==SELVISUALIZACION&&modoluces==true){
                if(luzdire->encendida==false ){
                    luzdire->encendida=true;
                }

                else{
                  printf("desactivo");
                  luzdire->encendida=false;
                }
                  //ultimaselec=

               }
               break ;
            case '1': //modo luces

            if(modoMenu==SELVISUALIZACION&&modoluces==true){
             if(luzposi->encendida==false ){
               luzposi->encendida=true;
             }
             else{

               luzposi->encendida=false;
             }

               this->dibujar();
            }
                 break ;
            case '2': //modo luces

                   if(modoMenu==SELVISUALIZACION&&modoluces==true){
                      this->dibujar();
                   }
                   break ;

            case '3': //modo luces

              if(modoMenu==SELVISUALIZACION&&modoluces==true){
                        this->dibujar();
                     }
                     break ;
            case '4': //modo luces

                  if(modoMenu==SELVISUALIZACION&&modoluces==true){
                         this->dibujar();
                      }
                     break ;

             case '5': //modo luces

                  if(modoMenu==SELVISUALIZACION&&modoluces==true){
                            this->dibujar();
                      }
                      break ;
            case '6': //modo luces

                  if(modoMenu==SELVISUALIZACION&&modoluces==true){
                            this->dibujar();
                    }
                      break ;

           case '7': //modo luces

                  if(modoMenu==SELVISUALIZACION&&modoluces==true){
                                  this->dibujar();
                     }
                     break ;
            case 'A':
                if(modoMenu==SELVISUALIZACION&&modoluces==true){
                            angulo=ALPHA;
                   }
               break ;

            case 'B':
            if(modoMenu==SELVISUALIZACION&&modoluces==true){
                        angulo=BETA;
               }
            break;
            case '>':

                if(modoMenu==SELVISUALIZACION&&modoluces==true&&angulo==ALPHA){
                            luzdire->variarAnguloAlpha(20);

                              this->dibujar();

                   }
                if(modoMenu==SELVISUALIZACION&&modoluces==true&&angulo==BETA){

                                luzdire->variarAnguloBeta(20);
                                 this->dibujar();
                  }
                   break ;
            case '<':

                      if(modoMenu==SELVISUALIZACION&&modoluces==true&&angulo==ALPHA){
                                  luzdire->variarAnguloAlpha(-20);

                                    this->dibujar();
                         }
                      if(modoMenu==SELVISUALIZACION&&modoluces==true&&angulo==BETA){

                                      luzdire->variarAnguloBeta(-20);
                                       this->dibujar();
                        }


               break ;

            case 'M':
              if(modoMenu==SELVISUALIZACION&&modoluces==true){
                      luzposi->Incrementarluz(incremento);
              }

              break ;
            case 'N':
            if(modoMenu==SELVISUALIZACION&&modoluces==true){
                      luzposi->Incrementarluz(incremento*-1);
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
