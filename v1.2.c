#include<stdio.h>
#include<stdlib.h>
void main()
{
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *head=NULL,*pos=NULL,*tail=NULL;
	int ch,entry;
	while(1)
	{
		printf("\n1.insert\n2.display\n3.search\n4.deletion\n5.exit");
		printf("\nenter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
		{
			printf("\nenter data");
			scanf("%d",&entry);
			if(head==NULL)
			{
				head=(struct node*)malloc(sizeof(struct node));
				head->data=entry;
				pos=head;
				tail=head;
			}
			else
			{
				tail->next=(struct node*)malloc(sizeof(struct node));		
				tail=tail->next;
				tail->data=entry;
			}
			break;
		}
		case 2:
		{		
			pos=head;
			printf("\nelements are\n");
			while(pos!=NULL)
			{
				printf("%d ",pos->data);
				pos=pos->next;
				
			}
			break;
		}
		
		case 3:
		{	
			int s,flag=0;	
			printf("\nenter element to be searched\n");
			scanf("%d",&s);
			pos=head;
			while(pos!=NULL)
			{
				if(s==pos->data)
				{
					flag=1;
					break;
				}	
				pos=pos->next;
			}
			if(flag==1)
				printf("\nelement  found");
			else
				printf("\nelement not found");	
			break;
		}
		case 4:
		{
			struct node *temp=head;
			printf("\n enter position of data from 0");
			scanf("%d",&entry);
			if(entry==0)
			{
				head=head->next;
				temp->next=NULL;
				free(temp);
			}
			else
			{
				for(int i=0;i<entry-1;i++)
				{
					temp=temp->next;
				}	
				struct node *del=temp->next;
				temp->next=temp->next->next;
				del->next=NULL;
				free(del);
			}
			break;
		}		
						
		case 5:
		{
			printf("\ngoodbye");
			exit(0);
		}
	}
}
}	
				
