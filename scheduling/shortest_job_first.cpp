// This was Shortest Job First(SJF) Algorithm in C-Plus-Plus Programming Language

#include<iostream>
 
using namespace std;
 
int main()
{
    int burst_time[20],p[20],waiting_time[20],turn_around_time[20],pr[20],i,j,n,total=0,pos,temp,average_waiting_time,average_turn_around_time;
    cout<<"Enter Total Number of Process:";
    cin>>n;
 
    cout<<"\nEnter Burst Time and Priority\n";
    for(i=0;i<n;i++)
    {
        cout<<"\nP["<<i+1<<"]\n";
        cout<<"Burst Time:";
        cin>>burst_time[i];
        cout<<"Priority:";
        cin>>pr[i];
        //For Process ID
        p[i]=i+1;           
    }
 
    //Selection Sort For Sorting Burst Time
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    //Waiting Time was always 0 Initially
    waiting_time[0]=0;            
 
    //For Finding Waiting Time
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
 
        total+=waiting_time[i];
    }
 
    //For Finding Average Waiting Time
    average_waiting_time=total/n;      
    total=0;
 
    cout<<"\nProcess ID\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        turn_around_time[i]=burst_time[i]+waiting_time[i];     //For Finding Turn Around Time
        total+=turn_around_time[i];
        cout<<"\nP["<<p[i]<<"]\t\t  "<<burst_time[i]<<"\t\t    "<<waiting_time[i]<<"\t\t\t"<<turn_around_time[i];
    }
 
    //For Finding Average Waiting Time
    average_turn_around_time=total/n;     
    cout<<"\n\nAverage Waiting Time="<<average_waiting_time;
    cout<<"\nAverage Turnaround Time="<<average_turn_around_time;
 
    return 0;
}