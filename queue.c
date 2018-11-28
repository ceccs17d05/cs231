#include<stdio.h>
#include<conio.h>
#define n 5
void main()
{
    int queue[n],ch=1,front=0,rear=0,i,j=1,x=n;
    clrscr();
    printf("Queue using Array");
    printf("\n1.Insertion \n2.Deletion \n3.Display \n4.Exit");
    while(ch)
    {
        printf("Enter the Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            if(rear==x)
                printf("Queue is Full");
            else
            {
                printf("Enter no %d",j++);
                scanf("%d",&queue[rear++]);
            }
            break;
        case 2:
            if(front==rear)
            {
                printf(" Queue is empty");
            }
            else
            {
                printf("Deleted Element is %d",queue[front++]);
                x++;
            }
            break;
        case 3:
            printf("Queue Elements are ");
            if(front==rear)
                printf(" Queue is Empty");
            else
            {
                for(i=front; i<rear; i++)
                {
                    printf("%d",queue[i]);
                   
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong Choice: please see the options");
            }
        }
    }
    getch();
}

