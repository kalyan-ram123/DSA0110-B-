#include <chrono>
#include <iostream>
#include <memory>
#include <variant>
#include <vector>
using namespace std;using Clock=chrono::steady_clock;
struct Base{virtual~Base()=default;virtual double total()const=0;};
struct OP:Base{double a,b;OP(double x,double y):a(x),b(y){}double total()const override{return a+b;}};
struct IP:Base{double d,r,p;IP(double x,double y,double z):d(x),r(y),p(z){}double total()const override{return d*r+p;}};
struct SwitchBill{int type;double a,b,c;double total()const{return type==0?a+b:a*b+c;}};
using V=variant<OP,IP>;
template<class F>long long timeUs(F f){auto s=Clock::now();volatile double x=f();(void)x;return chrono::duration_cast<chrono::microseconds>(Clock::now()-s).count();}
int main(){const int n=1000000;vector<unique_ptr<Base>>v;vector<SwitchBill>s;vector<V>w;v.reserve(n);s.reserve(n);w.reserve(n);for(int i=0;i<n;++i)if(i%2){v.push_back(make_unique<OP>(500,1200));s.push_back({0,500,1200,0});w.emplace_back(OP(500,1200));}else{v.push_back(make_unique<IP>(3,2500,40000));s.push_back({1,3,2500,40000});w.emplace_back(IP(3,2500,40000));}
cout<<"Virtual "<<timeUs([&]{double z=0;for(auto&x:v)z+=x->total();return z;})<<" us\n";
cout<<"Switch "<<timeUs([&]{double z=0;for(auto&x:s)z+=x.total();return z;})<<" us\n";
cout<<"Variant "<<timeUs([&]{double z=0;for(auto&x:w)z+=visit([](auto&q){return q.total();},x);return z;})<<" us\n";
for(int pct:{0,1,50}){auto a=Clock::now();int errors=0;for(int i=0;i<n;++i)if(i%100<pct)++errors;auto b=Clock::now();int thrown=0;for(int i=0;i<n;++i)try{if(i%100<pct)throw 1;}catch(int){++thrown;}auto c=Clock::now();cout<<pct<<"% invalid return "<<chrono::duration_cast<chrono::microseconds>(b-a).count()<<" us exceptions "<<chrono::duration_cast<chrono::microseconds>(c-b).count()<<" us ("<<errors<<','<<thrown<<")\n";}}