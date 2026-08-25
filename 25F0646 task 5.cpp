#include<iostream>
using namespace std;

template<typename T>
class ArrayStatistics { 
private:
    T* array;
    int size;
public:
    ArrayStatistics(int s) {
        size = s;
        array = new T[size];
        cout << " enter the values of the array" << endl;
        for (int i = 0; i < size; i++) {
            cin >> *(array + i);
        }
    }
    void display() {
        cout << " the values of the array are" << endl;
        for (int i = 0; i < size; i++) {
            cout << *(array + i) << " ";
        }
        cout << endl;
    }
    T minimum() {
        T min = *(array + 0);
        for (int i = 0; i < size; i++) {
            if (*(array + i) < min) {
                min = *(array + i);
            }
        }
        return min;
    }
    T maximum() {
        T max = *(array + 0);
        for (int i = 0; i < size; i++) {
            if (*(array + i) > max) {
                max = *(array + i);
            }
        }
        return max;
    }
    double average() {
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += *(array + i);
        }
        double avg = sum / size;
        return avg;
    }
    int count(T value) {
        int cnt = 0;
        for (int i = 0; i < size; i++) {
            if (*(array + i) == value) {
                cnt++;
            }
        }
        return cnt;
    }
    ~ArrayStatistics() {
        delete[] array;
    }
};

int main() {
    ArrayStatistics<int> intStats(5);
    ArrayStatistics<double> doubleStats(7);
    intStats.display();
    cout << "Minimum: " << intStats.minimum() << endl;
    cout << "Maximum: " << intStats.maximum() << endl;
    cout << "average: " << intStats.average() << endl;
    cout << "count of 5 is :" << intStats.count(5) << endl; 


    doubleStats.display();
    cout << "Minimum: " << doubleStats.minimum() << endl;
    cout << "Maximum: " << doubleStats.maximum() << endl;
    cout << "average: " << doubleStats.average() << endl;
    cout << "count of 5 is :" << doubleStats.count(5) << endl;


    return 0;
} 