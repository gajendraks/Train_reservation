#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* myconv(int , int );

struct node
{
	// char c_name[10];
	char no[10];
	char dep[20];
	char arr[20];
	char d_time[10];
	char a_time[10];
	float fare;
	float c_fare;
	struct node * next;  	
};
struct passenger
{
	char date[10];
	char dep[20];
	char arr[20];
//	int no_p;
	char name[20];
	char sex;
	int age;
	char categ[10];
	int userno;
	struct passenger * next;
};
struct user
{
	int userno;
	char username[10];
	char password[10];
	struct passenger * tic;
	struct user * next;
};
typedef struct node * Node;
typedef struct passenger * Pass;
typedef struct user * User;

Node insert(Node first,char no[10],char dep[20],char arr[20],char d_time[10],char a_time[10],float fare,float cfare);
void display(Node first);
User booking(Node first,User first1,int *k);
User signup(User first1,int *k);
User login(User first1);
int check_date(char *date);
void disp(User first1);
int compare(char date[],char date2[]);
User cancel_booking(User first1);
User b_signup(User first1,int *num_of_users, char *username, char *password);
Pass add_details(char *date, char *dep, char *arr, char *name, char *sex, char * age, char *categ, char * userno);
Node delete_train(Node first, char * train_num);