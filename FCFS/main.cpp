#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    ///1-define struct
    struct process {int id, at, bt, wt;};

    ///2-no of process
    cout<<"Enter number of process"<<endl;
    int n; cin>>n;

    ///3-dynamic array
    process *arr; arr=new process[n];

    ///4-Enter Arrival time & Burst time
    cout<<"Arrival Time     Burst Time"<<endl;
    for(int i=0 ; i<n ; i++){
        arr[i].id = i + 1;
        cin >> arr[i].at;
        cin >> arr[i].bt;
    }
    ///5-Sorting Process in ascending order according to its arrival time using Bubble Sort
    for(int i=0 ; i<n-1 ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(arr[i].at>arr[j].at){
                process temp=arr[i];
                        arr[i]=arr[j];
                        arr[j]=temp;
            }
        }
    }
    ///6-Calculating Waiting Time for each Process
    arr[0].wt=0;
    int total=0;
    for(int i=1 ; i<n ; i++){
        total+=arr[i-1].bt;
        arr[i].wt=total-arr[i].at;
    }
    cout<<"---------------------------------------"<<endl;
    ///7-The Sequence of Processes Will be & The Waiting Time for each process
    cout<<"Process     Arrival time     Burst Time     Waiting Time"<<endl;
    for(int i=0 ; i<n ;i++){
        cout<<"P"<<arr[i].id<<"\t \t"<<arr[i].at<<"\t \t"<<arr[i].bt<<"\t \t"<<arr[i].wt<<endl;
    }
    cout<<"---------------------------------------"<<endl;
    ///8- Drawing Gantt chart
    cout<<"Gantt Chart"<<endl;
    for(int i=0 ; i<n ;i++){
        cout<<setw(arr[i].bt)<<"P"<<arr[i].id<<"\t";
    }
    cout<<endl<<0;
    total=0;
    for(int i=0 ; i<n ; i++){
        total+=arr[i].bt;
        cout<<setfill('-')<<setw(arr[i].bt*2)<<total;
    }
    ///9-Calculating the Average Waiting Time
    int sum=0;
    for(int i=0 ; i<n ; i++){
        sum+=arr[i].wt;
    }
    cout<<endl<<"Average Waiting time = "<<sum<<"/"<<n<<" = "<<(float)sum/n<<endl;
    delete[] arr;
    return 0;
}
