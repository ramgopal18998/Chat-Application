#include <iostream>
#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
struct Process
	{
		int priority,burstcpu,waiting;char name;
	};
bool comparision(Process a,Process b)
{
	if(a.priority>b.priority)
	return true;
}
int main()
{

	int noOfProcesses;
	cin>>noOfProcesses;
	Process arr[noOfProcesses];
	loop(i,0,noOfProcesses)
	{
		cout<<"Ente the"<<i<<"th process name"<<endl;
		cin>>arr[i].name;
		cout<<"Ente the"<<i<<"th process cpuburst"<<endl;
		cin>>arr[i].burstcpu;

		cout<<"Ente the"<<i<<"th process priority"<<endl;
		cin>>arr[i].priority;
	}
	arr[0].waiting =  0;
	loop(i,1,n)
	arr[i].waiting = arr[i-1].waiting+arr[i].cpuburst;
	sort(arr,arr+noOfProcesses,comparision);
	loop(i,0,noOfProcesses)
	cout<<arr[i].name<<"\t"<<arr[i].priority<<"\t"<<arr[i].waiting<<endl;

}
