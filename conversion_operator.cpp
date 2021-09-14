#include <iostream>

using namespace std;
class Sample {
	private:
	int num;
	public:
	Sample (int x = 0) : num (x) { }

	Sample (const Sample &obj) {
		std::cout << "copy" << std::endl;
		num = obj.num;
	}
	Sample & operator = (const Sample &obj) {
		std::cout << "Assignment operator" << std::endl;
		if (this != &obj) {
			this->num = obj.num + 2;
		}
	    return *this;
	}
	int get() const {
			return num;
	}
	operator std::string () const;
};

Sample :: operator std::string () const{
	std::cout << "conversion operator" << std::endl;
	return std::to_string (num);
}
ostream & operator << (ostream &out, const Sample &c) 
{
	out << "ostream" << std::endl;
    out << c.get();
    return out;
}

int main() {
	Sample s (10);
	std::cout << s << std::endl;
	string str = s;
	std::cout << str << std::endl;
	Sample s1;
	s1 = s;
	std::cout << s1 << std::endl;
	Sample s2 = s1;
	std::cout << s2 << std::endl;
    return 0;
}
