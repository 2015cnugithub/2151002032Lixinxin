#include<iostream.h>
class Worker{
private:
	char* name;
	int age;
	char* sex;
    char* band;
	
public:
	double pay_per_hour;
	virtual void compute_pay(double hours)=0;
	friend ostream& operator<<(ostream& out, Worker& worker);
    Worker(char* n,int a,char* s,double p,char* b){
	name=n;
	age=a;
	sex=s;
    pay_per_hour=p;
	band=b;
	
	}
	void print(){
	cout<<"����������"<<name<<","<<"�������䣺"<<age<<","<<"�����Ա�"<<sex
			<<","<<"Сʱ���ʶ"<<pay_per_hour<<","<<"н��ȼ�:"<<band<<endl;
	}
	void Name(int i){
	cout<<i+1<<"--------------"<<name<<endl;
	}
};
    ostream& operator<<(ostream& out, Worker& worker)      //�����<<���غ���
	{
		out<<"����������"<<worker.name<<","<<"�������䣺"<<worker.age<<","<<"�����Ա�"<<worker.sex
			<<","<<"Сʱ���ʶ"<<worker.pay_per_hour<<","<<"н��ȼ�:"<<worker.band<<endl;
	    return out;
	}
	//������
class HourlyWorker:public Worker{
	private:

        double salary;
	public:
        HourlyWorker(char* b,char* n,int a,char* s1,double p):Worker(n,a,s1,p,b)//����
		{
		}
        void compute_pay(double hours){       //����ʵ�ʹ���ʱ�䣬ѡ�����ִ�еĺ���
	
			if(hours<=40)             
			{
				salary=pay_per_hour*hours;
				cout<<"�ù��˵Ĺ�нΪ��"<<salary<<endl;
			}
			else
			{
				salary=pay_per_hour*40+1.5*pay_per_hour*(hours-40);
			    cout<<"�ù��˵Ĺ�нΪ��"<<salary<<endl;
			}
		}
	
	};
class SalariedWorker:public Worker
{
private:
       double salary;
public:
	SalariedWorker(char* b,char* n,int a,char* s1,double p):Worker(n,a,s1,p,b)
	{ 
	}
    void compute_pay(double hours)//��Ϊÿ���˵�Сʱ���ʶ��ȷ�����������Ѷ��壩�����ֻҪ�жϹ���ʱ�伴��
	{
	        if(hours>=35)
			{
			salary=pay_per_hour*40;//��н = Сʱ���ʶ�*ʵ�ʹ���ʱ�� + 0.5 �� Сʱ���ʶ� �� (35 - ʵ�ʹ���ʱ��)��
			cout<<"�ù��˵Ĺ�нΪ��"<<salary<<endl;
			}
			else
			{
				salary=pay_per_hour*hours+0.5*pay_per_hour*(35-hours);
				cout<<"�ù��˵Ĺ�нΪ��"<<salary<<endl;
			}
	}

};
//������
void main(){

Worker *workers[5];                       //���庬5��Ԫ�صĶ���ָ������
workers[0]=new HourlyWorker("��ʱ����1��","����",20,"��",10);//5��new��Ӧ5��delete
workers[1]=new HourlyWorker("��ʱ����2��","����",30,"Ů",20);
workers[2]=new HourlyWorker("��ʱ����3��","���",40,"��",40);
workers[3]=new SalariedWorker("��н����1��","��Ȼ",32,"��",30);
workers[4]=new SalariedWorker("��н����2��","�պ�",50,"Ů",50);
//cout<<workers[i];                //operator<<(cout,workers[0])��ֱ�ӵ��û�������⣬���Ϊ��ֵַ
cout<<"������Ϣ��ʾ���£�"<<endl;
for(int i=0;i<5;i++){
workers[i]->print();
}
while(i)
{
	cout<<endl;
cout<<"��ѡ����Ҫ���в鿴�Ĺ��˱��:"<<endl;
for(i=0;i<5;i++){
workers[i]->Name(i);
}
cin>>i;
switch(i){
case 1:
     cout<<"���û�����ϢΪ��"<<endl;
	 workers[0]->print();                                      
	 cout<<"������ù�����Ա��ʵ�ʹ�������";
	 cin>>i;
     workers[0]->compute_pay(i);                    //��̬��̬����������ĺ���
	 break;
case 2:
     cout<<"���û�����ϢΪ��"<<endl;
	 workers[1]->print();                                      
	 cout<<"������ù�����Ա��ʵ�ʹ�������";
	 cin>>i;
     workers[1]->compute_pay(i);                     //��̬��̬����������ĺ���
	 break;
case 3:
     cout<<"���û�����ϢΪ��"<<endl;
	 workers[2]->print();                                      
	 cout<<"������ù�����Ա��ʵ�ʹ�������";
	 cin>>i;
     workers[2]->compute_pay(i);                      //��̬��̬����������ĺ���
	 break;
case 4:
     cout<<"���û�����ϢΪ��"<<endl;
	 workers[3]->print();                                     
	 cout<<"������ù�����Ա��ʵ�ʹ�������";
	 cin>>i;
     workers[3]->compute_pay(i);                        //��̬��̬����������ĺ���
	 break;
case 5:
     cout<<"���û�����ϢΪ��"<<endl;
	  workers[4]->print();                                     
	 cout<<"������ù�����Ա��ʵ�ʹ�������";
	 cin>>i;
     workers[4]->compute_pay(i);                        //��̬��̬����������ĺ���
	 break;
}
cout<<"��ѡ����Ҫ���еĲ�����0------�˳���������------����";
cin>>i;
}
for(i=0;i<5;i++)
delete workers[i];
}