
/*
作者：103080010林冠妙
作業4 
*/

#include <iostream>
using namespace std;



int main()
{ 
int x,i,j,k; 
cout << "請輸入小於10的正整數:";
cin >> x;

//設定條件式，x不能等於0 
if(x==0)
{
	cout <<"input error\n";
}


else 

{
//第1個迴圈，控制總共要跑幾輪 
	for(i=1;i<=x;i++) 
	{ 
	//第2個迴圈，控制每輪要顯示的空白 
		for(j=i+x-1;j>x;j--) 
		{ 
		printf(" "); 
		} 
		//第3個迴圈，控制每輪要顯示的數字 
		for(k=x;k>=i;k--) 
		{ 
		printf("%d",k); 
		} 
		printf("\n"); 
	}
}
}
 
