double findMaxDistance(double d, int i, double *dists) {
    //find max in array each time a distance is added
    dists[i] = d;
    double maxnum = dists[0];
    for (int j = 0; j < i+1; j++) {
        if (dists[j] > maxnum){
            maxnum = dists[j];
        }
    }
    return maxnum;
    
}

double findMinDistance(double d, int i, double *dists) {
    //find min in array each time a distance is added
    dists[i] = d;
    double minnum = dists[0];
    for (int j = 0; j < i+1; j++) {
        if (dists[j] < minnum) {
            minnum = dists[j];
        }
    }

    return minnum;
}
