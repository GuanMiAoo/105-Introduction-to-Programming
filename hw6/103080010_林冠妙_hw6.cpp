/*
�@�~6/�L�a��
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
int A[n]; //�إ߬۹������}�C 

for(int i=0;i<n;i++) //�Q��for�j���J�Ҧ����� 
	{
	cout << "��J�� "<<i+1 << "�Ӽ� "; 
	cin >> A[i];
	
	}


//�q�o�}�l���ΨӽT�{�ƦC�O�_��jolly jumper 
for(i=0;i<n-1;i++)
	{
		j=A[i+1]-A[i];
		if (j<0) //���N�t�Ȭ��t�Ȫ��զ����� 
		{
			j=j*(-1);		 
		}
		if(j==i+1) //�ŦX���󪺭ȧ令0�AEX: i=0, j=A[1]-A[0], �hj����=0+1=1 
		{
			j=0;
		}		
		total=total+j; // ��Ҧ��ȥ[�b�@�_�A�p�G�Ojolly jumper�Atotal�[�_�ӷ|�O0 
	}
	
for(int i=0;i<n;i++) //��X�Ҧ����� 
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
	

	
