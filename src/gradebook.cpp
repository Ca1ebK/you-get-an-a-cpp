#include "gradebook.hpp"
#include <sstream>

void Gradebook::add_student(const std::string& full_name, const std::string& student_id) {
    students.push_back({full_name, student_id});
    grades.emplace_back(assignments.size(), -1.0);
}

void Gradebook::add_assignment(const std::string& name, double points) {
    assignments.push_back({name, points});
    for (auto& student_grades : grades) {
        student_grades.push_back(-1.0);
    }
}

int Gradebook::find_student_index(const std::string& student_name) const {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].full_name == student_name) {
            return i;
        }
    }
    return -1;
}

int Gradebook::find_assignment_index(const std::string& assignment_name) const {
    for (int i = 0; i < assignments.size(); i++) {
        if (assignments[i].name == assignment_name) {
            return i;
        }
    }
    return -1;
}

void Gradebook::enter_grade(const std::string& student_name, const std::string& assignment_name, double points) {
    int student_idx = find_student_index(student_name);
    int assignment_idx = find_assignment_index(assignment_name);
    
    if (student_idx != -1 && assignment_idx != -1) {
        grades[student_idx][assignment_idx] = points;
    }
}

std::string Gradebook::extract_last_name(const std::string& full_name) const {
    size_t space_pos = full_name.find(' ');
    if (space_pos == std::string::npos) {
        return "";
    }
    return full_name.substr(space_pos + 1);
}

std::string Gradebook::extract_first_name(const std::string& full_name) const {
    size_t space_pos = full_name.find(' ');
    if (space_pos == std::string::npos) {
        return full_name;
    }
    return full_name.substr(0, space_pos);
}

std::string Gradebook::format_grade(double grade) const {
    if (grade >= 0.0) {
        return std::to_string((int)grade);
    }
    return "none";
}

std::string Gradebook::generate_header() const {
    std::stringstream header;
    header << "Last_Name,First_Name,Student_Id";
    for (const auto& assignment : assignments) {
        header << "," << assignment.name;
    }
    header << "\n";
    return header.str();
}

std::string Gradebook::generate_student_row(int student_idx) const {
    const auto& student = students[student_idx];
    std::string first_name = extract_first_name(student.full_name);
    std::string last_name = extract_last_name(student.full_name);
    
    std::stringstream row;
    row << last_name << "," << first_name << "," << student.student_id;
    
    for (const auto& grade : grades[student_idx]) {
        row << "," << format_grade(grade);
    }
    row << "\n";
    
    return row.str();
}

std::string Gradebook::report() const {
    if (students.empty() || assignments.empty()) {
        return "";
    }
    
    std::stringstream result;
    result << generate_header();
    
    for (int i = 0; i < students.size(); i++) {
        result << generate_student_row(i);
    }
    
    return result.str();
}