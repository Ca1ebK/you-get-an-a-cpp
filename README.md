# You Get an A (C++)

You can find the instructions for this lab at [More Than Equations][more-than-equations]. Create a new repository on GitHub to house your code. Be sure to make the repository public so that I can view and grade it.

We will use [CMake][cmake] to build executables (e.g. tests, the driver program, the benchmarks, etc.). Additionally, we will use [Catch2][catch2] for unit testing and benchmarking.

## Building Executables With CMake

You can use CMake to compile and build the executables for the project. First, you need to create a `build/` directory in the project. The build directory will house all of the compiled files as well as the `Makefile` for the project. Note that we do NOT check the `build/` directory into version control since each person will have to regenerate the executables on their own machine.

```bash
mkdir build
cd build
```

Once you are inside of the build directory, you can run the following command to build all of the executables for the project:

```bash
cmake .. && make
```

## Testing the App

Any tests that you define in the `tests/` directory must have a corresponding entry in `CMakeLists.txt`. After you build executables using CMake, you can run the corresponding test files from within the `build/` directory.

## Running the App

The `main.cpp` file at the root of the project must have a corresponding entry in `CMakeLists.txt`. After you build executables using CMake, you can run the driver program from within the `build/` directory.

```bash
./main
```

## Using the Gradebook

The `Gradebook` class allows you to track grades for CSC 122. Here's how to use it:

### 1. Add Students

Add students to your gradebook using `add_student()`:

```cpp
Gradebook gradebook;
gradebook.add_student("Bob Bobberson", "ABC123");
gradebook.add_student("Sam Sammerson", "DEF456");
```

Each student needs:
- Full name (string) - first and last name separated by a space
- Student ID (string)

### 2. Add Assignments

Add assignments to your gradebook using `add_assignment()`:

```cpp
gradebook.add_assignment("Quiz 1", 100);
gradebook.add_assignment("Lab 1", 50);
```

Each assignment needs:
- Assignment name (string)
- Total points possible (double)

### 3. Enter Grades

Enter a grade for a student on an assignment using `enter_grade()`:

```cpp
gradebook.enter_grade("Sam Sammerson", "Quiz 1", 95);
gradebook.enter_grade("Bob Bobberson", "Quiz 1", 85);
```

### 4. Generate Report

Generate a CSV-formatted report of all students and their grades:

```cpp
std::cout << gradebook.report();
```

The report is formatted as CSV with:
- Header row: Last_Name,First_Name,Student_Id,Assignment1,Assignment2,...
- Student rows in the order they were added
- Grades shown as integers, or "none" for missing grades

### Example Usage

See `main.cpp` for a complete example demonstrating all operations. The example matches the professor's sample code.

### Running Tests

To run the gradebook unit tests:

```bash
./gradebook_test
```

## Running Benchmarks

Benchmarking is provided with Catch2. You can write benchmarking assertions alongside test assertions right in your test files.

[catch2]: https://github.com/catchorg/Catch2
[cmake]: https://cmake.org/
[more-than-equations]: https://morethanequations.com/Computer-Science/Labs/You-Get-an-A
