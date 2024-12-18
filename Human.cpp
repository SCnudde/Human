#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class Date
{
    int day_;
    int month_;
    int year_;
public:
    Date() : Date(1, 1, 2024) {}
    explicit Date(int day) : Date(day, 1, 2024) {}
    Date(int day,int month) : Date(day, month, 2024) {}    
    Date(int day, int month, int year) : day_{ day }, month_{ month }, year_{ year } {}

    void Print();
    
    // getters
    int day() const;
    int month() const;
    int year() const;

    // setters
    Date& day(int day);
    Date& month(int month);
    Date& year(int year);
    Date& date(int day, int month, int year);

    // деструктор
    ~Date() {}
};

int Date::day() const
{
    return day_;
}

int Date::month() const
{
    return month_;
}

int Date::year() const
{
    return year_;
}

Date& Date::day( int day)
{
    day_ = day;
    return *this;
}

Date& Date::month(int month)
{
    month_ = month;
    return *this;
}

Date& Date::year(int year)
{
    year_ = year;
    return *this;
}

Date& Date::date(int day, int month, int year)
{
    day_ = day;
    month_ = month;
    year_ = year;
    return *this;
}

void Date::Print()
{
    std::cout << day_ << '.' << month_ << '.' << year_ << "\n";
}

class Human
{
    static int ID_;
    char* last_name_;
    char* first_name_;
    char* patronymic_;   

public:
    
    int id = 0;
    Human();
  
    Human(const char* first_name, const char* last_name, const char* patronimyc);
  
    void Print() const
    {
        std::cout << "ID: " << id << std::endl
            << "First name: " << first_name_ << std::endl
            << "Last name: " << last_name_ << std::endl
            << "Patronymic: " << patronymic_ << std::endl
            << "Birthday: " << std::endl;
    };

    // getters
    const char* last_name() const;
    const char* first_name() const;
    const char* patronymic() const;   

    // setters

    void set_first_name(char* first_name);
    void set_last_name(char* last_name);    
    void set_patronymic(char* patronymic);
   
    //конструктор копирования
    Human(const Human& object);

    ~Human()
    {
        id = --ID_;
        delete[] first_name_;
        delete[] last_name_;
        delete[] patronymic_;
    };
};

int Human::ID_ = 0;
Human::Human()
{
    id = ++ID_;
    first_name_ = NULL;
    last_name_ = NULL;
    patronymic_ = NULL;
};

//Getters
const char* Human::last_name() const
{
    return last_name_;
};

const char* Human::first_name() const
{
    return first_name_;
};

const char* Human::patronymic() const
{
    return patronymic_;
};

//Setters
 void Human::set_last_name(char* last_name)
{
    delete[] last_name_;
    last_name_ = new char[strlen(last_name) + 1];
    strcpy(last_name_, last_name);
};

void Human::set_first_name(char* first_name)
{
    delete[] first_name_;
    first_name_ = new char[strlen(first_name) + 1];
    strcpy(first_name_, first_name);
};

void  Human::set_patronymic(char* patronymic)
{
    delete[] patronymic_;
    patronymic_ = new char[strlen(patronymic) + 1];
    strcpy(patronymic_, patronymic);
};

 // конструктор с 1 параметром

//Human::Human(char* first_name)
//{
//    set_first_name(first_name);
//};

//конструктор копирования

Human::Human(const Human& object)
{
    id = ++ID_;
       
    delete[]first_name_;
    first_name_ = new char[strlen(object.first_name_) + 1];
    strcpy(first_name_, object.first_name_);

    delete[]last_name_;
    last_name_ = new char[strlen(object.last_name_) + 1];
    strcpy(last_name_, object.last_name_);

    delete[]patronymic_;
    patronymic_ = new char[strlen(object.patronymic_) + 1];
    strcpy(patronymic_, object.patronymic_);
    
};

// конструктор с параметрами

Human::Human(const char* first_name, const char* last_name, const char* patronimyc)
{
    id = ++ID_;

    delete[]first_name_;
    first_name_ = new char[strlen(first_name) + 1];
    strcpy(first_name_, first_name);

    delete[]last_name_;
    last_name_ = new char[strlen(last_name) + 1];
    strcpy(last_name_, last_name);

    delete[]patronymic_;
    patronymic_ = new char[strlen(patronimyc) + 1];
    strcpy(patronymic_, patronimyc);
};


int main()
{
   system("chcp 1251 >nul");
   setlocale(LC_ALL, "rus");
    
   std::cout << "Hello World!\n";
   
   Date Birthday{ 01,03,1987 };

   Human person_1("Serguey","Evgenievich","Ivanov");      
   
   Human person_2(person_1);
   Human person_3("Svetlana", "Ivanovna", "Kolobkova");   
   
   std::cout <<"_____________________" << "\n";
   person_1.Print();
   std::cout << "_____________________" << "\n";
   person_2.Print();
   std::cout << "_____________________" << "\n";
   person_3.Print();
   

  
}
