//calloc函数
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char*name;
    int *tasklist;
    int taskcount;
}Employee;

Employee*create_employee(const char*name,int taskcount);
void free_em(Employee*employee);
void print_em(const Employee*employee);

int main(void)
{
    Employee*develop=create_employee("fank",5);
    if(develop==NULL) return EXIT_FAILURE;

    develop->tasklist[0]=101;

    print_em(develop);
    free_em(develop);

    return EXIT_SUCCESS;
}

Employee*create_employee(const char*name,int taskcount)
{
    Employee*new_employee=(Employee*)malloc(sizeof(Employee));
    if(new_employee==NULL)
    {
        perror("failed");
        return NULL;
    }

    new_employee->name=(char*)malloc(sizeof(name)+1);
    if(new_employee->name==NULL)
    {
        perror("failed");
        free(new_employee);
        return NULL;
    }

    strcpy_s(new_employee->name,strlen(name)+1,name);

    new_employee->taskcount=taskcount;
    new_employee->tasklist=(int*)calloc(taskcount,sizeof(int));

    if(new_employee->tasklist==NULL)
    {
        perror("failed");
        free(new_employee->name);
        free(new_employee);
        return NULL;
    }
    return new_employee;
}

void free_em(Employee*employee)
{
    if(employee!=NULL)
    {
        free(employee->name);
        free(employee->tasklist);
        free(employee);
    }
}

void print_em(const Employee*employee)
{
    if(employee!=NULL)
    {
        printf("%s\n",employee->name);
        printf("%d\n",employee->tasklist[0]);
        printf("%d\n",employee->taskcount);

    }
}
