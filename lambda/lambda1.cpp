#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

int main (int argc, char ** argv)
{
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine gen(seed);
	size_t n = 50000;
	uniform_int_distribution<int> dist(1, n);
	vector<int> data;

	for (int i = 0; i < n; ++i)
		data.push_back(dist(gen));

	auto result = count_if(data.begin(), data.end(), [](int i) { return (i % 2 == 0); });

	cout << result << endl;
	
	return 0;
}
