#include <iostream>
#include <vector>
#include <list>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include "cRectangle.h"
#include "cRRectangle.h"
#include "cGRectangle.h"
#include "cCircle.h"
#include "cTriangle.h"
#include "cTrawa.h"
#include "cHTrawa.h"
#include <Windows.h>
#include <mmsystem.h>
#define NDEBUG


using namespace std;
double X_size, Y_size, X_Y;
std::vector<cShape*> obiekty;
std::vector<cShape*> obiekty_ene;
std::list<cShape*> tank;
std::list<cShape*> tank_ene;
std::list<cShape*> trawa;
std::list<cShape*> zycie_ene;
std::list<cShape*> zycie;
std::list<cShape*> stones;
bool animate = FALSE;
int shape = 1;
double licznik = 0;
double bariera = 0;
double licz = 0;

void follow_w_o_click(int x, int y)
{
	double openglX = ((double)x - 400) / 800 * 6.68;
	double openglY = -(((double)y - 300) / 600 * 5);
}

void onMouseButton(int button, int state, int x, int y)
{
	double openglX = ((double)x - X_size / 2) / X_size * (6.68) * (X_Y);
	double openglY = -(((double)y - Y_size / 2) / Y_size * 5);

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
	{
		for (auto itr = obiekty.begin(); itr < obiekty.end(); itr++)
		{
			if ((*itr)->colision(openglX, openglY))
			{
				
			}
		}
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) 
	{
		for (auto itr = obiekty.begin(); itr < obiekty.end(); itr++)
		{
			if ((*itr)->colision(openglX, openglY))
			{
				
			}
		}
	}
}

void resize(int width, int height)
{
	const float ar = (float)width / (float)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	X_size = width;
	Y_size = height;
	X_Y = width / height;
	glLoadIdentity();
}

void idle() 
{
	glutPostRedisplay();
}

void keyboard_callback(unsigned char key, int mouse_x, int mouse_y) 
{
	double openglX = ((double)mouse_x - X_size / 2) / X_size * (6.68) * (X_Y);
	double openglY = -(((double)mouse_y - Y_size / 2) / Y_size * 5);
	srand(time(NULL));
	double vx = ((rand() % 5)-2);
	double vy = ((rand() % 5)-2);	
	static int hehe = 1;
	static double xa = 0;
	double x_r = 0;
	double y_r = 0;
	auto itr1 = tank.begin();
	double end_x = (*itr1)->get_x() + 0.4;
	double end_y = (*itr1)->get_y() + licznik/100;
	double dx = 0;
		
	switch (key)
	{
	case 'w':
		if (licznik < 40) 
		{
			(*itr1)->animate(0.9);
			(*itr1)->move(0, 0.005);
			licznik++;	
		}
		break;
	case 's':
		if (licznik > -10)
		{
			(*itr1)->animate(-0.9);
			(*itr1)->move(0, -0.005);
			licznik--;	
		}
		break;
	case 'a':
		if (bariera > -0.8)
		{
			bariera -= 0.2;
		dx -= 0.2;
		}
		break;
	case 'd':
		if (bariera < 1.7) 
		{
			bariera += 0.2;
			dx += 0.2;
		}
		
		break;
	case 'q':
		exit(0);
		break;
	case ' ':
		cShape* temp;
		temp = new cCircle(0.1, end_x, end_y, 0.04+0.4*licznik/40, 0.06+0.6*licznik/40);
		obiekty.push_back(temp);
		break;
	default:
		break;
	}
	for (auto it = tank.begin(); it != tank.end(); it++) 
	{
		(*it)->move(dx, 0);	
	}
}

void music() 
{
	PlaySound(L"C:\\Users\\S³awek\\Desktop\\INFORMATYKA\\kolokwium\\3\\3\\music.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
}

void animation_timer(int /*nothing*/) 
{
	for (auto it = obiekty.begin(); it != obiekty.end(); it++) 
	{
		(*it)->acc(0, -0.1);
		(*it)->move_bullet();
	}
	// Kolizja naszego czo³gu  ***********************************************************************************
	auto zyciee2 = zycie.begin();
	for (auto itrr = tank.begin(); itrr != tank.end(); itrr++)
	{
	
		for (auto itr = obiekty.begin(); itr != obiekty.end(); itr++) 
		{
			double openglX = (*itr)->get_x();
			double openglY = (*itr)->get_y();
			if ((*itrr)->colision(openglX, openglY))
			{
				double width = (*zyciee2)->get_width();
				double height = (*zyciee2)->get_height();
				double posx = (*zyciee2)->get_x();
				double posy = (*zyciee2)->get_y();
				if (width > 0) 
				{
					(*zyciee2)->set_size(width - 0.076, height);
					(*zyciee2)->set_position(posx - 0.0375, posy);
				}
				else 
				{	
					exit(0);
				}
			}
		}
	}
	// Kolizja czo³gu przeciwnika  ***********************************************************************************
	auto zyciee = zycie_ene.begin();
	for (auto itrr = tank_ene.begin(); itrr != tank_ene.end(); itrr++)
	{
		for (auto itr = obiekty.begin(); itr != obiekty.end(); itr++) 
		{
			double openglX = (*itr)->get_x();
			double openglY = (*itr)->get_y();
			if ((*itrr)->colision(openglX, openglY))
			{
				
				double width= (*zyciee)->get_width();
				double height = (*zyciee)->get_height();
				double posx= (*zyciee)->get_x();
				double posy= (*zyciee)->get_y();
				if (width > 0) {
					(*zyciee)->set_size(width - 0.301, height);
					(*zyciee)->set_position(posx - 0.15, posy);
				}else {
					cout << "WYGRALES ZOLNIERZU" << endl;
					exit(0);
				}
				
			}
		}
	}
	glutTimerFunc(20, animation_timer, NULL);
}
void animation_timer2(int /*nothing*/)
{
	auto itr1 = tank_ene.begin();
	double end_x = (*itr1)->get_x() - 0.4;
	double end_y = (*itr1)->get_y() + 0.4;

		for (auto it = tank_ene.begin(); it != tank_ene.end(); it++)
		{
			auto itm = tank_ene.begin();
			if ((*itm)->get_x() > 3.1)
			{
				double vx = (*it)->get_vx();
				double vy = (*it)->get_vy();
				(*it)->set_velocity(-vx, vy);

				cShape* temp;
				temp = new cCircle(0.1, end_x, end_y, -0.52, 0.6);
				obiekty.push_back(temp);
			}
			if ((*itm)->get_x() < 2.4)
			{
				double vx = (*it)->get_vx();
				double vy = (*it)->get_vy();
				(*it)->set_velocity(-vx, vy);
				cShape* temp;
				temp = new cCircle(0.1, end_x, end_y, -0.26, 0.6);
				obiekty.push_back(temp);
			}
			if ((*itm)->get_x() > 2.73 && (*itm)->get_x() < 2.74)
			{
				cShape* temp;
				temp = new cCircle(0.1, end_x, end_y, -0.41, 0.6);
				obiekty.push_back(temp);
			}
			(*it)->move_animate(0.02);
		}
	glutTimerFunc(20, animation_timer2, NULL);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	{
		for (auto it = obiekty.begin(); it != obiekty.end(); it++) {
			(*it)->draw();
		}
		for (auto it = obiekty.begin(); it != obiekty.end(); it++) {
			(*it)->draw();
		}
		for (auto it = tank_ene.begin(); it != tank_ene.end(); it++) {
			(*it)->draw();
		}
		for (auto it = tank.begin(); it != tank.end(); it++) {
			(*it)->draw();
		}
		for (auto it = stones.begin(); it != stones.end(); it++) {
			(*it)->draw();
		}
		for (auto it = trawa.begin(); it != trawa.end(); it++) {
			(*it)->draw();
		}
		for (auto it = zycie_ene.begin(); it != zycie_ene.end(); it++) {
			(*it)->draw();
		}
		for (auto it = zycie.begin(); it != zycie.end(); it++) {
			(*it)->draw();
		}
		for (auto it = stones.begin(); it != stones.end(); it++) {
			(*it)->draw();
		}
	}
	glPopMatrix();
	glutSwapBuffers();
}

void InitGLUTScene(const char* window_name)
{
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutCreateWindow(window_name);
	glClearColor(0.2, 0.8, 0.99, 1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
}

void SetCallbackFunctions()
{
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutTimerFunc(20, animation_timer, NULL);
	glutTimerFunc(20, animation_timer2, NULL);
	glutKeyboardFunc(keyboard_callback);
	glutPassiveMotionFunc(follow_w_o_click);
	glutMouseFunc(onMouseButton);
	music();
}

int main(int argc, char *argv[])
{
	std::cout << "Hello openGL world!" << std::endl;
	glutInit(&argc, argv);
	InitGLUTScene("Hello GL");
	SetCallbackFunctions();	
	cShape* temp;
	temp = new cRectangle(1.5, 0.5, -3.0, -1.8, 0.0, 0.0);
	tank.push_front(temp);
	temp = new cRectangle(0.7, 0.4, -3.0, -1.5, 0.0, 0.0);
	tank.push_front(temp);
	temp = new cRectangle(0.8, 0.1, -2.4, -1.43, 0.0, 0.0);
	tank.push_front(temp);

	
	temp = new cRRectangle(1.5, 0.5, 3.5, -1.8, 0.3, 0.0);
	tank_ene.push_front(temp);
	temp = new cRRectangle(0.7, 0.4, 3.5, -1.5, 0.3, 0.0);
	tank_ene.push_front(temp);
	temp = new cRRectangle(0.8, 0.1, 2.9, -1.28, 0.3, 0.0);
	tank_ene.push_front(temp);

	auto itr1 = tank_ene.begin();
	(*itr1)->animate(150);
	
	temp = new cTrawa(10, 1, 0, -2, 0.0, 0.0);
	trawa.push_front(temp);
	temp = new cTrawa(10, 1, 0, -2, 0.0, 0.0);
	trawa.push_front(temp);

	temp = new cHTrawa(1.5, 0.2, 3.5, 2.2, 0.0);
	zycie_ene.push_front(temp);
	temp = new cHTrawa(1.5, 0.2, -3.5, 2.2, 0.0);
	zycie.push_front(temp);


	temp = new cGRectangle(0.7, 0.7, 0.2, -1.5, 0.0, 0.0);
	stones.push_front(temp);
	temp = new cGRectangle(0.6, 0.6, 0.15, -1.5, 0.0, 0.0);
	stones.push_front(temp);
	temp = new cGRectangle(0.5, 0.5, -0.11, -1.8, 0.0, 0.0);
	stones.push_front(temp);
	temp = new cGRectangle(0.6, 0.6, 0.25, -1.5, 0.0, 0.0);
	stones.push_front(temp);
	temp = new cGRectangle(0.5, 0.5, -0.15, -1.8, 0.0, 0.0);
	stones.push_front(temp);
	temp = new cGRectangle(0.4, 0.4, 0.15, -1.8, 0.0, 0.0);
	stones.push_front(temp);
	temp = new cGRectangle(0.3, 0.3, -0.15, -1.8, 0.0, 0.0);
	stones.push_front(temp);
	glutMainLoop();
	return 0;
}
