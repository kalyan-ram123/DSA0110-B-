#include <iostream>
#include <string>
using namespace std;
struct Person{string name,phone;int id;Person(string n="",int i=0,string p=""):name(n),phone(p),id(i){}};
struct Student:virtual Person{string programme;double cgpa;Student(string n,int i,string p,string pr,double c):Person(n,i,p),programme(pr),cgpa(c){}};
struct Staff:virtual Person{string department;double salary;Staff(string n,int i,string p,string d,double s):Person(n,i,p),department(d),salary(s){}};
struct TeachingAssistant:Student,Staff{TeachingAssistant(string n,int i,string p,string pr,double c,string d,double s):Person(n,i,p),Student(n,i,p,pr,c),Staff(n,i,p,d,s){}};
struct ResearchScholar:Student{double fellowship;ResearchScholar(string n,int i,string p,string pr,double c,double f):Person(n,i,p),Student(n,i,p,pr,c),fellowship(f){}};
int main(){TeachingAssistant t("Kavya",11,"9876543210","IT",8.7,"CSE",25000);ResearchScholar r("Arun",12,"9876500000","AI",9.1,18000);cout<<t.name<<' '<<t.programme<<' '<<t.department<<' '<<t.salary<<'\n'<<r.name<<' '<<r.programme<<' '<<r.fellowship<<'\n';}