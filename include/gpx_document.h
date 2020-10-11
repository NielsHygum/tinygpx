
#pragma once

#include <tinyxml2.h>
#include "route.h"

class GPXDocument
{
private:
    tinyxml2::XMLDocument gpx_document_;
    std::list<Route> routes_;
    std::list<Waypoint> waypoints_;
public:
    tinyxml2::XMLError loadFile(std::string filename);
    const std::list<Route> & getRoutes() const;
    const std::list<Waypoint> & getWaypoints() const;
};