import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		
		//Mhn tropopoiisete ton parakatw kwdika
		//Do not change the following code
		MolecularTest mTest1 = new MolecularTest("15/05/2020", "Alexiou", "Nasal", true,  0.99);
		AntigenTest aTest1 = new AntigenTest("20/10/2020", "Papadopoulos", "Throat", false,  30);
		MolecularTest mTest2 = new MolecularTest("29/11/2020", "Nikolaou", "Throat", true,  0.95);
		AntigenTest aTest2 = new AntigenTest("20/06/2020", "Petrou", "Throat", false,  60);
		MolecularTest mTest3 = new MolecularTest("19/09/2020", "Dimitriou",  "Nasal", false,  0.99);
		AntigenTest aTest3 = new AntigenTest("05/12/2020", "Ioannou", "Nasal", false,  45);
		MolecularTest mTest4 = new MolecularTest("17/12/2020", "Michailidis", "Throat", false,  0.98);
				
		//Sthn parakatw entolh tha prepei na antikatastisete to Epwnymo me to diko sas
		//In the next line please substitute Epwnymo with your own name
		AntigenTest aTest4 = new AntigenTest("04/01/2021", "Epwnymo", "Throat", false,  30);
				
		//Mhn tropopoiisete ton parakatw kwdika
		//Do not change the following code
		DiagnosticCenter diagnosticCenter = new DiagnosticCenter();
		
		diagnosticCenter.addTest(mTest1);
		diagnosticCenter.addTest(aTest1);
		diagnosticCenter.addTest(mTest2);
		diagnosticCenter.addTest(aTest2);
		diagnosticCenter.addTest(mTest3);
		diagnosticCenter.addTest(aTest3);
		diagnosticCenter.addTest(mTest4);
		diagnosticCenter.addTest(aTest4);
		
		ArrayList<String> testArray = new ArrayList<>();
		testArray.add("Papadopoulos");
		testArray.add("Alexiou");
		testArray.add("Georgiou");
		
		//Sto parakatw onoma tha prepei na antikatastisete to Epwnymo me to diko sas
		//In the following name please substitute Epwnymo with your own last name
		testArray.add("Epwnymo");
		
		//Mhn tropopoiisete ton parakatw kwdika
		//Do not change the following code
		testArray.add("Ioannou");
		diagnosticCenter.checkForTest(testArray);
		
	}

}
