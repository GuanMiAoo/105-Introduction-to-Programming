/*103080010�L�a��
�@�~7_04/25
*/ 


#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	
	string str1,str2;
	int eng=0;
	int num=0;
	int other=0;
	cin >> str1;
	int length=str1.length();	
	
	for(int i=0;i<length;i++) //�@�Ӥ@�Ӧr���U�h�P�_�O���O�r���άO�Ʀr 
	{
		if(isdigit(str1.at(i))) //�p�G�O�Ʀr�Anum�[�@�A�N���@�ӬO�Ʀr 
		{
			num++;
		}
		if(isalpha(str1.at(i))) //�p�G�O�r���Aeng�[�@�A�N���@�ӬO�r�� 
		{
			eng++;
			
		}
	
		
			other=length-num-eng; //���O�r���μƦr���Υ��������O�r���μƦr�� 
			
			
		
	}
	
	//�q�o�O�ΨӧP�w�O���O�^�� 
	for(int i=1;i<length+1;i=i+1) //�Φ���Ƥ�k�N��J���r��ϹL�ӡA�æs�istr2 
	{
		str2 = str2.append(str1,length-i,1);
		
			
	}
	
	if (str1==str2) //�p�G�쥻���r��M�ϹL�Ӫ��r��۵��A�N���r�ꬰ�^�� 
	{
		cout <<"yes ! "<< eng <<" "<< num <<" "<< other <<endl;
	}
	else
	{
		cout <<"no ... "<< eng <<" "<< num <<" "<< other <<endl;
	}
	

	 
 	
	
	
}

