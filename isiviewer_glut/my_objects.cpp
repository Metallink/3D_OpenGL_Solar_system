#include "my_objects.h"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <GL/gl.h>  // OpenGL include file

Cube::Cube()
{
        // vertex coordinates
        static const GLfloat ps[8][3] = {{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1},
                                         {-1,-1, 1},{-1,1, 1},{1,1, 1},{1,-1, 1}};

        // triangles vertices
        static const GLint ts[12][3] = {
                // bottom triangles
                {1,2,0},{3,0,2},
                // side triangles
                {1,5,6},{2,1,6},{2,6,3},{3,6,7},{3,7,0},{0,7,4},{0,4,1},{1,4,5},
                // top triangles
                {4,7,5},{7,6,5}
        };

        // normals components
        static const GLfloat ns[12][3] = {
                // bottom triangles
                {0,0,-1},{0,0,-1},
                // side triangles
                {0,1,0},{0,1,0},{1,0,0},{1,0,0},{0,-1,0},{0,-1,0},{-1,0,0},{-1,0,0},
                // top triangles
                {0,0,1},{0,0,1}
        };

        // Fill vertices, triangles and normalsT vectors
        int i;

        // Fill vertex vector
        for (i=0; i<8; ++i)
                _vertices.push_back(glm::vec3(ps[i][0], ps[i][1], ps[i][2]));

        // Fill triangle vector
        for (i=0; i<12; ++i)
                _triangles.push_back(std::vector<int>(ts[i], ts[i+1]));
        // It creates a vector with elements ts[i][0], ts[i][1], ts[i][2]

        // Fill normalsT vector
        for (i=0; i<12; ++i)
                _normalsT.push_back(glm::vec3(ns[i][0], ns[i][1], ns[i][2]));


        // Debug information
        bool debug = true;

        if (debug) {

                using namespace std; // so that writing "std::" is no more necessary

                cout << "Display Cube information" << endl;

                // display components of the first vertex
                cout << endl << "First vertex :" << endl;
                glm::vec3 & vert = _vertices[0];
                cout << vert.x <<"\t"<< vert.y <<"\t"<< vert.z << endl;

                // display components of the firt normal
                cout << endl << "First normal :" << endl;
                glm::vec3 & norm = _normalsT[0];
                cout << norm.x <<"\t"<< norm.y <<"\t"<< norm.z << endl;

                // display indices of the first triangle
                cout << endl << "First triangle :" << endl;
                copy(_triangles[0].begin(), _triangles[0].end(),
                     ostream_iterator<int>(cout, "\t"));
                cout << endl;
                // Ref STL: std::copy ->
                // http://www.sgi.com/tech/stl/copy.html

                // Ref STL: std::ostream_iterator<T> ->
                // http://www.sgi.com/tech/stl/ostream_iterator.html

                cout << endl;
        }

}



/**
 * Draw the cube
 *
 */
void Cube::draw()
{
        int t; // iterator on each triangle;
        int i; // iterator on each vertex indice;

        // for each triangle
        for(t=0; t<12; ++t) {

                //printf("triangle %d\n", t);

                // start drawing triangles
                glBegin(GL_TRIANGLES);

                // send normals to OpenGL
                glNormal3fv(_normalsT[t]);

                //std::cout << "normal: " << _normalsT[t] << std::endl;

                // for each vertex index for the current triangle
                for(i=0; i<3; i++) {

                        // send vertices components to OpenGL
                        glVertex3fv(_vertices[_triangles[t][i]]);

                        //std::cout << "vertex: " << _vertices[_triangles[t][i]] << std::endl;

                } // end for each vertex

                // stop drawing triangles
                glEnd();

        } // end for each triangle
}
