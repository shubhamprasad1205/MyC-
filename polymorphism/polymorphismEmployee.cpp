#include<iostream>
using namespace std;

class employee{
    protected:
        int empid;
        string name;
        float basSal;
    public:
       employee(){
            cout <<"\nEmployee default constructor ";
            empid = 0;
            name = "abc";
            basSal = 0.0f;
        }

        employee(int id, string na, float sal){
            cout <<"\nEmployee parameterised constructor ";
            empid = id;
            name = na;
            basSal = sal;
       }
       virtual ~employee(){
           cout << "\nemployee destructor ";
       }

       virtual float calculate_sal(){
           return basSal;
        }
};

class manager : public employee{
protected :
    float bonus;

public:
    manager(){
         cout <<"\nmanager default constructor ";
         bonus = 0.0f;
    }
    manager(int id, string na, float sal, float b) : employee(id, na, sal){
        cout <<"\nmanager parameterised constructor ";
        bonus = b;
    }
    ~manager(){
        cout << "\nmanager destructor ";
    }
     float calculate_sal(){
        return basSal+bonus;
    }
};

class salesManager : public manager{
protected :
    float totalSal;

public:
    salesManager(){
         cout <<"\nSales manager default constructor ";
         totalSal = 0.0f;
    }
    salesManager(int id, string na, float sal, float b, float ts) : manager(id, na, sal,b){
        cout <<"\nSales manager parameterised constructor ";
        totalSal = ts;
    }
    ~salesManager(){
        cout << "\nSales manager destructor ";
    }
    float calculate_sal(){
        float nSal;
        nSal = basSal + bonus +((totalSal * 15)/100);
        return nSal;
    }
};

class clerk : public employee{
protected:
    int overtime;

public:
    clerk(){
        cout<<"\nClerk Default Constructor";
        overtime =0;
    }
    clerk(int id, string na,float sal,int ot) : employee(id,na,sal){
        cout <<"\nClerk Parametrized constructor";
        overtime = ot;
    }
    ~clerk(){
        cout<<"\nClerk Destructor";
     }
     float calculate_sal(){
        int nSal;
        nSal = basSal + overtime * 1200;
        return nSal;
     }
};

class ceo : public employee{
protected:
    float incentive;
public:
    ceo(){
       cout <<"\nceo Default constructor";
       incentive = 0.0f;
    }
    ceo(int id,string na,float sal,float incen) : employee(id,na,sal){
        cout<<"\nCEO parametrized constructor";
        incentive = incen;
    }
    ~ceo(){
        cout<<"\nCEO Destructor called";
    }
    float calculate_sal(){
        return basSal + incentive;
    }

};

int main(){
    //employee em(12,"abc",4000.00f);
    //cout<<"\nSalary :"<<em.calculate_sal();

   // manager m(13,"xyz",67000.0f,3000.0f);
    //cout<<"\nManager Salary :"<<m.calculate_sal();

    //salesManager sm(14,"abc",40000.0f,5000.0f,200.0f);
    //cout<<"\nSales manager Salary :"<<sm.calculate_sal();

    //ceo c(15,"abc",50000.0f,45000.0f);
   // cout<<"\nCEO Salary :"<<c.calculate_sal();

   /*employee *ptr = new clerk(11, "abc", 50000.0f, 5);
   cout << "\nsalary " << ptr ->calculate_sal();
   delete ptr;  */

   manager *ptr = new salesManager(11, "abc", 55000.0f, 2000.0f, 200);
   cout << "\nsalary " << ptr -> calculate_sal();
   delete ptr;

}
