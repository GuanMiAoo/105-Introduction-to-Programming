#include<iostream>
#include<cstdlib>
#include<cstring> 
#include<string>
#include<sstream>
using namespace std;
int k;
int i=0;
int main()
{
	//��J�`�@���h�֭ӭ���(�u�n�j��һݪ��Y�i)�A�ΥH���w�}�C�j�p
	cout << "�п�J�Q�n�`���W��: ";
	cin >> k;
	//�ϥ� strtok �N��J���r����}�A�s�J�}�C��
	cout << "�п�J���W(���w����do do# re re# mi fa fa# sol sol# la la# si)�åγr���u,�v�۹j : " << endl; 
	char Music[k*4];
	cin >> Music;
	string A[k]; //���}�C�Ω�s�����ΥX��do re mi ���� 
	int C[k]; //���}�C�b�U��if�B������ 
	char *ptr;
	ptr=strtok(Music,",");
	while ((ptr != NULL)&&(i<k))
	{
		A[i]=ptr;
		i++;
		ptr=strtok(NULL,",");
		
	}
	//�N�^��r���ର�Ʀr
	//beep���ରstring�A�]��int�t�@�}�CC 
	for(i=0;i<k;i++)
	{
		if (A[i]=="do")
		{
		C[i]=262;}
		if (A[i]=="do#")
		{C[i]=277;}
		if (A[i]=="re")
		{C[i]=293;}
		if (A[i]=="re#")
		{C[i]=311;}
		if (A[i]=="mi")
		{C[i]=330;}
		if (A[i]=="fa")
		{C[i]=349;}
		if (A[i]=="fa#")
		{C[i]=370;}
		if (A[i]=="sol")
		{C[i]=392;}
		if (A[i]=="sol#")
		{C[i]=415;}
		if (A[i]=="la")
		{C[i]=440;}
		if (A[i]=="la#")
		{C[i]=466;}
		if (A[i]=="si")
		{C[i]=494;}									
	}
	
	//��J�����ƪ��r��ø�W��@�˥�strtok���} 
	
	cout << "�п�J��ƨåγr���u,�v�۹j : " << endl; 
	i=0;
	string B[k];
	char Second[k*5];
	cin >> Second;
	char *sec;
	sec=strtok(Second,",");
	while ((sec != NULL)&&(i<k))
	{
		B[i]=sec;
		i++;
		sec=strtok(NULL,",");
		
	}
	//���B���Nstring�ରdouble�~��M�J_beep 
	double D[k];
	for(i=0;i<k;i++)
	{
    istringstream is(B[i]);
    is >> D[i];
    D[i]=D[i]*1000;
	}
	
	//��X�n�� 
	for(i=0;i<k;i++)
	{
		_beep(C[i],D[i]);
	}
}
	
	
	
	
	

