#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "students.hpp"

int* getPointsInfo(int num_artif);

int* getWeightsInfo(int num_artif);

Student* getStudentsInfo(int num_students, int num_artif);

void getRawScores(int num_artif, Student* student_info, int orig_num_students);

double* getCutpoints();

#endif