#include<stdio.h>
#include<stdlib.h>



// This program demonstrates the use of a union and a struct to store different types of data.
// It uses a union to store an integer, a float, or a string, and a struct to hold the type of data and its value.

typedef union data{
    int int_value;
    float float_value;
    char* char_value; 
}data;

typedef enum datatypes{
    INT,
    FLOAT,
    STRING
}datatypes;

typedef struct typedata{
    data value;
    datatypes type;
}typedata;

void print_data(typedata *p);

int main(void)
{
    typedata data1={.type=INT, .value={.int_value=10}};
    typedata data2={.type=FLOAT, .value={.float_value=3.14}};
    typedata data3={.type=STRING, .value={.char_value="Hello, World!"}};
    print_data(&data1);
    print_data(&data2);
    print_data(&data3);
    return 0;
}
void print_data(typedata *p){
    switch(p->type){
        case INT:
            printf("int_value=%d\n",p->value.int_value);
            break;
        case FLOAT:
            printf("float_value=%f\n",p->value.float_value);
            break;
        case STRING:
            printf("char_value=%s\n",p->value.char_value);
            break;
        default:
            printf("Unknown type\n");
            break;
    }
}