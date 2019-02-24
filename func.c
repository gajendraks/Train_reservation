#include "header.h"
#include<stdlib.h>

Node insert(Node first,char no[10],char dep[20],char arr[20],char d_time[10],char a_time[10],float fare,float cfare)
{
	Node temp;
	temp=(Node)malloc(sizeof(struct node));
	// strcpy(temp->c_name,c_name);
	strcpy(temp->no,no);
	strcpy(temp->dep,dep);
	strcpy(temp->arr,arr);
	strcpy(temp->d_time,d_time);
	strcpy(temp->a_time,a_time);
	temp->fare=fare;
	temp->c_fare=cfare;
	temp->next=first;
	return temp;
}

void display(Node first)
{
	if(first==NULL)
	{
		printf("There are no train details availabale\n");
		return ;
	}
	Node temp;
	temp=first;
	printf("Details of all the trains are as follow\n");
	while(temp!=NULL)
	{
		// printf("train Company name:-%s\n",temp->c_name);
		printf("train Number:-%s\n",temp->no);
		printf("Departure:-%s\n",temp->dep);
		printf("Arrival:-%s\n",temp->arr);
		printf("Departure time:-%s\n",temp->d_time);
		printf("Arrival time:-%s\n",temp->a_time);
		printf("Fare:-%f\n",temp->fare);
		printf("Child Fare:-%f\n",temp->c_fare);
		printf("<_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ >\n");
		temp=temp->next;
	}
}



User booking(Node first,User first1,int *num_of_users)
{
	int signup_login,do_while=1,chk,chk1,d,userno,num_of_passengers,i,correct_train,age,x=0,y=0,z=0;
	User temp,p,c;
	Node a,b;
	Pass tem,tra;
	char username[10],password[10],dep[20],arr[20],date[10],name[10],sex,categ[10]; 
	do
	{
		printf("1.New User first Signup\n2.Login\nEnter your choice\n");
		scanf("%d",&signup_login);
		switch(signup_login)
		{
			case 1:first1=signup(first1,num_of_users);
					printf("Now Please select Login to continue booking\n");
					break;
			case 2:temp=login(first1);
					if(temp==NULL)
					{
						printf("User wants to sign up\nPlease Sign Up first\n");
						break;
					}
					while(1)
					{
						correct_train=0;
						printf("Enter the departure place\n");
						scanf("%s",dep);
						printf("Enter the destination place\n");
						scanf("%s",arr);
						a=first;
						while((a!=NULL)&&((strcmp(a->dep,dep)!=0)||(strcmp(a->arr,arr)!=0)))
						{
							a=a->next;
						}
						if(a==NULL)
						{
							printf("No trains found with departure %s and destination %s\n",dep,arr);
							correct_train=0;
							continue;
						}	
						else
						{
							correct_train=1;
							break;
						}
					}
					if(correct_train==1)
					{
						printf("Enter the date in(dd/mm/yyyy format)\n");
						scanf("%s",date);
						d=0;
						while(d==0)
						{
							d=check_date(date);
							if(d==1)
								break;
							else if(d==0)
							{
								printf("Entered date is wrong in syntax\nPlease Enter a valid date in the specified syntax(dd/mm/yyyy)\n");
								scanf("%s",date);
							}
							else if(d==2)
							{
								printf("Entered date is wrong\nPlease Enter a valid date\n");
								scanf("%s",date);
								d=0;
							}
						}
						printf("Enter the number of passengers\n");
						scanf("%d",&num_of_passengers);
						for(i=1;i<=num_of_passengers;i++)
						{
							printf("Enter the details of Passenger %d\n",i);
							printf("Enter the name of passenger\n");
							scanf("%s",name);
							printf("Enter the gender of the passenger\n");
							scanf("%c%c",&sex,&sex);
							while(sex!='M'&&sex!='m'&&sex!='F'&&sex!='f')
							{
								printf("Entered sex is wrong\nPlease Enter the sex of the passenger\n");
								scanf("%c%c",&sex,&sex);
							}
							if(sex=='m')
								sex='M';
							if(sex=='f')
								sex='F';
							printf("Enter the age of the passenger\n");
							scanf("%d",&age);
							while(age<1)
							{
								printf("Entered age is wrong\nPlease Enter the age of the passenger\n");
								scanf("%d",&age);
							}
							userno=temp->userno;
							if(age<=3)
							{
								strcpy(categ,"Free");
								x++;
							}
							else if(age<=12)
							{
								strcpy(categ,"Child");
								y++;
							}
							else
							{
								strcpy(categ,"Adult");
								z++;
							}
							tem=(Pass)malloc(sizeof(struct passenger));
							strcat(date,"\n");
							strcpy(tem->date,date);
							strcpy(tem->dep,dep);
							strcpy(tem->arr,arr);
							strcpy(tem->name,name);
							strcpy(tem->categ,categ);
							tem->sex=sex;
							tem->age=age;
							tem->userno=userno;
							tem->next=NULL;
							if(temp->tic==NULL)
							{
								temp->tic=tem;
							}
							else
							{
								tra=temp->tic;
								while(tra->next!=NULL)
								{
									tra=tra->next;
								}
								tra->next=tem;
							}
						}
						printf("Total number of passengers of free category is %d\n",x);
						printf("Total number of passengers of Child category is %d\n",y);
						printf("Total number of passengers of Adult category is %d\n",z);
						printf("Total fare of passengers of Child category is %f\n",(y*a->c_fare));
						printf("Total fare of passengers of Adult category is %f\n",(z*a->fare));
						printf("Total fare of all passengers is %f\n",((z*a->fare)+(y*a->c_fare)));
						FILE *fp;
						fp=fopen("a.html","w+");
						fprintf(fp,"<html><head><h1>WELCOME TO ICRTC RESERVATION SYSTEM</h1></head></html>");
						// fprintf(fp,"<table><tr><th>no of passengers</th>");
						// fprintf(fp,"<td> %d </td></tr>",x);
						fclose(fp);
					}
					break;
			default:printf("Wrong choice\n");
					break;
		}
		printf("Press 1 to log in and book a ticket or book few more tickets for the same train\nPress 0 for main menu\n");
		scanf("%d",&do_while);
	}while(do_while==1);
	return first1;
}


User signup(User first1,int *num_of_users)
{
	
	User temp,p,c;
	int userno;
	char username[10],password[10];
	printf("Enter your username\n");
	scanf("%s",username);
	int check_user=0;
	while(check_user==0)
	{
		temp=first1;
		while(temp!=NULL)
		{
			if(strcmp(username,temp->username)==0)//checking if username exists
			{               
				check_user=1;
				break;//user name already exists.....so come out of while loop is user exits
			}
								
			temp=temp->next;	
		}	
		if(temp==NULL)
		{
			break;//username doesn't exists....so u can continue signing up
		}
		if(check_user==1)
		{
			printf("Same user name already exists\nPlease Enter another username\n");
			scanf("%s",username);
			check_user=0;
		}
	}
	printf("Enter the password\n");
	scanf("%s",password);
	userno=*num_of_users;
	*num_of_users+=1;
	c=(User)malloc(sizeof(struct user));
	c->userno=userno;
	strcpy(c->username,username);
	strcpy(c->password,password);
	c->tic=NULL;
	c->next=NULL;
	if(first1==NULL)
	{
		first1=c;
	}
	else
	{
		p=first1;
		while(p->next!=NULL)
			p=p->next;
		p->next=c;
	}
	return first1;
}




User login(User first1)
{
	User temp;
	int check_user,check_pwd,chk2;
	char username[10],password[10];
	printf("Enter your username\n");
	scanf("%s",username);
	printf("Enter the password\n");
	scanf("%s",password);
	check_user=0;
	while(check_user==0)
	{
		temp=first1;
		while(temp!=NULL)
		{
			if(strcmp(username,temp->username)==0)
			{
				check_user=1;
				break;
			}				
			temp=temp->next;	
		}	
		if(temp==NULL && check_user==0)
		{
			printf("Username doesn't exist\nPlease Enter a valid user name\nOr else Sign Up if You are a new user\n");	
			printf("1.Sign Up\n2.Enter the username again\nEnter your choice\n");
			scanf("%d",&chk2);
			switch(chk2)
			{
				case 1:return NULL;
						break;
				case 2:	scanf("%s",username);
						printf("Enter the password\n");
						scanf("%s",password);
						break;
				default:printf("Wrong choice\n");
						break;
			}
		}
		if(check_user==1)
		{
			break;//user exists & break from while
		}
	}
	check_pwd=0;
	while(check_pwd==0)
	{
		if(strcmp(password,temp->password)==0)
		{
			check_pwd=1;
			break;
		}
		else
		{
			printf("Password doesn't matches\nPlease Enter the correct password\n");
			scanf("%s",password);
		}
	}
	return temp;
}


int check_date(char date[])
{
    //printf("%s",date);
	int i,j=0,ctr=0,d,m,y,k;
	char dd[2],mm[2],yy[4],c;
	if(strlen(date)!=10)
		return 0;
	if(date[2]!='/'||date[5]!='/')
		return 0;
	for(i=0;i<10;i++)
	{
        c=date[i];
		if(i==2||i==5)
			continue;
		if(c>=48&&c<=57)
			continue;
		else
			return 0;
	}
	for(i=0;i<10;i++)
	{
		c=date[i];
		if(c=='/')
		{
			j=0;
			ctr++;
			continue;
		}
		else
		{
			if(ctr==0)
			{
				dd[j]=c;
				j++;
			}
			else if	(ctr==1)
			{
				mm[j]=c;
				j++;
			}
			else
			{
				yy[j]=c;
				j++;
			}
		}
	}
	d=atoi(dd);
	m=atoi(mm);
	y=atoi(yy);
	if(y<2017||m<1||m>12||d<1||d>31)
		return 2;
	if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&(d>31))
		return 2;
	if((m==4||m==6||m==9||m==11)&&(d>30))
		return 2;
	if(m==2 && d>28)
		return 2;
	else
		return 1;
}

void disp(User first1)
{
	FILE *fp;
    fp=fopen("a.html","w+");
    fprintf(fp,"<html><head><h1>WELCOME TO ICRTC RESERVATION SYSTEM</h1></head>");
	fprintf(fp,"<body>");
	
	User temp;
	temp=login(first1);
		if(temp==NULL)
		{
			printf("User wants to sign up\nSign Up first\n");
			return;
		}

	fprintf(fp,"<h3>");
    fprintf(fp,"Username");
    fprintf(fp,temp->username);
	fprintf(fp,"</h3>");
	

	Pass tem,tra;
	char date[10];
	int d,check_passenger;
	printf("Enter the date(dd/mm/yyyy syntax)\n");
	scanf("%s",date);

	fprintf(fp,"<h3>");
    fprintf(fp,"Date");
    fprintf(fp,date);
    fprintf(fp,"</h3>");

	d=0;
		while(d==0)
		{
			d=check_date(date);
			if(d==1)
				break;
			else if(d==0)
			{
				printf("Entered date is wrong in syntax\nPlease Enter a valid date in the specified syntax(dd/mm/yyyy)");
				scanf("%s",date);
			}
			else if(d==2)
			{
				printf("Entered date is wrong\nPlease Enter a valid date\n");
				scanf("%s",date);
				d=0;
			}
		}	
		check_passenger=0;
		tra=temp->tic;

		fprintf(fp,"<table>");
        fprintf(fp,"<tr>");
        fprintf(fp,"<th>");
        fprintf(fp,"slno");
        fprintf(fp,"</th>");

        fprintf(fp,"<th>");
        fprintf(fp,"Name");
        fprintf(fp,"</th>");

        fprintf(fp,"<th>");
        fprintf(fp,"Gender");
        fprintf(fp,"</th>");

        fprintf(fp,"<th>");
        fprintf(fp,"Age");
        fprintf(fp,"</th>");

        fprintf(fp,"<th>");
        fprintf(fp,"Category");
        fprintf(fp,"</th>");

        fprintf(fp,"<th>");
        fprintf(fp,"Departure");
        fprintf(fp,"</th>");

        fprintf(fp,"<th>");
        fprintf(fp,"Destination");
        fprintf(fp,"</th>");

        fprintf(fp,"</tr>");
        fprintf(fp,temp->username);

        int slno = 1;

		while(tra!=NULL)
		{
			fprintf(fp,"<tr>");
			if(compare(date,tra->date))
			{
				fprintf(fp,"<th>");
                fprintf(fp,myconv(slno,10));
                fprintf(fp,"</th>");

				check_passenger+=1;
				printf("Details of the passenger ticket is as follow\n");
				printf("Name of the Passenger is %s\n",tra->name);
				fprintf(fp,"<th>");
                fprintf(fp,tra->name);
                fprintf(fp,"</th>");

				printf("Sex of the Passenger is %c\n",tra->sex);
				if(tra->sex=='M')
                {
                    fprintf(fp,"<th>");
                    fprintf(fp,"M");
                    fprintf(fp,"</th>");
                }
                else{
                    fprintf(fp,"<th>");
                    fprintf(fp,"F");
                    fprintf(fp,"</th>");
				}
				
				printf("Age of the Passenger is %d\n",tra->age);
				fprintf(fp,"<th>");
                fprintf(fp,myconv(tra->age,10));
				fprintf(fp,"</th>");
				
				printf("Category of the Passenger is %s\n",tra->categ);
				fprintf(fp,"<th>");
                fprintf(fp,tra->categ);
				fprintf(fp,"</th>");
				
				printf("Departure place is from  %s\n",tra->dep);
				fprintf(fp,"<th>");
                fprintf(fp,tra->dep);
				fprintf(fp,"</th>");
				
				printf("Destination place is %s\n",tra->arr);
				fprintf(fp,"<th>");
                fprintf(fp,tra->arr);
                fprintf(fp,"</th>");

				printf("<_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ >");
			}
			tra=tra->next;
			slno++;
            fprintf(fp,"</tr>");
		}
		fprintf(fp,"</table>");

		if(check_passenger==0)
		{
			printf("There are no tickets booked of the user %s on date %s\n",temp->username,date);
		}
		fprintf(fp,"</body>");
        fprintf(fp,"</html>");
        fclose(fp);
}


User cancel_booking(User first1)
{
	User temp;
	temp=login(first1);
	if(temp==NULL)
	{
		printf("User wants to sign up\nSign Up first\n");
		return NULL;
	}
	Pass tem,tra,p;
	char date[10],name[10];
	int d,chk;
	printf("Enter the date(dd/mm/yyyy syntax)\n");
	scanf("%s",date);
	d=0;
		while(d==0)
		{
			d=check_date(date);
			if(d==1)
				break;
			else if(d==0)
			{
				printf("Entered date is wrong in syntax\nPlease Enter a valid date in the specified syntax(dd/mm/yyyy)");
				scanf("%s",date);
			}
			else if(d==2)
			{
				printf("Entered date is wrong\nPlease Enter a valid date\n");
				scanf("%s",date);
				d=0;
			}
		}	
		printf("Enter the name of the passenger\n");
		scanf("%s",name);
		chk=0;
		p=NULL;
		tra=temp->tic;
		if(compare(date,tra->date) && strcmp(name,tra->name)==0)
		{
			chk=1;
			printf("Details of the passenger whose ticket is to be cancelledis as follow\n");
			printf("Name of the Passenger is %s\n",tra->name);
			printf("Sex of the Passenger is %c\n",tra->sex);
			printf("Age of the Passenger is %d\n",tra->age);
			printf("Category of the Passenger is %s\n",tra->categ);
			printf("Departure place is from  %s\n",tra->dep);
			printf("Destination place is %s\n",tra->arr);
			printf("<_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ >");
			tem=temp->tic;
			temp->tic=temp->tic->next;
			free(tem);
			return first1;
		}
		while(tra!=NULL)
		{
			if(compare(date,tra->date) && strcmp(name,tra->name)==0)
			{
				chk=1;
				printf("Details of the passenger whose ticket is to be cancelled is as follow\n");
				printf("Name of the Passenger is %s\n",tra->name);
				printf("Sex of the Passenger is %c\n",tra->sex);
				printf("Age of the Passenger is %d\n",tra->age);
				printf("Category of the Passenger is %s\n",tra->categ);
				printf("Departure place is from  %s\n",tra->dep);
				printf("Destination place is %s\n",tra->arr);
				printf("<_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ >");
				tem=tra;
				tra=tra->next;
				p->next=tra;
				free(tem);
				return first1;
			}
			p=tra;
			tra=tra->next;
		}
		if(chk==0)
		{
			printf("There are no tickets of the user %s on date %s\nSo no cancellation of tickets\n",temp->username,date);
			return first1;
		}
}


int compare(char date[],char date2[])
{
	int chk=0,i;
	for(i=0;i<10;i++)
	{
		if(date[i]==date2[i])
		{
			continue;
		}
		chk=1;
	}
	if(chk==1)
		return 0;
	else
		return 1;
}


char* myconv(int val, int base){
	
	static char buf[32] = {0};
	
	int i = 30;
	
	for(; val && i ; --i, val /= base)
	
		buf[i] = "0123456789abcdef"[val % base];
	
	return &buf[i+1];
	
}


User b_signup(User first1,int *num_of_users, char *username, char *password)
{
	
	User temp,p,c;
	int userno;
	
	userno=*num_of_users;
	*num_of_users+=1;
	c=(User)malloc(sizeof(struct user));
	c->userno=userno;
	strcpy(c->username,username);
	strcpy(c->password,password);
	c->tic=NULL;
	c->next=NULL;
	if(first1==NULL)
	{
		first1=c;
	}
	else
	{
		p=first1;
		while(p->next!=NULL)
			p=p->next;
		p->next=c;
	}
	return first1;
}

Pass add_details(char *date, char *dep, char *arr, char *name, char *sex, char * age, char *categ, char * userno)
{
    Pass tem;
    tem=(Pass)malloc(sizeof(struct passenger));
    strcat(date,"\n");
    strcpy(tem->date,date);
    strcpy(tem->dep,dep);
    strcpy(tem->arr,arr);
    strcpy(tem->name,name);
    strcpy(tem->categ,categ);
    tem->sex=sex[0];
    tem->age=atoi(age);
    tem->userno=atoi(userno);
    tem->next=NULL;
    
    return tem;
}

Node delete_train(Node first, char * train_num)
{
    Node temp,prev;
    temp=first;
    prev=NULL;
    while(temp!=NULL && strcmp(temp->no,train_num)!=0)
    {
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL)
    {
        printf("train doesn't exists\n");
        return first;
    }

    else if(prev==NULL)
    {
        first=temp->next;
        return first;
    }

    else{
        prev->next=temp->next;
        return first;
    }
    free(temp);
}