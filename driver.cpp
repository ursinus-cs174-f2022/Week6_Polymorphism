#include <iostream>
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
    int N = 5;
    Person** people = new Person*[N];
    people[0] = new SoccerPlayer("Hannah", "J", 60, 2026, true, "defense");
    people[1] = new Student("Tre", "D", 174, 2025, "cs");
    people[2] = new Person("Chris", "Tralie", 33, 2011);
    people[3] = new Student("Albert", "Einstein", 143, 1900, "teaching");
    people[4] = new Athlete("Usain", "Bolt", 36, 2008, "track", true);

    printPeople(people, N);

    // TODO: There is a memory leak
    delete[] people;
}
