import java.awt.*;
import java.awt.geom.*;
import java.util.*;
import java.util.List;

public class StringStates extends Observable implements
   MementoOriginator{
   private List<Model> lights =
      new ArrayList<Model>();

   public List<Model> lights() {
      return lights;
   }

   public void add(Model light) {
      lights.add(light);
      changed();
   }

   

   public Memento getMemento() {
      List<Model> lightCopies =
         new ArrayList<Model>();
      lightCopies.addAll(lights);
      return new Memento(lightCopies);
   }

   @Override
   public void setMemento(Memento memento) {
	  lights.clear();
	  lights.addAll(memento.getPaths());
      changed();
   }

   private void changed() {
      setChanged();
      notifyObservers();
   }
}