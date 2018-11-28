#include <iostream> 
using namespace std; 
struct node { 
    int data; 
    struct node* next; 
    struct node* prev; 
}; 
struct node* getNode() 
{ 
    return ((struct node*)malloc(sizeof(struct node))); 
} 
int displayList(struct node* temp) 
{ 
    struct node* t = temp; 
    if (temp == NULL) 
        return 0; 
    else { 
        cout << "The list is: "; 
  
        while (temp->next != t) { 
            cout << temp->data << " "; 
            temp = temp->next; 
        } 
  
        cout << temp->data << endl; 
  
        return 1; 
    } 
}  
int countList(struct node* start) 
{ 
    struct node* temp = start; 
    int count = 0;  
    while (temp->next != start) { 
        temp = temp->next; 
        count++; 
    } 
    count++; 
  
    return count; 
}  
bool insertAtLocation(struct node* start, int data, int loc) 
{ 
  
    struct node *temp, *newNode; 
    int i, count; 
    newNode = getNode();  
    temp = start;  
    count = countList(start); 
    if (temp == NULL || count < loc) 
        return false; 
  
    else {  
        newNode->data = data;  
        for (i = 1; i < loc - 1; i++) { 
            temp = temp->next; 
        } 
        newNode->next = temp->next;  
        (temp->next)->prev = newNode; 
        temp->next = newNode; 
        newNode->prev = temp; 
  
        return true; 
    } 
  
    return false; 
} 
void createList(int arr[], int n, struct node** start) 
{ 

    struct node *newNode, *temp; 
    int i; 
    for (i = 0; i < n; i++) { 
       
        newNode = getNode(); 
        newNode->data = arr[i]; 
        if (i == 0) { 
            *start = newNode; 
            newNode->prev = *start; 
            newNode->next = *start; 
        } 
  
        else { 
             
            temp = (*start)->prev; 
            temp->next = newNode; 
            newNode->next = *start; 
            newNode->prev = temp; 
            temp = *start; 
            temp->prev = newNode; 
        } 
    } 
} 
int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 5, 6 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    struct node* start = NULL; 
    createList(arr, n, &start); 
    displayList(start); 
    insertAtLocation(start, 8, 3); 
    displayList(start); 
  
    return 0; 
} 
