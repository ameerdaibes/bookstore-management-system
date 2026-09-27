
// Full Name: Ameer Daibes
// Student ID: 1240677
// Lecture Section: 2
// Lab Section: 11

#include <stdio.h>
#define MAXSIZE 100

void addBook( int bins[], double prices[], int *size);
void removebook (int bins [], double prices [], int *size);
void SearchForBook (int bins [], int size, double prices []);
void uploadDataFile ( int bins[], double prices[], int  *size );
void updateDataFile(int bins[], double prices[], int  size);
void printBooks (int bins[], double prices[], int  size);

int main ()
{
    printf("Welcome to our BookStore Management System\n");
    int bins[MAXSIZE];
    double prices[MAXSIZE];
    int size = 0;
    uploadDataFile(bins, prices, &size);
    int a;

    do
    {
        printf("Select an operation\n");
        printf("1- Add a Book\n");
        printf("2- Remove a Book\n");
        printf("3- Search for a Book\n");
        printf("4- Print Book List\n");
        printf("5- Exit System\n");
        scanf("%d", &a);

        switch (a)
        {
            case 1:
                addBook(bins, prices, &size);
                break;
            case 2:
                removebook(bins, prices, &size);
                break;
            case 3:
                SearchForBook(bins, size, prices);
                break;
            case 4:
                printBooks(bins, prices, size);
                break;
            case 5:
                updateDataFile(bins, prices, size);
                printf("thanks for using our system! <3 \n");
                break;
            default:
                printf("Incorrect input, try again.\n");
        }

    } while (a != 5);

    return 0;
}

void addBook(int bins[], double prices[], int *size)
{
    int add = 1;

    if (*size >= MAXSIZE)
    {
        printf("it's full\n");
        add = 0;
    }

    int bin;
    double price;

    if (add != 0)
    {
        printf("please enter the bin number that's 4 digits long\n");
        scanf("%d", &bin);
        printf("enter its price\n");
        scanf("%lf", &price);

        int y;
        for (y = 0; y < *size && bins[y] < bin; y++)
        {}
        if (y < *size && bins[y] == bin)
        {
            printf("the book entered already exists in the system\n");
            add = 0;
        }
        if (add != 0)
        {
            for (int k = *size; k > y; k--)
            {
                bins[k] = bins[k - 1];
                prices[k] = prices[k - 1];
            }

            bins[y] = bin;
            prices[y] = price;
            (*size)++;
            printf("book added successfully\n");
        }
    }
}

void removebook(int bins[], double prices[], int *size)
{
    int bin;
    int found = 0;

    printf("Enter the bin number to remove:\n");
    scanf("%d", &bin);

    int l = -1;

    for (int i = 0; i < *size; i++)
    {
        if (bins[i] == bin)
        {
            l = i;
            found = 1;
        }
    }

    if (found == 1)
    {
        for (int k = l; k < (*size - 1); k++)
        {
            bins[k] = bins[k + 1];
            prices[k] = prices[k + 1];
        }
        (*size)--;
        printf("removed successfully\n");
    }
    else
    {
        printf("there is not any book exists with that BIN\n");
    }
}


void SearchForBook(int bins[], int size, double prices[])
{
    int found = 0;

    if (size != 0)
    {
        int bin;
        printf("enter the BIN of the wanted book\n");
        scanf("%d", &bin);

        for (int i = 0; i < size; i++)
        {
            if (bins[i] == bin)
            {
                printf("the found book is %d and the price is %.2f\n", bins[i], prices[i]);
                found = 1;
            }
        }

        if (found == 0)
        {
            printf("no book is found\n");
        }
    }
    else
    {
        printf("error\n");
    }
}

void uploadDataFile ( int bins[], double prices[], int  *size )
{
    FILE*in;
    in= fopen("books.txt","r");
     while (*size < MAXSIZE && fscanf(in, "%d %lf", &bins[*size], &prices[*size]) != -1)
        {
        (*size)++;

        }
      fclose (in);
}
void updateDataFile(int bins[], double prices[], int  size)
{
    FILE*out;
    out = fopen ("books.txt","w");
    for (int i= 0; i < size; i++)
    {
        fprintf(out, "%d %f\n", bins [i], prices [i]);
    }
    fclose (out);
}
void printBooks (int bins[], double prices[], int  size)
{
    if (size == 0)
    {
        printf("empty list\n");
    }
    printf("list\n BIN\t price\n");
    for (int i = 0; i < size ; i++)
    {
        printf("\n%d\t%.2f\n", bins [i], prices [i]);
    }
}
