#include <vector>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::vector;


int binarySearch(vector<int> numlist, int start, int end, int target){
    /* Binary Search example
    */
    
    int mid = (start+end)/2;
    
    if (numlist[mid] == target){
        return mid;
    }
    if (numlist[mid] < target){
        return binarySearch(numlist, mid, end, target);
    }
    if (numlist[mid] > target){
        return binarySearch(numlist, start, mid, target);
    }
    return -1;
}


int main(){
    // initializing array
    vector<int> numlist = {1, 4, 8, 20, 55, 100, 500};
    string intro = "found your target number: ";
    // setting the target
    int target = 8;
    
    // getting the index that correalates with target
    int mid = binarySearch(numlist, 0, numlist.size(), target);

    // printing out out solution
    cout << intro << numlist[mid] << "\n";
}

