#pragma once

#include <vector>
#include <cstdint>


class subsum {
public:
	subsum() {
		left = right = 0;
		sum = INTMAX_MIN;
	}

	subsum(int l, int r, int s) : left(l), right(r), sum(s) {}

	~subsum() {};

	subsum& operator=(const subsum& other) {
		left = other.left;
		right = other.right;
		sum = other.sum;
		return *this;
	}
	
	void reset_sum() {
		sum = INTMAX_MIN;
	}
	void clear() {
		left = right = 0;
		sum = INTMAX_MIN;
	}

	int left, right;
	int sum;
};

// find max crossing 
subsum find_max_crossing_subarray(const std::vector<int>&, int, int, int);

subsum find_maximum_subarray(const std::vector<int>&, int, int);


subsum exhausion_max_maximum(const std::vector<int> A, int low, int high);

subsum nonrecursive_max_subarray(const std::vector<int>&, int, int);