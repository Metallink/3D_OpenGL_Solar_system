#include <assert.h>
#include <fstream>
#include <GL/gl.h>  // OpenGL include file
#include <GL/glut.h>

#include "texture.h"

using namespace std;


Texture::Texture() {

}

Texture::Texture(char* data, int w, int h) : m_data(data), m_width(w), m_height(h) {

}

Texture::~Texture() {
								delete[] m_data;
}

namespace {
//Converts a four-character array to an integer, using little-endian form
int toInt(const char* bytes) {
								return (int)(((unsigned char)bytes[3] << 24) |
																					((unsigned char)bytes[2] << 16) |
																					((unsigned char)bytes[1] << 8) |
																					(unsigned char)bytes[0]);
}

//Converts a two-character array to a short, using little-endian form
short toShort(const char* bytes) {
								return (short)(((unsigned char)bytes[1] << 8) |
																							(unsigned char)bytes[0]);
}

//Reads the next four bytes as an integer, using little-endian form
int readInt(ifstream &input) {
								char buffer[4];
								input.read(buffer, 4);
								return toInt(buffer);
}

//Reads the next two bytes as a short, using little-endian form
short readShort(ifstream &input) {
								char buffer[2];
								input.read(buffer, 2);
								return toShort(buffer);
}

//Just like auto_ptr, but for arrays
template<class T>
class auto_array {
private:
T* array;
mutable bool isReleased;
public:
explicit auto_array(T* array_ = NULL) :
								array(array_), isReleased(false) {
}

auto_array(const auto_array<T> &aarray) {
								array = aarray.array;
								isReleased = aarray.isReleased;
								aarray.isReleased = true;
}

~auto_array() {
								if (!isReleased && array != NULL) {
																delete[] array;
								}
}

T* get() const {
								return array;
}

T &operator*() const {
								return *array;
}

void operator=(const auto_array<T> &aarray) {
								if (!isReleased && array != NULL) {
																delete[] array;
								}
								array = aarray.array;
								isReleased = aarray.isReleased;
								aarray.isReleased = true;
}

T* operator->() const {
								return array;
}

T* release() {
								isReleased = true;
								return array;
}

void reset(T* array_ = NULL) {
								if (!isReleased && array != NULL) {
																delete[] array;
								}
								array = array_;
}

T* operator+(int i) {
								return array + i;
}

T &operator[](int i) {
								return array[i];
}
};

} // end namespace

// GETTERS/SETTERS

char* Texture::getData() {
								return m_data;
}

int Texture::getWidth() {
								return m_width;
}

int Texture::getHeight() {
								return m_height;
}

void Texture::setData(char *d) {
								m_data = d;
}

void Texture::setWidth(int d) {
								m_width = d;
}

void Texture::setHeight(int h) {
								m_height = h;
}


void Texture::readBMP(const char *nomDeFichier) {

								ifstream input(nomDeFichier, ios::binary);
								assert(!input.fail() || !"Could not find file");
								char buffer[2];
								input.read(buffer, 2);
								assert(buffer[0] == 'B' && buffer[1] == 'M' || !"Not a bitmap file");
								input.ignore(8);
								int dataOffset = readInt(input);

								//Read the header
								int headerSize = readInt(input);
								//int width;
								//int height;
								switch (headerSize) {
								case 40:
																//V3
																this->setWidth(readInt(input));
																this->setHeight(readInt(input));
																input.ignore(2);
																assert(readShort(input) == 24 || !"Texture is not 24 bits per pixel");
																assert(readShort(input) == 0 || !"Image is compressed");
																break;
								case 12:
																//OS/2 V1
																this->setWidth(readShort(input));
																this->setHeight(readShort(input));
																input.ignore(2);
																assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
																break;
								case 64:
																//OS/2 V2
																assert(!"Can't load OS/2 V2 bitmaps");
																break;
								case 108:
																//Windows V4
																assert(!"Can't load Windows V4 bitmaps");
																break;
								case 124:
																//Windows V5
																assert(!"Can't load Windows V5 bitmaps");
																break;
								default:

																assert(!"Unknown bitmap format");
								}

								//Read the data
								int bytesPerRow = ((this->getWidth() * 3 + 3) / 4) * 4 - (this->getWidth() * 3 % 4);
								int size = bytesPerRow * this->getHeight();
								auto_array<char> pixels(new char[size]);
								input.seekg(dataOffset, ios_base::beg);
								input.read(pixels.get(), size);

								//Get the data into the right format
								auto_array<char> pixels2(new char[this->getWidth() * this->getHeight() * 3]);
								for (int y = 0; y < this->getHeight(); y++) {
																for (int x = 0; x < this->getWidth(); x++) {
																								for (int c = 0; c < 3; c++) {
																																pixels2[3 * (this->getWidth() * y + x) + c] =
																																								pixels[bytesPerRow * y + 3 * x + (2 - c)];
																								}
																}
								}

								this->setData(pixels2.release());
								input.close();
								//return new Texture(pixels2.release(), width, height);
}


GLuint Texture::loadTexture() {
								// NOTE: http://www.codeincodeblock.com/2012/05/simple-method-for-texture-mapping-on.html
								GLuint textureId;
								glGenTextures(1, &textureId);
								glBindTexture(GL_TEXTURE_2D, textureId);
								glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_data);
								return textureId;
}
