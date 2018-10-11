# C++/OpenGL solar system
This project is a school project that consists in coding a 3D animated solar system using only C++ ! It is based on my teacher's template (M. Jobard)

# Libraries used
I used for this project:
- C++
- OpenGL
- Qt4
- QGLViewer

# Demo
These are instructions for Ubuntu systems. I do not know how to install the above libraries on Windows/Mac. Sorry :c <br />

## Setting up your environment
To configure your environment, you must do the following:

### Under Ubuntu 14.04
- install the packets:
`sudo apt-get install cmake cmake-qt-gui cmake-curses-gui libglew-dev libqglviewer-dev qt4-dev-tools qt4-qtconfig libtclap-dev qtcreator geomview doxygen-gui`

### Under Ubuntu 16.04
- install the packets: <br />
`sudo apt-get install cmake cmake-qt-gui cmake-curses-gui libglew-dev libqglviewer-dev-qt4 qt4-dev-tools qt4-qtconfig libtclap-dev qtcreator geomview doxygen-gui`
- create a symbolic link:
`cd /usr/lib/x86_64-linux-gnu/` <br />
`sudo ln -s libQGLViewer.so.2.6.3 libQGLViewer.so` <br />
`cd -`

### Under Ubuntu 18.04
- install the packets: <br />
`sudo apt-get install cmake cmake-qt-gui cmake-curses-gui libglew-dev libqglviewer-dev-qt5 qt5-default qt5-qmake libtclap-dev qtcreator geomview doxygen-gui libglm-dev`
- create a symbolic link:
`cd /usr/lib/x86_64-linux-gnu/` <br />
`sudo ln -s libQGLViewer-qt4.so libQGLViewer.so` <br />
`cd -`

## Compiling
- Erase the directory BUILD
- Create a new directory and name it whatever you want
- Navigate to the freshly created directory
- Enter `cmake ../isiviewer_glut/` (the makefile is created)
- `make` to build the executable
- `./isiviewer` to launch !
