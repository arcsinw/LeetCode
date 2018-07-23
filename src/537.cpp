#include <string>
#include <regex>
#include <iostream>
#include <iterator>
#include <sstream>
using namespace std;

string complexNumberMultiply(string a, string b)
{
    int a_real, a_imaginary = 0;
    int b_real, b_imaginary = 0;
    char buff;

    stringstream ss_a(a);
    stringstream ss_b(b);
    ss_a >> a_real >> buff >> a_imaginary;
    ss_b >> b_real >> buff >> b_imaginary;

    int t1 = (a_real - a_imaginary) * (b_real + b_imaginary);
    int t2 = (a_real * b_imaginary);
    int t3 = (a_imaginary * b_real);

    return to_string(t1 - t2 + t3) + "+" + to_string(t2 + t3) + "i";
}

int main()
{
    string a = "-1+2i";
    string b = "1+-1i";
    cout << complexNumberMultiply(a, b);
}
