// Write a c program to analyze collisions for different hash function based on a given set of inputs and given size.


#include <stdio.h>
#include <math.h>
#define SIZE 10

int division_remainder(int input){
    return input % 10; 
}

int multiplication_method(int input){
    double result = input * 0.6180339887;
    result -= (int)result;
    result *= SIZE;
    return floor(result); 
}

int folding_method(int input){
    int sum = 0;
    while(input!=0){
        int rem = input % 10;
        sum+= rem;
        input = input/10; 
    }

    return sum % SIZE;
}

int mid_square(int input) {
    
    long long result = (long long)input * input;

    
    if (result < 0)
        result = -result;

    
    int size = 0;
    long long temp = result;
    while (temp != 0) {
        size += 1;
        temp = temp / 10;
    }
    int middleIndex = 0;

    if(size%2!=0){
     middleIndex = ((size - 1) / 2);
    }
    else{
        middleIndex = ((size - 1) / 2)+1;
    }

    
    int i = 0;
    int code = 0;
    while (i <= middleIndex) {
        code = result % 10;
        result = result / 10;
        i++;
    }

    return code;
}

int checkCollision(int arr[],int hash,int input){
    if(arr[hash]==0){
        arr[hash]=input;
        return 0;
    }

    return 1;
    
}





int main(){

    int inputs[] = {23, 44, 55, 12, 78, 34, 62, 90, 33, 57};

    int collision1 = 0;
    int collision2 = 0;
    int collision3 = 0;
    int collision4 = 0;
    int hash1[SIZE];
    int hash2[SIZE];
    int hash3[SIZE];
    int hash4[SIZE];

    for(int i=0;i<SIZE;i++){
        hash1[i]=0;
        hash2[i]=0;
        hash3[i]=0;
        hash4[i]=0;
    }

    for (int i = 0; i < SIZE; i++) {
        int input = inputs[i];
        int hash_val1 = division_remainder(input);
        int hash_val2 = multiplication_method(input);
        int hash_val3 = folding_method(input);
        int hash_val4 = mid_square(input);
        collision1 += checkCollision(hash1, hash_val1, input);
        collision2 += checkCollision(hash2, hash_val2, input);
        collision3 += checkCollision(hash3, hash_val3, input);
        collision4 += checkCollision(hash4, hash_val4, input);

    }

    printf("Collisions Using division-remainder method:%d\n",collision1);
    printf("Collisions Using multiplication method:%d\n",collision2);
    printf("Collisions Using folding method:%d\n",collision3);
    printf("Collisions Using Mid-Square method:%d\n",collision4);

    

    

    return 0;
}