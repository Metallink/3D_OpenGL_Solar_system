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
/*Planete(string name, double radius, double distance, double orbit, double orbitSpeed, double axisTilt, double axisAni); */

Planete *sun = new Planete ("Soleil", RADIUS_SOLEIL, DISTANCE_SOLEIL, 0, 0, 0, 0); // radius du soleil non respecté sinon beaucoup trop grand par rapport aux autres planetes
Planete *mer = new Planete ("Mercure", RADIUS_MERCURE, DISTANCE_MERCURE, 0, 4.74, 02.11, 0);
Planete *ven = new Planete ("Venus", RADIUS_VENUS, DISTANCE_VENUS, 0, 3.50, 177.0, 0);
Planete *ear = new Planete ("Terre", RADIUS_TERRE, DISTANCE_TERRE, 0, 2.98, 23.44, 0);
Planete *lun = new Planete ("Lune", RADIUS_LUNE, DISTANCE_LUNE, 0, 5.40, 0, 0);
Planete *mar = new Planete ("Mars", RADIUS_MARS, DISTANCE_MARS, 0, 2.41, 25.00, 0);
Planete *jup = new Planete ("Jupiter", RADIUS_JUPITER, DISTANCE_JUPITER, 0, 1.31, 03.13, 0);
Planete *sat = new Planete ("Saturne", RADIUS_SATURNE, DISTANCE_SATURNE, 0, 0.97, 26.70, 0);
Planete *ura = new Planete ("Uranus", RADIUS_URANUS, DISTANCE_URANUS, 0, 0.68, 97.77, 0);
Planete *nep = new Planete ("Neptune", RADIUS_NEPTUNE, DISTANCE_NEPTUNE, 0, 0.54, 28.32, 0);


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

GLuint sunTexture, merTexture, venTexture, earTexture, lunTexture, marTexture, jupTexture, satTexture, uraTexture, nepTexture, staTexture, satRingTexture;



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

        Texture *sta = new Texture();
        sta->readBMP(GALAXIE_FICHIER_BMP);
        staTexture = sta->loadTexture();
        delete sta;

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

        Texture *lune = new Texture();
        lune->readBMP(LUNE_FICHIER_BMP);
        lunTexture = lune->loadTexture();
        delete lune;

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

        Texture *anneau_saturne = new Texture();
        anneau_saturne->readBMP(SATURNE_ANNEAUX_FICHIER_BMP);
        satRingTexture = anneau_saturne->loadTexture();
        delete anneau_saturne;

        Texture *uranus = new Texture();
        uranus->readBMP(URANUS_FICHIER_BMP);
        uraTexture = uranus->loadTexture();
        delete uranus;

        Texture *neptune = new Texture();
        neptune->readBMP(NEPTUNE_FICHIER_BMP);
        nepTexture = neptune->loadTexture();
        delete neptune;
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

                /* Lune */
                // trace orbite de la lune
                glPushMatrix();
                glColor3ub(255, 255, 255);
                glRotated(90.0, 1.0, 0.0, 0.0);
                glutWireTorus(0.001, lun->getDistance(), 100.0, 100.0);
                glPopMatrix();
                glPushMatrix();
                glColor3ub(255, 255, 255);
                glRotatef(lun->getOrbit(), 0.0, 1.0, 0.0);
                glTranslatef(lun->getDistance(), 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, lunTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, lun->getRadius(), 20.0, 20.0);
                glDisable(GL_TEXTURE_2D);
                glPopMatrix();
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
                // ANNEAUX DE SATURNE
                //FIXME: ANNEAUX BOF, VOIR SI CA PEUT S'AMELIORER
                //NOTE: https://learnopengl.com/#!Advanced-OpenGL/Instancing
                glPushMatrix();
                glRotatef(-66.0, 1.0, 0.0, 0.0);
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, satRingTexture);
                glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                gluQuadricTexture(quadric, 1);
                gluQuadricDrawStyle(quadric, GLU_FILL);
                gluDisk(quadric, sat->getRadius()+0.65, sat->getRadius()+2.3, 30.0, 30.0);
                glPopMatrix();
                // glPushMatrix();
                // glColor3ub(158, 145, 137);
                // glRotatef(-63.0, 1.0, 0.0, 0.0);
                // glutWireTorus(0.2, 8.0, 30.0, 30.0);
                // glutWireTorus(0.4, 7.0, 30.0, 30.0);
                // glPopMatrix();
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
        }
        glPopMatrix();

        //espace
        //FIXME: PK IL Y'A UN ROND NOIR???
        glPushMatrix();
        glScalef(-0.1,-0.1,-0.1);
        glTranslatef(0.0, 0.0, 0.0);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, staTexture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        gluQuadricOrientation(quadric,GLU_INSIDE);
        gluQuadricTexture(quadric, 1);
        gluSphere(quadric, 30, 20.0, 20.0);
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();

} // end of draw

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

        // change displau mode with 'z'
        else if ((e->key()==Qt::Key_Z) && (modifiers==Qt::NoButton)) {
                this->slotSetDisplayMode(_displayMode+1);
                handled = true;
        }

        // on souhaite avancer l'animation d'une heure
        if ((e->key()==Qt::Key_H) && (modifiers==Qt::NoButton)) {

                sun->deplacementEnUneHeure(1, ROTATION_SOLEIL, 1); // ref. revolution du soleil à 1 pour ne pas avoir une division par 0 lors du calcul de la revolution
                mer->deplacementEnUneHeure(REVOLUTION_MERCURE, ROTATION_MERCURE, 1);
                ven->deplacementEnUneHeure(REVOLUTION_VENUS, ROTATION_VENUS, 1);
                ear->deplacementEnUneHeure(REVOLUTION_TERRE, ROTATION_TERRE, 1);
                lun->deplacementEnUneHeure(REVOLUTION_LUNE_TERRE, ROTATION_LUNE, 1);
                mar->deplacementEnUneHeure(REVOLUTION_MARS, ROTATION_MARS, 1);
                jup->deplacementEnUneHeure(REVOLUTION_JUPITER, ROTATION_JUPITER, 1);
                sat->deplacementEnUneHeure(REVOLUTION_SATURNE, ROTATION_SATURNE, 1);
                ura->deplacementEnUneHeure(REVOLUTION_URANUS, ROTATION_URANUS, 1);
                nep->deplacementEnUneHeure(REVOLUTION_NEPTUNE, ROTATION_NEPTUNE, 1);

                handled = true;
        }
        // on souhaite reculer l'animation d'une heure
        else if ((e->key()==Qt::Key_H) && (modifiers==Qt::SHIFT)) {

                sun->deplacementEnUneHeure(1, ROTATION_SOLEIL, 0); // ref. revolution du soleil à 1 pour ne pas avoir une division par 0 lors du calcul de la revolution
                mer->deplacementEnUneHeure(REVOLUTION_MERCURE, ROTATION_MERCURE, 0);
                ven->deplacementEnUneHeure(REVOLUTION_VENUS, ROTATION_VENUS, 0);
                ear->deplacementEnUneHeure(REVOLUTION_TERRE, ROTATION_TERRE, 0);
                lun->deplacementEnUneHeure(REVOLUTION_LUNE_TERRE, ROTATION_LUNE, 0);
                mar->deplacementEnUneHeure(REVOLUTION_MARS, ROTATION_MARS, 0);
                jup->deplacementEnUneHeure(REVOLUTION_JUPITER, ROTATION_JUPITER, 0);
                sat->deplacementEnUneHeure(REVOLUTION_SATURNE, ROTATION_SATURNE, 0);
                ura->deplacementEnUneHeure(REVOLUTION_URANUS, ROTATION_URANUS, 0);
                nep->deplacementEnUneHeure(REVOLUTION_NEPTUNE, ROTATION_NEPTUNE, 0);

                handled = true;
        }

        // on souhaite avancer l'animation d'un jour
        if ((e->key()==Qt::Key_J) && (modifiers==Qt::NoButton)) {

                sun->deplacementEnUnJour(1, ROTATION_SOLEIL, 1); // ref. revolution du soleil à 1 pour ne pas avoir une division par 0 lors du calcul de la revolution
                mer->deplacementEnUnJour(REVOLUTION_MERCURE, ROTATION_MERCURE, 1);
                ven->deplacementEnUnJour(REVOLUTION_VENUS, ROTATION_VENUS, 1);
                ear->deplacementEnUnJour(REVOLUTION_TERRE, ROTATION_TERRE, 1);
                lun->deplacementEnUnJour(REVOLUTION_LUNE_TERRE, ROTATION_LUNE, 1);
                mar->deplacementEnUnJour(REVOLUTION_MARS, ROTATION_MARS, 1);
                jup->deplacementEnUnJour(REVOLUTION_JUPITER, ROTATION_JUPITER, 1);
                sat->deplacementEnUnJour(REVOLUTION_SATURNE, ROTATION_SATURNE, 1);
                ura->deplacementEnUnJour(REVOLUTION_URANUS, ROTATION_URANUS, 1);
                nep->deplacementEnUnJour(REVOLUTION_NEPTUNE, ROTATION_NEPTUNE, 1);

                handled = true;
        }
        // on souhaite reculer l'animation d'un jour
        else if ((e->key()==Qt::Key_J) && (modifiers==Qt::SHIFT)) {

                sun->deplacementEnUnJour(1, ROTATION_SOLEIL, 0); // ref. revolution du soleil à 1 pour ne pas avoir une division par 0 lors du calcul de la revolution
                mer->deplacementEnUnJour(REVOLUTION_MERCURE, ROTATION_MERCURE, 0);
                ven->deplacementEnUnJour(REVOLUTION_VENUS, ROTATION_VENUS, 0);
                ear->deplacementEnUnJour(REVOLUTION_TERRE, ROTATION_TERRE, 0);
                lun->deplacementEnUnJour(REVOLUTION_LUNE_TERRE, ROTATION_LUNE, 0);
                mar->deplacementEnUnJour(REVOLUTION_MARS, ROTATION_MARS, 0);
                jup->deplacementEnUnJour(REVOLUTION_JUPITER, ROTATION_JUPITER, 0);
                sat->deplacementEnUnJour(REVOLUTION_SATURNE, ROTATION_SATURNE, 0);
                ura->deplacementEnUnJour(REVOLUTION_URANUS, ROTATION_URANUS, 0);
                nep->deplacementEnUnJour(REVOLUTION_NEPTUNE, ROTATION_NEPTUNE, 0);

                handled = true;
        }

        // on souhaite avancer l'animation d'une semaine
        if ((e->key()==Qt::Key_S) && (modifiers==Qt::NoButton)) {

                sun->deplacementEnUneSemaine(1, ROTATION_SOLEIL, 1); // ref. revolution du soleil à 1 pour ne pas avoir une division par 0 lors du calcul de la revolution
                mer->deplacementEnUneSemaine(REVOLUTION_MERCURE, ROTATION_MERCURE, 1);
                ven->deplacementEnUneSemaine(REVOLUTION_VENUS, ROTATION_VENUS, 1);
                ear->deplacementEnUneSemaine(REVOLUTION_TERRE, ROTATION_TERRE, 1);
                lun->deplacementEnUneSemaine(REVOLUTION_LUNE_TERRE, ROTATION_LUNE, 1);
                mar->deplacementEnUneSemaine(REVOLUTION_MARS, ROTATION_MARS, 1);
                jup->deplacementEnUneSemaine(REVOLUTION_JUPITER, ROTATION_JUPITER, 1);
                sat->deplacementEnUneSemaine(REVOLUTION_SATURNE, ROTATION_SATURNE, 1);
                ura->deplacementEnUneSemaine(REVOLUTION_URANUS, ROTATION_URANUS, 1);
                nep->deplacementEnUneSemaine(REVOLUTION_NEPTUNE, ROTATION_NEPTUNE, 1);

                handled = true;
        }
        // on souhaite reculer l'animation d'une semaine
        else if ((e->key()==Qt::Key_S) && (modifiers==Qt::SHIFT)) {

                sun->deplacementEnUneSemaine(1, ROTATION_SOLEIL, 0); // ref. revolution du soleil à 1 pour ne pas avoir une division par 0 lors du calcul de la revolution
                mer->deplacementEnUneSemaine(REVOLUTION_MERCURE, ROTATION_MERCURE, 0);
                ven->deplacementEnUneSemaine(REVOLUTION_VENUS, ROTATION_VENUS, 0);
                ear->deplacementEnUneSemaine(REVOLUTION_TERRE, ROTATION_TERRE, 0);
                lun->deplacementEnUneSemaine(REVOLUTION_LUNE_TERRE, ROTATION_LUNE, 0);
                mar->deplacementEnUneSemaine(REVOLUTION_MARS, ROTATION_MARS, 0);
                jup->deplacementEnUneSemaine(REVOLUTION_JUPITER, ROTATION_JUPITER, 0);
                sat->deplacementEnUneSemaine(REVOLUTION_SATURNE, ROTATION_SATURNE, 0);
                ura->deplacementEnUneSemaine(REVOLUTION_URANUS, ROTATION_URANUS, 0);
                nep->deplacementEnUneSemaine(REVOLUTION_NEPTUNE, ROTATION_NEPTUNE, 0);

                handled = true;
        }

        // on souhaite avancer l'animation d'un mois
        if ((e->key()==Qt::Key_M) && (modifiers==Qt::NoButton)) {

                sun->deplacementEnUnMois(1, ROTATION_SOLEIL, 1); // ref. revolution du soleil à 1 pour ne pas avoir une division par 0 lors du calcul de la revolution
                mer->deplacementEnUnMois(REVOLUTION_MERCURE, ROTATION_MERCURE, 1);
                ven->deplacementEnUnMois(REVOLUTION_VENUS, ROTATION_VENUS, 1);
                ear->deplacementEnUnMois(REVOLUTION_TERRE, ROTATION_TERRE, 1);
                lun->deplacementEnUnMois(REVOLUTION_LUNE_TERRE, ROTATION_LUNE, 1);
                mar->deplacementEnUnMois(REVOLUTION_MARS, ROTATION_MARS, 1);
                jup->deplacementEnUnMois(REVOLUTION_JUPITER, ROTATION_JUPITER, 1);
                sat->deplacementEnUnMois(REVOLUTION_SATURNE, ROTATION_SATURNE, 1);
                ura->deplacementEnUnMois(REVOLUTION_URANUS, ROTATION_URANUS, 1);
                nep->deplacementEnUnMois(REVOLUTION_NEPTUNE, ROTATION_NEPTUNE, 1);

                handled = true;
        }
        // on souhaite reculer l'animation d'un mois
        else if ((e->key()==Qt::Key_M) && (modifiers==Qt::SHIFT)) {

                sun->deplacementEnUnMois(1, ROTATION_SOLEIL, 0); // ref. revolution du soleil à 1 pour ne pas avoir une division par 0 lors du calcul de la revolution
                mer->deplacementEnUnMois(REVOLUTION_MERCURE, ROTATION_MERCURE, 0);
                ven->deplacementEnUnMois(REVOLUTION_VENUS, ROTATION_VENUS, 0);
                ear->deplacementEnUnMois(REVOLUTION_TERRE, ROTATION_TERRE, 0);
                lun->deplacementEnUnMois(REVOLUTION_LUNE_TERRE, ROTATION_LUNE, 0);
                mar->deplacementEnUnMois(REVOLUTION_MARS, ROTATION_MARS, 0);
                jup->deplacementEnUnMois(REVOLUTION_JUPITER, ROTATION_JUPITER, 0);
                sat->deplacementEnUnMois(REVOLUTION_SATURNE, ROTATION_SATURNE, 0);
                ura->deplacementEnUnMois(REVOLUTION_URANUS, ROTATION_URANUS, 0);
                nep->deplacementEnUnMois(REVOLUTION_NEPTUNE, ROTATION_NEPTUNE, 0);

                handled = true;
        }




        // ... and so on with other else/if blocks.

        return handled;
}
