#include <iostream>
#include <new>
#include <stdexcept>
#include <string>
#include <utility>
using namespace std;
class ClaimError:public runtime_error{public:using runtime_error::runtime_error;};
struct Guard{string label;Guard(string s):label(s){}~Guard(){cout<<"destroy "<<label<<'\n';}};
double approve(double billed,double cover){if(billed<0||cover<0)throw invalid_argument("negative amount");if(billed>cover)throw ClaimError("exceeds cover");return billed;}
double settle(double b,double c){try{return approve(b,c);}catch(const ClaimError&e){cout<<"audit: "<<e.what()<<'\n';throw;}}
int main(){for(auto x:{pair<double,double>{40000,50000},{60000,50000},{-1,50000}}){try{Guard g("claim");cout<<"approved "<<settle(x.first,x.second)<<'\n';}catch(const ClaimError&e){cout<<"claim rejected: "<<e.what()<<'\n';}catch(const exception&e){cout<<"error: "<<e.what()<<'\n';}}
try{size_t n=static_cast<size_t>(-1)/sizeof(int);int*p=new int[n];delete[]p;}catch(const bad_alloc&){cout<<"allocation failed safely\n";}catch(...){cout<<"top-level catch-all handled error\n";}}