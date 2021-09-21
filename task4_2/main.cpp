//
//  main.cpp
//  task4
//
//学籍番号：71907528
//  Created by 松野光希 on 2020/05/26.
//  Copyright © 2020 松野光希. All rights reserved.
//
//
//キーボード：b , f, c, q
//マウス；クリック時に動く。
//
//

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>

float rotation = 0.0;
float lookposition =5.0;

double bgc0=1.0, bgc1=1.0, bgc2 = 1.0;
double bgc_a = 1.0, bgc_b = 1.0, bgc_c = 1.0;

//light0
const GLfloat lightPosition[4] = {0, -15, 4, 0.0};
const GLfloat teapotAmbient[4] = {0.5, 0.5, 1.0, 1.0};
const GLfloat teapotSpecular[4] = {1.0, 1.0, 1.0, 1.0};
const GLfloat teapotDiffuse[4] = {100.4, 1.0, 0.3, 1.0};
const GLfloat teapotShininess[1] = {120.0};


//decleartion of function
void bgc0_make();
void bgc1_make();
void bgc2_make();


void reshape(int width, int height){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluPerspective(30, (double)width/height, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

//視点位置
void LookAt(){
        gluLookAt(lookposition, lookposition, lookposition,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0);
}

//図の描画
void display(){
    glClearColor(bgc0, bgc1, bgc2, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    glPushMatrix();
    
    glRotatef(rotation, 1,1,0);
    
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

//ライトの設定
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

//ボタンを押したときの動作
void idle(){
    rotation = rotation + 1.0;
    if(rotation > 360) rotation = 0.0;
    glutPostRedisplay();
    
    lookposition -= 0.01;
    if (lookposition < -5) lookposition = 5.0;
    
    bgc0_make();
    bgc1_make();
    bgc2_make();
}


void bgc0_make(){
    bgc_a -= 0.01;
    if(bgc_a < 0 && bgc_a > -1){
        bgc0 = -bgc_a;
        std::cout << "bgc0=" << bgc0 << "\n";
    }else if(bgc_a < -1){
        bgc_a = 1.0;
        bgc0 = 1.0;
        std::cout << "bgc0=" << bgc0 << "\n";
    }else{
        bgc0 = bgc_a;
        std::cout << "bgc0 = " << bgc0 << "\n";
    }
    
}

void bgc1_make(){
    bgc_b  -= 0.005;
    if(bgc_b < 0 && bgc_b > -1){
        bgc1 = -bgc_b;
        std::cout << "bgc1=" << bgc1 << "\n";
    }else if(bgc_b < -1){
        bgc_b = 1.0;
        bgc1 = 1.0;
        std::cout << "bgc1=" << bgc1 << "\n";
    }else{
        bgc1 = bgc_b;
        std::cout << "bgc1 = " << bgc1 << "\n";
    }
    
}

void bgc2_make(){
    bgc_c  -= 0.0002;
    if(bgc_c < 0 && bgc_c > -1){
        bgc2 = -bgc_c;
        std::cout << "bgc2=" << bgc2 << "\n";
    }else if(bgc_c < -1){
        bgc_c = 1.0;
        bgc2 = 1.0;
        std::cout << "bgc2=" << bgc2 << "\n";
    }else{
        bgc2 = bgc_c;
        std::cout << "bgc2 = " << bgc2 << "\n";
    }
    
}

//bボタンを押した時の動作
void back(){
    rotation = rotation + 1.0;
    if(rotation > 360) rotation = 0.0;
    glutPostRedisplay();
    
    lookposition = lookposition + 0.1;
}

//fボタンを押したときの動作
void forward(){
    rotation = rotation + 1.0;
    if(rotation > 360) rotation = 0.0;

    glutPostRedisplay();
    
    lookposition = lookposition - 0.1;
    glutPostRedisplay();
    
}

//マウスをクリックした時の動作
void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){        //left buttonが押された場合
        glutIdleFunc(idle);
    }else{
        glutIdleFunc(0);
    }
}

//キーボード入力に関して
void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'q':
            exit(0);
            break;
        case 'c':
            rotation = 0;
            lookposition = 10.0;
            bgc0 = 1.0; bgc1 = 1.0;  bgc2 = 1.0;
            bgc_a = 1.0; bgc_b = 1.0; bgc_c = 1.0;
            glutPostRedisplay();
            break;
        case 'b':
            back();
            break;
        case 'f':
            forward();
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
