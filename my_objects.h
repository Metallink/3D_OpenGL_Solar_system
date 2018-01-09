/**
 * @file   my_objects.h
 * @author Bruno Jobard
 * @author Author1
 * @author Author2
 * @date   Oct 2006
 * 
 * @brief  Defines 3D objects
 * 
 * 
 */
#ifndef _ISI_MY_OBJECTS_H_
#define _ISI_MY_OBJECTS_H_

#include <vector>     // STL Vector type

#include <glm/glm.h>  // for vec3 (and other vector) type and related
		      // geometric operations. Look at documentation
		      // file: glm-0.4.1/info/fr/news.html

/** 
 * Simple cube object
 * 
 */
class Cube {

 protected:

  std::vector<glm::vec3>         _vertices;  /**< vector of 3D positions */
  std::vector<std::vector<int> > _triangles; /**< vector of vertex indices */
  std::vector<glm::vec3>         _normalsT;  /**< vector of 3D vectors */

 public:
  Cube();
  //~Cube(){};
  void draw();

};


#endif
