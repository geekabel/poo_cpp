#include <iostream>

using std::string;

//Creation d'une classe abstraitre mot-clé :virtual
class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee
{

private:
    string Compagny;
    int Age;

protected:
    string Name;

public:
    void setName(string name)
    {
        Name = name;
    }
    string getName()
    {
        return Name;
    }

    void setCompagny(string compagny)
    {
        Compagny = compagny;
    }
    string getCompagny()
    {
        return Compagny;
    }

    void setAge(int age)
    {
        Age = age;
    }
    int getAge()
    {
        return Age;
    }

    void introduceYourself()
    {
        std::cout << "Name -" << Name << std::endl;
        std::cout << "Company -" << Compagny << std::endl;
        std::cout << "Age -" << Age << std::endl;
    }

    Employee(string name, string compagny, int age)
    {
        Name = name;
        Compagny = compagny;
        Age = age;
    }

    void AskForPromotion()
    {
        if (Age > 30)
            std::cout << Name << " got promoted!" << std::endl;
        else
            std::cout << Name << ", sorry NO promotion for you!" << std::endl;
    }

    virtual void Work()
    {
        std::cout << Name << " is checking email, task backlog, perfoming tasks... " << std::endl;
    }
};

class Developper : public Employee
{
public:
    string FavProgrammingLanguage;
    Developper(string name, string compagny, int age, string favProgrammingLanguage)
        : Employee(name, compagny, age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }
    void FixBug()
    {
        std::cout << getName() << " fixed bug using " << FavProgrammingLanguage << std::endl;
    }
    void Work()
    {
        std::cout << Name << " is writting " << FavProgrammingLanguage << std::endl;
    }
};

class Teacher : public Employee
{
public:
    string Subject;
    Teacher(string name, string compagny, int age, string subject)
        : Employee(name, compagny, age)
    {
        Subject = subject;
    }
    void PreparLesson()
    {
        std::cout << getName() << " is preparing " << Subject << " lesson " << std::endl;
    }
    void Work()
    {
        std::cout << Name << " is theaching " << Subject << std::endl;
    }
};
int main()
{
    /*Employee employee1 = Employee("Jim", "CIC", 25);
    Employee employee2 = Employee("Toto", "NAVIS", 35);*/

    /*employee1.AskForPromotion();
    employee2.AskForPromotion();*/
    Developper d = Developper("Jim", "CIC", 25, "Java");
    Teacher t = Teacher("Jack", "CIC", 35, "History");

    Employee *e1 = &d;
    Employee *e2 = &t;
    e1->Work();
    e2->Work();
    /* employee1.setAge(39);
    std::cout << employee1.getName() << " is " << employee1.getAge() << " years old " << std::endl;*/
}