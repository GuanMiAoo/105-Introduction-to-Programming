#include <iostream>
using namespace std;

int main()
{
int n, max, total=0 ;
printf("�п�J1+2+..+n <=max ��max ��: ") ;
scanf("%d",&max) ;

/*�ΰj�����U�p��*/

for (total=0,n=0;total<=max;total=total+n)  //�i��j�骽��total<=max//
{
	if(total+n<max)  // ��u��total+n<max�ɡAn=n+1�~����(�קK�h�p��n)// 
	{
		
		n=n+1;
		
	}
}

	
printf("1 + 2 + .... + %d <=  %d\n", n, max);
return 0 ;
}
