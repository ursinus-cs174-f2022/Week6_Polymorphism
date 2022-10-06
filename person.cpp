#include "person.h"
#include <iostream>
using namespace std;

Person::Person(const char* firstName, const char* lastName, 
int age, int year) { // "Constructor method"
    this->firstName = firstName;
    this->lastName = lastName;
    if (age < 0) {
        cout << "Y0, you can't have a negative age\n";
    }
    this->age = age;
    this->year = year;
    numBirthdays = 0;
}

// Destructor (!!!!)
Person::~Person() {
    //cout << firstName << " " << lastName << " is being destructed\n";
}


void Person::celebrateBirthday() {
    age++;
    numBirthdays++;
}

void Person::printInfo() {
    cout << firstName << " " << lastName;
    cout << " is " << age << " years old, and";
    cout << " is in the class of " << year;
}



////////////////////////////////////////////////////


Athlete::Athlete(const char* firstName, const char* lastName, 
        int age, int year, const char* sport, bool varsity)
    :Person(firstName, lastName, age, year) {
    this->sport = sport;
    this->varsity = varsity;
}

void Athlete::printInfo() {
    Person::printInfo();
    cout << ", plays ";
    if (varsity) {
        cout << "varsity ";
    }
    cout << sport;
}


////////////////////////////////////////////////////
Student::Student(const char* firstName, const char* lastName, 
int age, int year, const char* major)
    :Person(firstName, lastName, age, year) {
    this->major = major;
}

void Student::printInfo() {
    Person::printInfo();
    cout << ", has major " << major;
}



SoccerPlayer::SoccerPlayer(const char* firstName, const char* lastName, 
int age, int year, bool varsity, const char* position)
    :Athlete(firstName, lastName, age, year, "Soccer", varsity) {
        this->position = position;
}

void SoccerPlayer::printInfo() {
    Athlete::printInfo();
    cout << ", plays position " << position;
}