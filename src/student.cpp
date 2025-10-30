#include "student.hpp"

Student::Student(const std::string& full_name, const std::string& student_id)
    : full_name(full_name), student_id(student_id) {}

std::string Student::getFullName() const {
    return full_name;
}

std::string Student::getStudentId() const {
    return student_id;
}

std::string Student::getFirstName() const {
    size_t space_pos = full_name.find(' ');
    if (space_pos == std::string::npos) return full_name;
    return full_name.substr(0, space_pos);
}

std::string Student::getLastName() const {
    size_t space_pos = full_name.find(' ');
    if (space_pos == std::string::npos) return "";
    return full_name.substr(space_pos + 1);
}

