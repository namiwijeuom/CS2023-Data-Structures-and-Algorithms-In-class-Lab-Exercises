#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int max = root;  //Initializing largest value as the root
   
   int l_node = 2*root + 1;  //Left child node
   int r_node = 2*root + 2;  //Right child node

   //If left node is larger than the root
   if (l_node < n && arr[l_node] > arr[max]){
        max = l_node;
   }

   //If right node is larger than largest so far
   if (r_node < n && arr[r_node] > arr[max]){
        max = r_node;
   }

   //If largest is not the root
   if (max != root) {

        swap(arr[root], arr[max]);

        //Recursively heapify
        heapify(arr, n, max);
    }

}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
   }

    //Extracting elements from the heap
    for (int j=n-1; j>=0; j--) {
        
        //Moving the current root to the end
        swap(arr[0], arr[j]);

        //Call max heapify for the shorten heap
        heapify(arr, j, 0);
    }


   //extracting elements from heap one by one
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program

int main()
{
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}