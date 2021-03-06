
public enum RegExSearchTypes {
	NORMAL(0b0000),
	START(0b0001),
	UNKNOWNCOUNT(0b0010),
	FORTBIDDEN(0b0100),
	COUNTER(0b1000);
	
	private final int code;
	
	private RegExSearchTypes(int value) {
        this.code = value;
    }
	
	public int getCode(){
		return this.code;
	}
	
}
