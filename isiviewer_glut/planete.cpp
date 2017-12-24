#include "planete.h"

#include <math.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

Planete::Planete(double radius, double distance, double orbit, double orbitSpeed, double axisTilt, double axisAni) {
        m_radius = radius;
        m_distance = distance;
        m_orbit = orbit;
        m_orbitSpeed = orbitSpeed;
        m_axisTilt = axisTilt;
        m_axisAni = axisAni;
}

Planete::~Planete() {
}

void Planete::dessinerOrbite () {
        // // glPushMatrix();
        // // glColor3d(255,255,255);
        // // // glColor3ub(255, 255, 255);
        // // glRotatef(90.0, 1.0, 0.0, 0.0);
        // // glutWireTorus(0.001, this->m_distance, 100.0, 100.0);
        // // glPopMatrix();
        //
        // glColor3d(255,0,0);
        // int i;
        // int lineAmount = 100;   //# of triangles used to draw circle
        //
        // GLfloat radius = m_dis;   //radius
        // GLfloat twicePi = 2.0f * M_PI;
        //
        // glBegin(GL_LINE_LOOP);
        // for(i = 0; i <= lineAmount; i++) {
        //         glVertex2f(
        //                 x + (radius * cos(i *  twicePi / lineAmount)),
        //                 y + (radius* sin(i * twicePi / lineAmount))
        //                 );
        // }
        // glEnd();
        // GLfloat x;
        // GLfloat y;
}

void Planete::drawMoon() {
        GLUquadricObj *quadric;
        quadric = gluNewQuadric();
        glPushMatrix();
        glColor3ub(255, 255, 255);
        glRotatef(m_orbit, 0.0, 1.0, 0.0);
        glTranslatef(m_distance, 0.0, 0.0);
        gluSphere(quadric, m_radius, 20.0, 20.0);
        glPopMatrix();
}

void Planete::animate() {

        m_orbit += m_orbitSpeed;
        if (m_orbit > 360.0)
                m_orbit -= 360.0;

        m_axisAni += 10.0;
        if (m_axisAni > 360.0)
                m_axisAni -= 360.0;
}


double Planete::getRadius() {
        return m_radius;
}

double Planete::getDistance() {
        return m_distance;
}

double Planete::getOrbit() {
        return m_orbit;
}

double Planete::getOrbitSpeed() {
        return m_orbitSpeed;
}

double Planete::getAxisTilt() {
        return m_axisTilt;
}

double Planete::getAxisAni() {
        return m_axisAni;
}


void Planete::setRadius(double r) {
        m_radius = r;
}

void Planete::setDistance(double d) {
        m_distance = d;
}

void Planete::setOrbit(double o) {
        m_orbit = o;
}

void Planete::setOrbitSpeed(double os) {
        m_orbitSpeed = os;
}

void Planete::setAxisTilt(double at) {
        m_axisTilt = at;
}

void Planete::setAxisAni(double aa) {
        m_axisAni = aa;
}
