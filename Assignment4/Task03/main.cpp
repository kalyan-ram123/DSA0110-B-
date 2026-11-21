#include <iostream>
#include <string>
using namespace std;
struct Address{string city;int pin;Address(string c,int p):city(c),pin(p){cout<<"Address constructed\n";}~Address(){cout<<"Address destroyed\n";}string str()const{return city+"-"+to_string(pin);}};
struct Person{string name;int age;Address home;Person(string n,int a,string c,int p):name(n),age(a),home(c,p){cout<<"Person constructed\n";}virtual ~Person(){cout<<"Person destroyed\n";}};
struct Student:Person{long long reg;Student(string n,int a,long long r,string c,int p):Person(n,a,c,p),reg(r){cout<<"Student constructed\n";}~Student(){cout<<"Student destroyed\n";}void print()const{cout<<reg<<' '<<name<<" ("<<age<<") "<<home.str()<<'\n';}};
struct Staff:Person{Staff(string n,int a,string c,int p):Person(n,a,c,p){cout<<"Staff constructed\n";}~Staff(){cout<<"Staff destroyed\n";}};
struct TA:Student{TA(string n,int a,long long r,string c,int p):Student(n,a,r,c,p){cout<<"TA constructed\n";}~TA(){cout<<"TA destroyed\n";}};
int main(){{Student s("Kavya",19,192311001,"Salem",636001);s.print();}{Staff s("Ravi",35,"Chennai",600001);}{TA t("Mira",22,192311002,"Madurai",625001);}}