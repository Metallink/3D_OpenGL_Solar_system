#ifndef PLANETE_H
#define PLANETE_H

#include <iostream>
#include <GL/gl.h>  // OpenGL include file
#include <GL/glut.h>

class Planet {

public:

//FIXME: remplacer tous les variables par _radius par m_radius
/* variables de classes */
float _radius;
float _distance;
float _orbit;
float _orbitSpeed;


// constructeur
Planet(float _radius, float _distance, float _orbit, float _orbitSpeed);


void traceOrbite();
void deplacementJour();

// sera utilité seulement pour la Terre
void traceLune();

};

#endif
