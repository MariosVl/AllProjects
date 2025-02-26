package allProgram;
import java.util.ArrayList;
import java.util.Scanner;

import javax.swing.JOptionPane;


public class Read {

	Scanner in=new Scanner(System.in);
	public void readData(ArrayList <Student> aStudents,ArrayList<Course> aCourses)
	{
		
		boolean more=true;
		Student S;
		Course C=null;
		while(more)
		{
			
			
			
			
			if(validateStudentType()==1)
				
				S=createStudent();
			
			else
			
				S=createGraduateStudent();
			
			
			int i=0;
			Course.setCounter(i);
			int limit=totalCourses();
			
			while(Course.getCounter()<limit)
			{
				
				
			
				boolean check1=false;
				boolean check2=false;
				
				
				//System.out.println("Give me " + (Course.getCounter()+1)+"st"+" course name to enroll student: " + S.getName());
			    String eachCourse=JOptionPane.showInputDialog("Give me " + (i+1)+"st"+" course name to enroll student: " + S.getName());
				//System.out.println("Give me " + (Course.getCounter()+1)+"st"+" course credits to enroll student: " + S.getName());
			    String eachCourseCredits=JOptionPane.showInputDialog("Give me " + (i+1)+"st"+" course credits to enroll student: " + S.getName());	
				
				ArrayList<Course> eachStudentCourses=S.getCourses();
				
				if(eachStudentCourses.isEmpty())
				{
				    
					C=courseAssignment_toStudent(S,eachCourse,eachCourseCredits);
					
					if(aCourses.isEmpty())
				    {   C.addStudent(S);
				    	aCourses.add(C);
				    }
				    else
				    {
				    	for(Course countCourse:aCourses)
				    	{
				    		if(C.getName().equalsIgnoreCase(countCourse.getName()))
				    		{
				    			countCourse.addStudent(S);
				    			check2=true;
				    			break;
				    		}
				    	}
				    	if(!check2)
				    	{
				    	  C.addStudent(S);
				    	  aCourses.add(C);
				    	}
				    	
				    } 
					
					
				}
				else
				{

					for(Course counterCourse:eachStudentCourses)
				    {
					
					   if(eachCourse.equalsIgnoreCase(counterCourse.getName()))
					     {
						       check1=true;
						       break;
					     }
				    }
					
				   if(!check1)
				     {
					   C=courseAssignment_toStudent(S,eachCourse,eachCourseCredits);
					   if(aCourses.isEmpty())
					    {   C.addStudent(S);
					    	aCourses.add(C);
					    }
					    else
					    {
					    	for(Course countCourse:aCourses)
					    	{
					    		if(C.getName().equalsIgnoreCase(countCourse.getName()))
					    		{
					    			countCourse.addStudent(S);
					    			check2=true;
					    			break;
					    		}
					    	}
					    	if(!check2)
					    	{
					    	  C.addStudent(S);
					    	  aCourses.add(C);
					    	}
					    	
					    } 

					   
				     }
				   
				}
				
				//i++;
			}
		
			aStudents.add(S);
			
		
			
			
			
			String continueAnswer=validateContinueAnswer();
			
		    if(continueAnswer.equalsIgnoreCase("N"))
		    	
		    	more=false;
		    
		}
		
	}
	
	
	
	public int  validateStudentType()
	{
		String selection;
		do {
			//System.out.println("Give 1 for Student and 2 for GraduateStudent");
			selection=JOptionPane.showInputDialog("Give 1 for Student and 2 for GraduateStudent");
			
			}while(!selection.equalsIgnoreCase("1") && !selection.equalsIgnoreCase("2"));
		return Integer.parseInt(selection);
	}
	
	
	public Student createStudent()
	{
		//System.out.println("Give Student's name");
		String name=JOptionPane.showInputDialog("Give Student's name");
		//System.out.println("Give Student's id");
		String id=JOptionPane.showInputDialog("Give Student's id");
		Student S=new Student(name,id);
		return S;
	}
	
	public Student createGraduateStudent()
	{
		//System.out.println("Give Graduate Student's name");
		String name=JOptionPane.showInputDialog("Give Graduate Student's name");
		//System.out.println("Give Graduate Student's id");
		String id=JOptionPane.showInputDialog("Give Graduate Student's id");
		//System.out.println("Give Graduate Student's supervisor name");
		String supervisor=JOptionPane.showInputDialog("Give Graduate Student's supervisor name");
		Student S=new GraduateStudent(name,id,supervisor);
		return S;
	}
	
	public String validateContinueAnswer()
	{
		String continue_insert;
		 do {
			   // System.out.println("Do you want continue give Students? y for YES / n for NO");
		        continue_insert=JOptionPane.showInputDialog("Do you want continue give Students? y for YES / n for NO ");
		    
			} while(!continue_insert.equalsIgnoreCase("Y") && !continue_insert.equalsIgnoreCase("N") );
		 
		 return continue_insert;
	}
	
	public int totalCourses()
	{
		//System.out.println("How many Courses you want to enroll?");
		String totalCourses=JOptionPane.showInputDialog("How many Courses you want to enroll?");
		return Integer.parseInt(totalCourses);
	}
	
	public Course courseAssignment_toStudent(Student aStudent,String eachCourse,String eachCourseCredits)
	{
		Course C=new Course(eachCourse,Integer.parseInt(eachCourseCredits));
		aStudent.addCourse(C);
		 return C;
		
	}
	
	
	
	
	
	
}
