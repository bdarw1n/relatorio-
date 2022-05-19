#include <stdio.h>
#include <stdlib.h>

///Cabeçalho:
void bubble_cres(int n, int *v);
void bubble_decresc(int n, int *v);
void insertion_cres(int n, int *v);
void insertion_decres(int n, int *v);
void selection_cres(int n, int *v);
void selection_decres(int n, int *v);
void quick_cres(int end, int *v, int start);
void quick_decres(int end, int *v, int start);
void mergesort(int *v, int n);
void sort(int *v, int *c, int i, int f);
void merge(int *v, int *c, int i, int m, int f);
///Função main:
int main (){
int n = 100000;
int v[n];

for(int i = 0; i< n; i++){
   v[i]= rand()% n;
}
////bubble sort:
//bubble_cres (n, v);//ordem crescente.
//bubble_decresc (n, v);//ordem decrescente.
////Insertion sort:
//insertion_cres(n, v);//ordem crescente.
//insertion_decres(n, v);//ordem decrescente.
////Selection sort:
//selection_cres(n, v);//ordem crescente.
//selection_decres(n,v);//ordem decrescente.
////quick sort:
//quick_cres(n-1,v, 0);//ordem crescente.
//quick_decres(n-1,v,0);//ordem decrescente.
////Merge Sort:
//mergesort(v,n);
////imprimir valores:
for(int i = 0; i< n; i++){
  printf("%6d\t",v[i]);

}

return 0;
}

///Bubble sort:
void bubble_cres(int n, int *v){
  for (int i =0; i < n -1; i++){
    for( int j = 0; j < n-1; j++){
        if (v[j] > v[j + 1]){
            int k = v[j];
            v[j]= v[j + 1];
            v[j+ 1] = k;
        }
    }
}
}
//////////
void bubble_decresc(int n, int *v){
 for (int i =n-1; i >=0; i--){
    for( int j = n-1; j >= 0; j--){
        if (v[j] > v[j - 1]){
            int k = v[j];
            v[j]= v[j - 1];
            v[j - 1] = k;
        }
    }
}
}
/// Insertion sort:
void insertion_cres(int n, int *v){
 for (int i = 0; i <= n; i++) {
 int j = i;
 while(v[j] < v[j - 1] && j != 0){
   int k = v[j];
   v[j] = v[j-1];
   v[j-1] = k;
   j = j-1;
}
}
}
//////////
void insertion_decres(int n, int *v){
 for (int i = 0; i <= n; i++) {
 int j = i;
 while(v[j] > v[j - 1] && j != 0){
   int k = v[j];
   v[j] = v[j-1];
   v[j-1] = k;
   j = j-1;
}
}
}
///Selection sort:
void selection_cres(int n, int *v){
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++ ){
        if (v[j] < v[i] ){
            int key = v[i];
            v[i]= v[j];
            v[j]=key;
        }
    }
 }
}
//////////
void selection_decres(int n, int *v){
for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++ ){
        if (v[j] > v[i] ){
            int key = v[i];
            v[i]= v[j];
            v[j]=key;
        }
    }
 }
}
///Quick sort:
void quick_cres(int end, int *v, int start){
  int i = start;
  int j = end;
  int key = v[i];
     if (start < end){
       while(i < j ) {
          while(v[j] >= key && i<j){j--;}
                v[i]= v[j];

          while (v[i] <= key && i<j){i++;}
                v[j] = v[i];

       }
      v[i]=key;
      quick_cres(i-1,v,start);
      quick_cres(end,v,j+1);
     }

}
//////////
void quick_decres(int end, int *v, int start){
  int i = start;
  int j = end;
  int key = v[i];
     if (start < end){
       while(i < j ) {
          while(v[j] <= key && i<j){j--;}
                v[i]= v[j];

          while (v[i] >= key && i<j){i++;}
                v[j] = v[i];

       }
      v[i]=key;
      quick_cres(i-1,v,start);
      quick_cres(end,v,j+1);
     }

}
///Merge sort:
void mergesort(int *v, int n){
  int *c = malloc(sizeof(int)*n);
  sort(v, c, 0, n-1);
  free(c);
}

void sort(int *v, int *c, int i, int f){
  if(i >= f) return;
  int m = (i+f)/2;
  sort(v,c,i,m);
  sort(v,c,m+1,f);
  merge(v,c,i,m,f);
}

void merge(int *v, int *c, int i, int m, int f){
  int z, iv = i, ic = m+1;
  for(z=i; z<=f; z++)
    c[z]=v[z];
  z=i;

  while(iv<=m && ic <= f){
    if(c[iv] <= c[ic]){
      v[z] = c[iv];
      z++;
      iv++;
    }else{
      v[z]=c[ic];
      z++;
      ic++;
    }
  }

  while(iv <= m) v[z++]= c[iv++];

  while(ic <= f) v[z++]= c[ic++];

}
