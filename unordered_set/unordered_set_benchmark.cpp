#include <unordered_set>
#include <set>

#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <vector>

using namespace std;

int main (int argc, char ** argv)
{
	if (argc != 3) {
		cerr << "Usage: " << argv[0]
				 << " [set size] [search target number]" << endl;
		return -1;
	}
	
	size_t n = stoull(argv[1]);
	size_t ntargets = stoull(argv[2]);

	vector<int> data;
	vector<int> search_data;

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine gen(seed);
	uniform_int_distribution<int> dist(1, n);
	
	for (int i = 0; i < n; ++i)
		data.push_back(dist(gen));
	for (int i = 0; i < ntargets; ++i)
		search_data.push_back(dist(gen));
	
	unordered_set<int> uiset;
	set<int> iset;

	chrono::time_point<chrono::system_clock> start, end;
	chrono::duration<double> elapsed;

	// benchmark unordered_set construction time
	start = chrono::system_clock::now();
	for (int v : data)
		uiset.insert(v);
	end = chrono::system_clock::now();
	elapsed = end - start;
	cout << "Construction unordered_set<int> takes: "
			 << elapsed.count() << "s" << endl;
	// benchmark set construction time
	start = chrono::system_clock::now();
	for (int v : data)
		iset.insert(v);
	end = chrono::system_clock::now();
	elapsed = end - start;
	cout << "Construction set<int> takes: "
			 << elapsed.count() << "s" << endl;
	// benchmark unordered_set search time
	start = chrono::system_clock::now();
	for (int i : search_data) {
		auto found = uiset.find(i);
		// avoid to be optimized out
		if (found != uiset.end())
			++found;
	}
	end = chrono::system_clock::now();
	elapsed = end - start;
	cout << "Search in unordered_set<int> takes: "
			 << elapsed.count() << "s" << endl;
	// benchmark unordered_set search time
	start = chrono::system_clock::now();
	for (int i : search_data) {
		auto found = iset.find(i);
		// avoid to be optimized out
		if (found != iset.end())
			++found;
	}
	end = chrono::system_clock::now();
	elapsed = end - start;
	cout << "Search in set<int> takes: "
			 << elapsed.count() << "s" << endl;
	return 0;
}














