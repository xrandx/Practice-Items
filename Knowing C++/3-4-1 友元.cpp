// һ�������Ԫ�������Է��ʸ����˽�г�Ա
class CCar; //��ǰ���� CCar��, �Ա����CDriver��ʹ��

class CDriver
{
	public:
		void ModifyCar( CCar * pCar) ; //��װ����
};

class CCar
{
	private:
		int price;
		friend int MostExpensiveCar( CCar cars[], int total); //������Ԫ ���⺯��
		friend void CDriver::ModifyCar(CCar * pCar); //������Ԫ �����ຯ��
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
		friend void B::function();//�����ຯ�������ڸ���
};

int MostExpensiveCar( CCar cars[], int total) //����������ļ۸�
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
         //����CDriverΪ��Ԫ��
         // CDriver��CCar����Ԫ��?���Է�����˽�г�Ա
};
class CDriver
{
	public:
		CCar myCar;
		void ModifyCar()   //��װ����
		{
			myCar.price += 1000; 
		}
};
// ��Ԫ��֮��Ĺ�ϵ
// ���ܴ���, ���ܼ̳�
int main()
{
	return 0;
}
