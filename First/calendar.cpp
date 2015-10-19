#include<iostream>
#include<iomanip>
using namespace std;
class Date
{
private:
	int year;
	int month;
	int day;
	int monthDay[12];
public:
	Date(int y=1,int m=1,int d=1)//:year(y),month(m),day(d)//设置带有默认值的构造函数
	{
    year=y;                     //数据成员赋初值
	month=m;
	day=d;
	monthDay[0]=31;
	monthDay[1]=28;
	monthDay[2]=31;
	monthDay[3]=30;
	monthDay[4]=31;
	monthDay[5]=30;
	monthDay[6]=31;
	monthDay[7]=31;
	monthDay[8]=30;
	monthDay[9]=31;
	monthDay[10]=30;
	monthDay[11]=31;
	}
    
//判断某一年是否为闰年
bool Isleapyear(int y)
{

	return ((y%4==0 && y%100!=0))||(y%400==0);     
}
int GetYearDays(int y){ 

	if(Isleapyear(y))
		return 366;
        return 365;
}
//日期转换为天数
int DateToNum(){
	int sum=0;
	int i=0;
	for(i=1;i<year;i++)
		sum+=GetYearDays(i);     //计算该年以前的所有天数之和
	if(Isleapyear(year))
        monthDay[1]=29;
	else
		monthDay[1]=28;
	for(int j=1;j<month;j++)     //计算该月之前所有天数之和
		sum+=monthDay[j-1];
	    return sum+day;          //返回总天数

}

//输入年月，输出该月日历
void OutputYearMonthDate(int y,int m)
{
if(y<=0)
return;
Date d;                    //调用带有参数默认值的构造函数
d.year=y;
d.month=m;
d.day=1;
cout<<endl<<endl<<setw(15)<<y<<"年"<<m<<"月"<<endl;
cout<<endl;
cout<<endl<<setw(5)<<"SUN"<<setw(5)<<"MON"<<setw(5)<<"TUE"<<setw(5)<<"WED"
<<setw(5)<<"THU"<<setw(5)<<"FRI"<<setw(5)<<"SAT"<<endl;
cout<<"------------------------------------------------"<<endl;
cout<<setw(5*(d.DateToNum()%7)+5)<<1;           //计算某年某月的第一天对应的星期位置
for(int j=1;j<d.monthDay[m-1];j++){
if((j+(d.DateToNum()%7))%7==0)                  //计算该月的其余天对应的星期位置
cout<<endl;                                     //输出的天数等于7天，则换行输出后面的一天
cout<<setw(5)<<j+1;
}
cout<<endl;
cout<<"------------------------------------------------"<<endl;

}
};

//主函数
int main(void)
{
cout<<endl<<"        --------------------------------------"<<endl;
cout<<"                   ******  万年历  ******"<<endl;
cout<<"        --------------------------------------"<<endl<<endl;
int year;
int month;
char choose;
cout<<"  请输入您要进行的操作：0——退出，其他键——继续"<<endl;
while(true){
	cin>>choose;
	if(choose=='0'){
	break;
	}
	cout<<"请输入您要查询的年份：";
	cin>>year;
    cout<<"请输入您要查询的月份：";
	cin>>month;
	Date d(year, month);      //调用带有参数默认值的构造函数，创建对象
	if(year<1||month>12||month<1){
	cout<<"您的输入有误，请重新输入！"<<endl;
	}
	else{
    d.OutputYearMonthDate(year,month);
	}
	cout<<"请输入您要进行的操作：0——退出，其他键——继续"<<endl;
}
return 0;


}