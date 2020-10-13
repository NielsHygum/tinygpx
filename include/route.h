

#pragma once

#include <list>
#include <waypoint.h>

class Route
{
private:
    std::string name_;
    std::list<Waypoint> route_points_;
public:
    void setName(std::string name);
    void push_back(const Waypoint & route_point);
    void push_front(const Waypoint & route_point);
    const std::list<Waypoint> & getRoutePoints() const;
    const std::string & getName() const;
};