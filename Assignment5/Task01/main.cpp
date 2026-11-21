#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
class Bill{protected:string patient;public:Bill(string p):patient(p){}virtual~Bill()=default;virtual double total()const=0;virtual string type()const=0;void print()const{cout<<type()<<' '<<patient<<": "<<total()<<'\n';}};
class OutPatient:public Bill{double c,t;public:OutPatient(string p,double x,double y):Bill(p),c(x),t(y){}double total()const override{return c+t;}string type()const override{return "OP";}};
class InPatient:public Bill{int days;double rate,procedure,med;public:InPatient(string p,int d,double r,double x,double m):Bill(p),days(d),rate(r),procedure(x),med(m){}double total()const override{return days*rate+procedure+med;}string type()const override{return "IP";}};
class DayCare:public Bill{double package;public:DayCare(string p,double x):Bill(p),package(x){}double total()const override{return package;}string type()const override{return "DayCare";}};
class Emergency:public Bill{double base,perHour;int hours;public:Emergency(string p,double b,double r,int h):Bill(p),base(b),perHour(r),hours(h){}double total()const override{return base+perHour*hours;}string type()const override{return "Emergency";}};
class Payer{public:virtual~Payer()=default;virtual double amountCovered(const Bill&)const=0;};
class SelfPay:public Payer{public:double amountCovered(const Bill&b)const override{return b.total();}};
class Insurance:public Payer{double limit,copay;public:Insurance(double l,double c):limit(l),copay(c){}double amountCovered(const Bill&b)const override{return min(limit,b.total()*(1-copay/100));}};
class GovernmentScheme:public Payer{double rate;public:GovernmentScheme(double r):rate(r){}double amountCovered(const Bill&b)const override{return min(rate,b.total());}};
int main(){vector<unique_ptr<Bill>>b;b.push_back(make_unique<OutPatient>("Ravi",500,1200));b.push_back(make_unique<InPatient>("Meena",3,2500,40000,3000));b.push_back(make_unique<DayCare>("Asha",25000));b.push_back(make_unique<Emergency>("John",2000,500,3));vector<unique_ptr<Payer>>p;p.push_back(make_unique<SelfPay>());p.push_back(make_unique<Insurance>(50000,20));p.push_back(make_unique<GovernmentScheme>(15000));double sum=0;for(auto&x:b){x->print();sum+=x->total();for(auto&y:p)cout<<"Covered "<<y->amountCovered(*x)<<'\n';}cout<<"Day total "<<sum<<'\n';}