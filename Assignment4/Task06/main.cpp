#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;
class Vehicle{string reg;bool rented=false;public:Vehicle(string r):reg(r){}virtual~Vehicle()=default;string registration()const{return reg;}void rent(){if(rented)throw runtime_error("Already rented");rented=true;}double giveBack(int late,double rate){if(!rented)throw runtime_error("Not rented");rented=false;return max(0,late)*rate;}virtual double charge(int days)const=0;virtual void print()const=0;};
class Bicycle:public Vehicle{public:using Vehicle::Vehicle;double charge(int d)const override{return 150*d;}void print()const override{cout<<"Bicycle "<<registration()<<'\n';}};
class TwoWheeler:public Vehicle{public:using Vehicle::Vehicle;double charge(int d)const override{return 500*d;}void print()const override{cout<<"TwoWheeler "<<registration()<<'\n';}};
class Car:public Vehicle{int seats;public:Car(string r,int s):Vehicle(r),seats(s){}double charge(int d)const override{return 1800*d;}void print()const override{cout<<"Car "<<registration()<<" seats "<<seats<<'\n';}};
class ElectricCar:public Vehicle{double kwh;public:ElectricCar(string r,double k):Vehicle(r),kwh(k){}double charge(int d)const override{return 12*kwh*d;}void print()const override{cout<<"ElectricCar "<<registration()<<'\n';}};
class ElectricBus:public Vehicle{double kwh;public:ElectricBus(string r,double k):Vehicle(r),kwh(k){}double charge(int d)const override{return 12*kwh*d;}void print()const override{cout<<"ElectricBus "<<registration()<<'\n';}};
int main(){vector<unique_ptr<Vehicle>>f;f.push_back(make_unique<Bicycle>("BI-01"));f.push_back(make_unique<TwoWheeler>("TW-02"));f.push_back(make_unique<Car>("CA-03",5));f.push_back(make_unique<ElectricCar>("EV-04",60));f.push_back(make_unique<ElectricBus>("EB-05",120));for(auto&v:f){v->print();v->rent();cout<<"Charge "<<v->charge(2)<<" late fee "<<v->giveBack(1,100)<<'\n';}}