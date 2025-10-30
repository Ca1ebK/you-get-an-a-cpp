#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

#include <string>

class Assignment {
public:
    Assignment(const std::string& name, double total_points);
    
    std::string getName() const;
    double getTotalPoints() const;

private:
    std::string name;
    double total_points;
};

#endif // ASSIGNMENT_HPP

