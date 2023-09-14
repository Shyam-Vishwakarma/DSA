#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr, int key) {
    int n=arr.size();
    int low=0, high=n-1, mid, ans=-1;
    while(low<=high) {
        mid=low+(high-low)/2;
        if(arr[mid]==key) {
            ans = mid;
            break;
        } else if(arr[mid]<key) {
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    return ans;
}
int main() {
    int n, key;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter elements : " << endl;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "Enter key to search : ";
    cin >> key;
    int result=binarySearch(arr, key);
    if(result!=-1) cout << key <<" is at index " << result;
    else cout << key <<" does not exist in array";
}