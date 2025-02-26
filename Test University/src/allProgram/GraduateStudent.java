package allProgram;

public class GraduateStudent extends Student {
	private String supervisor;
	public GraduateStudent (String aName, String anId, String aSuperVisor)
	{
		super(aName,anId);
		supervisor=aSuperVisor;
	}
	public void printInfo()
	{
		
		super.printInfo();
		System.out.println("SuperVisor is: " + supervisor);
		System.out.println("--------------------------------------------");
	}

}
