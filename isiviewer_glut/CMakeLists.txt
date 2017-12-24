cmake_minimum_required(VERSION 2.6)

project(M1_ISI_isiviewer_glut)

find_package(OpenGL REQUIRED)
find_package(Qt4)
set(QT_USE_QTXML 1)
set(QT_USE_QTOPENGL 1)
include(${QT_USE_FILE})

include_directories(glm-0.4.1 ${PROJECT_SOURCE_DIR} ${PROJECT_BINARY_DIR})

# Generate header files from qt designer ui files
set(UIC_IN  my_gui_form.ui)
qt4_wrap_ui(UIC_OUT ${UIC_IN})

# Generate cpp files from header files containing Q_OBJECT macro
set(MOC_IN my_main_window.h my_scene.h)
qt4_wrap_cpp(MOC_OUT ${MOC_IN})

set(SOURCES ${UIC_OUT} ${MOC_OUT} 
  main.cpp  my_main_window.cpp  my_objects.cpp  my_qglviewer.cpp  my_scene.cpp imageloader.cpp)

add_executable(isiviewer ${SOURCES})

target_link_libraries (isiviewer GLEW QGLViewer glut ${QT_LIBRARIES} ${OPENGL_LIBRARIES}) 


