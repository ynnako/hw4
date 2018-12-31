
#include "Student.h"

Student::Student(int person_id, char* p_person_name):
	Person( person_id,  p_person_name){}

int Student::getCourseCnt() const{
	return ee_course_num_+ cs_course_num_;
}

bool Student::addEE_Course(EE_Course* p_ee_course) {
	return 0;
}