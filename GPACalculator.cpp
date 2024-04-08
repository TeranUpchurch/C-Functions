
// C++ GPA Calculator

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class course {
    private:
        string name;
        char grade;
        int credits;
    public:
        void setName(string s) {name = s;};
        void setGrade(char g) {grade = toupper(g);};
        void setCredits(int c) {credits = c;};
        string getName() const {return name;};
        char getGrade() const {return grade;};
        int getCredits() const {return credits;};
        void printInfo();
};

void course::printInfo() {
    cout << "Class Name: " << course::getName() << endl;
    cout << "Grade: " << course::getGrade() << endl;
    cout << "Credits: " << course::getCredits() << endl;
}

void calcGPA (vector<course> inVec){
    double totalGrade, totalCredits, totalCourses;
    
    for (int i = 0; i < inVec.size(); i++) {
        char currGrade = inVec.at(i).getGrade();
        double currCredits = inVec.at(i).getCredits();
        totalCredits += currCredits;
        totalCourses++;
        if (currGrade == 'A') {
            totalGrade += 4 * currCredits;
        }
        else if (currGrade == 'B') {
            totalGrade += 3 * currCredits;
        }
        else if (currGrade == 'C') {
            totalGrade += 2 * currCredits;
        }
        else if (currGrade == 'D') {
            totalGrade += 1 * currCredits;
        }
    }

    cout << endl;
    cout << "You have taken " << totalCourses << " courses" << endl;
    cout << "Yout total GPA is: " << totalGrade / totalCredits << endl;
    cout << endl;
}

vector<course> enterCourses() {
    vector<course> retVec;
    cout << "Input x into course name to end" << endl;

    while (1 > 0) {
    course currCourse;
    string className;
    int credits;
    char grade;

    cout << "Enter course name: ";
    getline(cin, className);
    if (className == "x") {
        break;
    }
    currCourse.setName(className);

    cout << "Enter grade in course: ";
    cin >> grade;
    currCourse.setGrade(grade);
    cin.ignore();

    cout << "Enter credits of course: ";
    cin >> credits;
    currCourse.setCredits(credits);
    cin.ignore();

    retVec.push_back(currCourse);
    }

    return retVec;
}

void printCourses(vector<course> inVec) {
    cout << "Courses taken: " << endl; 
    for (int i = 0; i < inVec.size(); i++) {
        inVec.at(i).printInfo();
        cout << endl;
    }
}

int main () {

    vector<course> courseVec = enterCourses();
    
    calcGPA(courseVec);

    printCourses(courseVec);

    return 0;
}