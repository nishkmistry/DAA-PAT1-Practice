#include<iostream>
#include<iomanip>
using namespace std;
template<typename T>
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void swap(float &a, float &b){
    float temp = a;
    a = b;
    b = temp;
}
int main(){
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    int weights[n], values[n], capacity;
    float r[n], totalValue = 0;
    cout << "Enter the weights of the items: ";
    for(int i=0; i<n; i++){
        cin >> weights[i];
    }
    cout << "Enter the values of the items: ";
    for(int i=0; i<n; i++){
        cin >> values[i];
    }   
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;
    for(int i=0; i<n; i++){
        r[i] = (float)values[i]/weights[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(r[j] < r[j+1]){
                swap(r[j], r[j+1]);
                swap(weights[j], weights[j+1]);
                swap(values[j], values[j+1]);
            }
        }
    }
    cout << "Table after sorting: " << endl;
    cout << "Weights\tValues\tRatio" << endl;
    for(int i=0; i<n; i++){
        cout << weights[i] << "\t" << values[i] << "\t" << r[i] << endl;
    }
    for(int i=0; i<n; i++){
        if(weights[i] <= capacity){
            totalValue += values[i];
            capacity -= weights[i];
        }
        else{
            totalValue += r[i] * capacity;
            break;
        }
    }
    cout << "Total value in the knapsack: " << fixed << setprecision(2) << totalValue << endl;
    return 0;
}