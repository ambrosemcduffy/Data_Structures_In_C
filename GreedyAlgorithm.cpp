#include <vector>
#include <iostream>

using std::vector;
void knapSackProblem(vector<vector<int>> &data){
	int capacity = data.size();
	int* minWeight = nullptr;
	int* maxValue = nullptr;
	int currentWeight = 0;
	int currentValue = 0;
	
	for (auto i=0; i < data.size(); i++){
		int weight = data[i][0];
		int value = data[i][1];
		if (minWeight == nullptr){
			minWeight = &weight;
			maxValue = &value;
		}
		
		if (weight + (currentWeight) <= capacity){
			currentWeight = weight+currentWeight;
			currentValue = value + currentWeight;
		}
		if (currentValue > (*maxValue)){
			maxValue = &currentValue;
			minWeight = &currentWeight;
		}
	}
	std::cout << "Maximum Values are:\n";
	std::cout << (*minWeight) << " " << (*maxValue) << "\n";

}

int main(){
	// KnapsackValues
	std::vector<vector<int>> data = {{1,4}, {4, 10}, {3, 20}, {2, 11}};
	knapSackProblem(data);

}