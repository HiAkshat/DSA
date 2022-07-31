#include <stdio.h>
#include <stdlib.h>

struct customDataType
{
    int totalSize;
    int usedSize;
    int *ptr;
};

void createArray(struct customDataType *ptr, int tSize, int uSize)
{
    ptr->totalSize = tSize;
    ptr->usedSize = uSize;
    ptr->ptr = (int *)(malloc(tSize * sizeof(int)));
}

void setArray(struct customDataType *ptr)
{
    for (int i = 0; i < (ptr->usedSize); i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &ptr->ptr[i]);
    }
}

void displayArray(struct customDataType *ptr)
{
    for (int i = 0; i < ptr->usedSize; i++)
    {
        printf("\n%d", ptr->ptr[i]);
    }
}

void indexInsertion(struct customDataType *ptr, int index, int element)
{
    for (int i = ptr->usedSize - 1; i > index; i--)
    {
        ptr->ptr[i + 1] = ptr->ptr[i];
    }

    ptr->ptr[index] = element;
    ptr->usedSize++;
}

void indexDeletion(struct customDataType *ptr, int index)
{
    for (int i = index; i < ptr->usedSize; i++)
    {
        ptr->ptr[i] = ptr->ptr[i + 1];
    }

    ptr->usedSize--;
}

int binarySearch(struct customDataType *ptr, int element)
{
    int low=0, high=ptr->usedSize-1, mid;

    while (low<=high)
    {
        mid=(low+high)/2;
        printf("%d", mid);
        if (ptr->ptr[mid]==element)
        {
            return mid;
        }

        else if (ptr->ptr[mid]<element)
        {
            low=mid+1;
        }

        else if (ptr->ptr[mid]>element)
        {
            high=mid-1;
        }
    }
    
    return -1;
}

int main()
{
    struct customDataType myDataType;
    createArray(&myDataType, 8, 6);
    setArray(&myDataType);
    displayArray(&myDataType);
    //indexInsertion(&myDataType, 1, 10);
    //indexDeletion(&myDataType, 2);
    //displayArray(&myDataType);
    
    printf("\nThe element 30 is at %d.",binarySearch(&myDataType,30));
    
    return 0;
}