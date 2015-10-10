#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
	private:
		int *array;
		int size;
		int v_top;

		void expand_vector();
	public:
		Vector();
		Vector(int size1, int initial_value);
		Vector(const Vector &source);
		void push_back(int value);
		void pop_back();
		int top();
		bool is_empty();
		void operator<<(int val);
		friend std::ostream& operator<<(std::ostream &out, const Vector &v);
		bool operator!();
		bool operator==(const Vector &v2);
		bool operator!=(const Vector &v2);
		Vector& operator=(const Vector &source);
};

#endif
