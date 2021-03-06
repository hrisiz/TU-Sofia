import java.util.ArrayList;
import java.util.List;

public class Regex {
	private List<List<Character>> regex;
	private List<RegExSearchType> regex_type; 
	/* Regular expression search types
	 * 0 - Start regex
	 * 1 - + 0 or more unknown count
	 * 2 - * Unknown count
	 * 3 - Forbidden regex
	 */
	
	private void addToRegexType(int index, int value){
		try {
			regex_type.get(index).addType(value);
		} catch ( IndexOutOfBoundsException e ) {
			regex_type.add(new RegExSearchType(value));
		}
	}
	
	public Regex(String pattern) throws RegExException {
		regex = new ArrayList<List<Character>>();
		regex_type = new ArrayList<RegExSearchType>();
		int regex_counter = -1;
		boolean is_collection = false;
		boolean is_escape = false;
		boolean is_first = false;
		boolean is_collection_remove = false;
		boolean is_count_set = false;
		boolean max_regex_chars_count = false;
		for(int string_counter = 0; string_counter < pattern.length(); string_counter++){
			char current_char = pattern.charAt(string_counter);
			if(current_char == '/'){
				is_escape = true;
				continue;
			}
			if(!is_escape){
				if(current_char == '{'){
					is_count_set = true;
					this.addToRegexType(regex_counter ,RegExSearchTypes.COUNTER.getCode());
					continue;
				}
				if(current_char == '}' && is_count_set){
					RegExSearchType current_regex_type = regex_type.get(regex_counter);
					//System.out.println("xaa:" +current_regex_type.getMinCount() + "xaxa : "+current_regex_type.getMaxCount());
					if(current_regex_type.getMinCount() > current_regex_type.getMaxCount() && max_regex_chars_count){
						throw new RegExException("Minimum count is bigger then maximum count");
					}
					max_regex_chars_count = false;
					is_count_set = false;
					continue;
				}
				if(current_char == '*'){
					if(regex_counter < 0){
						throw new RegExException("Wrong use of *. You have to escape(/) this symbol.");
					}
					this.addToRegexType(regex_counter ,RegExSearchTypes.UNKNOWNCOUNT.getCode());
					continue;
				}
				if(current_char == '+'){
					if(regex_counter == -1){
						throw new RegExException("Wrong use of +. You have to escape(/) this symbol.");
					}
					regex.add(regex_counter, new ArrayList<Character>(regex.get(regex_counter)));
					regex_counter++; 
					regex_type.add(regex_counter,new RegExSearchType(regex_type.get(regex_counter-1)));
					this.addToRegexType(regex_counter ,RegExSearchTypes.UNKNOWNCOUNT.getCode());
					continue;
				}
				if(current_char == '^'){
					if(regex_counter == -1){
						is_first = true;
						continue;
					}else if(is_collection){
						this.addToRegexType(regex_counter ,RegExSearchTypes.FORTBIDDEN.getCode());
						continue;
					}else{
						throw new RegExException(" Wrong use of ^. You have to escape(/) this symbol.");
					}
				}
				if(current_char == '['){
					if(is_collection){
						is_collection_remove = true;
						continue;
					}
					regex_counter++;
					regex.add(new ArrayList<Character>());
					if(is_first){
						this.addToRegexType(regex_counter ,RegExSearchTypes.START.getCode());
						is_first = false;
					}else{
						this.addToRegexType(regex_counter ,RegExSearchTypes.NORMAL.getCode());
					}
					//regex_counter++;
					is_collection = true;
					continue;
				}
				if(current_char == ']' && is_collection){
					if(is_collection_remove){
						is_collection_remove = false;
					}else{
						is_collection = false;
					}
					continue;
				}
				if(current_char == '-' && is_collection){
					char prev_char = pattern.charAt(string_counter-1);
					char next_char = pattern.charAt(string_counter+1);
					if(((prev_char >= 'a' && prev_char <= 'z') &&
					   (next_char >= 'a' && next_char <= 'z')) ||
					   ((prev_char >= 'A' && prev_char <= 'Z') &&
					   (next_char >= 'A' && next_char <= 'Z')) ||
					   ((prev_char >= '0' && prev_char <= '9') &&
					   (next_char >= '0' && next_char <= '9'))){  
						
						if(is_collection_remove){
							for(char i = (char) ((int) prev_char + 1); i < next_char; i++){
								for (int j = 0; j < regex.get(regex_counter).size(); j++) {
									if(regex.get(regex_counter).get(j) == current_char){
										regex.get(regex_counter).remove(j);
										//break;
									}
								}
							}
						}else{
							for(char i = (char) ((int) prev_char + 1); i < next_char; i++){
								regex.get(regex_counter).add(i);
							}
						}
					}
					continue;
				}
			}else{
				is_escape = false;
			}
			
			if(is_count_set){
				if(current_char == ','){
					max_regex_chars_count = true;
				}else if(current_char >= '0' && current_char <= '9'){
					RegExSearchType regex_class = regex_type.get(regex_counter);
					if(max_regex_chars_count){
						regex_class.setMaxCount((regex_class.getMaxCount()*10) + (current_char - '0'));
					}else{
						regex_class.setMinCount((regex_class.getMinCount()*10) + (current_char - '0'));
					}
				}else{
					throw new RegExException("Wrong Regular Expression");
				}
				continue;
			}
			
			if(!is_collection){
				regex.add(new ArrayList<Character>());
				regex_counter++;
				this.addToRegexType(regex_counter ,RegExSearchTypes.NORMAL.getCode());
			}
			if(is_collection_remove){
				for (int i = 0; i < regex.get(regex_counter).size(); i++) {
					if(regex.get(regex_counter).get(i) == current_char){
						regex.get(regex_counter).remove(i);
						//break;
					}
				}
			}else{
				regex.get(regex_counter).add(current_char);
			}
		}
//		System.out.println(regex_type.size());
//		for (List<Character> list : regex) {
//			for (Character character : list) {
//				System.out.print(character);
//			}
//			System.out.println(";");
//		}
	}
	
	public boolean match(String input){
		int regex_counter = 0;
		boolean result = true;
		int string_counter;
		int regex_char_counter = 0;
		for (string_counter = 0; string_counter < input.length(); string_counter++) {
			//System.out.println("RegEx Count:" + regex_counter+ " size:" + regex_type.size());
			boolean is_found = false;
			//System.out.println("RegEx With Type:" + regex_type_copy.getType());
			for (char regex_char : regex.get(regex_counter)) {
				if(regex_char == input.charAt(string_counter)){
					is_found = true;
					break;
				}
			} 
			RegExSearchType regex_type_copy = new RegExSearchType(regex_type.get(regex_counter));
			if((regex_type_copy.getType() & RegExSearchTypes.FORTBIDDEN.getCode()) > 0 ){
				is_found = !is_found;
			}
			
			if((regex_type_copy.getType() &  RegExSearchTypes.UNKNOWNCOUNT.getCode()) > 0 ){
				if(!is_found){
					regex_counter++;
					if(regex_type_copy.getMinCount() > 0){
						result = false;
						break;
					}
					string_counter--;
				}//else{
					//check next
				//}
			}else if((regex_type_copy.getType() &  RegExSearchTypes.COUNTER.getCode()) > 0){
				if(is_found){
					regex_char_counter++;
					if(regex_type_copy.getMaxCount() > 0){
						if(regex_type_copy.getMaxCount() <= regex_char_counter){
							regex_counter++;
						}
					}else{
						if(regex_type_copy.getMinCount() - regex_char_counter == 0){
							regex_counter++;
						}
					}
				}else{
					if((regex_type_copy.getMinCount() - regex_char_counter) > 0){
						result = false;
						break;
					}
					regex_counter++;
					string_counter--;
				}
			}else{
				if(is_found){
					regex_counter++;
				}else{
					result = false;
					break;
				}
			}
			
			if((regex_type_copy.getType() &  RegExSearchTypes.START.getCode()) > 0 ){
				//System.out.println("found " + is_found + " s_count " + string_counter + " regex: " + regex_counter);
				if(!is_found && string_counter != 0 && 
				(regex_type_copy.getType() &  RegExSearchTypes.UNKNOWNCOUNT.getCode()) <= 0){
					result = false;
					System.out.println("here");
					break;
				}
			}	
			
			if(regex_counter >= regex.size()){
				break;
			}
		}

		if(regex_counter > regex.size() && (regex_type.get(regex_counter).getMinCount() - regex_char_counter) > 0){
			result = false;
		}
		
		if((string_counter+1) < input.length()){
			result = false;
		}
		for(int counter = regex_counter+1; counter < regex_type.size(); counter++){
			//System.out.println(regex_type.get(counter).getType() & RegExSearchTypes.UNKNOWNCOUNT.getCode());
			if((regex_type.get(counter).getType() & RegExSearchTypes.UNKNOWNCOUNT.getCode()) <= 0){
				result = false;
				break;
			}
		}
		return result;
	}
}
