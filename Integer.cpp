
#include"Integer.h"


/*validar si es un numero*/
Integer::Integer(long long number) {

	
	do {
		if (number >= 0) {
			digits.push_back(number % 10);

			number = number / 10;
		}
		else {

			long long aux = abs(number);


			digits.push_back(aux % 10);

			number = number / 10;
		
			if (number==0) {

				digits.push_back('-');
			}
		}

	} while (number);

}

Integer::Integer() {

	digits.push_back('0');
}

Integer::Integer(long number) {

	do {
		if (number >= 0) {
			digits.push_back(number % 10);

			number = number / 10;
		}
		else {

			long aux = abs(number);


			digits.push_back(aux % 10);

			number = number / 10;

			if (number == 0) {

				digits.push_back('-');
			}
		}

	} while (number);

}

Integer::Integer(int number) {

	do {
		if (number >= 0) {
			digits.push_back(number % 10);

			number = number / 10;
		}
		else {

			int aux = abs(number);


			digits.push_back(aux % 10);

			number = number / 10;

			if (number == 0) {

				digits.push_back('-');
			}
		}

	} while (number);

}

Integer::Integer(string s) {
	digits = "";
	int n = s.size();
	for (int i = n - 1; i >= 0; i--) {
		
		s[i] !=  '-' ? digits.push_back(s[i] - '0'): digits.push_back('-');
	}
}


string Integer::getDigits() {

	return digits;
}

 string Integer::toString() {

	stringstream s;

	if (digits[digits.size() - 1] == '-') {
		s << digits[digits.size() - 1];
	

		for (int i = digits.size() - 2; i >= 0; i--) {

			s << (short)digits[i];
		}
	}
	else {
		for (int i = digits.size() - 1; i >= 0; i--) {

			s << (short)digits[i];
		}
		
	}

	return s.str();
}

ostream& operator << (ostream& o,  Integer& i) {

	o << i.toString();

	return o;
}

bool Integer::operator ==(const Integer& i) {

	return this->digits == i.digits;

}

bool Integer::operator != (const Integer& i) {

	return this->digits != i.digits;

}

bool Integer::operator<(const Integer& b) {

	int n = digits.length(), m = b.digits.length();

	if (digits[n - 1] != '-' && b.digits[m - 1] != '-') {
	
		if (n != m)
			return n < m;
		while (n--)
			if (digits[n] != b.digits[n])
				return digits[n] < b.digits[n];
		return false;
	
	} //caso ambos positivos
	if (digits[n - 1] == '-' && b.digits[m - 1] == '-') { n -= 1; m -= 1;
	
	if (n != m)
		return n > m;
	while (n--)
		if (digits[n] != b.digits[n])
			return digits[n] > b.digits[n];
	return false;
	
	
	} //caso ambos negativos 
	if (digits[n - 1] == '-' && b.digits[m - 1] != '-') { 
	
		return true;
	
	} //primero negativo, segundo positivo
	if (digits[n - 1] != '-' && b.digits[m - 1] == '-') { 
	
		return false;
	} //primero positivo, segundo negativo;


	
}

bool Integer::operator>(const Integer& b) {

	int n = digits.length(), m = b.digits.length();

	if (digits[n - 1] != '-' && b.digits[m - 1] != '-') {

		if (n != m)
			return n > m;
		while (n--)
			if (digits[n] != b.digits[n])
				return digits[n] > b.digits[n];
		return false;

	} //caso ambos positivos
	if (digits[n - 1] == '-' && b.digits[m - 1] == '-') {
		n -= 1; m -= 1;

		if (n != m)
			return n < m;
		while (n--)
			if (digits[n] != b.digits[n])
				return digits[n] < b.digits[n];
		return false;


	} //caso ambos negativos 
	if (digits[n - 1] == '-' && b.digits[m - 1] != '-') {

		return false;

	} //primero negativo, segundo positivo
	if (digits[n - 1] != '-' && b.digits[m - 1] == '-') {

		return true;
	} //primero positivo, segundo negativo;


}



bool Integer::operator>=(const Integer& b) {


	bool x = (*this < b);

	x = !x;

	return x;


}

Integer& Integer::operator=(const Integer& b) {


	digits = b.digits;

	return *this;


}

bool Integer::operator<=(const Integer& b) {


	bool x = (*this > b);

	x = !x;

	return x;


}

Integer& Integer::operator+=(const Integer& b) {


	int t = 0, s, i;
	int n = digits.size(), m = b.digits.size();


	if (digits[n - 1] != '-' && b.digits[m - 1] != '-') {
	

		if (m > n)
			digits.append(m - n, 0);
	
		for (i = 0; i < n; i++) {
			if (i < m)
				s = (digits[i] + b.digits[i]) + t;
			else
				s = digits[i] + t;
			t = s / 10;
			digits[i] = (s % 10);
		}
		if (t)
			digits.push_back(t);
		return *this;
	
	
	
	
	} //caso ambos positivos
	if (digits[n - 1] == '-' && b.digits[m - 1] == '-') { 
		n -= 1, m-=1;

	if (m > n)
		digits.append(m - n, 0);

	for (i = 0; i < n; i++) {
		if (i < m)
			s = (digits[i] + b.digits[i]) + t;
		else
			s = digits[i] + t;
		t = s / 10;
		digits[i] = (s % 10);
	}
	if (t)
		digits.push_back(t);

	return *this;

	} //caso ambos negativos 
	if (digits[n - 1] == '-' && b.digits[m - 1] != '-') { 
		n -= 1;

		for (i = 0; i < n; i++) {
			if (i < m)
				s = digits[i] - b.digits[i] + t;
			else
				s = digits[i] + t;
			if (s < 0)
				s += 10,
				t = -1;
			else
				t = 0;
			digits[i] = s;
		}
		while (n > 1 && digits[n - 1] == 0)
			digits.pop_back(),
			n--;
		return *this;

	
	
	} //primero negativo, segundo positivo
	if (digits[n - 1] != '-' && b.digits[m - 1] == '-') { m -= 1; 
	
	

	for (i = 0; i < n; i++) {
		if (i < m)
			s = digits[i] - b.digits[i] + t;
		else
			s = digits[i] + t;
		if (s < 0)
			s += 10,
			t = -1;
		else
			t = 0;
		digits[i] = s;
	}
	while (n > 1 && digits[n - 1] == 0)
		digits.pop_back(),
		n--;
	return *this;
	
	
	} //primero positivo, segundo negativo;


}

Integer& Integer::operator+(const Integer& b) {

	return *this += b;

}

Integer& Integer::operator*=(const Integer& b) {

	int n = digits.size(), m = b.digits.size();
	bool negative=false;

	if(digits[n-1] != '-'&&b.digits[m-1] != '-'){} //caso ambos positivos
	if (digits[n - 1] == '-' && b.digits[m - 1] == '-') { n -= 1; m -= 1; } //caso amobos negativos 
	if (digits[n - 1] == '-' && b.digits[m - 1] != '-') { n -= 1; negative = true; } //primero negativo, segundo positivo
	if (digits[n - 1] != '-' && b.digits[m - 1] == '-') { m -= 1; negative = true;} //primero positivo, segundo negativo;


	vector<int> v(n + m, 0);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			v[i + j] += (digits[i]) * (b.digits[j]);
		}
	n += m;
	digits.resize(v.size());
	for (int s, i = 0, t = 0; i < n; i++)
	{
		s = t + v[i];
		v[i] = s % 10;
		t = s / 10;
		digits[i] = v[i];
	}
	for (int i = n - 1; i >= 1 && !v[i]; i--)
		digits.pop_back();

	if (negative == true) {
		digits.push_back('-');
	}

	return *this;
}

Integer& Integer::operator-=(const Integer& b) {


	int t = 0, s, i;
	int n = digits.size(), m = b.digits.size();


	if (digits[n - 1] != '-' && b.digits[m - 1] != '-') {

		m -= 1;

		for (i = 0; i < n; i++) {
			if (i < m)
				s = digits[i] - b.digits[i] + t;
			else
				s = digits[i] + t;
			if (s < 0)
				s += 10,
				t = -1;
			else
				t = 0;
			digits[i] = s;
		}
		while (n > 1 && digits[n - 1] == 0)
			digits.pop_back(),
			n--;
		return *this;

		


	} //caso ambos positivos
	if (digits[n - 1] == '-' && b.digits[m - 1] == '-') {
		n -= 1, m -= 1;

		if (m > n)
			digits.append(m - n, 0);

		for (i = 0; i < n; i++) {
			if (i < m)
				s = (digits[i] + b.digits[i]) + t;
			else
				s = digits[i] + t;
			t = s / 10;
			digits[i] = (s % 10);
		}
		if (t)
			digits.push_back(t);

		return *this;

	} //caso ambos negativos 
	if (digits[n - 1] == '-' && b.digits[m - 1] != '-') {
		n -= 1;

		for (i = 0; i < n; i++) {
			if (i < m)
				s = digits[i] - b.digits[i] + t;
			else
				s = digits[i] + t;
			if (s < 0)
				s += 10,
				t = -1;
			else
				t = 0;
			digits[i] = s;
		}
		while (n > 1 && digits[n - 1] == 0)
			digits.pop_back(),
			n--;
		return *this;



	} //primero negativo, segundo positivo
	if (digits[n - 1] != '-' && b.digits[m - 1] == '-') {
	

	} //primero positivo, segundo negativo;


}

Integer& Integer::operator-(const Integer& b) {

	return *this -= b;
}
Integer& Integer::operator/=(const Integer& b) {


	/*
	bool negative = false;

	if (*this < b) {
	 *this = Integer();
		return *this; //retorna 0;
	}
	if (*this == b) {
		*this = Integer(1);
		return *this; // retorna 1;
	}
	int i, lgcat = 0, cc;
	int n = digits.length(), m = b.digits.length();


	if (digits[n - 1] != '-' && b.digits[m - 1] != '-') {} //caso ambos positivos
	if (digits[n - 1] == '-' && b.digits[m - 1] == '-') { n -= 1; m -= 1; } //caso amobos negativos 
	if (digits[n - 1] == '-' && b.digits[m - 1] != '-') { n -= 1; negative = true; } //primero negativo, segundo positivo
	if (digits[n - 1] != '-' && b.digits[m - 1] == '-') { m -= 1; negative = true; } //primero positivo, segundo negativo;

	vector<int> cat(n, 0);
	Integer t;
	for (i = n - 1; t * 10 + digits[i] < b; i--) {
		t *= 10;
		t += digits[i];
	}
	for (; i >= 0; i--) {
		t = t * 10 + digits[i];
		for (cc = 9; cc * (m > t); cc--);
		t -= cc * m;
		cat[lgcat++] = cc;
	}
	digits.resize(cat.size());
	for (i = 0; i < lgcat; i++)
		digits[i] = cat[lgcat - i - 1];
	digits.resize(lgcat);
	return *this;

	if (negative == true) {
		digits.push_back('-');
	}
	*/
	return *this;

	
}
Integer& Integer::operator*(const Integer& i) {

	return *this *= i;

}

Integer Integer::parse(string tostring) {

	
	
	return NULL;
}