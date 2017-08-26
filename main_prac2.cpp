//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Gonzalez Vicente Juan Carlos		******//
//*************		Visual Studio Community 2017		******//
//*************				Version	15.3.2				******//
//************************************************************//
#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar

	glBegin(GL_TRIANGLES);

		glColor3f(1.0, 1.0, 0.0);
		glVertex3f(0, 13, -1.2f);
		glColor3f(0.0, 1.0, 1.0);
		glVertex3f(-2, 6.8, -1.2f);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0, 6, -1.2f);

	glEnd();

	glBegin(GL_TRIANGLES);

		glColor3f(0.5, 1.0, 0.0);
		glVertex3f(-6.8, 8.2, -1.2f);
		glColor3f(0.0, 0.3, 0.0);
		glVertex3f(0, 6, -1.2f);
		glColor3f(0.0, 0.0, 0.5);
		glVertex3f(0, 8.2, -1.2f);

	glEnd();

	glBegin(GL_TRIANGLES);

		glColor3f(0.1, 0.0, 0.5);
		glVertex3f(-6.8, 8.2, -1.2f);
		glColor3f(0.8, 0.3, 0.5);
		glVertex3f(-1.2, 4.2, -1.2f);
		glColor3f(0.0, 0.5, 0.8);
		glVertex3f(0, 6, -1.2f);

	glEnd();

	glBegin(GL_TRIANGLES);

		glColor3f(0.0, 0.9, 0.9);
		glVertex3f(-2, 6.8, -1.2f);
		glColor3f(0.1, 0.1, 0.1);
		glVertex3f(-4.2, 0.2, -1.2f);
		glColor3f(0.5, 0.5, 0.5);
		glVertex3f(0, 6, -1.2f);

	glEnd();

	glBegin(GL_TRIANGLES);
	
		glColor3f(0.4, 0.6, 0.5);
		glVertex3f(-4.2, 0.2, -1.2f);
		glColor3f(0.2, 0.5, 0.8);
		glVertex3f(1.2, 4.2, -1.2f);
		glColor3f(0.3, 0.3, 0.4);
		glVertex3f(0, 6, -1.2f);
	
	glEnd();

	// Espejo

	glBegin(GL_TRIANGLES);

	glColor3f(0.2, 0.2, 0.5);
	glVertex3f(0, 13, -1.2f);
	glColor3f(0.4, 0.7, 0.9);
	glVertex3f(2, 6.8, -1.2f);
	glColor3f(0.4, 0.5, 0.1);
	glVertex3f(0, 6, -1.2f);

	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(6.8, 8.2, -1.2f);
	glColor3f(0.9, 0.4, 0.4);
	glVertex3f(0, 6, -1.2f);
	glColor3f(0.2, 0.1, 0.5);
	glVertex3f(0, 8.2, -1.2f);

	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(0.9, 0.9, 0.5);
	glVertex3f(6.8, 8.2, -1.2f);
	glColor3f(0.7, 0.7, 0.5);
	glVertex3f(1.2, 4.2, -1.2f);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(0, 6, -1.2f);

	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(2, 6.8, -1.2f);
	glColor3f(0.9, 0.1, 0.9);
	glVertex3f(4.2, 0.2, -1.2f);
	glColor3f(0.3, 0.3, 0.4);
	glVertex3f(0, 6, -1.2f);

	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(0.3, 0.3, 0.5);
	glVertex3f(4.2, 0.2, -1.2f);
	glColor3f(0.9, 0.3, 0.3);
	glVertex3f(-1.2, 4.2, -1.2f);
	glColor3f(0.1, 0.9, 0.1);
	glVertex3f(0, 6, -1.2f);

	glEnd();

	// Nombre

	// J
	
	glBegin(GL_POLYGON);

	glColor3f(0.1, 0.0, 0.5);
	glVertex3f(-14, -1, -1.2f);
	glColor3f(0.5, 0.0, 0.5);
	glVertex3f(-14, -3, -1.2f);
	glColor3f(0.4, 0.0, 0.5);
	glVertex3f(-8, -3, -1.2f);
	glColor3f(0.9, 0.0, 0.5);
	glVertex3f(-8, -1, -1.2f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.0, 0.5);
	glVertex3f(-12, -3, -1.2f);
	glColor3f(0.0, 0.1, 0.5);
	glVertex3f(-12, -7, -1.2f);
	glColor3f(0.5, 0.0, 0.5);
	glVertex3f(-10, -7, -1.2f);
	glColor3f(0.0, 0.9, 0.5);
	glVertex3f(-10, -3, -1.2f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.1, 0.1, 0.5);
	glVertex3f(-14, -7, -1.2f);
	glColor3f(0.6, 0.6, 0.5);
	glVertex3f(-14, -9, -1.2f);
	glColor3f(0.5, 0.0, 0.5);
	glVertex3f(-10, -9, -1.2f);
	glColor3f(0.2, 0.2, 0.5);
	glVertex3f(-10, -7, -1.2f);

	glEnd();

	// C

	glBegin(GL_POLYGON);

	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-7, -1, -1.2f);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-5, -3, -1.2f);
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(-2, -3, -1.2f);
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(-2, -1, -1.2f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-7, -1, -1.2f);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-7, -9, -1.2f);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-5, -7, -1.2f);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-5, -3, -1.2f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-7, -9, -1.2f);
	glColor3f(0.1, 0.2, 0.2);
	glVertex3f(-5, -7, -1.2f);
	glColor3f(0.2, 0.2, 0.1);
	glVertex3f(-2, -7, -1.2f);
	glColor3f(0.2, 0.1, 0.2);
	glVertex3f(-2, -9, -1.2f);

	glEnd();

	// G

	glBegin(GL_POLYGON);

	glColor3f(0.1, 0.2, 0.3);
	glVertex3f(-1, -1, -1.2f);
	glColor3f(0.4, 0.5, 0.6);
	glVertex3f(1, -3, -1.2f);
	glColor3f(0.7, 0.8, 0.9);
	glVertex3f(6, -3, -1.2f);
	glColor3f(0.9, 0.8, 0.7);
	glVertex3f(6, -1, -1.2f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.6, 0.5, 0.4);
	glVertex3f(-1, -1, -1.2f);
	glColor3f(0.3, 0.2, 0.1);
	glVertex3f(-1, -9, -1.2f);
	glColor3f(0.2, 0.4, 0.6);
	glVertex3f(1, -7, -1.2f);
	glColor3f(0.8, 0.6, 0.4);
	glVertex3f(1, -3, -1.2f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.3, 0.6, 0.9);
	glVertex3f(-1, -9, -1.2f);
	glColor3f(0.9, 0.6, 0.3);
	glVertex3f(6, -9, -1.2f);
	glColor3f(0.4, 0.8, 0.4);
	glVertex3f(4, -7, -1.2f);
	glColor3f(0.5, 0.0, 0.5);
	glVertex3f(1, -7, -1.2f);

	glEnd();

	glBegin(GL_POLYGON);
	
	glColor3f(0.1, 0.2, 0.2);
	glVertex3f(6, -9, -1.2f);
	glColor3f(0.2, 0.2, 0.1);
	glVertex3f(4, -7, -1.2f);
	glColor3f(0.1, 0.2, 0.1);
	glVertex3f(4, -6, -1.2f);
	glColor3f(0.3, 0.2, 0.2);
	glVertex3f(6, -4, -1.2f);
	
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.1, 0.6, 0.6);
	glVertex3f(4, -6, -1.2f);
	glColor3f(0.6, 0.6, 0.1);
	glVertex3f(6, -4, -1.2f);
	glColor3f(0.1, 0.6, 0.1);
	glVertex3f(2, -4, -1.2f);
	glColor3f(0.7, 0.6, 0.6);
	glVertex3f(2, -6, -1.2f);

	glEnd();

	// V

	glBegin(GL_POLYGON);

	glColor3f(0.9, 0.1, 0.1);
	glVertex3f(7, -1, -1.2f);
	glColor3f(0.9, 0.2, 0.2);
	glVertex3f(9, -1, -1.2f);
	glColor3f(0.9, 0.3, 0.3);
	glVertex3f(10.5, -6.1, -1.2f);
	glColor3f(0.9, 0.4, 0.4);
	glVertex3f(9.5, -9, -1.2f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.9, 0.5, 0.5);
	glVertex3f(10.5, -6.1, -1.2f);
	glColor3f(0.9, 0.6, 0.6);
	glVertex3f(9.5, -9, -1.2f);
	glColor3f(0.9, 0.7, 0.7);
	glVertex3f(11.5, -9, -1.2f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.9, 0.8, 0.8);
	glVertex3f(10.5, -6.1, -1.2f);
	glColor3f(0.8, 0.1, 0.1);
	glVertex3f(11.5, -9, -1.2f);
	glColor3f(0.8, 0.2, 0.2);
	glVertex3f(14, -1, -1.2f);
	glColor3f(0.8, 0.3, 0.3);
	glVertex3f(12, -1, -1.2f);
	
	glEnd();

	glFlush();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
	if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(-15,15,-15,15,0.1,2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

