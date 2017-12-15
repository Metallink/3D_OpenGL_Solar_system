#include "sample.h"
#ifdef WIN32
#include "windows.h"
#endif
#include <GL/gl.h>
#include <glm/glmext.h>

using namespace glm;

static const GLsizei VertexCount = 6; 
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

static const GLsizei IndexSize = VertexCount * sizeof(GLuint);
static const GLuint IndexData[] =
{
	0, 1, 2, 3, 0, 2
};

void Begin(int Width, int Height)
{
    // Set projection matrix
	glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(perspectiveGTX(45.0f, 640.0f / 480.0f, 0.1f, 100.0f));
}

void End()
{}

void Render(float CurrentTime)
{
    // Set modelview matrix
    mat4 ModelView = translateGTX(0.0f, 0.0f,-4.0f);
    ModelView = rotateGTX(ModelView, CurrentTime * 10.f, 0.0f, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(ModelView);

    // Setup color rotation direction
    static GLboolean Toggle = GL_FALSE;
    Toggle = GLint(CurrentTime) & (1 << 0) ? GL_TRUE : GL_FALSE;

    // Setup color interpolation factor
    GLfloat NewTime = CurrentTime;
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
	glColorPointer(3, GL_FLOAT, 0, ColorData);
	glVertexPointer(2, GL_FLOAT, 0, PositionData);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

	glDrawElements(GL_TRIANGLES, VertexCount, GL_UNSIGNED_INT, IndexData);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}
