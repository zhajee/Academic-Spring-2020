#include <iostream>
#include "input.hpp"
#include "students.hpp"
#include "calculateScores.hpp"
#include "output.hpp"

int main()
{
    
    int num_artif; 
    std::cin >> num_artif;

    //creates arrays of points and weights for later use
    int* points = getPointsInfo(num_artif);
    int* weights = getWeightsInfo(num_artif);
    
    int num_students;
    std::cin >> num_students;

    //gets all student input and initializes rawscores array with zeros
    Student* student_info = getStudentsInfo(num_students, num_artif);

    getRawScores(num_artif, student_info, num_students);
    updateTotalScores(student_info, points, weights, num_students, num_artif);

    //delete allocated array of rawscores
    for(int i = 0; i < num_students; i++) {
        delete[] student_info[i].rawscores;
    }

    printTotalScores(num_students, student_info);

    int num_cutpoints;
    std::cin >> num_cutpoints;
    
    for (int i = 0; i < num_cutpoints; i++) {
        double* cutpoints = getCutpoints();
        updateLetterGrades(student_info, cutpoints, num_students);
        printCutpoints(student_info, num_students, i);

        delete[] cutpoints;
    }


    delete[] student_info;
    delete[] points;
    delete[] weights;
    
    return 0;
}

