/***************************************
** Program: math.cpp
** Author: Joseph Andrews
** Date: 1/14/17
** Description: Performs math operations using cmath library
** Input: None
** Output: Text to terminal
***************************************/

#include <iostream>
#include <cmath> 

using namespace std;

int main() {
	//declare some variables for part 1
	float result1 = cos(2.0/3.0);
	float result2 = (2.0 * sin(2.0/3.0));
	float result3 = tan(-3.0/4.0);
	float result4 = log10(55.0);
	float result5 = log(60.0);
	
	//part 1 answers
	cout << "Results for part 1: " << endl;
	cout << endl;
	cout << "cos(2/3) = " << result1 << endl;
	cout << "2sin(2/3) = " << result2 << endl;
	cout << "tan(-3/4) = " << result3 << endl;
	cout << "log10(55) = " << result4 << endl;
	cout << "ln(60) = " << result5 << endl;
	cout << endl;
	
	//variables for part 2
	float b = 2.0;
	float x = 15.0;
	float lnx = log(x);
	float lnb = log(b);
	float result = (lnx/lnb);
	
	//log base 2 of 15
	cout << "Results for part 2: " << endl;
	cout << endl;
	cout << "Steps for log base 2 of 15: " << endl;
	cout << "ln(x) = " << lnx << endl;
	cout << "ln(b) = " << lnb << endl;
	cout << "ln(x)/ln(b) = " << result << endl;
	cout << endl;
	
	//log base 4 of 40
	b = 4.0, x = 40.0, lnx = log(x), lnb = log(b), result = (lnx/lnb);
	cout << "Steps for log base 4 of 40: " << endl;
	cout << endl;
	cout << "ln(x) = " << lnx << endl;
	cout << "ln(b) = " << lnb << endl;
	cout << "ln(x)/ln(b) = " << result << endl;
	cout << endl;
	
	//part 3 when x is 1
	x = 1.0;
	cout << "Results for part 3: " << endl;
	cout << endl;
	cout << "Steps for solving 3^sin(x), when x = 1: " << endl;
	cout << "sin(x) = " << sin(x) << endl;
	cout << "3^(sin(x)) = " << pow(3.0, sin(x)) << endl;
	cout << endl;
	cout << "Steps for solving log base 2 of (x^2 + 1), when x = 1: " << endl;
	cout << "x^2 = " << pow(x, 2.0) << endl;
	cout << "x^2 + 1 = " << (pow(x, 2.0) + 1.0) << endl;
	cout << "ln(x) = " << log((pow(x, 2.0) + 1.0)) << endl;
	cout << "ln(b) = " << log(2.0) << endl;
	cout << "ln(x)/ln(b) = " << (log((pow(x, 2.0) + 1.0)))/(log(2.0)) << endl;
	cout << endl;
	
	//part 3 when x is 10
	x = 10.0;
	cout << "Steps for solving 3^sin(x), when x = 10: " << endl;
	cout << "sin(x) = " << sin(x) << endl;
	cout << "3^(sin(x)) = " << pow(3.0, sin(x)) << endl;
	cout << endl;
	cout << "Steps for solving log base 2 of (x^2 + 1), when x = 10: " << endl;
	cout << "x^2 = " << pow(x, 2.0) << endl;
	cout << "x^2 + 1 = " << (pow(x, 2.0) + 1.0) << endl;
	cout << "ln(x) = " << log((pow(x, 2.0) + 1.0)) << endl;
	cout << "ln(b) = " << log(2.0) << endl;
	cout << "ln(x)/ln(b) = " << (log((pow(x, 2.0) + 1.0)))/(log(2.0)) << endl;
	cout << endl;
	
	//part 3 when x is 100
	x = 100.0;
	cout << "Steps for solving 3^sin(x), when x = 100: " << endl;
	cout << "sin(x) = " << sin(x) << endl;
	cout << "3^(sin(x)) = " << pow(3.0, sin(x)) << endl;
	cout << endl;
	cout << "Steps for solving log base 2 of (x^2 + 1), when x = 100: " << endl;
	cout << "x^2 = " << pow(x, 2.0) << endl;
	cout << "x^2 + 1 = " << (pow(x, 2.0) + 1.0) << endl;
	cout << "ln(x) = " << log((pow(x, 2.0) + 1.0)) << endl;
	cout << "ln(b) = " << log(2.0) << endl;
	cout << "ln(x)/ln(b) = " << (log((pow(x, 2.0) + 1.0)))/(log(2.0)) << endl;
	cout << endl;

	return 0;
}

