#include "planete.h"

#include <math.h>
#include <iostream>

#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

Planete::Planete(string name, double radius, double distance, double revolution, double inclinaison, double rotation) {
        m_name = name;
        m_radius = radius;
        m_distance = distance;
        m_revolution = revolution;
        m_inclinaison = inclinaison;
        m_rotation = rotation;
}

Planete::~Planete() {
}

void Planete::deplacementEnUneHeure(double refRevolutionPlanete, double refRotationPlanete, int plusOuMoins) {

        // la ref. de la revolution de la planete sera donnée en jours
        double revolution = (360.0) / (refRevolutionPlanete*24);
        // la ref. de la rotation de la planete sera donnée en heures
        double rotation = (360.0) / refRotationPlanete;

        /* Le soleil est la planete de reference, elle n'a donc pas de revolution mais une rotation: on traite ce cas */
        if (this->getName().compare("Soleil") == 0) {

                // si on souhaite avancer d'une heure
                if (plusOuMoins == 1) {
                        m_rotation += rotation;
                        if (m_rotation > 360.0)
                                m_rotation -= 360.0;
                }
                else if (plusOuMoins == 0) { // ou alors on souhaite reculer d'une heure
                        m_rotation -= rotation;
                        if (m_rotation < 0)
                                m_rotation += 360.0;
                }
        }
        else { // pour les autres planetes

                // si on souhaite avancer d'une heure
                if (plusOuMoins == 1) {
                        m_revolution += revolution;
                        if (m_revolution > 360.0)
                                m_revolution -= 360.0;

                        m_rotation += rotation;
                        if (m_rotation > 360.0)
                                m_rotation -= 360.0;
                }
                else if (plusOuMoins == 0) { // ou alors on souhaite reculer d'une heure
                        m_revolution -= revolution;
                        if (m_revolution < 0)
                                m_revolution += 360.0;

                        m_rotation -= rotation;
                        if (m_rotation < 0)
                                m_rotation += 360.0;
                }
        }
}

void Planete::deplacementEnUnJour(double refRevolutionPlanete, double refRotationPlanete, int plusOuMoins) {

        // la ref. de la revolution de la planete sera donnée en jours
        double revolution = 360.0 / refRevolutionPlanete;
        // la ref. de la rotation de la planete sera donnée en heures
        double rotation = 360.0 / (refRotationPlanete/24);

        // si on souhaite avancer d'un jour
        if (plusOuMoins == 1) {
                m_revolution += revolution;
                if (m_revolution > 360.0)
                        m_revolution -= 360.0;

                m_rotation += rotation;
                if (m_rotation > 360.0)
                        m_rotation -= 360.0;
        }
        else if (plusOuMoins == 0) { // ou alors on souhaite reculer d'un jour
                m_revolution -= revolution;
                if (m_revolution < 0)
                        m_revolution += 360.0;

                m_rotation -= rotation;
                if (m_rotation < 0)
                        m_rotation += 360.0;
        }
}

void Planete::deplacementEnUneSemaine(double refRevolutionPlanete, double refRotationPlanete, int plusOuMoins) {

        // la ref. de la revolution de la planete sera donnée en jours
        double revolution = 360.0 / (refRevolutionPlanete/7);
        // la ref. de la rotation de la planete sera donnée en heures
        double rotation = 360.0 / (refRotationPlanete/(7*24));

        // si on souhaite avancer d'un jour
        if (plusOuMoins == 1) {
                m_revolution += revolution;
                if (m_revolution > 360.0)
                        m_revolution -= 360.0;

                m_rotation += rotation;
                if (m_rotation > 360.0)
                        m_rotation -= 360.0;
        }
        else if (plusOuMoins == 0) { // ou alors on souhaite reculer d'un jour
                m_revolution -= revolution;
                if (m_revolution < 0)
                        m_revolution += 360.0;

                m_rotation -= rotation;
                if (m_rotation < 0)
                        m_rotation += 360.0;
        }
}

void Planete::deplacementEnUnMois(double refRevolutionPlanete, double refRotationPlanete, int plusOuMoins) {

        // la ref. de la revolution de la planete sera donnée en jours
        double revolution = 360.0 / (refRevolutionPlanete/30); // je pars du principe qu'il y'a 30 jours dans un mois
        // la ref. de la rotation de la planete sera donnée en heures
        double rotation = 360.0 / (refRotationPlanete/(30*24));

        // si on souhaite avancer d'un jour
        if (plusOuMoins == 1) {
                m_revolution += revolution;
                if (m_revolution > 360.0)
                        m_revolution -= 360.0;

                m_rotation += rotation;
                if (m_rotation > 360.0)
                        m_rotation -= 360.0;
        }
        else if (plusOuMoins == 0) { // ou alors on souhaite reculer d'un jour
                m_revolution -= revolution;
                if (m_revolution < 0)
                        m_revolution += 360.0;

                m_rotation -= rotation;
                if (m_rotation < 0)
                        m_rotation += 360.0;
        }
}


/* GETTERS */
string Planete::getName() {
        return m_name;
}

double Planete::getRadius() {
        return m_radius;
}

double Planete::getDistance() {
        return m_distance;
}

double Planete::getRevolution() {
        return m_revolution;
}

double Planete::getInclinaison() {
        return m_inclinaison;
}

double Planete::getRotation() {
        return m_rotation;
}

/* SETTERS */
void Planete::setName(string n) {
        m_name = n;
}

void Planete::setRadius(double r) {
        m_radius = r;
}

void Planete::setDistance(double d) {
        m_distance = d;
}

void Planete::setRevolution(double r) {
        m_revolution = r;
}

void Planete::setInclinaison(double i) {
        m_inclinaison = i;
}

void Planete::setRotation(double rr) {
        m_rotation = rr;
}
