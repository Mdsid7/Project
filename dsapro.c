#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int c=0;
int sum=0;
int ch,op,iu,ex;
int p=0,f=0;
struct node
{
	char usn[200];
	char name[200];
	int dsa;
	int dm;
	int dcld;
	int em;
	int ec;
	int ee;
	int total;
	float percentage;
	struct node *link;
};

typedef struct node *NODE;
NODE getnode ()
{
	NODE x;
	x = (NODE) malloc (sizeof (struct node));
	if (x == NULL)
	{
		printf ("\nMemory not avalibale\n");
		exit (0);
	}
	else	
		return x;
}

NODE start = NULL;

void prior()
{
    NODE ptr1=getnode();
    start=ptr1;
    strcpy(ptr1->usn, "eng18cs0001");
    strcpy(ptr1->name, "Melissa");
    ptr1->dcld=1;
    ptr1->dm=9;
    ptr1->dsa=8;
    ptr1->ee=7;
    ptr1->ec=6;
    ptr1->em=5;
    
    
    NODE ptr2=getnode();
    ptr1->link=ptr2;
    strcpy(ptr2->usn, "eng18cs0002");
    strcpy(ptr2->name, "Gloria");
    ptr2->dcld=12;
    ptr2->dm=7;
    ptr2->dsa=26;
    ptr2->ee=99;
    ptr2->ec=76;
    ptr2->em=44;
   
    NODE ptr3=getnode();
    ptr2->link=ptr3;
    strcpy(ptr3->usn, "eng18cs0003");
    strcpy(ptr3->name, "Edwin");
    ptr3->dcld=66;
    ptr3->dm=37;
    ptr3->dsa=77;
    ptr3->ee=88;
    ptr3->ec=89;
    ptr3->em=45;
    
    NODE ptr4=getnode();
    ptr3->link=ptr4;
    strcpy(ptr4->usn, "eng18cs0004");
    strcpy(ptr4->name, "Seth");
    ptr4->dcld=32;
    ptr4->dm=43;
    ptr4->dsa=85;
    ptr4->ee=47;
    ptr4->ec=87;
    ptr4->em=38;
    
    NODE ptr5=getnode();
    ptr4->link=ptr5;
    strcpy(ptr5->usn, "eng18cs0005");
    strcpy(ptr5->name, "Alison");
    ptr5->dcld=80;
    ptr5->dm=85;
    ptr5->dsa=75;
    ptr5->ee=78;
    ptr5->ec=88;
    ptr5->em=90;
    
    NODE ptr6=getnode();
    ptr5->link=ptr6;
    strcpy(ptr6->usn, "eng18cs0006");
    strcpy(ptr6->name, "Jaime");
    ptr6->dcld=98;
    ptr6->dm=100;
    ptr6->dsa=90;
    ptr6->ee=80;
    ptr6->ec=90;
    ptr6->em=99;
    ptr6->link=NULL;
    
}
void insert ()
{
	NODE temp;
	temp = getnode ();
    printf("enter the details\n");
    printf ("\nUSN:");
	scanf ("%s", temp->usn);
    
    printf ("\nName:");
	scanf ("%s", temp->name);
    
    printf ("\nDCLD:");
    scanf ("%d", &temp->dcld);
    
    printf("\nDM:");
    scanf("%d",&temp->dm);
    
    printf ("\nDSA:");
	scanf ("%d", &temp->dsa);

    printf ("\nEC:");
    scanf ("%d", &temp->ec);
    
    printf ("\nEE:");
    scanf ("%d", &temp->ee);
    
    printf ("\nEM:");
	scanf ("%d", &temp->em);
    temp->link = start;
	start = temp;
}



void deletion ()
    {
        int position;
        printf("Enter the position to delete\n");
        scanf("%d",&position);
        NODE locationp,location;
        if(start==NULL)
        {
            printf("List is empty\n");
        }
        else{
            NODE temp=start;
            if(position==1)
            {
                start=start->link;
                free(temp);
            }
            else
            {
                locationp=start;
                location=start->link;
                int count=2;
                while(count!=position)
                {
                    locationp=location;
                    location=location->link;
                    count++;
                }
                if(locationp==NULL)
                {
                    start=location->link;
                }
                else{
                    locationp->link=location->link;
                    free(location);
                }
            }
    
        }
        printf("The node is deleted\n");
    }
    void display ()
    {
        int total;
        float percentage ,sgpa;
	
        NODE ptr;
        ptr=start;
	
        if(ptr==NULL)
        {
            printf("\nRecord is empty\n");
        }
        else
        {
            printf("\n The stuent details are\n");
            printf("\n---------------------------------------------------------------------------------------------------------------------\n");
            printf("\n\t        usn\t          name\t dcld\t dm\t dsa\t ec\t ee\t em\t total\t percentage");
            printf("\n----------------------------------------------------------------------------------------------------------------------\n");
            while(ptr!=NULL)
            {
                printf("\n\t%11s",ptr->usn);
                printf("\t %10s",ptr->name);
                printf("\t %4d",ptr->dcld);
                printf("\t %2d",ptr->dm);
                printf("\t %3d",ptr->dsa);
                printf("\t %2d",ptr->ec);
                printf("\t %2d",ptr->ee);
                printf("\t %2d",ptr->em);
                total= ((ptr->dsa)+(ptr->dcld)+(ptr->em)+(ptr->ec)+(ptr->ee)+(ptr->dm));
                percentage= (total/6);
                printf("\t %5d\t %10.2f%%",total,percentage);
                ptr=ptr->link;
            }
		printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
        }
        
    }
    void statistics ()
    {
        if(start==NULL)
        {
            printf("No records\n");
        }
        else{
            
        
        int choice_topper;
        int end ,max=-1;
        NODE ptr=start;
        NODE loc=NULL;
        NODE temp=start;
        do
        {
            printf("Enter the choice\n1-average in each subject\n2-topper in each subject\n3-passed and failed\n");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                    do{
                        temp=start;
                        sum=0;
                        c=0;
                        printf("Enter your choice\n1-DSA\n2-DCLD\n3-EM\n4-EC\n5-EE\n6-DM:\n");
                        scanf("%d",&op);
                        switch(op)
                            {
                            
                                case 1:
                                
                                    while(temp!=NULL)
                                    {
                                        sum=sum+temp->dsa;
                                        temp=temp->link;
                                        c++;
                                    }
                                    printf("The average in dsa is : %d\n",sum/c);
                                    break;
                                case 2:
                            
                                    while(temp!=NULL)
                                        {
                                            sum=sum+temp->dcld;
                                            temp=temp->link;
                                            c++;
                                        }
                                    printf("The average in dcld is : %d\n",sum/c);
                                    break;
                                case 3:
                                
                                    while(temp!=NULL)
                                        {
                                            sum=sum+temp->em;
                                            temp=temp->link;
                                            c++;
                                        }
                                    printf("The average in em is : %d\n",sum/c);
                                    break;
                                case 4:
                            
                                    while(temp!=NULL)
                                        {
                                            sum=sum+temp->ec;
                                            temp=temp->link;
                                            c++;
                                        }
                                    printf("The average in ec is : %d\n",sum/c);
                                    break;
                                case 5:
                                
                                    while(temp!=NULL)
                                        {
                                            sum=sum+temp->ee;
                                            temp=temp->link;
                                            c++;
                                        }
                                    printf("The average in ee is : %d\n",sum/c);
                                    break;
                                case 6:
                            
                                    while(temp!=NULL)
                                        {
                                            sum=sum+temp->dm;
                                            temp=temp->link;
                                            c++;
                                        }
                                    printf("The average in dms is : %d\n",sum/c);
                                    break;
                                default:
                                    printf("Wrong choice\n");
                            }
                        printf("Enter 1 to continue average\n");
                        scanf("%d",&end);
                    }while(end==1);
                    break;
                case 2:
                    do
                        {
                            max=-1;
                            ptr=start;
                            loc=NULL;
                            printf("enter your choice\n");
                            printf("\n1.DSA:");
                            printf("\n2.DCLD:");
                            printf("\n3.DM:");
                            printf("\n4.EM:");
                            printf("\n5.EC:");
                            printf("\n6.EE:");
                            scanf("%d",&choice_topper);
                            switch(choice_topper)
                                {
                                    case 1:
                                    while(ptr!=0)
                                    {
                                        if(ptr->dsa>max)
                                        {
                                            max=ptr->dsa;
                                            loc=ptr;
                                        }
                                        ptr=ptr->link;
                                    }
                                    break;
                                    case 2:
                                    while(ptr!=0)
                                    {
                                        if(ptr->dcld>max)
                                        {
                                            max=ptr->dcld;
                                            loc=ptr;
                                        }
                                        ptr=ptr->link;
                                    }
                                    break;
                                    case 3:
                                    while(ptr!=0)
                                    {
                                        if(ptr->dm>max)
                                        {
                                            max=ptr->dm;
                                            loc=ptr;
                                        }
                                        ptr=ptr->link;
                                    }
                                    break;
                                    case 4:
                                    while(ptr!=0)
                                    {
                                        if(ptr->em>max)
                                        {
                                            max=ptr->em;
                                            loc=ptr;
                                        }
                                        ptr=ptr->link;
                                    }
                                    break;
                                    case 5:
                                    while(ptr!=0)
                                    {
                                        if(ptr->ec>max)
                                        {
                                            max=ptr->ec;
                                            loc=ptr;
                                        }
                                        ptr=ptr->link;
                                    }
                                    break;
                                    case 6:
                                    while(ptr!=0)
                                    {
                                        if(ptr->ee>max)
                                        {
                                            max=ptr->ee;
                                            loc=ptr;
                                        }
                                        ptr=ptr->link;
                                    }
                                    break;
                                    default:
                                    {
                                        printf("Enter a valid choice\n");
                                        max=0;
                                        
                                    }
                                }
                            if (max==-1)
                            {
                                printf("No elements in the list \n");
                            }
                            else if(max==0)
                            {
                                
                            }
                            else{
                                printf("the topper details\n");
                                printf("USN:%s \nNAME:%s\nMARKS:%d\n",loc->usn,loc->name,max);
                                }
                            printf("Enter 1 to continue to display the topper\n");
                            scanf("%d",&end);
                        }while (end ==1);
                break;
	
                case 3:
            
                    temp=start;
                    f=0;
                    p=0;
                    while(temp!=0){
                        if(temp->dsa<=35||temp->dcld<=35||temp->dm<=35||temp->em<=35||temp->ec<=35||temp->ee<=35)
                        {
                            f++;
                        }
                        else
                        {
                            p++;
                        }
                        temp=temp->link;
                    }
                    printf("Pass:%d\tFail:%d\n",p,f);
                    break;
                default:
                printf("enter a valid choice\n");
                break;
            }
            printf("Enter 1 to statistics:\n");
            scanf("%d",&ex);
        }while(ex==1);
        
    }
    }
int main ()
    {
        int ch, i,password;
        prior();
        do
        {
            password=0;
            printf ("1.insertion \n");
            printf ("2.deletion\n");
            printf ("3.display \n");
            printf ("4.statistics \n");
            scanf ("%d", &ch);
            switch (ch)
            {
                case 1:
                printf("Password:");
                scanf("%d",&password);
                if(password==123)
                {
                    printf("\n\nCorrect Password\n\n");
                    insert ();
                }
                else{
                    printf("\n\nWrong Password\n\n");
                }
                break;
                case 2:
                printf("pPassword:");
                scanf("%d",&password);

                if(password==123)
                {
                    printf("\n\nCorrect Password\n\n");
                    deletion ();
                }
                else
                {
                    printf("\n\nWrong Password\n\n");
                }
                break;
                case 3:
                display ();
                break;
                case 4:
                statistics ();
                break;
                default:
                printf ("Enter a valid choice\n");
            }
            printf ("Enter 1 to continue\n");
            scanf ("%d", &i);
        }while (i == 1);
        return 0;
    }
