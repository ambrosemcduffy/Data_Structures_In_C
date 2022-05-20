#include <vector>
#include <iostream>

using std::vector;
using std::cout;


vector<int> selectionSort(vector<int> &array){
	/*
	   Selection Sort Algorithm O(n^2) runtime
	*/
	
	for (int i=0; i < array.size(); i++){
		for (int j=1; j < array.size(); j++){
			int current_element = array[j];
			int previous_element = array[j-1];
			if (previous_element < current_element){
				continue;
			}
			else{
				array[j] = previous_element;
				array[j-1] = current_element;
			}
			}
	}
	return array;
}


int main(){
	vector<int> array = {50, 100, 2, 4, 2000, 7};
	vector<int> sorted_array = selectionSort(array);

	for (int i=0; i < sorted_array.size(); i++){
		cout << sorted_array[i] << " ";
	}
	cout << "\n";
}
