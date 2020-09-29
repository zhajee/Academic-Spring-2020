#include <iostream>
#include <sstream>
#include <string>

std::string compileLocation(double lat, std::string latdir, double lon, std::string londir, std::string stloc) {
    //compile all parts of location into a string
    std::stringstream ss;
    ss << lat << latdir << " " << lon << londir << " (" << stloc << ")";
    return ss.str();
}


void printOutput(std::string stloc1, std::string closestLoc, double closestDistance, std::string farthestLoc, double furthestDistance) {
    //use string locations and numeric distances to print out the desired output
    std::cout << "Start Location: " << stloc1 << std::endl;
    std::cout << "Closest Location: " << closestLoc << " (";
    std::cout << closestDistance;
    std::cout << " miles)" << std::endl;
    std::cout << "Farthest Location: " << farthestLoc << " (";
    std::cout << furthestDistance;
    std::cout << " miles)" << std::endl;
 }
