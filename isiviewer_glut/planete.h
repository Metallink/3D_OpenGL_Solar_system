
#ifndef PLANETE_H
#define PLANETE_H

/* http://www.planetesdelyvette.u-psud.fr/spip.php?article47 */
/* Ex: rayon de mercure = diametre/2 -> 0.5cm/2 = 0.25; etc.. pour les autres*/
const double RADIUS_SOLEIL = 10;    // non proportionel
const double RADIUS_MERCURE = 0.25;
const double RADIUS_VENUS = 0.6;
const double RADIUS_TERRE = 0.65;
const double RADIUS_LUNE = 0.15;
const double RADIUS_MARS = 0.35;
const double RADIUS_JUPITER = 7.15;
const double RADIUS_SATURNE = 6.05;
const double RADIUS_URANUS = 2.55;
const double RADIUS_NEPTUNE = 2.5;

/* distance par rapport au soleil (non proportionel à la réalité) */
const int DISTANCE_SOLEIL = 0;
const int DISTANCE_MERCURE = 17;
const int DISTANCE_VENUS = 20;
const int DISTANCE_TERRE = 25;
const int DISTANCE_LUNE = 1; // distance de la lune par rapport à la terre
const int DISTANCE_MARS = 30;
const int DISTANCE_JUPITER = 42;
const int DISTANCE_SATURNE = 59;
const int DISTANCE_URANUS = 70;
const int DISTANCE_NEPTUNE = 78;

//
// Planete *mer = new Planete (0.25, 17, 0, 4.74, 02.11, 0);
// Planete *ven = new Planete (0.6, 20, 0, 3.50, 177.0, 0);
// Planete *ear = new Planete (0.65, 25, 0, 2.98, 23.44, 0);
// Planete *mar = new Planete (0.35, 30, 0, 2.41, 25.00, 0);
// Planete *jup = new Planete (7.15, 42, 0, 1.31, 03.13, 0);
// Planete *sat = new Planete (6.05, 59, 0, 0.97, 26.70, 0);
// Planete *ura = new Planete (2.55, 70, 0, 0.68, 97.77, 0);
// Planete *nep = new Planete (2.5, 78, 0, 0.54, 28.32, 0);
// Planete *lun = new Planete (0.15, 1, 0, 5.40, 0, 0);

class Planete {
private:

double m_radius;
double m_distance;
double m_orbit;
double m_orbitSpeed;
double m_axisTilt;
double m_axisAni;

public:
// constructeur-destructeur
Planete(double radius, double distance, double orbit, double orbitSpeed, double axisTilt, double axisAni);
~Planete();

// GETTERS/SETTERS

double getRadius();
double getDistance();
double getOrbit();
double getOrbitSpeed();
double getAxisTilt();
double getAxisAni();

void setRadius(double r);
void setDistance(double d);
void setOrbit(double o);
void setOrbitSpeed(double os);
void setAxisTilt(double at);
void setAxisAni(double aa);


void animate();
void dessinerOrbite();
void drawMoon();

};


 #endif
