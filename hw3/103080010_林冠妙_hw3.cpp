#include <iostream>
using namespace std;

int main()
{
int n, max, total=0 ;
printf("請輸入1+2+..+n <=max 的max 值: ") ;
scanf("%d",&max) ;

/*用迴圈幫助計算*/

for (total=0,n=0;total<=max;total=total+n)  //進行迴圈直到total<=max//
{
	if(total+n<max)  // 當只有total+n<max時，n=n+1才執行(避免多計算n)// 
	{
		
		n=n+1;
		
	}
}

	
printf("1 + 2 + .... + %d <=  %d\n", n, max);
return 0 ;
}
