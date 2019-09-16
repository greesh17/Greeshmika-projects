import java.util.*;
import java.awt.*;
import java.util.List;

public class Memento {
   private List<Model> paths;

   public Memento(List<Model> paths) {
      this.paths = paths;
   }

   public List<Model> getPaths() {
      return paths;
   }
}