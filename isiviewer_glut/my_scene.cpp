#include "my_scene.h"
#include "planet.h"

#include <iostream>
#include <math.h>
#include <GL/gl.h>  // OpenGL include file
#include <GL/glut.h>

//NOTE: https://www.youtube.com/watch?v=2E2OA_txjEI

using namespace std;


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
                glutSolidSphere(1, 20,10);
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

                /* creation des objets planetes */

                Planet soleil (5.0, 0, 0, 0);
                Planet mercure (0.38, 1, 0, 0);
                Planet venus (0.95, 2, 0, 0);
                Planet terre (1, 3,0, 0);
                Planet mars (0.53, 4, 0, 0);
                Planet jupiter (11.19, 5, 0, 0);
                Planet saturne(9.41, 6, 0, 0);
                Planet uranus (4.01, 7, 0, 0);
                Planet neptune(3.89, 8, 0, 0);

                /* creation des orbites */

                soleil.traceOrbite();
                mercure.traceOrbite();
                venus.traceOrbite();
                terre.traceOrbite();
                mars.traceOrbite();
                jupiter.traceOrbite();
                saturne.traceOrbite();
                uranus.traceOrbite();
                neptune.traceOrbite();

                /* on trace les planetes */


                /********************** SOLEIL **********************/
                glPushMatrix();
                glColor3f(255,255,0); // jaune
                glRotatef(soleil._orbit, 0.0, 1.0, 0.0);
                glTranslatef(soleil._distance, 0.0, 0.0);
                glPushMatrix();
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glutWireSphere(soleil._radius, 20,10);
                //glScalef(0.9,0.9,0.9);
                glPopMatrix();
                glPopMatrix();
                /********************** MERCURE **********************/
                glPushMatrix();
                glRotatef(mercure._orbit, 0.0, 1.0, 0.0);
                glTranslatef(mercure._distance, 0.0, 0.0);
                glColor3f(255,255,0);
                glPushMatrix();
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glutWireSphere(mercure._radius, 20,10);
                glPopMatrix();
                glPopMatrix();
                /********************** VENUS **********************/
                glPushMatrix();
                glRotatef(venus._orbit, 0.0, 1.0, 0.0);
                glTranslatef(venus._distance, 0.0, 0.0);
                glColor3f(255,255,0);
                glPushMatrix();
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glutWireSphere(venus._radius, 20,10);
                glPopMatrix();
                glPopMatrix();
                /********************** TERRE **********************/
                glPushMatrix();
                glRotatef(venus._orbit, 0.0, 1.0, 0.0);
                glTranslatef(venus._distance, 0.0, 0.0);
                glColor3f(255,255,0);
                glPushMatrix();
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glutWireSphere(venus._radius, 20,10);
                glPopMatrix();

                //trace de la Lune avec comme centre de repere global la Terre
                terre.traceLune();
                glPopMatrix();
                /********************** MARS **********************/
                glPushMatrix();
                glRotatef(mars._orbit, 0.0, 1.0, 0.0);
                glTranslatef(mars._distance, 0.0, 0.0);
                glColor3f(255,255,0);
                glPushMatrix();
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glutWireSphere(mars._radius, 20,10);
                glPopMatrix();
                glPopMatrix();
                /********************** JUPITER **********************/
                glPushMatrix();
                glRotatef(jupiter._orbit, 0.0, 1.0, 0.0);
                glTranslatef(jupiter._distance, 0.0, 0.0);
                glColor3f(255,255,0);
                glPushMatrix();
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glutWireSphere(jupiter._radius, 20,10);
                glPopMatrix();
                glPopMatrix();
                /********************** SATURNE **********************/
                glPushMatrix();
                glRotatef(saturne._orbit, 0.0, 1.0, 0.0);
                glTranslatef(saturne._distance, 0.0, 0.0);
                glColor3f(255,255,0);
                glPushMatrix();
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glutWireSphere(saturne._radius, 20,10);
                glPopMatrix();
                glPopMatrix();
                /********************** URANUS **********************/
                glPushMatrix();
                glRotatef(uranus._orbit, 0.0, 1.0, 0.0);
                glTranslatef(uranus._distance, 0.0, 0.0);
                glColor3f(255,255,0);
                glPushMatrix();
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glutWireSphere(uranus._radius, 20,10);
                glPopMatrix();
                glPopMatrix();
                /********************** NEPTUNE **********************/
                glPushMatrix();
                glRotatef(neptune._orbit, 0.0, 1.0, 0.0);
                glTranslatef(neptune._distance, 0.0, 0.0);
                glColor3f(255,255,0);
                glPushMatrix();
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glutWireSphere(neptune._radius, 20,10);
                glPopMatrix();
                glPopMatrix();

                break;
        }
}


/* =========== FONCTIONS UTILES POUR LE FICHIER MY_SCENE */
//FIXME: encaplusation de la fonction animation
void animation (Planet *p) {

        // soleil.deplacementJour();
        // mercure.deplacementJour();
        // venus.deplacementJour();
        // terre.deplacementJour();
        // mars.deplacementJour();
        // jupiter.deplacementJour();
        // saturne.deplacementJour();
        // uranus.deplacementJour();
        // neptune.deplacementJour();

        //p->deplacementJour();
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
