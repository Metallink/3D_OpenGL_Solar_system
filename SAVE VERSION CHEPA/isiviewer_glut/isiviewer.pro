TEMPLATE = app
TARGET   = 
CONFIG  += qt opengl warn_on release thread
QT      += xml opengl

FORMS       = my_gui_form.ui
HEADERS     = my_qglviewer.h my_main_window.h my_scene.h my_objects.h
SOURCES     = my_qglviewer.cpp my_main_window.cpp my_scene.cpp my_objects.cpp main.cpp

INCLUDEPATH += ./glm-0.4.1

unix:LIBS *= -lQGLViewer -lglut

# Intermediate files are created in a separate folder
MOC_DIR = .moc
OBJECTS_DIR = .obj
