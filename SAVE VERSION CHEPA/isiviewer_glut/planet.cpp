#include <iostream>
#include <GL/gl.h>  // OpenGL include file
#include <GL/glut.h>

#include "planet.h"

using namespace std;

//TODO: remplacer tous les _orbit par _position

Planet::Planet(double radius, double distance, double orbit, double orbitSpeed) {
								this->m_radius = radius;
								this->m_distance = distance;
								this->m_orbit = orbit;
								this->m_orbitSpeed = orbitSpeed;
}

void Planet::traceLune() {
								glPushMatrix();
								glColor3ub(255, 255, 255);
								glRotatef(90.0, 1.0, 0.0, 0.0);
								glutWireTorus(0.001, this->m_distance, 100.0, 100);
								glPopMatrix();
}

void Planet::traceOrbite(void) {

								glPushMatrix();
								glColor3ub(255, 255, 255);
								glTranslatef(0.0, 0.0, 0.0);
								glRotatef(90.0, 0.0, 0.0, 1.0);
								glutWireTorus(0.001, this->m_distance, 100.0, 100);
								glPopMatrix();


								// GLfloat x=0;
								// GLfloat y=0;
								// glColor3d(255,255,255);
								// int i;
								// int lineAmount = 100;   //# of triangles used to draw circle
								//
								// //GLfloat radius = 2.0f;   //radius
								// GLfloat twicePi = 2.0f * M_PI;
								//
								// glBegin(GL_LINE_LOOP);
								// for(i = 0; i <= lineAmount; i++) {
								//         glVertex2f(
								//                 x + (radius * cos(i * twicePi / lineAmount)),
								//                 y + (radius * sin(i * twicePi / lineAmount))
								//                 );
								// }
								// glEnd();
								//

}

void Planet::deplacementJour () {

								this->m_orbit += this->m_orbitSpeed;

								if (this->m_orbit > 360)
																this->m_orbit -= 360;
}
