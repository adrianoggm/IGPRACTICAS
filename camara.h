class Camara {

Tupla3f eye ;
Tupla3f at ;
Tupla3f up ;
int tipo ; // ORTOGONAL o Perspectiva
float left , right , near , far ; // o bien aspect, fov, near, far;
Camara ( ... ) ; // con los parametros necesarios
rotarXExaminar ( float angle );
rotarYExaminar ( float angle );
rotarZExaminar ( float angle );
rotarXFirstPerson ( float angle );
rotarYFirstPerson ( float angle );
rotarYFirstPerson ( float angle );
mover ( float x, float y, float z );
zoom ( float factor );
setObserver () { gluLookAt ( ..... ) }; // completar
setProyeccion ();

}
