#pragma once

#include <vector>

inline int parent(int i) { return (i - 1) / 2; }
inline int left(int i) { return 2 * i + 1; }
inline int right(int i) { return 2 * (i + 1); }

template <typename T>
class Heap {
public:
	Heap() {
		data = std::vector<T>();
		low = high = 0;
	}

	Heap(std::vector<T>& v) {
		data = v;
		low = 0;
		high = v.size() - 1;
	}
	~Heap() {};

	T& operator[](int i) {
		return data[i];
	}

	virtual void build_heap() = 0;

protected:
	std::vector<T> data;
	int low, high;

	void swap(int i, int j) {
		std::swap(data[i], data[j]);
	}
	virtual void heap_fy(int) = 0;
};

template<typename T>
class max_heap : public Heap<T> {
public:
	max_heap() {};
	max_heap( std::vector<T>& v) : Heap<T>(v) {}
	void build_heap() override;
	void heap_sort();

	std::vector<T>& get_data() { return data; }

protected:
	void heap_fy(int) override;
};

template<typename T>
class min_heap : public Heap<T> {
public:
	min_heap() {};
	min_heap( std::vector<T>& v) : Heap<T>(v) {}
	friend void heap_sort(std::vector<T>&);

	void build_heap() override;
protected:

	void heap_fy(int) override;
};

template<typename T>
void max_heap<T>::heap_fy(int i) {
	int l = left(i);
	int r = right(i);

	int largest = i;

	if (l <= high && data[l] > data[i])
		largest = l;
	if (r <= high && data[r] > data[largest])
		largest = r;

	if (largest != i) {
		swap(largest, i);
		heap_fy(largest);
	}
}

template<typename T>
void min_heap<T>::heap_fy(int i) {
	int l = left(i);
	int r = right(i);

	int minest = i;

	if (l <= high && data[l] < data[i])
		minest = l;
	if (r <= high && data[r] < data[minest])
		minest = r;

	if (minest != i) {
		swap(minest, i);
		heap_fy(minest);
	}
}

template<typename T>
void max_heap<T>::build_heap() {
	low = 0;
	high = data.size() - 1;

	int leaf_begin = high / 2; // 叶子节点的下标从 high / + 1 开始

	for (int i = leaf_begin; i >= 0; i--) {
		heap_fy(i);
	}
}

template<typename T>
void min_heap<T>::build_heap() {
	low = 0;
	high = data.size() - 1;

	int leaf_begin = high / 2;
	for (int i = leaf_begin; i > 0; i--) {
		heap_fy(i);
	}

}
template<typename T>
void max_heap<T>::heap_sort() {
	for (int i = high; i >= 1; i--) {
		swap(0, high);
		high--;
		heap_fy(0);
	}
}

template<typename T>
std::vector<T>& heap_sort(std::vector<T>& v) {
	max_heap<T> mh(v);
	mh.build_heap();

	mh.heap_sort();

	v.swap(mh.get_data());
	return v;
}




template <typename T>
int partition(std::vector<T>& A, int p, int r) {
	T x = A[r];
	int q = p - 1;
	for (int i = p; i <= r - 1; i++) {
		if (A[i] < x) {
			q++;
			std::swap(A[i], A[q]);
		}
	}
	std::swap(A[r], A[q+1]);
	return q + 1;
}

template <typename T>
void quick_sort(std::vector<T>& A, int p, int r) {
	int q;
	if (p < r) {
		q = partition(A, p, r);
		quick_sort(A, p, q - 1);
		quick_sort(A, q + 1, r);
	}
}


std::vector<int> count_sort(std::vector<int>& A, int n) {
	int size = A.size();
	std::vector<int> C(n+1, 0);

	for (int i = 0; i < size; i++) {
		int idx = A[i];
		C[idx]++;
	}

	for (int i = 1; i < n + 1; i++) {
		C[i] += C[i - 1];
	}

	std::vector<int> B(n+1, 0);
	for (int i = 0; i < size; i++) {
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}

	return B;
}