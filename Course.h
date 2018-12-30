



class Course {
	
	private:
		int course_number_;
		char course_name_[1000];/*need to change*/
		int num_of_exercises_;
		double miashkal_hw_;
		int exam_grade_;
		int grades_hw_array_[1000];/*need to change*/
	
	public:
		Course(int course_number,char* p_course_name,int num_of_exercises,double miashkal_hw);
		int getNum() const;
		char* getName() const;
		int getExamGrade() const;
		int getHwGrade(int num_of_exercise) const;
		int getHwNum() const;
		double getHwWeigh const();
		double getHwAverage const();
		int getCourseGrade const();
		void serExamGrade(int grade);
		bool setHwGrade(int mispar_targil,int grade);
}	;
		
	
	
	