package plugin.gitlab.views;

import java.io.IOException;
import java.util.zip.Inflater;

import org.eclipse.core.commands.ExecutionEvent;
import org.eclipse.core.commands.ExecutionException;
import org.eclipse.core.commands.HandlerEvent;
import org.eclipse.core.commands.IHandler;
import org.eclipse.core.commands.IHandler2;
import org.eclipse.core.commands.IHandlerListener;
import org.eclipse.jface.dialogs.MessageDialog;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Label;
import org.eclipse.ui.commands.ICommandService;
import org.eclipse.ui.part.ViewPart;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import plugin.gitlab.api.GitLabApi;

public class Members extends ViewPart implements IHandler2 {

	private Label label;
	public Members()
	{
		super();
	}
	
	@Override
	public void createPartControl(Composite parent) {
		label = new Label(parent, 0);
		((ICommandService)getSite().getService(ICommandService.class)).getCommand("plugin.gitlab.commands.projectPickCommand").setHandler(this);
	}

	@Override
	public void setFocus() {
		// TODO Auto-generated method stub
	}

	private boolean baseEnabled = true;

	@Override
	public void addHandlerListener(final IHandlerListener handlerListener) {
		addListenerObject(handlerListener);
	}

	protected void fireHandlerChanged(final HandlerEvent handlerEvent) {
		if (handlerEvent == null) {
			throw new NullPointerException();
		}

		for (Object listener : getListeners()) {
			final IHandlerListener handlerListener = (IHandlerListener) listener;
			handlerListener.handlerChanged(handlerEvent);
		}
	}

	
	@Override
	public boolean isEnabled() {
		return baseEnabled;
	}

	protected void setBaseEnabled(boolean state) {
		if (baseEnabled == state) {
			return;
		}
		baseEnabled = state;
		fireHandlerChanged(new HandlerEvent(this, true, false));
	}

	@Override
	public void setEnabled(Object evaluationContext) {
	}

	@Override
	public boolean isHandled() {
		return true;
	}

	protected boolean hasListeners() {
		return isListenerAttached();
	}

	@Override
	public void removeHandlerListener(final IHandlerListener handlerListener) {
		removeListenerObject(handlerListener);
	}	// TODO Auto-generated method stub

	@Override
	public Object execute(ExecutionEvent event) throws ExecutionException {
		StringBuffer information = new StringBuffer("Name\t\tUsername\t\tstate\n");
		try {
			JSONArray jsonMembersArray = 
					new JSONArray(GitLabApi.GitLabGetRequest("https://gitlab.com/api/v4/projects/" + event.getParameter("id") + "/members"));
			System.out.println(jsonMembersArray);
			for(Object member_o : jsonMembersArray)
			{
				JSONObject member = (JSONObject) member_o;
				information.append(member.get("name") + "\t\t");
				information.append(member.get("username") + "\t\t");
				information.append(member.get("state") + "\n");
			}
		} catch (JSONException | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		label.setText(information.toString());
		System.out.println(event.getParameter("id"));
		return null;
	}
}
