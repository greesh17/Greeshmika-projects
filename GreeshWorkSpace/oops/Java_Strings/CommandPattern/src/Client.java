import java.util.Observable;
import java.util.Observer;

import javax.swing.JFrame;

public class Client implements Observer {
	
	CommandStack stack = new CommandStack();
	StringStates stringstates = new StringStates();
	
	
	
	public static void main(String[] args) {
		Client client = new Client();
		 client.runCode();
	  }
	
	
	private void runCode() {
		
	
		
		stack.execute(new AppendCommand(stringstates));
	    stack.execute(new DeleteFirstCharCommand(stringstates));
	    stack.execute(new DeleteEndCharCommand(stringstates));
	    stack.execute(new CapitalizeCharCommand(stringstates));
	    stack.execute(new LowerCharCommand(stringstates));
	    stack.execute(new TitleCaseCommand(stringstates));
	    
	    stack.undo();
	    System.out.println(stringstates.getMemento().getPaths().get(stringstates.getMemento().getPaths().size()-1).getString());
	    stack.undo();
	    System.out.println(stringstates.getMemento().getPaths().get(stringstates.getMemento().getPaths().size()-1).getString());
	    stack.undo();
	    System.out.println(stringstates.getMemento().getPaths().get(stringstates.getMemento().getPaths().size()-1).getString());
	    stack.undo();
	    System.out.println(stringstates.getMemento().getPaths().get(stringstates.getMemento().getPaths().size()-1).getString());
	    stack.undo();
	    System.out.println(stringstates.getMemento().getPaths().get(stringstates.getMemento().getPaths().size()-1).getString());
	    stack.undo();
	    //System.out.println(stringstates.getMemento().getPaths().get(stringstates.getMemento().getPaths().size()-1).getString());
	    
	    System.out.println("\n");
	    System.out.println("Test Cases For Redo");
	    System.out.println("\n");
	    
	    
	    stack.redo();
	    System.out.println(stringstates.getMemento().getPaths().get(stringstates.getMemento().getPaths().size()-1).getString());
	    stack.redo();
	    System.out.println(stringstates.getMemento().getPaths().get(stringstates.getMemento().getPaths().size()-1).getString());
	    stack.redo();
	    System.out.println(stringstates.getMemento().getPaths().get(stringstates.getMemento().getPaths().size()-1).getString());
	    stack.redo();
	    System.out.println(stringstates.getMemento().getPaths().get(stringstates.getMemento().getPaths().size()-1).getString());
	    stack.redo();
	    System.out.println(stringstates.getMemento().getPaths().get(stringstates.getMemento().getPaths().size()-1).getString());
	    stack.redo();
	    //System.out.println(stringstates.getMemento().getPaths().get(stringstates.getMemento().getPaths().size()-1).getString());
	    
	    
	    
	}

	@Override
	public void update(Observable o, Object arg) {
		// TODO Auto-generated method stub
		
	}
}
