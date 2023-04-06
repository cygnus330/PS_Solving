struct Complex
{
	float r;
	float i;

	Complex(float real, float imag) : r(real), i(imag) {}
	Complex(float real) : r(real), i(0) {}
	Complex() : r(0), i(0) {}

	float abs() {return r*r - i*i;}

	Complex operator+(Complex &a) {return Complex(r + a.r, i + a.i);}
	Complex operator-(Complex &a) {return Complex(r - a.r, i - a.i);}
	Complex operator*(Complex &a) {return Complex(r*a.r - i*a.i, r*a.i + i*a.r);}
	Complex operator/(float &a) {return Complex(r/a, i/a);}
};