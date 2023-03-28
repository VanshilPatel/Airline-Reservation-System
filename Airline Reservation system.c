#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<malloc.h>
int register_id1=235238;
void let(int j)
{
    int i,k;
    for(i=0; i<j; i++)
        k=i;
}
void seatmap(int b[13],int c[29],int d[51])
{
    system("cls");
    system("color 2");
    printf("\n\n\t\t==>>AVAILABLE SEATS ARE..\n\n");
    printf("\n\t\t\t\t\xB2 First Class \xB2  ==>>>PRICE :- 5543/-\n\n");
    int x=1;
    for(int i=0; i<3; i++)
    {
        printf("\t\t\t\t");
        for(int j=0; j<4; j++)
        {
            if(b[x]==1)
                printf("\xB2\xB2   ");
            else if(x/10==0)
                printf("0%d   ",x);
            else
                printf("%d   ",x);
            x++;
        }
        printf("\n");
    }
    printf("\n");
    x=1;
    printf("\n\t\t\t\t\xB2 Business Class \xB2  ==>>>PRICE :- 4350/-\n\n");
    for(int i=0; i<4; i++)
    {
        printf("\t\t\t");
        for(int j=0; j<7; j++)
        {
            if(c[x]==1)
                printf("\xB2\xB2   ");
            else if(x/10==0)
                printf("0%d   ",x);
            else
                printf("%d   ",x);
            x++;
        }
        printf("\n");
    }
    printf("\n");
    x=1;
    printf("\n\t\t\t\t\xB2 Economy Class \xB2  ==>>>PRICE :- 3150/-\n\n");
    for(int i=0; i<5; i++)
    {
        printf("\t\t");
        for(int j=0; j<10; j++)
        {
            if(d[x]==1)
                printf("\xB2\xB2   ");
            else if(x/10==0)
                printf("0%d   ",x);
            else
                printf("%d   ",x);
            x++;
        }
        printf("\n");
    }
}
void payment1(int prize)
{
    long long int number;
    int cvv;
    char p[10];
    printf("----------------------------------------------------------------------");
    printf("\n\n\t\t==>>PAYMENT DETAILS..");
    printf("\n\n\t\t==>PAY %d RUPEES..\n",prize);
    printf("\n\t\t\xB2 ENTER CARD NUMBER      :- ");
    scanf("%lld",&number);
    printf("\n\t\t\xB2 ENTER CVV              :- ");
    scanf("%d",&cvv);
    printf("\n\t\t\xB2 ENTER EXP. DATE(MM/YY) :- ");
    scanf("%s",p);
    printf("\n\n\t==>>Payment under process ");
    for(int i=0; i<=12; i++)
    {
        if(i%2==0)
        {
            let(100000000);
            printf(".");
        }
        else
        {
            let(100000000);
        }
    }
    printf("\n\n\t\tPAYMENT SUCCESS..\n\n");
    system("cls");
}
struct flight_1
{
    char name[50];
    char date[13];
    int flight_no;
    int seat_no;
    char class1[15];
    int age;
    char gender[10];
    long long int mobile;
    char email[30];
    int register_id;
    int payment;
    struct flight_1 *next;
}*head=NULL;
void flight1(char s[15],char d[15])
{
    system("color 6");
    struct flight_1 *p=head;
    printf("\n\tEnter a journey date => ");
    char date[15];
    scanf("%s",date);
    printf("\n\n\t\t\tAvailble Routes..\n\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 1.   Vistara...\n");
    printf("| 10:00 => 12:05\t%s to %s\n",s,d);
    printf("| 2 h 5 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 2.   Air india...\n");
    printf("| 11:00 => 12:00\t%s to %s\n",s,d);
    printf("| 2 h 0 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 3.   Vistara...\n");
    printf("| 19:20 => 21:25\t%s to %s\n",s,d);
    printf("| 2 h 5 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 4.   Air india...\n");
    printf("| 21:00 => 23:00\t%s to %s\n",s,d);
    printf("| 2 h 0 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("\n\n\tChoose a flight no..");
    int flightnumber;
    scanf("%d",&flightnumber);
    printf("\n\n\t\tNumber of Travellers..");
    int j;
    scanf("%d",&j);
    int b[13]= {0},c[29]= {0},d1[51]= {0};
    while(p!=NULL)
    {
        if(p->class1[0]=='f' && !strcmp(p->date,date) && p->flight_no==flightnumber)
        {
            b[p->seat_no]=1;
        }
        else if(p->class1[0]=='b' && !strcmp(p->date,date) && p->flight_no==flightnumber)
        {
            c[p->seat_no]=1;
        }
        else if(p->class1[0]=='e' && !strcmp(p->date,date) && p->flight_no==flightnumber)
        {
            d1[p->seat_no]=1;
        }
        p=p->next;
    }
    seatmap(b,c,d1);
    int a[j];
    char class1[j][15];
    p=head;
    for(int i=0; i<j; i++)
    {
        printf("\n\tChoose a class for passenger %d => ",(i+1));
        char class2[15];
        scanf("%s",class2);
        strcpy(class1[i],class2);
        printf("\n\tChoose a seat for passenger %d => ",(i+1));
        int q;
        scanf("%d",&q);
        int h=0;
        while(p!=NULL)
        {
            if(p->seat_no==q)
                h++;
            if(p->flight_no==flightnumber)
                h++;
            if(!strcmp(p->class1,class2))
                h++;
            if(!strcmp(p->date,date))
                h++;
            if(h==4)
            {
                printf("\n\n\t\tINVAILD INPUT...Renter..\n");
                i--;
            }
            p=p->next;
            h=0;
        }
        if(p==NULL)
        {
            a[i]=q;
        }
        p=head;
    }
    int prize=0;
    system("cls");
    system("color 9");
    for(int i=0; i<j; i++)
    {
        struct flight_1 *t=(struct flight_1*)malloc(sizeof(struct flight_1));
        printf("\n\tEnter Detail of passanger %d...\n",(i+1));
        printf("\n\t\xB2\xB2 Name => ");
        scanf("%s",t->name);
        printf("\n\t\xB2\xB2 Age => ");
        scanf("%d",&t->age);
        printf("\n\t\xB2\xB2 Gender => ");
        scanf("%s",t->gender);
        printf("\n\t\xB2\xB2 Mobile no.. => ");
        scanf("%lld",&t->mobile);
        printf("\n\t\xB2\xB2 Email id.. => ");
        scanf("%s",t->email);
        if(class1[i][0]=='f')
        {
            t->payment=5543;
            prize+=5543;
        }
        else if(class1[i][0]=='b')
        {
            t->payment=4350;
            prize+=4350;
        }
        else
        {
            t->payment=3150;
            prize+=3150;
        }
        t->seat_no=a[i];
        t->flight_no=flightnumber;
        strcpy(t->date,date);
        strcpy(t->class1,class1[i]);
        t->register_id=register_id1;
        register_id1++;
        printf("\n\n\t\t==>> Your registration_id is.. :- %d\n\n",t->register_id);
        if(p==NULL)
        {
            head=t;
            head->next=NULL;
        }
        else
        {
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=t;
            t->next=NULL;
        }
        p=head;
    }
    payment1(prize);
}
struct flight_2
{
    char name[50];
    char date[13];
    int flight_no;
    int seat_no;
    char class1[15];
    int age;
    char gender[10];
    long long int mobile;
    char email[30];
    int register_id;
    int payment;
    struct flight_2 *next;
}*head1=NULL;
void flight2(char s[15],char d[15])
{
    system("color 6");
    struct flight_2 *p=head1;
    printf("\n\tEnter a journey date => ");
    char date[15];
    scanf("%s",date);
    printf("\n\n\t\t\tAvailble Routes..\n\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 1.   Vistara...\n");
    printf("| 10:00 => 12:05\t%s to %s\n",s,d);
    printf("| 2 h 5 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 2.   Air india...\n");
    printf("| 11:00 => 12:00\t%s to %s\n",s,d);
    printf("| 2 h 0 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 3.   Vistara...\n");
    printf("| 19:20 => 21:25\t%s to %s\n",s,d);
    printf("| 2 h 5 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 4.   Air india...\n");
    printf("| 21:00 => 23:00\t%s to %s\n",s,d);
    printf("| 2 h 0 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("\n\n\tChoose a flight no..");
    int flightnumber;
    scanf("%d",&flightnumber);
    printf("\n\n\t\tNumber of Travellers..");
    int j;
    scanf("%d",&j);
    int b[13]= {0},c[29]= {0},d1[51]= {0};
    while(p!=NULL)
    {
        if(p->class1[0]=='f' && !strcmp(p->date,date) && p->flight_no==flightnumber)
        {
            b[p->seat_no]=1;
        }
        else if(p->class1[0]=='b' && !strcmp(p->date,date) && p->flight_no==flightnumber)
        {
            c[p->seat_no]=1;
        }
        else if(p->class1[0]=='e' && !strcmp(p->date,date) && p->flight_no==flightnumber)
        {
            d1[p->seat_no]=1;
        }
        p=p->next;
    }
    seatmap(b,c,d1);
    int a[j];
    char class1[j][15];
    p=head1;
    for(int i=0; i<j; i++)
    {
        printf("\n\tChoose a class for passanger %d => ",(i+1));
        char class2[15];
        scanf("%s",class2);
        strcpy(class1[i],class2);
        printf("\n\tChoose a seat for passanger %d => ",(i+1));
        int q;
        scanf("%d",&q);
        int h=0;
        while(p!=NULL)
        {
            if(p->seat_no==q)
                h++;
            if(p->flight_no==flightnumber)
                h++;
            if(!strcmp(p->class1,class2))
                h++;
            if(!strcmp(p->date,date))
                h++;
            if(h==4)
            {
                printf("\n\n\t\tINVAILD INPUT...Renter..\n");
                i--;
            }
            p=p->next;
            h=0;
        }
        if(p==NULL)
        {
            a[i]=q;
        }
        p=head1;
    }
    int prize=0;
    system("cls");
    system("color 9");
    for(int i=0; i<j; i++)
    {
        struct flight_2 *t=(struct flight_2*)malloc(sizeof(struct flight_2));
        printf("\n\tEnter Detail of passanger %d...\n",(i+1));
        printf("\n\t\xB2\xB2 Name => ");
        scanf("%s",t->name);
        printf("\n\t\xB2\xB2 Age => ");
        scanf("%d",&t->age);
        printf("\n\t\xB2\xB2 Gender => ");
        scanf("%s",t->gender);
        printf("\n\t\xB2\xB2 Mobile no.. => ");
        scanf("%lld",&t->mobile);
        printf("\n\t\xB2\xB2 Email id.. => ");
        scanf("%s",t->email);
        if(class1[i][0]=='f')
        {
            t->payment=5543;
            prize+=5543;
        }
        else if(class1[i][0]=='b')
        {
            t->payment=4350;
            prize+=4350;
        }
        else
        {
            t->payment=3150;
            prize+=3150;
        }
        t->seat_no=a[i];
        t->flight_no=flightnumber;
        strcpy(t->date,date);
        strcpy(t->class1,class1[i]);
        t->register_id=register_id1;
        register_id1++;
        printf("\n\n\t\t==>> Your registration_id is.. :- %d\n\n",t->register_id);
        if(p==NULL)
        {
            head1=t;
            head1->next=NULL;
        }
        else
        {
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=t;
            t->next=NULL;
        }
        p=head1;
    }
    payment1(prize);
}
struct flight_3
{
    char name[50];
    char date[13];
    int flight_no;
    int seat_no;
    char class1[15];
    int age;
    char gender[10];
    long long int mobile;
    char email[30];
    int register_id;
    int payment;
    struct flight_3 *next;
}*head2=NULL;
void flight3(char s[15],char d[15])
{
    system("color 6");
    struct flight_3 *p=head2;
    printf("\n\tEnter a journey date => ");
    char date[15];
    scanf("%s",date);
    printf("\n\n\t\t\tAvailble Routes..\n\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 1.   Vistara...\n");
    printf("| 10:00 => 12:05\t%s to %s\n",s,d);
    printf("| 2 h 5 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 2.   Air india...\n");
    printf("| 11:00 => 12:00\t%s to %s\n",s,d);
    printf("| 2 h 0 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 3.   Vistara...\n");
    printf("| 19:20 => 21:25\t%s to %s\n",s,d);
    printf("| 2 h 5 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 4.   Air india...\n");
    printf("| 21:00 => 23:00\t%s to %s\n",s,d);
    printf("| 2 h 0 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("\n\n\tChoose a flight no..");
    int flightnumber;
    scanf("%d",&flightnumber);
    printf("\n\n\t\tNumber of Travellers..");
    int j;
    scanf("%d",&j);
    int b[13]= {0},c[29]= {0},d1[51]= {0};
    while(p!=NULL)
    {
        if(p->class1[0]=='f' && !strcmp(p->date,date) && p->flight_no==flightnumber)
        {
            b[p->seat_no]=1;
        }
        else if(p->class1[0]=='b' && !strcmp(p->date,date) && p->flight_no==flightnumber)
        {
            c[p->seat_no]=1;
        }
        else if(p->class1[0]=='e' && !strcmp(p->date,date) && p->flight_no==flightnumber)
        {
            d1[p->seat_no]=1;
        }
        p=p->next;
    }
    seatmap(b,c,d1);
    int a[j];
    char class1[j][15];
    p=head2;
    for(int i=0; i<j; i++)
    {
        printf("\n\tChoose a class for passanger %d => ",(i+1));
        char class2[15];
        scanf("%s",class2);
        strcpy(class1[i],class2);
        printf("\n\tChoose a seat for passanger %d => ",(i+1));
        int q;
        scanf("%d",&q);
        int h=0;
        while(p!=NULL)
        {
            if(p->seat_no==q)
                h++;
            if(p->flight_no==flightnumber)
                h++;
            if(!strcmp(p->class1,class2))
                h++;
            if(!strcmp(p->date,date))
                h++;
            if(h==4)
            {
                printf("\n\n\t\tINVAILD INPUT...Renter..\n");
                i--;
            }
            p=p->next;
            h=0;
        }
        if(p==NULL)
        {
            a[i]=q;
        }
        p=head2;
    }
    int prize=0;
    system("cls");
    system("color 9");
    for(int i=0; i<j; i++)
    {
        struct flight_3 *t=(struct flight_3*)malloc(sizeof(struct flight_3));
        printf("\n\tEnter Detail of passanger %d...\n",(i+1));
        printf("\n\t\xB2\xB2 Name => ");
        scanf("%s",t->name);
        printf("\n\t\xB2\xB2 Age => ");
        scanf("%d",&t->age);
        printf("\n\t\xB2\xB2 Gender => ");
        scanf("%s",t->gender);
        printf("\n\t\xB2\xB2 Mobile no.. => ");
        scanf("%lld",&t->mobile);
        printf("\n\t\xB2\xB2 Email id.. => ");
        scanf("%s",t->email);
        if(class1[i][0]=='f')
        {
            t->payment=5543;
            prize+=5543;
        }
        else if(class1[i][0]=='b')
        {
            t->payment=4350;
            prize+=4350;
        }
        else
        {
            t->payment=3150;
            prize+=3150;
        }
        t->seat_no=a[i];
        t->flight_no=flightnumber;
        strcpy(t->date,date);
        strcpy(t->class1,class1[i]);
        t->register_id=register_id1;
        register_id1++;
        printf("\n\n\t\t==>> Your registration_id is.. :- %d\n\n",t->register_id);
        if(p==NULL)
        {
            head2=t;
            head2->next=NULL;
        }
        else
        {
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=t;
            t->next=NULL;
        }
        p=head2;
    }
    payment1(prize);
}
struct flight_4
{
    char name[50];
    char date[13];
    int flight_no;
    int seat_no;
    char class1[15];
    int age;
    char gender[10];
    long long int mobile;
    char email[30];
    int register_id;
    int payment;
    struct flight_4 *next;
}*head3=NULL;
void flight4(char s[15],char d[15])
{
    system("color 6");
    struct flight_4 *p=head3;
    printf("\n\tEnter a journey date => ");
    char date[15];
    scanf("%s",date);
    printf("\n\n\t\t\tAvailble Routes..\n\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 1.   Vistara...\n");
    printf("| 10:00 => 12:05\t%s to %s\n",s,d);
    printf("| 2 h 5 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 2.   Air india...\n");
    printf("| 11:00 => 12:00\t%s to %s\n",s,d);
    printf("| 2 h 0 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 3.   Vistara...\n");
    printf("| 19:20 => 21:25\t%s to %s\n",s,d);
    printf("| 2 h 5 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 4.   Air india...\n");
    printf("| 21:00 => 23:00\t%s to %s\n",s,d);
    printf("| 2 h 0 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("\n\n\tChoose a flight no..");
    int flightnumber;
    scanf("%d",&flightnumber);
    printf("\n\n\t\tNumber of Travellers..");
    int j;
    scanf("%d",&j);
    int b[13]= {0},c[29]= {0},d1[51]= {0};
    while(p!=NULL)
    {
        if(p->class1[0]=='f' && !strcmp(p->date,date) && p->flight_no==flightnumber)
        {
            b[p->seat_no]=1;
        }
        else if(p->class1[0]=='b' && !strcmp(p->date,date) && p->flight_no==flightnumber)
        {
            c[p->seat_no]=1;
        }
        else if(p->class1[0]=='e' && !strcmp(p->date,date) && p->flight_no==flightnumber)
        {
            d1[p->seat_no]=1;
        }
        p=p->next;
    }
    seatmap(b,c,d1);
    int a[j];
    char class1[j][15];
    p=head3;
    for(int i=0; i<j; i++)
    {
        printf("\n\tChoose a class for passanger %d => ",(i+1));
        char class2[15];
        scanf("%s",class2);
        strcpy(class1[i],class2);
        printf("\n\tChoose a seat for passanger %d => ",(i+1));
        int q;
        scanf("%d",&q);
        int h=0;
        while(p!=NULL)
        {
            if(p->seat_no==q)
                h++;
            if(p->flight_no==flightnumber)
                h++;
            if(!strcmp(p->class1,class2))
                h++;
            if(!strcmp(p->date,date))
                h++;
            if(h==4)
            {
                printf("\n\n\t\tINVAILD INPUT...Renter..\n");
                i--;
            }
            p=p->next;
            h=0;
        }
        if(p==NULL)
        {
            a[i]=q;
        }
        p=head3;
    }
    int prize=0;
    system("cls");
    system("color 9");
    for(int i=0; i<j; i++)
    {
        struct flight_4 *t=(struct flight_4*)malloc(sizeof(struct flight_4));
        printf("\n\tEnter Detail of passanger %d...\n",(i+1));
        printf("\n\t\xB2\xB2 Name => ");
        scanf("%s",t->name);
        printf("\n\t\xB2\xB2 Age => ");
        scanf("%d",&t->age);
        printf("\n\t\xB2\xB2 Gender => ");
        scanf("%s",t->gender);
        printf("\n\t\xB2\xB2 Mobile no.. => ");
        scanf("%lld",&t->mobile);
        printf("\n\t\xB2\xB2 Email id.. => ");
        scanf("%s",t->email);
        if(class1[i][0]=='f')
        {
            t->payment=5543;
            prize+=5543;
        }
        else if(class1[i][0]=='b')
        {
            t->payment=4350;
            prize+=4350;
        }
        else
        {
            t->payment=3150;
            prize+=3150;
        }
        t->seat_no=a[i];
        t->flight_no=flightnumber;
        strcpy(t->date,date);
        strcpy(t->class1,class1[i]);
        t->register_id=register_id1;
        register_id1++;
        printf("\n\n\t\t==>> Your registration_id is.. :- %d\n\n",t->register_id);
        if(p==NULL)
        {
            head3=t;
            head3->next=NULL;
        }
        else
        {
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=t;
            t->next=NULL;
        }
        p=head3;
    }
    payment1(prize);
}
struct flight_5
{
    char name[50];
    char date[13];
    int flight_no;
    int seat_no;
    char class1[15];
    int age;
    char gender[10];
    long long int mobile;
    char email[30];
    int register_id;
    int payment;
    struct flight_5 *next;
}*head4=NULL;
void flight5(char s[15],char d[15])
{
    system("color 6");
    struct flight_5 *p=head4;
    printf("\n\tEnter a journey date => ");
    char date[15];
    scanf("%s",date);
    printf("\n\n\t\t\tAvailble Routes..\n\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 1.   Vistara...\n");
    printf("| 10:00 => 12:05\t%s to %s\n",s,d);
    printf("| 2 h 5 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 2.   Air india...\n");
    printf("| 11:00 => 12:00\t%s to %s\n",s,d);
    printf("| 2 h 0 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 3.   Vistara...\n");
    printf("| 19:20 => 21:25\t%s to %s\n",s,d);
    printf("| 2 h 5 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 4.   Air india...\n");
    printf("| 21:00 => 23:00\t%s to %s\n",s,d);
    printf("| 2 h 0 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("\n\n\tChoose a flight no..");
    int flightnumber;
    scanf("%d",&flightnumber);
    printf("\n\n\t\tNumber of Travellers..");
    int j;
    scanf("%d",&j);
    int b[13]= {0},c[29]= {0},d1[51]= {0};
    while(p!=NULL)
    {
        if(p->class1[0]=='f' && !strcmp(p->date,date) && p->flight_no==flightnumber)
        {
            b[p->seat_no]=1;
        }
        else if(p->class1[0]=='b' && !strcmp(p->date,date) && p->flight_no==flightnumber)
        {
            c[p->seat_no]=1;
        }
        else if(p->class1[0]=='e' && !strcmp(p->date,date) && p->flight_no==flightnumber)
        {
            d1[p->seat_no]=1;
        }
        p=p->next;
    }
    seatmap(b,c,d1);
    int a[j];
    char class1[j][15];
    p=head4;
    for(int i=0; i<j; i++)
    {
        printf("\n\tChoose a class for passanger %d => ",(i+1));
        char class2[15];
        scanf("%s",class2);
        strcpy(class1[i],class2);
        printf("\n\tChoose a seat for passanger %d => ",(i+1));
        int q;
        scanf("%d",&q);
        int h=0;
        while(p!=NULL)
        {
            if(p->seat_no==q)
                h++;
            if(p->flight_no==flightnumber)
                h++;
            if(!strcmp(p->class1,class2))
                h++;
            if(!strcmp(p->date,date))
                h++;
            if(h==4)
            {
                printf("\n\n\t\tINVAILD INPUT...Renter..\n");
                i--;
            }
            p=p->next;
            h=0;
        }
        if(p==NULL)
        {
            a[i]=q;
        }
        p=head4;
    }
    int prize=0;
    system("cls");
    system("color 9");
    for(int i=0; i<j; i++)
    {
        struct flight_5 *t=(struct flight_5*)malloc(sizeof(struct flight_5));
        printf("\n\tEnter Detail of passanger %d...\n",(i+1));
        printf("\n\t\xB2\xB2 Name => ");
        scanf("%s",t->name);
        printf("\n\t\xB2\xB2 Age => ");
        scanf("%d",&t->age);
        printf("\n\t\xB2\xB2 Gender => ");
        scanf("%s",t->gender);
        printf("\n\t\xB2\xB2 Mobile no.. => ");
        scanf("%lld",&t->mobile);
        printf("\n\t\xB2\xB2 Email id.. => ");
        scanf("%s",t->email);
        if(class1[i][0]=='f')
        {
            t->payment=5543;
            prize+=5543;
        }
        else if(class1[i][0]=='b')
        {
            t->payment=4350;
            prize+=4350;
        }
        else
        {
            t->payment=3150;
            prize+=3150;
        }
        t->seat_no=a[i];
        t->flight_no=flightnumber;
        strcpy(t->date,date);
        strcpy(t->class1,class1[i]);
        t->register_id=register_id1;
        register_id1++;
        printf("\n\n\t\t==>> Your registration_id is.. :- %d\n\n",t->register_id);
        if(p==NULL)
        {
            head4=t;
            head4->next=NULL;
        }
        else
        {
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=t;
            t->next=NULL;
        }
        p=head4;
    }
    payment1(prize);
}
struct flight_6
{
    char name[50];
    char date[13];
    int flight_no;
    int seat_no;
    char class1[15];
    int age;
    char gender[10];
    long long int mobile;
    char email[30];
    int register_id;
    int payment;
    struct flight_6 *next;
}*head5=NULL;
void flight6(char s[15],char d[15])
{
    system("color 6");
    struct flight_6 *p=head5;
    printf("\n\tEnter a journey date => ");
    char date[15];
    scanf("%s",date);
    printf("\n\n\t\t\tAvailble Routes..\n\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 1.   Vistara...\n");
    printf("| 10:00 => 12:05\t%s to %s\n",s,d);
    printf("| 2 h 5 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 2.   Air india...\n");
    printf("| 11:00 => 12:00\t%s to %s\n",s,d);
    printf("| 2 h 0 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 3.   Vistara...\n");
    printf("| 19:20 => 21:25\t%s to %s\n",s,d);
    printf("| 2 h 5 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("------------------------------------------");
    printf("\n|\n");
    printf("| 4.   Air india...\n");
    printf("| 21:00 => 23:00\t%s to %s\n",s,d);
    printf("| 2 h 0 m\t\t=>Non-stop");
    printf("\n|\n");
    printf("_____________________________________\n");
    printf("\n\n\tChoose a flight no..");
    int flightnumber;
    scanf("%d",&flightnumber);
    printf("\n\n\t\tNumber of Travellers..");
    int j;
    scanf("%d",&j);
    int b[13]= {0},c[29]= {0},d1[51]= {0};
    while(p!=NULL)
    {
        if(p->class1[0]=='f' && !strcmp(p->date,date) && p->flight_no==flightnumber)
        {
            b[p->seat_no]=1;
        }
        else if(p->class1[0]=='b' && !strcmp(p->date,date) && p->flight_no==flightnumber)
        {
            c[p->seat_no]=1;
        }
        else if(p->class1[0]=='e' && !strcmp(p->date,date) && p->flight_no==flightnumber)
        {
            d1[p->seat_no]=1;
        }
        p=p->next;
    }
    seatmap(b,c,d1);
    int a[j];
    char class1[j][15];
    p=head5;
    for(int i=0; i<j; i++)
    {
        printf("\n\tChoose a class for passanger %d => ",(i+1));
        char class2[15];
        scanf("%s",class2);
        strcpy(class1[i],class2);
        printf("\n\tChoose a seat for passanger %d => ",(i+1));
        int q;
        scanf("%d",&q);
        int h=0;
        while(p!=NULL)
        {
            if(p->seat_no==q)
                h++;
            if(p->flight_no==flightnumber)
                h++;
            if(!strcmp(p->class1,class2))
                h++;
            if(!strcmp(p->date,date))
                h++;
            if(h==4)
            {
                printf("\n\n\t\tINVAILD INPUT...Renter..\n");
                i--;
            }
            p=p->next;
            h=0;
        }
        if(p==NULL)
        {
            a[i]=q;
        }
        p=head5;
    }
    int prize=0;
    system("cls");
    system("color 9");
    for(int i=0; i<j; i++)
    {
        struct flight_6 *t=(struct flight_6*)malloc(sizeof(struct flight_6));
        printf("\n\tEnter Detail of passanger %d...\n",(i+1));
        printf("\n\t\xB2\xB2 Name => ");
        scanf("%s",t->name);
        printf("\n\t\xB2\xB2 Age => ");
        scanf("%d",&t->age);
        printf("\n\t\xB2\xB2 Gender => ");
        scanf("%s",t->gender);
        printf("\n\t\xB2\xB2 Mobile no.. => ");
        scanf("%lld",&t->mobile);
        printf("\n\t\xB2\xB2 Email id.. => ");
        scanf("%s",t->email);
        if(class1[i][0]=='f')
        {
            t->payment=5543;
            prize+=5543;
        }
        else if(class1[i][0]=='b')
        {
            t->payment=4350;
            prize+=4350;
        }
        else
        {
            t->payment=3150;
            prize+=3150;
        }
        t->seat_no=a[i];
        t->flight_no=flightnumber;
        strcpy(t->date,date);
        strcpy(t->class1,class1[i]);
        t->register_id=register_id1;
        register_id1++;
        printf("\n\n\t\t==>> Your registration_id is.. :- %d\n\n",t->register_id);
        if(p==NULL)
        {
            head5=t;
            head5->next=NULL;
        }
        else
        {
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=t;
            t->next=NULL;
        }
        p=head5;
    }
    payment1(prize);
}
void oneway(char flight[8][50])
{
    printf("\t\t\tAvailble Routes..\n\n\n");
    for(int i=0; i<8; i++)
    {
        printf("%s\n",flight[i]);
    }
    printf("\t\tChoose a option..");
    int opt3;
    scanf("%d",&opt3);
    if(opt3==1)
    {
        system("cls");
        flight1("Ahmedabad","Surat");
    }
    else if(opt3==2)
    {
        system("cls");
        flight2("Ahmedabad","Delhi");
    }
    else if(opt3==3)
    {
        system("cls");
        flight3("Surat","Mumbai");
    }
    else if(opt3==4)
    {
        system("cls");
        flight4("Surat","Ahmedabad");
    }
    else if(opt3==5)
    {
        system("cls");
        flight5("Delhi","Ahmedabad");
    }
    else
    {
        system("cls");
        flight6("Mumbai","Surat");
    }

}
void roundtrip(char flight[8][50])
{
    printf("\t\t\tAvailble Routes..\n\n\n");
    for(int i=0; i<8; i++)
    {
        printf("%s\n",flight[i]);
    }
    printf("\t\tChoose a option..");
    int opt3;
    scanf("%d",&opt3);
    if(opt3==1)
    {
        system("cls");
        flight1("Ahmedabad","Surat");
        printf("\n\n\t\t=>BOOK a return ticket..\n\n");
        flight4("Surat","Ahmedabad");
    }
    else if(opt3==2)
    {
        system("cls");
        flight2("Ahmedabad","Delhi");
        printf("\n\n\t\t=>BOOK a return ticket..\n\n");
        flight5("Delhi","Ahmedabad");
    }
    else if(opt3==3)
    {
        system("cls");
        flight3("Surat","Mumbai");
        printf("\n\n\t\t=>BOOK a return ticket..\n\n");
        flight6("Mumbai","Surat");
    }
    else if(opt3==4)
    {
        system("cls");
        flight4("Surat","Ahmedabad");
        printf("\n\n\t\t=>BOOK a return ticket..\n\n");
        flight1("Ahmedabad","Surat");
    }
    else if(opt3==5)
    {
        system("cls");
        flight5("Delhi","Ahmedabad");
        printf("\n\n\t\t=>BOOK a return ticket..\n\n");
        flight2("Ahmedabad","Delhi");
    }
    else
    {
        system("cls");
        flight6("Mumbai","Surat");
        printf("\n\n\t\t=>BOOK a return ticket..\n\n");
        flight3("Surat","Mumbai");
    }

}
void download()
{
    printf("\n\n\n\tEnter a mobile no...");
    long long int mobile;
    scanf("%lld",&mobile);
    int count=0;
    struct flight_1 *p=head;
    while(p!=NULL)
    {
        if(p->mobile==mobile)
        {
            printf("\n\n--------------------------------------------------------------\n");
            printf("|  FROM           :- Ahmedabad\n");
            printf("|  TO             :- Surat\n");
            printf("|  NAME           :- %s\n",p->name);
            printf("|  DATE           :- %s\n",p->date);
            printf("|  MOBILE_NO..    :- %lld\n",p->mobile);
            printf("|  EMAIL          :- %s\n",p->email);
            printf("|\n");
            printf("|  FLIGHT_NO..    :- %d\n",p->flight_no);
            printf("|  CLASS          :- %s\n",p->class1);
            printf("|  SEAT_NO..      :- %d\n",p->seat_no);
            if(p->flight_no==1)
                printf("|  DEPARTURE_TIME :- 10:00\n");
            else if(p->flight_no==2)
                printf("|  DEPARTURE_TIME :- 11:00\n");
            else if(p->flight_no==3)
                printf("|  DEPARTURE_TIME :- 19:20\n");
            else
                printf("|  DEPARTURE_TIME :- 21:00\n");
            printf("|  PRICE          :- %d\n",p->payment);
            printf("|  STATUS         :- SUCCESS\n");
            printf("--------------------------------------------------------------\n");
            count++;
        }
        p=p->next;
    }
    struct flight_2 *p1=head1;
    while(p1!=NULL)
    {
        if(p1->mobile==mobile)
        {
            printf("\n\n--------------------------------------------------------------\n");
            printf("|  FROM           :- Ahmedabad\n");
            printf("|  TO             :- Delhi\n");
            printf("|  NAME           :- %s\n",p1->name);
            printf("|  DATE           :- %s\n",p1->date);
            printf("|  MOBILE_NO..    :- %lld\n",p1->mobile);
            printf("|  EMAIL          :- %s\n",p1->email);
            printf("|\n");
            printf("|  FLIGHT_NO..    :- %d\n",p1->flight_no);
            printf("|  CLASS          :- %s\n",p1->class1);
            printf("|  SEAT_NO..      :- %d\n",p1->seat_no);
            if(p1->flight_no==1)
                printf("|  DEPARTURE_TIME :- 10:00\n");
            else if(p1->flight_no==2)
                printf("|  DEPARTURE_TIME :- 11:00\n");
            else if(p1->flight_no==3)
                printf("|  DEPARTURE_TIME :- 19:20\n");
            else
                printf("|  DEPARTURE_TIME :- 21:00\n");
            printf("|  PRICE          :- %d\n",p1->payment);
            printf("|  STATUS         :- SUCCESS\n");
            printf("--------------------------------------------------------------\n");
            count++;
        }
        p1=p1->next;
    }
    struct flight_3 *p2=head2;
    while(p2!=NULL)
    {
        if(p2->mobile==mobile)
        {
            printf("\n\n--------------------------------------------------------------\n");
            printf("|  FROM           :- Surat\n");
            printf("|  TO             :- Mumbai\n");
            printf("|  NAME           :- %s\n",p2->name);
            printf("|  DATE           :- %s\n",p2->date);
            printf("|  MOBILE_NO..    :- %lld\n",p2->mobile);
            printf("|  EMAIL          :- %s\n",p2->email);
            printf("|\n");
            printf("|  FLIGHT_NO..    :- %d\n",p2->flight_no);
            printf("|  CLASS          :- %s\n",p2->class1);
            printf("|  SEAT_NO..      :- %d\n",p2->seat_no);
            if(p2->flight_no==1)
                printf("|  DEPARTURE_TIME :- 10:00\n");
            else if(p2->flight_no==2)
                printf("|  DEPARTURE_TIME :- 11:00\n");
            else if(p2->flight_no==3)
                printf("|  DEPARTURE_TIME :- 19:20\n");
            else
                printf("|  DEPARTURE_TIME :- 21:00\n");
            printf("|  PRICE          :- %d\n",p2->payment);
            printf("|  STATUS         :- SUCCESS\n");
            printf("--------------------------------------------------------------\n");
            count++;
        }
        p2=p2->next;
    }
    struct flight_4 *p3=head3;
    while(p3!=NULL)
    {
        if(p3->mobile==mobile)
        {
            printf("\n\n--------------------------------------------------------------\n");
            printf("|  FROM           :- Surat\n");
            printf("|  TO             :- AhmedabadSurat\n");
            printf("|  NAME           :- %s\n",p3->name);
            printf("|  DATE           :- %s\n",p3->date);
            printf("|  MOBILE_NO..    :- %lld\n",p3->mobile);
            printf("|  EMAIL          :- %s\n",p3->email);
            printf("|\n");
            printf("|  FLIGHT_NO..    :- %d\n",p3->flight_no);
            printf("|  CLASS          :- %s\n",p3->class1);
            printf("|  SEAT_NO..      :- %d\n",p3->seat_no);
            if(p3->flight_no==1)
                printf("|  DEPARTURE_TIME :- 10:00\n");
            else if(p3->flight_no==2)
                printf("|  DEPARTURE_TIME :- 11:00\n");
            else if(p3->flight_no==3)
                printf("|  DEPARTURE_TIME :- 19:20\n");
            else
                printf("|  DEPARTURE_TIME :- 21:00\n");
            printf("|  PRICE          :- %d\n",p3->payment);
            printf("|  STATUS         :- SUCCESS\n");
            printf("--------------------------------------------------------------\n");
            count++;
        }
        p3=p3->next;
    }
    struct flight_5 *p4=head4;
    while(p4!=NULL)
    {
        if(p4->mobile==mobile)
        {
            printf("\n\n--------------------------------------------------------------\n");
            printf("|  FROM           :- Delhi\n");
            printf("|  TO             :- Ahmedabad\n");
            printf("|  NAME           :- %s\n",p4->name);
            printf("|  DATE           :- %s\n",p4->date);
            printf("|  MOBILE_NO..    :- %lld\n",p4->mobile);
            printf("|  EMAIL          :- %s\n",p4->email);
            printf("|\n");
            printf("|  FLIGHT_NO..    :- %d\n",p4->flight_no);
            printf("|  CLASS          :- %s\n",p4->class1);
            printf("|  SEAT_NO..      :- %d\n",p4->seat_no);
            if(p4->flight_no==1)
                printf("|  DEPARTURE_TIME :- 10:00\n");
            else if(p4->flight_no==2)
                printf("|  DEPARTURE_TIME :- 11:00\n");
            else if(p4->flight_no==3)
                printf("|  DEPARTURE_TIME :- 19:20\n");
            else
                printf("|  DEPARTURE_TIME :- 21:00\n");
            printf("|  PRIZE          :- %d\n",p4->payment);
            printf("|  STATUS         :- SUCCESS\n");
            printf("--------------------------------------------------------------\n");
            count++;
        }
        p4=p4->next;
    }
    struct flight_6 *p5=head5;
    while(p5!=NULL)
    {
        if(p5->mobile==mobile)
        {
            printf("\n\n--------------------------------------------------------------\n");
            printf("|  FROM           :- Mumbai\n");
            printf("|  TO             :- Surat\n");
            printf("|  NAME           :- %s\n",p5->name);
            printf("|  DATE           :- %s\n",p5->date);
            printf("|  MOBILE_NO..    :- %lld\n",p5->mobile);
            printf("|  EMAIL          :- %s\n",p5->email);
            printf("|\n");
            printf("|  FLIGHT_NO..    :- %d\n",p5->flight_no);
            printf("|  CLASS          :- %s\n",p5->class1);
            printf("|  SEAT_NO..      :- %d\n",p5->seat_no);
            if(p5->flight_no==1)
                printf("|  DEPARTURE_TIME :- 10:00\n");
            else if(p5->flight_no==2)
                printf("|  DEPARTURE_TIME :- 11:00\n");
            else if(p5->flight_no==3)
                printf("|  DEPARTURE_TIME :- 19:20\n");
            else
                printf("|  DEPARTURE_TIME :- 21:00\n");
            printf("|  PRICE          :- %d\n",p5->payment);
            printf("|  STATUS         :- SUCCESS\n");
            printf("--------------------------------------------------------------\n");
            count++;
        }
        p5=p5->next;
    }
    if(count==0)
    {
        printf("\n\n\t\t==>>Ticket is not found...\n\n");
    }

}
void cancel()
{
    printf("\n\n\n\tEnter a mobile no...");
    long long int mobile;
    scanf("%lld",&mobile);
    printf("\n\n\tEnter a registration_no.. :-");
    int register_no;
    scanf("%d",&register_no);
    int count=0;
    struct flight_1 *p=head;
    while(p!=NULL)
    {
        if(p->mobile==mobile && p->register_id==register_no)
        {
            struct flight_1 *z1=p->next,*z2=p;
            p=head;
            while(p!=NULL)
            {
                if(p=z2)
                {
                    head=z1;
                    free(z1);
                    free(z2);
                    break;
                }
                else if(p->next==z2)
                {
                    p->next=z1;
                    free(z1);
                    free(z2);
                    break;
                }
                p=p->next;
            }
            count++;
            break;
        }
        p=p->next;
    }
    struct flight_2 *p1=head1;
    while(p1!=NULL)
    {
        if(p1->mobile==mobile && p1->register_id==register_no)
        {
            struct flight_2 *z1=p1->next,*z2=p1;
            p1=head1;
            while(p1!=NULL)
            {
                if(p1=z2)
                {
                    head1=z1;
                    free(z1);
                    free(z2);
                    break;
                }
                else if(p1->next==z2)
                {
                    p1->next=z1;
                    free(z1);
                    free(z2);
                    break;
                }
                p1=p1->next;
            }
            count++;
            break;
        }
        p1=p1->next;
    }
    struct flight_3 *p2=head2;
    while(p2!=NULL)
    {
        if(p2->mobile==mobile && p2->register_id==register_no)
        {
            struct flight_3 *z1=p2->next,*z2=p2;
            p2=head2;
            while(p2!=NULL)
            {
                if(p2=z2)
                {
                    head2=z1;
                    free(z1);
                    free(z2);
                    break;
                }
                else if(p2->next==z2)
                {
                    p2->next=z1;
                    free(z1);
                    free(z2);
                    break;
                }
                p2=p2->next;
            }
            count++;
            break;
        }
        p2=p2->next;
    }
    struct flight_4 *p3=head3;
    while(p3!=NULL)
    {
        if(p3->mobile==mobile && p3->register_id==register_no)
        {
            struct flight_4 *z1=p3->next,*z2=p3;
            p3=head3;
            while(p3!=NULL)
            {
                if(p3=z2)
                {
                    head3=z1;
                    free(z1);
                    free(z2);
                    break;
                }
                else if(p3->next==z2)
                {
                    p3->next=z1;
                    free(z1);
                    free(z2);
                    break;
                }
                p3=p3->next;
            }
            count++;
            break;
        }
        p3=p3->next;
    }
    struct flight_5 *p4=head4;
    while(p4!=NULL)
    {
        if(p4->mobile==mobile && p4->register_id==register_no)
        {
            struct flight_5 *z1=p4->next,*z2=p4;
            p4=head4;
            while(p4!=NULL)
            {
                if(p4=z2)
                {
                    head4=z1;
                    free(z1);
                    free(z2);
                    break;
                }
                else if(p4->next==z2)
                {
                    p4->next=z1;
                    free(z1);
                    free(z2);
                    break;
                }
                p4=p4->next;
            }
            count++;
            break;
        }
        p4=p4->next;
    }
    struct flight_6 *p5=head5;
    while(p5!=NULL)
    {
        if(p5->mobile==mobile && p5->register_id==register_no)
        {
            struct flight_6 *z1=p5->next,*z2=p5;
            p5=head5;
            while(p5!=NULL)
            {
                if(p5=z2)
                {
                    head5=z1;
                    free(z1);
                    free(z2);
                    break;
                }
                else if(p5->next==z2)
                {
                    p5->next=z1;
                    free(z1);
                    free(z2);
                    break;
                }
                p5=p5->next;
            }
            count++;
            break;
        }
        p5=p5->next;
    }
    if(count==0)
    {
        printf("\n\n\t\t==>>Booking is not found..Try again..\n\n");
    }
    else
    {
        printf("\n\n\t\t==>>Ticket cancle successfully..\n\n");
    }
}
int main()
{
     while(1)
    {
    printf("\n\n\t\t\t\t\t\t-----------------------");
    printf("\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MakeMyTrip \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\t\t\t\t-----------------------");
    char flight[8][50]= {"1.Ahmedabad->Surat","2.Ahmedabad->Delhi","3.Surat->Mumbai","4.Surat->Ahmedabad","5.Delhi->Ahmedabad","6.Mumbai->Surat"};
        printf("\n\n\n");
        printf("1.   Book a ticket\n2.   Download a ticket\n3.   Cancle a ticket\n4.   Exit");
        printf("\n\n\t\tchoose option..");
        int opt;
        scanf("%d",&opt);
        if(opt==1)
        {+

            printf("Type of Trip..\n\n\n");
            printf("1.   One Way\n2.   Round Trip\n");
            printf("\n\n\t\tchoose option..");
            int opt1;
            scanf("%d",&opt1);
            if(opt1==1)
            {
                oneway(flight);
            }
            else
            {
                roundtrip(flight);
            }
        }
        else if(opt==2)
        {
            download();
        }
        else if(opt==3)
        {
            cancel();
        }
        else
        {
            break;
        }
    }
}

