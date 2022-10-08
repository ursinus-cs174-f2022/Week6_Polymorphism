#include <iostream>
#include <list>
#include "person.h"
using namespace std;

/**
 * @brief Print out the array of people
 * 
 * @param people Array of Person references
 * @param N Number of people in the array
 */
void printPeople(Person** people, int N) {
    for (int i = 0; i < N; i++) {
        people[i]->printInfo();
        cout << "\n\n";
    }
}

int main() {
    list<Person*> people;
    people.push_back( new SoccerPlayer("Hannah", "J", 60, 2026, true, "defense"));
    people.push_back(new Student("Tre", "D", 174, 2025, "cs"));
    people.push_back(new Person("Chris", "Tralie", 33, 2011));
    people.push_back(new Student("Albert", "Einstein", 143, 1900, "teaching"));
    people.push_back(new Athlete("Usain", "Bolt", 36, 2008, "track", true));

    list<Person*>::iterator it;
    for (it = people.begin(); it != people.end(); it++) {
        Person* p = (Person*)*it;
        if (p->getAge() == 33) {
            // This is how you delete an element in
            // the middle of an array
            it = people.erase(it);
        }
    }

    // Print out info
    for (it = people.begin(); it != people.end(); it++) {
        Person* p = (Person*)*it;
        p->printInfo();
        cout << "\n";
    }

    cout << "\n\n";
    // Clean up memory
    for (it = people.begin(); it != people.end(); it++) {
        Person* p = (Person*)*it;
        delete p;
    }

}
