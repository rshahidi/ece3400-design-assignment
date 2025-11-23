#include "PPP/Window.h"
#include "PPP/Graph.h"
#include "Clock.h"

#define PI 3.14159265

// theta is the counterclockwise angle of rotation of the 
// traffic lights
#define theta 0

using namespace Graph_lib;
int main(int /*argc*/, char* /*argv*/[])
{
    Application app;

    const int trafficlightwidth = 120;
    const int trafficlightheight = 220;

    const int margin = 70;

    Point rectangle[4];

    Window w(2 * trafficlightheight + 2 * margin,
        trafficlightheight + margin, "Traffic light");

    Point trafficlights_upperleft{
        trafficlightheight - trafficlightwidth / 2 + margin,
        margin };

    const int redlightverticaloffset = 50;
    const int lightverticalspacing = 70;

    rectangle[0] = trafficlights_upperleft;
    rectangle[1] = { trafficlights_upperleft.x +
    trafficlightwidth, trafficlights_upperleft.y };
    rectangle[2] = { trafficlights_upperleft.x +
    trafficlightwidth, trafficlights_upperleft.y +
    trafficlightheight };
    rectangle[3] = { trafficlights_upperleft.x,
    trafficlights_upperleft.y + trafficlightheight };
    Point Upperleft_red = { trafficlightheight + margin,
        redlightverticaloffset + margin };
    Point Upperleft_amber = { trafficlightheight + margin,
        redlightverticaloffset + lightverticalspacing + margin };
    Point Upperleft_green = { trafficlightheight + margin,
        redlightverticaloffset + 2 * lightverticalspacing + margin };

    // ADD CODE HERE TO ROTATE ENTIRE TRAFFIC LIGHT SET BY THETA
    // RADIANS COUNTERCLOCKWISE
 
    Polygon r;
    for (int i = 0; i < 4; i++)
        r.add(rectangle[i]);
    
    r.set_fill_color(Color::black);

    const int second = 1000;
    const int amber_delay_seconds = 1;
    const int red_green_delay_seconds = 12;
    const int amber_delay = amber_delay_seconds * second;
    const int red_green_delay = red_green_delay_seconds * second;

    const int lightradius = 30;

    Clock red(Upperleft_red, lightradius);
    Clock amber(Upperleft_amber, lightradius);
    Clock green(Upperleft_green, lightradius);

    w.attach(r);
    w.attach(red);
    w.attach(amber);
    w.attach(green);
    
    while (true)
    {
        for (int i = 0; i < 3; i++) // Cycle through lights 3 times
        {
            for (int j = 0; j < red_green_delay_seconds; j++)
            {
                amber.set_fill_color(Color::black);
                green.set_fill_color(Color::black);
                red.set_fill_color(Color::red);
                w.timer_wait(second); // wait a second before redrawing
            }
            for (int j = 0; j < red_green_delay_seconds; j++)
            {
                amber.set_fill_color(Color::black);
                red.set_fill_color(Color::black);
                green.set_fill_color(Color::green);
                w.timer_wait(second); // wait a second before redrawing
            }
            for (int j = 0; j < amber_delay_seconds; j++)
            {
                amber.set_fill_color(Color::yellow);
                red.set_fill_color(Color::black);
                green.set_fill_color(Color::black);
                w.timer_wait(second); // wait a second before redrawing
            }
        }
    }
    app.gui_main();
}
