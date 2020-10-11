
#pragma once

#include <tinyxml2.h>
#include "route.h"

class GPXDocument
{
private:
    XMLDocument gpx_document_;
    std::list<Route> routes_;
    std::list<Waypoint> waypoints_;
public:
    XMLError loadFile(std::string filename);
    const std::list<Route> & getRoutes() const;
    const std::list<Waypoint> & getWaypoints() const;
};