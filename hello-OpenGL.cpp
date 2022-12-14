// First Program in OpenGL
// Compile with:
// g++ hello-OpenGL.cpp -o hello-opengl -lglut -lGLU -lGL

#include <GL/glut.h>
#include <math.h>
using namespace std;
float vertices[25] = {1,2,100,20,
				  100,200,50,10,
				  300,300,10,10,
				  200,300,250,50,
				  350,350,100,300
};
// (or others, depending on the system in use)
void init (void){
    glClearColor (1.0, 1.0, 1.0, 0.0);    // Set display-window color to white.
    glMatrixMode (GL_PROJECTION);         // Set projection parameters.
    gluOrtho2D (0.0, 400.0, 0.0, 400.0);  //coordinate limits for the picture we want to display.
}


void lineSegment (void){
    glClear (GL_COLOR_BUFFER_BIT);        // Clear display window.

    glColor3f (0.0, 0.4, 0.2);            // Set line segment color to green.
    glBegin (GL_LINES);
      glVertex2i (180, 15);                 // Specify line-segment geometry.
      glVertex2i (10, 145);
    glEnd ( );
    glFlush ( );                    // Process all OpenGL routines as quickly as possible.
}


void points (void) {
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.4, 0.2);
    glBegin (GL_POINTS);
    
    int place = 0;
    for(int times = 0; times < 5; times++){
    	  	
    	float p1x = vertices[place];
    	place++;
    	float p1y = vertices[place];
    	place++;
    	float p2x = vertices[place];
    	place++;
    	float p2y = vertices[place];
    	place++;
    	
    	if ((p1x < p2x) && (p1y < p2y)){
    		float aux;
    		aux = p1x;
    		p1x = p2x;
    		p2x = aux;
    		
    		aux = p1y;
    		p1y = p2y;
    		p2y = aux;   		
    	}
    	
    	float dx = p2x - p1x;
    	float dy = p2y - p1y;
    	
    	int step;
    	if (dx >= dy){
    		step = abs(dx);
    	}
    	else{
    		step = abs(dy);
    	}
    	
    	float x = p1x;
    	float y = p1y;
    	dx = dx / step;
    	dy = dy / step;
    	
    	for (int i = 0; i < step; i++){
    		x += dx;
    		y += dy;
    		glVertex2i (x, y);
    	}  	
    }    
    
    glEnd ();
    glFlush();
}

int main (int argc, char** argv)
{
    glutInit (&argc, argv);    // Initialize GLUT.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);    // Set display mode.
    glutInitWindowPosition (50, 100);    // Set top-left display-window position.
    glutInitWindowSize (400, 400);    // Set display-window width and height.
    glutCreateWindow ("An Example OpenGL Program"); // Create display window.
    init (); // Execute initialization procedure.
    //glutDisplayFunc(lineSegment);    // Send graphics to display window.
    glutDisplayFunc (points);
    glutMainLoop ( );    // Display everything and wait.
    return 0;
}
