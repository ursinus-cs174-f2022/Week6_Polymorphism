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

    // Programmatically delete the person whose age is 33
    for (int i = 0; i < N; i++) {
        if(people[i]->getAge() == 33) {
            delete people[i];
            N--;
            // Make a new array
            Person** temp = new Person*[N];
            for (int k = 0; k < N; k++) {
                if (k < i) {
                    // Copy over everything before the removed index to the same index
                    temp[k] = people[k];    
                }
                else {
                    // Copy over everything after shifted by 1
                    temp[k] = people[k+1];
                }
            }
            // Free up the old array, and set the people reference to be the new array
            delete[] people;
            people = temp;
        }
    }

    // Print again to make sure they're gone
    printPeople(people, N);
    // Delete people, then array of people references
    for (int i = 0; i < N; i++) {
        delete people[i];
    }
    delete[] people;
}
