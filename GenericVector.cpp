#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector {
private:
	T* array; // pointer to the dynamic array
	size_t length; // current size of array

public:
	// constructor
	MyVector() : array(nullptr), length(0) {}

	// destructor
	~MyVector() {
		delete[] array;
	}

	// add element to end of array
	void addElement(T value) {
		T* newArray = new T[length + 1];
		int i;
		for (size_t i = 0; i < length; ++i) {
			newArray[i] = array[i];
		}
		newArray[length] = value; // add new element
		delete[] array; // delete old array
		array = newArray; // update pointer
		++length; // increment size
	}

	// return value at specific index
	T at(size_t index) const {
		if(index >= length) {
			throw std::out_of_range("Index out of range");
		}
		return array[index];
	}

	// return size of array
	size_t size() const {
		return length;
	}

	// calculate sum of all elements
	T sum() const {
		T total = 0;
		for (size_t i = 0; i < length; ++i) {
			total += array[i];
		}
		return total;
	}	

	// find max element
	T max() const {
		if (length == 0) {
			throw std::runtime_error("Array is empty");
		}
		T maxValue = array[0];
		for (size_t i = 1; i < length; ++i) {
			if (array[i] > maxValue) {
				maxValue = array[i];
			}
		}
		return maxValue;
	}

	// find min element
	T min() const {
		if (length == 0) {
			throw std::runtime_error("Array is empty");
		}
		T minValue = array[0];
		for (size_t i = 1; i < length; ++i) {
			if (array[i] < minValue) {
				minValue = array[i];
			}
		}		
		return minValue;
	}

	// create slice of the array
	T* slice(size_t begin, size_t end) const {
		if(begin > end || end >= length) {
			throw std::out_of_range("Slice bounds are invalid");
		}
		size_t sliceSize = end - begin + 1;
		T* newSlice = new T[sliceSize];
		for (size_t i = 0; i < sliceSize; ++i) {
			newSlice[i] = array[begin + i];
		}
		return newSlice;
	}
};

// main function
int main() {
	MyVector<int> intArray;
	
	// adding elements
	intArray.addElement(10);
	intArray.addElement(20);
	intArray.addElement(30);
	intArray.addElement(40);
	intArray.addElement(50);

	// print size
	std::cout << "Size of array is " << intArray.size() << std::endl;

	// print sum of elements
	std::cout << "Sum of array is " << intArray.sum() << std::endl;

	// find max and min
	std::cout << "Maximum of array is: " << intArray.max() << std::endl;
	std::cout << "Minimum of array is: " << intArray.min() << std::endl;

	// creating slice
	int* slicedArray = intArray.slice(1, 3);
	std::cout << "Sliced array: ";
	for (size_t i = 0; i < 3; ++i) { // 3 is end -  begin + 1
		std::cout << slicedArray[i] << " ";
	}
	std::cout << std::endl;

	delete[] slicedArray;

	return 0;
}

