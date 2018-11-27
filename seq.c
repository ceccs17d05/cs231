  
#include <stdio.h>
void main()
{
	int arr[]={12,23,78,98,67,56,45,19,65,9},key,i,flag=0;
	printf("ENTER A NUMBER ");
	scanf("%d",&key);
	for(i=0;i<10;i++)
	{
		if(key==arr[i])
			flag=1;
	}
	if(flag==1)
		printf("THE NUMBER %d EXISTS IN THE ARRAY",key);
	else
printf("THE NUMBER %d DOES NOT EXIST IN THE ARRAY",key);
}



