//
//  main.cpp
//  gp3
//
//  Created by 松野光希 on 2020/05/19.
//  Copyright © 2020 松野光希. All rights reserved.
//

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <OpenGl/OpenGL.h>
#include <GLUT/glut.h>

void reshape(int width, int height){
    glViewport(0, 0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, (double)width/height, 1.0, 100.0);
    gluLookAt(0.0, 0.0, 10.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
}

void display(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glutWireTeapot(1.0);
    glFlush();
}

int main(int argc, char * argv[]){
    glutInit(& argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("hello 3d world");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
