//�������� ���� ����� � ����� �� ������� � ������ ����������
public class Document {
	private String name;
	private float progress;
	private double income;
	private String faculty;
	private DocumentType type; // ��������� ���������� �� ����� �� ���������.
	public Document(String name,float progress,double income,String faculty,DocumentType type) {
		//����� �� �����������, ����� ������� �������� �� �������� ���������.
		this.name = name;
		this.progress = progress;
		this.income = income;
		this.faculty = faculty;
		this.type = type;
	}
	// ������ ������ � ������
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public float getProgress() {
		return progress;
	}
	public void setProgress(float progress) {
		this.progress = progress;
	}
	public double getIncome() {
		return income;
	}
	public void setIncome(double income) {
		this.income = income;
	}
	public String getFaculty() {
		return faculty;
	}
	public void setFaculty(String faculty) {
		this.faculty = faculty;
	}
	public DocumentType getType() {
		return type;
	}
	public void setType(DocumentType type) {
		this.type = type;
	}
	
}
