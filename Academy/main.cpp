#include <iostream>
#include<fstream>
#include<string>
using namespace std;

#define delimiter "\n------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age


class Human
{
    static const int HUMAN_TYPE_WIDTH = 10;
    static const int LAST_NAME_WIDTH = 15;
    static const int FIRST_NAME_WIDTH = 15;
    static const int AGE_NAME_WIDTH = 5;

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
   virtual std::ostream& info(std::ostream& os)const
   {
       return os << last_name << " " << first_name << " " << age << " y/o";
   }
   virtual std::ofstream& write(std::ofstream& ofs)const
   {
       //ofs <<strchr(typeid(*this).name(), ' ')+ 1 << ":\t" << last_name << " " << first_name << " " << endl;
       ofs.width(HUMAN_TYPE_WIDTH); ofs << left << std::string(strchr(typeid(*this).name(), ' ') + 1 ) + ":";
       ofs.width(LAST_NAME_WIDTH); ofs << left << last_name;
       ofs.width(FIRST_NAME_WIDTH); ofs<< left << first_name;
       ofs.width(AGE_NAME_WIDTH); ofs  << age;

       return ofs;
   }
 virtual  std::ifstream& read(std::ifstream& ifs)
   {
     ifs >> last_name >> first_name >> age ;
     return ifs;
 }

};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
    return obj.info(os);
}

std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
    return obj.write(ofs);
}
std::ifstream& operator>>(std::ifstream& is, Human& obj)
{
    return obj.read(is);
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance
class Student :public Human
{
    static const int SPECIALITI_WIDTH = 25;
    static const int GROUP_WIDTH = 8;
    static const int RATING_WIDTH = 8;
    static const int ATTENDANCE_WIDTH = 8;
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
    std::ostream& info(std::ostream& os)const override //��������������
    {
        return Human::info(os) << " "
            << speciality << " " << group << " " << rating << " " << attendance;
    }
     std::ofstream& write(std::ofstream& ofs)const override
     {
         Human::write(ofs) ;
         ofs.width(SPECIALITI_WIDTH);    ofs << speciality ;
         ofs.width(GROUP_WIDTH);    ofs << group ;
         ofs.width(RATING_WIDTH);   ofs << rating ;
         ofs.width(ATTENDANCE_WIDTH);    ofs << attendance;
         return ofs;
     }
     std::ifstream& read(std::ifstream& ifs)override
     {
         Human::read(ifs)>>speciality >> group >> rating >> attendance;
         return ifs;
     }



};
class Teacher :public Human
{
    static const int SPECIALITY_WIDTH = 25;
    static const int EXPERIENCE_WIDTH = 5;
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
   std::ostream& info(std::ostream& os)const
   {
       return Human::info(os) << " " << speciality << " " << experience << " years";
   }
   std::ofstream& write(std::ofstream& ofs)const override
   {
       Human::write(ofs) ;
       ofs.width(SPECIALITY_WIDTH);  ofs << speciality;
       ofs.width(EXPERIENCE_WIDTH); ofs << experience;
       return ofs;
   }
   std::ifstream& read(std::ifstream& ifs)override
   {
       Human::read(ifs)>>speciality>>experience;
       return ifs;
   }

};

class Graduate :public Student
{
    static const int THEM_WIDTH = 32;
    static const int SUPERVISOR_WIDTH = 32;
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
    std::ostream& info(std::ostream& os)const override
    {
        return Student::info(os) << them << " " << supervisor;
    }
    std::ofstream& write(std::ofstream& ofs)const override
    {
        Student::info(ofs) ;
        ofs.width(THEM_WIDTH);   ofs << them ;
        ofs.width(SUPERVISOR_WIDTH);    ofs << supervisor;
        return ofs;
    }
    std::ifstream& read(std::ifstream& ifs)override
    {
        Student::read(ifs) ;
        std::getline(ifs, them,'.');
        std::getline(ifs, supervisor);
        return ifs;
    }

};

void Save(Human* group[], const int n, const std::string& filename)
{
    std::ofstream fout(filename);
    for (int i = 0; i < n; i++)
    {
        //  group[i]->info();
        fout << *group[i] << endl;
    }
    fout.close();
    std::string cmd = "notepad " + filename;
    system(cmd.c_str());    // ���������� ���������� ������� std::string � ���� ������� C-string
}

void Print( Human* group[], const int n)
{
    cout << delimiter << endl;
    for (int i = 0; i <n; i++)
    {
        //  group[i]->info();
        cout << *group[i] << endl;
        cout << delimiter << endl;
    }


}

void Clear(Human* group[], const int n)
{
    for (int i = 0; i <n; i++)
    {
        delete group[i];
    }
}
Human* HumanFactory(const std::string& type)
{
    Human* human = nullptr;
    if (type == "Human:")human = new Human("", "", 0);
    if (type == "Student:")human = new Student("", "", 0, "", "", 0, 0);
    if (type == "Teacher:")human = new Teacher("", "", 0, "", 0);
    if (type == "Graduate:")human = new Graduate("", "", 0, "", "", 0, 0,"","");
    return human;
}
Human** Load(const std::string& filename, int& n)
{
    n = 0;
    Human** group = nullptr;
    std::ifstream fin(filename);
    if (fin.is_open())
    {
        n = 0;
        while (!fin.eof())
        {
            std::string buffer;
            std::getline(fin, buffer);
            if (buffer.size() < 16)continue;
            n++;
        }
        cout << "���������� ����� � ����� "<<n<<endl;

        group = new Human * [n] {};
        cout << fin.tellg() << endl;
        fin.clear();
        fin.seekg(0);
        cout << fin.tellg() << endl;
        for (int i = 0; i < n; i++)
        {
            std::string type;
            fin >> type;
            group[i] = HumanFactory(type);
            if (group[i])fin >> *group[i];
            else continue;
        }

        fin.close();
    }
    else
    {
        std::cerr << "Error:File not found" << endl;
    }
    return group;
}


//std::ostream& operator<<(std::ostream& os, const Human& tst)
//{
//    tst.info();
//    return os;
//}
//

//#define INHERITANCE_CHECK
//#define POLYMORPHISM
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
#ifdef POLYMORPHISM
    Human* group[] =
    {
        new Student("Pinkman", "Jessie", 22, "Chemistry", "WW_220", 70, 97),
        new Teacher("White", "Walter", 50, "Chemistry", 25),
        new Student("Vercetty", "Tommy", 30, "Theft", "Vice", 97, 98),
        new Graduate("Winchester","Sam",41,"Jurisprudence","1J",174,100,"Banking activity: financial and legal aspect.","John L. Henessy"),
        new Teacher("Diaz","Ricardo",50,"Weapons distribution",20)
    };

    Print(group, sizeof(group) / sizeof(group[0]));
    Save(group, sizeof(group) / sizeof(group[0]), "Group.txt");
    Clear(group, sizeof(group) / sizeof(group[0]));
#endif // POLYMORPHISM
    int n = 0;
    Human** group = Load("group.txt", n);
    Print(group,n);
    Clear(group,n);

}