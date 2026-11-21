#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
class Staff{string name;int id;double basic;protected:double base()const{return basic*1.42;}public:Staff(string n,int i,double b):name(n),id(i),basic(b){}virtual ~Staff()=default;virtual double pay()const=0;void print()const{cout<<name<<" ("<<id<<"): "<<pay()<<'\n';}};
class Professor:public Staff{double research;public:Professor(string n,int i,double b,double r):Staff(n,i,b),research(r){}double pay()const override{return base()+research;}};
class LabAssistant:public Staff{public:using Staff::Staff;double pay()const override{return base();}};
class GuestFaculty:public Staff{double hours,rate;public:GuestFaculty(string n,int i,double h,double r):Staff(n,i,0),hours(h),rate(r){}double pay()const override{return hours*rate;}};
int main(){vector<unique_ptr<Staff>> v;v.push_back(make_unique<Professor>("Asha",101,50000,8000));v.push_back(make_unique<LabAssistant>("Ravi",102,30000));v.push_back(make_unique<GuestFaculty>("Mira",103,20,1000));for(auto&x:v)x->print();}