

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

       Camara camara0(Tupla3f(0.0,300.0,700.0),Tupla3f(0.0,0.0,0.0), Tupla3f(0.0,1.0,0.0),
                      0, -50.0, 50.0, Front_plane, Back_plane, 50.0, -50.0);
       Camara camara1(Tupla3f(0.0,300.0,700.0),Tupla3f(0.0,0.0,0.0), Tupla3f(0.0,1.0,0.0),
                      1, -50.0, 50.0, Front_plane, Back_plane, 50.0, -50.0);
       Camara camara2(Tupla3f(0.0,450.0,-150.0),Tupla3f(0.0,300.0,0.0), Tupla3f(0.0,1.0,0.0),
                      0, -50.0, 50.0, Front_plane, Back_plane, 50.0, -50.0);

       camaras.push_back(camara0);
       camaras.push_back(camara1);
       camaras.push_back(camara2);

    ejes.changeAxisSize( 5000 );

    // crear los objetos de la escena....
    // .......completar: ...
    // .....
    piramide= new PiramidePentagonal(135.0,45.0);
    cubo = new Cubo(40.0);
    peon =new ObjRevolucion("./plys/peon.ply",10,100);
    tetraedro=new Tetraedro(70);
    jugador1=new Jugador();
    cilindro=new Cilindro(11,35,50,25);//num_vert_perfil ,const int num_instancias_perf ,const float altura ,const float radio
    cuadro= new Cuadro(50.0);
    //cilindro.draw();


    cono=new Cono(11,20,120,55);//( const int num_vert_perfil ,const int num_instancias_perf,const float altura ,const float radio )


    //esfera=new Esfera(11,35,25);//( const int num_vert_perfil ,const int num_instancias_perf,const float altura ,const float radio )

    //LUCES Escena
    luzdire=new LuzDireccional(Tupla2f(0.0,0.0));
    luzposi=new LuzPosicional(Tupla3f(40.0f,40.0f,40.f));
    //peon1 =new ObjRevolucion("./plys/peon.ply",10,100);

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
    //green rubber				.078125
    Material greenrub (Tupla4f(0.0,0.05,0.0,0.96f),Tupla4f(0.4,0.5,0.4,0.96f),Tupla4f(0.04,0.7,0.04,0.96f),0.078125);
    cilindro->setMaterial(negro);
    cubo->setMaterial(esmerald);
    //peon1->setMaterial(pearl);

    cuadro->setMaterial(greenrub);
    peon->setMaterial(negro);
    piramide->setMaterial(greenrub);
    cono->setMaterial(blanco);
    //piramide->setMaterial(pearl);
    cilindro->setTextura("./text-lata-1.jpg");
    cubo->setTextura("./text-lata-1.jpg");
    cuadro->setTextura("./textura-hierba-verde.jpg");
    //esfera->setTextura("./text-lata-1.jpg");
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


  if(animacion){
    jugador1->animacion();

  }
if(modoluces){
  if(!seleccion){
    glEnable( GL_LIGHTING );
  }

    GLfloat lmodel_ambient[] = { 0, 0, 0, 1.0 }; //La pongo como luz negra y asi intento ver porque no funcionan mis luces


    if(luzposi->encendida==true){
      luzposi->activar();
      if(animacion){
        AnimacionPuntual();

      }
    }
    else{
        glDisable(luzposi->id);
    }

    if(luzdire->encendida==true){
      luzdire->activar();
      if(animacion){
        AnimacioncolorDireccional();
      }
    }
    else{
          glDisable(luzdire->id);
    }
    glPushMatrix ();

    glTranslatef (-200,-80,-200);
    cubo->draw();
    glPopMatrix ();

    glPushMatrix ();

    glRotatef(-90,1,0,0);
    glScalef(25,25,1);
    glTranslatef(-25,-25,-80);

    cuadro->draw();
    //esfera->draw();
    glPopMatrix ();
    glPushMatrix ();
      glTranslatef (200,0,200);
      glScalef(60,60,60);
      peon->draw();
    glPopMatrix ();

    glPushMatrix ();
    glTranslatef (-200,-80,200);
    glRotatef(180,1.0,0.0,0.0);
    cono->draw();
    glPopMatrix ();
    glPushMatrix ();

    glTranslatef (200,-80,-200);
    piramide->draw();
    glPopMatrix ();
    ////jugador1->dibuja(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,Tupla3f(0.0,0.0,0.0),0,0,0);
    glPushMatrix ();
    glRotatef(180,0,1.0,0.0);
      jugador1->draw();
    glPopMatrix ();

    glPushMatrix ();

    glTranslatef (0,-30,-200);
    glScalef(10,10,10);
    beethoven.draw();
    glPopMatrix ();

}
else{
      if(modoso){




        glPolygonMode(GL_FRONT,GL_FILL);
        glPushMatrix ();

        glTranslatef (-200,-80,-200);
        cubo->draw();
        glPopMatrix ();

        glPushMatrix ();

        glRotatef(-90,1,0,0);
        glScalef(25,25,1);
        glTranslatef(-25,-25,-80);

        cuadro->draw();
        //esfera->draw();
        glPopMatrix ();
        glPushMatrix ();
          glTranslatef (200,0,200);
          glScalef(60,60,60);
          peon->draw();
        glPopMatrix ();

        glPushMatrix ();
        glTranslatef (-200,-80,200);
        glRotatef(180,1.0,0.0,0.0);
        cono->draw();
        glPopMatrix ();
        glPushMatrix ();

        glTranslatef (200,-80,-200);
        piramide->draw();
        glPopMatrix ();
        ////jugador1->dibuja(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,Tupla3f(0.0,0.0,0.0),0,0,0);
        glPushMatrix ();
        glRotatef(180,0,1.0,0.0);
          jugador1->draw();
        glPopMatrix ();

        glPushMatrix ();

        glTranslatef (0,-30,-200);
        glScalef(10,10,10);
        beethoven.draw();
        glPopMatrix ();

      }
      if(modolin){


        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glPushMatrix ();

        glTranslatef (-200,-80,-200);
        cubo->draw();
        glPopMatrix ();

        glPushMatrix ();

        glRotatef(-90,1,0,0);
        glScalef(25,25,1);
        glTranslatef(-25,-25,-80);

        cuadro->draw();
        //esfera->draw();
        glPopMatrix ();
        glPushMatrix ();
          glTranslatef (200,0,200);
          glScalef(60,60,60);
          peon->draw();
        glPopMatrix ();

        glPushMatrix ();
        glTranslatef (-200,-80,200);
        glRotatef(180,1.0,0.0,0.0);
        cono->draw();
        glPopMatrix ();
        glPushMatrix ();

        glTranslatef (200,-80,-200);
        piramide->draw();
        glPopMatrix ();
        ////jugador1->dibuja(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,Tupla3f(0.0,0.0,0.0),0,0,0);
        glPushMatrix ();
        glRotatef(180,0,1.0,0.0);
          jugador1->draw();
        glPopMatrix ();

        glPushMatrix ();

        glTranslatef (0,-30,-200);
        glScalef(10,10,10);
        beethoven.draw();
        glPopMatrix ();

      }
      if(modovert){

          glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
          glPushMatrix ();

          glTranslatef (-200,-80,-200);
          cubo->draw();
          glPopMatrix ();

          glPushMatrix ();

          glRotatef(-90,1,0,0);
          glScalef(25,25,1);
          glTranslatef(-25,-25,-80);

          cuadro->draw();
          //esfera->draw();
          glPopMatrix ();
          glPushMatrix ();
            glTranslatef (200,0,200);
            glScalef(60,60,60);
            peon->draw();
          glPopMatrix ();

          glPushMatrix ();
          glTranslatef (-200,-80,200);
          glRotatef(180,1.0,0.0,0.0);
          cono->draw();
          glPopMatrix ();
          glPushMatrix ();

          glTranslatef (200,-80,-200);
          piramide->draw();
          glPopMatrix ();
          ////jugador1->dibuja(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,Tupla3f(0.0,0.0,0.0),0,0,0);
          glPushMatrix ();
          glRotatef(180,0,1.0,0.0);
            jugador1->draw();
          glPopMatrix ();

          glPushMatrix ();

          glTranslatef (0,-30,-200);
          glScalef(10,10,10);
          beethoven.draw();
          glPopMatrix ();
      }
    }
    glPushMatrix ();
      glTranslatef (200,0,200);
      glScalef(60,60,60);
      peon->drawespecial();
    glPopMatrix ();

    glPushMatrix ();
    glTranslatef (-200,-80,200);
    glRotatef(180,1.0,0.0,0.0);
    cono->drawespecial();
    glPopMatrix ();
    glPushMatrix ();

    glTranslatef (200,-80,-200);
    piramide->drawespecial();
    glPopMatrix ();
    glPolygonMode(GL_FRONT,GL_FILL);
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
        modoMenu=CAMARA;
       cout << "Seleccione la camara que quiere ver" << endl;
       cout << "0: Camara perspectiva" << endl;
       cout << "1: Camara ortogonal" << endl;
       cout << "2: Camara perspectiva 2" << endl;
       cout << "Q: salir" << endl;
       cout << endl;
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

           }
           break ;

           case 'T': //modo luces

             if(modoMenu==SELVISUALIZACION){

                modoluces=true;

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
               if( modoMenu == CAMARA){
              camaraActiva = 0;
              change_projection(1.0);
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


            }
              if( modoMenu == CAMARA){
                camaraActiva = 1;
                change_projection(1.0);
              }
                 break ;
            case '2': //modo luces

                   if(modoMenu==SELVISUALIZACION&&modoluces==true){
                      this->dibujar();
                   }
                   if( modoMenu == CAMARA){
                  camaraActiva = 2;
                  change_projection(1.0);
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
              animacion=false;
              jugador1->resetJugador();
                if(!animacion){
                  modoMenu=SELGRADOLIB;
                }

              break ;
            case '7':

                  if(modoMenu==SELGRADOLIB&&animacion==false){
                            gradolib=0;
                        }
                    break ;
            case '8':

                  if(modoMenu==SELGRADOLIB&&animacion==false){
                            gradolib=1;
                            }
                            break ;
           case '9':

            if(modoMenu==SELGRADOLIB&&animacion==false){
                          gradolib=2;
                      }
                        break ;
          case 'N':
            if(animacion==true){
              jugador1->resetJugador();
                  animacion=false;

            }
            else{
              animacion=true;
              }

              break ;

              case '+':

                  if(animacion){

                      jugador1->setincremento(0.2);

                     }
                     else{
                       if(modoMenu==SELGRADOLIB)
                        jugador1->setgradolibertad(gradolib,5);
                     }
                     break ;
              case '-':

                    if(animacion){

                        jugador1->setincremento(-0.2);

                    }
                    else{
                        if(modoMenu==SELGRADOLIB)
                            jugador1->setgradolibertad(gradolib,-5);
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
	   /*case GLUT_KEY_LEFT:
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
         */
         case GLUT_KEY_LEFT:
          camaras[camaraActiva].rotarYExaminar(-3.0*M_PI/180.0);
          break;
 	   case GLUT_KEY_RIGHT:
          camaras[camaraActiva].rotarYExaminar(3.0*M_PI/180.0);
          break;
 	   case GLUT_KEY_UP:
          camaras[camaraActiva].rotarXExaminar(3.0*M_PI/180.0);
          break;
 	   case GLUT_KEY_DOWN:
          camaras[camaraActiva].rotarXExaminar(-3.0*M_PI/180.0);
          break;
 	   case GLUT_KEY_F1:
          camaras[camaraActiva].zoom(1/1.2);
          change_projection(1.0);
          break;
 	   case GLUT_KEY_F2:
          camaras[camaraActiva].zoom(1.2);
          change_projection(1.0);
          break;
    case GLUT_KEY_PAGE_UP:
         camaras[camaraActiva].zoom(1/1.2);
        change_projection(1.0);
        break;
    case GLUT_KEY_PAGE_DOWN:
        camaras[camaraActiva].zoom(1.2);
        change_projection(1.0);
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
   camaras[camaraActiva].setProjection();
}
//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************

void Escena::redimensionar( int newWidth, int newHeight )
{
   Width  = newWidth/10;
   Height = newHeight/10;
   for(int i = 0; i < camaras.size(); i++){
      camaras[i].setLetf(camaras[i].getBottom()*Width/Height);
      camaras[i].setRight(camaras[i].getTop()*Width/Height);
   }
   change_projection( float(newHeight)/float(newWidth) );
   glViewport( 0, 0, newWidth, newHeight );
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************
void Escena::AnimacionPuntual(){

  float desplazamientox=sin(angulopunt)*70;
  float desplazamientoz=cos(angulopunt)*70;
  Tupla3f posi(desplazamientox,0.0f,desplazamientoz);
  luzposi->CambiarPosicion(posi);
  angulopunt+=10;
}
void Escena::AnimacioncolorDireccional(){
  float randomr=rand()%10/10.0f;
  float randomg=rand()%10/10.0f;
  float randomb=rand()%10/10.0f;

  Tupla4f luz(randomr,randomg,randomb,1.0f);
  luzdire->variarColor(luz);

}
void Escena::change_observer()
{
   // posicion del observador
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   camaras[camaraActiva].setObserver();
}


void Escena::ratonMovido(int x, int y){
   if(ratonPulsado){
      /*if(camaras[camaraActiva].getSeleccionado() == NOSEL){
         camaras[camaraActiva].girar(x-x_ant, y-y_ant);
      } else {
        camaras[camaraActiva].rotarXExaminar(-0.25*(y-y_ant)*M_PI/180.0);
        camaras[camaraActiva].rotarYExaminar(-0.25*(x-x_ant)*M_PI/180.0);
      }*/
      camaras[camaraActiva].rotarXExaminar(-0.25*(y-y_ant)*M_PI/180.0);
      camaras[camaraActiva].rotarYExaminar(-0.25*(x-x_ant)*M_PI/180.0);
      x_ant = x;
      y_ant = y;
   }
}

void Escena::clickRaton(int boton, int status, int x, int y){
   if(boton == GLUT_RIGHT_BUTTON){
      //Mover primera persona
      if(status == GLUT_DOWN){
         x_ant = x;
         y_ant = y;
         ratonPulsado = true;
      } else {
         ratonPulsado = false;
      }
   } else if (boton == GLUT_LEFT_BUTTON){
      //Seleccionar objeto
      if(status == GLUT_DOWN){
         //dibujar_seleccion();
         dibujar_seleccion(x,y);
      }
   } else if (boton == 3){
      camaras[camaraActiva].zoom(1.2);
      change_projection(1.0);
   } else if (boton == 4){
      camaras[camaraActiva].zoom(1/1.2);
      change_projection(1.0);
   }
}


void Escena::dibujar_seleccion(int x, int y){
  bool luz_activada=false;
  bool textura_activada=false;
  bool dither_activado=false;

  if(glIsEnabled(GL_LIGHTING)){
     glDisable(GL_LIGHTING);
     luz_activada=true;
  }

  if(glIsEnabled(GL_TEXTURE_2D)){
     glDisable(GL_TEXTURE_2D);
    textura_activada=true;

  }

  if(glIsEnabled(GL_DITHER)){
     glDisable(GL_DITHER);
     dither_activado=true;
  }
    seleccion=true;
    dibujar();
    seleccion=false;
   GLint viewport[4];
   //glColor3ub pixel[3];
   GLfloat pixel[3];
   glGetIntegerv(GL_VIEWPORT,viewport);
   glReadPixels(x,viewport[3]-y,1,1,GL_RGB,GL_FLOAT,pixel);
  // seleccionables objetoadibujar=NOSEL;


  Tupla3f color = {pixel[0],pixel[1],pixel[2]};
   printf("Color obtenido \n");

     printf("%f  ,",color[0]);
     printf("%f ,",color[1]);
     printf("%f \n",color[2]);
     float epsilon =0.001;
   if((color(0) >= 0.400000-epsilon&&color(0) <= 0.400000+epsilon) && (color(1) >= 0.000000-epsilon&&color(1) <= 0.000000+epsilon) && (color(2) >= 0.400000-epsilon&&color(2) <= 0.400000+epsilon)){
      printf("Cono \n");//0.498039  ,0.000000 ,0.498039
      camaras[camaraActiva].setSeleccionado(CONO);
      camaras[camaraActiva].mover(-200,-80,200);
    //  objetoadibujar=CONO;
   } else if(color(0) == 0.0 && color(1) == 0.0 && color(2) == 0.0){
      printf("Peon \n");
      camaras[camaraActiva].setSeleccionado(PEON);
      camaras[camaraActiva].mover(200,0,200);

      //objetoadibujar=PEON;
   } else if(color(0) == 0.0 && color(1) == 1.0 && color(2) == 1.0){
      printf("Piramde \n");
      camaras[camaraActiva].setSeleccionado(PIRAMIDE);
      camaras[camaraActiva].mover(200,-80,-200);
      //objetoadibujar=PIRAMIDE;glTranslatef (;
   } else {
      camaras[camaraActiva].setSeleccionado(NOSEL);
      camaras[camaraActiva].mover(0.0,0.0,0.0);
      //camaras[camaraActiva].mover(-300.0,50.0,-500.0); a por defecto
      //objetoadibujar=NOSEL;
   }
   //OBTENIDO EL OBJETO SELECCIONADO Y CENTRADA LA CAMARA
   change_observer();
   GLint polygonMode[2];
   glGetIntegerv(GL_POLYGON_MODE,polygonMode);
   Material negro (Tupla4f(0.04f,0.04f,0.04f,0.96f),Tupla4f(0.96f,0.96f,0.96f,0.96f),Tupla4f(0.04f,0.04f,0.04f,0.96f),128.f);
   Material blanco (Tupla4f(0.96f,0.96f,0.96f,0.96f),Tupla4f(0.04f,0.04f,0.04f,0.96f),Tupla4f(0.96f,0.96f,0.96f,0.96f),128.f);
   Material greenrub (Tupla4f(0.0,0.05,0.0,0.96f),Tupla4f(0.4,0.5,0.4,0.96f),Tupla4f(0.04,0.7,0.04,0.96f),0.078125);

  Material oro ({0.24725, 0.1995, 0.0745, 1}, {0.75164, 0.60648, 0.22648, 1}, {0.628281, 0.555802, 0.366065, 1}, 0.4*128.0f);

   glPushMatrix();



         glPushMatrix();
         //ITEM A DIBUJAR
         if(camaras[camaraActiva].getSeleccionado()==CONO){
           peon->setMaterial(negro);
           piramide->setMaterial(greenrub);
           cono->setMaterial(oro);

          cono->setselec(true);
          peon->setselec(false);
          piramide->setselec(false);
          glTranslatef (-200,-80,200);
          glRotatef(180,1.0,0.0,0.0);
          cono->draw();


          printf("Co \n");
         }
         glPopMatrix();


           glPushMatrix();
             if(camaras[camaraActiva].getSeleccionado()==PIRAMIDE){
           //ITEM A DIBUJAR
           peon->setMaterial(negro);
           piramide->setMaterial(oro);
           cono->setMaterial(blanco);
           peon->setselec(false);

           cono->setselec(false);
           piramide->setselec(true);
           glTranslatef (200,-80,-200);
           piramide->draw();

           printf("Co \n");
           }
           glPopMatrix();


             glPushMatrix();
              if(camaras[camaraActiva].getSeleccionado()==PEON){
             //ITEM A DIBUJAR
             peon->setMaterial(oro);
             piramide->setMaterial(greenrub);
             cono->setMaterial(blanco);
             piramide->setselec(false);
             cono->setselec(false);
             peon->setselec(true);
             glTranslatef (200,0,200);
             glScalef(60,60,60);

             peon->draw();
            //  peon->setselec(false);
              printf("Co \n");
             }
             if(camaras[camaraActiva].getSeleccionado()==NOSEL){
              peon->setselec(false);
              piramide->setselec(false);
              cono->setselec(false);
              peon->setMaterial(negro);
              piramide->setMaterial(greenrub);
              cono->setMaterial(blanco);
             }
             glPopMatrix();


   glPopMatrix();
   /*
   if(!glIsEnabled(GL_LIGHTING)&&luz_activada){
      glEnable(GL_LIGHTING);
   }
   */
   glPolygonMode(polygonMode[1],polygonMode[0]);

   if(!glIsEnabled(GL_TEXTURE_2D&&textura_activada)){
      glEnable(GL_TEXTURE_2D);
   }

   if(glIsEnabled(GL_DITHER)&&dither_activado){
      glEnable(GL_DITHER);
   }
}
