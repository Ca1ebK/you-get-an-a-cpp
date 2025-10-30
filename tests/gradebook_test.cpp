#include <catch2/catch_test_macros.hpp>
#include "../src/gradebook.hpp"

TEST_CASE("Add student to gradebook") {
    Gradebook gradebook;
    gradebook.add_student("John Doe", "J001");
    gradebook.add_student("Jane Smith", "J002");
}

TEST_CASE("Add assignment to gradebook") {
    Gradebook gradebook;
    gradebook.add_assignment("Homework 1", 100.0);
    gradebook.add_assignment("Midterm", 150.0);
}

TEST_CASE("Enter grade for student and assignment") {
    Gradebook gradebook;
    gradebook.add_student("Alice Anderson", "A001");
    gradebook.add_assignment("Homework 1", 100.0);
    
    gradebook.enter_grade("Alice Anderson", "Homework 1", 85.0);
    gradebook.enter_grade("Alice Anderson", "Homework 1", 0.0);
    gradebook.enter_grade("Alice Anderson", "Homework 1", 100.0);
}

TEST_CASE("Report with multiple students and assignments") {
    Gradebook gradebook;
    gradebook.add_student("Alice Anderson", "A001");
    gradebook.add_student("Bob Brown", "B002");
    gradebook.add_assignment("Homework 1", 100.0);
    gradebook.add_assignment("Midterm", 150.0);
    
    gradebook.enter_grade("Alice Anderson", "Homework 1", 95.0);
    gradebook.enter_grade("Alice Anderson", "Midterm", 142.0);
    gradebook.enter_grade("Bob Brown", "Homework 1", 87.0);
    
    std::string result = gradebook.report();
    REQUIRE(result.length() > 0);
}

TEST_CASE("Empty gradebook returns empty report") {
    Gradebook empty_gradebook;
    std::string result = empty_gradebook.report();
    REQUIRE(result == "");
}

TEST_CASE("Report shows none for missing grades") {
    Gradebook gradebook;
    gradebook.add_student("Alice Anderson", "A001");
    gradebook.add_assignment("Homework 1", 100.0);
    gradebook.add_assignment("Homework 2", 100.0);
    
    gradebook.enter_grade("Alice Anderson", "Homework 1", 0.0);
    
    std::string result = gradebook.report();
    REQUIRE(result.find("none") != std::string::npos);
}
