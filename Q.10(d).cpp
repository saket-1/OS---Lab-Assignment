#include <bits/stdc++.h>
using namespace std;
  
int main() 
{
      int n;
      cout<<"Enter number of processes\n";
      cin>>n;
      int wait[n];
      int burst[n];
      int arrival[n];
      int turn[n];
      int remaining[n];
       for(int i =0;i<n;i++)
        {
            cout<<"Enter burst time for process P"<<i<<"\n";
            cin>>burst[i];
            cout<<"Enter arrival time for process P"<<i<<"\n";
            cin>>arrival[i];
            remaining[i]=burst[i];
        }
      int time_quantum;
      cout<<"Enter Time quantum"<<"\n";
      cin>>time_quantum;
      int count =0;
      int process =n;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;
     
      for(int time = 0,i=0; process != 0; )
      {
          if(remaining[i] <= time_quantum && remaining[i] > 0)
            {
                  time = time + remaining[i];
                  remaining[i] = 0;
                  count = 1;
            }
            else if(remaining[i] > 0)
            {
                  remaining[i] = remaining[i] - time_quantum;
                  time = time + time_quantum;
            }
            if(remaining[i] == 0 && count == 1)
            {
                  process--;
                  wait[i]= time - arrival[i] - burst[i];
                  wait_time = wait_time + time - arrival[i] - burst[i];
                  turnaround_time = turnaround_time + time - arrival[i];
                   turn[i] =  time - arrival[i];
                  count = 0;
            }
            if(i == n - 1)
            {
                  i = 0;
            }
            else if(arrival[i + 1] <= time)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
          
      }
      for(int i =0;i<n;i++)
      {
        cout<<"Waiting Time for P"<<i<<" = "<<wait[i]<<"\n";
        cout<<"Turn Around Time for P"<<i<<" = "<<turn[i]<<"\n";
      }
      average_waiting_time = wait_time / n; 
      average_turnaround_time = turnaround_time / n;
      cout<<"Average Waiting Time = "<< average_waiting_time<<"\n";
      cout<<"Average Turnaround Time = "<< average_turnaround_time;
      return 0;
}
