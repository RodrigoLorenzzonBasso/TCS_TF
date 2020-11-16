#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_opt.h"
#include "array.h"
#include "sort.h"

int main(int argc, char **argv) {
    int i, method, size, array_type, print_vector = 0;

    if(!check_opt(argc)){
        fprintf(stderr,"Not enough parameters\n");
        fprintf(stderr,"Expected: -a SORTTYPE -n ARRAYSIZE -s ARRAYSTATE [-P]\n");
        fprintf(stderr,"Please read the doc.\n");
        return 1;
    }

    get_opt(argc, argv, &method, &size, &array_type, &print_vector);

    // Create the vector with the specified size and situation
    int *vet = generate_array(size, array_type);

    if(!vet){
        fprintf(stderr,"Memory allocation failed.\n");
        return 1;
    }

    int *vet_aux = (int*)malloc(sizeof(int)*size);
    // Create a copy of the vector to print it berfore and after it is sorted in case this option is enabled
    for(i=0; i<size; i++){
        vet_aux[i] = vet[i];
    }
    // Sort the array
    sort_array(vet, size, method);

    printf("-- Analysis --\n\n");
    printf("Sorting algorithm: %s\n", get_method_name(method));
    printf("Array type: %s\n", get_array_type_name(array_type));
    printf("Array size: %d\n", size);
    /*
    if(method < GPUQUICK ){
        printf("Number of comparisons: %d\n", get_comparisons());
        printf("Number of swaps: %d\n", get_swaps());
    }
    */
    printf("Time elapsed: %f s\n", get_elapsed_time());
    if(print_vector){
        printf("Original: ");
        for(i=0; i<size; i++){
            printf("%d ", vet_aux[i]);
        }
        printf("\n\nSorted: ");
        for(i=0; i<size; i++){
            printf("%d ", vet[i]);
        }
    }
    free(vet);
    free(vet_aux);
    printf("\n\n");
    return 0;
}

/**
 * Method that receives a pointer to an array that will be sorted,
 * his size and the constant of the method that will be used
 * @param  array  Array to be sorted
 * @param  size   Size of the array
 * @param  method Sorting algorithm constant
 * @return        Pointer to the sorted array
 */
int* sort_array(int *array, int size, int method){

    switch(method){
        case SELECTION:
            start = clock();
            selection_sort(array, size);
            end = clock();
        break;

        case INSERTION:
            start = clock();
            insertion_sort(array, size);
            end = clock();
        break;

        case SHELL:
            start = clock();
            shell_sort(array, size);
            end = clock();
        break;

        case QUICK:
            start = clock();
            quick_sort(array, 0, size-1);
            end = clock();
        break;

        case HEAP:
            start = clock();
            heap_sort(array, size);
            end = clock();
        break;

        case MERGE:
            start = clock();
            merge_sort(array, size);
            end = clock();
        break;
/*
        case GPUQUICK:
            start = clock();
            gpu_qsort(array,size);
            end = clock();
        break;

        case GPUMERGE:
            start = clock();
            gpumerge_sort(array,size);
            end = clock();
*/            
    }
    elapsed_time = (((double)(end-start))/CLOCKS_PER_SEC);
    return array;
}

double get_elapsed_time(){
    return elapsed_time;
}

int get_swaps(){
    return numberOfSwaps;
}

int get_comparisons(){
    return numberOfComparisons;
}
