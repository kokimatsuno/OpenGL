//
//  main.cpp
//  task6
//
//  Created by 松野光希 on 2020/06/09.
//  Copyright © 2020 松野光希. All rights reserved.
//
//学籍番号：71907528
//キーボード：b , f, c, q
//マウス；クリック時に動く。
//
//コマンドライン　引数：視点位置の設定（x=y=z)
//

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#include <cstdlib>

float rotation = 0.0;
float lookposition =5.0;

double bgc0=1.0, bgc1=1.0, bgc2 = 1.0;
double bgc_a = 1.0, bgc_b = 1.0, bgc_c = 1.0;

//light0
const GLfloat lightPosition0[4] = {0, -15, 4, 0.0};
const GLfloat teapotAmbient0[4] = {0.5, 0.5, 1.0, 1.0};
const GLfloat teapotSpecular0[4] = {1.0, 1.0, 1.0, 1.0};
const GLfloat teapotDiffuse0[4] = {100.4, 1.0, 0.3, 1.0};
const GLfloat teapotShininess0[1] = {120.0};


//light1
const GLfloat lightPosition1[4] = {5, 2, 0, 10};
const GLfloat teapotAmbient1[4] = {10, 0.5, 1.0, 1.0};
const GLfloat teapotSpecular1[4] = {1.0, 1.0, 1.0, 1.0};
const GLfloat teapotDiffuse1[4] = {10.4, 101.0, 0.3, 1.0};
const GLfloat teapotShininess1[1] = {20.0};


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


    glPushMatrix();         //回転範囲始め

    glRotatef(rotation, 1,1,0);


    //小さい立方体の描画
    glPushMatrix();
    glRotatef(rotation, 1, 0, 0);
    glTranslatef(0.5, 1.0, 0.0);
    glutSolidCube(0.1);
    glPopMatrix();

   //円の描画
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

    glPopMatrix();              //回転範囲終わり




    glLoadIdentity();
    LookAt();

    glutSwapBuffers();
}

//ライトの設定
void setup(){
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, teapotAmbient0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teapotDiffuse0);
    glMaterialfv(GL_FRONT, GL_SPECULAR, teapotSpecular0);
    glMaterialfv(GL_FRONT, GL_SHININESS, teapotShininess0);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition1);
    glMaterialfv(GL_FRONT, GL_AMBIENT, teapotAmbient1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teapotDiffuse1);
    glMaterialfv(GL_FRONT, GL_SPECULAR, teapotSpecular1);
    glMaterialfv(GL_FRONT, GL_SHININESS, teapotShininess1);
    }


//make idle function
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


//背景色変化設定
//bgc0
void bgc0_make(){
    bgc_a -= 0.01;
    if(bgc_a < 0 && bgc_a > -1){
        bgc0 = -bgc_a;
    }else if(bgc_a < -1){
        bgc_a = 1.0;
        bgc0 = 1.0;
    }else{
        bgc0 = bgc_a;
    }

}

//bgc1
void bgc1_make(){
    bgc_b  -= 0.005;
    if(bgc_b < 0 && bgc_b > -1){
        bgc1 = -bgc_b;
    }else if(bgc_b < -1){
        bgc_b = 1.0;
        bgc1 = 1.0;
    }else{
        bgc1 = bgc_b;
    }

}

//bgc2
void bgc2_make(){
    bgc_c  -= 0.0002;
    if(bgc_c < 0 && bgc_c > -1){
        bgc2 = -bgc_c;
    }else if(bgc_c < -1){
        bgc_c = 1.0;
        bgc2 = 1.0;
    }else{
        bgc2 = bgc_c;
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
    lookposition = std::stof(argv[1]);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("hello 3d world");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    setup();

    glutMainLoop();

    return 0;
}
