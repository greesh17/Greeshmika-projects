import java.awt.*;
import java.util.*;



abstract public class AbstractCommand implements Command {
   private Memento memento;
   private static Model model = new Model("testString");   
   
   protected StringStates stringstate;
   int count = 0;
  
   public AbstractCommand() {
   }

   public AbstractCommand(StringStates stringstate) {
      
      this.stringstate = stringstate;

   }
   
   
   public void execute() {
	  
      this.memento = stringstate.getMemento();
          
      transform(model);
      String s = model.getString();
      model.setString(s);
          
      model.changeString(model);
            
   }

   abstract protected void transform(Model light);

   public void undo() {
      Memento redoMemento = stringstate.getMemento();
      stringstate.setMemento(memento);
      memento = redoMemento;
   }

   public void redo() {
      Memento undoMemento = stringstate.getMemento();
      stringstate.setMemento(memento);
      memento = undoMemento;
   }

  
}