#include "Algo.h"
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	Algo<int> a1( n );
	a1.read();
	int ival;
	cin >> ival;
	a1.find(ival);
	cout << endl;

	cin >> n;
	Algo<double> a2( n );
	a2.read();
	double dval;
	cin >> dval;
	a2.find(dval);
	cout << endl;

	cin >> n;
	Algo<char> a3( n );
	a3.read();
	char cval;
	cin >> cval;
	a3.find(cval);

	//system("pause");
	return 0;
}