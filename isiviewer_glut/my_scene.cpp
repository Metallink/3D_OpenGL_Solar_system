#include "my_scene.h"

#include <iostream>
#include <math.h>
#include <GL/gl.h>  // OpenGL include file
#include <GL/glut.h>

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

                //... insert here the other objects

                // création et insertion du soleil
                glPushMatrix();
                glScalef(0.9,0.9,0.9);
                glColor3f(255,255,0);
                glutSolidSphere(1, 20,10);
                glPopMatrix();

                // axe blanc autour du soleil
                glColor3d(255,255,255);

                GLfloat x;
                GLfloat y;
                int i;
                int lineAmount = 100; //# of triangles used to draw circle

                GLfloat radius = 2.0f; //radius
                GLfloat twicePi = 2.0f * M_PI;

                glBegin(GL_LINE_LOOP);
                for(i = 0; i <= lineAmount; i++) {
                        glVertex2f(
                                x + (radius * cos(i *  twicePi / lineAmount)),
                                y + (radius* sin(i * twicePi / lineAmount))
                                );
                }
                glEnd();

                // mercure
                glPushMatrix();
                glRotatef(_nbRotate,0,0,-1); // revolution
                glRotatef(_nbRotatePlanete,0,0,-1); //rotation
                glTranslatef(2,0,0);
                glScalef(0.3,0.3,0.3);
                glColor3f(242,245,249);
                glutSolidSphere(1, 20,10);
                glPopMatrix();


                // venus
                glPushMatrix();
                glRotatef(_nbRotate,0,0,-1); // revolution
                glRotatef(_nbRotatePlanete,0,0,-1); //rotation
                glTranslatef(3,0,0);
                glScalef(0.5,0.5,0.5);
                glColor3f(212,55,72);
                glutSolidSphere(1, 20,10);
                glPopMatrix();

                break;
        }
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

        // Increase rotation of the current displayed object with 'h'
        if ((e->key()==Qt::Key_Z) && (modifiers==Qt::NoButton)) {
                std::cout << "Vous avez appuyez sur Z" << endl;
                //this->_x += 1;
                //this->_y += 1;
                this->_nbRotate += 2;
                this->_nbRotatePlanete +=  4;
        }



        // ... and so on with other else/if blocks.

        return handled;
}
