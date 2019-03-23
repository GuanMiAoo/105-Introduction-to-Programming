/*
作業6/林冠妙
2017/4/23 
*/

#include <iostream>
using namespace std;
int main()
{
int n,i,j;
int total=0;

cin >> n;
if (n>=100||n<=0)
{
	cout<< "Please input correct number."<< endl;
}
else
{
int A[n]; //建立相對應的陣列 

for(int i=0;i<n;i++) //利用for迴圈輸入所有的數 
	{
	cout << "輸入第 "<<i+1 << "個數 "; 
	cin >> A[i];
	
	}


//從這開始為用來確認數列是否為jolly jumper 
for(i=0;i<n-1;i++)
	{
		j=A[i+1]-A[i];
		if (j<0) //先將差值為負值的調成正值 
		{
			j=j*(-1);		 
		}
		if(j==i+1) //符合條件的值改成0，EX: i=0, j=A[1]-A[0], 則j應該=0+1=1 
		{
			j=0;
		}		
		total=total+j; // 把所有值加在一起，如果是jolly jumper，total加起來會是0 
	}
	
for(int i=0;i<n;i++) //輸出所有的數 
	{
	cout <<A[i]<<" ";
	} 

if(total>0)
	{			
	cout<<"This is not jolly jumper."<<endl;
	}
else
	{
	cout<<"This is jolly jumper."<<endl;
	
	}
}
}
	

	
