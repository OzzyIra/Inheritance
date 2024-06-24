#include <iostream>

using namespace std;
#define delimiter "\n------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age


class Human
{
    std::string last_name;
    std::string first_name;
    unsigned int age;
public:
    const std::string& get_last_name()const
    {
        return last_name;
    }
    const std::string& get_first_name()const
    {
        return first_name;
    }
    const unsigned int get_age()const
    {
        return age;
    }
    void set_last_name(const std::string& last_name)
    {
        this->last_name = last_name;
    }
    void set_first_name(const std::string& first_name)
    {
        this->first_name = first_name;
    }
    void set_age(unsigned int age)
    {
        this->age = age;
    }
    //      Constructer
    Human(HUMAN_TAKE_PARAMETERS)
    {
        set_last_name(last_name);
        set_first_name(first_name);
        set_age(age);
        cout << "HConstructer:\t" << this << endl;
    }
   virtual ~Human()
    {
        cout << "HDestructor:\t" << this << endl;
    }

    //      Methods
   virtual void info()const
    {
        cout << last_name << " " << first_name << " " << age << "y/o"<<endl;
    }
};

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance
class Student :public Human
{
    std::string speciality;
    std::string group;
    double rating;
    double attendance;
public:
    const std::string& get_speciality()const
    {
        return speciality;
    }
    const std::string& get_group()const
    {
        return group;
    }
    double get_rating()const
    {
        return rating;
    }
    double get_attendance()const
    {
        return attendance;
    }
    void set_speciality(const std::string& speciality)
    {
        this->speciality = speciality;
    }
    void set_group(const std::string& group)
    {
        this->group = group;
    }
    void set_reting(double rating)
    {
        this->rating = rating;
    }
    void set_attendance(double attendance)
    {
        this->attendance = attendance;
    }
    //      Constructer
    Student
    (HUMAN_TAKE_PARAMETERS,STUDENT_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
    {

        set_speciality(speciality);
        set_group(group);
        set_reting(rating);
        set_attendance(attendance);
        cout << "SConstructer:\t" << this << endl;

    }
    ~Student()
    {
        cout << "SDestructor:\t" << this << endl;       
    }
    //      Methods
    void info()const override // ��������������
    {
        Human::info();
        cout << speciality << " " << group << " " << rating << " " << attendance << endl;
    }
    

};
class Teacher :public Human
{
    std::string speciality;
    unsigned experience;
public:
    const std::string& get_speciality()const
    {
        return speciality;
    }
   unsigned int get_experience()const
    {
        return experience;
    }
   void set_speciality(const std::string& speciality)
   {
       this->speciality = speciality;
   }
   void set_experience(unsigned int experience)
   {
       this->experience = experience;
   }
   //       Constructer
   Teacher(HUMAN_TAKE_PARAMETERS, const std::string& speciality, unsigned int experiance) :Human(HUMAN_GIVE_PARAMETERS)
   {
       set_speciality(speciality);
       set_experience(experiance);
       cout << "TConstructer:\t" << this << endl;
   }
   ~Teacher()
   {
       cout << "TDestructor:\t" << this << endl;
   }
   //       Methods
   void info()const
   {
       Human::info();
       cout << speciality << " " << experience << " years" << endl;
   }

};

class Graduate :public Student
{
    std::string them;
    std::string supervisor;
public:
    const std::string& get_theem()const
    {
        return them;
    }
    const std::string& get_supervisor()const
    {
        return supervisor;
    }
    void set_them(const std::string& them)
    {
        this->them = them;
    }
    void set_supervisor(const std::string& supervisor)
    {
        this->supervisor = supervisor;
    }
    //      Construcrtors
    Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& them, const std::string& supervisor) :Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
    {
        set_them(them);
        set_supervisor(supervisor);
        cout << "GConstructor:\t" << this << endl;
    }
    ~Graduate()
    {
        cout << "GDestructor:\t" << this << endl;
    }
    //      Methods
    void info()const override
    {
        Student::info();
        cout << them << " " << supervisor << endl;
    }
};

std::ostream& operator<<(std::ostream& os, const Human& tst)
{
    tst.info();
    return os;
}


//#define INHERITANCE_CHECK
void main()
{
    setlocale(LC_ALL, "Russian");
#ifdef INHERITANCE_CHECK
    Human human("Vercetty", "Tommy", 30);
    human.info();

    Student student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 70, 97);
    student.info();

    Teacher teacher("White", "Walter", 50, "Chemistry", 25);
    teacher.info();

#endif // INHERITANCE_CHECK
    Human* group[] =
    {
        new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 70, 97),
        new Teacher("White", "Walter", 50, "Chemistry", 25),
        new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 97, 98),
        new Graduate("Winchester","Sam",41,"Jurisprudence","1J",174,100,"Banking activity: financial and legal aspect.","John L. Henessy")
    };

    cout << delimiter << endl;
    for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
    {
      //  group[i]->info();
        cout << *group[i] << endl;
        cout << delimiter << endl;
    }
    
    for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
    {
       delete group[i];
    }
}