//�@��:�L�a��103080010//  
#include <iostream>
using namespace std;

int main()
{
	//�ŧi�ܼ�year// 
	int year;
	cout << "enter the year(0~3999): "; 
	cin >> year;
	
	//�����󦡧P�_�O�_���|�~//
	if (year%400==0)
	{  
		cout<< year << " is a leap year.\n";
			}
	else 
	
	{
		if(year%4==0 && year%100)
		{
		cout<< year << " is a leap year.\n";}
		else
		{
		cout<< year << " is not a leap year.\n";}
	 } 
	 
	system("pause");
	
}
