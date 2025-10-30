#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student {
public:
    Student(const std::string& full_name, const std::string& student_id);
    
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getFullName() const;
    std::string getStudentId() const;

private:
    std::string full_name;
    std::string student_id;
};

#endif // STUDENT_HPP

