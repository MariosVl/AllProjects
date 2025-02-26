import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class GUI extends JFrame{
	
	private JPanel panel = new JPanel();
	private JButton button = new JButton("TestResults");
	
	public GUI() {
		
		panel.add(button);
		this.setContentPane(panel);		
		
		ButtonListener listener = new ButtonListener();
		button.addActionListener(listener);
		
		this.setVisible(true);
		this.setSize(200, 200);
		this.setTitle("Test Results");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	class ButtonListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent arg0) {
			// TODO Auto-generated method stub
			
		}
		
	}

}
