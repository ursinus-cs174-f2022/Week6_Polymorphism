#include <iostream>
#include "person.h"
using namespace std;

int main() {
    SoccerPlayer hannah("Hannah", "J", 60, 2026, true, "defense");
    Person chris("Chris", "Tralie", 33, 2011);
    Student tre("Tre", "D", 174, 2025, "cs");

    int N = 3;
    Person** people = new Person*[N];
    people[0] = &hannah;
    people[1] = &chris;
    people[2] = &tre;

    for (int i = 0; i < N; i++) {
        people[i]->printInfo();
        cout << "\n\n";
    }
    delete[] people;
}
