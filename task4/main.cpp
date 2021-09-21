//
//  main.cpp
//  task4
//
//  Created by 松野光希 on 2020/05/26.
//  Copyright © 2020 松野光希. All rights reserved.
//

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#include <stdlib.h>

float rotation = 0.0;
float lookposition =10.0;

//light0
const GLfloat lightPosition[4] = {0, -15, 4, 0.0};
const GLfloat teapotAmbient[4] = {0.5, 0.5, 1.0, 1.0};
const GLfloat teapotSpecular[4] = {1.0, 1.0, 1.0, 1.0};
const GLfloat teapotDiffuse[4] = {100.4, 1.0, 0.3, 1.0};
const GLfloat teapotShininess[1] = {120.0};



void reshape(int width, int height){
    double x=5.0;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluPerspective(30, (double)width/height, 1.0, 100.0);
    /*gluLookAt(lookposition, lookposition, lookposition,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);*/
    glMatrixMode(GL_MODELVIEW);
}

void LookAt(){
int i;

GLdouble look[3], norm;
GLdouble ViewAt[3] = {5.0, 7.5, 5.0};
GLdouble ViewTo[3] = {0.0, 0.0, 0.0};
GLdouble ViewUp[3];
for(i=0; i<3; i++){
look[i] =ViewTo[i] - ViewAt[i];
}

ViewUp[0] = - look[0] * look[2];
ViewUp[1] = - look[1] * look[2];
ViewUp[2] = look[0] * look[0] + look[1] * look[1] + look[2] * look[2];
norm = ViewUp[0]*ViewUp[0] + ViewUp[1]*ViewUp[1] + ViewUp[2]*ViewUp[2];
//norm = sqrt(norm);
for(i=0; i<3; i++){
ViewUp[i] /= norm;
}
gluLookAt(ViewAt[0], ViewAt[1], ViewAt[2],
ViewTo[0], ViewTo[1], ViewTo[2], ViewUp[0], ViewUp[1], ViewUp[2]);
}

void display(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glRotatef(rotation, 1,1,0);
    /*glTranslatef(0,0.5,0);
    glutSolidTeapot(0.5);*/
    
    glutSolidSphere(0.5, 20, 20);
  //上側ピラミッド
    for (double i = 1.0; i>=0.1; i-=0.1){
    glBegin(GL_LINE_LOOP);
        glVertex3d(i, 1-i, i);
        glVertex3d(-i,1-i, i);
        glVertex3d(-i, 1-i, -i);
        glVertex3d(i, 1-i, -i);
    glEnd();
    }
    
    for (double i = 0.1; i>= 0.0; i-=0.05){
    glBegin(GL_LINE_LOOP);
        glVertex3d(i, 1.0-i, i);
        glVertex3d(-i, 1.0-i, i);
        glVertex3d(-i, 1.0-i, -i);
        glVertex3d(i, 1.0-i, -i);
    glEnd();
    }
    
    glBegin(GL_LINES);
    glVertex3d(0, 1, 0);
    glVertex3d(1, 0, 1);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3d(0, 1, 0);
    glVertex3d(-1, 0, 1);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3d(0, 1, 0);
    glVertex3d(-1, 0, -1);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3d(0, 1, 0);
    glVertex3d(1, 0, -1);
    glEnd();
    
    //下側ピラミッド
    for (double i = 1.0; i>=0.1; i-=0.1){
    glBegin(GL_LINE_LOOP);
        glVertex3d(i, -(1-i), i);
        glVertex3d(-i,-(1-i), i);
        glVertex3d(-i, -(1-i), -i);
        glVertex3d(i, -(1-i), -i);
    glEnd();
    }
    
    for (double i = 0.1; i>= 0.0; i-=0.05){
    glBegin(GL_LINE_LOOP);
        glVertex3d(i, -(1.0-i), i);
        glVertex3d(-i, -(1.0-i), i);
        glVertex3d(-i, -(1.0-i), -i);
        glVertex3d(i, -(1.0-i), -i);
    glEnd();
    }
    
    glBegin(GL_LINES);
    glVertex3d(0, -1, 0);
    glVertex3d(1, 0, 1);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3d(0, -1, 0);
    glVertex3d(-1, 0, 1);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3d(0, -1, 0);
    glVertex3d(-1, 0, -1);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3d(0, -1, 0);
    glVertex3d(1, 0, -1);
    glEnd();
    
    glPopMatrix();
    
    glLoadIdentity();
    LookAt();
    
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
    
    lookposition -= 0.5;
    if (lookposition == -10) lookposition = 10.0;
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
