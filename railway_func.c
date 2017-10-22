struct detail* getdetails(int pnr)
{
    struct detail *d;
    d=(struct detail*)malloc(sizeof(struct node));
    printf("enter your name");
    scanf("%s",d->name);
    printf("enter your age");
    scanf("%d",&(d->age));
    printf("enter your gender M/F");
    scanf("%c",&(d->gender));
    printf("enter your source train departure station code");
    scanf("%s",d->source);
    printf("enter your train destination station code");
    scanf("%s",d->destination);
    printf("enter your food_type V/N");
    scanf("%c",&(d->food_type));
    printf("enter your class AC1/AC2/AC3");
    scanf("%s",d->class);
    d->pnr=pnr;
    // d->price=price_calculator(d);
    if(d->class==AC1){
        d->price=1500;
    }
    else if(d->class==AC2){
        d->price=1000;
    }
    else if(d->class==AC3){
        d->price=700;
    }//flat prices just for now 
    
    return d;

}

void enque_booking(struct detail** d,)