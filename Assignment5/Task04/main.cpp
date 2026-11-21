#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
class Bill{protected:string patient;public:Bill(string p):patient(p){}virtual~Bill()=default;virtual double total()const=0;virtual string type()const=0;};
class OP:public Bill{double c,t;public:OP(string p,double x,double y):Bill(p),c(x),t(y){}double total()const override{return c+t;}string type()const override{return "OP";}};
class IP:public Bill{int days;double rate,proc;public:IP(string p,int d,double r,double x):Bill(p),days(d),rate(r),proc(x){}double total()const override{return days*rate+proc;}string type()const override{return "IP";}};
class DayCare:public Bill{double p;public:DayCare(string n,double x):Bill(n),p(x){}double total()const override{return p;}string type()const override{return "DayCare";}};
class Emergency:public Bill{double b,r;int h;public:Emergency(string n,double x,double y,int z):Bill(n),b(x),r(y),h(z){}double total()const override{return b+r*h;}string type()const override{return "Emergency";}};
class Maternity:public Bill{double p,e;public:Maternity(string n,double x,double y):Bill(n),p(x),e(y){}double total()const override{return p+e;}string type()const override{return "Maternity";}};
class Payer{public:virtual~Payer()=default;virtual double cover(const Bill&)const=0;};
class SelfPay:public Payer{public:double cover(const Bill&b)const override{return b.total();}};
class Insurance:public Payer{double limit,co;public:Insurance(double l,double c):limit(l),co(c){}double cover(const Bill&b)const override{return min(limit,b.total()*(1-co/100));}};
class Corporate:public Payer{double discount;public:Corporate(double d):discount(d){}double cover(const Bill&b)const override{return b.total()*(1-discount/100);}};
int main(){vector<unique_ptr<Bill>>b;b.push_back(make_unique<OP>("Ravi",500,1200));b.push_back(make_unique<IP>("Meena",3,2500,40000));b.push_back(make_unique<DayCare>("Asha",25000));b.push_back(make_unique<Emergency>("John",2000,500,3));b.push_back(make_unique<Maternity>("Sara",60000,5000));vector<unique_ptr<Payer>>p;p.push_back(make_unique<SelfPay>());p.push_back(make_unique<Insurance>(50000,20));p.push_back(make_unique<Corporate>(15));double sum=0;for(auto&x:b){sum+=x->total();cout<<x->type()<<' '<<x->total()<<" | ";for(auto&y:p)cout<<y->cover(*x)<<' ';cout<<'\n';}cout<<"All bills total "<<sum<<'\n';}