// Java program to implement a queue using an array
import java.lang.*;
public class Implement_Queue_using_array_in_Java{
	static private int front, rear, capacity;
	static private int queue[];

	Implement_Queue_using_array_in_Java (int c)
	{
		front = rear = 0;
		capacity = c;
		queue = new int[capacity];
	}

	// function to insert an element
	// at the rear of the queue
	static void queueEnqueue(int data)
	{
		// check queue is full or not
		if (capacity == rear) {
			System.out.printf("\nQueue is full\n");
			return;
		}

		// insert element at the rear
		else {
			queue[rear] = data;
			rear++;
		}
		return;
	}

	// function to delete an element
	// from the front of the queue
	static void queueDequeue()
	{
		// if queue is empty
		if (front == rear) {
			System.out.printf("\nQueue is empty\n");
			return;
		}

		// shift all the elements from index 2 till rear
		// to the right by one
		else {
			for (int i = 0; i < rear - 1; i++) {
				queue[i] = queue[i + 1];
			}

			// store 0 at rear indicating there's no element
			if (rear < capacity)
				queue[rear] = 0;

			// decrement rear
			rear--;
		}
		return;
	}

	// print queue elements
	static void queueDisplay()
	{
		int i;
		if (front == rear) {
			System.out.printf("\nQueue is Empty\n");
			return;
		}

		// traverse front to rear and print elements
		for (i = front; i < rear; i++) {
			System.out.printf(" %d <-- ", queue[i]);
		}
		return;
	}

	// print front of queue
	static void queueFront()
	{
		if (front == rear) {
			System.out.printf("\nQueue is Empty\n");
			return;
		}
		System.out.printf("\nFront Element is: %d",
						queue[front]);
		return;
	}
}

class Naya{

	// Driver code
	public static void main(String[] args)
	{
		// Create a queue of capacity 4
		Implement_Queue_using_array_in_Java q = new Implement_Queue_using_array_in_Java(4);

		// print Queue elements
		Implement_Queue_using_array_in_Java.queueDisplay();

		// inserting elements in the queue
		Implement_Queue_using_array_in_Java.queueEnqueue(20);
		Implement_Queue_using_array_in_Java.queueEnqueue(30);
		Implement_Queue_using_array_in_Java.queueEnqueue(40);
		Implement_Queue_using_array_in_Java.queueEnqueue(50);

		// print Queue elements
		Implement_Queue_using_array_in_Java.queueDisplay();

		// insert element in the queue
		Implement_Queue_using_array_in_Java.queueEnqueue(60);

		// print Queue elements
		Implement_Queue_using_array_in_Java.queueDisplay();

		Implement_Queue_using_array_in_Java.queueDequeue();
		Implement_Queue_using_array_in_Java.queueDequeue();
		System.out.printf(
			"\n\nafter two node deletion\n\n");

		// print Queue elements
		Implement_Queue_using_array_in_Java.queueDisplay();

		// print front of the queue
		Implement_Queue_using_array_in_Java.queueFront();
	}
}
