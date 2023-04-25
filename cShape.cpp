#include "cShape.h"

void cShape::set_position(double x, double y)
{
	x_ = x;
	y_ = y;
}

void cShape::set_size(double width, double height)
{
	width_ = width;
	height_ = height;
}


void cShape::set_velocity(double vx, double vy) 
{
	v_x_ = vx;
	v_y_ = vy;
}

void cShape::animate(double time) 
{
	alpha_ += time;
}

void cShape::move_animate(double time)
{
	x_ += v_x_*time;
	y_ += v_y_*time;
}






void cShape::move_bullet()
{
	x_ += v_x_;
	y_ += v_y_;
}
void cShape::acc(double xV, double yV)
{
	v_x_ += xV;
	v_y_ += yV;
}







void cShape::move(double x, double y) {
	x_ += x;
	y_ += y;
}

bool cShape::colision(double x, double y)
{
	double x1 = x_ - x, y1 = y_ - y;
	double licz = sqrt(pow(x1, 2.0) + pow(y1, 2.0));
	if (licz<height_)
	{
		
		return TRUE;
	}
	else
	{
		
		return FALSE;
	}
}

double cShape::get_width()
{
	return width_;
}

double cShape::get_height()
{
	return height_;
}
double cShape::get_alpha() 
{
	return alpha_;
}
double cShape::get_x()
{
	return x_;
}

double cShape::get_y()
{
	return y_;
}
double cShape::get_vx()
{
	return v_x_;
}
double cShape::get_vy()
{
	return v_y_;
}
double cShape::get_r()
{
	return r_;
}
void cShape::set_r(double r)
{
	r_ = r;
}
