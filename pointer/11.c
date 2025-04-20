#include<stdio.h>
#include<stdlib.h>

//realloc函数

void printBudgets(double*budgets,int size);

int main(void)
{
    int size=3;

    double*budgets=(double*)calloc(size,sizeof(double));
    if(budgets==NULL)
    {
        perror("failed to allocate initial budgets\n");
        exit(EXIT_FAILURE);
    }

    budgets[0]=10000;
    budgets[1]=20000;
    budgets[2]=30000;

    printBudgets(budgets,size);

    int newSize=6;
    double*newBudgets=(double*)realloc(budgets,newSize*sizeof(double));

    if(newBudgets==NULL)
    {
        perror("failed to allocate initial budgets\n");
        exit(EXIT_FAILURE);
    }

    budgets=newBudgets;
    budgets[3]=40000;
    budgets[4]=50000;
    budgets[5]=60000;

    printBudgets(budgets,newSize);
    free(budgets);
    
    return 0;

}

void printBudgets(double*budgets,int size)
{
    puts("budgets :\n");
    for(int i=0;i<size;i++)
    {
        printf("department %d: %.2f\n",i+1,budgets[i]);
    }
}