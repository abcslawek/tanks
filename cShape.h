#ifndef cShape_h
#define cShape_h

#include <GL/freeglut.h>
#include <math.h>
#include <iostream>
#include <conio.h>

class cShape {
public:
	//~cShape();
	cShape(double width = 1.0, double height = 1.0, double x = 0.0, double y = 0.0) {
		set_position(x, y);
		set_size(width, height);
	}
	void set_position(double x, double y);
	void set_size(double width, double height);
	void set_velocity(double vx, double vy);
	void set_r(double r);

	void animate(double time);
	void move(double x, double y);
	bool colision(double x, double y);
	void move_animate(double time);
	void move_bullet();
	void acc(double xV, double yV);
	double get_width();
	double get_height();
	double get_x();
	double get_y();
	double get_vx();
	double get_vy();
	double get_r();
	double get_alpha();
	virtual void draw() = 0;
protected:
	double x_;
	double y_;
	double r_;

	double alpha_ = 0;

	double v_x_ = 0.0;
	double v_y_ = 0.0;

	double width_;
	double height_;

};

#endif /* cShape_h */


