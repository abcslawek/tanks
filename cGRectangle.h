#ifndef cGRectangle_h
#define cGRectangle_h
#include "cShape.h"

class cGRectangle : public cShape {
public:
	cGRectangle(double width = 1.0, double height = 1.0, double x = 0.0, double y = 0.0, double v_x = 1, double v_y = 1) {
		set_position(x, y);
		set_size(width, height);
		set_velocity(v_x, v_y);
	}

	virtual void draw();
private:

};

#endif /* cRectangle_h */
#pragma once
