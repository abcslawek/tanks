#include "cGRectangle.h"

void cGRectangle::draw() {
	glPushMatrix();
	glTranslated(x_, y_, 0.0);
	glRotated(alpha_, 0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	{
		glColor3d(0.5, 0.5, 0.5);
		glVertex3d(-width_ / 2, height_ / 2, 0);
		glColor3d(0.6, 0.6, 0.6);
		glVertex3d(width_ / 2, height_ / 2, 0);
		glColor3d(0.4, 0.4, 0.4);
		glVertex3d(width_ / 2, -height_ / 2, 0);
		glColor3d(0.3, 0.3, 0.3);
		glVertex3d(-width_ / 2, -height_ / 2, 0);
	}
	glEnd();
	glPopMatrix();
}
