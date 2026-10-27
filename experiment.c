#include <stdio.h>
#include <stdlib.h>

int main(){

    //malloc() = a function in C that dynmaically allocates
    //           a specified number bytes in memory
    // malloc uses memory from the heap
    //

    int number = 0;
    printf("Enter the numeber of grades: ");
    scanf("%d", &number);
    
    char *grades = malloc(number * sizeof(char));

    if(grades == NULL){
        printf("Memory allocation failed!\n");
        return 1; //we know error occurs
    }

    for(int i = 0; i < number; i++){
        printf("Enter grade #%d: ", i + 1);
        scanf(" %c", &grades[i]); //scanf inserts the inputs into grades
    }

    for(int i = 0; i < number; i++){
        printf("%c ", grades[i]);
    }

    free(grades); //return the memory back to heap
    grades = NULL; //avoid pointer pointing to random memory

    return 0;
}