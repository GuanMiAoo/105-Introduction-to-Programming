
/*
�@�̡G103080010�L�a��
�@�~4 
*/

#include <iostream>
using namespace std;



int main()
{ 
int x,i,j,k; 
cout << "�п�J�p��10�������:";
cin >> x;

//�]�w���󦡡Ax���൥��0 
if(x==0)
{
	cout <<"input error\n";
}


else 

{
//��1�Ӱj��A�����`�@�n�]�X�� 
	for(i=1;i<=x;i++) 
	{ 
	//��2�Ӱj��A����C���n��ܪ��ť� 
		for(j=i+x-1;j>x;j--) 
		{ 
		printf(" "); 
		} 
		//��3�Ӱj��A����C���n��ܪ��Ʀr 
		for(k=x;k>=i;k--) 
		{ 
		printf("%d",k); 
		} 
		printf("\n"); 
	}
}
}
 
