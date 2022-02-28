#include <iostream>
#include <list>
#include <cstring>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;
#define nl "\n"

//colors(works with linux terminal)
#define FT_YEL "\x1B[0;33m"
#define FT_B_RED "\x1B[1;31m"
#define FT_B_GRN "\x1B[1;32m"
#define FT_B_YEL "\x1B[1;33m"
#define FT_B_WHT "\x1B[1;37m"
#define FT_NRM "\x1B[0m"

//clearing the screen
#define clearscreen()               \
    {                               \
        cout << "\033[2J\033[1;1H"; \
    }

class person
{
protected:
    string name;
    string roll_no;

public:
    person(string name, string roll_no)
    {
        this->name = name;
        this->roll_no = roll_no;
    }
};

class student : virtual protected person
{
protected:
    string course1;
    string course2;
    string course3;

public:
    student(string name, string roll_no, string course1, string course2, string course3) : person{name, roll_no}
    {
        this->course1 = course1;
        this->course2 = course2;
        this->course3 = course3;
    }
  
};

class research_student : virtual protected person
{
protected:
    string course1;
    string research_area;

public:
    research_student(string name, string roll_no, string course1, string research_area) : person{name, roll_no}
    {
        this->course1 = course1;
        this->research_area = research_area;
    }
   
};

class TA : protected student, protected research_student
{
protected:
    string course_assigned;
    string role;

public:
    //constructor if research student
    TA(string name, string roll_no, string course1, string research_area, string course_assigned, string role) : research_student{name, roll_no, course1, research_area}, person{name, roll_no}, student(name, roll_no, "", "", "")
    {
        this->course_assigned = course_assigned;
        this->role = role;
    }
    //constructor if student
    TA(string name, string roll_no, string course1, string course2, string course3, string course_assigned, string role) : student{name, roll_no, course1, course2, course3}, person{name, roll_no}, research_student{name, roll_no, "", ""}
    {
        this->course_assigned = course_assigned;
        this->role = role;
    }

    //checks whether roll no matches
    bool is_matches(string roll_no)
    {
        
        if (this->roll_no == roll_no)
        {
            return true;
        }
        return false;
    }   
};

//returns position of TA in the list
int getPos(list<TA> &l1, string roll_no)
{
    //returns position of TA
}
int main()
{
    list<TA> TA_list;
    int choice;
    char ch;
    string roll_no, name, course[3], research_area, course_assigned, role;
    while (1)
    {
        //printing menu
        int choice2 = 3;
        cout << "\n\tMENU\n";
        cout << "1. Set TA Details\n";
        cout << "2. Display\n";
        cout << "3. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        clearscreen();
        switch (choice)
        {
        case 1:
        {
            while (1)
            {
                cout << "Set TA Details\n";
                do
                {
                    cout << "Enter the Roll number: ";
                    cin >> roll_no;

                } while (getPos(TA_list, roll_no) != -1);

                while (cin.get() != '\n')
                    ;
                cout << "Enter the name: ";
                std::getline(std::cin, name);

                do
                {
                    cout << "Choose the role: 1)Student 2)Research Student\n";
                    cout << "Your choice: ";
                    cin >> choice2;
                } while (choice2 != 1 && choice2 != 2);

                //if student
                if (choice2 == 1)
                {
                    while (cin.get() != '\n')
                        ;
                    role = "Student";
                    cout << "Enter Course 1: ";
                    std::getline(std::cin, course[0]);
                    cout << "Enter Course 2: ";
                    std::getline(std::cin, course[1]);
                    cout << "Enter Course 3: ";
                    std::getline(std::cin, course[2]);
                    do
                    {
                        cout << "Enter the course assigned: ";
                        std::getline(std::cin, course_assigned);
                    } while (course_assigned == course[0] || course_assigned == course[1] || course_assigned == course[2]);

                    TA t1{name, roll_no, course[0], course[1], course[2], course_assigned, role};
                    TA_list.push_back(t1);
                    clearscreen();
                }
                //if research student
                else
                {
                    while (cin.get() != '\n')
                        ;
                    role = "Research Student";
                    cout << "Enter Course 1: ";
                    std::getline(std::cin, course[0]);
                    cout << "Enter the research area: ";
                    std::getline(std::cin, research_area);
                    do
                    {
                        cout << "Enter the course assigned: ";
                        std::getline(std::cin, course_assigned);
                    } while (course_assigned == course[0]);
                    TA t1{name, roll_no, course[0], research_area, course_assigned, role};
                    TA_list.push_back(t1);
                    clearscreen();

                }
                break;
            }
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            exit(1);
        }
        default:
        {
            cout << FT_B_YEL "Invalid choice.... Try again....\n" FT_NRM;
        }
        }
    }
}