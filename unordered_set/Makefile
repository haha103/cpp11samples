CXX = clang++
CXX_FLAGS = -Wall -O3 -std=c++11

EXE = unordered_set_benchmark

$(EXE): unordered_set_benchmark.cpp
	$(CXX) $(CXX_FLAGS) $< -o $@

clean:
	rm -rf $(EXE)
