
public class RegExSearchType {
	private int type;
	private int minCount;
	private int maxCount;
	
	public RegExSearchType(int type) {
		this.type = type;
		this.minCount = 0;
		this.maxCount = 0;
	}
	
	public RegExSearchType(RegExSearchType old) {
		this.type = old.getType();
		this.minCount = old.getMinCount();
		this.maxCount = old.getMaxCount();
	}
	
	public void setMinCount(int minCount) {
		this.minCount = minCount;
	}
	
	public void setMaxCount(int maxCount) {
		this.maxCount = maxCount;
	}

	public int addMinCount(int minCount) {
		return this.minCount += minCount;
	}
	
	public int addMaxCount(int maxCount) {
		return this.maxCount += maxCount;
	}
	
	public int getMaxCount() {
		return maxCount;

	}
	
	public int getMinCount() {
		return minCount;
	}
	
	public int getType() {
		return type;
	}
	
	public void addType(double type){
		this.type += type;
	}
}
