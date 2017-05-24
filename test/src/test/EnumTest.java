package test;

public enum EnumTest {
	Test1(1),
	Test2(2);
	private int test;
	private EnumTest(int i) {
		this.test = i;
	}
}
