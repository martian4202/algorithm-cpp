#include <vector>

#include "divide.h"
#include <cstdint>

static subsum find_max_crossing_subarray(const std::vector<int>& A, int low, int mid, int high)
{
	subsum s;

	int sum = 0;

	int left_sum = s.sum;
	for (int i = mid; i >= low; i--)
	{
		sum += A[i];
		if (sum > left_sum)
		{
			s.left = i;
			left_sum = sum;
		}
	}

	sum = 0;
	
	int right_sum = s.sum;
	for (int i = mid + 1; i <= high; i++)
	{
		sum += A[i];
		if (sum > right_sum)
		{
			s.right = i;
			right_sum = sum;
		}
	}

	s.sum = left_sum + right_sum;

	return s;
	// TODO: 在此处插入 return 语句
}

subsum find_maximum_subarray(const std::vector<int>& A, int low, int high)
{
	if (low >= high) {
		return subsum(low, high, A[low]);
	}

	int mid = (low + high) / 2;
	subsum ls = find_maximum_subarray(A, low, mid);
	subsum ms = find_max_crossing_subarray(A, low, mid, high);
	subsum rs = find_maximum_subarray(A, mid + 1, high);
	
	if (ls.sum >= rs.sum && ls.sum >= ms.sum)
		return ls;
	if (rs.sum >= ls.sum && rs.sum >= ms.sum)
		return rs;

	return ms;
}

subsum exhausion_max_maximum(const std::vector<int> A, int low, int high) {
	subsum s;
	int sum = s.sum;

	for (int i = low; i < high; i++)
	{
		int base = A[i];
		for (int j = i + 1; j <= high; j++)
		{
			if (A[j] - base > sum) {
				sum = A[j] - base;
				s.left = i;
				s.right = j;
			}
		}
	}
	s.sum = sum;
	return s;
}

subsum nonrecursive_max_subarray(const std::vector<int>& A, int low, int high)
{
	subsum oldsub(0, 0, A[low]);
	subsum newsub;

	for (int i = low + 1; i <= high; i++)
	{
		newsub.clear();
		if (A[i] <= 0)
			continue;

		int tmp = A[i];
		for (int j = i-1; j > oldsub.right; j--) {
			tmp += A[j];
			if (tmp < 0)
				break;
			if (tmp >= newsub.sum) {
				newsub.left = j;
				newsub.right = i;
				newsub.sum = tmp;
			}
		}

		if (newsub.left == oldsub.right + 1) {
			oldsub.right = newsub.right;
			oldsub.sum += newsub.sum;
		}
		else if (newsub.sum > oldsub.sum) {
			oldsub = newsub;
		}
	}
	return oldsub;
}