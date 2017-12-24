#include "my_scene.h"
#include "imageloader.h"

#include <iostream>
#include <math.h>
#include <GL/gl.h>  // OpenGL include file
#include <GL/glut.h>

using namespace std;


class Planet {
public:
float radius, distance, orbit, orbitSpeed, axisTilt, axisAni;
Planet(float _radius, float _distance, float _orbit, float _orbitSpeed, float _axisTilt, float _axisAni){
        radius = _radius;
        distance = _distance;
        orbit = _orbit;
        orbitSpeed = _orbitSpeed;
        axisTilt = _axisTilt;
        axisAni = _axisAni;
}

void drawSmallOrbit(void){
        glPushMatrix();
        glColor3ub(255, 255, 255);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glutWireTorus(0.001, distance, 100.0, 100.0);
        glPopMatrix();
}

void drawMoon(void){
        GLUquadricObj *quadric;
        quadric = gluNewQuadric();
        glPushMatrix();
        glColor3ub(255, 255, 255);
        glRotatef(orbit, 0.0, 1.0, 0.0);
        glTranslatef(distance, 0.0, 0.0);
        gluSphere(quadric, radius, 20.0, 20.0);
        glPopMatrix();
}

};

//Sun, Planets and Stars
Planet sun(5.0, 0, 0, 0, 0, 0);    //Sun
Planet mer(1.0, 7, 0, 4.74, 02.11, 0);  //Mercury
Planet ven(1.5, 11, 0, 3.50, 177.0, 0);  //Venus
Planet ear(2.0, 16, 0, 2.98, 23.44, 0);  //Earth
Planet mar(1.2, 21, 0, 2.41, 25.00, 0);  //Mars
Planet jup(3.5, 28, 0, 1.31, 03.13, 0);  //Jupiter
Planet sat(3.0, 37, 0, 0.97, 26.70, 0);  //Saturn
Planet ura(2.5, 45.5, 0, 0.68, 97.77, 0); //Uranus
Planet nep(2.3, 53.6, 0, 0.54, 28.32, 0); //Neptune
Planet lun(.40, 3, 0, 5.40, 0, 0);   //Luna     (Earth)


int isAnimate = 0;
int bigOrbitActive = 1;
int smallOrbitActive = 1;
int moonsActive = 1;
int changeCamera = 0;
int frameCount = 0;
int labelsActive = 0;
int zoom = 50;
int logoScene = 1;

GLuint sunTexture, merTexture, venTexture, earTexture, marTexture, jupTexture, satTexture, uraTexture, nepTexture, pluTexture, staTexture, logTexture;

GLuint loadTexture(Image* image) {
        //http://www.codeincodeblock.com/2012/05/simple-method-for-texture-mapping-on.html
        GLuint textureId;
        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
        return textureId;
}

void animate(int n){
        if (isAnimate) {
                mer.orbit += mer.orbitSpeed;
                ven.orbit += ven.orbitSpeed;
                ear.orbit += ear.orbitSpeed;
                mar.orbit += mar.orbitSpeed;
                jup.orbit += jup.orbitSpeed;
                sat.orbit += sat.orbitSpeed;
                ura.orbit += ura.orbitSpeed;
                nep.orbit += nep.orbitSpeed;
                lun.orbit += lun.orbitSpeed;
                if (mer, ven, ear, mar, jup, sat, ura, nep, lun.orbit > 360.0) {
                        mer, ven, ear, mar, jup, sat, ura, nep, lun.orbit -= 360.0;
                }
                mer.axisAni += 10.0;
                ven.axisAni += 10.0;
                ear.axisAni += 10.0;
                mar.axisAni += 10.0;
                jup.axisAni += 10.0;
                sat.axisAni += 10.0;
                ura.axisAni += 10.0;
                nep.axisAni += 10.0;
                if (mer, ven, ear, mar, jup, sat, ura, nep.axisAni > 360.0) {
                        mer, ven, ear, mar, jup, sat, ura, nep.axisAni -= 360.0;
                }
                //glutPostRedisplay();
                //glutTimerFunc(30, animate, 1);
        }
}

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
        _radiusMax = 1000.0;
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
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glLineWidth(1.5);

        glClearColor(0.0, 0.0, 0.0, 0.0);
        glEnable(GL_NORMALIZE); // normalize normal vectors when objects are scaled
        glEnable(GL_COLOR_MATERIAL);
        Image *soleil = loadBMP("../isiviewer_glut/textures/soleil.bmp");
        sunTexture = loadTexture(soleil);
        delete soleil;


        Image* sta = loadBMP("../isiviewer_glut/textures/espace.bmp");  staTexture = loadTexture(sta);  delete sta;
        Image* mer = loadBMP("../isiviewer_glut/textures/mercure.bmp"); merTexture = loadTexture(mer);  delete mer;
        Image* ven = loadBMP("../isiviewer_glut/textures/venus.bmp");  venTexture = loadTexture(ven);  delete ven;
        Image* ear = loadBMP("../isiviewer_glut/textures/terre.bmp");  earTexture = loadTexture(ear);  delete ear;
        Image* mar = loadBMP("../isiviewer_glut/textures/mars.bmp");  marTexture = loadTexture(mar);  delete mar;
        Image* jup = loadBMP("../isiviewer_glut/textures/jupiter.bmp"); jupTexture = loadTexture(jup);  delete jup;
        Image* sat = loadBMP("../isiviewer_glut/textures/saturne.bmp");  satTexture = loadTexture(sat);  delete sat;
        Image* ura = loadBMP("../isiviewer_glut/textures/uranus.bmp");  uraTexture = loadTexture(ura);  delete ura;
        Image* nep = loadBMP("../isiviewer_glut/textures/neptune.bmp"); nepTexture = loadTexture(nep);  delete nep;

}

/**
 * Draw the scene
 *
 */
void MyScene::draw()
{


        GLUquadric *quadric;
        quadric = gluNewQuadric();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //glLoadIdentity();

        glPushMatrix();
        glScalef(_radius/2, _radius/2, _radius/2);

        switch(_currentObject%_numberOfObjects) {
        case MyScene::CUBE: // Draw the cube
                _cube.draw();
                break;
        case MyScene::AXIS: // Draw the axis

                // essai avec une sphere et un cylindre GLUT pour le moment...
                // mettre le code dans un objet Axis et appeler sa methode draw.

                glMatrixMode(GL_MODELVIEW);

                glPushMatrix();
                glScalef(0.2,0.2,0.2);
                glutSolidSphere(1, 20,10);
                glPopMatrix();

                glPushMatrix();
                glRotatef(90,0,1,0);
                glTranslatef(0,0,1);
                glScalef(0.1,0.1,1);
                glutWireSphere(1, 20,10);
                glPopMatrix();

                break;

        case MyScene::SOLARSYSTEM:

                //... insert here the other objects

                // Sun
                // glPushMatrix();
                // glScalef(0.1,0.1,0.1);
                // glEnable(GL_TEXTURE_2D);
                // glBindTexture(GL_TEXTURE_2D, sunTexture);
                // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                // gluQuadricTexture(quadric, 1);
                // gluSphere(quadric, sun.radius, 20.0, 20.0);
                // glDisable(GL_TEXTURE_2D);
                // glPopMatrix();

                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(sun.orbit, 0.0, 1.0, 0.0);
                glTranslatef(sun.distance, 0.0, 0.0);

                glPushMatrix();
                glRotatef(sun.axisTilt, 1.0, 0.0, 0.0);
                glRotatef(sun.axisAni, 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, sunTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, sun.radius, 20.0, 20.0);
                glDisable(GL_TEXTURE_2D);
                glPopMatrix();
                glPopMatrix();

                // Mercury
                // glPushMatrix();
                // glScalef(0.1,0.1,0.1);
                // glRotatef(360,0,1,0);
                // glRotatef(90,0,1,0);
                // glTranslatef(7,0,0);
                // glutSolidSphere(1, 20,10);
                // glPopMatrix();
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(mer.orbit, 0.0, 1.0, 0.0);
                glTranslatef(mer.distance, 0.0, 0.0);

                glPushMatrix();
                glRotatef(mer.axisTilt, 1.0, 0.0, 0.0);
                glRotatef(mer.axisAni, 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, merTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, mer.radius, 20.0, 20.0);
                glDisable(GL_TEXTURE_2D);
                glPopMatrix();
                glPopMatrix();

                //Venus
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(ven.orbit, 0.0, 1.0, 0.0);
                glTranslatef(ven.distance, 0.0, 0.0);

                glPushMatrix();
                glRotatef(ven.axisTilt, 1.0, 0.0, 0.0);
                glRotatef(ven.axisAni, 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, venTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, ven.radius, 20.0, 20.0);
                glDisable(GL_TEXTURE_2D);
                glPopMatrix();
                glPopMatrix();

                //Earth, Orbit, Moon
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(ear.orbit, 0.0, 1.0, 0.0);
                glTranslatef(ear.distance, 0.0, 0.0);

                glPushMatrix();
                glRotatef(ear.axisTilt, 1.0, 0.0, 0.0);
                glRotatef(ear.axisAni, 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, earTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, ear.radius, 20.0, 20.0);
                glDisable(GL_TEXTURE_2D);
                glPopMatrix();
                // lune
                lun.drawMoon();
                glPopMatrix();

                //Mars, Orbits, Moons
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(mar.orbit, 0.0, 1.0, 0.0);
                glTranslatef(mar.distance, 0.0, 0.0);

                glPushMatrix();
                glRotatef(mar.axisTilt, 1.0, 0.0, 0.0);
                glRotatef(mar.axisAni, 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, marTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, mar.radius, 20.0, 20.0);
                glDisable(GL_TEXTURE_2D);
                glPopMatrix();
                glPopMatrix();

                //Jupiter, Orbits, Moons
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(jup.orbit, 0.0, 1.0, 0.0);
                glTranslatef(jup.distance, 0.0, 0.0);

                glPushMatrix();
                glRotatef(jup.axisTilt, 1.0, 0.0, 0.0);
                glRotatef(jup.axisAni, 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, jupTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, jup.radius, 20.0, 20.0);
                glDisable(GL_TEXTURE_2D);
                glPopMatrix();
                glPopMatrix();

                //Saturn, Orbit, Moon
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(sat.orbit, 0.0, 1.0, 0.0);
                glTranslatef(sat.distance, 0.0, 0.0);
                glPushMatrix();
                glRotatef(sat.axisTilt, 1.0, 0.0, 0.0);
                glRotatef(sat.axisAni, 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, satTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, sat.radius, 20.0, 20.0);
                glPopMatrix();
                glDisable(GL_TEXTURE_2D);
                glPushMatrix();
                glColor3ub(158, 145, 137);
                glRotatef(-63.0, 1.0, 0.0, 0.0);
                glutWireTorus(0.2, 6.0, 30.0, 30.0);
                glutWireTorus(0.4, 5.0, 30.0, 30.0);
                glPopMatrix();
                glPopMatrix();

                glColor3ub(255, 255, 255); //FIXES SHADING ISSUE

                //Uranus, Orbit, Moon
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(ura.orbit, 0.0, 1.0, 0.0);
                glTranslatef(ura.distance, 0.0, 0.0);

                glPushMatrix();
                glRotatef(ura.axisTilt, 1.0, 0.0, 0.0);
                glRotatef(ura.axisAni, 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, uraTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, ura.radius, 20.0, 20.0);
                glDisable(GL_TEXTURE_2D);
                glPopMatrix();
                glPopMatrix();

                //Neptune, Orbit, Moon
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(nep.orbit, 0.0, 1.0, 0.0);
                glTranslatef(nep.distance, 0.0, 0.0);

                glPushMatrix();
                glRotatef(nep.axisTilt, 1.0, 0.0, 0.0);
                glRotatef(nep.axisAni, 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, nepTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, nep.radius, 20.0, 20.0);
                glDisable(GL_TEXTURE_2D);
                glPopMatrix();
                glPopMatrix();

                //espace
                //FIXME: pk il y'a un rond noir?
                // glPushMatrix();
                // glScalef(-0.1,-0.1,-0.1);
                // glTranslatef(0.0, 0.0, 0.0);
                // glEnable(GL_TEXTURE_2D);
                // glBindTexture(GL_TEXTURE_2D, staTexture);
                // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                // gluQuadricOrientation(quadric,GLU_INSIDE);
                // gluQuadricTexture(quadric, 1);
                // gluSphere(quadric, 30, 20.0, 20.0);
                // glDisable(GL_TEXTURE_2D);
                // glPopMatrix();

                // glPushMatrix();
                // glScalef(0.1,0.1,0.1);
                // glRotatef(360,0,1,0);
                // glTranslatef(11,0,0);
                // glutSolidSphere(1.5, 20,10);
                // glPopMatrix();

        }

        glPopMatrix();

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
        // change displau mode with 'z'
        else if ((e->key()==Qt::Key_Z) && (modifiers==Qt::NoButton)) {
                if (isAnimate) isAnimate = 0;
                else{ isAnimate = 1; animate(1); };
        }




        // ... and so on with other else/if blocks.

        return handled;
}
