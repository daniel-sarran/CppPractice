#include <iostream>
using std::string;

// https://www.youtube.com/watch?v=wN0x9eZLix4&ab_channel=freeCodeCamp.org

class AbstractEmployee {
    // Interface for Employee
    virtual void AskForPromotion() = 0;
    // Whoever implements abstract employee has to provide implementation for
    // "AskForPromotion" -- a "Pure Function"?

    // When a virtual function is invoked, "can you check if implementation
    // available in my derived classes? if yes, execute that instead.""
    // Polymorphism in a nutshell
};

class Employee : AbstractEmployee {
   public:
    // Getters and setters can be named like variables, snake_case
    void set_name(string name) {
        name_ = name;
    }
    string name() {
        return name_;
    }
    void set_company(string company) {
        company_ = company;
    }
    string company() {
        return company_;
    }
    void set_age(int age) {
        age_ = age;
    }
    int age() {
        return age_;
    }
    // Functions are PascalCase
    void IntroduceYourself() {
        std::cout << "Name - " << name_ << std::endl;
        std::cout << "Company - " << company_ << std::endl;
        std::cout << "Age - " << age_ << std::endl;
    }
    void AskForPromotion() {
        if (age_ > 30) {
            std::cout << name_ << " got promoted!" << std::endl;
        } else {
            std::cout << name_ << ", sorry, no promotion!" << std::endl;
        }
    }
    virtual void Work() {
        // Polymorphism: we are going to override this Work function for both
        // Teacher and Developer -- so that it is unique to those inheriting
        // classes
        std::cout << name_ << " is checking email, task backlog... "
                  << std::endl;
    }
    Employee(string name, string company, int age) {
        // Constructor
        // No return type
        // Public
        // Same name as class
        name_ = name;
        company_ = company;
        age_ = age;
        // class data members have trailing underscore, e.g. snake_case_
    }

   protected:
    string name_;

   private:
    string company_;
    int age_;
};

class Developer : public Employee {
    // Public in inheritance is necessary if you want to access public
    // members of Employee, otherwise assumed private
   public:
    string favorite_programming_language_;
    Developer(string name, string company, int age, string language)
        : Employee(name, company, age) {
        // We list ALL the construction args, even inherited ones
        // Then we divert the inherited args to the Employee constructor
        favorite_programming_language_ = language;
    }
    void FixBug() {
        std::cout << name_ << " fixed bug using "
                  << favorite_programming_language_ << std::endl;
    }
    virtual void Work() {
        std::cout << name_ << " coding and fixing bugs in "
                  << favorite_programming_language_ << std::endl;
    }
};

class Teacher : public Employee {
   public:
    string subject_;
    void PrepareLesson() {
        std::cout << name_ << " is preparing " << subject_ << " lesson."
                  << std::endl;
    }
    void Work() {
        std::cout << name_ << " is teaching " << subject_ << "." << std::endl;
    }
    Teacher(string name, string company, int age, string subject)
        : Employee(name, company, age) {
        subject_ = subject;
    }
};

int main() {
    Developer d = Developer("Daniel", "Facebook", 35, "C++");
    Teacher t = Teacher("Kristina", "Heritage", 30, "Spanish");

    Employee* e1 = &d;
    Employee* e2 = &t;

    e1->Work();
    e2->Work();
}