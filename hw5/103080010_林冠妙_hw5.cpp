//103080010�L�a��
//�@�~5_20170415 
//�}�C�ϥνm��
 
#include <iostream>
using namespace std;
int main()
{
int i,n;
printf("Key in n:") ;
cin >> n; //�M�w�n��{�ĴX�����ϼu 
float A[n],j,k; //�C���ϼu���צs�iA�}�C(�B�}�C�j�p���|�W�Ln��)
				//�g�L�Z����j��ܡAk�Ω�L�{�����p�� 

A[0]=100;
//�C���ϼu���׬���Ӥ@�b 
	for(int i=0;i<n;i++)
	{
	A[i+1]=A[i]/2;}
//�C���g�L�Z�����@�W�߬��AA[0]+2(A[1]...A[n-1]) �A���F���@�ҥ~���An�O0�ɡAj��0
//��if�P�_���ӰϧO�ҥ~ 
	if (n==0)
	{
	j=0;}
	else
	{
		i=0;
		for(j=100;i<n-1;i++)
		{
	
		k=2*A[i+1];
		j=j+k;
		}
		
	
	}
cout <<n<<"nd, the distance="<<j<<endl; 

cout <<n<<"nd, the length="<<A[n]<<endl;  


}

