#include<stdio.h>


struct matrixx{
int S[10][10];
int m,n,i,j,k,size;


}a[1];


int accept(struct matrixx *a);
int display1(struct matrixx *a);
void trip(struct matrixx *a,int M[][10]);
void display2(struct matrixx *a,int M[][10]);

int main() 
{ 

   a[1].k=0;
   a[1].size=0;
   int p=0,q=0;
   while(q!=1){
   printf("Enter your choice\n1. enter matrix\n2. add\n3. transpose\n4. insert \n5.display sparse form");
   scanf("%d",&p);
   switch (p)
{
    case 1:accept(a);
        break;
    case 5:display1(a);
        trip(a,M);
        break;
    case 3: trip(a,M);
        break;
    case 4:
        break;
    case 6: exit(0);  
}
   }
    

    
    
    int M[3][a[1].size];


    display2(a,M);
    

} 

int accept(struct matrixx *a)
{
      printf("Enter number of rows in the matrix : ");
    scanf("%d",&a[1].m);
    printf("Enter number of columns in the matrix : ");
    scanf("%d",&a[1].n);
    printf("Enter elements in the matrix : ");
     for (int i = 0; i < a[1].m; i++) 
        {
          for (int j = 0; j < a[1].n; j++) 
            scanf("%d",&a[1].S[i][j]);
            }
 return 0;        
}


int display1(struct matrixx *a)
{
      printf("The matrix is \n");
 
    for (a[1].i = 0; a[1].i < a[1].m; a[1].i++) {

        for ( a[1].j = 0; a[1].j < a[1].n; a[1].j++) {
            printf(" %d ",a[1].S[a[1].i][a[1].j]);
            if (a[1].S[a[1].i][a[1].j] != 0) 
                a[1].size++;
        }
        printf("\n");
    }
return 0;
}

void trip(struct matrixx *a,int M[][10]){
      for (a[1].i = 0; a[1].i < a[1].m; a[1].i++) 
        for (a[1].j = 0; a[1].j < a[1].n; a[1].j++) 
            if (a[1].S[a[1].i][a[1].j] != 0) 
            { 
                M[0][a[1].k] = a[1].i; 
                M[1][a[1].k] = a[1].j; 
                M[2][a[1].k] = a[1].S[a[1].i][a[1].j]; 
                a[1].k++; 
            } 


}

void display2(struct matrixx *a,int M[][10]){
    printf("Triplet representation of the matrix is \n");
    for (a[1].i=0; a[1].i<3; a[1].i++) 
    {  
          char label[3][100]={"Row   ","Column","Value "};
           printf("%s",label[a[1].i]);
        for (a[1].j=0; a[1].j<a[1].size; a[1].j++) 
            printf(" %d ", M[a[1].i][a[1].j]); 
        printf("\n"); 
    }  
}

void addition(int ktemp[3][100], int ltemp[3][100], int k, int l)
{
    int i = 0, j = 0, sparse[3][100], x = 0;

    while (i < k && j < l)
    {
        if ((ktemp[0][i] == ltemp[0][j]) && (ltemp[1][j] == ktemp[1][i]))
        {
            printf("Entered this");
            sparse[0][x] = ktemp[0][i];
            sparse[1][x] = ktemp[1][i];
            sparse[2][x] = ltemp[2][j] + ktemp[2][i];
            x++;
            i++;
            j++;
        }
        else
        {
            if (ktemp[0][i] < ltemp[0][j])
            {
                sparse[0][x] = ktemp[0][i];
                sparse[1][x] = ktemp[1][i];
                sparse[2][x] = ktemp[2][i];
                x++;
                i++;
            }

            else
            {
                if ((ktemp[0][i] == ltemp[0][j]) && (ktemp[1][i] < ltemp[1][j]))
                {
                    sparse[0][x] = ktemp[0][i];
                    sparse[1][x] = ktemp[1][i];
                    sparse[2][x] = ktemp[2][i];
                    x++;
                    i++;
                }
                else
                {
                    sparse[0][x] = ktemp[0][j];
                    sparse[1][x] = ktemp[1][j];
                    sparse[2][x] = ktemp[2][j];
                    x++;
                    j++;
                }
            }
        }
    }

    while (i < k)
    {
        sparse[0][x] = ktemp[0][i];
        sparse[1][x] = ktemp[1][i];
        sparse[2][x] = ktemp[2][i];
        x++;
        i++;
    }
    while (j < l)
    {
        sparse[0][x] = ktemp[0][j];
        sparse[1][x] = ktemp[1][j];
        sparse[2][x] = ktemp[2][j];
        x++;
        j++;
    }

    printf("\n Addition Matrix is \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < x; j++)
        {
            printf("%d", sparse[i][j]);
        }
        printf("\n");
    }
}
