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
GLuint soleilTexture, mercureTexture, venusTexture, terreTexture, luneTexture, marsTexture, jupiterTexture, saturneTexture, uranusTexture, neptuneTexture, espaceTexture, saturneRingTexture;
int activerTexture = 1; // active ou non les textures

/*****************************************************/
/**       INITIALISATION DES OBJETS "PLANETE"       **/
/*****************************************************/
/* Les dimensions des planeetes ont été respecté sauf pour le soleil en se basant sur les diametres de la maquette du lien fourni dans le sujet.*/
/* De plus, les distances n'ont pas été respecté comme specifié dans le sujet. J'ai fait en sorte que les planetes soient equidistantes.*/

/* RAPPEL CONSTRUCTEUR DE LA CLASSE PLANETE */
/*Planete(string name, double radius, double distance, double revolution, double inclinaison, double rotation); */

Planete *soleil = new Planete ("Soleil", RADIUS_SOLEIL, DISTANCE_SOLEIL, 0, 0, 0); // radius du soleil non respecté sinon beaucoup trop grand par rapport aux autres planetes
Planete *mercure = new Planete ("Mercure", RADIUS_MERCURE, DISTANCE_MERCURE, 0, INCLINAISON_MERCURE, 0);
Planete *venus = new Planete ("Venus", RADIUS_VENUS, DISTANCE_VENUS, 0, INCLINAISON_VENUS, 0);
Planete *terre = new Planete ("Terre", RADIUS_TERRE, DISTANCE_TERRE, 0, INCLINAISON_TERRE, 0);
Planete *lune = new Planete ("Lune", RADIUS_LUNE, DISTANCE_LUNE, 0, INCLINAISON_LUNE, 0);
Planete *mars = new Planete ("Mars", RADIUS_MARS, DISTANCE_MARS, 0, INCLINAISON_MARS, 0);
Planete *jupiter = new Planete ("Jupiter", RADIUS_JUPITER, DISTANCE_JUPITER, 0, INCLINAISON_JUPITER, 0);
Planete *saturne = new Planete ("Saturne", RADIUS_SATURNE, DISTANCE_SATURNE, 0, INCLINAISON_SATURNE, 0);
Planete *uranus = new Planete ("Uranus", RADIUS_URANUS, DISTANCE_URANUS, 0, INCLINAISON_URANUS, 0);
Planete *neptune = new Planete ("Neptune", RADIUS_NEPTUNE, DISTANCE_NEPTUNE, 0, INCLINAISON_NEPTUNE, 0);



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
        glEnable(GL_CULL_FACE); // n'affiche pas les vertices qui ne ne sont pas visibles
        glEnable(GL_NORMALIZE); // normalize normal vectors when objects are scaled
        glEnable(GL_COLOR_MATERIAL);


        /*****************************************************/
        /**             CHARGEMENT DES TEXTURES             **/
        /*****************************************************/

        Texture *espace = new Texture();
        espace->readBMP(GALAXIE_FICHIER_BMP);
        espaceTexture = espace->loadTexture();
        delete espace;

        Texture *soleil = new Texture();
        soleil->readBMP(SOLEIL_FICHIER_BMP);
        soleilTexture = soleil->loadTexture();
        delete soleil;

        Texture *mercure = new Texture();
        mercure->readBMP(MERCURE_FICHIER_BMP);
        mercureTexture = mercure->loadTexture();
        delete mercure;

        Texture *venus = new Texture();
        venus->readBMP(VENUS_FICHIER_BMP);
        venusTexture = venus->loadTexture();
        delete venus;

        Texture *terre = new Texture();
        terre->readBMP(TERRE_FICHIER_BMP);
        terreTexture = terre->loadTexture();
        delete terre;

        Texture *lune = new Texture();
        lune->readBMP(LUNE_FICHIER_BMP);
        luneTexture = lune->loadTexture();
        delete lune;

        Texture *mars = new Texture();
        mars->readBMP(MARS_FICHIER_BMP);
        marsTexture = mars->loadTexture();
        delete mars;

        Texture *jupiter = new Texture();
        jupiter->readBMP(JUPITER_FICHIER_BMP);
        jupiterTexture = jupiter->loadTexture();
        delete jupiter;

        Texture *saturne = new Texture();
        saturne->readBMP(SATURNE_FICHIER_BMP);
        saturneTexture = saturne->loadTexture();
        delete saturne;

        Texture *anneau_saturne = new Texture();
        anneau_saturne->readBMP(SATURNE_ANNEAUX_FICHIER_BMP);
        saturneRingTexture = anneau_saturne->loadTexture();
        delete anneau_saturne;

        Texture *uranus = new Texture();
        uranus->readBMP(URANUS_FICHIER_BMP);
        uranusTexture = uranus->loadTexture();
        delete uranus;

        Texture *neptune = new Texture();
        neptune->readBMP(NEPTUNE_FICHIER_BMP);
        neptuneTexture = neptune->loadTexture();
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

                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(soleil->getRevolution(), 0.0, 1.0, 0.0);
                glTranslatef(soleil->getDistance(), 0.0, 0.0);

                /*****************************************************/
                /**       ON AFFICHE LES ORBITES DES PLANETES       **/
                /*****************************************************/
                glPushMatrix();
                glColor3ub(255, 255, 255);
                glRotated(90.0, 1.0, 0.0, 0.0);
                glutWireTorus(0.001, mercure->getDistance(), 100.0, 100.0);
                glutWireTorus(0.001, venus->getDistance(), 100.0, 100.0);
                glutWireTorus(0.001, terre->getDistance(), 100.0, 100.0);
                glutWireTorus(0.001, mars->getDistance(), 100.0, 100.0);
                glutWireTorus(0.001, jupiter->getDistance(), 100.0, 100.0);
                glutWireTorus(0.001, saturne->getDistance(), 100.0, 100.0);
                glutWireTorus(0.001, uranus->getDistance(), 100.0, 100.0);
                glutWireTorus(0.001, neptune->getDistance(), 100.0, 100.0);
                glPopMatrix();

                /*****************************************************/
                /**                  SOLEIL                         **/
                /*****************************************************/

                glPushMatrix();
                glRotatef(soleil->getInclinaison(), 1.0, 0.0, 0.0);
                glRotatef(soleil->getRotation(), 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                if (activerTexture) { // affiche la texture si on appuie sur la touche t
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D, soleilTexture);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                        gluQuadricTexture(quadric, 1);
                        gluSphere(quadric, soleil->getRadius(), 20.0, 20.0);
                        glDisable(GL_TEXTURE_2D);
                } else { // sinon on affiche la planete en fil de fer avec une couleur caracteristique unique
                        glColor3ub(249, 242, 27);
                        glutWireSphere(soleil->getRadius(), 20.0,20.0);
                }
                glPopMatrix();
                glPopMatrix();

                /*****************************************************/
                /**                  MERCURE                        **/
                /*****************************************************/

                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(mercure->getRevolution(), 0.0, 1.0, 0.0);
                glTranslatef(mercure->getDistance(), 0.0, 0.0);

                glPushMatrix();
                glRotatef(mercure->getInclinaison(), 1.0, 0.0, 0.0);
                glRotatef(mercure->getRotation(), 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                if (activerTexture) { // affiche la texture si on appuie sur la touche t
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D, mercureTexture);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                        gluQuadricTexture(quadric, 1);
                        gluSphere(quadric, mercure->getRadius(), 20.0, 20.0);
                        glDisable(GL_TEXTURE_2D);
                } else { // sinon on affiche la planete en fil de fer avec une couleur caracteristique unique
                        glColor3ub(178, 166, 166);
                        glutWireSphere(mercure->getRadius(), 20.0,20.0);
                }
                glPopMatrix();
                glPopMatrix();

                /*****************************************************/
                /**                     VENUS                       **/
                /*****************************************************/
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(venus->getRevolution(), 0.0, 1.0, 0.0);
                glTranslatef(venus->getDistance(), 0.0, 0.0);

                glPushMatrix();
                glRotatef(venus->getInclinaison(), 1.0, 0.0, 0.0);
                glRotatef(venus->getRotation(), 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                if (activerTexture) { // affiche la texture si on appuie sur la touche t
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D, venusTexture);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                        gluQuadricTexture(quadric, 1);
                        gluSphere(quadric, venus->getRadius(), 20.0, 20.0);
                        glDisable(GL_TEXTURE_2D);
                } else { // sinon on affiche la planete en fil de fer avec une couleur caracteristique unique
                        glColor3ub(232, 80, 4);
                        glutWireSphere(venus->getRadius(), 20.0,20.0);
                }
                glPopMatrix();
                glPopMatrix();

                /*****************************************************/
                /**                    TERRE                        **/
                /*****************************************************/
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(terre->getRevolution(), 0.0, 1.0, 0.0);
                glTranslatef(terre->getDistance(), 0.0, 0.0);

                glPushMatrix();
                glRotatef(terre->getInclinaison(), 1.0, 0.0, 0.0);
                glRotatef(terre->getRotation(), 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                if (activerTexture) { // affiche la texture si on appuie sur la touche t
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D, terreTexture);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                        gluQuadricTexture(quadric, 1);
                        gluSphere(quadric, terre->getRadius(), 20.0, 20.0);
                        glDisable(GL_TEXTURE_2D);
                } else { // sinon on affiche la planete en fil de fer avec une couleur caracteristique unique
                        glColor3ub(4, 88, 206);
                        glutWireSphere(terre->getRadius(), 20.0,20.0);
                }
                glPopMatrix();

                /*****************************************************/
                /**                    LUNE                         **/
                /*****************************************************/
                // On trace l'orbite de la lune
                glPushMatrix();
                glColor3ub(255, 255, 255);
                glRotated(90.0, 1.0, 0.0, 0.0);
                glutWireTorus(0.001, lune->getDistance(), 100.0, 100.0);
                glPopMatrix();
                glPushMatrix();
                glColor3ub(255, 255, 255);
                glRotatef(lune->getRevolution(), 0.0, 1.0, 0.0);
                glTranslatef(lune->getDistance(), 0.0, 0.0);
                if (activerTexture) { // affiche la texture si on appuie sur la touche t
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D, luneTexture);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                        gluQuadricTexture(quadric, 1);
                        gluSphere(quadric, lune->getRadius(), 20.0, 20.0);
                        glDisable(GL_TEXTURE_2D);
                } else { // sinon on affiche la planete en fil de fer avec une couleur caracteristique unique
                        glColor3ub(225, 232, 242);
                        glutWireSphere(lune->getRadius(), 20.0,20.0);
                }
                glPopMatrix();
                glPopMatrix();

                /*****************************************************/
                /**                     MARS                        **/
                /*****************************************************/
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(mars->getRevolution(), 0.0, 1.0, 0.0);
                glTranslatef(mars->getDistance(), 0.0, 0.0);

                glPushMatrix();
                glRotatef(mars->getInclinaison(), 1.0, 0.0, 0.0);
                glRotatef(mars->getRotation(), 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                if (activerTexture) { // affiche la texture si on appuie sur la touche t
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D, marsTexture);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                        gluQuadricTexture(quadric, 1);
                        gluSphere(quadric, mars->getRadius(), 20.0, 20.0);
                        glDisable(GL_TEXTURE_2D);
                } else { // sinon on affiche la planete en fil de fer avec une couleur caracteristique unique
                        glColor3ub(183, 51, 11);
                        glutWireSphere(mars->getRadius(), 20.0,20.0);
                }
                glPopMatrix();
                glPopMatrix();

                /*****************************************************/
                /**                    JUPITER                      **/
                /*****************************************************/
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(jupiter->getRevolution(), 0.0, 1.0, 0.0);
                glTranslatef(jupiter->getDistance(), 0.0, 0.0);

                glPushMatrix();
                glRotatef(jupiter->getInclinaison(), 1.0, 0.0, 0.0);
                glRotatef(jupiter->getRotation(), 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                if (activerTexture) { // affiche la texture si on appuie sur la touche t
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D, jupiterTexture);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                        gluQuadricTexture(quadric, 1);
                        gluSphere(quadric, jupiter->getRadius(), 20.0, 20.0);
                        glDisable(GL_TEXTURE_2D);
                } else { // sinon on affiche la planete en fil de fer avec une couleur caracteristique unique
                        glColor3ub(237, 136, 21);
                        glutWireSphere(jupiter->getRadius(), 20.0,20.0);
                }
                glPopMatrix();
                glPopMatrix();

                /*****************************************************/
                /**                  SATURNE                        **/
                /*****************************************************/
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(saturne->getRevolution(), 0.0, 1.0, 0.0);
                glTranslatef(saturne->getDistance(), 0.0, 0.0);
                glPushMatrix();
                glRotatef(saturne->getInclinaison(), 1.0, 0.0, 0.0);
                glRotatef(saturne->getRotation(), 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                if (activerTexture) { // affiche la texture si on appuie sur la touche t
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D, saturneTexture);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                        gluQuadricTexture(quadric, 1);
                        gluSphere(quadric, saturne->getRadius(), 20.0, 20.0);
                        glPopMatrix();
                        glDisable(GL_TEXTURE_2D);
                        // ANNEAUX DE SATURNE
                        //COMBAK: ANNEAUX BOF, VOIR SI JE PEUX AMELIORER CA
                        //NOTE: https://learnopengl.com/#!Advanced-OpenGL/Instancing
                        glPushMatrix();
                        glRotatef(-66.0, 1.0, 0.0, 0.0);
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D, saturneRingTexture);
                        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                        gluQuadricTexture(quadric, 1);
                        gluQuadricDrawStyle(quadric, GLU_FILL);
                        gluDisk(quadric, saturne->getRadius()+0.65, saturne->getRadius()+2.3, 30.0, 30.0);
                } else { // sinon on affiche la planete en fil de fer avec une couleur caracteristique unique
                        glColor3ub(242, 177, 104);
                        glutWireSphere(saturne->getRadius(), 20.0,20.0);
                        glPopMatrix();
                        glPushMatrix();
                        glColor3ub(158, 145, 137);
                        glRotatef(-63.0, 1.0, 0.0, 0.0);
                        //glutWireTorus(0.2, 8.0, 30.0, 30.0);
                        glutWireTorus(0.4, 7.0, 30.0, 30.0);
                }
                glPopMatrix();
                glPopMatrix();

                glColor3ub(255, 255, 255); //BUG: "SHADING ISSUE"

                /*****************************************************/
                /**                   URANUS                        **/
                /*****************************************************/
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(uranus->getRevolution(), 0.0, 1.0, 0.0);
                glTranslatef(uranus->getDistance(), 0.0, 0.0);

                glPushMatrix();
                glRotatef(uranus->getInclinaison(), 1.0, 0.0, 0.0);
                glRotatef(uranus->getRotation(), 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                if (activerTexture) { // affiche la texture si on appuie sur la touche t
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D, uranusTexture);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                        gluQuadricTexture(quadric, 1);
                        gluSphere(quadric, uranus->getRadius(), 20.0, 20.0);
                        glDisable(GL_TEXTURE_2D);
                } else { // sinon on affiche la planete en fil de fer avec une couleur caracteristique unique
                        glColor3ub(52, 227, 237);
                        glutWireSphere(uranus->getRadius(), 20.0,20.0);
                }
                glPopMatrix();
                glPopMatrix();

                /*****************************************************/
                /**                  NEPTUNE                        **/
                /*****************************************************/
                glPushMatrix();
                glScalef(0.1,0.1,0.1);
                glRotatef(neptune->getRevolution(), 0.0, 1.0, 0.0);
                glTranslatef(neptune->getDistance(), 0.0, 0.0);

                glPushMatrix();
                glRotatef(neptune->getInclinaison(), 1.0, 0.0, 0.0);
                glRotatef(neptune->getRotation(), 0.0, 1.0, 0.0);
                glRotatef(90.0, 1.0, 0.0, 0.0);
                if (activerTexture) { // affiche la texture si on appuie sur la touche t
                        glEnable(GL_TEXTURE_2D);
                        glBindTexture(GL_TEXTURE_2D, neptuneTexture);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                        gluQuadricTexture(quadric, 1);
                        gluSphere(quadric, neptune->getRadius(), 20.0, 20.0);
                        glDisable(GL_TEXTURE_2D);
                } else { // sinon on affiche la planete en fil de fer avec une couleur caracteristique unique
                        glColor3ub(25, 112, 193);
                        glutWireSphere(neptune->getRadius(), 20.0,20.0);
                }
                glPopMatrix();
                glPopMatrix();
        }
        glPopMatrix();

        /*****************************************************/
        /**                  SKYBOX ESPACE                  **/
        /*****************************************************/
        //FIXME: POURQUOI IL Y'A UN ROND NOIR???
        glPushMatrix();
        glScalef(0.1,0.1,0.1);
        glTranslatef(0.0, 0.0, 0.0);
        if (activerTexture) { // affiche la texture avec les étoiles si on appuie sur la touche t
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, espaceTexture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gluQuadricOrientation(quadric,GLU_INSIDE);
                gluQuadricTexture(quadric, 1);
                gluSphere(quadric, 15, 20.0, 20.0);
                glDisable(GL_TEXTURE_2D);
        } // sinon il n'y a rien, que du noir

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

                soleil->deplacementEnUneHeure(1, ROTATION_SOLEIL, 1); // ref. revolution du soleil à 1 pour ne pas avoir une division par 0 lors du calcul de la revolution
                mercure->deplacementEnUneHeure(REVOLUTION_MERCURE, ROTATION_MERCURE, 1);
                venus->deplacementEnUneHeure(REVOLUTION_VENUS, ROTATION_VENUS, 1);
                terre->deplacementEnUneHeure(REVOLUTION_TERRE, ROTATION_TERRE, 1);
                lune->deplacementEnUneHeure(REVOLUTION_LUNE_TERRE, ROTATION_LUNE, 1);
                mars->deplacementEnUneHeure(REVOLUTION_MARS, ROTATION_MARS, 1);
                jupiter->deplacementEnUneHeure(REVOLUTION_JUPITER, ROTATION_JUPITER, 1);
                saturne->deplacementEnUneHeure(REVOLUTION_SATURNE, ROTATION_SATURNE, 1);
                uranus->deplacementEnUneHeure(REVOLUTION_URANUS, ROTATION_URANUS, 1);
                neptune->deplacementEnUneHeure(REVOLUTION_NEPTUNE, ROTATION_NEPTUNE, 1);

                handled = true;
        }
        // on souhaite reculer l'animation d'une heure
        else if ((e->key()==Qt::Key_H) && (modifiers==Qt::SHIFT)) {

                soleil->deplacementEnUneHeure(1, ROTATION_SOLEIL, 0); // ref. revolution du soleil à 1 pour ne pas avoir une division par 0 lors du calcul de la revolution
                mercure->deplacementEnUneHeure(REVOLUTION_MERCURE, ROTATION_MERCURE, 0);
                venus->deplacementEnUneHeure(REVOLUTION_VENUS, ROTATION_VENUS, 0);
                terre->deplacementEnUneHeure(REVOLUTION_TERRE, ROTATION_TERRE, 0);
                lune->deplacementEnUneHeure(REVOLUTION_LUNE_TERRE, ROTATION_LUNE, 0);
                mars->deplacementEnUneHeure(REVOLUTION_MARS, ROTATION_MARS, 0);
                jupiter->deplacementEnUneHeure(REVOLUTION_JUPITER, ROTATION_JUPITER, 0);
                saturne->deplacementEnUneHeure(REVOLUTION_SATURNE, ROTATION_SATURNE, 0);
                uranus->deplacementEnUneHeure(REVOLUTION_URANUS, ROTATION_URANUS, 0);
                neptune->deplacementEnUneHeure(REVOLUTION_NEPTUNE, ROTATION_NEPTUNE, 0);

                handled = true;
        }

        // on souhaite avancer l'animation d'un jour
        if ((e->key()==Qt::Key_J) && (modifiers==Qt::NoButton)) {

                soleil->deplacementEnUnJour(1, ROTATION_SOLEIL, 1); // ref. revolution du soleil à 1 pour ne pas avoir une division par 0 lors du calcul de la revolution
                mercure->deplacementEnUnJour(REVOLUTION_MERCURE, ROTATION_MERCURE, 1);
                venus->deplacementEnUnJour(REVOLUTION_VENUS, ROTATION_VENUS, 1);
                terre->deplacementEnUnJour(REVOLUTION_TERRE, ROTATION_TERRE, 1);
                lune->deplacementEnUnJour(REVOLUTION_LUNE_TERRE, ROTATION_LUNE, 1);
                mars->deplacementEnUnJour(REVOLUTION_MARS, ROTATION_MARS, 1);
                jupiter->deplacementEnUnJour(REVOLUTION_JUPITER, ROTATION_JUPITER, 1);
                saturne->deplacementEnUnJour(REVOLUTION_SATURNE, ROTATION_SATURNE, 1);
                uranus->deplacementEnUnJour(REVOLUTION_URANUS, ROTATION_URANUS, 1);
                neptune->deplacementEnUnJour(REVOLUTION_NEPTUNE, ROTATION_NEPTUNE, 1);

                handled = true;
        }
        // on souhaite reculer l'animation d'un jour
        else if ((e->key()==Qt::Key_J) && (modifiers==Qt::SHIFT)) {

                soleil->deplacementEnUnJour(1, ROTATION_SOLEIL, 0); // ref. revolution du soleil à 1 pour ne pas avoir une division par 0 lors du calcul de la revolution
                mercure->deplacementEnUnJour(REVOLUTION_MERCURE, ROTATION_MERCURE, 0);
                venus->deplacementEnUnJour(REVOLUTION_VENUS, ROTATION_VENUS, 0);
                terre->deplacementEnUnJour(REVOLUTION_TERRE, ROTATION_TERRE, 0);
                lune->deplacementEnUnJour(REVOLUTION_LUNE_TERRE, ROTATION_LUNE, 0);
                mars->deplacementEnUnJour(REVOLUTION_MARS, ROTATION_MARS, 0);
                jupiter->deplacementEnUnJour(REVOLUTION_JUPITER, ROTATION_JUPITER, 0);
                saturne->deplacementEnUnJour(REVOLUTION_SATURNE, ROTATION_SATURNE, 0);
                uranus->deplacementEnUnJour(REVOLUTION_URANUS, ROTATION_URANUS, 0);
                neptune->deplacementEnUnJour(REVOLUTION_NEPTUNE, ROTATION_NEPTUNE, 0);

                handled = true;
        }

        // on souhaite avancer l'animation d'une semaine
        if ((e->key()==Qt::Key_S) && (modifiers==Qt::NoButton)) {

                soleil->deplacementEnUneSemaine(1, ROTATION_SOLEIL, 1); // ref. revolution du soleil à 1 pour ne pas avoir une division par 0 lors du calcul de la revolution
                mercure->deplacementEnUneSemaine(REVOLUTION_MERCURE, ROTATION_MERCURE, 1);
                venus->deplacementEnUneSemaine(REVOLUTION_VENUS, ROTATION_VENUS, 1);
                terre->deplacementEnUneSemaine(REVOLUTION_TERRE, ROTATION_TERRE, 1);
                lune->deplacementEnUneSemaine(REVOLUTION_LUNE_TERRE, ROTATION_LUNE, 1);
                mars->deplacementEnUneSemaine(REVOLUTION_MARS, ROTATION_MARS, 1);
                jupiter->deplacementEnUneSemaine(REVOLUTION_JUPITER, ROTATION_JUPITER, 1);
                saturne->deplacementEnUneSemaine(REVOLUTION_SATURNE, ROTATION_SATURNE, 1);
                uranus->deplacementEnUneSemaine(REVOLUTION_URANUS, ROTATION_URANUS, 1);
                neptune->deplacementEnUneSemaine(REVOLUTION_NEPTUNE, ROTATION_NEPTUNE, 1);

                handled = true;
        }
        // on souhaite reculer l'animation d'une semaine
        else if ((e->key()==Qt::Key_S) && (modifiers==Qt::SHIFT)) {

                soleil->deplacementEnUneSemaine(1, ROTATION_SOLEIL, 0); // ref. revolution du soleil à 1 pour ne pas avoir une division par 0 lors du calcul de la revolution
                mercure->deplacementEnUneSemaine(REVOLUTION_MERCURE, ROTATION_MERCURE, 0);
                venus->deplacementEnUneSemaine(REVOLUTION_VENUS, ROTATION_VENUS, 0);
                terre->deplacementEnUneSemaine(REVOLUTION_TERRE, ROTATION_TERRE, 0);
                lune->deplacementEnUneSemaine(REVOLUTION_LUNE_TERRE, ROTATION_LUNE, 0);
                mars->deplacementEnUneSemaine(REVOLUTION_MARS, ROTATION_MARS, 0);
                jupiter->deplacementEnUneSemaine(REVOLUTION_JUPITER, ROTATION_JUPITER, 0);
                saturne->deplacementEnUneSemaine(REVOLUTION_SATURNE, ROTATION_SATURNE, 0);
                uranus->deplacementEnUneSemaine(REVOLUTION_URANUS, ROTATION_URANUS, 0);
                neptune->deplacementEnUneSemaine(REVOLUTION_NEPTUNE, ROTATION_NEPTUNE, 0);

                handled = true;
        }

        // on souhaite avancer l'animation d'un mois
        if ((e->key()==Qt::Key_M) && (modifiers==Qt::NoButton)) {

                soleil->deplacementEnUnMois(1, ROTATION_SOLEIL, 1); // ref. revolution du soleil à 1 pour ne pas avoir une division par 0 lors du calcul de la revolution
                mercure->deplacementEnUnMois(REVOLUTION_MERCURE, ROTATION_MERCURE, 1);
                venus->deplacementEnUnMois(REVOLUTION_VENUS, ROTATION_VENUS, 1);
                terre->deplacementEnUnMois(REVOLUTION_TERRE, ROTATION_TERRE, 1);
                lune->deplacementEnUnMois(REVOLUTION_LUNE_TERRE, ROTATION_LUNE, 1);
                mars->deplacementEnUnMois(REVOLUTION_MARS, ROTATION_MARS, 1);
                jupiter->deplacementEnUnMois(REVOLUTION_JUPITER, ROTATION_JUPITER, 1);
                saturne->deplacementEnUnMois(REVOLUTION_SATURNE, ROTATION_SATURNE, 1);
                uranus->deplacementEnUnMois(REVOLUTION_URANUS, ROTATION_URANUS, 1);
                neptune->deplacementEnUnMois(REVOLUTION_NEPTUNE, ROTATION_NEPTUNE, 1);

                handled = true;
        }
        // on souhaite reculer l'animation d'un mois
        else if ((e->key()==Qt::Key_M) && (modifiers==Qt::SHIFT)) {

                soleil->deplacementEnUnMois(1, ROTATION_SOLEIL, 0); // ref. revolution du soleil à 1 pour ne pas avoir une division par 0 lors du calcul de la revolution
                mercure->deplacementEnUnMois(REVOLUTION_MERCURE, ROTATION_MERCURE, 0);
                venus->deplacementEnUnMois(REVOLUTION_VENUS, ROTATION_VENUS, 0);
                terre->deplacementEnUnMois(REVOLUTION_TERRE, ROTATION_TERRE, 0);
                lune->deplacementEnUnMois(REVOLUTION_LUNE_TERRE, ROTATION_LUNE, 0);
                mars->deplacementEnUnMois(REVOLUTION_MARS, ROTATION_MARS, 0);
                jupiter->deplacementEnUnMois(REVOLUTION_JUPITER, ROTATION_JUPITER, 0);
                saturne->deplacementEnUnMois(REVOLUTION_SATURNE, ROTATION_SATURNE, 0);
                uranus->deplacementEnUnMois(REVOLUTION_URANUS, ROTATION_URANUS, 0);
                neptune->deplacementEnUnMois(REVOLUTION_NEPTUNE, ROTATION_NEPTUNE, 0);

                handled = true;
        }

        // affichage des textures
        if ((e->key()==Qt::Key_T) && (modifiers==Qt::NoButton)) {

                if (activerTexture)
                        activerTexture = 0;
                else
                        activerTexture = 1;

        }
        // ... and so on with other else/if blocks.

        return handled;
}
