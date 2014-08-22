#include <iostream>
#include <vector>

using namespace std;

vector<int> init(int n)
{
	vector<int> v;
	for (int i = 0; i < n; ++i)
		v.push_back(i);
	return v;
}

int main (int argc, char ** argv)
{
	auto data = init(100);
	cout << data.size() << endl;
	return 0;
}
