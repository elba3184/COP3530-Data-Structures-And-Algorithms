//Elba Chimilio
//COP3530, Section: 7303
//Bubble Sort Algorithm

public class BubbleAlgorithm {

	/**
	 * Implements the bubble sort algorithm
	 * @param arr (Array constructed from files)
	 */

	public static void bubbleSort(int[] arr) {
		
		int arrLength = arr.length; //Array length
		int temp = 0;
		
		for (int i = 0; i < arrLength; i++) { //Looping through the entire array
			for (int index = 1; index < (arrLength - i); index++) { //Considering pairs through indices adjacent to each other
				if (arr[index - 1] > arr[index]) { //If second value is larger than the first
					temp = arr[index - 1]; //Then swap the elements
					arr[index - 1] = arr[index];
					arr[index] = temp; //This is set as the new focused value
				}
			}
		}
	}
	//End of algorithm
}
//End of program

