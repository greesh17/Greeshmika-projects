import java.util.*;
import java.awt.*;

public class Memento {
   private List<Model> paths;

   public Memento(List<Model> paths) {
      this.paths = paths;
   }

   public List<Model> getPaths() {
      return paths;
   }
}