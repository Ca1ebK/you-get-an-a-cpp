#include "assignment.hpp"

Assignment::Assignment(const std::string& name, double total_points)
    : name(name), total_points(total_points) {}

std::string Assignment::getName() const {
    return name;
}

double Assignment::getTotalPoints() const {
    return total_points;
}

