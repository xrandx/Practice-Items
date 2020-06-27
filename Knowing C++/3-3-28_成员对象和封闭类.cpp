// 成员对象和封闭类
#include <iostream>
class CTyre   //轮胎类
{
	private:
		int radius; //半径
		int width; //宽度
	public:
		CTyre(int r, int w):radius(r), width(w) { }
};

class CEngine   //引擎类
{
};

class CCar   //汽车类 ? “封闭类”
{
	private:
		int price; //价格
		CTyre tyre;
		CEngine engine;
// 成员对象的构造函数调用顺序
// ? 和成员对象在类中的说明顺序一致
// ? 与在成员初始化列表中出现的顺序无关
	public:
		CCar(int p, int tr, int tw);
};

CCar::CCar(int p, int tr, int w):price(p), tyre(tr, w)
{
};
// 如果 CCar 类不定义构造函数, 则
// CCar car; // error ? 编译出错

int main()
{
// 当封闭类对象生成时,
// ? S1: 执行所有成员对象 的构造函数
// ? S2: 执行 封闭类 的构造函数
	CCar car(20000,17,225);
// 当封闭类的对象消亡时,
// ? S1: 先执行 封闭类 的析构函数
// ? S2: 执行 成员对象 的析构函数
// 析构函数顺序和构造函数的调用顺序相反
	return 0;
}
