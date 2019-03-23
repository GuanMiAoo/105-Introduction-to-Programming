//作者:林冠妙103080010//  
#include <iostream>
using namespace std;

int main()
{
	//宣告變數year// 
	int year;
	cout << "enter the year(0~3999): "; 
	cin >> year;
	
	//給條件式判斷是否為閏年//
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
