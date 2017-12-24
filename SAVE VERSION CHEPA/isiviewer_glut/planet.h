#ifndef PLANETE_H
#define PLANETE_H

#include <iostream>
#include <GL/gl.h>  // OpenGL include file
#include <GL/glut.h>
#include <math.h>

class Planet {

public:

//FIXME: remplacer tous les variables par _radius par m_radius
/* variables de classes */
float m_radius;
float m_distance;
float m_orbit;
float m_orbitSpeed;


// constructeur
Planet(double radius, double distance, double orbit, double orbitSpeed);


void traceOrbite(void);
void deplacementJour();

// sera utilité seulement pour la Terre
void traceLune();

};

#endif
