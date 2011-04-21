#include "archive.h"
//#include <iostream>
using namespace std;
class base
{
	friend class archive;
	public:
	int a;
	
	archive& serialize(archive  &ar)
	{
		ar<<a;
		cout<<"Base: ";
		//ar.printString();
		return ar;
	}
	archive& deserialize(archive &ar)
	{
		return (ar>>a);
	}
};
class derived
{
	friend class archive;
	public:
	base b;
	char c;
	archive& serialize(archive  &ar)
	{
		ar<<b<<c;//vi;	
		cout<<"Derived: ";
		//ar.printString();
		return ar;
	}
	archive& deserialize(archive &ar)
	{
		ar>>b>>c;
		return ar;
	}

};

class Student
{
	friend class archive;
public:
	
	char  gender;
	int age;
	double weight;
	vector<int> vi;
	map<char, int> mp;
	void add()
	{
		vi.push_back(2);
		vi.push_back(5);
		mp['f'] = 31;
		mp['i'] = 28;
		mp['r'] = 31;
		mp['s'] = 30;
		mp['t'] = 31;
		
	}
	void serialize(archive  &ar)
	{
		ar<<gender<<age<<weight;
		ar<<vi;
		ar<<mp;	
	}
	void deserialize(archive &ar)
	{
		ar>>gender>>age>>weight;
		ar>>vi;
		ar>>mp;
	}
};

int main()
{

	/*Student one;
	one.gender = 'F';
	one.age = 16;
	one.weight=17.5;
	one.add();
	//ofstream ofs("fifthgrade.ros");
   	//serializer srlz(ofs);
	//ofs.write((char *)&one, sizeof(one));
	archive a;
	a.save_object(one);
	Student two;
	a.load_object(two);
	cout<<two.gender<<" ";
	cout<<two.age<<" "<<two.weight<<" ";
	//cout<<one.vi[0];
	//cout<<one.vi[1];

	cout << "Size: "<< two.mp.size() << endl;
	for (auto iter = two.mp.begin(); iter != two.mp.end(); iter++)
	{
		cout << (*iter).first << " " << (*iter).second << endl;
	}
*/
archive a;
derived d;
d.b.a=10;
d.c='a';
a.save_object(d);
derived d1;
a.load_object(d1);
cout<<d1.b.a<<" "<<d1.c;

return 0;
}