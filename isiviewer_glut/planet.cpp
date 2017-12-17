#include <iostream>
#include <GL/gl.h>  // OpenGL include file
#include <GL/glut.h>

#include "planet.h"

using namespace std;

//TODO: remplacer tous les _orbit par _position

Planet::Planet(float _radius, float _distance, float _orbit, float _orbitSpeed) {
								radius = _radius;
								distance = _distance;
								orbit = _orbit;
								orbitSpeed = _orbitSpeed;
}

void Planet::traceLune() {
								glPushMatrix();
								glColor3ub(255, 255, 255);
								glRotatef(90.0, 1.0, 0.0, 0.0);
								glutWireTorus(0.001, distance, 100.0, 100.0);
								glPopMatrix();
}

void Planet::traceOrbite() {
								glPushMatrix();
								glColor3ub(255, 255, 255);
								glTranslatef(0.0, 0.0, 0.0);
								glRotatef(90.0, 1.0, 0.0, 0.0);
								glutWireTorus(0.001, this._distance, 100.0, 100.0);
								glPopMatrix();
}

void Planet::deplacementJour () {

								this._orbit += this._orbitSpeed;

								if (this._orbit > 360)
																this._orbit -= 360;
}
