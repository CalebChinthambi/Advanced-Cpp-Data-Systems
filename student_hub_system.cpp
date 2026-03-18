#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

class Student {
public:
    string name;
    string lastName;
    string studentID;
    string club;

    Student(string n, string ln, string id, string c) 
        : name(n), lastName(ln), studentID(id), club(c) {}

    // Overloading the << operator for easy printing
    friend ostream& operator<<(ostream& os, const Student& s) {
        os << "ID: " << s.studentID << " | Name: " << s.name << " " << s.lastName << " | Club: " << s.club;
        return os;
    }
};

class StudentHub {
private:
    vector<Student> students;

public:
    void addStudent(const Student& s) {
        students.push_back(s);
    }

    // Demonstrating search logic
    void findByClub(string clubName) {
        cout << "\n--- Members of " << clubName << " ---" << endl;
        for (const auto& s : students) {
            if (s.club == clubName) {
                cout << s << endl;
            }
        }
    }

    // Demonstrating sorting by Last Name using std::sort
    void sortAndDisplay() {
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return a.lastName < b.lastName;
        });

        cout << "\n--- Students Sorted by Last Name ---" << endl;
        for (const auto& s : students) {
            cout << s << endl;
        }
    }
};

int main() {
    StudentHub hub;
    
    hub.addStudent(Student("Caleb", "Chinthambi", "402107974", "Data Science Club"));
    hub.addStudent(Student("Alice", "Smith", "102", "Soccer Club"));
    hub.addStudent(Student("John", "Doe", "105", "Data Science Club"));

    hub.findByClub("Data Science Club");
    hub.sortAndDisplay();

    return 0;
}
