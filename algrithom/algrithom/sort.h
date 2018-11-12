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

	Heap(const std::vector<T>& v) : data(v) {}
	~Heap() {};

	T operator[](int i) const {
		return data.at(i);
	}

	virtual void build_heap() = 0;

protected:
	std::vector<T> data;
	int low, high;

	virtual void heap_fy(int) = 0;
};

template<typename T>
class max_heap : public Heap<T> {
public:
	max_heap() {};
	max_heap(const std::vector<T>& v) : Heap<T>(v) {}
	void build_heap() override;

protected:
	void heap_fy(int) override;
};

template<typename T>
class min_heap : public Heap<T> {
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
		std::swap(largest, i);
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
		std::swap(minest, i);
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