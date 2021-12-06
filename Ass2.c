#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int p;
struct cric
{
  char name[15], country[15], category[15];
  int age, odi, twenty, batscore, wkts;
};

int battingcountry(struct cric a[]);

int bowlingcountry(struct cric a[]);

int maxwickets(struct cric a[]);

int display_one(struct cric a[]);

int maxruns(struct cric a[]);

int main()
{
  struct cric s[10];
  int i, choice;
  char cntry[15], nm[15];
  printf("\nTOTAL PLAYERS ");
  scanf("%d",&p);
  printf("\nNOW ENTER DATA OF %d PLAYERS\n",p);
  for(i=0;i<p;i++)
  {
    printf("Enter player name ");
    scanf("%s", s[i].name);
    printf("Enter player age ");
    scanf("%d", &s[i].age);
    printf("Enter player country ");
    scanf("%s", s[i].country);
    printf("Enter player category ");
    scanf("%s", s[i].category);
    printf("Enter ODIs played ");
    scanf("%d", &s[i].odi);
    printf("Enter 20-20s played ");
    scanf("%d", &s[i].twenty);
    printf("Enter batting average ");
    scanf("%d", &s[i].batscore);
    printf("Enter wicket average ");
    scanf("%d", &s[i].wkts);
    printf("\n");
  }

  do
  {
    printf("\n\n#####################################################\n");
    printf("\n\nPlease choose an operation\n1) Number of batsman of a particular country \n");
    printf("2) Number of bowlers of a particular country  \n");
    printf("3) Bowler that has taken maximum no of wickets \n");
    printf("4) Show a particular players entire -Display board information \n");
    printf("5) Display average batting score of a particular player.\n");
    printf("6) Exit \n");
    printf("\n\n#####################################################\n");

    printf("Enter you choice");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1: battingcountry(s);
      break;

      case 2: bowlingcountry(s);
      break;

      case 3: maxwickets(s);
      break;

      case 4: maxruns(s);
      break;

      case 5: display_one(s);
      break;

      case 6: exit(0);
    }
  }while(1);
}

int battingcountry(struct cric a[])
{
  int ctr;
  char cntry[15];
  ctr=0;
  printf("\nEnter country to display number of batsman: ");
  scanf("%s",cntry);
  for(int i=0; i<p; i++)
  {
    if((strcmp(cntry,a[i].country)==0)&&(strcmp("batsman",a[i].category)==0))
    ctr++;
  }
  printf("\nNumber of batsman of country %s = %d ", cntry,ctr);
  return 0;
}

int bowlingcountry(struct cric a[])
{
  int ctr=0;
  char cntry[15];
  printf("\nEnter country to display number of bowlers: ");
  scanf("%s", cntry);
  for(int i=0; i<p; i++)
  {
    if((strcmp(cntry,a[i].country)==0)&&(strcmp("bowler",a[i].category)==0))
    ctr++;
  }
  printf("\nNumber of bowlers of a %s country= %d ", cntry,ctr);
  return 0;
}

int maxruns(struct cric a[])
{
  int ctr=a[0].batscore;
  int index=0;
  for(int i=0; i<p; i++)
  {
    if(strcmp("batsman",a[i].category)==0)
    {
      if (a[i].batscore>ctr)
        {
        ctr=a[i].batscore;
        index=i;
        }
      }
    }
    printf("\n Name of Batsman with highest average score is %s with score %d\n",a[index].name,ctr);
    return 0;
}
int maxwickets(struct cric a[])
{
  int ctr=0;
  int index=0;
  for(int i=0; i<p; i++)
  {
    if(strcmp("bowler",a[i].category)==0)
    {
      if (a[i].wkts>ctr)
      {
        ctr=a[i].wkts;
        index=i;
      }
    }
  }
  printf("\n Name of Bowler who has taken maximum no of wickets is %s\n", a[index].name);
  return 0;
}

//indivisual player
int display_one(struct cric a[])
{
  char nm[15];
  printf("\n Enter Name of player to display data ");
  scanf("%s", nm);
  for(int i=0; i<p; i++)
  {
    if(strcmp(nm,a[i].name)==0)
    {
      printf("name \tcountry \tcategory \tage \todi \t20-20s \tbatscore \twkts\n");
      printf("%s \t\t%s \t\t%s \t\t%d ",a[i].name, a[i].country,a[i].category, a[i].age);
      printf("\t\t%d \t\t%d \t\t%d \t\t%d\n",a[i].odi,a[i].twenty ,a[i].batscore, a[i].wkts);
    }
  }
  return 0;
}


