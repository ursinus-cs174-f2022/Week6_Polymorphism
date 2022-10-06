#ifndef PERSON_H
#define PERSON_H

class Person {
    protected:
        // Instance variables
        int numBirthdays; // Keep track of #of birthdays I've celebrated
        // since calling the constructor
        const char* firstName; // "Camel case"
        const char* lastName;
        int age;
        int year;

    public:
        // Instance methods
        Person() {}
        Person(const char* firstName, const char* lastName, 
        int age, int year);

        // Destructor (!!!!)
        ~Person();
        void celebrateBirthday();

        /*****The virtual keyword here leads to runtime polymorphism****/
        virtual void printInfo(); 
}; // Every class definition ends with a semicolon



class Athlete: public Person {
    protected:
        const char* sport;
        bool varsity;
    
    public:
        Athlete(const char* firstName, const char* lastName, 
        int age, int year, const char* sport, bool varsity);
        
        void printInfo();


}; // Every class definition ends with a semicolon


class Student: public Person {
    public:
        const char* major;

        Student(const char* firstName, const char* lastName, 
    int age, int year, const char* major);

    void printInfo();
};



class SoccerPlayer: public Athlete {
    private:
        const char* position;
    public:
        SoccerPlayer(const char* firstName, const char* lastName, 
        int age, int year, bool varsity, const char* position);

        void printInfo();
};

#endif