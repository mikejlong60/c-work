//func FoldRight[T1, T2 any](as []T1, z T2, f func(T1, T2) T2) T2 {
//	if len(as) > 1 { //Slice has a head and a tail.
//		h, t := as[0], as[1:len(as)]
//		return f(h, FoldRight(t, z, f))
//	} else if len(as) == 1 { //Slice has a head and an empty tail.
//		h := as[0]
//		return f(h, FoldRight(Zero[T1](), z, f))
//	}
//	return z
//}/
#include <stdio.h>


int FoldRight(const int *xs, int z, int size, int (*f)(int, int)) {
    //int size1 = sizeof(xs) / sizeof(xs[0]);
    //printf("Array size in foldright: %d\n", size1);
    int outLength;
    if (size > 1) {//Has at least two elements
        int h = xs[0];
        int* t = sliceArray(&xs, 1, size, &outLength); 
        int s = sizeof(t) / sizeof(h);
        return f(h, FoldRight(t, z, s, f));
    } else if (size == 1) {
        int h = xs[0];
    }
    return z;
}

int sum(int a, int b) {
    return a + b;
}

#include <stdio.h>
#include <stdlib.h>

//Returns a slice of the given array starting at index start and ending at end(exclusive) 
int* sliceArray(const int *array, int start, int end, int *outLength) {
    *outLength = end - start;
    int *slice = (int*)malloc(*outLength * sizeof(int));

    for (int i = 0; i < *outLength; i++) {
        slice[i] = array[start + i];
    }
 
    return slice;
}

int maint() {
    int numbers[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int start = 2;
    int end = 5;
    int length;
    printf("length: %d\n", length);
    if (start >= 0 && end <= (sizeof(numbers) / sizeof(numbers[0])) && start < end) {
        printf("length1: %d\n", length);
        int *slice = sliceArray(numbers, start, end, &length);
        printf("length2: %d\n", length);
        for (int i = 0; i < length; i++) {
            printf("%d ", slice[i]);
        }
        printf("\n");

        // Remember to free the allocated memory
        printf("slice before free call: %p\n", (void*)slice);
        free(slice);
        printf("slice after free call: %p\n", (void*)slice);
        *slice = NULL;
        printf("slice after setting pointer to NULL: %p\n", *slice);
    } else {
        printf("Invalid slice indices.\n");
    }

    return 0;
}


int main() {
    int xs[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int size = sizeof(xs) / sizeof(xs[0]);
    int result = FoldRight(xs, 0, size, sum);
    printf("Array size in main: %d\n", result);

    maint();

}