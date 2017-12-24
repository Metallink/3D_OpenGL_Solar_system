#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/gl.h>  // OpenGL include file
#include <GL/glut.h>

const char SOLEIL_FICHIER_BMP[] = "../isiviewer_glut/textures/soleil.bmp";
const char MERCURE_FICHIER_BMP[] = "../isiviewer_glut/textures/mercure.bmp";
const char VENUS_FICHIER_BMP[] = "../isiviewer_glut/textures/venus.bmp";
const char TERRE_FICHIER_BMP[] = "../isiviewer_glut/textures/terre.bmp";
const char MARS_FICHIER_BMP[] = "../isiviewer_glut/textures/mars.bmp";
const char JUPITER_FICHIER_BMP[] = "../isiviewer_glut/textures/jupiter.bmp";
const char SATURNE_FICHIER_BMP[] = "../isiviewer_glut/textures/saturne.bmp";
const char URANUS_FICHIER_BMP[] = "../isiviewer_glut/textures/uranus.bmp";
const char NEPTUNE_FICHIER_BMP[] = "../isiviewer_glut/textures/neptune.bmp";

class Texture {

private:
//variables de classe
char* m_data;
int m_width;
int m_height;

public:
//constructeur-destucteur
Texture();
Texture(char* data, int w, int h);
~Texture();

// GETTERS/SETTERS

char* getData();
int getWidth();
int getHeight();

void setData(char *d);
void setWidth(int d);
void setHeight(int h);

// lit les datas d'une image BMP
void readBMP(const char *nomDeFichier);
// charge une texture
GLuint loadTexture();
};

#endif
