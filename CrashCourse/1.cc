#include <iostream>
using std::string;

class Employee {
   public:
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

    void IntroduceYourself() {
        std::cout << "Name - " << name_ << std::endl;
        std::cout << "Company - " << company_ << std::endl;
        std::cout << "Age - " << age_ << std::endl;
    }
    Employee(string name, string company, int age) {
        name_ = name;
        company_ = company;
        age_ = age;
    }

   private:
    string name_;
    string company_;
    int age_;
};

int main() {
    Employee employee1 = Employee("Daniel", "Google", 35);
    employee1.IntroduceYourself();
    employee1.set_age(22);
    employee1.IntroduceYourself();
}