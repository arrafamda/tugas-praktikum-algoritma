#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Produk{
    char nama[50];
    float harga;
    char kategori[30];
    int stok;
};

Produk arr[100];
int n = 0;

void loadFile(){
    FILE *file = fopen("lelele.csv","r");

    if(file == NULL){
        return;
    }

    while (fscanf(file," %[^,],%f,%[^,],%d\n",
        arr[n].nama,
        &arr[n].harga,
        arr[n].kategori,
        &arr[n].stok) != EOF){
        n++;
    }

    fclose(file);
}

void saveFile(){
    FILE *file = fopen("lelele.csv","w");

    for(int i=0;i<n;i++){
        fprintf(file,"%s,%.1f,%s,%d\n",
            arr[i].nama,
            arr[i].harga,
            arr[i].kategori,
            arr[i].stok);
    }

    fclose(file);
}

void tambahProduk(){
    cout<<"Nama produk: ";
    cin.ignore();
    cin.getline(arr[n].nama,50);

    cout<<"Harga: ";
    cin>>arr[n].harga;

    do{
        cout<<"Kategori (makanan/minuman): ";
        cin>>arr[n].kategori;

        if(strcmp(arr[n].kategori,"makanan")!=0 &&
           strcmp(arr[n].kategori,"minuman")!=0){
            cout<<"Kategori harus makanan atau minuman!\n";
        }

    }while(strcmp(arr[n].kategori,"makanan")!=0 &&
           strcmp(arr[n].kategori,"minuman")!=0);

    cout<<"Stok: ";
    cin>>arr[n].stok;

    n++;

    saveFile();

    cout<<"Produk berhasil ditambahkan!\n";
}

void tampil(){
    if(n==0){
        cout<<"Data kosong\n";
        return;
    }

    cout<<"\nDAFTAR PRODUK\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<". "
        <<arr[i].nama<<" | "
        <<arr[i].harga<<" | "
        <<arr[i].kategori<<" | "
        <<arr[i].stok<<endl;
    }
}

void bubbleSort(){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(strcmp(arr[j].nama,arr[j+1].nama)>0){
                Produk temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int partition(int low,int high){
    float pivot = arr[high].harga;
    int i = low-1;

    for(int j=low;j<high;j++){
        if(arr[j].harga > pivot){
            i++;
            Produk temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    Produk temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}

void quickSort(int low,int high){
    if(low<high){
        int pi = partition(low,high);

        quickSort(low,pi-1);
        quickSort(pi+1,high);
    }
}

void sequentialSearch(){
    char cari[50];
    cout<<"Masukkan nama produk: ";
    cin.ignore();
    cin.getline(cari,50);

    for(int i=0;i<n;i++){
        if(strcmp(arr[i].nama,cari)==0){
            cout<<"Produk ditemukan:\n";
            cout<<arr[i].nama<<" | "
            <<arr[i].harga<<" | "
            <<arr[i].kategori<<" | "
            <<arr[i].stok<<endl;
            return;
        }
    }

    cout<<"Produk tidak ditemukan!\n";
}

int binarySearch(char cari[]){
    int l=0;
    int r=n-1;

    while(l<=r){
        int mid=(l+r)/2;

        int cmp = strcmp(arr[mid].nama,cari);

        if(cmp==0)
            return mid;

        if(cmp<0)
            l=mid+1;
        else
            r=mid-1;
    }

    return -1;
}

void binarySearchMenu(){
    bubbleSort();

    char cari[50];

    cout<<"Masukkan nama produk: ";
    cin.ignore();
    cin.getline(cari,50);

    int hasil = binarySearch(cari);

    if(hasil!=-1){
        cout<<"Produk ditemukan:\n";
        cout<<arr[hasil].nama<<" | "
        <<arr[hasil].harga<<" | "
        <<arr[hasil].kategori<<" | "
        <<arr[hasil].stok<<endl;
    }
    else{
        cout<<"Produk tidak ditemukan!\n";
    }
}

int main(){

    loadFile();

    int pilih;

    do{
        cout<<"\n=== MENU LE LELE ===\n";
        cout<<"1. Tambah Produk\n";
        cout<<"2. Tampilkan Produk\n";
        cout<<"3. Sort Nama (Bubble Sort)\n";
        cout<<"4. Sort Harga (Quick Sort)\n";
        cout<<"5. Cari Produk Sequential\n";
        cout<<"6. Cari Produk Binary\n";
        cout<<"0. Keluar\n";
        cout<<"Pilih: ";
        cin>>pilih;

        switch(pilih){

            case 1:
                tambahProduk();
                break;

            case 2:
                tampil();
                break;

            case 3:
                bubbleSort();
                tampil();
                break;

            case 4:
                quickSort(0,n-1);
                tampil();
                break;

            case 5:
                sequentialSearch();
                break;

            case 6:
                binarySearchMenu();
                break;

        }

    }while(pilih!=0);

}
