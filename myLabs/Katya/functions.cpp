#include "functions.h"
using namespace std;

Man::Man() {
    cout << "Constructor of Man" << endl;
}

Man::~Man() {
    cout << "Destructor of Man" << endl;
}

Teacher::Teacher(const char* course, const char* firstName, const char* secondName, int age, int experience, int year, int month, int day) {
    cout << "Constructor of Teacher" << endl;
    strncpy(this->course, course, SIZE);
    strncpy(this->ManFirstName, firstName, SIZE);
    strncpy(this->ManSecondName, secondName, SIZE);
    this->age = age;
    this->experience = experience;
    this->day = day;
    this->year = year;
    this->month = month;
}

Teacher::~Teacher() {
    cout << "Destructor of Teacher" << endl;
}

const char* Teacher::getFName() {
    return ManFirstName;
}

const char* Teacher::getSName() {
    return ManSecondName;
}

int Teacher::getAge() {
    return age;
}

void Teacher::setAge(int newAge) {
    age = newAge;
}

int Teacher::getExperience() {
    return experience;
}

const char* Teacher::getName() {
    return course;
}

bool isValidDate(int year, int month, int day)
{
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        return false;
    }


    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        return false;
    }
    else if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            if (day > 29)
            {
                return false;
            }
        } else
        {
            if (day > 28)
            {
                return false;
            }
        }
    }

    return true;
}



UnionMember::UnionMember(const char* post, const char* firstName, const char* secondName, int age) {
    cout << "Constructor of UnionMember" << endl;
    strncpy(this->post, post, SIZE);
    strncpy(this->ManFirstName, firstName, SIZE);
    strncpy(this->ManSecondName, secondName, SIZE);
    this->age = age;
}

UnionMember::~UnionMember()
{
    cout << "Destructor of UnionMember" << endl;
}

const char* UnionMember::getFName() {
    return ManFirstName;
}

const char* UnionMember::getSName() {
    return ManSecondName;
}

int UnionMember::getAge() {
    return age;
}

void UnionMember::setAge(int newAge) {
    age = newAge;
}

const char* UnionMember::getPost() {
    return post;
}

UnionMemberAndTeacher::UnionMemberAndTeacher(const char* interests, const char* course, const char* post, const char* firstName,
                                             const char* secondName, int age, int experience, int year, int month, int day)
        : Teacher(course, firstName, secondName, age, experience,year, month, day), UnionMember(post, firstName, secondName, age) {
    cout << "Constructor of UnionMemberAndTeacher" << endl;
    strncpy(this->interests, interests, SIZE);
}

UnionMemberAndTeacher::~UnionMemberAndTeacher()
{
    cout << "Destructor of UnionMemberAndTeacher" << endl;
}

const char* UnionMemberAndTeacher::getFName() {
    return Teacher::getFName();
}

const char* UnionMemberAndTeacher::getSName() {
    return Teacher::getSName();
}

int UnionMemberAndTeacher::getAge() {
    return Teacher::getAge();
}

void UnionMemberAndTeacher::setAge(int newAge) {
    Teacher::setAge(newAge);
}

int UnionMemberAndTeacher::getExperience() {
    return Teacher::getExperience();
}

const char* UnionMemberAndTeacher::getInterest() {
    return interests;
}

bool isValidNum(int& num) {
    if (cin >> num) {
        return true;
    }
    else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw ExceptionInputNumber("Ошибка ввода числа");
    }
}





void task1() {
    char course[SIZE];
    char firstName[SIZE];
    char secondName[SIZE];
    int experience;
    int age;
    int day;
    int year;
    int month;

    cout << "Enter course: ";
    cin >> course;
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter second name: ";
    cin >> secondName;
    cout << "Enter experience: ";
    isValidNum(experience);
    cout << "Enter data: ";
    isValidNum(day);
    isValidNum(month);
    isValidNum(year);
    if(!isValidDate(year, month, day)) throw ExceptionInputData("Ошибка ввода даты");

    if(experience <= 0 || experience > 100) throw ExceptionInputAge("Ошибка ввода опыта работы");

    cout << "Enter age: ";
    isValidNum(age);
    if(age <= 0 || age > 100) throw ExceptionInputAge("Ошибка ввода возраста");



    Teacher teacher(course, firstName, secondName, age, experience, year, month, day);
    cout << "Teacher created: " << teacher.getFName() << " " << teacher.getSName()
         << ", Age: " << teacher.getAge() << ", Course: " << teacher.getName() << ", Experience: "
         << teacher.getExperience() << endl;
}

void task2() {
    char post[SIZE];
    char firstName[SIZE];
    char secondName[SIZE];
    int age;

    cout << "Enter post: ";
    cin >> post;
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter second name: ";
    cin >> secondName;
    cout << "Enter age: ";
    isValidNum(age);
    if(age <= 0 || age > 100) throw ExceptionInputAge("Ошибка ввода возраста");

    UnionMember member(post, firstName, secondName, age);
    cout << "Union Member created: " << member.getFName() << " " << member.getSName()
         << ", Age: " << member.getAge() << ", Post: " << member.getPost() << endl;
}

void task3() {
    char interests[SIZE];
    char course[SIZE];
    char post[SIZE];
    char firstName[SIZE];
    char secondName[SIZE];
    int experience;
    int age;
    int day;
    int month;
    int year;

    cout << "Enter interests: ";
    cin >> interests;
    cout << "Enter course: ";
    cin >> course;
    cout << "Enter post: ";
    cin >> post;
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter second name: ";
    cin >> secondName;
    cout << "Enter experience: ";
    isValidNum(experience);
    cout << "Enter age: ";
    isValidNum(age);
    if(age <= 0 || age > 100) throw ExceptionInputAge("Ошибка ввода возраста");
    cout << "Enter data: ";
    isValidNum(day);
    isValidNum(month);
    isValidNum(year);
    if(!isValidDate(year, month, day)) throw ExceptionInputData("Ошибка ввода даты");


    UnionMemberAndTeacher memberTeacher(interests, course, post, firstName, secondName, age, experience, year, month, day);
    cout << "Union Member and Teacher created: " << memberTeacher.getFName() << " " << memberTeacher.getSName()
         << ", Age: " << memberTeacher.getAge() << ", Course: " << memberTeacher.getName()
         << ", Post: " << memberTeacher.getPost() << ", Interest: " << memberTeacher.getInterest() << endl;
}

void task4() {
    Teacher teachers[] = {
            Teacher("Math", "John", "Doe", 35, 6, 12,11,2000),
            Teacher("Physics", "Alice", "Smith", 42, 10,11,11,2000),
            Teacher("History", "Bob", "Johnson", 28, 71, 55,3,2001)
    };

    UnionMember members[] = {
            UnionMember("President", "Tom", "Brown", 45),
            UnionMember("Secretary", "Sara", "White", 30),
            UnionMember("Treasurer", "Emma", "Davis", 38)
    };

    UnionMemberAndTeacher memberTeachers[] = {
            UnionMemberAndTeacher("Science Club", "Biology", "Chairman", "Chris", "Lee", 33, 8,3,2,2002),
            UnionMemberAndTeacher("Art Club", "English", "Vice President", "Eva", "Wilson", 40, 9,5,7,2001),
            UnionMemberAndTeacher("Music Club", "Chemistry", "Coordinator", "Max", "Clark", 35, 11,3,4,2001)
    };


    cout << "Information about Teachers:" << endl;
    for (Teacher teacher : teachers) {
        cout << "Teacher: " << teacher.getFName() << " " << teacher.getSName()
             << ", Age: " << teacher.getAge() << ", Course: " << teacher.getName() << ", Experience: "
             << teacher.getExperience() << endl;
    }


    cout << "\nInformation about Union Members:" << endl;
    for (UnionMember member : members) {
        cout << "Union Member: " << member.getFName() << " " << member.getSName()
             << ", Age: " << member.getAge() << ", Post: " << member.getPost() << endl;
    }


    cout << "\nInformation about Union Members and Teachers:" << endl;
    for (UnionMemberAndTeacher memberTeacher : memberTeachers) {
        cout << "MemberTeacher: " << memberTeacher.getFName() << " " << memberTeacher.getSName()
             << ", Age: " << memberTeacher.getAge() << ", Course: " << memberTeacher.getName()
             << ", Post: " << memberTeacher.getPost() << ", Interest: " << memberTeacher.getInterest()
             << ", Experience: " << memberTeacher.getExperience() << endl;
    }
}