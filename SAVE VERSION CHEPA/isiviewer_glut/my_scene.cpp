#include "my_scene.h"
#include "planet.h"

#include <iostream>
#include <math.h>
#include <GL/gl.h>  // OpenGL include file
#include <GL/glut.h>

//NOTE: https://www.youtube.com/watch?v=2E2OA_txjEI

using namespace std;

/* creation des objets planetes */

// Planet *soleil  = new Planet (5.0, 0, 0, 0);
// Planet *mercure = new Planet (0.38, 7, 0, 0);
// Planet *venus = new Planet (0.95, 11, 0, 0);
// Planet *terre = new Planet (1, 16, 0, 0);
// Planet *mars = new Planet (0.53, 21, 0, 0);
// Planet *jupiter = new Planet (11.1, 28, 0, 0);
// Planet *saturne = new Planet (9.41, 37, 0, 0);
// Planet *uranus = new Planet (4.01, 45.5, 0, 0);
// Planet *neptune = new Planet (3.89, 53.6, 0, 0);

Planet *soleil  = new Planet (5.0, 0, 0, 0);
Planet *mercure = new Planet (0.38, 7, 0, 0);
Planet *venus = new Planet (0.95, 11, 0, 0);
Planet *terre = new Planet (1, 16, 0, 0);
Planet *mars = new Planet (0.53, 21, 0, 0);
Planet *jupiter = new Planet (11.1, 28, 0, 0);
Planet *saturne = new Planet (9.41, 37, 0, 0);
Planet *uranus = new Planet (4.01, 45.5, 0, 0);
Planet *neptune = new Planet (3.89, 53.6, 0, 0);

/**
 * Constructor
 *
 * @param radius
 */
MyScene::MyScene(float radius)
{
        std::cout << "constructing :  MyScene" << std::endl;

        _currentObject = MyScene::SOLARSYSTEM;
        _numberOfObjects = 3;    // increment it when you add a new 3D object!

        _displayMode = MyScene::FLATSHADED;

        _radius = radius;

        _radiusMin = 0.1;
        _radiusMax = 2.0;
        _radiusIncr = 0.1;
}

/**
 * Destructor
 *
 */
MyScene::~MyScene()
{
        std::cout<<"~MyScene"<<std::endl;
}

/**
 * Init the scene and OpenGL state
 *
 */
void MyScene::init()
{

        // set antialiased lines
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glLineWidth(1.5);

        glEnable(GL_NORMALIZE); // normalize normal vectors when objects are scaled
}

/**
 * Draw the scene
 *
 */
void MyScene::draw()
{
        glPushMatrix();
        glScalef(_radius/2, _radius/2, _radius/2);

        switch(_currentObject%_numberOfObjects) {

        case MyScene::CUBE: // Draw the cube
                glColor3f(1., 0., 0.);
                _cube.draw();
                break;

        case MyScene::AXIS: // Draw the axis

                // essai avec une sphere et un cylindre GLUT pour le moment...
                // mettre le code dans un objet Axis et appeler sa methode draw.

                glMatrixMode(GL_MODELVIEW);


                // Axe X
                // cercle central, on le fait une fois
                glPushMatrix();
                glScalef(0.2,0.2,0.2);
                glColor3f(1., 1., 1.);
                glutWireSphere(1, 20,10);
                glPopMatrix();

                glPushMatrix();
                glRotatef(90,0,1,0);
                glTranslatef(0,0,1);
                glScalef(0.1,0.1,1);
                glColor3f(1., 0., 0.); // red
                glutWireSphere(1, 20,10);
                glPopMatrix();


                // Axe Y
                glPushMatrix();
                glRotatef(90,-1,0,0); //on l'oriente sur l'axe y
                glTranslatef(0,0,1);
                glScalef(0.1,0.1,1);
                glColor3f(0., 1., 0.); // green
                glutWireSphere(1, 20,10);
                glPopMatrix();

                // Axe Z
                glPushMatrix();
                glRotatef(90,0,0,-1); //on l'oriente sur l'axe z
                glTranslatef(0,0,1);
                glScalef(0.1,0.1,1);
                glColor3f(0., 0., 1.);
                glutWireSphere(1, 20,10);
                glPopMatrix();

                break;

        case MyScene::SOLARSYSTEM:

                // /* creation des objets planetes */
                //
                // Planet *soleil  = new Planet (5.0, 0, 0, 0);
                // Planet *mercure = new Planet (0.38, 7, 0, 0);
                // Planet *venus = new Planet (0.95, 11, 0, 0);
                // Planet *terre = new Planet (1, 16, 0, 0);
                // Planet *mars = new Planet (0.53, 21, 0, 0);
                // Planet *jupiter = new Planet (11.1, 28, 0, 0);
                // Planet *saturne = new Planet (9.41, 37, 0, 0);
                // Planet *uranus = new Planet (4.01, 45.5, 0, 0);
                // Planet *neptune = new Planet (3.89, 53.6, 0, 0);

                /* creation des orbites */

                mercure->traceOrbite();
                venus->traceOrbite();
                terre->traceOrbite();
                mars->traceOrbite();
                jupiter->traceOrbite();
                saturne->traceOrbite();
                uranus->traceOrbite();
                neptune->traceOrbite();

                // glColor3d(255,0,0);
                // int i;
                // int lineAmount = 100; //# of triangles used to draw circle
                //
                // GLfloat radius = 2.0f; //radius
                // GLfloat twicePi = 2.0f * M_PI;
                // GLfloat x;
                // GLfloat y;
                //
                // glBegin(GL_LINE_LOOP);
                // for(i = 0; i <= lineAmount; i++) {
                //         glVertex2f(
                //                 x + (radius * cos(i *  twicePi / lineAmount)),
                //                 y + (radius* sin(i * twicePi / lineAmount))
                //                 );
                // }
                // glEnd();
                //
                // glColor3d(255,0,0);
                // radius = 4.0f;
                // glBegin(GL_LINE_LOOP);
                // for(i = 0; i <= lineAmount; i++) {
                //         glVertex2f(
                //                 x + (radius * cos(i *  twicePi / lineAmount)),
                //                 y + (radius* sin(i * twicePi / lineAmount))
                //                 );
                // }
                // glEnd();


                /* on trace les planetes */


                /********************** SOLEIL **********************/
                // glPushMatrix();
                // glColor3f(255,255,0);
                // glRotatef(90,1,0,0);
                // glTranslatef(soleil->m_distance, 0.0, 0.0);
                // glScalef(0.9,0.9,0.9);
                // glutSolidSphere(1, 20,10);
                // glPopMatrix();

                // glPushMatrix();
                // glColor3f(255,255,0); // jaune
                // glRotatef(soleil->m_orbit, 0.0, 1.0, 0.0);
                // glTranslatef(soleil->m_distance, 0.0, 0.0);
                // glPushMatrix();
                // glRotatef(90.0, 1.0, 0.0, 0.0);
                // glutSolidSphere(soleil->m_radius, 20,10);
                // //glScalef(0.9,0.9,0.9);
                // glPopMatrix();
                // glPopMatrix();
                /********************** MERCURE **********************/
                // glPushMatrix();
                // glRotatef(mercure->m_orbit, 0.0, 1.0, 0.0);
                // glTranslatef(mercure->m_distance, 0.0, 0.0);
                // glColor3f(255,255,0);
                // glPushMatrix();
                // glRotatef(90.0, 1.0, 0.0, 0.0);
                // glutSolidSphere(mercure->m_radius, 20,10);
                // glPopMatrix();
                // glPopMatrix();
                /********************** VENUS **********************/
                // glPushMatrix();
                // glRotatef(venus->m_orbit, 0.0, 1.0, 0.0);
                // glTranslatef(venus->m_distance, 0.0, 0.0);
                // glColor3f(255,255,0);
                // glPushMatrix();
                // glRotatef(90.0, 1.0, 0.0, 0.0);
                // glutSolidSphere(venus->m_radius, 20,10);
                // glPopMatrix();
                // glPopMatrix();
                // /********************** TERRE **********************/
                // glPushMatrix();
                // glRotatef(venus->m_orbit, 0.0, 1.0, 0.0);
                // glTranslatef(venus->m_distance, 0.0, 0.0);
                // glColor3f(255,255,0);
                // glPushMatrix();
                // glRotatef(90.0, 1.0, 0.0, 0.0);
                // glutSolidSphere(venus->m_radius, 20,10);
                // glPopMatrix();
                //
                // //trace de la Lune avec comme centre de repere global la Terre
                // terre->traceLune();
                // glPopMatrix();
                // /********************** MARS **********************/
                // glPushMatrix();
                // glRotatef(mars->m_orbit, 0.0, 1.0, 0.0);
                // glTranslatef(mars->m_distance, 0.0, 0.0);
                // glColor3f(255,255,0);
                // glPushMatrix();
                // glRotatef(90.0, 1.0, 0.0, 0.0);
                // glutSolidSphere(mars->m_radius, 20,10);
                // glPopMatrix();
                // glPopMatrix();
                // /********************** JUPITER **********************/
                // glPushMatrix();
                // glRotatef(jupiter->m_orbit, 0.0, 1.0, 0.0);
                // glTranslatef(jupiter->m_distance, 0.0, 0.0);
                // glColor3f(255,255,0);
                // glPushMatrix();
                // glRotatef(90.0, 1.0, 0.0, 0.0);
                // glutSolidSphere(jupiter->m_radius, 20,10);
                // glPopMatrix();
                // glPopMatrix();
                // /********************** SATURNE **********************/
                // glPushMatrix();
                // glRotatef(saturne->m_orbit, 0.0, 1.0, 0.0);
                // glTranslatef(saturne->m_distance, 0.0, 0.0);
                // glColor3f(255,255,0);
                // glPushMatrix();
                // glRotatef(90.0, 1.0, 0.0, 0.0);
                // glutSolidSphere(saturne->m_radius, 20,10);
                // glPopMatrix();
                // glPopMatrix();
                // /********************** URANUS **********************/
                // glPushMatrix();
                // glRotatef(uranus->m_orbit, 0.0, 1.0, 0.0);
                // glTranslatef(uranus->m_distance, 0.0, 0.0);
                // glColor3f(255,255,0);
                // glPushMatrix();
                // glRotatef(90.0, 1.0, 0.0, 0.0);
                // glutSolidSphere(uranus->m_radius, 20,10);
                // glPopMatrix();
                // glPopMatrix();
                // /********************** NEPTUNE **********************/
                // glPushMatrix();
                // glRotatef(neptune->m_orbit, 0.0, 1.0, 0.0);
                // glTranslatef(neptune->m_distance, 0.0, 0.0);
                // glColor3f(255,255,0);
                // glPushMatrix();
                // glRotatef(90.0, 1.0, 0.0, 0.0);
                // glutSolidSphere(neptune->m_radius, 20,10);
                // glPopMatrix();
                // glPopMatrix();

                break;
        }
}


/* =========== FONCTIONS UTILES POUR LE FICHIER MY_SCENE */
//FIXME: encaplusation de la fonction animation
void MyScene::animation(Planet *p) {

        // soleil.deplacementJour();
        // mercure.deplacementJour();
        // venus.deplacementJour();
        // terre.deplacementJour();
        // mars.deplacementJour();
        // jupiter.deplacementJour();
        // saturne.deplacementJour();
        // uranus.deplacementJour();
        // neptune.deplacementJour();

        p->deplacementJour();
}

/**
 * Slot set current object
 *
 * @param currentObject
 */
void MyScene::slotSetCurrentObject(int currentObject)
{
        std::cout << "slotSetCurrentObject "<< currentObject << std::endl;
        _currentObject = currentObject;
        emit sigCurrentObjectChanged(currentObject);

}

/**
 * Slot set display mode
 *
 * @param currentObject
 */
void MyScene::slotSetDisplayMode(int displayMode)
{
        std::cout << "slotSetDisplayMode "<< displayMode%3 << std::endl;
        _displayMode = displayMode;

        switch (displayMode%3) {
        case MyScene::WIREFRAME:
                glDisable(GL_LIGHTING);
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                break;
        case MyScene::FLATSHADED:
                glEnable(GL_LIGHTING);
                glShadeModel(GL_FLAT);
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                break;
        case MyScene::SMOOTHSHADED:
                glEnable(GL_LIGHTING);
                glShadeModel(GL_SMOOTH);
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                break;
        }

        emit sigDisplayModeChanged(displayMode);
}

/**
 * Slot set radius
 *
 * @param radius
 */
void MyScene::slotSetRadius(double radius)
{
        if (fabs(_radius - float(radius))>1e-6) {
                //std::cout << "slotSetRadius "<< radius << std::endl;
                _radius = radius;
                emit sigRadiusChanged(radius);
        }
}



/**
 * Process keyboard events for QGLViewer widget
 *
 * @param e a keyboard event from QGLViewer
 *
 * @return true if the event has been handled
 */
bool MyScene::keyPressEvent(QKeyEvent *e)
{
        const Qt::KeyboardModifiers modifiers = e->modifiers();

        // A simple switch on e->key() is not sufficient if we want to take
        // state key into account.  With a switch, it would have been
        // impossible to separate 'F' from 'CTRL+F'.  That's why we use
        // imbricated if...else and a "handled" boolean.

        bool handled = false;

        float epsilon = 1e-5; // for float comparison
        // Increase radius with 'r'
        if ((e->key()==Qt::Key_R) && (modifiers==Qt::NoButton)) {
                if (_radius+_radiusIncr <= _radiusMax + epsilon)
                        this->slotSetRadius(_radius+_radiusIncr);
                handled = true;
        }
        // Decrease radius with 'R'
        else if ((e->key()==Qt::Key_R) && (modifiers==Qt::SHIFT)) {
                if (_radius-_radiusIncr >= _radiusMin - epsilon)
                        this->slotSetRadius(_radius-_radiusIncr);
                handled = true;
        }

        // Increase current displayed object with 'o'
        if ((e->key()==Qt::Key_O) && (modifiers==Qt::NoButton)) {
                this->slotSetCurrentObject(_currentObject+1);
                handled = true;
        }
        // Decrease current displayed object with 'O'
        else if ((e->key()==Qt::Key_O) && (modifiers==Qt::SHIFT)) {
                this->slotSetCurrentObject(_currentObject-1);
                handled = true;
        }

        // change displau mode with 's'
        else if ((e->key()==Qt::Key_S) && (modifiers==Qt::NoButton)) {
                this->slotSetDisplayMode(_displayMode+1);
                handled = true;
        }


        //FIXME: revoir le modulo pour les révolutions
        //FIXME: revoir la revolution des planetes
        // Increase rotation of the current displayed object with 'h'
        if ((e->key()==Qt::Key_Z) && (modifiers==Qt::NoButton)) {
                //std::cout << "Vous avez appuyez sur Z" << endl;

                // soleil._orbit += soleil._orbitSpeed;
                // mercure._orbit += mercure._orbitSpeed;
                // venus._orbit += venus._orbitSpeed;
                // terre._orbit += terre._orbitSpeed;
                // mars._orbit += mars._orbitSpeed;
                // jupiter._orbit += jupiter._orbitSpeed;
                // saturne._orbit += saturne._orbitSpeed;
                // uranus._orbit += uranus._orbitSpeed;
                // neptune._orbit += neptune._orbitSpeed;
                //
                // if (soleil, mercure, venus, terre, mars, jupiter, saturne, uranus, neptune._orbit > 360.0)
                //         soleil, mercure, venus, terre, mars, jupiter, saturne, uranus, neptune._orbit -= 360.0;

                soleil->deplacementJour();
                //animation(soleil);
                //soleil->deplacementJour()
                handled = true;

                //fmod (_revolutionMercure, (360/87.97));
                //this->_rotationMercure +=  4;

                /*this->_revolutionMercure += fmod (_revolutionMercure, (360/87.97));
                   this->_rotationMercure +=  4;
                   this->_revolutionVenus += fmod(_revolutionVenus,(360/224.67));
                   this->_rotationVenus +=  3;
                   this->_revolutionTerre += fmod(_revolutionTerre,(360/365.25));
                   this->_rotationTerre +=  2;

                   this->_revolutionMars += fmod(_revolutionMars,(360/686.98));
                   this->_rotationMars +=  6;
                   this->_revolutionJupiter += fmod(_revolutionJupiter,(360/4332.58));
                   this->_rotationJupiter +=  5;
                   this->_revolutionSaturne += fmod(_revolutionSaturne,(360/10759.23));
                   this->_rotationSaturne +=  7;
                   this->_revolutionUranus += fmod(_revolutionUranus,(360/30685.4));
                   this->_rotationUranus +=  9;
                   this->_revolutionNeptune += fmod(_revolutionNeptune,(360/60266));
                   this->_rotationNeptune +=  8;*/

        }

        //TODO: fonction "util" qui des que la rotation depasse 360, remet à 0



        // ... and so on with other else/if blocks.

        return handled;
}