#include "cHTrawa.h"

void cHTrawa::draw() {
	glPushMatrix();
	glTranslated(x_, y_, 0.0);
	glRotated(alpha_, 0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	{
		glColor3d(0.8, 0, 0);
		glVertex3d(-width_ / 2, height_ / 2, 0);
		glColor3d(0.8, 0, 0);
		glVertex3d(width_ / 2, height_ / 2, 0);
		glColor3d(0.8, 0, 0);
		glVertex3d(width_ / 2, -height_ / 2, 0);
		glColor3d(0.8, 0, 0);
		glVertex3d(-width_ / 2, -height_ / 2, 0);
	}
	glEnd();
	glPopMatrix();
}
