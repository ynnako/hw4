#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "Person.h"
#include "CS_Course.h"
#include "EE_Course.h"
#include "Proj.h"

class Student : public Person {
private:
	EE_Course* p_ee_course_array_[MAX_COURSE_NUM]  ;
	CS_Course* p_cs_course_array_[MAX_COURSE_NUM]  ;
	int num_of_ee_courses_;
	int num_of_cs_courses_;

public:
	Student(int person_id, char* p_person_name);
	~Student();
	int getCourseCnt()const;
	bool addEE_Course(EE_Course* p_ee_course);
	bool addCS_Course(CS_Course* p_cs_course);
	bool rem_Course(int course_num);
	EE_Course* getEE_Course(int ee_course_num);
	CS_Course* getCS_Course(int cs_course_num);
	int getAvg() const;
	void print() const;

};
#endif
		