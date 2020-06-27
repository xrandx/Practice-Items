// 一个类的友元函数可以访问该类的私有成员
class CCar; //提前声明 CCar类, 以便后面CDriver类使用

class CDriver
{
	public:
		void ModifyCar( CCar * pCar) ; //改装汽车
};

class CCar
{
	private:
		int price;
		friend int MostExpensiveCar( CCar cars[], int total); //声明友元 类外函数
		friend void CDriver::ModifyCar(CCar * pCar); //声明友元 其他类函数
};

void CDriver::ModifyCar( CCar * pCar)
{
	pCar->price += 1000; 
}

class B
{
	public:
		void function();
};

class A
{
		friend void B::function();//其他类函数作用于该类
};

int MostExpensiveCar( CCar cars[], int total) //求最贵汽车的价格
{
	int tmpMax = -1;
	for( int i = 0; i < total; ++i )
		if( cars[i].price > tmpMax)
			tmpMax = cars[i].price;
	return tmpMax;
}

class CCar
{
	private:
		int price;
		friend class CDriver;
         //声明CDriver为友元类
         // CDriver是CCar的友元类?可以访问其私有成员
};
class CDriver
{
	public:
		CCar myCar;
		void ModifyCar()   //改装汽车
		{
			myCar.price += 1000; 
		}
};
// 友元类之间的关系
// 不能传递, 不能继承
int main()
{
	return 0;
}
