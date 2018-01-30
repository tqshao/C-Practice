#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class func{
public:
	func(double x_zero, double increment):x(x_zero), incr(increment){};
	double operator()(){
		x += incr;
		return x*x;
		 }
private:
	double x, incr;
};

double integrate(func f, int n){
	vector<double> fx(n);
	generate(fx.begin(),fx.end(),f);
	return accumulate(fx.begin(),fx.end(),0.0)/n;
}

int main(){
	const int n = 1000;
	func f(0.0, static_cast<double>(1)/n);
	cout<< integrate(f, n) << endl;
	return 0;
}
