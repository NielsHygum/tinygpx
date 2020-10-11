

#pragma once

#include <list>
#include <waypoint.h>

class Route
{
private:
    std::list<Waypoint> route_points_;
public:
    void push_back(const Waypoint & route_point);
    void push_front(const Waypoint & route_point);
    const std::list<Waypoint> & getRoutePoints() const;
};