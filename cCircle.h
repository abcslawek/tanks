#ifndef cCircle_h
#define cCircle_h
#include "cShape.h"

class cCircle : public cShape {
public:
	cCircle(double radius = 1.0, double x = 0.0, double y = 0.0, double v_x = 1, double v_y = 1) {
		set_position(x, y);
		set_r(radius);
		set_velocity(v_x, v_y);
	}

	virtual void draw();
private:

};

#endif /* cCircle_h */
#pragma once
