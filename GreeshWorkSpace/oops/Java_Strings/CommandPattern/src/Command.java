public interface Command {
	public void execute();
	void undo();
	void redo();
}
