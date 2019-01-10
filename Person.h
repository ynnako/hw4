#ifndef _PERSON_H_
#define _PERSON_H_

class Person {
	
private:
	int person_id_;
	char* p_person_name_;
public:
	
	Person(int person_id,char* person_name);
	~Person();
	int getID()const;
	char* getName()const;	
};
#endif	