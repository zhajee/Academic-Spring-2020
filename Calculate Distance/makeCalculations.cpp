#include <string>
#include <cmath>

const double R = 3959.9; //Radius of Earth
const double PI = 3.14159265;

double reverseLat(std::string latdir1, std::string latdir2, double lat2) {
    //if the directions of latitude are N and S, change the sign of lat2
    if (latdir1 != latdir2) {
        lat2 = lat2*(-1);
    }
    return lat2;
}

double reverseLon(std::string londir1,std::string londir2, double lon2) {
    //if the directions of longitude are E and W, change the sign of lat2
    if (londir1 != londir2) {
        lon2 = lon2*(-1);
    }
    return lon2;
}

double toRad(double param) {
    //degrees to radians conversion
    return param * PI / 180.0;
}

double getdLat(double lat1, double lat2) {
    //difference between latitudes
    return (lat1-lat2);
}

double getdLon(double lon1, double lon2) {
    //difference between longitudes
    return (lon1 - lon2);
}

double getA(double lat1, double lat2, double lon1, double lon2) {
    //formula calculation for a
    double a;
    a = pow(sin(toRad(getdLat(lat1,lat2)/2)),2) + cos(toRad(lat1)) * cos(toRad(lat2)) * pow(sin(toRad(getdLon(lon1,lon2)/2)),2);
    return a;
    
}

double getC(double lat1, double lat2, double lon1, double lon2) {
    //fomula calculation for c using a
    double a;
    a = getA(lat1, lat2, lon1, lon2);
    double c;
    c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return c;
}

double getDistance(double lat1, double lat2, double lon1, double lon2) {
    //formula calculation for distance using c
    double c;
    double d;
    c = getC(lat1,lat2,lon1,lon2);
    d = R * c;
    return d;

}
