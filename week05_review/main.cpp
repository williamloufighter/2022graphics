#include <GL/glut.h>
#include <stdio.h>
int N=0;
int x[100], y[100];
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<N; i++){
        glVertex2f((x[i]-150)/150.0, -(y[i]-150)/150.0);
    }
    glEnd();
    glutSwapBuffers();
}
void motion(int mouseX, int mouseY)
{
        printf("現在按下滑鼠，得到新座標 %d %d\n",x[N-1],y[N-1]);
        N++;
        x[N-1]=mouseX; y[N-1]=mouseY;
        display();
}
int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05 複習mouse");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMainLoop();
}
