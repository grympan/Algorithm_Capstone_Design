#include <iostream>
using namespace std;

int GreatestCommonDivisor(int a, int b)
{
	int temp1;
	temp1 = a % b;
	if (temp1 == 0)
		return b;
	else
		return GreatestCommonDivisor(b, temp1);
}

int LeastCommonMultiple(int a, int b)
{
	int temp2;
	temp2 = a / GreatestCommonDivisor(a, b);
	return temp2 * b;
}

int main()
{
	int a, b;
	cin >> a;
	cin >> b;

	if (a < 1 || b < 1)
		return 0;

	cout << GreatestCommonDivisor(a, b) << endl;
	cout << LeastCommonMultiple(a, b) << endl;

	return 0;
}