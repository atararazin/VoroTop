import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Font;
import java.awt.GridLayout;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class GUI {
	public void create() {
	    Box horizontalBox;
	    JPanel panel;
	    JFrame frame = new JFrame("VoroTop");
	    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	    Container contentPane = frame.getContentPane();
	    contentPane.setLayout(new GridLayout(0, 1));

	    horizontalBox = Box.createHorizontalBox();
	    JLabel l = new JLabel("Number Of Atoms:");
	    horizontalBox.add(l);
	    horizontalBox.add(Box.createGlue());
	    JTextField atomsText = new JTextField();
	    horizontalBox.add(atomsText);
	    //atomsText.setMaximumSize(atomsText.getPreferredSize());


	    panel = new JPanel(new BorderLayout());
	    panel.add(horizontalBox);
	    panel.setBorder(BorderFactory.createTitledBorder("Beginning Glue"));
	    contentPane.add(panel);

	    horizontalBox = Box.createHorizontalBox();
	    horizontalBox.add(new JLabel("X:"));
	    horizontalBox.add(Box.createGlue());
	    horizontalBox.add(new JTextField());
	    horizontalBox.add(Box.createGlue());
	    horizontalBox.add(new JTextField());
	    panel = new JPanel(new BorderLayout());
	    panel.add(horizontalBox);
	    panel.setBorder(BorderFactory.createTitledBorder("Bounds:"));
	    contentPane.add(panel);
	    
	    horizontalBox = Box.createHorizontalBox();
	    horizontalBox.add(new JLabel("Y:"));
	    horizontalBox.add(Box.createGlue());
	    horizontalBox.add(new JTextField());
	    horizontalBox.add(Box.createGlue());
	    horizontalBox.add(new JTextField());
	    panel = new JPanel(new BorderLayout());
	    panel.add(horizontalBox);
	    panel.setBorder(BorderFactory.createTitledBorder(" "));
	    contentPane.add(panel);
	    

	    horizontalBox = Box.createHorizontalBox();
	    horizontalBox.add(new JLabel("Z:"));
	    horizontalBox.add(Box.createGlue());
	    horizontalBox.add(new JTextField());
	    horizontalBox.add(Box.createGlue());
	    horizontalBox.add(new JTextField());
	    panel = new JPanel(new BorderLayout());
	    panel.add(horizontalBox);
	    panel.setBorder(BorderFactory.createTitledBorder(" "));
	    contentPane.add(panel);

	    horizontalBox = Box.createHorizontalBox();
	    horizontalBox.add(new JLabel("Output Type:"));
	    horizontalBox.add(Box.createGlue());
	    String[] comboStrs = {"Weinberg Vector","Filter"};
	    horizontalBox.add(new JComboBox(comboStrs));
	    panel = new JPanel(new BorderLayout());
	    panel.add(horizontalBox);
	    panel.setBorder(BorderFactory.createTitledBorder(" "));
	    contentPane.add(panel);

	    horizontalBox = Box.createHorizontalBox();
	    final JFileChooser fc = new JFileChooser();
	    //In response to a button click:
	    //int returnVal = fc.showOpenDialog(aComponent);
	    horizontalBox.add(fc);
	    panel = new JPanel(new BorderLayout());
	    horizontalBox.add(Box.createGlue());
	    panel.add(horizontalBox);
	    panel.setBorder(BorderFactory.createTitledBorder("Upload File:"));
	    contentPane.add(panel);


	    horizontalBox = Box.createHorizontalBox();
	    horizontalBox.add(new JButton("Calculate!"));
	    panel = new JPanel(new BorderLayout());
	    panel.add(horizontalBox);
	    panel
	        .setBorder(BorderFactory
	            .createTitledBorder(" "));
	    contentPane.add(panel);

	    frame.setSize(2000, 1500);
	    frame.setVisible(true);
	  
	}
	
}
