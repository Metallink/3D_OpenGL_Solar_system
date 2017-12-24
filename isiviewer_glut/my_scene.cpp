#include "my_scene.h"
#include "texture.h"
#include "planete.h"

#include <iostream>
#include <math.h>
#include <GL/gl.h>  // OpenGL include file
#include <GL/glut.h>

using namespace std;

/*****************************************************/
/**              VARIABLES GLOBALES                 **/
/*****************************************************/
//double

/*****************************************************/
/**       INITIALISATION DES OBJETS "PLANETE"       **/
/*****************************************************/
/* Les dimensions des planeetes ont été respecté sauf pour le soleil en se basant sur les diametres de la maquette du lien fourni dans le sujet.*/
/* De plus, les distances n'ont pas été respecté comme specifié dans le sujet. J'ai fait en sorte que les planetes soient equidistantes.*/

/* RAPPEL CONSTRUCTEUR DE LA CLASSE PLANETE */
/*Planete(double radius, double distance, double orbit, double orbitSpeed, double axisTilt, double axisAni); */

Planete *sun = new Planete (RADIUS_SOLEIL, DISTANCE_SOLEIL, 0, 0, 0, 0); // radius du soleil non respecté sinon beaucoup trop grand par rapport aux autres planetes
Planete *mer = new Planete (RADIUS_MERCURE, DISTANCE_MERCURE, 0, 4.74, 02.11, 0);
Planete *ven = new Planete (RADIUS_VENUS, DISTANCE_VENUS, 0, 3.50, 177.0, 0);
Planete *ear = new Planete (RADIUS_TERRE, DISTANCE_TERRE, 0, 2.98, 23.44, 0);
Planete *lun = new Planete (RADIUS_LUNE, DISTANCE_LUNE, 0, 5.40, 0, 0);
Planete *mar = new Planete (RADIUS_MARS, DISTANCE_MARS, 0, 2.41, 25.00, 0);
Planete *jup = new Planete (RADIUS_JUPITER, DISTANCE_JUPITER, 0, 1.31, 03.13, 0);
Planete *sat = new Planete (RADIUS_SATURNE, DISTANCE_SATURNE, 0, 0.97, 26.70, 0);
Planete *ura = new Planete (RADIUS_URANUS, DISTANCE_URANUS, 0, 0.68, 97.77, 0);
Planete *nep = new Planete (RADIUS_NEPTUNE, DISTANCE_NEPTUNE, 0, 0.54, 28.32, 0);


//FIXME: essayer d'utiliser la fonction dessinerOrbite de planete.cpp au lieu de cette merde
void MyScene::orbitalTrails() {
        glPushMatrix();
        glColor3ub(255, 255, 255);
        glRotated(90.0, 1.0, 0.0, 0.0);
        glutWireTorus(0.001, mer->getDistance(), 100.0, 100.0);
        glutWireTorus(0.001, ven->getDistance(), 100.0, 100.0);
        glutWireTorus(0.001, ear->getDistance(), 100.0, 100.0);
        glutWireTorus(0.001, mar->getDistance(), 100.0, 100.0);
        glutWireTorus(0.001, jup->getDistance(), 100.0, 100.0);
        glutWireTorus(0.001, sat->getDistance(), 100.0, 100.0);
        glutWireTorus(0.001, ura->getDistance(), 100.0, 100.0);
        glutWireTorus(0.001, nep->getDistance(), 100.0, 100.0);
        glPopMatrix();
}

// variables globales
int bigOrbitActive = 1;
int smallOrbitActive = 1;
int moonsActive = 1;
int changeCamera = 0;

GLuint sunTexture, merTexture, venTexture, earTexture, marTexture, jupTexture, satTexture, uraTexture, nepTexture, pluTexture, staTexture, logTexture;



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
        _radiusMax = 10.0;
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

        //glColor3ub(0,0,0);
        glClearColor(0.0, 0.0, 0.0, 0.0);  // raz les couleurs et colorise tout en noir
        glEnable(GL_NORMALIZE); // normalize normal vectors when objects are scaled
        glEnable(GL_COLOR_MATERIAL);


        /*****************************************************/
        /**             CHARGEMENT DES TEXTURES             **/
        /*****************************************************/

        //Texture *sta = readBMP("../isiviewer_glut/textures/espace.bmp");  staTexture = loadTexture(sta);  delete sta;
        Texture *soleil = new Texture();
        soleil->readBMP(SOLEIL_FICHIER_BMP);
        sunTexture = soleil->loadTexture();
        delete soleil;

        Texture *mercure = new Texture();
        mercure->readBMP(MERCURE_FICHIER_BMP);
        merTexture = mercure->loadTexture();
        delete mercure;

        Texture *venus = new Texture();
        venus->readBMP(VENUS_FICHIER_BMP);
        venTexture = venus->loadTexture();
        delete venus;

        Texture *terre = new Texture();
        terre->readBMP(TERRE_FICHIER_BMP);
        earTexture = terre->loadTexture();
        delete terre;

        Texture *mars = new Texture();
        mars->readBMP(MARS_FICHIER_BMP);
        marTexture = mars->loadTexture();
        delete mars;

        Texture *jupiter = new Texture();
        jupiter->readBMP(JUPITER_FICHIER_BMP);
        jupTexture = jupiter->loadTexture();
        delete jupiter;

        Texture *saturne = new Texture();
        saturne->readBMP(SATURNE_FICHIER_BMP);
        satTexture = saturne->loadTexture();
        delete saturne;

        Texture *uranus = new Texture();
        uranus->readBMP(URANUS_FICHIER_BMP);
        uraTexture = uranus->loadTexture();
        delete uranus;

        Texture *neptune = new Texture();
        neptune->readBMP(NEPTUNE_FICHIER_BMP);
        nepTexture = neptune->loadTexture();
        delete neptune;

        //NOTE:FONCTIONNELLE
        // Texture *soleil = readBMP("../isiviewer_glut/textures/soleil.bmp"); sunTexture = loadTexture(soleil); delete soleil;
        // Texture *sta = readBMP("../isiviewer_glut/textures/espace.bmp");  staTexture = loadTexture(sta);  delete sta;
        // Texture *mer = readBMP("../isiviewer_glut/textures/mercure.bmp"); merTexture = loadTexture(mer);  delete mer;
        // Texture *ven = readBMP("../isiviewer_glut/textures/venus.bmp");  venTexture = loadTexture(ven);  delete ven;
        // Texture *ear = readBMP("../isiviewer_glut/textures/terre.bmp");  earTexture = loadTexture(ear);  delete ear;
        // Texture *mar = readBMP("../isiviewer_glut/textures/mars.bmp");  marTexture = loadTexture(mar);  delete mar;
        // Texture *jup = readBMP("../isiviewer_glut/textures/jupiter.bmp"); jupTexture = loadTexture(jup);  delete jup;
        // Texture *sat = readBMP("../isiviewer_glut/textures/saturne.bmp");  satTexture = loadTexture(sat);  delete sat;
        // Texture *ura = readBMP("../isiviewer_glut/textures/uranus.bmp");  uraTexture = loadTexture(ura);  delete ura;
        // Texture *nep = readBMP("../isiviewer_glut/textures/neptune.bmp"); nepTexture = loadTexture(nep);  delete nep;

}

/**
 * Draw the scene
 *
 */
void MyScene::draw()
{

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        GLUquadric *quadric;
        quadric = gluNewQuadric();

        glPushMatrix();
        glScalef(_radius/10, _radius/10, _radius/10);

        // glRotated(90.0, 1.0, 0.0, 0.0);
        // glutWireTorus(0.001, mer->getDistance(), 100.0, 100.0);
        // glutWireTorus(0.001, ven->getDistance(), 100.0, 100.0);
        // glutWireTorus(0.001, ear->getDistance(), 100.0, 100.0);
        // glutWireTorus(0.001, mar->getDistance(), 100.0, 100.0);
        // glutWireTorus(0.001, jup->getDistance(), 100.0, 100.0);
        // glutWireTorus(0.001, sat->getDistance(), 100.0, 100.0);
        // glutWireTorus(0.001, ura->getDistance(), 100.0, 100.0);
        // glutWireTorus(0.001, nep->getDistance(), 100.0, 100.0);

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
                glRotatef(sun->getOrbit(), 0.0, 1.0, 0.0);
                glTranslatef(sun->getDistance(), 0.0, 0.0);

                /*****************************************************/
                /**       ON AFFICHE LES ORBITES DES PLANETES       **/
                /*****************************************************/
                orbitalTrails();

                glPushMatrix();
                glRotatef(sun->getAxisTilt(), 1.0, 0.0, 0.0);
                glRotatef(sun->getAxisAni(), 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, sunTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, sun->getRadius(), 20.0, 20.0);
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
                glRotatef(mer->getOrbit(), 0.0, 1.0, 0.0);
                glTranslatef(mer->getDistance(), 0.0, 0.0);

                glPushMatrix();
                glRotatef(mer->getAxisTilt(), 1.0, 0.0, 0.0);
                glRotatef(mer->getAxisAni(), 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, merTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, mer->getRadius(), 20.0, 20.0);
                glDisable(GL_TEXTURE_2D);
                glPopMatrix();
                glPopMatrix();

                //Venus
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(ven->getOrbit(), 0.0, 1.0, 0.0);
                glTranslatef(ven->getDistance(), 0.0, 0.0);

                glPushMatrix();
                glRotatef(ven->getAxisTilt(), 1.0, 0.0, 0.0);
                glRotatef(ven->getAxisAni(), 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, venTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, ven->getRadius(), 20.0, 20.0);
                glDisable(GL_TEXTURE_2D);
                glPopMatrix();
                glPopMatrix();

                //Earth, Orbit, Moon
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(ear->getOrbit(), 0.0, 1.0, 0.0);
                glTranslatef(ear->getDistance(), 0.0, 0.0);

                glPushMatrix();
                glRotatef(ear->getAxisTilt(), 1.0, 0.0, 0.0);
                glRotatef(ear->getAxisAni(), 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, earTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, ear->getRadius(), 20.0, 20.0);
                glDisable(GL_TEXTURE_2D);
                glPopMatrix();
                // lune
                lun->drawMoon();
                glPopMatrix();

                //Mars, Orbits, Moons
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(mar->getOrbit(), 0.0, 1.0, 0.0);
                glTranslatef(mar->getDistance(), 0.0, 0.0);

                glPushMatrix();
                glRotatef(mar->getAxisTilt(), 1.0, 0.0, 0.0);
                glRotatef(mar->getAxisAni(), 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, marTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, mar->getRadius(), 20.0, 20.0);
                glDisable(GL_TEXTURE_2D);
                glPopMatrix();
                glPopMatrix();

                //Jupiter, Orbits, Moons
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(jup->getOrbit(), 0.0, 1.0, 0.0);
                glTranslatef(jup->getDistance(), 0.0, 0.0);

                glPushMatrix();
                glRotatef(jup->getAxisTilt(), 1.0, 0.0, 0.0);
                glRotatef(jup->getAxisAni(), 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, jupTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, jup->getRadius(), 20.0, 20.0);
                glDisable(GL_TEXTURE_2D);
                glPopMatrix();
                glPopMatrix();

                //Saturn, Orbit, Moon
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(sat->getOrbit(), 0.0, 1.0, 0.0);
                glTranslatef(sat->getDistance(), 0.0, 0.0);
                glPushMatrix();
                glRotatef(sat->getAxisTilt(), 1.0, 0.0, 0.0);
                glRotatef(sat->getAxisAni(), 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, satTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, sat->getRadius(), 20.0, 20.0);
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
                glRotatef(ura->getOrbit(), 0.0, 1.0, 0.0);
                glTranslatef(ura->getDistance(), 0.0, 0.0);

                glPushMatrix();
                glRotatef(ura->getAxisTilt(), 1.0, 0.0, 0.0);
                glRotatef(ura->getAxisAni(), 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, uraTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, ura->getRadius(), 20.0, 20.0);
                glDisable(GL_TEXTURE_2D);
                glPopMatrix();
                glPopMatrix();

                //Neptune, Orbit, Moon
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(nep->getOrbit(), 0.0, 1.0, 0.0);
                glTranslatef(nep->getDistance(), 0.0, 0.0);

                glPushMatrix();
                glRotatef(nep->getAxisTilt(), 1.0, 0.0, 0.0);
                glRotatef(nep->getAxisAni(), 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, nepTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, nep->getRadius(), 20.0, 20.0);
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

                sun->animate();
                mer->animate();
                ven->animate();
                ear->animate();
                mar->animate();
                jup->animate();
                sat->animate();
                ura->animate();
                nep->animate();
                lun->animate();

        }




        // ... and so on with other else/if blocks.

        return handled;
}
