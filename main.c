#include "header.h"

int main()
{
	Node first=NULL;
	User first1=NULL;
	int ch,loop=1,k=1;

	char no[10];
	char dep[20];
	char arr[20];
	char d_time[10];
	char a_time[10];
	float fare;
	float c_fare;

	first=insert(first,"61482","Bengaluru","Ranchi","7:30","9:50",4000,2000);
	first=insert(first,"62483","Ranchi","Bengaluru","7:30","9:50",4000,2000);
	first=insert(first,"63484","Bengaluru","Delhi","7:30","9:50",4000,2000);
	first=insert(first,"64485","Kolkata","Bengaluru","7:30","9:50",4000,2000);
	first=insert(first,"65486","Kolkata","Ranchi","7:30","9:50",4000,2000);
	first=insert(first,"66487","Bengaluru","Hydrabad","7:30","9:50",4000,2000);
	first=insert(first,"67488","Kolkata","Ranchi","7:30","9:50",4000,2000);

	// FILE *train = fopen("train.txt","a+");
	FILE *user = fopen("user.txt","w+");
	FILE *user1 = fopen("user1.txt","r+");

	// int k=0;//no of users 
	char a[1000];
	char *d,*username, * password;
	User tempo;
	while(fgets(a,1000,user1)!=NULL)
	{
		// fgets(a,1000,user);
		d=strtok(a,",");
		
		if(d[0]=='U')
		{
			// printf("---------------------------------------------------------------------------------");
			username=strtok(NULL,",");
			password=strtok(NULL,",");
			first1 = b_signup(first1,&k,username,password);
			continue;
		}
			tempo=first1;
			while(tempo->next!=NULL)
			{
				if(tempo->username==username)
				{
					// printf("/////////////////////////////////////////////////");
					break;
				}	
				tempo=tempo->next;
			}
			char *date=strtok(NULL,",");
			char *dep=strtok(NULL,",");
			char *arr=strtok(NULL,",");
			char *name=strtok(NULL,",");
			char *sex=strtok(NULL,",");
			char *age=strtok(NULL,",");
			char *categ=strtok(NULL,",");
			char *userno=strtok(NULL,",");
			
			Pass tem,tra;
			tem=(Pass)malloc(sizeof(struct passenger));
			// strcat(date,"\n");
			strcpy(tem->date,date);
			strcpy(tem->dep,dep);
			strcpy(tem->arr,arr);
			strcpy(tem->name,name);
			strcpy(tem->categ,categ);
			tem->sex=sex[0];
			tem->age=atoi(age);
			tem->userno=atoi(userno);
			tem->next=NULL;
			if(tempo->tic==NULL)
			{
				tempo->tic=tem;
			}
			else
			{
				tra=tempo->tic;
				while(tra->next!=NULL)
				{
					tra=tra->next;
				}
				tra->next=tem;
			}

		
			
	}	
	fclose(user1);
	// printf("[[[[[[[[[[[[[[  %s",first1->next->username);
	
	




	while(loop)
	{
		printf("1.Display the details of every train\n2.Book a ticket\n3.Display details of Passengers\n4.Cancel a ticket\n");
		printf("5.add train\n6.delete train\n7.Exit\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:display(first);
					break;
			case 2:first1=booking(first,first1,&k);
					break;
			case 3:disp(first1);
					break;
			case 4:first1=cancel_booking(first1);
					break;

			
			case 5: printf("enter train number:");
					scanf("%s",no);
					printf("enter departure station:");
					scanf("%s",dep);
					printf("enter arrival station:");
					scanf("%s",arr);
					printf("enter departure time:");
					scanf("%s",d_time);
					printf("enter arrival time:");
					scanf("%s",a_time);
					printf("adult ticket cost:");
					scanf("%f",&fare);
					printf("children ticket cost:");
					scanf("%f",&c_fare);
					first=insert(first,no,dep,arr,d_time,a_time,fare,c_fare);
					break;

			case 6: printf("enter the train number to be deleted:");
					scanf("%s",no);
					first=delete_train(first,no);
					break;
			
			case 7:printf("Exit\n");

					remove("user1.txt");


					User temp=first1;
					while(temp!=NULL)
					{
						fputs("U",user);fputs(",",user);
						fputs(temp->username,user);fputs(",",user);
						fputs(temp->password,user);fputs(",",user);
						fputc('\n',user);
						Pass tra = temp->tic;
						while(tra!=NULL)
						{
							fputs("P",user);fputs(",",user);
							char dat[10];
							for(int i=0;i<10;i++)
							{
								dat[i]=tra->date[i];
							}
							fputs(dat,user);fputs(",",user);
							fputs(tra->dep,user);fputs(",",user);
							fputs(tra->arr,user);fputs(",",user);
							fputs(tra->name,user);fputs(",",user);
							fprintf(user,"%c",tra->sex);fputs(",",user);
							fprintf(user,"%d",tra->age);fputs(",",user);
							fputs(tra->categ,user);fputs(",",user);
							fprintf(user,"%d",tra->userno);fputs(",",user);
							fputc('\n',user);
							tra=tra->next;
						}
						temp=temp->next;
					}
					fclose(user);



					rename("user.txt","user1.txt");

					exit(1);
			default:printf("Wrong Choice\n");
					break;
		}
	}
}