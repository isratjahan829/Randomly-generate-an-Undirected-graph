#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define max 9001
int AM [max][max];
int main()
{
  int i, j, n, e=0, degree=0, s=0;
  double total_time;
  clock_t start,end;

    printf("Enter the Number of Vertices : ");
    scanf("%d",&n);
    srand(time(0));
    start=clock();
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        AM[i][j]=rand()%2;
        if(AM[i][j]==1&&i!=j){
            AM[j][i]=1;
        }
        else if(AM[i][j]==0&&i!=j){
           AM[j][i]=0;
        }
        else if(i==j){
            AM[i][j]=0;
        }
    }
}
 for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf(" %d",AM[i][j]);
        }
        printf("\n");
    }
     printf("\n Vertices \t Degree ");
    for ( i = 0 ; i < n ; i++ ){
        degree = 0;
        for ( j = 0 ; j < n ; j++ )
            if ( AM[i][j] == 1)
                degree++;
        printf("\n\n %5d \t\t %d\n\n", i, degree);
    }

for(i=0;i<n;i++){
    degree=0;
    for(j=0;j<n;j++){
        if(AM[i][j]==1){
            degree=degree+1;
        }
        if(AM[i][j]==1&&i>=j){
            e=e+1;
        }
    }
    s=s+degree;
}
printf("\n\n The Number of Total Degrees is: %d\n",s);

printf("\n\n The Number of Total Edges is: %d\n",e);

printf("\n\n The Number of Edges is=(Summation of Total Degree/2)=(%d/2)=%d" ,s,s/2);
printf("\n \n As we know, Every edge produces 2 degrees.");

printf("\n\n Therefore Handshaking Theorem is Proved\n\n");

     end=clock();
     total_time=((double)(end-start)/CLOCKS_PER_SEC)*pow(10,3);

     printf("\nExecution time : %1f ms \n",total_time);
     printf("\n");
     return 0;
