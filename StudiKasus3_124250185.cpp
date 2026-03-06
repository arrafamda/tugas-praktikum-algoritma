#include <iostream>
using namespace std;

void bubbleSort(string arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int partition(string arr[], int low, int high){
    string pivot = arr[high];
    int i = low - 1;

    for(int j=low;j<high;j++){
        if(arr[j] > pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(string arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(){
    int n;
    cout<<"Masukkan jumlah mahasiswa: ";
    cin>>n;

    string nama[n];

    cout<<"Masukkan nama mahasiswa:\n";
    for(int i=0;i<n;i++){
        cin>>nama[i];
    }

    string namaQuick[n];
    for(int i=0;i<n;i++){
        namaQuick[i] = nama[i];
    }

    bubbleSort(nama,n);

    cout<<"\nUrutan Ascending (Bubble Sort):\n";
    for(int i=0;i<n;i++){
        cout<<nama[i]<<endl;
    }

    quickSort(namaQuick,0,n-1);

    cout<<"\nUrutan Descending (Quick Sort):\n";
    for(int i=0;i<n;i++){
        cout<<namaQuick[i]<<endl;
    }

    return 0;
}
