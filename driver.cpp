#include <iostream>
#include "person.h"
using namespace std;

#define NUM_PEOPLE 4

int main() {
    Person** people = new Person*[NUM_PEOPLE];
    people[0] = new Student(80, "reagan", "freshman");
    people[1] = new Person(32, "Chris");
    people[2] = new Person(40, "Nick");
    people[3] = new Student(10, "einstein", "senior");
    for (int i = 0; i < NUM_PEOPLE; i++) {
        cout << people[i]->toString() << "\n";
    }

    // Cleanup
    for (int i = 0; i < NUM_PEOPLE; i++) {
        delete people[i];
    }
    delete[] people;
    return 0;
}
