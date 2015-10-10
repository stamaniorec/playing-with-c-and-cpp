#include <iostream>

class StudentListNode
{
private:
	std::string name;
	int grade;
	StudentListNode *next;
public:
	StudentListNode(std::string name, int grade) : 
		name(name), grade(grade), next(NULL) {};

	friend std::ostream& operator<<(std::ostream &out, const StudentListNode *student)
	{
		out << student->name << ": " << student->grade << std::endl;
		return out;
	}

	StudentListNode* get_next() { return next; }
	void set_next(StudentListNode *next) { this->next = next; }

	std::string get_name() { return name; }
};

class LinkedList
{
private:
	StudentListNode *head;
	StudentListNode *tail;
public:
	LinkedList() : head(NULL), tail(NULL) {};

	void add(std::string name, int grade)
	{
		StudentListNode *student = new StudentListNode(name, grade);
		if(!head && !tail)
		{	
			head = student;
			tail = student;
		}
		else
		{
			// for O(1) add 
			tail->set_next(student);
			tail = student;
		}
	}

	void remove(std::string key)
	{
		if(!empty())
		{
			// If the list only has one element
			if(head == tail)
			{
				// If this one element holds the key, remove it 
				if(head->get_name() == key)
				{
					delete head;
					head = tail = NULL;
				}
			}
			else
			{
				// If the Head is to be removed
				if(head->get_name() == key)
				{
					StudentListNode *next = head->get_next();
					delete head;
					head = next;
				}
				else
				{
					StudentListNode *cur = head;
					// Traverse until the second last element
					while(cur->get_next())
					{
						// If the next element contains the key
						if(cur->get_next()->get_name() == key)
						{
							// If this next element is the Tail
							if(!cur->get_next()->get_next())
							{
								delete cur->get_next();
								cur->set_next(NULL);
								tail = cur;
							}
							else
							{
								StudentListNode *next = cur->get_next();
								cur->set_next(cur->get_next()->get_next());
								delete next;
							}
							break;
						} 
						cur = cur->get_next();
					}
				}
			}
		}
	}

	void print()
	{
		if(!head && !tail)
		{
			std::cout << "Empty list." << std::endl;
		}
		else
		{
			StudentListNode *cur = head;
			while(cur)
			{
				std::cout << cur;
				cur = cur->get_next();
			}
		}
	}

	bool empty()
	{
		return !head && !tail;
	}
};

class HashTable
{
private:
	static const int TABLE_SIZE = 100;
	LinkedList* hash_arr[TABLE_SIZE];
public:
	HashTable()
	{
		for(int i = 0; i < TABLE_SIZE; ++i)
		{
			hash_arr[i] = new LinkedList;
		}
	}

	int hash_function(std::string string)
	{
		int index = 0;
		for(int i = 0; i < string.length(); ++i)
		{
			index += (int)string[i];
		}
		index = index % TABLE_SIZE;
	}

	void add(std::string name, int value)
	{
		int index = hash_function(name);
		LinkedList *list = hash_arr[index];
		list->add(name, value);
	}

	void remove(std::string key)
	{
		int index = hash_function(key);
		LinkedList *list = hash_arr[index];
		list->remove(key);
	}

	void print()
	{
		for(int i = 0; i < TABLE_SIZE; ++i)
		{
			if(!hash_arr[i]->empty())
			{
				hash_arr[i]->print();
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	/*LinkedList *students = new LinkedList;
	students->add("Keeth", 5);
	students->add("Melisa", 4);
	students->add("Teresa", 3);
	students->print();
	students->remove("Keeth");
	students->print();*/

	HashTable hash;
	std::cout << "Hash with Keeth, Melisa and Teresa" << std::endl;
	hash.add("Keeth", 5);
	hash.add("Melisa", 4);
	hash.add("Teresa", 3);
	hash.print();
	std::cout << "Removing Melisa" << std::endl;
	hash.remove("Melisa");
	hash.print();
	std::cout << "Adding gnpnz( for which hash_function yields 97, like Keeth" << std::endl;
	hash.add("gnpnz(", 16);
	hash.print();

	return 0;
}