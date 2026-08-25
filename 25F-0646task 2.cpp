#include<iostream>
using namespace std;
int main(){
    const int n =10;
int array[n];
int target;
cout<<" enter the target value"<<endl;
cin>>target;
// taking the input of the array
cout<<" enter the values of the array"<<endl;
for (int i=0;i<n;i++){
    cin>>array[i];

}
for (int i=0;i<n;i++){
    cout<<array[i]<<" ";
}
cout<<endl;
// merge sort
for (int size = 1; size < n; size *= 2) {
    for (int left = 0; left < n - size; left += 2 * size) {
        int mid = left + size;
        int right = left + 2 * size;
        if (right > n) {
            right = n;
        }

        int temp[n];
        int i = left;
        int j = mid;
        int k = left;

        while (i < mid && j < right) {
            if (array[i] <= array[j]) {
                temp[k++] = array[i++];
            } else {
                temp[k++] = array[j++];
            }
        }

        while (i < mid) {
            temp[k++] = array[i++];
        }

        while (j < right) {
            temp[k++] = array[j++];
        }

        for (int x = left; x < right; x++) {
            array[x] = temp[x];
        }
    }
}

    // TWO POINTERS
    bool found = false;

    int start = 0;
    int last = n - 1;

    while (start < last) {

        int sum = array[start] + array[last];

        if (sum == target) {

            cout << "The pair is "
                 << array[start] << " and "
                 << array[last] << endl;

            found = true;
            break;
        }
        else if (sum < target) {
            start++;
        }
        else {
            last--;
        }
    }

    if (!found) {
        cout << "No pair found" << endl;
    }

    return 0;
}
