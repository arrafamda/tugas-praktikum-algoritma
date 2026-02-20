#include <iostream>
using namespace std;

int main() {

    int arr[] = {10, 25, 7, 40, 18};   
    int length = sizeof(arr) / sizeof(arr[0]); 

    int *ptr = arr;

    printf("Elemen array:\n");
    for (int i = 0; i < length; i++) {           
        printf("%d ", *(ptr + i));               
    }
    printf("\n");

    
    int max = *ptr;   
    int min = *ptr;   

    for (int i = 1; i < length; i++) {            
        if (*(ptr + i) > max) {                   
            max = *(ptr + i);                     
        }
        if (*(ptr + i) < min) {                  
            min = *(ptr + i);                   
        }
    }

    printf("Nilai maksimum: %d\n", max);
    printf("Nilai minimum: %d\n", min);

    int sum = 0;        
    float average;     

    for (int i = 0; i < length; i++) {            
        sum += *(ptr + i);                        
    }

    average = (float)sum / length;               

    printf("Jumlah array: %d\n", sum);
    printf("Rata-rata array: %.2f\n", average);

    return 0;  
}
