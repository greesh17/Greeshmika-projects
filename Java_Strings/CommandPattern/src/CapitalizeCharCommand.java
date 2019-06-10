public class CapitalizeCharCommand extends AbstractCommand {
   private static final int SIZE = 12;
  
   public CapitalizeCharCommand(StringStates stringstate) {
      super(stringstate);
   }
   
   
  

   @Override
   public void transform(Model model) {
	   
	   if(model.getString() != null && model.getString().length() > 1) {
	    	String s = model.getString().substring(0,1).toUpperCase() + model.getString().substring(1);
	    	model.setString(s);
	 	    model.changeString(model);
	 	    System.out.println("CapitalizeCharCommand.transform()" + model.getString());
	    	stringstate.add(new Model(s));
	    
	    }
	   
	   
   }

   
}