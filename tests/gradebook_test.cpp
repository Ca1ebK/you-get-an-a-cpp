#include <catch2/catch_test_macros.hpp>
#include "../src/gradebook.hpp"

TEST_CASE("One student with one assignment and one grade") {
    Gradebook gradebook;
    gradebook.add_student("Alice Anderson", "A001");
    gradebook.add_assignment("Quiz 1", 100.0);
    gradebook.enter_grade("Alice Anderson", "Quiz 1", 85.0);
    
    std::string result = gradebook.report();
    REQUIRE(result.find("Anderson") != std::string::npos);
    REQUIRE(result.find("Alice") != std::string::npos);
    REQUIRE(result.find("A001") != std::string::npos);
    REQUIRE(result.find("85") != std::string::npos);
}

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

TEST_CASE("Enter grade for non-existent student") {
    Gradebook gradebook;
    gradebook.add_student("Alice Anderson", "A001");
    gradebook.add_assignment("Quiz 1", 100.0);
    
    gradebook.enter_grade("Bob Brown", "Quiz 1", 95.0);
    
    std::string result = gradebook.report();
    REQUIRE(result.find("none") != std::string::npos);
}

TEST_CASE("Enter grade for non-existent assignment") {
    Gradebook gradebook;
    gradebook.add_student("Alice Anderson", "A001");
    gradebook.add_assignment("Quiz 1", 100.0);
    
    gradebook.enter_grade("Alice Anderson", "Midterm", 95.0);
    
    std::string result = gradebook.report();
    REQUIRE(result.find("none") != std::string::npos);
}

TEST_CASE("Boundary: Maximum grade value") {
    Gradebook gradebook;
    gradebook.add_student("Alice Anderson", "A001");
    gradebook.add_assignment("Extra Credit", 1000.0);
    gradebook.enter_grade("Alice Anderson", "Extra Credit", 999.0);
    
    std::string result = gradebook.report();
    REQUIRE(result.find("999") != std::string::npos);
}

TEST_CASE("Boundary: Name with multiple spaces") {
    Gradebook gradebook;
    gradebook.add_student("Mary Jane Watson", "M001");
    gradebook.add_assignment("Quiz 1", 100.0);
    gradebook.enter_grade("Mary Jane Watson", "Quiz 1", 90.0);
    
    std::string result = gradebook.report();
    REQUIRE(result.find("Mary") != std::string::npos);
}

TEST_CASE("Boundary: Single name without space") {
    Gradebook gradebook;
    gradebook.add_student("Cher", "C001");
    gradebook.add_assignment("Quiz 1", 100.0);
    gradebook.enter_grade("Cher", "Quiz 1", 88.0);
    
    std::string result = gradebook.report();
    REQUIRE(result.find("Cher") != std::string::npos);
    REQUIRE(result.find("88") != std::string::npos);
}
