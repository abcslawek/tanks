#include "cCircle.h"

void cCircle::draw() {
	glPushMatrix();
	glTranslated(x_, y_, 0.0);
	glRotated(alpha_, 0.0, 0.0, 1.0);

	const float DEG2RAD = 3.14159 / 180;
	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i<360; i++)
	{
		float degInRad = i * DEG2RAD;
		glVertex2f(cos(degInRad)*r_, sin(degInRad)*r_);
		glColor3d(0.0, 0.0, 0.0);
	}
	glEnd();
	glPopMatrix();
}
