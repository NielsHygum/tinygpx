#pragma once
#include <string>
#include <cmath>

class Waypoint
{
private:
    //Required
    float latitude_;
    float longitude_;

    //Optional
    std::string name_;
    float elevation_ = NAN;
public:
    Waypoint(float latitude, float longitude);
    void setElevation(float elevation);
    void setName(std::string name);
    std::string getName() const;
    float getLatitude() const;
    float getLongitude() const;
    float getElevation() const;
};