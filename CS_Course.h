#ifndef _CS_COURSE_H_
#define _CS_COURSE_H_
#include "Course.h"

class CS_Course :public Course {
	private:
		int isTakef_;
		char* p_book_name_;
	public:
		CS_Course(int course_number, char* p_course_name, int num_of_exercises, float weight_hw, bool isTakef, char* p_book_name);
		~CS_Course();
		bool setTakef(bool isTakef);
		int getCourseGrade() const;
		void setBook(char* p_book_name);
};
#endif	