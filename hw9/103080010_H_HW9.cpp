/*
作者:103080010林冠妙 
*/

#include<iostream>
#include<cstdlib>
#include<string>
#include<sstream>
using namespace std;

string num; //輸入之字串 
string sumtotal(string); //定義函式 

int main()
{	
	cin >> num;  
	//用while：使得使用者除其輸入0外 可一直輸入字串
	while(num!="0")
	{
	cout << sumtotal(num) << endl;
	cin >> num;
	}	
}

//利用函式進行呼叫 
string sumtotal(string num)
{
	int total=0,i=0;
	int len=num.length();
	string A[len];
	int C[len];
	
		for(i=0;i<len;i++)
		{
		//將字串中各個數字存入A陣列中	
		A[i]=num.at(i);
		//進行string→int的轉換，才能將數字加起來 
		istringstream is(A[i]);
    	is >> C[i];
		total=total+C[i];
		}
		//進行int→string的轉換，並將值存入num 
		stringstream ss;
		ss << total;
		ss >>  num;
	
	if (total<10)
	{
	
		return num;
	}
	//利用遞回再次帶入函式直到得到的值為個位數為止 
	else
	{
	
		return sumtotal(num);
	}
} 




