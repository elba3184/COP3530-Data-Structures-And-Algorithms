//Elba Chimilio
//COP3530, Section: 7303
//Quick Sort Algorithm

public class QuickAlgorithm {
	
	/**
	 * Implements Quick Sort algorithm
	 * @param arr (Array constructed from files)
	 */
	
	public static void quickSort(int[] arr, int left, int right) {
		
		if (arr == null | arr.length == 0) {
			return;
		}
		if (left >= right) {
			return;
		}
		
		int middle = left + (right - left) / 2;//Middle of array
		int pivot = arr[middle];//Choosing the pivot
		
		int i = left;
		int j = right;
		
		//Makes the left of pivot less than pivot
		//And right of pivot more than pivot
		while (i <= j) {
			while (arr[i] < pivot) {
				i++;
			}
			while (arr[j] > pivot) {
				j--;
			}
			//If the left value is smaller than or equal to the right value, then swap
			if (i <= j) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				i++;
				j--;
			}
		}
		
		//Recursively sort
		if (left < j)
			quickSort(arr, left, j);
		if (right > i)
			quickSort(arr, i, right);
	}
	//End of algorithm
}
//End of program