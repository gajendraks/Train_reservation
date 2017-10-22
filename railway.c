#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct bogee
{
    // int seat_num[100];
    int r_upper[10];
    int r_lower[10];
    int n_upper[20];
    int n_middle[20];
    int n_lower[20];
}
struct Train{
    int number;//train number
    // int general;//total seats in general class
    // int sleeper;//total seats in sleeper class
    struct bogee AC1;//total seats in first class
    struct bogee AC2;//total seats in second class
    struct bogee AC3;//total seats in third class
};

struct Reservation
{
    int booked_1;//seats reserved in 1st class
    int booked_2;//seats reserved in 2nd class
    int booked_3;//seats reserved in 3rd class

}
struct detail
{
    char name[100];
    int age;
    char gender;
    char source[100];
    char destination[100];
    char food_type;
    char class[20];
    int pnr;
    int train_no;
    int price;
}



