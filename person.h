#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

// "Forward declaration" (Specification)
class Person {
    protected:
        int age; // Member variable
        string name;
        string mood;

    public:
        Person(int age, string name);
        string toString();
};

class Student: public Person {
    private:
        string classYear;
    public:
        Student(int age, string name, string classYear);
        string toString();
};