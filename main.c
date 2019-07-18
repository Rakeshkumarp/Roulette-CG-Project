#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>
#include<string.h>

/* Global declaration of some variables.*/
int k=0,id1=0,id2=0,w=0,i=0,rn=0,e=0,f=0,n=0,t=0,v1[38],v2[38],j=0,d=0;
float r=0.0;
int fol;
int p=0,q=0,res;
int rx[12]={42,39,33,26,20,17,17,20,26,33,39,42};
int ry[12]={55,63,68,68,63,54,44,36,31,31,36,45};
int bx[12]={42,39,33,26,20,17,17,20,26,33,39,42};
int by[12]={45,36,31,31,36,44,54,63,68,68,63,55};
float wx1[12]={50,47.3,40,30,20,12.7,10,12.7,20,30,40,47.3};
float wy1[12]={50,65,76,80,76,65,50,35,24,20,24,35};
float wx2[12]={47.3,40,30,20,12.7,10,12.7,20,30,40,47.3,50};
float wy2[12]={65,76,80,76,65,50,35,24,20,24,35,50};

/*Declare the strings which need to be displayed on the screen. */
static char str1[]="COMPUTER GRAPHICS LABORATORY WITH MINI PROJECT",
str2[]="ROULETTE WHEEL",
str3[][100]={"PUNEETH  AGRAWAL   (1PE16CS121)","RAKESH  KUMAR  P      (1PE16CS125)"},
str5[][100]={"Press Enter to play.","Press Escape to quit.","Press Space to see instructions."},
str7[]="INSTRUCTIONS ON HOW TO PLAY",
str8[][100]={"The croupier (or dealer) spins a ball on the outer rim of the wheel",
"after which it will eventually fall into one of the numbered spaces.",
"The objective of the player is to guess what number the ball will land in.",
"Before each spin,players have the opportunity to place bets around the roulette table."},
str10[]={"Use Mouse to place the bets on the betting table after starting the wheel."},
str9[]={"Press Enter and place a bet;Spacebar to stop"},
str15[][5]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18"},
str16[][20]={"1-6","Even","Red"},
str17[][20]={"Black","Odd","7-12"},
str13[]={"YOUR BET IS:"},
str21[]={"WELCOME TO ROULETTE"},
str14[]={"YOU LOOSE"},
str18[]={"YOU WIN"},
str51[]={"1-6"},
str52[]={"Even"},
str53[]={"Red"},
str54[]={"Black"},
str55[]={"Odd"},
str56[]={"7-12"},
str57[]={"Press Enter to play Again"};

/* Iniatilize the environment first.*/
void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 100.0, 0.0, 100.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

//Function to print the characters
void char1(int c,char *str,float xa,float ya){
    switch(c){
        case 0:glColor3f(0.0,0.0,0.0);
            break;
        case 1:glColor3f(1.0,0.0,0.0);
            break;
        case 2:glColor3f(0.0,1.0,0.0);
            break;
        case 3:glColor3f(0.0,0.0,1.0);
            break;
        default:glColor3f(1.0,1.0,1.0);
    }
    glRasterPos2f(xa,ya);
    for(k=0;k<strlen(str);k++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[k]);
}

/* Code to draw the roulette wheel.*/
void wheel(int q) {
        int i=0;
        for(i=0; i<12; i++) {
            if(i%2==0)  glColor3f(0.0,0.0,1.0);
            else glColor3f(0.0,1.0,0.0);
            glBegin(GL_TRIANGLES);
                glVertex2f(30,50);
                glVertex2f(wx1[(q+i)%12],wy1[(q+i)%12]);
                glVertex2f(wx2[(q+i)%12],wy2[(q+i)%12]);
            glEnd();
            glColor3f(1.0,1.0,1.0);
            glRasterPos2f(rx[(q+i)%12],ry[(q+i)%12]);
            for(j=0;j<strlen(str15[i]);j++)
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str15[i][j]);
        }
    glutSwapBuffers();
}

/*Code to draw the ball.*/
void ball(p,q) {
float x1,y1,x2,y2;
float angle;
double radius=2.0;
x1 = p,y1=q;
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLE_FAN);
glVertex2f(x1,y1);
for (angle=1.0f;angle<361.0f;angle+=0.2)
{
    x2 = x1+sin(angle)*radius;
    y2 = y1+cos(angle)*1.5*radius;
    glVertex2f(x2,y2);
}
glEnd();
}

/*Code for drawing the layout of roulette table */
void table() {
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2i(65,58);
        glVertex2i(95,58);
        glVertex2i(95,82);
        glVertex2i(65,82);
    glEnd();
    int i=0,j=0,k=1;
    for(i=0;i<4;i++) {
        for(j=0;j<3;j++) {
            if(k%2==1)      glColor3f(0.0,0.0,0.0);
            else            glColor3f(1.0,0.0,0.0);
            glBegin(GL_POLYGON);
                glVertex2i(65+(j*10),10+(i*12));
                glVertex2i(65+((j+1)*10),10+(i*12));
                glVertex2i(65+((j+1)*10),10+((i+1)*12));
                glVertex2i(65+(j*10),10+((i+1)*12));
            glEnd();
            k++;
        }
    }
    int u=0;
    glColor3f(1.0,1.0,1.0);
    for(i=0;i<4;i++) {
        for(j=0;j<3;j++) {
            glRasterPos2f(70+(j*10),52-(i*12));
            if(i==6 && j==0 ) { u++; }
            for(w=0;w<strlen(str15[u]);w++)
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str15[u][w]);
            u++;
        }
    }
    int o=0;
    glColor3f(0.0,0.0,0.0);
    for(int i=0;i<3;i++) {
                glRasterPos2f(68+(i*10),75);
                for(w=0;w<strlen(str16[o]);w++)
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str16[o][w]);
                o++;
    }
     o=0;
    glColor3f(0.0,0.0,0.0);
    for(int i=0;i<3;i++) {
                glRasterPos2f(68+(i*10),65);
                for(w=0;w<strlen(str17[o]);w++)
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str17[o][w]);
                o++;
    }
    glColor3f(1.0,1.0,1.0);
    glLineWidth(1);
    glBegin(GL_LINES);
        glVertex2i(65,70);
        glVertex2i(95,70);
        glVertex2i(75,82);
        glVertex2i(75,58);
        glVertex2i(85,82);
        glVertex2i(85,58);
    glEnd();
}

//mymouse function to capture the position of the mouse to decide the bet
void mymouse(GLint button,GLint action,GLint xMouse,GLint yMouse){
    if(xMouse<889 || xMouse>1297 || yMouse<140|| yMouse>690) f=0;
    else if(xMouse>889 && xMouse<1024 && yMouse<231 && yMouse>140) f=13;
    else if(xMouse>1024 && xMouse<1162 && yMouse<231 && yMouse>140) f=14;
    else if(xMouse>1162 && xMouse<1297 && yMouse<231 && yMouse>140) f=15;
    else if(xMouse>889 && xMouse<1024 && yMouse<324 && yMouse>231) f=16;
    else if(xMouse>1024 && xMouse<1162 && yMouse<324 && yMouse>231) f=17;
    else if(xMouse>1162 && xMouse<1297 && yMouse<324 && yMouse>231) f=18;
    else if(xMouse>889 && xMouse<1024 && yMouse<414 && yMouse>324) f=1;
    else if(xMouse>1024 && xMouse<1162 && yMouse<414 && yMouse>324) f=2;
    else if(xMouse>1162 && xMouse<1297 && yMouse<414 && yMouse>324) f=3;
    else if(xMouse>889 && xMouse<1024 && yMouse<506 && yMouse>414) f=4;
    else if(xMouse>1024 && xMouse<1162 && yMouse<506 && yMouse>414) f=5;
    else if(xMouse>1162 && xMouse<1297 && yMouse<506 && yMouse>414) f=6;
    else if(xMouse>889 && xMouse<1024 && yMouse<598 && yMouse>506) f=7;
    else if(xMouse>1024 && xMouse<1162 && yMouse<598 && yMouse>506) f=8;
    else if(xMouse>1162 && xMouse<1297 && yMouse<598 && yMouse>506) f=9;
    else if(xMouse>889 && xMouse<1024 && yMouse<690 && yMouse>598) f=10;
    else if(xMouse>1024 && xMouse<1162 && yMouse<690 && yMouse>598) f=11;
    else if(xMouse>1162 && xMouse<1297 && yMouse<690 && yMouse>598) f=12;
}

//bet function to print the bet on screen
void bet(int ff){
    char str0[5];
    if(ff<=12){
        sprintf(str0, "%d", ff);
        char1(0,str0,22,10);
    }
    if(ff>12){
        switch(ff){
            case 13:    char1(0,str51,22,10);break;
            case 14:    char1(0,str52,22,10);break;
            case 15:    char1(0,str53,22,10);break;
            case 16:    char1(0,str54,22,10);break;
            case 17:    char1(0,str55,22,10);break;
            case 18:    char1(0,str56,22,10);break;
        }
    }
    glutSwapBuffers();
}

/* Code to display the wheel,ball and table all in one screen called the game.*/
void game() {
    glClear(GL_COLOR_BUFFER_BIT);
    char1(1,str21,40,90);
    char1(1,str9,30,10);
    wheel(0);
    glutMouseFunc(mymouse);
}

/*Code to rotate the wheel abouts its centre*/
void rotate() {
    usleep(50*1000);
    glClear(GL_COLOR_BUFFER_BIT);
    char1(1,str21,30,90);
    char1(1,str9,30,10);
    char1(2,str13,10,10);
    table();
    p=(p+2)%12;
    q=(q+3)%12;
    wheel(q);
    ball(bx[p],by[p]);
    bet(f);
    fol=f;
    if((q==0)&&(p==0)){res=3;}
    if((q==0)&&(p==4)){res=11;}
    if((q==0)&&(p==8)){res=7;}
    if((q==3)&&(p==2)){res=10;}
    if((q==3)&&(p==6)){res=6;}
    if((q==3)&&(p==10)){res=2;}
    if((q==6)&&(p==0)){res=9;}
    if((q==6)&&(p==4)){res=5;}
    if((q==6)&&(p==8)){res=1;}
    if((q==9)&&(p==2)){res=4;}
    if((q==9)&&(p==6)){res=12;}
    if((q==9)&&(p==10)){res=8;}
}

//To stop the wheel and to print the result
void iselect(){
    int r=0;
    usleep(2000*1000);
    glClear(GL_COLOR_BUFFER_BIT);
    if(fol==res)                r=1;
    if((fol==13) && (res<7))    r=1;
    if((fol==14) && (res%2==0)) r=1;
    if((fol==15) && (res%2==1)) r=1;
    if((fol==16) && (res%2==0)) r=1;
    if((fol==17) && (res%2==1)) r=1;
    if((fol==18) && (res>7))    r=1;
    if(r==1)
    char1(2,str18,40,50);
    else
    char1(1,str14,40,50);
    char1(0,str57,35,40);
    glutSwapBuffers();
}

//Keyboard function for first window
void keyboard1(unsigned char key) {
    if(key==27)     exit(0);                                        //Exit if Escape is pressed
    if(key==32)     instructions();                                 //See instructions if spacebar is pressed
    if(key==13)   { glutDestroyWindow(id1); glutSetWindow(id2);}   //Play the game if Enter is pressed
}

//Keyboard function for second window
void keyboard2(unsigned char key){
    if(key==27)     glutDestroyWindow(id2); //Quit if Escape is pressed
    if(key==13)      glutIdleFunc(rotate);   //Start the wheel if 0 is pressed
    if(key==32)   glutIdleFunc(iselect); //stop the wheel if c is pressed
}

/*Code for Info about the project and the team.*/
void home() {
    glClear(GL_COLOR_BUFFER_BIT);
     glClearColor(0.0,0.0, 0.0, 0.0);
    glColor3f(1.0,1.0,1.0);
    glRasterPos2f(25,80);
    for(k=0;k<strlen(str1);k++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str1[k]);
    glBegin(GL_LINES);
        glVertex2d(25,79);
        glVertex2d(75,79);
    glEnd();
    glColor3f(1.0,0.0,0.0);
    glRasterPos2f(40,60);
    for(k=0;k<strlen(str2);k++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str2[k]);
    glColor3f(0.0,1.0,0.0);
    for(i=0;i<2;i++) {
        glRasterPos2f(35,40-(i*5));
        for(k=0;k<strlen(str3[i]);k++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str3[i][k]);
    }
    glColor3f(0.0,0.0,1.0);
    for(i=0;i<3;i++) {
        glRasterPos2f(35,25-(i*5));
        for(k=0;k<strlen(str5[i]);k++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str5[i][k]);
    }
    glutSwapBuffers();
}

/* Code to display the instructions.*/
void instructions() {
    glClear(GL_COLOR_BUFFER_BIT);
    char1(4,str7,30,90);
     glBegin(GL_LINES);
        glVertex2d(30,89);
        glVertex2d(59,89);
    glEnd();
    glColor3f(1.0,0.0,0.0);
    for(i=0;i<5;i++) {
        glRasterPos2f(20,80-(i*5));
        for(k=0;k<strlen(str8[i]);k++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str8[i][k]);
    }
    char1(2,str10,20,50);
    glColor3f(0.0,0.0,1.0);
    for(i=0;i<2;i++) {
    glRasterPos2f(35,25-(i*5));
    for(k=0;k<strlen(str5[i]);k++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str5[i][k]);
    }
    glutSwapBuffers();
}

/*Main function*/
void main(int argc, char **argv) {
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
        glutInitWindowPosition(500,500);
        id2=glutCreateWindow("Roulette Wheel");
        myInit();
        glutDisplayFunc(game);
        glutFullScreen();
        glutKeyboardFunc(keyboard2);
        glutInitWindowPosition(0,0);
        id1=glutCreateWindow("About");
        myInit();
        glutFullScreen();
        glutDisplayFunc(home);
        glutKeyboardFunc(keyboard1);
        glutMainLoop();
}
