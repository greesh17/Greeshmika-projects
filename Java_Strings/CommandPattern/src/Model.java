
public class Model {
	private String str;
	
	public Model(String str) {
		this.str = str;
	}
	
	public Model() {
		
	}
	
	public String getString() {
		return this.str;
	}
	
	public void setString(String str) {
		this.str = str;
	}
	
	public void changeString(Model light) {
		light.setString(light.getString());
	}
	
	public String appendToString(){
		  String s =(new StringBuilder()).append(str).append("a").toString();
		  this.str = s;
		  return str;
	  }
	  
	public String deleteFromString(){
	    if(str != null) {
	    	String s = str.substring(1);
	    	return s;
	    }
	    return null;
	 }
	
}
