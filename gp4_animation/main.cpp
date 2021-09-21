//
//  main.cpp
//  gp4_animation
//
//  Created by 松野光希 on 2020/05/26.
//  Copyright © 2020 松野光希. All rights reserved.
//

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>

float rotation = 0.0;

//light0
const GLfloat lightPosition[4] = {0, -15, 4, 0.0};
const GLfloat teapotAmbient[4] = {0.5, 0.5, 1.0, 1.0};
const GLfloat teapotSpecular[4] = {1.0, 1.0, 1.0, 1.0};
const GLfloat teapotDiffuse[4] = {100.4, 1.0, 0.3, 1.0};
const GLfloat teapotShininess[1] = {120.0};



void reshape(int width, int height){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluPerspective(30, (double)width/height, 1.0, 100.0);
    gluLookAt(3, 10.1, 5.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
}

void display(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(rotation, 0,1,0);
    glTranslatef(0,0.5,0);
    glutSolidTeapot(0.5);
    glPopMatrix();
    
    glPushMatrix();
    double earth =0.1;
    glRotatef(earth, 0.0, 1.0, 0.0);
    glTranslatef( -1.0, 0.0, 0);
    glutWireSphere(0.2, 64, 64);
    
    
    glPopMatrix();
     
    glutSwapBuffers();
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
    }
    
void idle(){
    rotation = rotation + 1.0;
    if(rotation > 360) rotation = 0.0;
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_UP){        //left buttonが押された場合
        glutIdleFunc(idle);
    }else{
        glutIdleFunc(0);
    }
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'q':
            exit(0);
            break;
        case 'c':
            rotation = 0;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

int main(int argc, char * argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("hello 3d world");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    //glutIdleFunc(idle);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    setup();
    
    glutMainLoop();
    
    return 0;
}
