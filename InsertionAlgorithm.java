//Elba Chimilio
//COP3530, Section: 7303
//Insertion Sort Algorithm

public class InsertionAlgorithm {

	/**
	 * Implements the insertion sort algorithm
	 * @param arr (array constructed from program files)
	 */

	public static void insertionSort(int[] arr) {

		int temp;
		for (int i = 1; i < arr.length; i++) { //Looping through the entire array
			for (int j = i; j > 0; j--) {
				if (arr[j] < arr[j - 1]) { //If the focused number you are comparing is less than the one before it
					temp = arr[j]; 
					arr[j] = arr[j - 1]; //Then swap them
					arr[j - 1] = temp; //This is set as the new focused value
				}
			}
		}
	}
	//End of algorithm
}
//End of program