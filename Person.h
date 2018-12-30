

class Person {
	
private:
	int person_id_;
	char person_name_[255];
public:
	Person(int person_id,*char person_name);
	int getID()const;
	char* getName()const;
	/*need to add destructor*/
}	
	