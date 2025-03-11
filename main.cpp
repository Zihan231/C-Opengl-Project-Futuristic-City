
#include<cstdio>
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include<bits/stdc++.h>

float angle=0.0f;
float motion = 0.0f;
float motion1_Blue= 0.0f;
float motion2_red = 0.0f;
float motion3_yellow= 0.0f;
float motion_Escalator_1=0.0f;
float cloud_motion=0.0f;
float flying_Vehicle_motion_Y=0.0f;
float flying_Vehicle_motion_X=0.0f;
float UFO_X=0;
float UFO_Y=0;
bool isNight=false;
void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Sky color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-600, 600, -500, 500); // Set ortho2D range
}

void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(r, g, b);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float x = radius * cos(A);
        float y = radius * sin(A);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}

void Car_Standing_Before_Station()//CrStnd
{
    glPushMatrix();
    glTranslatef(800,200,0);
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2f(-600,-240);//W
    glVertex2f(-560,-230);//A_{1}

    glVertex2f(-540,-220);//V
    glVertex2f(-460,-220);//C_{1}
    glVertex2f(-420,-240);//E_{1}
    glVertex2f(-380,-244);//F_{1}
    glVertex2f(-380,-270);//G_{1}
    glVertex2f(-460,-270);//D_{1}
    glVertex2f(-540,-270);//U
    glVertex2f(-600,-270);//Z
    glEnd();

    //Glass front
    glBegin(GL_POLYGON);
    glColor3ub(86, 190, 202);
    glVertex2f(-460,-222);//S_{6}
    glVertex2f(-422,-240);//T_{6}
    glVertex2f(-488,-240);//V_{6}
    glVertex2f(-488,-222);//U_{6}
    glEnd();

    //front door
    glBegin(GL_POLYGON);
    glColor3ub(253, 107, 107);
    glVertex2f(-488,-244);//H_{7}
    glVertex2f(-422,-244);//I_{7}
    glVertex2f(-422,-260);//J_{7}
    glVertex2f(-435,-265);//K_{7}
    glVertex2f(-488,-265);//L_{7}
    glEnd();

    //Back Door
    glBegin(GL_POLYGON);
    glColor3ub(253, 107, 107);
    glVertex2f(-560,-244);//F_{7}
    glVertex2f(-500,-244);//C_{7}
    glVertex2f(-500,-265);//D_{7}
    glVertex2f(-540,-265);//G_{7}
    glVertex2f(-560,-260);//E_{7}
    glEnd();

    //Glass Back
    glBegin(GL_POLYGON);
    glColor3ub(86, 190, 202);
    glVertex2f(-500,-222);//W_{6}
    glVertex2f(-500,-240);//Z_{6}
    glVertex2f(-560,-240);//B_{7}
    glVertex2f(-540,-222);//A_{7}
    glEnd();



    // Adding wheels to the car
    circle(19, -560, -270, 0, 0, 0); // Left wheel tier
    circle(13, -560, -270, 255, 255, 255); // Left wheel

    circle(19, -430, -270, 0, 0, 0); // Right wheel tier
    circle(13, -430, -270, 255, 255, 255); // Right wheel

    glPopMatrix();
}

void Road() //Rd
{
    //Horizontal Road
    glBegin(GL_POLYGON);
    glColor3ub(51, 51, 51);
    glVertex2f(-600,-400);//K
    glVertex2f(-600,-200);//E
    glVertex2f(600,-200);//F
    glVertex2f(600,-400);//C
    glVertex2f;//
    glEnd();

    //Left side Block At Escalator ending
    glBegin(GL_POLYGON);
    glColor3ub(68,68,68);
    glVertex2f(-118,-190);//G
    glVertex2f(-108,-140);//J_{3}
    glVertex2f(-150,-140);//L_{1}
    glVertex2f(-150,-190);//M
    glVertex2f;//
    glEnd();

    //Right side Block At Escalator ending
    glBegin(GL_POLYGON);
    glColor3ub(68, 68, 68);
    glVertex2f(108,-140);//K_{3}
    glVertex2f(150,-140);//L_{3}
    glVertex2f(150,-190);//N
    glVertex2f(118,-190);//H
    glEnd();

    // Footpath block white Line 1 Horizontal
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-600, -200); // E
    glVertex2f(-600, -190); // K_{1}
    glVertex2f(600, -190); // J_{1}
    glVertex2f(600, -200); // M
    glEnd();

    int X = 100;
    int startX = -570;

    // Loop to create black blocks
    for (int i = 0; i < 13; i++) {
        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(startX + i * X, -190); // M_{1}
        glVertex2f(startX + i * X + 30, -190); // O_{1}
        glVertex2f(startX + i * X + 30, -200); // P_{1}
        glVertex2f(startX + i * X, -200); // N_{1}
        glEnd();
    }

    // Footpath block white Line 2 Horizontal
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-600, -200 - 210.5); // E
    glVertex2f(-600, -190 - 210.5); // K_{1}
    glVertex2f(600, -190 - 210.5); // J_{1}
    glVertex2f(600, -200 - 210.5); // M
    glEnd();

    int stepSize = 100;
    int initialX = -570;

    // Loop to create multiple black blocks
    for (int i = 0; i < 13; i++) {
        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(initialX + i * stepSize, -190 - 210.5); // M_{1}
        glVertex2f(initialX + i * stepSize + 30, -190 - 210.5); // O_{1}
        glVertex2f(initialX + i * stepSize + 30, -200 - 210.5); // P_{1}
        glVertex2f(initialX + i * stepSize, -200 - 210.5); // N_{1}
        glEnd();
    }

    //Verticle Road
    glBegin(GL_POLYGON);
    glColor3ub(51, 51, 51);
    glVertex2f(-120,-200);//G
    glVertex2f(-80,40);//I
    glVertex2f(80,40);//J
    glVertex2f(120,-200);//H
    glVertex2f;//
    glEnd();

    //Mid Lines
    int x = 200;
    glLineWidth(6);

    for(int i = 0; i<7; i++)
    {
        glBegin(GL_LINES);
        if(isNight)
        {
            glColor3ub(236, 230, 58);
        }
        else
            glColor3ub(255,255,255);
        glVertex2f(-600+x*i,-300);//Q
        glVertex2f(-500+x*i,-300);//R
        glEnd();
    }

    //Mid Line Horizontal
    glBegin(GL_LINES);
    if(isNight)
    {
        glColor3ub(236, 230, 58);
    }
    else
        glColor3ub(255,255,255);
    glVertex2f(0,-150);//H1
    glVertex2f(0,-50);//I1
    glEnd();

    glBegin(GL_LINES);
    if(isNight)
    {
        glColor3ub(236, 230, 58);
    }
    else
        glColor3ub(255,255,255);
    glVertex2f(0,-150+170);//H1
    glVertex2f(0,-50+44);//I1
    glEnd();
}
void UFO() //UF
{
    //circle OR Glass
    float centerX = -213.0f;
    float centerY = 407.0f;
    float radius = 20.0f;
    glPushMatrix();
    glTranslated(UFO_X,UFO_Y,0);
    glBegin(GL_POLYGON);
    if(isNight)
        glColor3ub(236, 230, 58);
    else
        glColor3ub(107, 232, 240);

    for (int i = 0; i < 90; i++)
    {
        float pi = 3.1416f;
        float A = (i * pi) / 90; // Calculate angle
        float x = centerX + radius * cos(A); // Calculate x-coordinate
        float y = centerY + radius * sin(A); // Calculate y-coordinate
        glVertex2f(x, y); // Add vertex
    }
    glEnd();
    //Upper
    glBegin(GL_POLYGON);
    glColor3ub(81,204,170);
    glVertex2f(-260.8307935406947,393.6096192702505);//N_{2}
    glVertex2f(-238.969708548241,407.508057411148);//P_{2}
    glVertex2f(-187.7192179036806,407.218506616546);//Q_{2}
    glVertex2f(-166.0029083085279,394.0439454621535);//O_{2}
    glEnd();

    //Lower
    glBegin(GL_POLYGON);
    glColor3ub(231, 76, 60);
    glVertex2f(-192.4041278829823,382.791023323668);//S_{2}
    glVertex2f(-233.9128443846186,382.6505538938824);//R_{2}
    glVertex2f(-260.8307935406947,393.6096192702505);//N_{2}
    glVertex2f(-166.0029083085279,394.0439454621535);//O_{2}
    glEnd();

    //Upper Strip
    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 189);
    glVertex2f(-237.4189322274372,408.6717956510645);//T_{2}
    glVertex2f(-189.8195314519894,408.5359913692515);//U_{2}
    glVertex2f(-187.7192179036806,407.218506616546);//Q_{2}
    glVertex2f(-238.969708548241,407.508057411148);//P_{2}
    glEnd();

    //Middle strip
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(69,153,249);
    glVertex2f(-230.6346738061945,407.0426531615483);//Z_{2}
    glVertex2f(-240.5694021821934,392.2379598953541+3);//A_{3}

    glVertex2f(-220.5051468345878,407.1400524593523);//B_{3}
    glVertex2f(-221.8687370038426,392.0431612997463+3);//C_{3}

    glVertex2f(-207.3562416310599,407.0426531615483);//D_{3}
    glVertex2f(-204.7264605903543,391.6535641085307+3);//E_{3}

    glVertex2f(-195.3761280011788,406.9452538637444);//F_{3}
    glVertex2f(-183.4934136691017,392.6275570865697+3);//G_{3}

    glColor3ub(62, 161, 254);
    glVertex2f(-260.8307935406947,393.6096192702505);//N_{2}
    glVertex2f(-166.0029083085279,394.0439454621535);//O_{2}

    glEnd();

    //Lower Strip
    glBegin(GL_POLYGON);
    glColor3ub(35, 255, 0);
    glVertex2f(-233.9128443846186,382.6505538938824);//R_{2}
    glVertex2f(-192.4041278829823,382.791023323668);//S_{2}
    glVertex2f(-192.5390372301164,381.207340073547);//W_{2}
    glVertex2f(-233.960036455074,380.9612747316166);//V_{2}
    glEnd();
    //UFO Fire1
    int ux=670;
    int uy=508;
    int y=5;
    glBegin(GL_POLYGON);
    glColor3ub(243, 156, 18);
    glVertex2f(463-ux,-125-y+uy);//M_{15}
    glVertex2f(480-ux,-125-y+uy);//N_{15}
    glVertex2d(486-ux,-136+uy);//W_{15}
    glVertex2d(476-ux,-132-y+uy);//V_{15}
    glVertex2d(471-ux,-144-y+uy);//U_{15}
    glVertex2d(467-ux,-131-y+uy);//T_{15}
    glVertex2d(457-ux,-136+uy);//S_{15}
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2f(463-ux,-125+uy);//M_{15}
    glVertex2f(480-ux,-125+uy);//N_{15}
    glVertex2d(486-ux,-136+uy);//W_{15}
    glVertex2d(476-ux,-132+uy);//V_{15}
    glVertex2d(471-ux,-144+uy);//U_{15}
    glVertex2d(467-ux,-131+uy);//T_{15}
    glVertex2d(457-ux,-136+uy);//S_{15}
    glEnd();
    //UFO Fire2
    ux=685;
    uy=508;
    glBegin(GL_POLYGON);
    glColor3ub(243, 156, 18);
    glVertex2f(463-ux,-125-y+uy);//M_{15}
    glVertex2f(480-ux,-125-y+uy);//N_{15}
    glVertex2d(486-ux,-136+uy);//W_{15}
    glVertex2d(476-ux,-132-y+uy);//V_{15}
    glVertex2d(471-ux,-144-y+uy);//U_{15}
    glVertex2d(467-ux,-131-y+uy);//T_{15}
    glVertex2d(457-ux,-136+uy);//S_{15}
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2f(463-ux,-125+uy);//M_{15}
    glVertex2f(480-ux,-125+uy);//N_{15}
    glVertex2d(486-ux,-136+uy);//W_{15}
    glVertex2d(476-ux,-132+uy);//V_{15}
    glVertex2d(471-ux,-144+uy);//U_{15}
    glVertex2d(467-ux,-131+uy);//T_{15}
    glVertex2d(457-ux,-136+uy);//S_{15}
    glEnd();
    //UFO Fire3
    ux=695;
    uy=508;
    glBegin(GL_POLYGON);
    glColor3ub(243, 156, 18);
    glVertex2f(463-ux,-125-y+uy);//M_{15}
    glVertex2f(480-ux,-125-y+uy);//N_{15}
    glVertex2d(486-ux,-136+uy);//W_{15}
    glVertex2d(476-ux,-132-y+uy);//V_{15}
    glVertex2d(471-ux,-144-y+uy);//U_{15}
    glVertex2d(467-ux,-131-y+uy);//T_{15}
    glVertex2d(457-ux,-136+uy);//S_{15}
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2f(463-ux,-125+uy);//M_{15}
    glVertex2f(480-ux,-125+uy);//N_{15}
    glVertex2d(486-ux,-136+uy);//W_{15}
    glVertex2d(476-ux,-132+uy);//V_{15}
    glVertex2d(471-ux,-144+uy);//U_{15}
    glVertex2d(467-ux,-131+uy);//T_{15}
    glVertex2d(457-ux,-136+uy);//S_{15}
    glEnd();
    glPopMatrix();
}
void Building1() //Build_1
{
    // Right
    glBegin(GL_POLYGON);
    glColor3ub(61, 147, 187);
    glVertex2f(-150, -50); // B_{2}
    glVertex2f(-130, 40);  // J_{2}
    glVertex2f(-130, 440); // H_{2}
    glVertex2f(-150, 350); // E_{2}
    glEnd();

    // Front
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-300, -50); // C_{2}
    glVertex2f(-150, -50); // B_{2}
    glVertex2f(-150, 350); // E_{2}
    glVertex2f(-300, 350); // D_{2}
    glEnd();

    // Top
    glBegin(GL_POLYGON);
    glColor3ub(248, 210, 154);
    glVertex2f(-300, 350); // D_{2}
    glVertex2f(-150, 350); // E_{2}
    glVertex2f(-130, 440); // H_{2}
    glVertex2f(-270, 440); // I_{2}
    glEnd();

    // Door
    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19); // Brown color
    glVertex2f(-250, -50); // A_{2}
    glVertex2f(-200, -50); // B_{2}
    glVertex2f(-200, 50);  // C_{2}
    glVertex2f(-250, 50);  // D_{2}
    glEnd();

    //  Windows
    // First floor windows
    if(isNight)
        glColor3ub(236, 230, 58); // Sky blue color
    else
        glColor3ub(0, 191, 255);
    glBegin(GL_POLYGON);
    glVertex2f(-280, 80);
    glVertex2f(-260, 90);
    glVertex2f(-240, 80);
    glVertex2f(-240, 120);
    glVertex2f(-260, 130);
    glVertex2f(-280, 120);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-200, 80);
    glVertex2f(-180, 90);
    glVertex2f(-160, 80);
    glVertex2f(-160, 120);
    glVertex2f(-180, 130);
    glVertex2f(-200, 120);
    glEnd();

    // Second floor windows
    glBegin(GL_POLYGON);
    glVertex2f(-280, 180);
    glVertex2f(-260, 190);
    glVertex2f(-240, 180);
    glVertex2f(-240, 220);
    glVertex2f(-260, 230);
    glVertex2f(-280, 220);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-200, 180);
    glVertex2f(-180, 190);
    glVertex2f(-160, 180);
    glVertex2f(-160, 220);
    glVertex2f(-180, 230);
    glVertex2f(-200, 220);
    glEnd();

    // Third floor windows
    glBegin(GL_POLYGON);
    glVertex2f(-280, 280);
    glVertex2f(-260, 290);
    glVertex2f(-240, 280);
    glVertex2f(-240, 320);
    glVertex2f(-260, 330);
    glVertex2f(-280, 320);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-200, 280);
    glVertex2f(-180, 290);
    glVertex2f(-160, 280);
    glVertex2f(-160, 320);
    glVertex2f(-180, 330);
    glVertex2f(-200, 320);
    glEnd();
}
void Building2_TOP_Part()//Build_2_Tp
{
    //top Polygon

    //TOP
    glBegin(GL_POLYGON);
    glColor3ub(50, 100, 90);
    glVertex2f(-540,400);//Q _{3}
    glVertex2f(-480,440);//N_{3}

    glColor3ub(30, 70, 60);
    glVertex2f(-400,440);//O _{3}
    glVertex2f(-340,400);//P_{3}
    glEnd();

    //GLASS
    glBegin(GL_POLYGON);
    glColor3ub(134, 198, 255);
    glVertex2f(-540,400);//Q _{3}
    glVertex2f(-340,400);//P_{3}

    glColor3ub(0, 191, 255);
    glVertex2f(-400,350);//M_{3}
    glVertex2f(-480,350);//L_{3}

    glEnd();

    //window
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255,255,255);
    glVertex2f(-540,400);//Q_{3}
    glVertex2f(-340,400);//P_{3}
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(-540,400);//Q _{3}
    glVertex2f(-480,440);//N_{3}

    glVertex2f(-480,440);//N_{3}
    glVertex2f(-400,440);//O _{3}

    glVertex2f(-400,440);//O _{3}
    glVertex2f(-340,400);//P_{3}

    glVertex2f(-340,400);//P_{3}
    glVertex2f(-400,350);//M_{3}

    glVertex2f(-400,350);//M_{3}
    glVertex2f(-480,350);//L_{3}

    glVertex2f(-480,350);//L_{3}
    glVertex2f(-540,400);//Q _{3}


    glVertex2f(-455,350);//N_{4}
    glVertex2f(-480,400);//H_{5}

    glVertex2f(-425,350);//O_{4}
    glVertex2f(-400,400);//I_{5}

    glVertex2f(-505,370);//J_{5}
    glVertex2f(-375,370);//K_{5}
    glEnd();
}
void Building2() //Build_2
{
    //front side
    glBegin(GL_POLYGON);
    glColor3ub(0, 191, 255);
    glVertex2f(-500,-80);//N
    glVertex2f(-380,-80);//O
    glVertex2f(-380,80);//T_{1}
    glVertex2f(-500,80);//S_{1}
    glEnd();
    //front side Doors
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-460,80);//R_{3}
    glVertex2f(-460,-80);//T_{3}

    glVertex2f(-420,-80);//U_{3}
    glVertex2f(-420,80);//S_{3}

    glVertex2f(-500,-20);//V_{3}
    glVertex2f(-380,-20);//W_{3}

    glVertex2f(-500,20);//Z_{3}
    glVertex2f(-380,20);//A_{4}

    glVertex2f(-500,50);//B_{4}
    glVertex2f(-380,50);//C_{4}
    glVertex2f;//
    glEnd();

    //Right Side
    glBegin(GL_POLYGON);
    glColor3ub(222, 75, 32);
    glVertex2f(-380,-80);//O
    glVertex2f(-340,-40);//P
    glVertex2f(-340,120);//V_{1}
    glVertex2f(-380,80);//T_{1}
    glEnd();

    //Left Side Doors
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-360,100);//I_{4}
    glVertex2f(-360,-60);//L_{4}=

    glVertex2f(-380,-20);//W_{3}=
    glVertex2f(-340,20);//K_{4}=

    glVertex2f(-380,20);//A_{4}=
    glVertex2f(-340,60);//J_{4}=

    glVertex2f(-380,50);//C_{4}
    glVertex2f(-340,90);//M_{4}
    glEnd();

    //Left Side
    glBegin(GL_POLYGON);
    glColor3ub(222, 75, 32);
    glVertex2f(-500,-80);//N
    glVertex2f(-540,-40);//Q_{1}
    glVertex2f(-540,120);//U_{1}
    glVertex2f(-500,80);//S_{1}
    glEnd();

    //Left Side Doors
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);

    glVertex2f(-500,-20);//V_{3}
    glVertex2f(-540,20);//D_{4}

    glVertex2f(-500,20);//Z_{3}=
    glVertex2f(-540,60);//E_{4}=

    glVertex2f(-500,50);//B_{4}=
    glVertex2f(-540,90);//F_{4}=

    glVertex2f(-520,-60);//H_{4}=
    glVertex2f(-520,100);//G_{4}=
    glVertex2f;//
    glVertex2f;//
    glVertex2f;//
    glEnd();


    //Upper Left Triangle
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 164);
    glVertex2f(-500,80);//S_{1}
    glVertex2f(-540,120);//U_{1}
    glVertex2f(-480,350);//L_{3}
    glEnd();

    //Upper Left Triangle Windows
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);

    glVertex2f(-520,100);//G_{4}
    glVertex2f(-480,350);//L_{3}


    glVertex2f(-520+22,100+10);//G_{4}
    glVertex2f(-480-52,350-200);//L_{3}

    glVertex2f(-496,140);//R_{4}
    glVertex2f(-524.2,180);//S_{4}

    glVertex2f(-494,170);//K_{2}
    glVertex2f(-516,210);//U_{4}

    glVertex2f(-491.5,200);//T_{4}
    glVertex2f(-508.5,240);//W_{4}

    glEnd();

    //Upper Right Triangle
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 164);
    glVertex2f(-380,80);//T_{1}
    glVertex2f(-340,120);//V_{1}
    glVertex2f(-400,350);//M_{3}
    glEnd();

    //Upper Right Triangle Windows
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-360,100);//I_{4}
    glVertex2f(-400,350);//M_{3}

    glVertex2f(-382,110);//Q_{4}
    glVertex2f(-348,150);//D_{5}

    glVertex2f(-384,140);//Z_{4}
    glVertex2f(-356,180);//E_{5}

    glVertex2f(-385,170);//A_{5}
    glVertex2f(-363.6,208);//F_{5}

    glVertex2f(-388,200);//B_{5}
    glVertex2f(-371.4,240);//G_{5}
    glEnd();




    //Upper Front View
    glBegin(GL_POLYGON);
    glColor3ub(0, 191, 255);
    glVertex2f(-500,80);//S_{1}
    glVertex2f(-380,80);//T_{1}
    glVertex2f(-400,350);//M_{3}
    glVertex2f(-480,350);//L_{3}
    glEnd();

    //Upper front Windows
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-460,80);//R_{3}
    glVertex2f(-455,350);//N_{4}

    glVertex2f(-425,350);//O_{4}
    glVertex2f(-420,80);//S_{3}

    glVertex2f(-498,110);//P_{4}
    glVertex2f(-382,110);//Q_{4}

    glVertex2f(-498+2,110+30);//P_{4}
    glVertex2f(-382-2,110+30);//Q_{4}

    glVertex2f(-498+4,110+60);//P_{4}
    glVertex2f(-382-4,110+60);//Q_{4}

    glVertex2f(-498+6,110+90);//P_{4}
    glVertex2f(-382-6,110+90);//Q_{4}

    glVertex2f(-498+8,110+120);//P_{4}
    glVertex2f(-382-8,110+120);//Q_{4}

    glVertex2f(-498+10,110+150);//P_{4}
    glVertex2f(-382-10,110+150);//Q_{4}

    glVertex2f(-498+12,110+180);//P_{4}
    glVertex2f(-382-12,110+180);//Q_{4}

    glVertex2f(-498+14,110+210);//P_{4}
    glVertex2f(-382-14,110+210);//Q_{4}
    glEnd();

    //Middle Line
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-540,120);//U_{1}
    glVertex2f(-500,80);//S_{1}

    glVertex2f(-500,80);//S_{1}
    glVertex2f(-380,80);//T_{1}

    glVertex2f(-380,80);//T_{1}
    glVertex2f(-340,120);//V_{1}
    glEnd();

    Building2_TOP_Part();
}

void Moon() //Mn
{
    float centerX = 480;
    float centerY = 420.0f;
    float radius = 50.0f;

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);

    for (int i = 0; i < 90; i++)
    {
        float pi = 3.1416f;
        float A = (i *2* pi) / 90; // Calculate angle
        float x = centerX + radius * cos(A); // Calculate x-coordinate
        float y = centerY + radius * sin(A); // Calculate y-coordinate
        glVertex2f(x, y); // Add vertex
    }
    glEnd();
}
void Stars() //str
{
    // Adding some stars
    glPointSize(2.0); // Set the size of the stars
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255); // White color for stars

    glVertex2d(-400, 400);
    glVertex2d(-200, 450);
    glVertex2d(0, 425);
    glVertex2d(200, 475);
    glVertex2d(400, 425);
    glVertex2d(-450, 350);
    glVertex2d(-350, 430);
    glVertex2d(-250, 410);
    glVertex2d(-150, 470);
    glVertex2d(-50, 390);
    glVertex2d(50, 460);
    glVertex2d(150, 415);
    glVertex2d(250, 480);
    glVertex2d(350, 405);
    glVertex2d(450, 470);
    glVertex2d(450, 200);
    glVertex2d(440, 470);

    glVertex2d(-500, 460);
    glVertex2d(-300, 470);
    glVertex2d(-100, 490);
    glVertex2d(100, 410);
    glVertex2d(300, 440);
    glVertex2d(500, 460);
    glVertex2d(-550, 370);
    glVertex2d(-450, 420);
    glVertex2d(-350, 395);
    glVertex2d(-250, 460);
    glVertex2d(-150, 380);
    glVertex2d(-50, 470);
    glVertex2d(50, 430);
    glVertex2d(150, 450);
    glVertex2d(250, 390);
    glVertex2d(350, 470);
    glVertex2d(450, 440);
    glVertex2d(550, 410);
    glVertex2d(-600, 400);
    glVertex2d(600, 450);
    glEnd();
}

void Night()
{
    // Set the sky to a dark blue color
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 139); // Dark Blue
    glVertex2d(-600, 500); // A
    glVertex2d(600, 500);  // D
    glVertex2d(600, 150);  // G_{2}
    glVertex2d(-600, 150); // F_{2}
    glEnd();
    Stars();
    Moon();
}
void Day(){
    glBegin(GL_POLYGON);
    glColor3ub(135,206,250);
    glVertex2d(-600, 500); // A
    glVertex2d(600, 500);  // D
    glVertex2d(600, 150);  // G_{2}
    glVertex2d(-600, 150); // F_{2}
    glEnd();
}
void Sun() //Sn
{
    float centerX = 480;
    float centerY = 420.0f;
    float radius = 50.0f;

    glBegin(GL_POLYGON);
    glColor3ub(237, 254, 87);

    for (int i = 0; i < 90; i++)
    {
        float pi = 3.1416f;
        float A = (i *2* pi) / 90; // Calculate angle
        float x = centerX + radius * cos(A); // Calculate x-coordinate
        float y = centerY + radius * sin(A); // Calculate y-coordinate
        glVertex2f(x, y); // Add vertex
    }
    glEnd();
}

void bluiding_ON_top_Charging_Station()//GlsBuild
{
    glPushMatrix();
    glTranslatef(-200,0,0);
    glScalef(1.3, 1.3, 1);
    glBegin(GL_POLYGON);
    glColor3ub(0, 191, 255);
    glVertex2f(242,102);//N_{5}
    glVertex2f(300,350);//M_{7}
    glVertex2f(584,117);//O _{5}
    glVertex2f(289,123);//R_{5}
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0, 0,0);

    glVertex2f(289,123);//R_{5}
    glVertex2f(300,350);//M_{7}

    glVertex2f(300,350);//M_{7}
    glVertex2f(242,102);//N_{5}

    glVertex2f(291,160);//N_{7}
    glVertex2f(530,160);//S_{7}

    glVertex2f(291,160);//N_{7}
    glVertex2f(251,140);//T_{7}

    glVertex2f(294,220);//O_{7}
    glVertex2f(458,220);//R_{7}

    glVertex2f(294,220);//O_{7}
    glVertex2f(265,200);//U_{7}

    glVertex2f(297,280);//P_{7}
    glVertex2f(384,280);//Q_{7}

    glVertex2f(297,280);//P_{7}
    glVertex2f(279,260);//V_{7}

    glVertex2f(300,350);//M_{7}
    glVertex2f(584,117);//O _{5}
    glEnd();
    glPopMatrix();


}
void charging_station() //CrgSt
{
    glPushMatrix();
    glTranslatef(-200,0,0);
    glScalef(1.3, 1.5, 1); // Try smaller scaling factors
    glBegin(GL_POLYGON);
    glColor3ub(71, 199, 6); //dark green
    glVertex2f(242,102);//N_{5}
    glVertex2f(242,89);//S_{5}
    glColor3ub(141, 234, 95);
    glVertex2f(289,102);//T_{5}
    glVertex2f(289,123);//R_{5}
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 199, 6);//Lite green
    glVertex2f(289,102);//T_{5}
    glVertex2f(289,123);//R_{5}
    glColor3ub(121, 216, 73);
    glVertex2f(584,117);//O _{5}
    glVertex2f(584,102);//U_{5}
    glEnd();

    //white roof
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(242,89);//S_{5}
    glVertex2f(289,102);//T_{5}
    glVertex2f(584,102);//U_{5}
    glVertex2f(460,90);//V_{5}
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(18, 32, 75);
    glVertex2f(267,88);//Z_{5}
    glVertex2f(272,-22);//P_{5}
    glVertex2f(286,-24);//Q_{5}
    glVertex2f(296,96);//W_{5}
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(18, 32, 75);
    glVertex2f(493,93);//C_{6}
    glVertex2f(497,-21);//D_{6}
    glVertex2f(512,-24);//E_{6}
    glVertex2f(521,96);//F_{6}
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 199, 6); //dark green
    glVertex2f(383,121);//M_{6}
    glVertex2f(383,144);//O_{6}
    glColor3ub(71, 150, 6);//Lite green
    glVertex2f(388,149);//P_{6}
    glVertex2f(389,121);//N_{6}
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(71, 199, 6); //dark green
    glVertex2f(389,121);//N_{6}
    glVertex2f(388,149);//P_{6}
    glColor3ub(71, 199, 6);//Lite green
    glVertex2f(470,146);//Q_{6}
    glVertex2f(470,119);//R_{6}
    glEnd();

    //Charger
    glBegin(GL_POLYGON);
    glColor3ub(71, 199, 6); //dark green
    glVertex2f(295,-26);//I_{6}
    glVertex2f(319,-26);//J_{6}
    glColor3ub(211, 214, 209);//off white
    glVertex2f(323,42);//K_{6}
    glVertex2f(296,41);//L_{6}
    glEnd();

    int x=70;
    glBegin(GL_POLYGON);
    glColor3ub(71, 199, 6); //dark green
    glVertex2f(295+x,-26);//I_{6}
    glVertex2f(319+x,-26);//J_{6}
    glColor3ub(211, 214, 209);//off white
    glVertex2f(323+x,42);//K_{6}
    glVertex2f(296+x,41);//L_{6}
    glEnd();

    int y=80;
    glBegin(GL_POLYGON);
    glColor3ub(71, 199, 6); //dark green
    glVertex2f(295+x+y,-26);//I_{6}
    glVertex2f(319+x+y,-26);//J_{6}
    glColor3ub(211, 214, 209);//off white
    glVertex2f(323+y+x,42);//K_{6}
    glVertex2f(296+x+y,41);//L_{6}
    glEnd();

    glPopMatrix();

}

void Bulding_between_1and2() //SkyScrp_6
{

    glBegin(GL_POLYGON);
    glColor3ub(20, 143, 119);
    glVertex2f(-380,20);//A_{4}
    glVertex2f(-380,275);//W_{7}
    glVertex2f(-380,300);//Z_{7}
    glVertex2f(-372,320);//B_{8}
    glVertex2f(-360,330);//D_{8}
    glVertex2f(-350,330);//F_{8}
    glVertex2f(-350,340);//H_{8}
    glVertex2f(-340,345);//J_{8}
    glVertex2f(-330,340);//I_{8}
    glVertex2f(-330,330);//G_{8}
    glVertex2f(-320,330);//E_{8}
    glVertex2f(-312,320);//C_{8}
    glVertex2f(-304,300);//A_{8}
    glVertex2f(-304,20);//K_{8}
    glEnd();


    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-380,300);//Z_{7}
    glVertex2f(-304,300);//A_{8}
    glVertex2f(-380,300);//Z_{7}
    glVertex2f(-372,320);//B_{8}
    glVertex2f(-372,320);//B_{8}
    glVertex2f(-312,320);//C_{8}
    glVertex2f(-320,330);//E_{8}
    glVertex2f(-360,330);//D_{8}
    glVertex2f(-350,340);//H_{8}
    glVertex2f(-350,330);//F_{8}
    glVertex2f(-350,340);//H_{8}
    glVertex2f(-340,345);//J_{8}
    glVertex2f(-340,345);//J_{8}
    glVertex2f(-330,340);//I_{8}
    glVertex2f(-330,340);//I_{8}
    glVertex2f(-330,330);//G_{8}
    glVertex2f(-330,330);//G_{8}
    glVertex2f(-320,330);//E_{8}
    glVertex2f(-320,330);//E_{8}
    glVertex2f(-312,320);//C_{8}
    glVertex2f(-312,320);//C_{8}
    glVertex2f(-304,300);//A_{8}
    glVertex2f(-372,320);//B_{8}
    glVertex2f(-360,330);//D_{8}

    glVertex2f(-331,20);//L8
    glVertex2f(-330,330);//G_{8}
    glVertex2f(-350,330);//F_{8}
    glVertex2f(-350,20);//M_{8}


    int x=20;
    for(int i = 1; i<15; i++)
    {
        glVertex2f(-380,300-x*i);//Z_{7}
        glVertex2f(-304,300-x*i);//A_{8}
    }


    glVertex2f(-304,300);//A_{8}
    glVertex2f(-304,20);//K_{8}


    glVertex2f(-380,20);//A_{4}
    glVertex2f(-380,300);//Z_{7}

    glEnd();
    glLineWidth(1.3);
    glBegin(GL_LINES);
    glVertex2f(-340,345);//J_{8}
    glVertex2f(-340,380);//N_{8}
    glEnd();


}
void Escalator1()//Esc1
{
    //Es_1
    glBegin(GL_POLYGON);
    glColor3ub(18, 32, 75);
    glVertex2f(-600,-190);//k_{1}
    glVertex2f(600,-190);//J_{1}
    glVertex2f(600,-140);//L_{1}
    glVertex2f(-600,-140);//W_{1}
    glEnd();

}
void Escalator_1_MovingPart() //Esc1_MovingPt
{
    glPushMatrix();
    glTranslatef(-motion_Escalator_1,0,0);
    int x = 44;
    //int startX = -560;
    int startX = -1000;

    // Loop to create multiple lines
    for (int i = 0; i < 120; i++)
    {
        glLineWidth(8);
        glBegin(GL_LINES);
        glColor3ub(230, 238, 0);
        glVertex2f(startX + i * x, -140);
        glVertex2f(startX + i * x, -190);
        glEnd();
    }
    glPopMatrix();
}
void Escalator2()//Esc2
{
    //ES_2
    glPushMatrix();
    glTranslatef(0,-270,0);
    glBegin(GL_POLYGON);
    glColor3ub(18, 32, 75);
    glVertex2f(-600,-190);//k_{1}
    glVertex2f(600,-190);//J_{1}
    glVertex2f(600,-140);//L_{1}
    glVertex2f(-600,-140);//W_{1}
    glEnd();

    glPopMatrix();
}
void Escalator_2_MovingPart() //Esc2_MovingPt
{
    glPushMatrix();
    glTranslatef(motion_Escalator_1,-270,0);
    int x = 44;
    //int startX = -560;
    int startX = -1500;

    // Loop to create multiple lines
    for (int i = 0; i < 120; i++)
    {
        glLineWidth(8);
        glBegin(GL_LINES);
        glColor3ub(230, 238, 0);
        glVertex2f(startX + i * x, -140);
        glVertex2f(startX + i * x, -190);
        glEnd();
    }
    glPopMatrix();
}
void Ground() //Grnd
{
    glBegin(GL_POLYGON);
    glColor3ub(128, 128, 128);
    glVertex2f(-600,-500);//B
    glVertex2f(600,-500);//C
    glVertex2f(600,150);//G_{2}
    glVertex2f(-600,150);//F_{2}
    glEnd();
}
void Bus_Stop() //BStp
{
    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-140,200);//Q_{8}
    glVertex2f(120,200);//T_{8}
    glVertex2f(120,185);//E_{9}
    glVertex2f(-140,185);//Z_{8}
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2f(-140,185);//Z_{8}
    glVertex2f(120,185);//E_{9}
    glVertex2f(120,170);//C_{9}
    glVertex2f(-140,170);//U_{8}
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(0, 191, 255);
    glVertex2f(-100,150);//H_{9}
    glVertex2f(80,150);//G_{9}=
    glVertex2f(80,50);//J_{9}=
    glVertex2f(-100,50);//I_{9}=
    glEnd();

    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-120,170);//V_{8}=
    glVertex2f(-120,50);//A_{9}=

    glVertex2f(100,170);//W_{8}=
    glVertex2f(100,50);//F_{9}


    glVertex2f(-100,160);//H_{9}
    glVertex2f(-100,50);//I_{9}

    glVertex2f(-35,160);//K_{9}
    glVertex2f(-35,50);//O_{9}

    glVertex2f(25,160);//L_{9}
    glVertex2f(25,50);//M_{9}

    glVertex2f(80,160);//G_{9}
    glVertex2f(80,50);//J_{9}

    glVertex2f(-100,150);//H_{9}
    glVertex2f(80,150);//G_{9}
    glEnd();
}
void Bench(int x,int y) //Bn_1,2,3,4,5
{
    glPushMatrix();
    glTranslatef(x,y,0);
    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3ub(149, 88, 70);
    glVertex2f(-96,50);//N_{9}
    glVertex2f(-96,94);//Q_{9}

    glVertex2f(-38,94);//R_{9}
    glVertex2f(-38,50);//P_{9}
    glEnd();

    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3ub(241, 196, 15);

    glVertex2f(-110,80+10);//S_{9}
    glVertex2f(-25,80+10);//T_{9}

    glVertex2f(-110,80);//S_{9}
    glVertex2f(-25,80);//T_{9}

    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(241, 196, 15);
    glVertex2f(-105,70);//W_{9}
    glVertex2f(-28.0186249832127+5,69.9825282637824);//A_{10}
    glVertex2f(-36.3703802696617+5,60.071778657197);//B_{10}
    glVertex2f(-115,60);//Z_{9}
    glEnd();
    glPopMatrix();
}

void skyScraper_Most_Left_Side_Back()//SkyScrp_1
{
    glPushMatrix();
    glTranslated(-1100,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(26, 82, 118);
    glVertex2f(548,271); //G_{10}
    glVertex2f(597,271); //H_{10}
    glVertex2f(597,35);  //I_{10}
    glVertex2f(548,35);  //J_{10}
    glEnd();

    // window offsets
    float xOffset = 11.5;
    float yOffset = 19.1;

    //window
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            glBegin(GL_POLYGON);
            glColor3ub(56, 160, 187);
            glVertex2f(552 + i * xOffset, 57 + j * yOffset);
            glVertex2f(558 + i * xOffset, 57 + j * yOffset);
            glVertex2f(558 + i * xOffset, 42 + j * yOffset);
            glVertex2f(552 + i * xOffset, 42 + j * yOffset);
            glEnd();
        }
    }
    glBegin(GL_POLYGON);
    glColor3ub(26, 82, 118);
    glVertex2f(563,288);//Q_{10}
    glVertex2f(582,288);//P_{10}
    glVertex2f(582,271);//O_{10})
    glVertex2f(563,271);//R_{10}
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(26, 82, 118);
    glVertex2f(563,288);//Q_{10}
    glVertex2f(582,288);//P_{10}
    glVertex2f(573,300);//S_{10}
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(56, 160, 187);
    glVertex2f(575,273);//W_{10}
    glVertex2f(580,273);//T_{10}
    glVertex2f(580,285);//U_{10}
    glVertex2f(575,285);//V_{10}
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(56, 160, 187);
    glVertex2f(575-9,273);//W_{10}
    glVertex2f(580-9,273);//T_{10}
    glVertex2f(580-9,285);//U_{10}
    glVertex2f(575-9,285);//V_{10}
    glEnd();
    glPopMatrix();
}
void skyScraper_Most_right_Side() //SkyScrp_2
{

    glBegin(GL_POLYGON);
    glColor3ub(222, 78, 78);
    glVertex2f(548,271); //G_{10}
    glVertex2f(597,271); //H_{10}
    glVertex2f(597,35);  //I_{10}
    glVertex2f(548,35);  //J_{10}
    glEnd();

    // window offsets
    float xOffset = 11.5;
    float yOffset = 19.1;

    //window
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            glBegin(GL_POLYGON);
            if(isNight)
                glColor3ub(197, 191, 3);
            else
                glColor3ub(56, 160, 187);
            glVertex2f(552 + i * xOffset, 57 + j * yOffset); // Adjusted x and y positions
            glVertex2f(558 + i * xOffset, 57 + j * yOffset);
            glVertex2f(558 + i * xOffset, 42 + j * yOffset);
            glVertex2f(552 + i * xOffset, 42 + j * yOffset);
            glEnd();
        }
    }
    glBegin(GL_POLYGON);
    glColor3ub(222, 78, 78);
    glVertex2f(563,288);//Q_{10}
    glVertex2f(582,288);//P_{10}
    glVertex2f(582,271);//O_{10}
    glVertex2f(563,271);//R_{10}
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(222, 78, 78);
    glVertex2f(563,288);//Q_{10}
    glVertex2f(582,288);//P_{10}
    glVertex2f(573,300);//S_{10}
    glEnd();

    //Two Upper Window
    glBegin(GL_POLYGON);
    if(isNight)
        glColor3ub(197, 191, 3);
    else
        glColor3ub(56, 160, 187);
    glVertex2f(575,273);//W_{10}
    glVertex2f(580,273);//T_{10}
    glVertex2f(580,285);//U_{10}
    glVertex2f(575,285);//V_{10}
    glEnd();

    glBegin(GL_POLYGON);
    if(isNight)
        glColor3ub(197, 191, 3);
    else
        glColor3ub(56, 160, 187);
    glVertex2f(575-9,273);//W_{10}
    glVertex2f(580-9,273);//T_{10}
    glVertex2f(580-9,285);//U_{10}
    glVertex2f(575-9,285);//V_{10}
    glEnd();
}
void skyScraper_Most_Left_Side() //SkyScrp_3
{

    glBegin(GL_POLYGON);
    glColor3ub(222, 78, 78);
    glVertex2f(-592,326);//D_{11}
    glVertex2f(-543,326);//E_{11}
    glVertex2f(-543,29);//G_{11}
    glVertex2f(-592,29);//F_{11}
    glEnd();

    float x = 4.8;
    glLineWidth(2);
    for(int i = 0; i<10; i++)
    {
        glBegin(GL_LINES);
        if(isNight)
            glColor3ub(200, 200, 58); // Sky blue color
        else
            glColor3ub(255,255,255);
        glVertex2f(-590+x*i,320);//I_{11}
        glVertex2f(-590+x*i,47);//H_{11}
        glEnd();
    }
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(-567,360);//J_{11}
    glVertex2f(-567,437);//T_{11}
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(222, 78, 78);
    glVertex2f(-592,326);//D_{11}
    glVertex2f(-543,326);//E_{11}
    glVertex2f(-567,363);//J_{11}
    glEnd();
}

void skyScraper_Middle()//SkyScrp_4
{
    //Right
    glBegin(GL_POLYGON);
    glColor3ub(205, 97, 85);
    glVertex2f(41,130);//P_{12}
    glVertex2f(88,130);//M_{12}
    glVertex2f(88,293);//N_{12}
    glVertex2f(41,293);//O_{12}
    glEnd();

    //Right Top
    glBegin(GL_POLYGON);
    glColor3ub(205, 97, 85);
    glVertex2f(37,293);//E_{13}
    glVertex2f(37,300);//F_{13}
    glVertex2f(91,300);//G_{13}
    glVertex2f(91,293);//H_{13}
    glEnd();
    //right Windows
    float Rx=10;
    float Ry=10;
    for(int i =0; i<4; i++)
    {
        for(int j=0; j<15; j++)
        {
            glBegin(GL_POLYGON);
            if(isNight)
            {
                glColor3ub(197, 191, 3);
            }
            else
            {
                glColor3ub(0,0,0);
            }
            glVertex2f(45+Rx*i,290-Ry*j);//P_{13}
            glVertex2f(53+Rx*i,290-Ry*j);//Q_{13}
            glVertex2f(53+Rx*i,283-Ry*j);//R_{13}
            glVertex2f(45+Rx*i,283-Ry*j);//S_{13}
            glEnd();
        }
    }

    //Middle
    glBegin(GL_POLYGON);
    glColor3ub(205, 97, 85);
    glVertex2f(-37,130);//R_{12}
    glVertex2f(38,130);//Q_{12}
    glVertex2f(38,408);//S_{12}
    glVertex2f(-37,408);//T_{12}
    glEnd();

    //Middle top
    glBegin(GL_POLYGON);
    glColor3ub(205, 97, 85);
    glVertex2f(-42,408);//I_{13}
    glVertex2f(-42,420);//J_{13}
    glVertex2f(42,420);//K_{13}
    glVertex2f(42,408);//L_{13}
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(205, 97, 85);
    glVertex2f(-32,420);//M_{13}
    glVertex2f(0,460);//O_{13}
    glVertex2f(32,420);//N_{13}
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0,460);//O_{13}
    glVertex2f(0,480);//K_{12}
    glEnd();

    //Middle Windows
    float Mx=15;
    float My=15;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<17; j++)
        {
            glBegin(GL_POLYGON);
            if(isNight)
            {
                glColor3ub(197, 191, 3);
            }
            else
            {
                glColor3ub(0,0,0);
            }
            glVertex2f(-27+i*Mx,390-j*My);//B_{14}
            glVertex2f(-16+i*Mx,390-j*My);//C_{14}
            glVertex2f(-16+i*Mx,400-j*My);//A_{14}
            glVertex2f(-27+i*Mx,400-j*My);//Z_{13}
            glEnd();
        }
    }


    //Left
    glBegin(GL_POLYGON);
    glColor3ub(205, 97, 85);
    glVertex2f(-98,130);//L_{12}
    glVertex2f(-40,130);//U_{12}
    glVertex2f(-40,285);//W_{12}
    glVertex2f(-98,285);//V_{12}
    glEnd();

    //Left Top
    glBegin(GL_POLYGON);
    glColor3ub(205, 97, 85);
    glVertex2f(-102,285);//D_{13}
    glVertex2f(-102,293);//C_{13}
    glVertex2f(-37,293);//B_{13}
    glVertex2f(-37,285);//A_{13}
    glEnd();

    float Lx = 8;
    for (int i = 0; i < 15; i++)
    {
        glBegin(GL_POLYGON);
        if(isNight)
        {
            glColor3ub(197, 191, 3);
        }
        else
        {
            glColor3ub(0,0,0);
        }
        glVertex2f(-91, 277 - Ry * i+Lx); //T_{13}
        glVertex2f(-49, 277 - Ry * i+Lx); //V_{13}
        glVertex2f(-49, 270 - Ry * i+Lx); //W_{13}
        glVertex2f(-91, 270 - Ry * i+Lx); //U_{13}
        glEnd();
    }

}
void cloud() //Cd
{
    glPushMatrix();
    glScaled(0.7,0.7,1);
    glTranslated(700-cloud_motion,100,0);
    circle(50, 450, 445, 255, 255, 255);
    circle(50, 400, 445, 255, 255, 255);
    circle(50, 450, 395, 255, 255, 255);
    circle(50, 500, 395, 255, 255, 255);
    circle(50, 370, 395, 255, 255, 255);

    circle(40, 200, 320, 255, 255, 255);
    circle(35, 150, 320, 255, 255, 255);
    circle(60, 200, 270, 255, 255, 255);
    circle(30, 250, 270, 255, 255, 255);
    circle(45, 120, 270, 255, 255, 255);

    int x =100;
    int y =200;
    circle(40, 200-x, 320+y, 255, 255, 255);
    circle(35, 150-x, 320+y, 255, 255, 255);
    circle(60, 200-x, 270+y, 255, 255, 255);
    circle(30, 250-x, 270+y, 255, 255, 255);
    circle(45, 120-x, 270+y, 255, 255, 255);


    glPopMatrix();
}
void flying_Vehicle() //FCr
{
    glPushMatrix();
    if(flying_Vehicle_motion_Y>500)
    {
        glTranslatef(-flying_Vehicle_motion_X,500,0);
    }
    else
    {
        glTranslatef(0,flying_Vehicle_motion_Y,0);
    }
    glBegin(GL_POLYGON);
    glColor3ub(144, 0, 35);
    glVertex2f(434,-91);//G_{6}
    glVertex2f(434,-62);//H_{14}
    glVertex2f(460,-64);//P_{14}
    glVertex2f(479,-38);//Q_{14}
    glColor3ub(114, 0, 35);
    glVertex2f(532,-38);//R_{14}
    glVertex2f(548,-62);//O_{14})
    glVertex2f(596,-62);//I_{14}
    glVertex2f(596,-91);//J_{14}
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(430,-91);//K_{14}
    glVertex2f(600,-91);//M_{14}
    glVertex2f(600,-98);//N_{14}
    glVertex2f(430,-98);//L_{14}
    glEnd();

    //Lower Body
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(455,-98);//C_{15}
    glVertex2f(487,-98);//D_{15}
    glVertex2f(492,-103);//H_{15}
    glVertex2f(492,-117);//I_{15}
    glVertex2f(450,-117);//J_{15}
    glVertex2f(450,-103);//G_{15}
    glEnd();
    int x = 90;
    glBegin(GL_POLYGON);
    glVertex2f(455+x,-98);//C_{15}
    glVertex2f(487+x,-98);//D_{15}
    glVertex2f(492+x,-103);//H_{15}
    glVertex2f(492+x,-117);//I_{15}
    glVertex2f(450+x,-117);//J_{15}
    glVertex2f(450+x,-103);//G_{15}
    glEnd();

    //lowest
    glBegin(GL_POLYGON);
    glColor3ub(255, 49, 49);
    glVertex2f(463,-117);//K_{15}
    glVertex2f(480,-117);//L_{15}
    glVertex2f(480,-125);//N_{15}
    glVertex2f(463,-125);//M_{15}
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 49, 49);
    glVertex2f(463+x,-117);//K_{15}
    glVertex2f(480+x,-117);//L_{15}
    glVertex2f(480+x,-125);//N_{15}
    glVertex2f(463+x,-125);//M_{15}
    glEnd();

    //Glass
    glColor3ub(0, 191, 255);
    glBegin(GL_POLYGON);
    glVertex2f(480,-42);//T_{14}
    glVertex2f(500,-42);//S_{14}
    glVertex2f(500,-64);//V_{14}
    glVertex2f(462,-64);//U_{14}
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(504,-42);//Z_{14}
    glVertex2f(531,-42);//A_{15}
    glVertex2f(543,-63);//B_{15}
    glVertex2f(504,-63);//W_{14}
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0,255,255);
    glVertex2d(462,-68);//O_{15}
    glVertex2d(472,-68);//P_{15}

    glVertex2d(462+53,-68);//O_{15}
    glVertex2d(472+53,-68);//P_{15}
    glEnd();

    //Car fire
    int y=5;
    glBegin(GL_POLYGON);
    glColor3ub(243, 156, 18);
    glVertex2f(463,-125-y);//M_{15}
    glVertex2f(480,-125-y);//N_{15}
    glVertex2d(486,-136);//W_{15}
    glVertex2d(476,-132-y);//V_{15}
    glVertex2d(471,-144-y);//U_{15}
    glVertex2d(467,-131-y);//T_{15}
    glVertex2d(457,-136);//S_{15}
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2f(463,-125);//M_{15}
    glVertex2f(480,-125);//N_{15}
    glVertex2d(486,-136);//W_{15}
    glVertex2d(476,-132);//V_{15}
    glVertex2d(471,-144);//U_{15}
    glVertex2d(467,-131);//T_{15}
    glVertex2d(457,-136);//S_{15}
    glEnd();
    //end one

    glBegin(GL_POLYGON);
    glColor3ub(243, 156, 18);
    glVertex2f(463+x,-125-y);//M_{15}
    glVertex2f(480+x,-125-y);//N_{15}
    glVertex2d(486+x,-136);//W_{15}
    glVertex2d(476+x,-132-y);//V_{15}
    glVertex2d(471+x,-144-y);//U_{15}
    glVertex2d(467+x,-131-y);//T_{15}
    glVertex2d(457+x,-136);//S_{15}
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2f(463+x,-125);//M_{15}
    glVertex2f(480+x,-125);//N_{15}
    glVertex2d(486+x,-136);//W_{15}
    glVertex2d(476+x,-132);//V_{15}
    glVertex2d(471+x,-144);//U_{15}
    glVertex2d(467+x,-131);//T_{15}
    glVertex2d(457+x,-136);//S_{15}
    glEnd();

    glPopMatrix();

}
void Building_2nd_Most_Right_Side() //SkyScrp_5
{
    //BOX
    glBegin(GL_POLYGON);
    glColor3ub(56,90,100);
    glVertex2f(435,301);//N_{16}
    glVertex2f(542,360);//R_{16}
    glVertex2f(542,46);//P_{16}
    glVertex2f(435,46);//Q_{16}
    glEnd();

    //Left side Color
    glBegin(GL_POLYGON);
    glColor3ub(33,62,68);
    glVertex2f(435,301);//N_{16}
    glVertex2f(463,315);//S_{16}
    glVertex2f(463,39);//O_{16}
    glVertex2f(435,46);//Q_{16}
    glEnd();

    //Window Middle
    glBegin(GL_POLYGON);
    if(isNight)
        glColor3ub(255, 191, 3);
    else
        glColor3ub(238,240,228);
    glVertex2f(468,294+23);//T_{16}
    glVertex2f(508,294+23);//U_{16}
    glVertex2f(508,284+23);//V_{16}
    glVertex2f(468,284+23);//W_{16}
    glEnd();


    int Diff=25;
    for(int i = 0; i<10; i++)
    {
        glBegin(GL_POLYGON);
        if(isNight)
            glColor3ub(255, 191, 3);
        else
            glColor3ub(238,240,228);
        //Middle Window
        glVertex2f(468,294-i*Diff);//T_{16}
        glVertex2f(508,294-i*Diff);//U_{16}
        glVertex2f(508,284-i*Diff);//V_{16}
        glVertex2f(468,284-i*Diff);//W_{16}
        glEnd();
        //Right Window
        glBegin(GL_POLYGON);
        glVertex2f(517,294-i*Diff);//C_{17}
        glVertex2f(537,294-i*Diff);//Z_{16}
        glVertex2f(537,283-i*Diff);//A_{17}
        glVertex2f(517,283-i*Diff);//B_{17}
        glEnd();
        //Window Left
        glBegin(GL_POLYGON);
        glVertex2f(451,294-i*Diff);//F_{17}
        glVertex2f(461,294-i*Diff);//E_{17}
        glVertex2f(461,283-i*Diff);//D_{17}
        glVertex2f(451,283-i*Diff);//G_{17}
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(437,294-i*Diff);//F_{17}
        glVertex2f(447,294-i*Diff);//E_{17}
        glVertex2f(447,283-i*Diff);//D_{17}
        glVertex2f(437,283-i*Diff);//G_{17}
        glEnd();
    }
    //Window Right
    glBegin(GL_POLYGON);
    if(isNight)
        glColor3ub(255, 191, 3);
    else
        glColor3ub(238,240,228);
    glVertex2f(517,294+23);//C_{17}
    glVertex2f(537,294+23);//Z_{16}
    glVertex2f(537,283+23);//A_{17}
    glVertex2f(517,283+23);//B_{17}
    glEnd();
    glBegin(GL_POLYGON);
    if(isNight)
        glColor3ub(255, 191, 3);
    else
        glColor3ub(238,240,228);
    glVertex2f(517,294+23*2);//C_{17}
    glVertex2f(537,294+23*2);//Z_{16}
    glVertex2f(537,283+23*2);//A_{17}
    glVertex2f(517,283+23*2);//B_{17}
    glEnd();
}
void car_opposite_Side(int positionX, int positionY,int direction, int r, int g, int b, int Motion) //MCr_color_Direction
{
    glPushMatrix();
    glScalef(direction, 1.0, 1.0);       // Flip horizontally
    glTranslated(-Motion+positionX,-15+positionY,0);
    glBegin(GL_POLYGON);
    glColor3ub(r,g,b);//72,156,237
    glVertex2f(245,-342);//I_{17}
    glVertex2f(251,-335);//J_{17}
    glVertex2f(290,-324);//K_{17}
    glVertex2f(333,-320);//N_{17}
    glVertex2f(365,-300);//O _{17}
    glVertex2f(369,-301);//P_{17}
    glVertex2f(344,-323);//Q _{17}
    glVertex2f(406,-314);//Z_{17}
    glVertex2f(439,-307);//A_{18}
    glVertex2f(443,-316);//B_{18}
    glVertex2f(493,-319);//C_{18}
    glVertex2f(494,-323);//D_{18}
    glVertex2f(493,-337);//E_{18}
    glVertex2f(498,-343);//F_{18}
    glVertex2f(496,-349);//G_{18}
    glVertex2f(463,-359);//H_{18}
    glVertex2f(422,-362);//I_{18}
    glVertex2f(314,-362);//J_{18}
    glVertex2f(274,-361);//K_{18}
    glVertex2f(260,-360);//H_{17}
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(51,112,166);
    glVertex2f(316,-347);//M_{18}
    glVertex2f(425,-330);//N_{18}
    glVertex2f(419,-346);//O _{18}
    glVertex2f(340,-354);//P_{18}
    glVertex2f(417,-355.5);//Q _{18}
    glVertex2f(422,-362);//I_{18}
    glVertex2f(314,-362);//J_{18}
    glEnd();

    //Back Light
    glBegin(GL_POLYGON);
    if(isNight)
    glColor3ub(160,50,50);
    else
    glColor3ub(204,202,200);
    glVertex2f(494,-323);//D_{18}
    glVertex2f(493,-337);//E_{18}
    glVertex2f(483,-341);//T_{18}
    glVertex2f(483,-330);//S_{18}
    glEnd();
    //front Light
    glBegin(GL_POLYGON);
    if(isNight)
    glColor3ub(255,255,0);
    else
    glColor3ub(204,202,200);
    glVertex2f(245,-342);//I_{17}
    glVertex2f(260,-342);//U_{18}
    glVertex2f(263,-348);//V_{18
    glVertex2f(255,-349);//W_{18}
    glEnd();

    //Front glass
    glBegin(GL_POLYGON);
    glColor3ub(195,202,208);
    glVertex2f(310,-320);//N_{17}
    glVertex2f(365,-300);//O_{17}
    glVertex2f(369,-301);//P_{17}
    glVertex2f(325,-320);//Q_{17}
    glEnd();

    //left wheel
    circle(18, 293,-355, 0, 0, 0); // Left wheel
    circle(13, 293,-355, 255, 255, 255); // Left wheel
    //Right wheel
    circle(18, 442,-355, 0, 0, 0); // Left wheel
    circle(13, 442,-355, 255, 255, 255); // Left wheel
    glPopMatrix();
}
void trafficLight(int x, int y) //TF Lt_1,2
{
    glPushMatrix();
    glScaled(1.5,1.5,1);
    glTranslated(x,y,0);
    glBegin(GL_POLYGON);
    glColor3ub(70, 70, 70);
    glVertex2f(-207,-119);//E_{16}
    glVertex2f(-194,-119);//H_{16}
    glVertex2f(-197,-115);//G_{16}
    glVertex2f(-205,-115);//F_{16}
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-202,-115);//J_{16}
    glVertex2f(-199,-115);//I_{16}
    glVertex2f(-199,-72);//I_{19}
    glVertex2f(-202,-72);//K_{16}
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(51,51,51);
    glVertex2f(-208,-72);//J_{19}
    glVertex2f(-194,-72);//K_{19}
    glVertex2f(-194,-33);//M_{19}
    glVertex2f(-208,-33);//L_{19}
    glEnd();


    glColor3ub(60,60,60);
    for (int i = 0; i < 3; i++)
    {
    glBegin(GL_TRIANGLES);
    glVertex2f(-212, -35 - (10 * i)); // P_{19}
    glVertex2f(-208, -35 - (10 * i)); // N_{19}
    glVertex2f(-208, -43 - (10 * i)); // O_{19}
    glEnd();
    }

    for (int i = 0; i < 3; i++) {
    glBegin(GL_TRIANGLES);
    glVertex2f(-194, -35 - (10 * i)); // P_{19}
    glVertex2f(-190, -35 - (10 * i)); // N_{19}
    glVertex2f(-194, -43 - (10 * i)); // O_{19}
    glEnd();
    }
    circle(5,-200.5126903786498,-40.0196195725485,255,4,1);
    circle(5,-200.5126903786498,-63.4251728082315,8,255,0);
    circle(5,-200.5126903786498,-51.6195740039058,255,207,0);
    glPopMatrix();
}
void PaperBox(int x,int y,float Motion)//PprBx_1
{
    glPushMatrix();
    glTranslatef(x+Motion,y,0);
    //top
    glBegin(GL_POLYGON);
    glColor3ub(250, 171, 96);
    glVertex2f(-521,-153);//F_{19}
    glVertex2f(-500,-164);//H_{19}
    glVertex2f(-480,-153);//D_{19}
    glVertex2f(-500,-143);//E_{19}
    glEnd();

    //left
    glBegin(GL_POLYGON);
    glColor3ub(250, 161, 93);
    glVertex2f(-521,-153);//F_{19}
    glVertex2f(-500,-164);//H_{19}
    glVertex2f(-500,-184);//B_{19}
    glVertex2f(-521,-175);//G_{19}
    glEnd();

    //Right
    glBegin(GL_POLYGON);
    glColor3ub(240, 149, 82);
    glVertex2f(-480,-153);//D_{19}
    glVertex2f(-500,-164);//H_{19}
    glVertex2f(-500,-184);//B_{19}
    glVertex2f(-480,-175);//C_{19}
    glEnd();
    glPopMatrix();
}
void LampPost(int x, int y, float Sx, float Sy)//Lm pst 01,02,03,04,05,06
{
    glPushMatrix();
    glScaled(Sx,Sy,1);
    glTranslated(x,y,0);
    glBegin(GL_POLYGON);
    glColor3ub(64,88,104);
    glVertex2d(-317,-120);//A_{20}
    glVertex2d(-316,-117);//E_{20}
    glVertex2d(-305,-117);//F_{20}
    glVertex2d(-307,-120);//B_{20}
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(-314,-117);//G_{20}
    glVertex2d(-307,-117);//H_{20}
    glVertex2d(-306.5,-101);//J_{20}
    glVertex2d(-314.5,-101);//I_{20}
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(-306.5,-101);//J_{20}
    glVertex2d(-314.5,-101);//I_{20}
    glVertex2d(-312,-92);//K_{20}
    glVertex2d(-309,-92);//L_{20}
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(-312,-92);//K_{20}
    glVertex2d(-309,-92);//L_{20}
    glVertex2d(-309,-3);//M_{20}
    glVertex2d(-312,-3);//N_{20}
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(-309,-13);//S_{20}
    glVertex2d(-309,-10);//O_{20}
    glVertex2d(-285,-0);//Q _{20}
    glVertex2d(-285,-3);//T_{20}
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(-285,-0);//Q _{20}
    glVertex2d(-270,1);//P_{20}
    glVertex2d(-266,-6);//R_{20}
    glVertex2d(-284,-6);//U_{20}
    glEnd();
    glPopMatrix();
}
void LampPost_Light(int x, int y, float Sx, float Sy)// Lm pst lt 01,02,03,04,05,06
{
    glPushMatrix();
    glScaled(Sx,Sy,1);
    glTranslated(x,y,0);
    if(isNight){
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 50); // Dark Blue
    glVertex2d(-266,-6);//R_{20}
    glVertex2d(-284,-6);//U_{20}
    glColor3ub(51, 51, 51); // Dark Blue
    glVertex2d(-294,-110);//
    glVertex2d(-230,-110);//
    glEnd();
    }
    glPopMatrix();
}
void Charging_poin(int x,int y)//Crg Pt_01,2,3
{

    glPushMatrix();
    glTranslated(x,y,0);
    glBegin(GL_POLYGON);
    glColor3ub(29,173,78);
    glVertex2d(-377,-110);//N_{19}
    glVertex2d(-337,-110);//M_{19}
    glVertex2d(-337,-204);//L_{19}
    glVertex2d(-377,-204);//K_{19}
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(-380,-204);//A_{20}
    glVertex2d(-334,-204);//B_{20
    glVertex2d(-334,-208);//D_{20}
    glVertex2d(-380,-208);//C_{20}
    glEnd();

    glBegin(GL_POLYGON);
    if(isNight)
    glColor3ub(0, 251, 255);
    else
    glColor3ub(255,255,255);
    glVertex2d(-373,-120);//O _{19}
    glVertex2d(-341,-120);//P_{19
    glVertex2d(-341,-140);//Q_{19}
    glVertex2d(-373,-140);//R_{19}
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2d(-365,-181);//S_{19}
    glVertex2d(-355,-162);//T_{19}
    glVertex2d(-355,-179);//U_{19}
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2d(-358,-176);//W_{19}
    glVertex2d(-349,-174);//V_{19}
    glVertex2d(-361,-194);//Z_{19}
    glEnd();
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    if(isNight)
    {
        Night();
    }
    else
    {   Day();
        Sun(); //Sn
        cloud(); //Cd
    }
    Ground();//Grnd
    Bulding_between_1and2(); //SkyScrp_6
    Building1();//Build_1
    Escalator1();//Esc1
    Escalator_1_MovingPart();//Esc1_MovingPt
    skyScraper_Most_Left_Side_Back();//SkyScrp_1
    skyScraper_Most_right_Side();//SkyScrp_2
    Escalator2();//Esc2
    Escalator_2_MovingPart();//Esc2_MovingPt
    Road(); //Rd
    PaperBox(0,-270,motion_Escalator_1);//PprBx_1
    PaperBox(300,-270,motion_Escalator_1);//PprBx_2
    PaperBox(600,-270,motion_Escalator_1);//PprBx_3
    PaperBox(900,-270,motion_Escalator_1); //PprBx_4

    skyScraper_Most_Left_Side();//SkyScrp_3
    skyScraper_Middle();//SkyScrp_4
    Building_2nd_Most_Right_Side(); //SkyScrp_5
    bluiding_ON_top_Charging_Station(); //GlsBuild
    charging_station(); //CrgSt

    Car_Standing_Before_Station(); //CrStnd

    Bus_Stop(); //BStp
    Bench(0,0);//Bn_01
    Bench(116,0);//Bn_02
    Bench(-460,-175);//Bn_03
    Bench(-175,-175);//Bn_04
    Bench(300,-175);//Bn_05
    LampPost_Light(235,100,1.4,1.3); //Lm pst lt 01
    LampPost_Light(225,45,-1.4,1.3); //Lm pst lt 02
    LampPost_Light(-50,-235,-1.5,1.15); //Lm pst lt 03
    LampPost_Light(210,-235,-1.5,1.15); //Lm pst lt 04
    LampPost_Light(500,-235,-1.5,1.15); //Lm pst lt 05
    LampPost_Light(215,-33,1.4,1.3); //Lm pst lt 06


    //Right to Left
    car_opposite_Side(0,0,1,72,156,237,motion1_Blue); //MCr_Bl_R2L
    car_opposite_Side(-400,0,1,255,255,0,motion3_yellow); //MCr_YL_R2L
    car_opposite_Side(-800,0,1,255,0,0,motion2_red); //MCr_Rd_R2L

    //Opposite Direction [Left to Right]
    car_opposite_Side(0,105,-1,255,255,0,motion1_Blue); //MCr_Bl_L2R
    car_opposite_Side(-400,105,-1,72,156,237,motion3_yellow); //MCr_YL_L2R
    car_opposite_Side(-800,105,-1,255,0,0,motion2_red); //MCr_Rd_L2R

    Building2(); //Build_2
    flying_Vehicle(); //FCr

    UFO(); //UF
    trafficLight(100,30); //TF Lt_1
    trafficLight(300,30); //TF Lt_2

    LampPost(235,100,1.4,1.3);//Lm pst 01
    LampPost(215,-33,1.4,1.3); //Lm pst 02
    LampPost(225,45,-1.4,1.3); //Lm pst 03
    LampPost(-50,-235,-1.5,1.15);//Lm pst 04
    LampPost(210,-235,-1.5,1.15);//Lm pst 05
    LampPost(500,-235,-1.5,1.15);//Lm pst 06

    Charging_poin(-210,140); //Crg Pt_01
    Charging_poin(30,80); //Crg Pt_0
    Charging_poin(800,80); //Crg Pt_0

    glutSwapBuffers();
}
void handleKeypress(unsigned char key,int x, int y)
{
    switch (key)
    {
    case 'a':
        isNight = true;
        break;
    case 's':
        isNight = false;
        break;

    case 'r':
        UFO_X+=10;
        break;
    case 'l':
        UFO_X-=10;
        break;
    case 't':
        UFO_Y+=10;
        break;
    case 'b':
        UFO_Y-=10;
        break;
    }
    glutPostRedisplay();
}

void Car_Blue_R2L_UPDATE(int value) //MCr_Bl_R2L_UPDATE
{
    motion1_Blue+=2;
    if(motion1_Blue>1100)
    {
        motion1_Blue =-400;
    }
    glutPostRedisplay();
    glutTimerFunc(20,Car_Blue_R2L_UPDATE,0);
}

void Car_Yellow_R2L_UPDATE(int value) //MCr_YL_R2L_UPDATE
{
    motion3_yellow+=2;
    if(motion3_yellow>700)
    {
        motion3_yellow =-800;
    }
    glutPostRedisplay();
    glutTimerFunc(20,Car_Yellow_R2L_UPDATE,0);
}
void Car_Red_R2L_UPDATE(int value) //MCr_Rd_R2L_UPDATE
{
    motion2_red+=2;
    if(motion2_red>300)
    {
        motion2_red =-1200;
    }
    glutPostRedisplay();
    glutTimerFunc(20,Car_Red_R2L_UPDATE,0);
}

void Escalator1_Update(int value)
{
    motion_Escalator_1 += 1;
    if(motion_Escalator_1>1200)
    {
        motion_Escalator_1 = -500;
    }
    glutPostRedisplay();
    glutTimerFunc(20,Escalator1_Update,0);
}
void Cloud_Update_Z(int value){
    cloud_motion+=2;
    if(cloud_motion>2100)
    {
        cloud_motion = -350;
    }
    glutPostRedisplay();
    glutTimerFunc(20,Cloud_Update_Z,0);
}

void FlyingCar_Update_Z(int value)
{
    flying_Vehicle_motion_Y += 1;
    if(flying_Vehicle_motion_Y>500)
    {
        flying_Vehicle_motion_X +=1;
        if(flying_Vehicle_motion_X>1200)
        {
            flying_Vehicle_motion_X=0;
            flying_Vehicle_motion_Y=0;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20,FlyingCar_Update_Z,0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Scene-4");

    init();

    glutDisplayFunc(display);
    //glutTimerFunc(20, Timer, 0); // Register timer callback
    //Changes
    glutTimerFunc(20,Car_Blue_R2L_UPDATE,0); //MCr_Bl_R2L_UPDATE
    glutTimerFunc(20,Car_Yellow_R2L_UPDATE,0); //MCr_YL_R2L_UPDATE
    glutTimerFunc(20,Car_Red_R2L_UPDATE,0); //MCr_Rd_R2L_UPDATE
    glutTimerFunc(20,Escalator1_Update,0); //Esc_UPDATE
    glutTimerFunc(20,Cloud_Update_Z,0); //Cd_UPDATE
    glutTimerFunc(20,FlyingCar_Update_Z,0); //FCr_Update

    glutKeyboardFunc(handleKeypress);
    glutMainLoop();
    return 0;
}
