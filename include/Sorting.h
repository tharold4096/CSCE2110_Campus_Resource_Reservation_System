#include <vector>
#ifndef SORTING_H
#define SORTING_H

using namespace std;


// merges two of the sorted sections back together 
template <typename T, typename Compare> 
void merge_sections(vector<T>& items, int left, int middle, int right, Compare less) {
	vector<T> temp;

	int i = left;
	int j = middle + 1;

	while (i <= middle && j <= right) {

		if (less(items[i], items[j])) {
			temp.push_back(items[i]);
			i++;
		}
		else {
			temp.push_back(items[j]);
			j++;
		}
	}
	while (i <= middle) {
		temp.push_back(items[i]); 
		i++;
	}
	while (j <= right) {
		temp.push_back(items[j]);
		j++;
	}

	for (int k = 0; k < static_cast<int>(temp.size()); k++) {
		items[left + k] = temp[k];
	}

}
// recursively splits the list into smaller sections 
template <typename T, typename Compare> void merge_sort_recursive(vecotr<T>& items, int left, int right, Compare less) {
	if (left < right) {

		int middle = left + (right - left) / 2;
	
		merge_sort_recursive(items, left, middle, less);
		merge_sort_recursive(items, middle, +1, right, less);
		merge_sections(items, left, middle, right, less);

	}
}

// public merge sort function
template <typename T,  typename Compare>
void merge_sort(vector<T>& items, Compare less) {

	if (items.size() > 1) {
		merge_sort_recursive(items, 0, static_cast<int>(items.size()) - 1, less);
	}
}
