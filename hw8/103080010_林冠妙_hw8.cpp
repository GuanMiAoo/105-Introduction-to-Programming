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
	//輸入總共有多少個音符(只要大於所需的即可)，用以限定陣列大小
	cout << "請輸入想要總音頻數: ";
	cin >> k;
	//使用 strtok 將輸入的字串切開，存入陣列中
	cout << "請輸入音頻(限定中音do do# re re# mi fa fa# sol sol# la la# si)並用逗號「,」相隔 : " << endl; 
	char Music[k*4];
	cin >> Music;
	string A[k]; //此陣列用於存取切割出的do re mi 等等 
	int C[k]; //此陣列在下方if處做說明 
	char *ptr;
	ptr=strtok(Music,",");
	while ((ptr != NULL)&&(i<k))
	{
		A[i]=ptr;
		i++;
		ptr=strtok(NULL,",");
		
	}
	//將英文字母轉為數字
	//beep不能為string，因此int另一陣列C 
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
	
	//輸入關於秒數的字串並跟上方一樣用strtok切開 
	
	cout << "請輸入秒數並用逗號「,」相隔 : " << endl; 
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
	//此處為將string轉為double才能套入_beep 
	double D[k];
	for(i=0;i<k;i++)
	{
    istringstream is(B[i]);
    is >> D[i];
    D[i]=D[i]*1000;
	}
	
	//輸出聲音 
	for(i=0;i<k;i++)
	{
		_beep(C[i],D[i]);
	}
}
	
	
	
	
	

