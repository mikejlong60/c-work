#include <stdio.h>
#include <stdlib.h>

//Returns a slice of the given array starting at index start and ending at end(exclusive) 
int* sliceArray(const int *array, int start, int end, int *outLength) {
    *outLength = end - start;
    int *slice = (int*)malloc(*outLength * sizeof(int));

    for (int i = 0; i < *outLength; i++) { 
        slice[i] = array[start + i];
        printf("sliceArray element:%d \n", slice[i]);
   }
 
    return slice;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i+1]);
    }
    printf("\n");
}

int main() {
    int x =1, y=2, z[10];
    printf("duuh1 %d\n", x);
    printf("duuh2 %d\n", y);
    printf("duuh3 %d\n", z[10]);
    int *ip; //ip is a pointer to int

    ip = &x; //ip now points to x
    printf("duuh4 %d\n", *ip);
    y = *ip; //y is now 1
    printf("duuh5 %d\n", y);
    *ip = 0; //x is now 0
    printf("duuh6 %d\n", x);
    //ip = &z[0]; //ip now points to z[0]
    printf("duuh7 %d\n", *ip);

    //double *dp, atof(char *);

    *ip = *ip + 10;//increments *ip by 10
    printf("duuh8 %d\n", *ip);
    y = *ip + 1;//takes whatever ip points at,adds 1, and assigns thed result to y
    printf("duuh9 %d\n", y);
    *ip += 1;//increments what ip points to
    printf("duuh10 %d\n", *ip);
    ++*ip;//increments what ip points to
    printf("duuh11 %d\n", *ip);
    (*ip)++;
    printf("duuh12 %d\n", *ip);
    

    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printArray(numbers, size); // 'numbers' decays to a pointer to the first element
    int *z2;
    int outlen = 2;
    z2 = sliceArray(numbers, 2, 4, &outlen);

}