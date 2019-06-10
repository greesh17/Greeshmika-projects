import java.util.*;

public class CommandStack {
   private LinkedList<Command> commandStack =
      new LinkedList<Command>();
   private LinkedList<Command> redoStack =
      new LinkedList<Command>();

   public void execute(Command command) {
      command.execute();
      commandStack.addFirst(command);
      redoStack.clear();
   }

   public void undo() {
      if (commandStack.isEmpty())
         return;
      Command command = commandStack.removeFirst();
      System.out.println(command.toString());
      command.undo();
      redoStack.addFirst(command);
   }

   public void redo() {
      if (redoStack.isEmpty())
         return;
      Command command = redoStack.removeFirst();
      System.out.println(command.toString());
      command.redo();
      commandStack.addFirst(command);
   }
}