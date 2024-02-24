#include <stdio.h>
#include<stdlib.h>
int *table = NULL;
int length = 0;

void arraydestroy(int *p)
{
    if(p!=NULL)
    {
        free(p);
    }
}
void insert()
{
    int num;
    printf(" Enter a value: ");
    scanf("%d",&num);
    length++;
    if ( (table=(int*)realloc(table,length*sizeof(int)))==0)
    {
        printf("ERROR");
    }
    table[length-1]=num;
}
void display()
{
    int x;
    for(x=0; x<length; x++)
    {
        printf(" %d\n",table[x]);
    }
}

int Delete(int num)
{
    int x;
    x=FindNum(num);
    if (x==-1)
    {
        return(-1);
    }
    else
    {
        table[x]=table[length-1];
        length--;
        table=(int*)realloc(table,length*sizeof(int));
        return(1);
    }
}
void SortTable()
{
    int *s[length],*tmp,j,i;
    for(i=0; i<length; i++)
    {
        s[i]=&table[i];
    }
    for(i=0; i<length; i++)
    {
        for(j=i+1; j<length; j++)
        {
            if(*s[j]<*s[i])
            {
                tmp=s[i];
                s[i]=s[j];
                s[j]=tmp;
            }
        }
    }
    for(i=0; i<length; i++)
    {
        printf("%d : %d\n",i+1,*s[i]);
    }
}

int FindNum(int num)
{
    int i;
    for(i=0; i<length; i++)
    {
        if(table[i]==num)
        {
            return(i);
        }
    }
    return(-1);
}
int maximum() {
    int i,max; max=table[0];
    for(i=1;i<length;i++) {
        if (table[i]>max) {max=table[i];}
    }
    return(max);
}

int minimum(){
    int i,min; min=table[0];
    for(i=1;i<length;i++) {
        if (table[i]<min) {min=table[i];}
    }
    return(min);
}


int main(int ai,char* os[])
{
    int output,y,num;
    do
    {
        putchar('\n');
        printf(" 1: Insert a number\n");
        printf(" 2: Display the table\n");
        printf(" 3: Delete a number\n");
        printf(" 4: Sort the table\n");
        printf(" 5: Find a number\n");
        printf(" 6: Print maximum number\n");
        printf(" 7: Print minimum number\n");
        printf(" 8: Exit\n\n");
        printf(" Choose a number:  ");
        scanf("%d",&y);
        switch (y)
        {
        case 1 :
        {
            printf(" Inserting numbers in the table:\n");
            insert();
            break;
        }
        case 2 :
        {
            printf(" Displaying the table: \n\n");
            display();
            break;
        }
        case 3 :
        {
            printf(" Enter a value to delete: ");
            scanf("%d",&num);
            output=Delete(num);
            if(output==1)
            {
                printf("\n %d has been deleted.\n",num);
            }
            else
            {
                if(output==-1)
                {
                    printf("\n %d does not exist.\n",num);
                }
                else
                {
                    printf("\n Did not deleted %d.\n",num);
                }
            }
            break;
        }
        case 4 :
        {
            printf(" \nThe sorted table is: \n");
            SortTable();
            break;
        }

        case 5 :
        {
            printf(" Enter a number: ");
            scanf("%d",&num);
            printf(" The number is: %d",num);
            output=FindNum(num);
            if(output==-1)
            {
                printf(" The number is not Found\n");
            }
            else
            {
                printf(" Number is at %d\n",output+1);
            }
            break;
        }
        case 6 :
        {
           output=maximum();
           printf(" Maximum number is : %d\n",output);
           break;
       }
       case 7:

       {
           output=minimum(0,table);
           printf(" Minimum number is : %d\n",output);
           break;
       }

       }
    }
    while(y!=0);
    arraydestroy(table);
    exit(0);
}



