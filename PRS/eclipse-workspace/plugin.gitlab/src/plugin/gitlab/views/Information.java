package plugin.gitlab.views;

import org.eclipse.jface.viewers.ISelection;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Label;
import org.eclipse.ui.ISelectionListener;
import org.eclipse.ui.IWorkbenchPart;
import org.eclipse.ui.part.ViewPart;

public class Information extends ViewPart implements ISelectionListener{

	Label label;
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

	@Override
	public void selectionChanged(IWorkbenchPart part, ISelection selection) {
		// TODO Auto-generated method stub
		
	}
}
