#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
class Cart{string item[10];double price[10];int n=0;double discount=0;public:Cart& add(string s,double p){if(n<10&&p>=0){item[n]=s;price[n++]=p;}return *this;}Cart& setDiscount(double d){this->discount=d;return *this;}double total()const{double t=0;for(int i=0;i<n;++i)t+=price[i];return t*(100-discount)/100;}};
int main(){Cart c;c.add("Rice",60).add("Dal",120).setDiscount(10);Cart*p=&c;p->add("Oil",180);Cart&r=c;cout<<fixed<<setprecision(2)<<r.total()<<'\n';Cart direct;direct.add("Milk",50);Cart*d=new Cart;d->add("Bread",40);cout<<direct.total()<<' '<<d->total()<<'\n';delete d;Cart a,b;a.add("A",100);b.add("B",250);Cart*list[]={&a,&b};Cart*best=list[0];for(auto*x:list)if(x->total()>best->total())best=x;cout<<"Highest "<<best->total()<<'\n';}