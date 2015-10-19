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
	Date(int y=1,int m=1,int d=1)//:year(y),month(m),day(d)//���ô���Ĭ��ֵ�Ĺ��캯��
	{
    year=y;                     //���ݳ�Ա����ֵ
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
    
//�ж�ĳһ���Ƿ�Ϊ����
bool Isleapyear(int y)
{

	return ((y%4==0 && y%100!=0))||(y%400==0);     
}
int GetYearDays(int y){ 

	if(Isleapyear(y))
		return 366;
        return 365;
}
//����ת��Ϊ����
int DateToNum(){
	int sum=0;
	int i=0;
	for(i=1;i<year;i++)
		sum+=GetYearDays(i);     //���������ǰ����������֮��
	if(Isleapyear(year))
        monthDay[1]=29;
	else
		monthDay[1]=28;
	for(int j=1;j<month;j++)     //�������֮ǰ��������֮��
		sum+=monthDay[j-1];
	    return sum+day;          //����������

}

//�������£������������
void OutputYearMonthDate(int y,int m)
{
if(y<=0)
return;
Date d;                    //���ô��в���Ĭ��ֵ�Ĺ��캯��
d.year=y;
d.month=m;
d.day=1;
cout<<endl<<endl<<setw(15)<<y<<"��"<<m<<"��"<<endl;
cout<<endl;
cout<<endl<<setw(5)<<"SUN"<<setw(5)<<"MON"<<setw(5)<<"TUE"<<setw(5)<<"WED"
<<setw(5)<<"THU"<<setw(5)<<"FRI"<<setw(5)<<"SAT"<<endl;
cout<<"------------------------------------------------"<<endl;
cout<<setw(5*(d.DateToNum()%7)+5)<<1;           //����ĳ��ĳ�µĵ�һ���Ӧ������λ��
for(int j=1;j<d.monthDay[m-1];j++){
if((j+(d.DateToNum()%7))%7==0)                  //������µ��������Ӧ������λ��
cout<<endl;                                     //�������������7�죬������������һ��
cout<<setw(5)<<j+1;
}
cout<<endl;
cout<<"------------------------------------------------"<<endl;

}
};

//������
int main(void)
{
cout<<endl<<"        --------------------------------------"<<endl;
cout<<"                   ******  ������  ******"<<endl;
cout<<"        --------------------------------------"<<endl<<endl;
int year;
int month;
char choose;
cout<<"  ��������Ҫ���еĲ�����0�����˳�����������������"<<endl;
while(true){
	cin>>choose;
	if(choose=='0'){
	break;
	}
	cout<<"��������Ҫ��ѯ����ݣ�";
	cin>>year;
    cout<<"��������Ҫ��ѯ���·ݣ�";
	cin>>month;
	Date d(year, month);      //���ô��в���Ĭ��ֵ�Ĺ��캯������������
	if(year<1||month>12||month<1){
	cout<<"���������������������룡"<<endl;
	}
	else{
    d.OutputYearMonthDate(year,month);
	}
	cout<<"��������Ҫ���еĲ�����0�����˳�����������������"<<endl;
}
return 0;


}