#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <sstream>

static int cu = 0;
static int cu2 = 0;

class Person
{
public:
    Person(){};
    virtual ~Person(){};
    virtual void getdata()  = 0;
    virtual void putdata()  = 0;
    int age;
    string name;    
};

class Professor: public Person
{
public:
    Professor();
    virtual ~Professor(){cu--;};
    Professor(const Professor&);
    virtual void getdata() override;
    virtual void putdata() override;
    int publications;
    int cnt = 0;
};

Professor::Professor()
{
    cu++; 
    cnt = cu;
}

Professor::Professor(const Professor&)
{
    cu++;
    cnt = cu;
}

void Professor::getdata()
{
    cin >> name >> age >> publications;
}

void Professor::putdata()
{
    cout << name << " " << age << " "<< publications << " " << cnt << endl;
}

class Student: public Person
{
public:
    Student();
    Student(const Student&);
    virtual ~Student(){cu2--;};
    virtual void getdata() override;
    virtual void putdata() override;
    int cnt = 0;
    int jaca = 0;
};


Student::Student()
{
    cu2++;
    jaca = cu2;
}

Student::Student(const Student&)
{
    cu2++;
    jaca = cu2;
}

void Student::getdata()
{
    cnt = 0;
    cin >> name >> age;
    for( int i = 0 ; i < 6; i++ )
    {
       int tmp = 0;
       cin >> tmp ;
       cnt = cnt + tmp;
    }
}

void Student::putdata()
{
    
    cout << name << " " << age << " " << cnt << " " << jaca << endl;

}


int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

