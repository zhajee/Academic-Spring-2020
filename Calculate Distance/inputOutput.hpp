#ifndef INPUTOUTPUT_HPP_
#define INPUTOUTPUT_HPP_

std::string compileLocation(double lat, std::string latdir, double lon, std::string londir, std::string stloc);

void printOutput(std::string stloc1, std::string closestLoc, double closestDistance, std::string farthestLoc, double furthestDistance);


#endif