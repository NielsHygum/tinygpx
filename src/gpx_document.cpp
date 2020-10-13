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
    XMLElement * gpx_root = gpx_document_.FirstChildElement("gpx");

    if(gpx_root != nullptr)
    {
        for(auto root_node = gpx_root->FirstChildElement("wpt"); root_node != nullptr; root_node = root_node->NextSiblingElement("wpt"))
        {
            float lat;
            float lon;

            XMLError lat_result = root_node->QueryFloatAttribute("lat", &lat);
            XMLError lon_result = root_node->QueryFloatAttribute("lon", &lon);

            if((lat_result == XMLError::XML_SUCCESS) and (lon_result == XMLError::XML_SUCCESS))
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
}

void GPXDocument::extractRoutes()
{
    XMLElement * gpx_root = gpx_document_.FirstChildElement("gpx");

    if(gpx_root != nullptr)
    {
        for(auto root_node = gpx_root->FirstChildElement("rte"); root_node != nullptr; root_node =root_node->NextSiblingElement("rte"))
        {
            Route route;

            auto name_element = root_node->FirstChildElement("name");
            if(name_element != nullptr)
            {
                const char * name_ptr = name_element->GetText();

                route.setName(name_ptr);
            }

            for(auto rte_node = root_node->FirstChildElement("rtept"); rte_node != nullptr; rte_node = rte_node->NextSiblingElement("rtept"))
            {
                float lat;
                float lon;

                XMLError lat_result = rte_node->QueryFloatAttribute("lat", &lat);
                XMLError lon_result = rte_node->QueryFloatAttribute("lon", &lon);

                if((lat_result == XMLError::XML_SUCCESS) and (lon_result == XMLError::XML_SUCCESS))
                {
                    Waypoint waypoint(lat, lon);

                    auto name_element = rte_node->FirstChildElement("name");
                    if(name_element != nullptr)
                    {
                        const char * name_ptr = name_element->GetText();

                        waypoint.setName(name_ptr);
                    }

                    route.push_back(waypoint);
                }
            }
            routes_.push_back(route);
        }
    }

}

const std::list<Route> & GPXDocument::getRoutes() const
{
    return routes_;
}

const std::list<Waypoint> & GPXDocument::getWaypoints() const
{
    return waypoints_;
}