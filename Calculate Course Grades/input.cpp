#include <iostream>
#include <string>
#include "students.hpp"


int* getPointsInfo(int num_artif) {

    //array of first line of input: points of each artifact
    int* points = new int[num_artif];
    for (int i = 0; i < num_artif; i++) {
        std::cin >> points[i];
    }

    return points;
}

int* getWeightsInfo(int num_artif) {

    //array of second line of input: weights of each artifact
    int* weights = new int[num_artif];
    for (int i = 0; i < num_artif; i++) {
        std::cin >> weights[i];
    }

    return weights;

}

Student* getStudentsInfo(int num_students, int num_artif) {

    //array of Students
    Student* studentinfo = new Student[num_students];
    for (int i = 0; i < num_students; i++) {
        std::cin >> studentinfo[i].id;
        std::cin >> studentinfo[i].gradeop;
        std::cin.ignore(1);
        std::getline(std::cin, studentinfo[i].name);
        
        int* rawscores = new int[num_artif]();
        //studentinfo[i].rawscores = new int[num_artif]();
        studentinfo[i].rawscores = rawscores;
        //delete[] studentinfo[i].rawscores;
        
    }

    return studentinfo;
}

//returns a pointer to the student with matching ID
Student* getStruct(Student* student_info, int id_input, int orig_num_students, int num_artif) {
    Student* student_ptr = NULL;
    for (int i = 0; i < orig_num_students; i++) {
        if (student_info[i].id == id_input) {
            student_ptr = student_info + i;
        }
    }
    return student_ptr;
}

//sets raw scores according to inputted ID
void getRawScores(int num_artif, Student* student_info, int orig_num_students) {

    int num;
    std::cin >> num;

    for (int i = 0; i < num; i++) {
        int id_input;
        std::cin >> id_input;
        int* rawscores = new int[num_artif];
        for (int j = 0; j < num_artif; j++) {
            std::cin >> rawscores[j];
        }
        Student* student = getStruct(student_info, id_input, orig_num_students, num_artif);
        student->rawscores = rawscores;
        /*
        if (student != NULL) {
            student->rawscores = rawscores;
        }
        */
        
    }

}

//returns array of cutpoints
double* getCutpoints() {
    double* cutpoints = new double[4];
    for (int i = 0; i < 4; i++) {
        std::cin >> cutpoints[i];
    }
    return cutpoints;
}


