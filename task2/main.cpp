//
//  main.cpp
//  task2
//学籍番号：71907528
//  Created by 松野光希 on 2020/05/14.
//  Copyright © 2020 松野光希. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#define GL_SILENCE_DEPRECATION

void display(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.0, 0.0, 0.5);
    glBegin(GL_POLYGON);
        glVertex2f(-0.4, 0.5);
        glVertex2f(-0.4, -0.3);
        glVertex2f(-0.15, -0.4);
        glVertex2f(-0.15, 0.5);
    glEnd();
    
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.15, 0.5);
        glVertex2f(-0.15, -0.4);
        glVertex2f(0.0, -0.47);
        glVertex2f(0.15, -0.4);
        glVertex2f(0.15, 0.5);
    glEnd();
    
    glColor3f(0.0, 0.0, 0.5);
    glBegin(GL_POLYGON);
        glVertex2f(0.4, 0.5);
        glVertex2f(0.4, -0.3);
        glVertex2f(0.15, -0.4);
        glVertex2f(0.15, 0.5);
    glEnd();
        
    glFlush();
}

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("task2");
    glutDisplayFunc(display);
    glutMainLoop();
        
    return 0;
    }
