import java.util.*;
import java.util.stream.Stream;
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
		    StringBuffer resultPlaceHolder =new StringBuffer(input.length());
		    Stream.of(input.split(" ")).forEach(stringPart ->
		    {
		    	if(stringPart.length()>1)
		    		resultPlaceHolder.append(stringPart.substring(0,1).toUpperCase()).append(stringPart.substring(1).toLowerCase());
		    	else
		    		resultPlaceHolder.append(stringPart.toUpperCase());
		    	resultPlaceHolder.append(" ");
		    });
	 	   
	 	System.out.println("TitleCaseCommand.transform()"+resultPlaceHolder.toString());
	 	   stringstate.add(new Model(resultPlaceHolder.toString()));
	 	  System.out.println("\n");
	 	  System.out.println("Test Cases Undo");
	 	 System.out.println("\n");
	    	//stringstate.add(new Model(s));
	    
	    }
	   
	   
   }

   
}