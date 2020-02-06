//
//  main.cpp
//  animal project
//
//  Created by mac on 2019. 5. 11..
//  Copyright © 2019년 Minji_Lee. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Animal {
    
public :
    
    static int animalNumber;
    static int rabbitNumber;
    static int catNumber;
    static int personNumber;
    static int studentNumber;
    
    static void animalCount(void){
        std::cout << std::endl;
        std::cout << "****************************" << std::endl;
        std::cout << " Statistics " << std::endl;
        std::cout << "****************************" << std::endl;
        std::cout << " # of Animal : " << animalNumber << std::endl;
        std::cout << " # of Rabbit : " << rabbitNumber << std::endl;
        std::cout << " # of Cat : " << catNumber << std::endl;
        std::cout << " # of Person : " << personNumber << std::endl ;
        std::cout << " # of Studnet : " << studentNumber << std::endl ;
        std::cout << "****************************" << std::endl;
    }
    
    Animal() {}
    
    Animal(int newAge, string newName){
        
        setAge(newAge);
        setName(newName);
        animalNumber++;
    }
    
    Animal(const Animal& rhs){
        age = rhs.age;
        name = rhs.name;
    }
    
    int get_age(){
        return age;
    }
    
    string get_name(){
        return name;
    }
    
    void setAge(int value){
        age = value;
    }
    
    void setName(string value){
        name = value;
    }
    
    void print() {
        
        cout << "Animal : (" << age << ", " << name << " ) \n" ;
    }
    
    ~Animal(){
        animalNumber--;
    }


    protected :

    int age;
    string name;
    
    
};

class Rabbit: public Animal {
    
public :
    
    Rabbit(const Rabbit& rhs){
        age = rhs.age;
        name = rhs.name;
    }
    Rabbit(int newAge, string newName): Animal(newAge, newName){
        rabbitNumber++;
    }
    
    void print() {
        
        cout << "Rabbit : (" << age << ", " << name << " ) \n" ;
        
    }
    
    
    ~Rabbit(){
        rabbitNumber--;
    }
};

class Cat: public Animal {
    
    public :
    
    Cat(const Cat& rhs){
        age = rhs.age;
        name = rhs.name;
    }
    Cat(int newAge, string newName): Animal(newAge, newName){
        catNumber++;
    }
    
    void print() {
        
        cout << "Cat : (" << age << ", " << name << " ) \n" ;
        
    }
    
    void speak() {
        
        cout << "Meow! \n";
    }
    
    ~Cat(){
        catNumber--;
    }
};

class Person: public Animal {
    
    
public :
    
    Person () {}
    Person(int newAge, string newName) : Animal(newAge, newName) {
        personNumber++;
    }
    

    
    int age_diff (Person &other){
        
        if(age>other.get_age()){
            return age - other.get_age();
        }
        else{
            return other.get_age() - age;
        }
    
    }
    
    void speak() {
        
        cout << "Hello\n";
    }
    
    void print() {
        
        cout << "Person : (" << age << ", " << name << " ) \n" ;
        
    }
    ~Person(){
        personNumber--;
    }
};

class Student: public Person {
    
    string major;
    
public :
    
    Student(int newAge, string newName, string newMajor): Person(newAge, newName){
        setAge(newAge);
        setName(newName);
        Change_major(newMajor);
        studentNumber++;
    }
    
   void Change_major(string newMajor){
       major=newMajor;
    }
    
    void print() {
        
        cout << "Student : (" << age << ", " << name << " ) \n" ;
        
    }
    void speak() {
        
        cout << "I have a homework \n";
    }
    
    ~Student(){
        studentNumber--;
    }
};


    int Animal::animalNumber =0 ;
    int Animal::rabbitNumber =0 ;
    int Animal::catNumber =0 ;
    int Animal::personNumber =0 ;
    int Animal::studentNumber =0 ;

int main(void)
{
    Animal a1 (2, "animal1" );
    Animal a2 (3, "animal2" );
    Rabbit r1 (4, "rabbit1" );
    Rabbit r2 (5, "rabbit2" );
    Cat c1 (6, "cat1" );
    Cat c2 (7, "cat2" );
    Person p1 (6, "person1" );
    Person p2 (7, "person2" );
    Student s1 (8, "student1", "CS" );
    Student s2 (9, "student2","EE" );
    
    a1.print();
    a2.print();

    r1.print();
    r2.print();

    c1.print();
    c2.print();
    c1.speak();
    c2.speak();

    p1.print();
    p2.print();
    p1.speak();
    p2.speak();
    std::cout << p1.age_diff(p2) << std::endl;

    s1.print();
    s2.print();
    s1.speak();
    s2.speak();
    std::cout << s1.age_diff(s2) << std::endl;
 
    Animal::animalCount();
    
    return 0;
}
