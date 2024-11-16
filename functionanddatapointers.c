// Online C compiler to run C program online
//this code uses multiple times a function inside another!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct car {
    int price;
    char name[50];
} Car;

typedef struct person {
    float age;
    char name[50];
} Person;

struct use_struct {
    void* any_struct;
};

typedef struct list_container_struct {
    struct use_struct data;
    struct list_container_struct* connector;
} ListContainer;

float xsq(float x) {
    return x * x;
}
float xqu(float x) {
    return x * x * x;
}

float use_function(float x, float (*function)(float)) {
    return function(x);
}

int main() {
    Car car0;
    car0.price = 10000;
    strncpy(car0.name, "AMG", sizeof(car0.name));
    Person person0;
    person0.age = 20.5;
    strncpy(person0.name, "Nick", sizeof(person0.name));
    ListContainer list0;
    list0.data.any_struct = (void*)&car0; // Store address of car0
    ListContainer list1;
    list1.data.any_struct = (void*)&person0; // Store address of person0

    // Connect the lists
    list0.connector = &list1; // Use address of list1
    list1.connector = &list0; // Use address of list0
    
    Person *personPtr = (Person*)list1.data.any_struct;
    float age = personPtr->age; // Access the age member
    printf("%f\n", age);
    
    // Write C code here
    printf("Try programiz.pro\n");
    printf("%f\n", use_function(10.f, xsq));
    printf("%f\n", use_function(10.f, xqu));
    return 0;
}
