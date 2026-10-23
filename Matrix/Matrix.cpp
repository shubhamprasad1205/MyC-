/*1. Accept matrix elements from the user.
2. Display the matrix.
3. Calculate the sum of all elements.
4. Calculate the sum of each row.
5. Calculate the sum of each column.
6. Find the largest element.
7. Find the smallest element.
8. Subtract the second matrix from the first.
9. Multiply two matrices.*/

#include<iostream>
using namespace std;

void acceptMatrix(int(*ptr)[3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> ptr[i][j];
        }
    }
}

void displayMatrix(int(*ptr)[3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
                cout << ptr[i][j] << " " ;
        }
        cout << endl;
    }
}

int calculateSum(int(*ptr)[3]){
    int sum = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            sum = sum + ptr[i][j];
        }
    }
    return sum;
}

void calculateRowSum(int(*ptr)[3]){


    for(int i = 0; i < 3; i++){
            int sum = 0;
        for(int j = 0; j < 3; j++){
            sum = sum + ptr[i][j];
        }
        cout<<"\nRow Sum :"<<sum;
    }
}
void calculateColumnSum(int(*ptr)[3]){
    for(int i = 0; i < 3; i++){
            int sum = 0;
        for(int j = 0; j < 3; j++){

            sum = sum + ptr[j][i];
        }
        cout<<"\nColumn Sum :"<<sum;
    }
}
int checkLargest(int (*ptr)[3]){
    int max = INT_MIN;
    for(int i =0; i < 3; i++){
        for(int j =0; j < 3 ; j++){
            if(ptr[i][j] > max){
                max = ptr[i][j];
            }
        }
    }
    return max;

}
int checkSmallest(int (*ptr)[3]){
    int min = INT_MAX;
    for(int i =0; i < 3; i++){
        for(int j =0; j < 3 ; j++){
            if(ptr[i][j] < min){
                min = ptr[i][j];
            }
        }
    }
    return min;
}

void sub2Matrix(int(*ptr)[3], int(*ptr1)[3], int(*ptr2)[3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ptr2[i][j] = ptr1[i][j] - ptr[i][j];
        }
    }
}

void Multiply2Matrix(int(*ptr)[3], int(*ptr1)[3], int(*ptr2)[3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ptr2[i][j] = ptr1[i][j] * ptr[i][j];
        }
    }
}

int main(){

    int arr[3][3];
    int arr1[3][3];
    int arr2[3][3];

    acceptMatrix(arr);
    displayMatrix(arr);
    cout << calculateSum(arr);
    calculateRowSum(arr);
    calculateColumnSum(arr);
    cout<<"\nLargest :"<<checkLargest(arr);
    cout<<"\nSmallest :"<<checkSmallest(arr) << endl;

    acceptMatrix(arr1);
    displayMatrix(arr1);

    sub2Matrix(arr,arr1,arr2);
    displayMatrix(arr2);

    Multiply2Matrix(arr,arr1,arr2);
    displayMatrix(arr2);

}

