#ifndef CALCULATESCORES_HPP_
#define CALCULATESCORES_HPP_

void updateTotalScores(Student* student_info, int* points, int* weights, int num_students, int num_artif);

void updateLetterGrades(Student* student_info, double* cutpoints, int num_students);

#endif