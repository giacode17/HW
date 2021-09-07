#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void dynAlloc(int * &origArrayPtr, int size ) {
	int i = 0;
    srand(time(NULL));
    for (int i = 0; i< size ; i++){
        *(origArrayPtr + i) = rand() % 100 + 1;
    } 
}

void displayArray(int *arrayPtr, int size) {
    
    for(int i = 0; i < size ; i++ ){
        
        if (i % 10 == 9){
            cout << arrayPtr[i] << endl;
        }
        else {
            cout << arrayPtr[i] << setw(4);;
        }
    }
    cout << endl;     

}

void swapElements(int *x, int*y) {
    int temp;
    
    temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort (int *unsortedArray, int *&sortedArray, int size) {
    int i, j, ct = 0;
    bool sorted = false;
    
    for (i = 0; i < size; i++) {
        (*(sortedArray + i) = *(unsortedArray + i));
    }
    
    while (!sorted)
    {
        ct++;
        sorted = true;
        for( int i = 0; i < size-1; i++ )
        {
            if( *(sortedArray + i) > *(sortedArray + (i+1)))
            {
                sorted = false;
                swapElements ((sortedArray + i), (sortedArray + (i+1)));
            }
        }
    } 
    cout << "\nThe number of iteration by bubble sort is " 
         << ct << ". \n";
         
}

void insertionSort(int *unsortedArray, int *&sortedArray, int size) {
    int i, j, ct = 0;
    
    for (i = 0; i < size; i++)
    {
        (*(sortedArray + i) = *(unsortedArray + i));
    }
    
    for ( i = 1; i < size; i++ )
    {
        ct++;
        int t = sortedArray[i];
        for( j = i-1; j >= 0 && sortedArray[j] > t ; j--)
        {
            sortedArray[j+1] = sortedArray[j];
        }
        sortedArray[j+1] = t;    
    }

    cout << "\nThe number of iteration for insertion sort is " 
         << ct << ". \n";
}

int linearSearch (int *arrayPtr, int num, int size) {
    int i = 0; //location = -1;
    bool found = false;
    
    while (!found && i < size)
    {
        if(*(arrayPtr + i) == num)
        {
            found = true;
            return i;
        }
        else{
            i++;
        }
    }
    return -1;
}

int binarySearch(int *arrayPtr, int size, int target) {
    int low = 0, high = size-1, mid;
    bool found = false;
    while (!found && low <= high)
    {
        mid = (low + high)/2;
        if( *(arrayPtr + mid) == target){
            found = true;
        }
        else if (*(arrayPtr +mid) < target ){
            low = mid + 1;// less than mid so except mid 
        }
        else {
            high = mid - 1;
        }
    }
    return found ? mid: -1;
}

int main() {
    
    const int SIZE = 100;
    int *array1Ptr = new int[SIZE];
    int *array2Ptr = new int[SIZE];

    //1.Make array with random number.
    dynAlloc(array1Ptr, SIZE);
    //2.Display unsorted array.
    cout << "Here is the unsorted array"<< endl;
    displayArray(array1Ptr, SIZE);
    
    //3.Disply sorted array by bubble sort.
    bubbleSort (array1Ptr, array2Ptr, SIZE);

    cout << "Here is the sorted array by bubble sort."<< endl;
    displayArray(array2Ptr, SIZE);

    insertionSort (array1Ptr, array2Ptr, SIZE);
    cout << "Here is the sorted array by insertion sort."<< endl;
    displayArray(array2Ptr, SIZE);

    int target;
    cout << "\nEnter the number betwee 1-100 you want to find."<< endl;
    cin >> target;
    
    int linear = linearSearch (array2Ptr, target, SIZE);
    cout << "\nThe number of index is "<< linear << " by the linear search. \n";

    int binary = binarySearch(array2Ptr, SIZE, target);
    cout << "The number of index is "<< binary<< " by the binary search. \n\n";
  
    return 0;
}