/*
�@��:103080010�L�a�� 
*/

#include<iostream>
#include<cstdlib>
#include<string>
#include<sstream>
using namespace std;

string num; //��J���r�� 
string sumtotal(string); //�w�q�禡 

int main()
{	
	cin >> num;  
	//��while�G�ϱo�ϥΪ̰����J0�~ �i�@����J�r��
	while(num!="0")
	{
	cout << sumtotal(num) << endl;
	cin >> num;
	}	
}

//�Q�Ψ禡�i��I�s 
string sumtotal(string num)
{
	int total=0,i=0;
	int len=num.length();
	string A[len];
	int C[len];
	
		for(i=0;i<len;i++)
		{
		//�N�r�ꤤ�U�ӼƦr�s�JA�}�C��	
		A[i]=num.at(i);
		//�i��string��int���ഫ�A�~��N�Ʀr�[�_�� 
		istringstream is(A[i]);
    	is >> C[i];
		total=total+C[i];
		}
		//�i��int��string���ഫ�A�ñN�Ȧs�Jnum 
		stringstream ss;
		ss << total;
		ss >>  num;
	
	if (total<10)
	{
	
		return num;
	}
	//�Q�λ��^�A���a�J�禡����o�쪺�Ȭ��Ӧ�Ƭ��� 
	else
	{
	
		return sumtotal(num);
	}
} 




