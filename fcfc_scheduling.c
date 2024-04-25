# include <stdio.h>


int main(){
    int n;
    printf("Enter the number of process :");
    scanf("%d",&n);
    
    int  at[n];
    int bt[n];
    int p[n];
    printf("\n enter Arrive-time  burst-time:");
    for (int i=0;i<n;i++){
        
    printf("\n arrive time  for process %d:",i+1);
    scanf ("%d",&at[i]);
    
    printf("\n burst time  for process %d:",i+1);
    scanf ("%d",&bt[i]);
    p[i]=i+1;
    }
    
    int ct[n];
    for (int i=0;i<n ;i++){
        
        if(i<0){
            ct[i]= bt[i];
        }
        else {
            
            ct[i]=ct[i-1]+bt[i];
        }
    }
    
    int tat[n];
    int wt[n];
    for (int i=0;i<n ;i++){
        
        tat[i]=ct[i]-at[i];
    }
    for (int i=0 ; i<n ;i++){
        
        wt[i]=tat[i]-bt[i];
    }
    
     printf("\n processes | Arrive time  | burst time  | completion time |TAT   | WT ");
    for(int i=0;i<n ;i++){
    printf("\n  %d       |  %d          | %d            |    %d          | %d   | %d    ",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);


    }
    
    int totaltat=0;
    int totalwt=0;
    for (int i=0 ;i<n;i++){
        totaltat+=tat[i];
        totalwt+=wt[i];
    }
    printf("\ntotal turn around time:");
    printf("%d",totaltat);
    printf("\ntotal waiting time:");
    printf("%d",totalwt);
    float  avgtat= totaltat/n;
    float avgwt=totalwt/n;
    
    printf("\n avg turn around time is : %f", avgtat);
    printf("\n avg waiting time time is : %f", avgwt);
    
    
    return 0;
}
