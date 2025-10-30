#ifndef GRADEBOOK_HPP
#define GRADEBOOK_HPP

#include <string>
#include <vector>
#include <algorithm>

class Gradebook {
public:
    void add_student(const std::string& full_name, const std::string& student_id);
    void add_assignment(const std::string& name, double points);
    void enter_grade(const std::string& student_name, const std::string& assignment_name, double points);
    std::string report() const;

private:
    struct Student {
        std::string full_name;
        std::string student_id;
    };
    
    struct Assignment {
        std::string name;
        double points;
    };
    
    std::vector<Student> students;
    std::vector<Assignment> assignments;
    std::vector<std::vector<double>> grades; // grades[student_index][assignment_index], -1.0 means no grade
    
    int find_student_index(const std::string& student_name) const;
    int find_assignment_index(const std::string& assignment_name) const;
};

#endif // GRADEBOOK_HPP

