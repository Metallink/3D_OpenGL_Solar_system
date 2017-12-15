#include "sample.h"
#ifdef WIN32
#include "windows.h"
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <glm/glm.h>

using namespace glm;

static const GLsizei VertexSize = 4;

static const GLsizei PositionSize = VertexSize * sizeof(vec2);
static const vec2 PositionData[] =
{
	vec2(-1.0f,-1.0f),
	vec2( 1.0f,-1.0f),
	vec2( 1.0f, 1.0f),
	vec2(-1.0f, 1.0f)
};

static const GLsizei ColorSize = VertexSize * sizeof(vec3);
static const vec3 ColorData1[VertexSize] =
{
	vec3(1.0f, 0.0f, 0.0f),
	vec3(1.0f, 1.0f, 0.0f),
	vec3(0.0f, 1.0f, 0.0f),
	vec3(0.0f, 0.0f, 1.0f)
};

static const vec3 ColorData2[VertexSize] =
{
    vec3(0.0f, 0.0f, 1.0f),
	vec3(1.0f, 0.0f, 0.0f),
	vec3(1.0f, 1.0f, 0.0f),
	vec3(0.0f, 1.0f, 0.0f)
};

static vec3 ColorData[VertexSize];

void Begin(int Width, int Height)
{
    // Set projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 640.0f / 480.0f, 0.1f, 100.0f);
}

void End()
{}

void Render(float CurrentTime)
{
    // Set modelview matrix
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f,-4.0f);
    glRotatef(CurrentTime * 5.f, 0.0f, 0.0f, 1.0f);

    // Setup color rotation direction
    static GLboolean Toggle = GL_FALSE;
    Toggle = GLint(CurrentTime) & (1 << 0) ? GL_TRUE : GL_FALSE;

    // Setup color interpolation factor
    GLfloat NewTime = CurrentTime * 0.5f;
    while(NewTime >= 1.0f)
        NewTime -= 1.0f;
    NewTime = clamp(NewTime, 0.0f, 1.0f);

    // Compute color buffer
    if(Toggle == GL_FALSE)
        for(GLint i = 0; i < VertexSize; ++i)
            ColorData[i] = mix(ColorData1[i], ColorData2[i], NewTime);
    else
        for(GLint i = 0; i < VertexSize; ++i)
            ColorData[i] = mix(ColorData2[i], ColorData1[i], NewTime);

    // Render
    glBegin(GL_QUADS);
        for(GLint i = 0; i < 4; ++i)
        {
            glColor3fv(ColorData[i]);
            glVertex2fv(PositionData[i]);
        }
    glEnd();
}
