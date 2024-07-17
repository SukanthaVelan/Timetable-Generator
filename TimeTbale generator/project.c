#include<stdio.h>
int n;
int timetable(char fn[5][4],char lunch[5],char lab[5],int no,int d,char sub[n][5],char day[5][10],int q,int l)
{
    printf("\n");
    printf("CLASS %d : \n",l);
    for(int i=d;i<=4;i++)
    {
        printf("%s |",day[q]);
        for(int j=0;j<4;j++)
        {
            if(fn[i][j]==1)
            {
                printf("| %s ",sub[0]);
            }
            else if(fn[i][j]==2)
            {
                printf("| %s ",sub[1]);
            }
            else if(fn[i][j]==3)
            {
                printf("| %s ",sub[2]);
            }
            else if(fn[i][j]==4)
            {
                printf("| %s ",sub[3]);
            }
            else if(fn[i][j]==5)
            {
                printf("| %s ",sub[4]);
            }
            else
            {
                printf("|  -  ");
            }
        }
        printf("||%c|",lunch[q]);
        if(lab[i]!=0)
        {
            printf("| %s ",sub[lab[i]-1]);
        }
        else
        {
            printf("|  -  ");
        }
        printf("|\n");
        q=q+1;
    }
    for(int i=0;i<d;i++)
    {
        printf("%s |",day[q]);
        for(int j=0;j<4;j++)
        {
            if(fn[i][j]==1)
            {
                printf("| %s ",sub[0]);
            }
            else if(fn[i][j]==2)
            {
                printf("| %s ",sub[1]);
            }
            else if(fn[i][j]==3)
            {
                printf("| %s ",sub[2]);
            }
            else if(fn[i][j]==4)
            {
                printf("| %s ",sub[3]);
            }
            else if(fn[i][j]==5)
            {
                printf("| %s ",sub[4]);
            }
            else
            {
            printf("|  -  ");
            }
        }
        printf("||%c|",lunch[q]);
        if(lab[i]!=0)
        {
        printf("| %s ",sub[lab[i]-1]);
        }
        else
        {
            printf("|  -  ");
        }
        printf("|\n");
        q=q+1;
    }
    no=no-1;
    if(no==1)
    {
        return 0;
    }
    else
    {
        timetable(fn,lunch,lab,no,d-1,sub,day,0,l+1);
    }
}
int main()
{
    int cls,x,i,j,y,no,d=4,l=2;
    printf("Welcome to the Time-Table generator 2.0™\n");
    printf("Note from developers : \n*Please give the subject codes under a 3 letter abbreviation in order to get a fairly neat output.\n*Please restraint the lab hours to 1 hour.\n*The code may not produce the desired output if the sum of L and T hours of an individual subject exceed 4. So please plan accordingly.");
    printf("\nEnter the number of section : ");
    scanf("%d",&no);
    printf("Enter the number of subjects: ");
    scanf("%d",&n);
    char sub[n][5];
    char temp1[3][15] = {"tutorial","lecture","practical"};
    char day[5][10]= {"MONDAY   ","TUESDAY  ","WEDNESDAY","THURSDAY ","FRIDAY   "};
    int slot[n][3];
    char fn[5][4];
    char lunch[5]={"LUNCH"};
    char lab[5];
    for(i = 0;i < n;i++)
    {
        printf("Enter the name of subject %d : ",i+1);
        scanf("%s",&sub[i]);
        for(j = 0;j <=2;j++)
        {
            printf("Enter the number of %s hours : ",temp1[j]);
            scanf("%d",&slot[i][j]);
        }
    }
    for(i = 0;i < n;i++)
    {
    y=0;
        x=slot[i][0]+slot[i][1];
        for(j = 0;j < 4;j++)
        {
            if(y<x)
            {
                if(i+j<=4)
                {
                    fn[i+j][j]=i+1;
                }
                else
                {
                    fn[i+j-5][j]=i+1;
                }
            }
            else
            {
                if(i+j<=4)
                {
                    fn[i+j][j]=0;
                }
                else
                {
                    fn[i+j-5][j]=0;
                }
            }
            y=y+1;
        }
        if(slot[i][2]==1)
        {
            lab[i]=i+1;
        }
        else
        {
            lab[i]=0;
        }
    }
    printf("\n");
    printf("CLASS 1 : \n");
    for(i=0;i<5;i++)
    {
        printf("%s |",day[i]);
        for(j=0;j<4;j++)
        {
            if(fn[i][j]==1)
            {
                printf("| %s ",sub[0]);
            }
            else if(fn[i][j]==2)
            {
                printf("| %s ",sub[1]);
            }
            else if(fn[i][j]==3)
            {
                printf("| %s ",sub[2]);
            }
            else if(fn[i][j]==4)
            {
                printf("| %s ",sub[3]);
            }
            else if(fn[i][j]==5)
            {
                printf("| %s ",sub[4]);
            }
            else
            {
            printf("|  -  ");
            }
        }
        printf("||%c|",lunch[i]);
        if(lab[i]!=0)
        {
        printf("| %s ",sub[lab[i]-1]);
        }
        else
        {
            printf("|  -  ");
        }
        printf("|\n");
    }
    if(no>1)
    {
        timetable(fn,lunch,lab,no,d,sub,day,0,l);
    }
    return 0;
}