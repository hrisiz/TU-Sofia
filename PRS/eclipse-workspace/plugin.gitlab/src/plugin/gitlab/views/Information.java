package plugin.gitlab.views;

import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Label;
import org.eclipse.ui.part.ViewPart;

public class Information extends ViewPart {

	private Label label;
	public Information()
	{
		super();
	}
	
	@Override
	public void createPartControl(Composite parent) {
		label = new Label(parent,0);
		label.setText("Main");
		
	}

	@Override
	public void setFocus() {
		// TODO Auto-generated method stub
	}

}
