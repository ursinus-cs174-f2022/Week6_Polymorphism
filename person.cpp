#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include "person.h"

using namespace std;

// Implementation
Person::Person(int age, string name) { // Instance method
    mood = "happy";
    (*this).age = age;
    this->name = name;
}

string Person::toString() {
    stringstream stream;
    stream << this->name << " is " << age << " years old";
    return stream.str();
}




Student::Student(int age, string name, string classYear):Person(age, name) {
    this->classYear = classYear;
}
string Student::toString() {
    stringstream stream;
    stream << Person::toString();
    stream << ", is a " << classYear;
    return stream.str();
}