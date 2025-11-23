#pragma once
#include "PPP/Graph.h"
using namespace Graph_lib;

class Clock : public Circle
{
public:
	Clock(Point p, int r);

	void draw_specifics(Painter& painter) const override;
};
