#include "PPP/Graph.h"
#include "Clock.h"
#include <chrono>
#include <thread>
#include <cmath>
#include <numbers>

using namespace Graph_lib;

Clock::Clock(Point p, int r) :Circle(p, r) {}

void Clock::draw_specifics(Painter& painter) const
{
	Circle c(Point(point(0).x + radius(), point(0).y + radius()), radius());
	c.set_fill_color(((Circle*)this)->fill_color());
	c.draw(painter);

	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);

	// Convert to local time structure
	std::tm* local_time = std::localtime(&now_c);

	// Extract hour, minute, and second
	int hour = local_time->tm_hour;
	int minute = local_time->tm_min;
	int second = local_time->tm_sec;

	double hourangle = std::numbers::pi * hour * 30 / 180;
	double minuteangle = std::numbers::pi * minute * 6 / 180;
	double secondangle = std::numbers::pi * second * 6 / 180;
	double hourhandlength = radius() / 2;
	double minutehandlength = radius() * 0.75;
	double secondhandlength = radius() * 0.9;

	Line hourhand = Line(Point(point(0).x + radius(), point(0).y + radius()),
		Point(point(0).x + radius() + sin(hourangle) * hourhandlength,
			point(0).y + radius() - cos(hourangle) * hourhandlength));
	Line minutehand = Line(Point(point(0).x + radius(), point(0).y + radius()),
		Point(point(0).x + radius() + sin(minuteangle) * minutehandlength,
			point(0).y + radius() - cos(minuteangle) * minutehandlength));
	Line secondhand = Line(Point(point(0).x + radius(), point(0).y + radius()),
		Point(point(0).x + radius() + sin(secondangle) * secondhandlength,
			point(0).y + radius() - cos(secondangle) * secondhandlength));

	hourhand.set_color(Color::black);
	hourhand.set_fill_color(Color::black);
	minutehand.set_color(Color::black);
	minutehand.set_fill_color(Color::black);
	secondhand.set_color(Color::black);
	secondhand.set_fill_color(Color::black);
	hourhand.draw(painter);
	minutehand.draw(painter);
	secondhand.draw(painter);
}
