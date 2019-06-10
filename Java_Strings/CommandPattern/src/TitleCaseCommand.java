import java.util.*;
import java.awt.*;
public class TitleCaseCommand extends AbstractCommand {
   private static final int SIZE = 12;

   
   public TitleCaseCommand(StringStates stringstate) {
      super(stringstate);
   }
   
  
  

   @Override
   public void transform(Model model) {
	   
	   if(model.getString() != null && model.getString().length() > 1) {   
		    String input = model.getString();
		    String firstCharCap = input.substring(0,1).toUpperCase();

	    	//String s = model.getString().substring(0,1).toUpperCase() + model.getString().substring(1);
	    	String lower = model.getString().substring(1, model.getString().length()).toLowerCase();
	    	String s =  firstCharCap + lower;
	    	model.setString(s);
	 	    model.changeString(model);
	 	    System.out.println("TitleCaseCommand.transform()" + model.getString());
	 	   System.out.println("\n");
	 	  System.out.println("Test Cases Undo");
	 	 System.out.println("\n");
	 	  
	 	   
	    	stringstate.add(new Model(s));
	    
	    }
	   
	   
   }

   
}