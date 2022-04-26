#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr { 2, 13, -4, -6, 6, -9, 1};
	int sum = 0;
	int *max = &arr.at(0);
	int *min = max;
	int ps = 1;
	for (int i = 0; i < arr.size(); i++)
	{
		if (*min > arr.at(i))
			min = &arr.at(i);
		if (*max < arr.at(i))
			max = &arr.at(i);
		if (arr.at(i) < 0)
			sum += arr.at(i);
	}
	if (max < min) {
		int *s = max;
		max = min;
		min = s;
	}
	for (int *i = min; i <= max; i++)
	{
		ps *= *i;
	}
	cout << sum << endl << ps;
	return sum;
}