/*103080010狶玜М
穨7_04/25
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
	
	for(int i=0;i<length;i++) //じ耞琌ぃ琌ダ┪琌计 
	{
		if(isdigit(str1.at(i))) //狦琌计numΤ琌计 
		{
			num++;
		}
		if(isalpha(str1.at(i))) //狦琌ダengΤ琌ダ 
		{
			eng++;
			
		}
	
		
			other=length-num-eng; //ぃ琌ダ┪计ノ场Ι奔琌ダ┪计 
			
			
		
	}
	
	//眖硂琌ノㄓ﹚琌ぃ琌ゅ 
	for(int i=1;i<length+1;i=i+1) //ノㄧ计よ猭盢块﹃は筁ㄓ秈str2 
	{
		str2 = str2.append(str1,length-i,1);
		
			
	}
	
	if (str1==str2) //狦セ﹃㎝は筁ㄓ﹃单﹃ゅ 
	{
		cout <<"yes ! "<< eng <<" "<< num <<" "<< other <<endl;
	}
	else
	{
		cout <<"no ... "<< eng <<" "<< num <<" "<< other <<endl;
	}
	

	 
 	
	
	
}

