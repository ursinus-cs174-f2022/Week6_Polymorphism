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
            Person** temp = new Person*[N];
            for (int k = 0; k < N; k++) {
                if (k < i) {
                    temp[k] = people[k];    
                }
                else {
                    temp[k] = people[k+1];
                }
            }
            delete[] people;
            people = temp;
        }
    }

    // Print again to make sure they're gone
    printPeople(people, N);

    // TODO: There is a memory leak
    for (int i = 0; i < N; i++) {
        delete people[i];
    }
    delete[] people;
}
