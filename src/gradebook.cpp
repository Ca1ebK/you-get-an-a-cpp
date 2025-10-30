#include "gradebook.hpp"
#include <sstream>
#include <algorithm>

void Gradebook::add_student(const std::string& full_name, const std::string& student_id) {
    students.push_back({full_name, student_id});
    grades.resize(students.size());
    for (auto& row : grades) {
        row.resize(assignments.size(), -1.0);
    }
}

void Gradebook::add_assignment(const std::string& name, double points) {
    assignments.push_back({name, points});
    for (auto& row : grades) {
        row.resize(assignments.size(), -1.0);
    }
}

void Gradebook::enter_grade(const std::string& student_name, const std::string& assignment_name, double points) {
    int student_idx = find_student_index(student_name);
    int assignment_idx = find_assignment_index(assignment_name);
    
    if (student_idx == -1 || assignment_idx == -1) {
        return;
    }
    
    grades[student_idx][assignment_idx] = points;
}

std::string Gradebook::report() const {
    if (students.empty() || assignments.empty()) {
        return "";
    }
    
    std::stringstream result;
    
    // Create indices and sort by last name
    std::vector<size_t> indices(students.size());
    for (size_t i = 0; i < students.size(); i++) {
        indices[i] = i;
    }
    
    std::sort(indices.begin(), indices.end(), [this](size_t a, size_t b) {
        size_t space_a = students[a].full_name.find(' ');
        size_t space_b = students[b].full_name.find(' ');
        std::string last_a = (space_a != std::string::npos) ? students[a].full_name.substr(space_a + 1) : "";
        std::string last_b = (space_b != std::string::npos) ? students[b].full_name.substr(space_b + 1) : "";
        return last_a < last_b;
    });
    
    // Header
    result << "Last_Name,First_Name,Student_Id";
    for (const auto& assignment : assignments) {
        result << "," << assignment.name;
    }
    result << "\n";
    
    // Student rows (in sorted order)
    for (size_t idx : indices) {
        const auto& student = students[idx];
        size_t space_pos = student.full_name.find(' ');
        std::string first_name = (space_pos != std::string::npos) ? student.full_name.substr(0, space_pos) : student.full_name;
        std::string last_name = (space_pos != std::string::npos) ? student.full_name.substr(space_pos + 1) : "";
        
        result << last_name << "," << first_name << "," << student.student_id;
        
        for (size_t j = 0; j < assignments.size(); j++) {
            result << ",";
            if (grades[idx][j] >= 0.0) {
                result << static_cast<int>(grades[idx][j]);
            } else {
                result << "none";
            }
        }
        result << "\n";
    }
    
    return result.str();
}

int Gradebook::find_student_index(const std::string& student_name) const {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].full_name == student_name) return i;
    }
    return -1;
}

int Gradebook::find_assignment_index(const std::string& assignment_name) const {
    for (size_t i = 0; i < assignments.size(); i++) {
        if (assignments[i].name == assignment_name) return i;
    }
    return -1;
}
