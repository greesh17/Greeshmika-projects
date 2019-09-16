
public class AppendCommand extends AbstractCommand {
   private static final int SIZE = 12;
  
   public AppendCommand(StringStates stringstate) {
      super(stringstate);
   }
   
   
   
   
   
   @Override
   public void transform(Model model) {
	   
	   String s =(new StringBuilder()).append(model.getString()).append("S").toString();
	   model.setString(s);
	   model.changeString(model);
	   System.out.println("AppendCommand.transform()" + model.getString());
	   stringstate.add(new Model(s));
   }

   
}