#ifndef _COURSE_H_
#define _COURSE_H_

class Course {

public:
	Course(int course_number, char* p_course_name, int num_of_exercises, double weight_hw);
	~Course();
	int getNum() const;
	char* getName() const;
	int getExamGrade() const;
	int getHwGrade(int num_of_exercise) const;
	int getHwNum() const;
	double getHwWeigh()const;
	double getHwAverage() const;
	int getCourseGrade()const;
	bool setExamGrade(int exam_grade);
	bool setHwGrade(int exercise_num, int exercise_grade);

	private:
		int course_number_;
		char* p_course_name_;
		int num_of_exercises_;
		double weight_hw_;
		int exam_grade_;
		int* p_grades_hw_array_;
};
#endif
	
	