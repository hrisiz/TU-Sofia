package plugin.gitlab.views;

import java.io.IOException;

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.events.SelectionListener;
import org.eclipse.swt.widgets.*;
import org.eclipse.ui.part.ViewPart;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import plugin.gitlab.api.GitLabApi;

public class UserGroups extends ViewPart {
	private Tree mainTree;
    private GitLabApi gitLabAPI = new GitLabApi();
    private enum ItemType{
    	GROUP,
    	PROJECT
    }
    
	private void onGroupClick(int id)
	{
		System.out.println("Clicked on group with id " + id );
	}
	
	private void onProjectClick(int id)
	{
		System.out.println("Clicked on project with id " + id );
	}
	
    private class TreeSelectionListener implements SelectionListener
    {
    	@Override
		public void widgetSelected(SelectionEvent e) {
			
		}
		
		@Override
		public void widgetDefaultSelected(SelectionEvent e) {
			switch((ItemType) e.item.getData("type"))
			{
				case GROUP:
					onGroupClick((int)e.item.getData("id"));
					break;
				case PROJECT:
					onProjectClick((int)e.item.getData("id"));
					break;
			}
		}
    }
    
    public UserGroups() {
        super();
    }

    
	public void createPartControl(Composite parent) {
		mainTree = new Tree(parent, SWT.VERTICAL);
		mainTree.addSelectionListener(new TreeSelectionListener());
		try {
			JSONArray jsonGroupsArray = new JSONArray(gitLabAPI.GitLabGetRequest("https://gitlab.com/api/v4/groups"));
			for(Object group_o : jsonGroupsArray )
			{
				JSONObject groupJson = (JSONObject) group_o;
				TreeItem groupTreeItem = new TreeItem(mainTree, SWT.VERTICAL);
				groupTreeItem.setData("id", groupJson.getInt("id"));
				groupTreeItem.setData("type", ItemType.GROUP);
				groupTreeItem.setText(groupJson.getString("name") + " " + groupJson.getString("web_url"));
				
				JSONArray jsonProjectsArray = new JSONArray(gitLabAPI.GitLabGetRequest("https://gitlab.com/api/v4/groups/" + groupJson.getInt("id") + "/projects"));
				for(Object project_o : jsonProjectsArray )
				{
					JSONObject projectJson = (JSONObject) project_o;
					TreeItem projectTreeItem = new TreeItem(groupTreeItem,SWT.VERTICAL);
					projectTreeItem.setData("id", projectJson.getInt("id"));
					projectTreeItem.setData("type", ItemType.PROJECT);
					projectTreeItem.setText(projectJson.getString("name") + " " + projectJson.getString("web_url"));
				}
			}
			//label.setText(label_text);
		} catch (JSONException | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	@Override
	public void setFocus() {
		// TODO Auto-generated method stub
		
	}
}
