#include <iostream>
#include "students.hpp"

void printTotalScores(int num_students, Student* student_info) {
    std::cout << "TOTAL SCORES" << std::endl;
    for (int i = 0; i < num_students; i++){
        Student student = student_info[i];
        std:: cout << student.id << " ";
        std::cout << student.name << " ";
        std::cout << student.totalscore << std::endl;
    }

}

void printCutpoints(Student* student_info, int num_students, int n) {
    std::cout << "CUTPOINT SET" << " ";
    std::cout << n+1 << std::endl;
    for (int i = 0; i < num_students; i++){
        Student student = student_info[i];
        std:: cout << student.id << " ";
        std::cout << student.name << " ";
        std::cout << student.lettergrade << std::endl;
    }
}
