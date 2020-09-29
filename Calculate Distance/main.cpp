#include <iostream>
#include <string>

#include "inputOutput.hpp"
#include "makeCalculations.hpp"
#include "findTargets.hpp"

int main()
{
    //initialize starting location input variables
    double lat1, lon1;
    std::string latdir1, londir1, stloc1;

    //first line of input
    std::cin >> lat1 >> latdir1 >> lon1 >> londir1;
    std::cin.ignore(1); //ignore 1 space before start location
    std::getline(std::cin, stloc1);
    stloc1 = compileLocation(lat1, latdir1, lon1, londir1, stloc1);

    //second line of input
    int tarloc; //number of target locations specified by user
    std::cin >> tarloc;

    //arrays to store string locations and numeric distances
    std::string* locs = new std::string[tarloc];
    double* dists = new double[tarloc];

    //initialize input variables
    double lat2, lon2;
    std::string latdir2, londir2, stloc2;

    double d; //distance from starting location

    //initialize output variables
    std::string farthestLoc, closestLoc;
    double furthestDistance, closestDistance;

    for (int i = 0; i < tarloc; i++) {
        //input for target locations
        std::cin >> lat2 >> latdir2 >> lon2 >> londir2;
        std::cin.ignore(1); //ignore 1 space before start location
        std::getline(std::cin, stloc2);

        //compare latitude and longitude directions
        double adjLat2 = reverseLat(latdir1,latdir2,lat2);
        double adjLon2 = reverseLon(londir1,londir2,lon2);

        //adds string compilation of each location to locs array
        locs[i] = compileLocation(lat2, latdir2, lon2, londir2, stloc2);
  
        d = getDistance(lat1, adjLat2, lon1, adjLon2);

        //find the max and assign it to farthestLoc if d is the max
        furthestDistance = findMaxDistance(d, i, dists);
        if (d == furthestDistance) {
           farthestLoc = locs[i];
        } 

        //find the min and assign it to closestLoc if d is the min
        closestDistance = findMinDistance(d, i, dists);
        if (d == closestDistance) {
            closestLoc = locs[i];
        }
    
    }

    printOutput(stloc1, closestLoc, closestDistance, farthestLoc, furthestDistance);

    delete[] locs;
    delete[] dists;
    return 0;
}

