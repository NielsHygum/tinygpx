#include "route.h"

void Route::push_back(const Waypoint & route_point)
{
    route_points_.push_back(route_point);
}

void Route::push_front(const Waypoint & route_point)
{
    route_points_.push_front(route_point);
}

const std::list<Waypoint> & Route::getRoutePoints() const
{
    return route_points_;
}