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
	cout<<"工人姓名："<<name<<","<<"工人年龄："<<age<<","<<"工人性别："<<sex
			<<","<<"小时工资额："<<pay_per_hour<<","<<"薪金等级:"<<band<<endl;
	}
	void Name(int i){
	cout<<i+1<<"--------------"<<name<<endl;
	}
};
    ostream& operator<<(ostream& out, Worker& worker)      //运算符<<重载函数
	{
		out<<"工人姓名："<<worker.name<<","<<"工人年龄："<<worker.age<<","<<"工人性别："<<worker.sex
			<<","<<"小时工资额："<<worker.pay_per_hour<<","<<"薪金等级:"<<worker.band<<endl;
	    return out;
	}
	//派生类
class HourlyWorker:public Worker{
	private:

        double salary;
	public:
        HourlyWorker(char* b,char* n,int a,char* s1,double p):Worker(n,a,s1,p,b)//构造
		{
		}
        void compute_pay(double hours){       //根据实际工作时间，选择调用执行的函数
	
			if(hours<=40)             
			{
				salary=pay_per_hour*hours;
				cout<<"该工人的工薪为："<<salary<<endl;
			}
			else
			{
				salary=pay_per_hour*40+1.5*pay_per_hour*(hours-40);
			    cout<<"该工人的工薪为："<<salary<<endl;
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
    void compute_pay(double hours)//因为每个人的小时工资额都已确定（在类中已定义），因此只要判断工作时间即可
	{
	        if(hours>=35)
			{
			salary=pay_per_hour*40;//周薪 = 小时工资额*实际工作时数 + 0.5 × 小时工资额 × (35 - 实际工作时数)。
			cout<<"该工人的工薪为："<<salary<<endl;
			}
			else
			{
				salary=pay_per_hour*hours+0.5*pay_per_hour*(35-hours);
				cout<<"该工人的工薪为："<<salary<<endl;
			}
	}

};
//主函数
void main(){

Worker *workers[5];                       //定义含5个元素的对象指针数组
workers[0]=new HourlyWorker("计时工人1级","李明",20,"男",10);//5个new对应5个delete
workers[1]=new HourlyWorker("计时工人2级","王红",30,"女",20);
workers[2]=new HourlyWorker("计时工人3级","孙杰",40,"男",40);
workers[3]=new SalariedWorker("计薪工人1级","刘然",32,"男",30);
workers[4]=new SalariedWorker("计薪工人2级","陶虹",50,"女",50);
//cout<<workers[i];                //operator<<(cout,workers[0])若直接调用会出现问题，输出为地址值
cout<<"工人信息显示如下："<<endl;
for(int i=0;i<5;i++){
workers[i]->print();
}
while(i)
{
	cout<<endl;
cout<<"请选择您要进行查看的工人编号:"<<endl;
for(i=0;i<5;i++){
workers[i]->Name(i);
}
cin>>i;
switch(i){
case 1:
     cout<<"该用户的信息为："<<endl;
	 workers[0]->print();                                      
	 cout<<"请输入该工作人员的实际工作数：";
	 cin>>i;
     workers[0]->compute_pay(i);                    //动态多态，调用子类的函数
	 break;
case 2:
     cout<<"该用户的信息为："<<endl;
	 workers[1]->print();                                      
	 cout<<"请输入该工作人员的实际工作数：";
	 cin>>i;
     workers[1]->compute_pay(i);                     //动态多态，调用子类的函数
	 break;
case 3:
     cout<<"该用户的信息为："<<endl;
	 workers[2]->print();                                      
	 cout<<"请输入该工作人员的实际工作数：";
	 cin>>i;
     workers[2]->compute_pay(i);                      //动态多态，调用子类的函数
	 break;
case 4:
     cout<<"该用户的信息为："<<endl;
	 workers[3]->print();                                     
	 cout<<"请输入该工作人员的实际工作数：";
	 cin>>i;
     workers[3]->compute_pay(i);                        //动态多态，调用子类的函数
	 break;
case 5:
     cout<<"该用户的信息为："<<endl;
	  workers[4]->print();                                     
	 cout<<"请输入该工作人员的实际工作数：";
	 cin>>i;
     workers[4]->compute_pay(i);                        //动态多态，调用子类的函数
	 break;
}
cout<<"请选择您要进行的操作：0------退出，其他键------继续";
cin>>i;
}
for(i=0;i<5;i++)
delete workers[i];
}