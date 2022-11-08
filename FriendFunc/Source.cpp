#include<iostream>

using namespace std;
//class Money;


class Money
{
	int rub;
	int kop;
public:
	Money()//rub = 0; kop = 0;
	{
		rub = 0;
		kop = 0;
	}
	Money(int rub, int kop)
	{
		this->rub = rub;
		this->kop = kop;
	}
	Money(int); //пересчет
	Money(float);// пересчет
	friend Money operator+(Money m1, Money m2)
	{
		return Money(m1.get_koppeek() + m2.get_koppeek());
	}
	friend class SummaClass;
	friend bool operator==(Money m1, Money m2)
	{

		if(m1.get_koppeek() == m2.get_koppeek())
			return true;
		else
		{
			return false;
		}
	}
	friend Money operator/(Money m1, int div)
	{
		return Money(m1.get_koppeek() / 3);
	}
	double get_money()
	{
		return (double)(rub + kop / 100);
	}
	friend double operator-(double c, Money m1)
	{
		return c - m1.get_money();
	
	}
	
	Money operator*=(int div) 
	{
		int kops = rub * 100 + kop;
		kops *= div;
		rub = kops / 100;
		kop = kops % 100;
		return *this;
	}
	void set_kop(int a)
	{
		kop = 0;
	}
	void set_rub(int a)
	{
		rub = 0;
	}
	Money operator+=(Money m1)
	{
		int kopeek = this->get_koppeek() + m1.get_koppeek();
		
		rub = kopeek / 100;
		kop = kopeek % 100;
		return *this;
	}

	friend bool operator>(Money m1, Money m2)
	{

		if (m1.get_koppeek() > m2.get_koppeek())
			return true;
		else
		{
			return false;
		}
	}
	friend bool operator<(Money m1, Money m2)
	{

		if (m1.get_koppeek() < m2.get_koppeek())
			return true;
		else
		{
			return false;
		}
	}
	friend bool operator<=(Money m1, Money m2)
	{

		if (m1.get_koppeek() <= m2.get_koppeek())
			return true;
		else
		{
			return false;
		}
	}
	friend bool operator>=(Money m1, Money m2)
	{

		if (m1.get_koppeek() >= m2.get_koppeek())
			return true;
		else
		{
			return false;
		}
	}
	int get_koppeek()
	{
		return rub * 100 + kop;
	}
	void print() 
	{
		cout << rub <<" rubles " << kop <<" kopeek\n";
	}

};


Money::Money(int _kops) 
{
	kop = _kops % 100;
	rub = (_kops - kop) / 100;
}
Money::Money(float _buble)
{
	rub = (int)_buble;
	kop = (int)((_buble - rub) * 100);

}
void PrintObject(Money mArray[], int count)
{
	for (int i = 0; i<count; i++)
	{
		mArray[i].print();
	}
}

class SummaClass
{
	Money summa;
public:
	SummaClass()
	{
		summa.set_rub(0);
		summa.set_kop(0);
	}
	void GetSumma(Money mArray[], int count)
	{
		for (int i = 0; i < count; i++)
		{
			summa += mArray[i];
		}
		summa.print();
		summa.set_rub(0);
		summa.set_kop(0);
	}
	void getByIndex(Money mArray[], int index)
	{
		mArray[index].print();
	}
	void show_sum(Money m1, Money m2)
	{
		int rub = (m1.get_koppeek() + m2.get_koppeek()) / 100;
		int kop = ((int)(m1.get_koppeek() + m2.get_koppeek())) % 100;
		cout << rub  << "\t" << kop << "\n";
	}

};

int main()
{
	Money m1;
	Money m2(1, 50);
	Money m3(250);
	Money m4(1.50f);
	Money mArraY[]{ m1,m2,m3, m4 };
	PrintObject(mArraY, sizeof(mArraY)/sizeof(Money));
	/*cout << (m2 >= m4);
	cout << '\n';
	Money m5 = m2 + m4;
	m5.print();
	Money m6 = m2 / 3 ;
	m6.print();
	m6 *= 3;
	m6.print();
	m6 -= 0.5;
	m6.print();
	double x = 5.5 - m6;
	cout << (int)x<<" rubles " <<((int)(x*100))%100<<" kopeek\n";
	*/
	SummaClass summa;
	summa.GetSumma(mArraY, sizeof(mArraY) / sizeof(Money));
	summa.getByIndex(mArraY, 3);
	summa.show_sum(m2, m4);
	return 0;
}