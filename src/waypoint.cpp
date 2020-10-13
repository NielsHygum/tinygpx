#include "waypoint.h"

Waypoint::Waypoint(float latitude, float longitude)
{
    latitude_ = latitude;
    longitude_ = longitude;
}

void Waypoint::setElevation(float elevation)
{
    elevation_ = elevation;
}

void Waypoint::setName(std::string name)
{
    name_ = name;
}

std::string Waypoint::getName() const
{
    return name_;
}

float Waypoint::getLatitude() const
{
    return latitude_;
}

float Waypoint::getLongitude() const
{
    return longitude_;
}

float Waypoint::getElevation() const
{
    return elevation_;
}