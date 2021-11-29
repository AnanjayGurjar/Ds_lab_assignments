#include<stdio.h>
void binarySearch(int arr[], int start, int end, int key){
    if(start>end){
        printf("Couldn't find the element");
        return;
    }
    int mid = start + (end - start)/2;
    if(arr[mid] == key){
        printf("Element found at the index %d", mid);
    }else if(key > arr[mid]){
        binarySearch(arr, mid + 1, end, key);
    }else{
        binarySearch(arr, start, mid -1, key );
    }


}
int gcd(int a, int b){
    if (a == 0)
       return b;
    if (b == 0)
       return a;
 
    // base case
    if (a == b)
        return a;
 
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
int main(){

    // int arr[20], n;
    // printf("Enter the size of array: ");
    // scanf("%d", &n);
    // printf("Enter the array in sorted order");
    // for(int i = 0; i < n; i++){
    //     scanf("%d", &arr[i]);
    // }
    // printf("enter the element you want to searc");
    // int key;
    // scanf("%d", &key);
    // binarySearch(arr, 0, n -1, key);

    printf("%d", gcd(231, 396));

}