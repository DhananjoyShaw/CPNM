#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DIGITS 100

// Define the structure for a segment node
typedef struct SegmentNode
{
    char *segment;
    struct SegmentNode *next;
} SegmentNode;

// Function to create a new segment node
SegmentNode *createSegmentNode(const char *segmentContent)
{
    SegmentNode *newNode = (SegmentNode *)malloc(sizeof(SegmentNode));
    newNode->segment = strdup(segmentContent);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a segment node at the end of a list
void insrtsegmnts(SegmentNode **head, const char *segmentContent)
{
    SegmentNode *newNode = createSegmentNode(segmentContent);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        SegmentNode *present = *head;
        while (present->next != NULL)
        {
            present = present->next;
        }
        present->next = newNode;
    }
}

// Function to insert large number segments into a list
void insrtLNsegmnts(SegmentNode **head, const char *number)
{
    int segmentIndex = 0;
    char currentSegment[11];
    for (int i = 0; i < strlen(number); i++)
    {
        if (segmentIndex < 9)
        {
            currentSegment[segmentIndex] = number[i];
            segmentIndex++;
        }
        else
        {
            currentSegment[segmentIndex] = '\0';
            insrtsegmnts(head, currentSegment);
            segmentIndex = 0;
            currentSegment[0] = number[i];
            segmentIndex++;
        }
    }
    if (segmentIndex > 0)
    {
        currentSegment[segmentIndex] = '\0';
        insrtsegmnts(head, currentSegment);
    }
}

// Function to reverse characters in a string
void reverseCharacters(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Function to remove the first digit from a string
void removeFirstDigit(char *str)
{
    int length = strlen(str);
    if (length <= 1)
    {
        str[0] = '\0'; // Set the string to an empty string
    }
    else
    {
        memmove(str, str + 1, length); // Shift the characters left by one position
    }
}

// Function to add large number segments
void addLNsegmnts(SegmentNode *list1, SegmentNode *list2, SegmentNode **result)
{
    SegmentNode *presentList1 = list1;
    SegmentNode *presentList2 = list2;

    int carry = 0;
    while (presentList1 != NULL || presentList2 != NULL || carry)
    {
        int part1 = 0, part2 = 0;

        if (presentList1 != NULL)
        {
            char currentSegment1[11];
            strcpy(currentSegment1, presentList1->segment);
            reverseCharacters(currentSegment1);
            part1 = atoi(currentSegment1);
            presentList1 = presentList1->next;
        }

        if (presentList2 != NULL)
        {
            char currentSegment2[11];
            strcpy(currentSegment2, presentList2->segment);
            reverseCharacters(currentSegment2);
            part2 = atoi(currentSegment2);
            presentList2 = presentList2->next;
        }

        int sum = part1 + part2 + carry;
        carry = sum / 1000000000;

        char sumSegment[11];
        sprintf(sumSegment, "%d", sum);
        sumSegment[strlen(sumSegment)] = '\0';
        if (strlen(sumSegment) > 9)
            removeFirstDigit(sumSegment);

        insrtsegmnts(result, sumSegment);
    }
}

// Function to reverse a segment list
void reverseSegmentList(SegmentNode **head)
{
    SegmentNode *prev = NULL;
    SegmentNode *present = *head;
    SegmentNode *next;

    while (present != NULL)
    {
        next = present->next;
        present->next = prev;
        prev = present;
        present = next;
    }
    *head = prev;
}

// Function to print a segment list
void printSegmentList(SegmentNode *head)
{
    if (head == NULL)
    {
        printf("0"); // Print 0 if the list is empty
        return;
    }

    SegmentNode *current = head;
    int isFirstSegment = 1; // To keep track of the first segment

    while (current != NULL)
    {
        if (!isFirstSegment)
        {
            printf(""); // If you want comma or space after the first segment otherwise use as it is
        }

        printf("%s", current->segment);

        isFirstSegment = 0;
        current = current->next;
    }
}

int main()
{

    // Declare pointers to linked lists for storing segments of input and result numbers

    SegmentNode *inputList1 = NULL;     // Pointer to the first number's segment list
    SegmentNode *inputList2 = NULL;     // Pointer to the second number's segment list
    SegmentNode *outputSegments = NULL; // Pointer to the result's segment list

    char inputNum1[MAX_DIGITS], inputNum2[MAX_DIGITS];
    printf("Enter the first +ve large number : ");
    scanf("%s", inputNum1);
    printf("Enter the second +ve large number : ");
    scanf("%s", inputNum2);

    reverseCharacters(inputNum1);
    reverseCharacters(inputNum2);
    insrtLNsegmnts(&inputList1, inputNum1);
    insrtLNsegmnts(&inputList2, inputNum2);

    addLNsegmnts(inputList1, inputList2, &outputSegments);
    reverseSegmentList(&outputSegments);

    printf("\nThe Sum of the two large numbers is: "); // Print the result of the addition
    printSegmentList(outputSegments);

    return 0;
}
