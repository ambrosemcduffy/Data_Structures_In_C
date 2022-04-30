#include <vector>
#include <iostream>

using std::cout;
using std::vector;


vector<int> concat(vector<int> array1, vector<int> array2){
	/* 
	Concatenate two vectors.
	*/
	for (int i=0; i < array1.size(); i++){
		array2.push_back(array1[i]);
	}
	return array2;
}


vector<int> slice(vector<int> array, int start, int end){
	/*
	Slices a vector at it's start and end points
	*/
	vector<int> new_array = {};
	for (int i=start; i < end; i++){
		new_array.push_back(array[i]);
	}
	return new_array;
}


vector<int> mergeAll(vector<int> left_array, vector<int> right_array){
	/* Sorts Vectors, merges
	*/
	int left_index = 0;
	int right_index = 0;
	vector<int> merged_array = {};

	while ((left_index < left_array.size()) and (right_index < right_array.size())){
		if (left_array[left_index] > right_array[right_index]){
			merged_array.push_back(right_array[right_index]);
			right_index +=1;
		}
		else{
			merged_array.push_back(left_array[left_index]);
			left_index += 1;
		}
	}
	
	vector<int> left_array_ = slice(left_array, left_index, left_array.size());
	vector<int> right_array_ = slice(right_array, right_index, right_array.size());

	merged_array = concat(right_array_, merged_array);
	merged_array = concat(left_array_, merged_array);

	return merged_array;
}


vector<int> mergeSort(vector<int> array){
	/*
	MergeSort Divide and Conquer sorting Algorithm
	*/
	if (array.size() <= 1){
		return array;
	}

	int mid = array.size()/2;
	
	vector<int> right_array = slice(array, mid, array.size());
	vector<int> left_array = slice(array, 0, mid);


	
	vector<int> right_array_ = mergeSort(right_array);
	vector<int> left_array_ = mergeSort(left_array);
	
	return mergeAll(left_array_, right_array_);

}


int main(){
	// Initializing a vector
	vector<int> numlist = {50, 110, 2, 5, 10, 1};
	// Obtaining the sorted vector
	vector<int> sorted_array = mergeSort(numlist);
	
	//printing out the result
	for (int i=0; i<sorted_array.size(); i++){
		cout << sorted_array[i] << " ";
	}
	cout << "\n";
}

