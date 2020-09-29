#include "students.hpp"

//calculate total score based on rawscores, points, and weights for each artifact
void updateTotalScores(Student* student_info, int* points, int* weights, int num_students, int num_artif) {
    for (int i = 0; i < num_students; i++) {
        double sum = 0;
        for (int j = 0; j < num_artif; j++) {
            double score = ((double)student_info[i].rawscores[j] / (double)points[j]) * (double)weights[j];
            sum += score;
        }
        student_info[i].totalscore = sum;
        //delete[] student_info[i].rawscores;
    }

    
}

void updateLetterGrades(Student* student_info, double* cutpoints, int num_students) {
    //calculate letter grade based on cutpoints
    for (int i = 0; i < num_students; i++) {
        Student student = student_info[i];

        std::string letters[4] = {"A", "B", "C", "D"};
        std::string letter = "F";
        //move backwards from cutpoints aligned with letter grade
        for (int j = 3; j >= 0; j--) {      
            if (student_info[i].totalscore >= cutpoints[j]) {
                letter = letters[j];
            }
        }
            student_info[i].lettergrade = letter;

        //assign Pass / No Pass based on letter grade calculated above
        if (student.gradeop == "P") {
            if (letter == "D" or letter == "F") {
                student_info[i].lettergrade = "NP";
            }
            else {
                student_info[i].lettergrade = "P";
            }
        }        
            

    }

}
