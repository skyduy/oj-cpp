#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void print_vector(vector<auto> const &arr);

int partition(vector<auto> &arr, int start, int end){
    auto element = arr[end];
    auto tmp = element;
    int i = start - 1;
    for (int j=start; j<=end-1; j++){
        if (arr[j] <= element){
            i += 1;
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
        }
    }
    i += 1;
    tmp = arr[end];
    arr[end] = arr[i];
    arr[i] = tmp;
    return i;
}

void quick_sort(vector<auto> &arr, int start, int end){
    if(start < end){
        int mid = partition(arr, start, end);
        quick_sort(arr, start, mid-1);
        quick_sort(arr, mid, end);
    }
}

int main(){
    string line;
    cout << "Enter a sequence " << endl;
    getline(cin, line);
    istringstream iss(line);

    int input;
    vector<int> arr;
    while(iss >> input){
        arr.push_back(input);
    }

    quick_sort(arr, 0, arr.size()-1);
    cout << "After sorted:" << endl;
    print_vector(arr);
}

void print_vector(vector<auto> const & arr){
    for(auto i:arr){
        cout << i << " ";
    }
    cout << endl;
}