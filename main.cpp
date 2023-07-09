#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;
	int GCD = 1;

public:
	Fraction()
	{

	}
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	Fraction operator +(const Fraction& other)
	{
		Fraction temp;
		temp.numerator_ = numerator_ * other.denominator_ + denominator_ * other.numerator_;
		temp.denominator_ = denominator_ * other.denominator_;
		return temp;
	}
	Fraction operator -(const Fraction& other)
	{
		Fraction temp;
		temp.numerator_ = numerator_ * other.denominator_ - denominator_ * other.numerator_;
		temp.denominator_ = denominator_ * other.denominator_;
		return temp;
	}
	Fraction operator *(const Fraction& other)
	{
		Fraction temp;
		temp.numerator_ = numerator_ * other.numerator_;
		temp.denominator_ = denominator_ * other.denominator_;
		this->GCD = greatest_common_divisor(temp.numerator_, temp.denominator_);
		temp.numerator_ = temp.numerator_ / GCD;
		temp.denominator_ = temp.denominator_ / GCD;
		return temp;
	}
	Fraction operator /(const Fraction& other)
	{
		Fraction temp;
		temp.numerator_ = numerator_ * other.denominator_;
		temp.denominator_ = denominator_ * other.numerator_;
		return temp;
	}
	Fraction& operator ++()
	{
		numerator_ = numerator_ + denominator_;
		denominator_ = denominator_;
		return *this;
	}
	Fraction operator ++(int value)
	{
		Fraction temp = *this;
		numerator_ = numerator_ + denominator_;
		denominator_ = denominator_;
		return temp;
	}
	Fraction& operator --()
	{
		numerator_ = numerator_ - denominator_;
		denominator_ = denominator_;
		return *this;
	}
	Fraction operator --(int value)
	{
		Fraction temp = *this;
		numerator_ = numerator_ - denominator_;
		denominator_ = denominator_;
		return temp;
	}
	int greatest_common_divisor(int numerator, int denominator)
	{
		for (int i = ((numerator) > (denominator) ? (denominator) : (numerator)); i > 0; i--)
		{

			if (numerator % i == 0 && denominator % i == 0)
			{
				GCD = i; break;
			}
		}
		return GCD;
	}
	void Print()
	{
		std::cout << numerator_ << "/" << denominator_;
	}
};

int main()
{
	setlocale(0, "");

	int numerator, denominator;

	std::cout << "¬ведите числитель дроби 1: ";
	std::cin >> numerator;
	std::cout << "¬ведите знаменатель дроби 1: ";
	std::cin >> denominator;

	Fraction fr1(numerator, denominator);

	std::cout << "¬ведите числитель дроби 2: ";
	std::cin >> numerator;
	std::cout << "¬ведите знаменатель дроби 2: ";
	std::cin >> denominator;

	Fraction fr2(numerator, denominator);

	Fraction Add = fr1 + fr2;
	std::cout << "\n"; fr1.Print(); std::cout << " + "; fr2.Print(); std::cout << " = "; Add.Print();

	Fraction Sub = fr1 - fr2;
	std::cout << "\n"; fr1.Print(); std::cout << " - "; fr2.Print(); std::cout << " = "; Sub.Print();

	Fraction Mult = fr1 * fr2;
	std::cout << "\n"; fr1.Print(); std::cout << " * "; fr2.Print(); std::cout << " = "; Mult.Print();

	Fraction Div = fr1 / fr2;
	std::cout << "\n"; fr1.Print(); std::cout << " / "; fr2.Print(); std::cout << " = "; Div.Print();

	std::cout << "\n++"; fr1.Print(); std::cout << " * "; fr2.Print(); std::cout << " = ";

	++fr1;
	Mult = fr1 * fr2; Mult.Print();

	std::cout << "\n«начение дроби 1 = "; fr1.Print();

	std::cout << "\n"; fr1.Print(); std::cout << "-- * "; fr2.Print(); std::cout << " = ";

	fr1--;
	Mult = fr1 * fr2; Mult.Print();

	std::cout << "\n«начение дроби 1 = "; fr1.Print(); std::cout << "\n\n";
}