//103080010林冠妙
//作業5_20170415 
//陣列使用練習
 
#include <iostream>
using namespace std;
int main()
{
int i,n;
printf("Key in n:") ;
cin >> n; //決定要顯現第幾次的反彈 
float A[n],j,k; //每次反彈高度存進A陣列(且陣列大小不會超過n個)
				//經過距離用j表示，k用於過程中的計算 

A[0]=100;
//每次反彈高度為原來一半 
	for(int i=0;i<n;i++)
	{
	A[i+1]=A[i]/2;}
//每次經過距離有一規律為，A[0]+2(A[1]...A[n-1]) ，除了有一例外為，n是0時，j為0
//用if判斷式來區別例外 
	if (n==0)
	{
	j=0;}
	else
	{
		i=0;
		for(j=100;i<n-1;i++)
		{
	
		k=2*A[i+1];
		j=j+k;
		}
		
	
	}
cout <<n<<"nd, the distance="<<j<<endl; 

cout <<n<<"nd, the length="<<A[n]<<endl;  


}

