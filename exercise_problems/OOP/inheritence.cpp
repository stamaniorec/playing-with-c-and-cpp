#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class ID_Class
{
	private:
		string ID_;
		int random_number;
	public:
		ID_Class()
		{
			ID_ = "";
			random_number = 0;
		}
		ID_Class(string string1, int random1) : ID_(string1), random_number(random1){};
		string get_id() { return ID_; }
		int get_random() { return random_number; }
};

class Employee
{
	protected:
		string name;
		double pay;
		ID_Class id;
	public: 
		Employee()
		{
			name = "";
			pay = 0.0;
		}
		
		Employee(string name1, double pay1, ID_Class id1) : name(name1), pay(pay1), id(id1){};
		
		string get_name() { return name; }
		void   set_name(string name1) { name = name1; }
		double get_pay() { return pay; }
		void   set_pay(double pay1) { pay = pay1; }
		string get_ID() { return id.get_id(); }

		string returnAll()
		{
			stringstream sstream;
			sstream << name << "'s pay is: " << pay << endl;
			return sstream.str();
		}

		double gross_pay (int hours)
		{
			return hours * pay;
		}
};

class Manager : public Employee
{
	private:
		bool has_salary;
	public:
		Manager(string name1, double pay1, ID_Class id1, bool boolean) :
			Employee(name1, pay1, id1)
		{
			has_salary = boolean;
		}
		
		bool get_has_salary() { return has_salary; }

		double gross_pay()
		{
			return pay;
		} 
};

int main()
{
	ID_Class id("randomID", 3);
	Employee employee("John Smith", 15, id);
	cout << employee.returnAll();
	cout << employee.gross_pay(40) << endl;
	cout << employee.get_ID() << endl;

	ID_Class man_id("Im the boss here yo", 5);
	Manager manager("Mr Boss", 30000, man_id, true);
	cout << manager.get_name() << endl;
	cout << manager.get_has_salary() << endl;
	cout << manager.gross_pay() << endl;
	cout << manager.get_ID() << endl;
	
	return 0;
}
