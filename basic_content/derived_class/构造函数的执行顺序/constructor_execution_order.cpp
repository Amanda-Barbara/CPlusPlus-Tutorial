#include <iostream>
#include <memory>
#include <map>

using namespace std;

class Person{
public:
    Person(const string& nm, const string& id);
public:
    string name;
    string idNum;
};
Person::Person(const string& nm, const string& id)
{
    name = nm;
    idNum = id;
}
class Student : public Person{
public:
    Student(const string& nm, const string& id, const string& maj, int year);
    string major;
    int gradYear;
};
Student::Student(const string& nm, const string& id, const string& maj, int year)
        : Person(nm, id){
    // Person(nm, id)基类构造函数放在这里程序编译时报错
    major =maj;
    gradYear =year;
}


int main() {
    Student s1("jack", "001", "math", 1);
    cout << s1.name << endl;
}
