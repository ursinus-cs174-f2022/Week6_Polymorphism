#include <iostream>
#include <list>
#include "person.h"
using namespace std;

#define NUM_PEOPLE 5

int main() {
    Person** people = new Person*[NUM_PEOPLE];
    *people = new Student(80, "reagan", "freshman");
    *(people+1) = new Person(32, "Chris");
    people[2] = new Person(40, "Nick");
    people[3] = new Student(10, "einstein", "senior");
    people[4] = new StudentAthlete(20, "Eddie", "sophomore", "lacrosse");
    
    // Remove Chris, knowing that he's at index 1
    // Loop through, set any entry at index > 1
    // to be that index -1
    // Delete the last
    int idxRem = 1;
    delete people[idxRem];
    Person** peopleNew = new Person*[NUM_PEOPLE-1];
    // Step 1: Copy everything before idxRem over
    // to this new array
    for (int i = 0; i < idxRem; i++) {
        peopleNew[i] = people[i];
    }
    for (int i = idxRem+1; i < NUM_PEOPLE; i++) {
        peopleNew[i-1] = people[i];
    }
    delete[] people;
    people = peopleNew;
    for (int i = 0; i < NUM_PEOPLE-1; i++) {
        cout << people[i]->toString() << "\n";
    }
    // Cleanup (before I burn my map, I need
    // to follow my map to the locations I'm trying
    // to blowup)
    for (int i = 0; i < NUM_PEOPLE-1; i++) {
        delete people[i];
    }
    delete[] people; // Deleting what peopleNew referred to
    return 0;
}
