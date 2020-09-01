#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
void dividir(int a[], int ini, int fin);
void fusionar(int a[],int prin,int pfinal, int med);
void ingresar(int a[]);
void imprimir(int a[]);

int main() {
  int a[11];
  ofstream archivo;
  archivo.open("mergersot.txt",ios::app);
  ingresar(a);
  cout<<endl;
  dividir(a,0,10);
   archivo<<"Arreglo ordenado "<<endl;
for(int i=0;i<11;i++){
  cout<<"|"<<a[i]<<"|";  
  archivo<<"|"<<a[i]<<"|";
}
cout<<endl;
archivo<<endl;

archivo.close();
  return 0;
}

void ingresar(int a[]){
  ofstream archivo;
  archivo.open("mergersot.txt",ios::app);
  for(int i=0;i<11;i++){
    cout<<" Ingresar elemento numero "<<i+1<<" :";
    cin>>a[i];
}
archivo<<"Arreglo desordenado"<<endl;
 for(int i=0;i<11;i++){
    cout<<"|"<<a[i]<<"|";
    archivo<<"|"<<a[i]<<"|";
 }
 archivo<<endl;
}
void dividir(int a[], int ini, int fin){
  int mid;
  if(ini<fin){
    mid=(ini+fin)/2;
    dividir(a,ini,mid);
    dividir(a,mid+1,fin);
    fusionar(a,ini,fin,mid);
  }
  
}
void fusionar(int a[],int prin,int pfinal, int med){
  int i,j,k,temp[pfinal-prin];
  i=prin;
  k=0;
  j=med+1;
  while(i<= med && j<=pfinal){
    if(a[i]<a[j]){
      temp[k]= a[i];
      k++;
      i++;
    }
    else{
      temp[k]= a[j];
      k++;
      j++;
    }
  }
    while( i<=med){
       temp[k]= a[i];
      k++;
      i++;
    }
    while(j<=pfinal){
      temp[k]= a[j];
      k++;
      j++;
    }
    for(i=prin;i<=pfinal;i++){
      a[i]=temp[i-prin];
    }
  }
