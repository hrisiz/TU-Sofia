#include<stdio.h>
#include<stdlib.h>

int main(){
	int array[4][4] = {
		{1,-2,3,-4},
		{-12,13,-14,5},
		{11,-16,15,-6},
		{-10,9,-8,7}
	};	
	
	int array_size = 4;
	int r = array_size/2;
	int new_array[array_size*array_size];
	int array_in = 0;
	int elem = 0;
	while(1){
		int max_elements = ((r*2)-1)+array_in;
		for(int x = array_in; x < max_elements; x++){
			new_array[elem++] = array[array_in][x];
		}
		for(int y = array_in; y < max_elements; y++){
			new_array[elem++] = array[y][max_elements];
		}
		for(int x = max_elements; x > array_in; x--){
			new_array[elem++] = array[max_elements][x];
		}
		for(int y = max_elements; y > array_in; y--){
			new_array[elem++] = array[y][array_in];
		}
		if(r == 1){
			break;
		}	
		r--;	
		array_in++;
	}
	int prev_elem = new_array[0];
	int result = 1;
	int bigger;
	if(new_array[0] > new_array[1]){
		bigger = 1;
	}else{
		bigger = 0;
	}
	for(int i = 1; i < elem ;i++){
		if(prev_elem < new_array[i] && bigger == 1){
			result = 0;
			break;
		}else if(prev_elem > new_array[i] && bigger == 0){
			result = 0;
			break;
		}
		bigger *= -1;
		prev_elem = new_array[i];
	}
	if(result == 1){
		printf("OK!\n");
	}else{
		printf("Not OK!\n");
	}
	return EXIT_SUCCESS;
}
