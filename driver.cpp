#include <iostream>
#include <list>
#include "person.h"
using namespace std;

#define NUM_PEOPLE 5

int main() {
    list<Person*> people;
    //Person** people = new Person*[NUM_PEOPLE];
    people.push_back(new Student(80, "reagan", "freshman"));
    people.push_back(new Person(32, "Chris"));
    people.push_back(new Person(40, "Nick"));
    people.push_back(new Student(10, "einstein", "senior"));
    people.push_back(new StudentAthlete(20, "Eddie", "sophomore", "lacrosse"));
    
    list<Person*>::iterator it;
    // it will hold a reference to some element in the linked
    // list
    // Go through and remove anyone who's 32
    it = people.begin();
    while (it != people.end()) {
        Person* p = *it;
        if (p->getAge() == 32) {
            delete p; // Free dynamic memory
            it = people.erase(it);
        }
        else {
            it++;
        }
    }
    // Now start over at the beginning of the list and print out
    // anyone who's left
    for (it = people.begin(); it != people.end(); it++) {
        Person* p = *it;
        cout << p->toString() << "\n";
    }

    // Cleanup (before I burn my map, I need
    // to follow my map to the locations I'm trying
    // to blowup)
    for (it = people.begin(); it != people.end(); it++) {
        delete *it;
    }
    return 0;
}
