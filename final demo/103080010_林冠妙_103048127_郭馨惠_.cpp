#include<iostream>
#include<cstdlib>
#include<cstring> 
#include<string>
#include<sstream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
using namespace std;

///設定背景顏色所需///// 
void SetColor(int color = 7)
{
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,color);
}

int mode;//選擇模式(購買or系統模式) 

//////////mode1-購買模式//////////////////////////////////////////
int date=0; //輸入今天的日期以將銷售紀錄記在今天的日期上 
string sdate;//用來轉換date(int)
int referdate=0; //date-1，用來叫出前一天的存貨紀錄
string sreferdate;//用來轉換referdate(int)

//coin用
int m50,m10,m5,m1;//各個硬幣幣值 
int n50,n10,n5,n1;//使用者投入的錢的數量 
int mm50,mm10,mm5,mm1;//要找的錢的數量 
int nn50=0,nn10=0,nn5=0,nn1=0;//因為錢投不夠使用者再次追加投幣的總數量 
int ns50=0,ns10=0,ns5=0,ns1=0;//因為錢投不夠使用者再次追加投幣
int money=0;//money總投幣金額
int real=0; //real應付金額 

//stock用 
int save=0; //存取使用者選取的品項的存貨量
int math; //math 使用者輸入品項代碼  
string choose; //硬幣不足時用來選擇繼續投幣或退幣 

////////mode0-系統模式/////////////////////////////////
int i; //用來選擇要使用模式中哪種功能 
int search2=0; //查詢特定日期紀錄 
string strsearch; //search2轉string 
string items;  //輸入欲查詢的品項 
int pass; //進入系統模式的密碼 
int total=0;//從過去到現在的總花費金額 


//自訂函式處// 
//用在code0：將品項庫存及硬幣庫存存入txt中 
char inrecord[30];
char stockfunc(char inrecord[30]);
char incoin[30];
char coinfunc(char incoin[30]);
/////////////////////////////////

int main()
{	
system("color F0");//設定背景顏色 
while(1)
{

cout <<"輸入0會進入系統，輸入1會進入購買模式，輸入3會結束程式: ";
cin >> mode;
if(mode==0)
{
cout <<"輸入密碼進入維修系統: ";
cin >> pass;
if(pass==987654)
{
int cocola=0,fanta=0,pie=0,noodle=0,water=0,sarsa=0,tea=0,soda=0,cookie=0,candy=0,bread=0,coffee=0,milk=0,yakult=0;//品項價錢用 
int acocola=0,afanta=0,apie=0,anoodle=0,awater=0,asarsa=0,atea=0,asoda=0,acookie=0,acandy=0,abread=0,acoffee=0,amilk=0,ayakult=0;//品項數量用 
int aa50=0, aa10=0 ,aa5=0,aa1=0;//硬幣數量用 
			while(1) //使用者可一直使用，直到其想要結束系統 
			{
			SetColor(243);
			cout << "寫入之前物品庫存請輸1(一旦寫入會消去過去庫存紀錄)" << endl ; 
			cout << "寫入之前硬幣庫存請輸2(一旦寫入會消去過去庫存紀錄)" << endl ; 
			cout << "查詢特定日期消售資料請輸3 " << endl ; 
			cout << "查詢特定日期、特定品項消售資料請輸4 " << endl ;
			cout << "查詢從過去到現在累積消費金額請輸5 " << endl ;
			cout << "結束系統模式請輸6: " << endl;
			cin >> i;		
			if (i==1)
			{	//寫入庫存紀錄 
				cout << "請依指示輸入: " <<endl;
				cout << "請先輸入日期(EX:1060501): " <<endl;
				cin >> search2;
				cout << "接下來開始輸入各品項的價錢及庫存: "<< endl;
				cout << "請輸入cocola的價錢及庫存:  " << endl;
				cin >> cocola;
				cin >> acocola;
				cout << "請輸入fanta的價錢及庫存:  " << endl;
				cin >> fanta;
				cin >> afanta;
				cout << "請輸入pie的價錢及庫存:  " << endl;
				cin >> pie;
				cin >> apie;
				cout << "請輸入noodle的價錢及庫存:  " << endl;
				cin >> noodle;
				cin >> anoodle;
				cout << "請輸入water的價錢及庫存:  " << endl;
				cin >> water;
				cin >> awater;
				cout << "請輸入sarsa.的價錢及庫存:  " << endl;
				cin >> sarsa;
				cin >> asarsa;
				cout << "請輸入tea的價錢及庫存:  " << endl;
				cin >> tea;
				cin >> atea;
				cout << "請輸入soda的價錢及庫存:  " << endl;
				cin >> soda;
				cin >> asoda;
				cout << "請輸入cookie的價錢及庫存:  " << endl;
				cin >> cookie;
				cin >> acookie;
				cout << "請輸入candy的價錢及庫存:  " << endl;
				cin >> candy;
				cin >> acandy;
				cout << "請輸入bread的價錢及庫存:  " << endl;
				cin >> bread;
				cin >> abread;
				cout << "請輸入coffee的價錢及庫存:  " << endl;
				cin >> coffee;
				cin >> acoffee;
				cout << "請輸入milk的價錢及庫存:  " << endl;
				cin >> milk;
				cin >> amilk;
				cout << "請輸入yakult的價錢及庫存:  " << endl;
				cin >> yakult;
				cin >> ayakult;
				cout << "庫存記錄輸入完畢" <<  endl;
				
					char daily1[20]="stock_record.txt";
					ofstream readFile(daily1,ios_base::out);
					readFile << "date" << '\t' << "item" << '\t' << "num" << '\t' << "price" << endl;
					readFile<< search2 <<'\t'<< "cocola" <<'\t'<< acocola <<'\t'<<cocola <<endl;
					readFile<< search2 <<'\t'<< "fanta" <<'\t'<< afanta <<'\t'<<fanta <<endl;
					readFile<< search2 <<'\t'<< "pie" <<'\t'<< apie <<'\t'<<pie <<endl;
					readFile<< search2 <<'\t'<< "noodle" <<'\t'<< anoodle <<'\t'<<noodle <<endl;
					readFile<< search2<<'\t'<< "water" <<'\t'<< awater <<'\t'<<water <<endl;
					readFile<< search2 <<'\t'<< "sarsa." <<'\t'<< asarsa <<'\t'<<sarsa <<endl;
					readFile<< search2 <<'\t'<< "tea" <<'\t'<< atea <<'\t'<<tea<<endl;
					readFile<< search2 <<'\t'<< "soda" <<'\t'<< asoda <<'\t'<<soda <<endl;
					readFile<< search2 <<'\t'<< "cookie" <<'\t'<< acookie <<'\t'<<cookie <<endl;
					readFile<< search2 <<'\t'<< "candy" <<'\t'<< acandy <<'\t'<<candy <<endl;
					readFile<< search2 <<'\t'<< "bread" <<'\t'<< abread <<'\t'<<bread <<endl;
					readFile<< search2 <<'\t'<< "coffee" <<'\t'<< acoffee <<'\t'<<coffee <<endl;
					readFile<< search2 <<'\t'<< "milk" <<'\t'<< amilk <<'\t'<<milk <<endl;
					readFile<< search2 <<'\t'<< "yakult" <<'\t'<< ayakult <<'\t'<<yakult<<endl<<endl;
					readFile.close();
			
			}
				//寫入硬幣庫存 
			if (i==2)
			{
				cout << "請依指示輸入: " <<endl;
				cout << "請先輸入日期(EX:1060501): " <<endl;
				cin >> search2;
				cout << "接下來開始輸入各硬幣的庫存: "<< endl;
				cout << "請輸入50元的庫存:  " << endl;
				cin >> aa50;
				cout << "請輸入10元的庫存:  " << endl;
				cin >> aa10;
				cout << "請輸入5元的庫存:  " << endl;
				cin >> aa5;
				cout << "請輸入1元的庫存:  " << endl;
				cin >> aa1;
				cout << "庫存記錄輸入完畢" <<  endl;
				
					char daily3[20]="coin_record.txt";
					ofstream readmo(daily3,ios_base::out);
					readmo<< "date" << '\t' << "item" << '\t' << "num" <<endl;
					readmo<< search2 <<'\t'<< "50" <<'\t'<< aa50 <<endl;
					readmo<< search2 <<'\t'<< "10" <<'\t'<< aa10 <<endl;
					readmo<< search2 <<'\t'<< "5" <<'\t'<< aa5 <<endl;
					readmo<< search2 <<'\t'<< "1" <<'\t'<< aa1 <<endl<<endl;
					readmo.close();
				
			}
			if(i==3)
			{
				//////查詢特定日期消售資料///////
			cout << "請輸入欲查詢日期(僅限1060502後的資料):" << endl;
			cin >> search2;
			stringstream sear;
			sear << search2;
			sear >>  strsearch; //從int轉string 
			SetColor(244);
			cout << "date" << '\t' << "item" << '\t' << "num" << '\t' << "sum" << endl;
			/////內部處理，讀取所需資料存進G[][]中////// 
			ifstream Sear("daily_expense.txt");
			string find;  //用來存取檔案中讀取的每一行 
			string G[600][20]; //存取分割後的資料 
			int q=0,w=0,e=0,u=0,sum=0,H[20]; //G[q][w]，e用於計算取代次數，u、sum用於最後加總金額，H[20]用來轉換G[][]的data 
			while(getline(Sear,find)) {
			w=0;
			char *ptr6; 
			char FI[50];
			strcpy(FI,find.c_str()); //將find轉為char才能使用strtok 
			ptr6=strtok(FI,"'\t'");
				while ((ptr6 != NULL)&&w<=3)
				{
				G[q][w]=ptr6;
				ptr6=strtok(NULL,"'\t'");
				w++;
				}
			q++;
			}
			q=0;
			////找到目標日期///// 
			while(G[q][0]!=strsearch)
			{
				
				//G[0][0]=G[q+1][0];
				q++;
				e++;
			}
			/////進行取代//////// 
			q=0;
			w=0;
			for(q=0;q<14;q++)
			{
				for(w=0;w<4;w++)
				{
					G[q][w]=G[q+e][w];
					cout << G[q][w] << '\t';		 
				}
				cout << endl;
			}	
			///轉換到int才能加起來////////// 
			for(u=0;u<14;u++)
			{
			istringstream countsum(G[u][3]);
    		countsum >> H[u];
			sum=sum+H[u];	
			}
				cout << search2 <<"所花費的金額為: $" << sum << endl; 
				Sear.close();
			}
			
			if(i==4)
			{
				////查詢特定日期、特定品項消售資料/////////////
			cout << "請輸入欲查詢日期(僅限1060502後的資料):" << endl;
			cin >> search2;
			stringstream sear;
			sear << search2;
			sear >>  strsearch; //從int轉string 
			cout << "請輸入欲查詢品項:cocola , fanta , pie , noodle , water , sarsa. , tea , soda , cookie , candy , bread , coffee	, milk , yakult" << endl;
			cin >>items;
			SetColor(244);
			cout << "date" << '\t' << "item" << '\t' << "num" << '\t' << "sum" << endl;
			/////內部處理，讀取所需資料存進G[][]中////// 與i==3雷同 
			ifstream Sear("daily_expense.txt");
			string find;  //用來存取檔案中讀取的每一行 
			string G[600][20]; //存取分割後的資料 
			int q=0,w=0,e=0,u=0,sum=0,H[20]; //G[q][w]，e用於計算取代次數，u、sum用於最後加總金額，H[20]用來轉換G[][]的data 
			while(getline(Sear,find)) {
			w=0;
			char *ptr6;
			char FI[50];
		
			strcpy(FI,find.c_str());
			ptr6=strtok(FI,"'\t'");
				while ((ptr6 != NULL)&&w<=3)
				{
				G[q][w]=ptr6;
				ptr6=strtok(NULL,"'\t'");
				//cout << G[19][1]<< endl;
				w++;
				}
			q++;
			}
			//cout << G[2][1]<< endl;
			/*if (G[2][1]!=items)
			{
				cout << "yes";
			}*/
			q=0;
			//須滿足找到特定日期與品項才執行///// 
			while(G[q][0]!=strsearch)
			{			
			
				
				q++;
				e++;
				
			
			}
			while(G[q][1]!=items)
			{
				q++;
				e++;
			}
			
			//	cout << G[0][0] << G[0][1] << endl ;
			
			q=0;
			w=0;
			////印出找到的那一行資料/////// 
				for(w=0;w<4;w++)
				{
					G[0][w]=G[e][w];
				//cout << e;
					cout << G[0][w] << '\t';
					 
				}
				cout << endl;
				Sear.close();					
			}
			
			
			if(i==5)
			{
				////查詢從過去到現在累積消費金額/////寫法與i==3以及i==4雷同 
			total=0;
			ifstream Sear("daily_expense.txt");
			string find;
			string G[600][20];
			int q=0,w=0,e=0,u=0,sum=0,I[20];
			while(getline(Sear,find)) {
			w=0;
			char *ptr6;
			char FI[50];
			char tab='\t';
			strcpy(FI,find.c_str());
			ptr6=strtok(FI,"'\t'");
				while ((ptr6 != NULL)&&w<=3)
				{
				G[q][w]=ptr6;
				ptr6=strtok(NULL,"'\t'");
				istringstream ssum(G[q][3]);
    			ssum >> I[q];///轉換變數型別以加總值 
				w++;
				}
			q++;
			e++;
		
			}
			for(q=0;q<=e-1;q++)
			{
				total=total+I[q];
				/*if(isdigit(I[q]))
				{
				total=total+I[q];
				cout<<"從過去到現在的總花費金額為 $" << total << endl;
				}*/
			}
			
			////印出金額/////// 
			SetColor(244);
			cout <<"從過去到現在的總花費金額為 $" << total << endl;
			Sear.close();
			}
			
			if(i==6)
			{
				//結束系統模式	
				break;
			}
		}
}


}

///進入購買模式/////////////// 
if(mode==1)
{
			while(1)
			{
			
			cout << "請輸入今天日期(EX:1060501)，如輸入000會離開購買系統:" << endl;
			cin >> date;
			if(date==000)
			{
				break;
			}
			referdate=date-1; //要叫出前一天的data來用 
			
			stringstream sss;
			sss << referdate;
			sss >>  sreferdate; //從int轉string 
			//cout << sreferdate;
			stringstream ssss;
			ssss << date;
			ssss >>  sdate;
			//cout << sdate;
			/////內部處理1，同上面做法，用於存取品項庫存data////// 
			ifstream inFile("stock_record.txt");
			string line;
			string E[600][20];
			int f=0,g=0,h=0;
			while(getline(inFile,line)) {
			g=0;
			char *ptr3;
			char ST[50];
			char tab='\t';
			strcpy(ST,line.c_str());
			ptr3=strtok(ST,"'\t'");
				while ((ptr3 != NULL)&&g<=3)
				{
				E[f][g]=ptr3;
				ptr3=strtok(NULL,"'\t'");
				g++;
				}
			f++;
			}
			f=0;
			while(E[f][0]!=sreferdate)
			{	
				E[0][0]=E[f+1][0];
				f++;
				h++;
			}
			f=0;
			g=0;
			for(f=0;f<14;f++)
			{
				for(g=0;g<4;g++)
				{
					E[f][g]=E[f+h][g];
					//cout << E[f][g] << endl;
				}
			}
			inFile.close();
			///////內部處理1結束////////// 
////////////////////////////////////////////////////
			/////內部處理2，用於存取硬幣庫存data////// 
			ifstream inFile2("coin_record.txt");
			string line2;
			string F[600][20];
			int r=0,t=0,y=0;
			while(getline(inFile2,line2)) {
			t=0;
			char *ptr5;
			char STF[50];
			char tab='\t';
			strcpy(STF,line2.c_str());
			ptr5=strtok(STF,"'\t'");
				while ((ptr5 != NULL)&&t<=3)
				{
				F[r][t]=ptr5;
				ptr5=strtok(NULL,"'\t'");
				t++;
				}
			r++;
			}
			r=0;
			
			while(F[r][0]!=sreferdate)
			{	
				F[0][0]=F[r+1][0];
				r++;
				y++;
			}
			r=0;
			t=0;
			for(r=0;r<4;r++)
			{
				for(t=0;t<3;t++)
				{
					F[r][t]=F[r+y][t];
				}
			}
			inFile2.close();
			///////內部處理2結束////////// 
////////////////下面兩種結構會用來存取在上面程式執行後得到的各個庫存數量////////////////////////////////////
//結構1 品項庫存用/////////// 
	typedef struct _stu{
	int price; //價錢 
	int code; //代碼 
	int num; //數量	
	int co; //計算賣出去的量 
	} stu;
	stu co;
	co.price=0;co.code=1;co.num=0;co.co=0;
	istringstream is1(E[0][2]);
    	is1 >> co.num;
    istringstream s1(E[0][3]);
    	s1 >> co.price;
	stu fa;
	fa.price=0;fa.code=2;fa.num=0;fa.co=0;
	istringstream is2(E[1][2]);
    	is2 >> fa.num;
    istringstream s2(E[1][3]);
    	s2 >> fa.price;
	stu cho;
	cho.price=0;cho.code=3;cho.num=0;cho.co=0;
	istringstream is3(E[2][2]);
    	is3 >> cho.num;
    istringstream s3(E[2][3]);
    	s3 >> cho.price;
	stu noo;
	noo.price=0;noo.code=4;noo.num=0;noo.co=0;
	istringstream is4(E[3][2]);
    	is4 >> noo.num;
    istringstream s4(E[3][3]);
    	s4 >> noo.price;
	stu h2o;
	h2o.price=0;h2o.code=5;h2o.num=0;h2o.co=0;
	istringstream is5(E[4][2]);
    	is5 >> h2o.num;
    istringstream s5(E[4][3]);
    	s5 >> h2o.price;
	stu sar;
	sar.price=18;sar.code=6;sar.num=0;sar.co=0;
	istringstream is6(E[5][2]);
    	is6 >> sar.num;
    istringstream s6(E[5][3]);
    	s6 >> sar.price;
	stu tea;
	tea.price=17;tea.code=7;tea.num=0;tea.co=0;
	istringstream is7(E[6][2]);
    	is7 >> tea.num;
    istringstream s7(E[6][3]);
    	s7 >> tea.price;
    stu soda;
    soda.price=20;soda.code=8;soda.num=0;soda.co=0;
	istringstream is8(E[7][2]);
    	is8 >> soda.num;
    istringstream s8(E[7][3]);
    	s8 >> soda.price;
    stu cookie;
    cookie.price=10;cookie.code=9;cookie.num=0;cookie.co=0;
	istringstream is9(E[8][2]);
    	is9 >> cookie.num;
    istringstream s9(E[8][3]);
    	s9 >> cookie.price;
    stu can;
	can.price=15;can.code=10;can.num=0;can.co=0;
	istringstream is10(E[9][2]);
    	is10 >> can.num;
    istringstream s10(E[9][3]);
    	s10 >> can.price;
	stu bread;
	bread.price=30;bread.code=11;bread.num=0;bread.co=0;
	istringstream is11(E[10][2]);
		is11 >> bread.num;
	istringstream s11(E[10][3]);
    	s11 >> bread.price;
	stu cof;
	cof.price=40;cof.code=12;cof.num=0;cof.co=0;
	istringstream is12(E[11][2]);
		is12 >> cof.num;
	istringstream s12(E[11][3]);
    	s12 >> cof.price;
	stu milk;
	milk.price=45;milk.code=13;milk.num=0;milk.co=0;
	istringstream is13(E[12][2]);
		is13 >> milk.num;
	istringstream s13(E[12][3]);
    	s13 >> milk.price;
	stu dodo;
	dodo.price=25;dodo.code=14;dodo.num=0;dodo.co=0;
	istringstream is14(E[13][2]);
		is14 >> dodo.num;
	istringstream s14(E[13][3]);
    	s14 >> dodo.price;
//結構1結束  

//結構2 硬幣庫存用//////////////////////////////////////
	typedef struct _mtu{
	int pri;
	int mnum; //數量	
	} mtu;
	mtu a50;
	a50.pri=50;a50.mnum=0;
	istringstream mo1(F[0][2]);
	mo1 >> a50.mnum;
					
	mtu a10;
	a10.pri=10;a10.mnum=0;
	istringstream mo2(F[1][2]);
	mo2 >> a10.mnum;
					
	mtu a5;
	a5.pri=5;a5.mnum=0;
	istringstream mo3(F[2][2]);
	mo3 >> a5.mnum;
				
	mtu a1;
	a1.pri=1;
	a1.mnum=0;
	istringstream mo4(F[3][2]);
	mo4 >> a1.mnum;
				
	//結構2結束 //////////////////////
	
	///////每日開始前，將3個檔案的資料(前幾日的data)
	//先存在另3個檔案內(daily_record_stock.txt、coin_record_stock.txt、daily.txt)
	//等到一天結束再貼回檔案///////// 
char ori[30]="stock_record.txt";
string st1;
ifstream inf2;
ofstream outf2("daily_record_stock.txt",ios_base::out);
inf2.open(ori);
if(!inf2.is_open())
{
cout<< ori << " is not exist."<<endl;
}else
{
while(getline(inf2,st1))
{
outf2<<st1 <<endl;
}
inf2.close();
outf2.close();
}

char ori2[30]="coin_record.txt";
string st2;
ifstream inf3;
ofstream outf3("coin_record_stock.txt",ios_base::out);
inf3.open(ori2);
if(!inf3.is_open())
{
cout<< ori2 << " is not exist."<<endl;
}else
{
while(getline(inf3,st2))
{
outf3<<st2 <<endl;
}
inf3.close();
outf3.close();
}

char dai1[30]="daily_expense.txt";
string ts1;
fstream inf10;
ofstream outf10("daily.txt",ios_base::out);
inf10.open(dai1);

while(getline(inf10,ts1))
{
outf10<<ts1 <<endl;
}
inf10.close();
outf10.close();


while(1){
SetColor(240);
cout <<"輸入123可開始購買/輸入321結束這一天: ";
cin >> pass;


if (pass==123)
{


m50=50;
m10=10;
m5=5;
m1=1;	
SetColor(243);
			
			cout << "請投幣後輸入代碼!" << endl 
				<< " cola $" << co.price << "代碼1" << endl
				<< " fanta $" << fa.price << "代碼2" << endl
				<< "chocolate pie $" << cho.price << "代碼3" << endl
				<< "instant noodles $" << noo.price << "代碼4" << endl 
				<< "water $" << h2o.price << "代碼5" << endl
				<< "sarsaparilla $" << sar.price << "代碼6" << endl
				<< "green tea $" << tea.price << "代碼7" << endl
				<< "soda $" << soda.price << "代碼8" << endl
				<< "cookie $" << cookie.price << "代碼9" << endl
				<< "candy $" << can.price << "代碼10" << endl
				<< "bread $" << bread.price << "代碼11" << endl
				<< "coffee $" << cof.price << "代碼12" << endl
				<< "milk $" << milk.price << "代碼13" << endl
				<< "yakult $" << dodo.price << "代碼14" << endl;	
				cout << "50元數量: ";
				cin >> n50;
				cout << "10元數量: ";
				cin >> n10;
				cout << "5元數量: ";
				cin >> n5;
				cout << "1元數量: ";
				cin >> n1;
			    money=n50*m50+n10*m10+n5*m5+n1*m1; //計算投入金額 
			    SetColor(244);
			    cout << "總共投入金額: " << money << endl;
			    cout << "輸入物品代碼: " ;
				cin >> math;
			
				
			//用switch將價格，庫存量存入real以及save 
			switch (math){
				case 1:
					real=co.price;
					save=co.num;
					//cout << save;
					break;
				case 2:
					real=fa.price;
					save=fa.num;
					break;
				case 3: 
					real=cho.price;
					save=cho.num;
					break;
				case 4:
					real=noo.price;
					save=noo.num;
					break;
				case 5:
					real=h2o.price;
					save=h2o.num;
					break;
				case 6:
					real=sar.price;
					save=sar.num;
					break;
				case 7:
					real=tea.price;
					save=tea.num;
					break;
				case 8:
					real=soda.price;
					save=soda.num;
					break;
				case 9:
					real=cookie.price;
					save=cookie.num;
					break;	
				case 10:
					real=can.price;
					save=can.num;
					break;
				case 11:
					real=bread.price;
					save=bread.num;
					break;
				case 12:
					real=cof.price;
					save=cof.num;	
					break;
				case 13:
					real=milk.price;
					save=milk.num;
					break;
				case 14:
					real=dodo.price;
					save=dodo.num;
					break;
			}

		
			///沒有庫存時///// 
			while (save==0&&math!=000)
			{
				SetColor(243);
				cout << "已無庫存，請輸入其他商品代碼或進行退幣(000)" << endl;
				cin >> math;
				switch (math){
				case 000:
					SetColor(244);
					cout << "退幣$" << money << "元" << endl; 
					break;
					
				case 1:
					real=co.price;
					save=co.num;
					break;
				case 2:
					real=fa.price;
					save=fa.num;
					break;
				case 3: 
					real=cho.price;
					save=cho.num;
					break;
				case 4:
					real=noo.price;
					save=noo.num;
					break;
				case 5:
					real=h2o.price;
					save=h2o.num;
					break;
				case 6:
					real=sar.price;
					save=sar.num;
					break;
				case 7:
					real=tea.price;
					save=tea.num;
					break;
				case 8:
					real=soda.price;
					save=soda.num;
					break;
				case 9:
					real=cookie.price;
					save=cookie.num;
					break;	
				case 10:
					real=can.price;
					save=can.num;
					break;
				case 11:
					real=bread.price;
					save=bread.num;
					break;
				case 12:
					real=cof.price;
					save=cof.num;	
					break;
				case 13:
					real=milk.price;
					save=milk.num;
					break;
				case 14:
					real=dodo.price;
					save=dodo.num;
					break;
			}
				
			}
			
			
			///投入硬幣數不夠時 //////////
			while (money < real)
			{
				SetColor(243);
				cout << "金額不足!請再投幣(並輸入con)!如不想繼續投幣請輸入end，機器將為您進行退幣" << endl;
				cin >> choose;
				if (choose=="end")
				{ 
				SetColor(244);
				cout << "退幣$" << money << "元"<< endl ; 
				break;
				} 
				else {
				////使用者繼續投錢///// 
				cout << "50元數量: ";
				cin >> ns50;
				nn50=nn50+ns50;//計算後來投的錢 
				cout << "10元數量: ";
				cin >> ns10;
				nn10=nn10+ns10;
				cout << "5元數量: ";
				cin >> ns5;
				nn5=nn5+ns5;
				cout << "1元數量: ";
				cin >> ns1;
				nn1=nn1+ns1;
				money=money+ns50*m50+ns10*m10+ns5*m5+ns1*m1;	
			}
			}
			///不用找錢且有庫存時///////////// 
			if (money==real&&save>0)
			{
				SetColor(244);
				cout << "請盡速拿取物品!" << endl;
				cout << "謝謝光臨!" << endl;
				///硬幣庫存量改變//////// 
				a50.mnum=a50.mnum+n50+nn50;
				a10.mnum=a10.mnum+n10+nn10;
				a5.mnum=a5.mnum+n5+nn5;
				a1.mnum=a1.mnum+n1+nn1;
				///品項庫存量改變//////// 
				///daily_expense改變，用__.co紀錄//////// 
				switch (math){
				case 1:
					co.num=co.num-1;
					co.co=co.co+1;
					break;
				case 2:
					fa.num=fa.num-1;
					fa.co=fa.co+1;
					break;
				case 3: 
					cho.num=cho.num-1;
					cho.co=cho.co+1;
					break;
				case 4:
					noo.num=noo.num-1;
					noo.co=noo.co+1; 
					break;
				case 5:
					h2o.num=h2o.num-1;
					h2o.co=h2o.co+1;
					break;
				case 6:
					sar.num=sar.num-1;
					sar.co=sar.co+1;
					break;
				case 7:
					tea.num=tea.num-1;
					tea.co=tea.co+1;
					break;
				case 8:
					soda.num=soda.num-1;
					soda.co=soda.co+1;
					break;
				case 9:
					cookie.num=cookie.num-1;
					cookie.co=cookie.co+1;
					break;	
				case 10:
					can.num=can.num-1;
					can.co=can.co+1;
					break;
				case 11:
					bread.num=bread.num-1;
					bread.co=bread.co+1;
					break;
				case 12:
					cof.num=cof.num-1;	
					cof.co=cof.co+1;
					break;
				case 13:
					milk.num=milk.num-1;
					milk.co=milk.co+1;
					break;
				case 14:
					dodo.num=dodo.num-1;
					dodo.co=dodo.co+1;
					break;
				
			}
			} 
	
			//需要找錢時/////////////
			if(money>real&&save>0)
			{
				///計算最適找法/////// 
				mm50=(money-real)/50;
				mm10=((money-real)%50)/10; 
				mm5=(((money-real)%50)%10)/5; 
				mm1=(((money-real)%50)%10)%5; 
				////目前硬幣庫存量更新///// 
				a50.mnum=a50.mnum+n50+nn50;
				a10.mnum=a10.mnum+n10+nn10;
				a5.mnum=a5.mnum+n5+nn5;
				a1.mnum=a1.mnum+n1+nn1;	
				////硬幣庫存量不夠應變方法//// 
				if(a10.mnum<mm10)
				{
				////10元不夠//// 
				mm5=mm5+(mm10-a10.mnum)*10/5;
				mm10=a10.mnum;
				if (a5.mnum<mm5)
				{
					////5元也不夠//// 
					mm1=mm1+(mm5-a5.mnum)*5;
					mm5=a5.mnum;
					if (a1.mnum<mm1)
					{
						////1元不夠，退幣//// 
						SetColor(244);
						cout << "零錢不足!即將退幣!請洽客服" <<endl;
						cout << "退幣$" << money << "元" << endl;
						////減掉以使庫存無變化///////////// 
						a50.mnum=a50.mnum-n50-nn50;
						a10.mnum=a10.mnum-n10-nn10;
						a5.mnum=a5.mnum-n5-nn5;
						a1.mnum=a1.mnum-n1-nn1;	
					}
				}
			}
				////5元不夠//// 
				else if (a5.mnum<mm5)
				{
					mm1=mm1+(mm5-a5.mnum)*5;
					mm5=a5.mnum;
					if (a1.mnum<mm1)
					{
						////1元也不夠，退幣//// 
						SetColor(244);
						cout << "零錢不足!即將退幣!請洽客服" <<endl;
						cout << "退幣$" << money << "元"<< endl ;
						a50.mnum=a50.mnum-n50-nn50;
						a10.mnum=a10.mnum-n10-nn10;
						a5.mnum=a5.mnum-n5-nn5;
						a1.mnum=a1.mnum-n1-nn1; 
					}
					
				}
			//1元不夠，退幣////// 
			else if (a1.mnum<mm1)
					{
						SetColor(244);
						cout << "零錢不足!即將退幣!請洽客服" <<endl;
						cout << "退幣$" << money << "元" << endl;
						a50.mnum=a50.mnum-n50-nn50;
						a10.mnum=a10.mnum-n10-nn10;
						a5.mnum=a5.mnum-n5-nn5;
						a1.mnum=a1.mnum-n1-nn1; 
					}
			/////錢足夠找零，找錢，購買物品完成//////////// 
			if ((mm50||mm10||mm5||mm1!=0)&& a1.mnum>=mm1 && choose!="end" )
			{
				SetColor(244);
				printf("找錢:\n"); 
				printf("50元硬幣:%d個\n",mm50); 
				printf("10元硬幣:%d個\n",mm10); 
				printf("5元硬幣:%d個\n",mm5); 
				printf("1元硬幣:%d個\n",mm1); 
				cout << "請盡速拿取物品!" << endl;
				cout << "謝謝光臨!" << endl;
				///硬幣庫存量改變//////// 
				a50.mnum=a50.mnum-mm50;
				a10.mnum=a10.mnum-mm10;
				a5.mnum=a5.mnum-mm5;
				a1.mnum=a1.mnum-mm1;
				///品項庫存量改變//////// 
				///daily_expense改變，用__.co紀錄//////// 
				switch (math){
				case 1:
					co.num=co.num-1;
					co.co=co.co+1;
					
					break;
				case 2:
					fa.num=fa.num-1;
					fa.co=fa.co+1;
					break;
				case 3: 
					cho.num=cho.num-1;
					cho.co=cho.co+1;
					break;
				case 4:
					noo.num=noo.num-1;
					noo.co=noo.co+1; 
					break;
				case 5:
					h2o.num=h2o.num-1;
					h2o.co=h2o.co+1;
					break;
				case 6:
					sar.num=sar.num-1;
					sar.co=sar.co+1;
					break;
				case 7:
					tea.num=tea.num-1;
					tea.co=tea.co+1;
					break;
				case 8:
					soda.num=soda.num-1;
					soda.co=soda.co+1;
					break;
				case 9:
					cookie.num=cookie.num-1;
					cookie.co=cookie.co+1;
					break;	
				case 10:
					can.num=can.num-1;
					can.co=can.co+1;
					break;
				case 11:
					bread.num=bread.num-1;
					bread.co=bread.co+1;
					break;
				case 12:
					cof.num=cof.num-1;	
					cof.co=cof.co+1;
					break;
				case 13:
					milk.num=milk.num-1;
					milk.co=milk.co+1;
					break;
				case 14:
					dodo.num=dodo.num-1;
					dodo.co=dodo.co+1;
					break;
					
									
			}
			}
		}
			/////每買一樣物品，分別修改3個檔案一次//////////////// 
					char daily1[20]="stock_record.txt";
					ofstream readFile(daily1,ios_base::out);
					readFile << "date" << '\t' << "item" << '\t' << "num" << '\t' << "price" << endl;
					readFile<< date <<'\t'<< "cocola" <<'\t'<< co.num <<'\t'<<co.price <<endl;
					readFile<< date <<'\t'<< "fanta" <<'\t'<< fa.num <<'\t'<<fa.price <<endl;
					readFile<< date <<'\t'<< "pie" <<'\t'<< cho.num <<'\t'<<cho.price <<endl;
					readFile<< date <<'\t'<< "noodle" <<'\t'<< noo.num <<'\t'<<noo.price <<endl;
					readFile<< date <<'\t'<< "water" <<'\t'<< h2o.num <<'\t'<<h2o.price <<endl;
					readFile<< date <<'\t'<< "sarsa." <<'\t'<< sar.num <<'\t'<<sar.price <<endl;
					readFile<< date <<'\t'<< "tea" <<'\t'<< tea.num <<'\t'<<tea.price<<endl;
					readFile<< date <<'\t'<< "soda" <<'\t'<< soda.num <<'\t'<<soda.price <<endl;
					readFile<< date <<'\t'<< "cookie" <<'\t'<< cookie.num <<'\t'<<cookie.price <<endl;
					readFile<< date <<'\t'<< "candy" <<'\t'<< can.num <<'\t'<<can.price <<endl;
					readFile<< date <<'\t'<< "bread" <<'\t'<< bread.num <<'\t'<<bread.price <<endl;
					readFile<< date <<'\t'<< "coffee" <<'\t'<< cof.num <<'\t'<<cof.price <<endl;
					readFile<< date <<'\t'<< "milk" <<'\t'<< milk.num <<'\t'<<milk.price <<endl;
					readFile<< date <<'\t'<< "yakult" <<'\t'<< dodo.num <<'\t'<<dodo.price<<endl<<endl;
					readFile.close();
					
					char daily3[20]="coin_record.txt";
					ofstream readmo(daily3,ios_base::out);
					readmo<< "date" << '\t' << "item" << '\t' << "num" <<endl;
					readmo<< date <<'\t'<< a50.pri <<'\t'<< a50.mnum <<endl;
					readmo<< date <<'\t'<< a10.pri <<'\t'<< a10.mnum <<endl;
					readmo<< date <<'\t'<< a5.pri <<'\t'<< a5.mnum <<endl;
					readmo<< date <<'\t'<< a1.pri <<'\t'<< a1.mnum <<endl<<endl;
					readmo.close();
					
					
					char daily2[20]="daily_expense.txt";
					ofstream readdaily(daily2,ios_base::out);
					readdaily<< "date" << '\t' << "item" << '\t' << "num" << '\t' << "sum" << endl;
					readdaily<< date <<'\t'<< "cocola" <<'\t'<< co.co <<'\t'<<co.price*co.co <<endl;
					readdaily<< date <<'\t'<< "fanta" <<'\t'<< fa.co <<'\t'<<fa.price*fa.co <<endl;
					readdaily<< date <<'\t'<< "pie" <<'\t'<< cho.co <<'\t'<<cho.price*cho.co <<endl;
					readdaily<< date <<'\t'<< "noodle" <<'\t'<< noo.co <<'\t'<<noo.price*noo.co <<endl;
					readdaily<< date <<'\t'<< "water" <<'\t'<< h2o.co <<'\t'<<h2o.price*h2o.co <<endl;
					readdaily<< date <<'\t'<< "sarsa." <<'\t'<< sar.co <<'\t'<<sar.price*sar.co <<endl;
					readdaily<< date <<'\t'<< "tea" <<'\t'<< tea.co <<'\t'<<tea.price*tea.co <<endl;
					readdaily<< date <<'\t'<< "soda" <<'\t'<< soda.co <<'\t'<<soda.price*soda.co <<endl;
					readdaily<< date <<'\t'<< "cookie" <<'\t'<< cookie.co <<'\t'<<cookie.price*cookie.co <<endl;
					readdaily<< date <<'\t'<< "candy" <<'\t'<< can.co <<'\t'<<can.price*can.co <<endl;
					readdaily<< date <<'\t'<< "bread" <<'\t'<< bread.co <<'\t'<<bread.price*bread.co <<endl;
					readdaily<< date <<'\t'<< "coffee" <<'\t'<< cof.co <<'\t'<<cof.price*cof.co <<endl;
					readdaily<< date <<'\t'<< "milk" <<'\t'<< milk.co <<'\t'<<milk.price*milk.co <<endl;
					readdaily<< date <<'\t'<< "yakult" <<'\t'<< dodo.co <<'\t'<<dodo.price*dodo.co <<endl<<endl;
					readdaily.close();
					
					
					
			}
///今天的買賣結束，將今天的變動寫入stock_record、coin_record、daily_expense中////////////////////					
if(pass==321)
{					
					char ori3[30]="stock_record.txt";
					string st3;
					ifstream inf4;
					ofstream outf4("daily_record_stock.txt",ios_base::app);
					inf4.open(ori3);
					if(!inf4.is_open())
					{
					cout<< ori3 << " is not exist."<<endl;
					}else
					{
					while(getline(inf4,st3))
					{
					outf4<<st3 <<endl;
					}
					inf4.close();
					outf4.close();
					}
					
					char ori4[40]="daily_record_stock.txt";
					ifstream inf5;
					string st4;
					ofstream outf5("stock_record.txt",ios_base::out);
					inf5.open(ori4);
					if(!inf5.is_open())
					{
					cout<< ori4 << " is not exist."<<endl;
					}else
					{
					while(getline(inf5,st4))
					{
					outf5<<st4 <<endl;
					}
					inf5.close();
					outf5.close();
					}
					
					
					char ori5[30]="coin_record.txt";
					string st5;
					fstream inf6;
					fstream outf6("coin_record_stock.txt",ios_base::app);
					inf6.open(ori5);
					if(!inf6.is_open())
					{
					cout<< ori5 << " is not exist."<<endl;
					}else
					{
					while(getline(inf6,st5))
					{
					outf6<<st5 <<endl;
					}
					inf6.close();
					outf6.close();
					}
					
					char ori6[40]="coin_record_stock.txt";
					string st6;
					fstream inf7;
					fstream outf7("coin_record.txt",ios_base::out);
					inf7.open(ori6);
					if(!inf7.is_open())
					{
					cout<< ori6 << " is not exist."<<endl;
					}else
					{
					while(getline(inf7,st6))
					{
					outf7<<st6 <<endl;
					}
					inf7.close();
					outf7.close();
					}
					
					char dai2[30]="daily_expense.txt";
					string ts2;
					ifstream inf11;
					ofstream outf11("daily.txt",ios_base::app);
					inf11.open(dai2);
					if(!inf11.is_open())
					{
					cout<< dai2 << " is not exist."<<endl;
					}else
					{
					while(getline(inf11,ts2))
					{
					outf11<<ts2 <<endl;
					}
					inf11.close();
					outf11.close();
					}
					
					char dai3[30]="daily.txt";
					string ts3;
					ifstream inf12;
					ofstream outf12("daily_expense.txt",ios_base::out);
					inf12.open(dai3);
					if(!inf12.is_open())
					{
					cout<< dai3 << " is not exist."<<endl;
					}else
					{
					while(getline(inf12,ts3))
					{
					outf12<<ts3 <<endl;
					}
					inf12.close();
					outf12.close();
					}

					
					
					
					break;
			}			
}

				
}
}
if(mode==3)
{
	break;
}

}
}


//main主程式結束 






