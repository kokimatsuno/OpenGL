//
//  main.cpp
//  gp3_shade
//
//  Created by 松野光希 on 2020/05/19.
//学籍番号：71907528
//  Copyright © 2020 松野光希. All rights reserved.
//

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>

//light0
const GLfloat lightPosition[4] = {4, 10, 5, 3.0};
const GLfloat teapotAmbient[4] = {0.5, 0.5, 0.0, 1.0};
const GLfloat teapotSpecular[4] = {1.0, 1.0, 1.0, 1.0};
const GLfloat teapotDiffuse[4] = {0.4, 1.0, 0.3, 1.0};
const GLfloat teapotShininess[1] = {120.0};


void reshape(int width, int height){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluPerspective(30, (double)width/height, 1.0, 100.0);
    gluLookAt(-0.5, 2.1, 2.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
}

void display(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(0.5);
    glFlush();
}

void setup(){
    glEnable(GL_DEPTH_TEST);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glMaterialfv(GL_FRONT, GL_AMBIENT, teapotAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teapotDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, teapotSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, teapotShininess);
    
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition1);
    glMaterialfv(GL_FRONT, GL_AMBIENT, teapotAmbient1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teapotDiffuse1);
    glMaterialfv(GL_FRONT, GL_SPECULAR, teapotSpecular1);
    glMaterialfv(GL_FRONT, GL_SHININESS, teapotShininess1);
   
    glEnable(GL_LIGHT2);
    glLightfv(GL_LIGHT2, GL_POSITION, lightPosition2);
    glMaterialfv(GL_FRONT, GL_AMBIENT, teapotAmbient2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teapotDiffuse2);
    glMaterialfv(GL_FRONT, GL_SPECULAR, teapotSpecular2);
    glMaterialfv(GL_FRONT, GL_SHININESS, teapotShininess2);
    
    glEnable(GL_LIGHT3);
    glLightfv(GL_LIGHT3, GL_POSITION, lightPosition3);
    glMaterialfv(GL_FRONT, GL_AMBIENT, teapotAmbient3);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teapotDiffuse3);
    glMaterialfv(GL_FRONT, GL_SPECULAR, teapotSpecular3);
    glMaterialfv(GL_FRONT, GL_SHININESS, teapotShininess3);

    }
    

int main(int argc, char * argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
    glutCreateWindow("hello 3d world");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    setup();
    
    glutMainLoop();
    
    return 0;
}
