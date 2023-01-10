Tan solo es necesario posicionarse en el directorio de esta carpeta en terminal y ejecutar el comando make
que por defecto cogerá el makefile de esta carpeta.

En cuanto a la ejecución debdo a que mi ordenador y algunas prácticas recomedaban las teclas
de un modo u otro. La configuración del panel de control queda como a continuación.

MODOS VISTA    TECLA V 

	MODO SOLIDO TECLA S
	MODO LINEAS TECLA L
	MODO PUNTOS TECLA P
	MODO LUCES  TECLA T
		
		DENTRO MODO LUCES 
		LUZ POSICIONAL TECLA 0
		LUZ DIRECCIONAL TECLA 1 
		2 3 4 5 6  ESTAN RESERVADAS POR SI QUEREMOS AÑADIR MAS LUCES
	 		MODIFICAR ALFA TECLA A 
	 		MODIFICAR BETA TECLA B
	 		 
	 		 USAR > O < SI QUEREMOS AUMENTAR O DISMINUIR EL ÁNGULO

MODO SELGRADO DE LIBERTAD TECLA M //RESETEA AL JUGADOR A LA POSICION INICIAL Y LE PERMITE ELEGIR ENTRE TRES GRADOS DE LIBERTAD (La implementación del muñeco es capaz de aceptar un numero de 26 grados de libertad ej:jugador1->dibuja(-90,-10,0,0,-15, //5
      45,0,-25,0,-15,  //5
      0,0,0,0,0,0,	//6
      0,10,56,30,0,50,Tupla3f (0,0,0), //7
      0,0,0) //3 pero por simplicidad he cogido los a mi parecer más importantes.
    
   	GRADO LIBERTAD 0 brazo izq del muñeco ejex  TECLA 7  
   	GRADO LIBERTAD 1 pierna dch del muñeco rotoz TECLA 8
   	GRADO LIBERTAD 2 balon desplazamiento en z   TECLA 9 
   	
   	TECLAS + - despues de pulsar 7-8-9 para incrementar o decrementar los valores del angulo o en caso de 9 desplazamiento.
   	
   	
MODO ANIMACION TECLA N COMIENZA LA ANIMACIÓN DE LA ESCENA CON LA ANIMACIÓN DEL JUGADOR LUZ POSICIONAL Y LUZ DIRECCIONAL.
	
	TECLAS + - INCREMENTA O DECREMENTAN LA VELOCIDAD DE LA ANIMACIÓN.
	


