int main()
{
    printf("Welcome to Railway Resrevation\n");
    // struct detail *d[100];
    while(1)
    {
        printf("enter your choice:\n
        1.Book a ticket\n
        2.cancel a ticket\n
        3.PNR status\n
        4.Train Berth Availability\n
        5.Exit\n
        ")
        //1.doubly linked list(insert_tail).
        //2,Binary_search_tree.
        //3.doubly linked list(delete_node).
        //4.traversing array and evaluating functions.
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: static int pnr=-1;
                    pnr++;
                    struct detail *d;
                    d=getdetails(pnr);
                    enque_booking(&d,pnr);//queue formation using 
                    printf("your pnr is %d\n",pnr);
                    
            case 2: printf("enter your pnr");
                    scanf("%d",&e_pnr);
                    cancel_ticket(&d,e_pnr);//uses delete_node in doubly linked list
        }



    }
}