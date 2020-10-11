#include "gpx_document.h"

using namespace tinyxml2;

XMLError GPXDocument::loadFile(std::string filename)
{
    XMLError load_error = gpx_document_.LoadFile(filename.c_str());

    if(load_error != XMLError::XML_SUCCESS) 
        return load_error;

    extractWaypoints();
    extractRoutes();
    
    return XMLError::XML_SUCCESS;
}

void GPXDocument::extractWaypoints()
{
    for(auto root_node = gpx_document_.FirstChildElement("wpt"); root_node != nullptr; root_node->NextSiblingElement("wpt"))
    {
        float lat;
        float lon;

        XMLError lat_result = root_node->QueryFloatAttribute("lat", &lat);
        XMLError lon_result = root_node->QueryFloatAttribute("lon", &lon);

        if(lat_result == lon_result == XMLError::XML_SUCCESS)
        {
            Waypoint waypoint(lat, lon);

            auto name_element = root_node->FirstChildElement("name");
            if(name_element != nullptr)
            {
                const char * name_ptr = name_element->GetText();

                waypoint.setName(name_ptr);
            }

            waypoints_.push_back(waypoint);
        }
    }

}

void GPXDocument::extractRoutes()
{

}

const std::list<Route> & GPXDocument::getRoutes() const
{
    return routes_;
}

const std::list<Waypoint> & GPXDocument::getWaypoints() const
{
    return waypoints_;
}