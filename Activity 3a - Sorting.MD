### Tasks

## 1. Use Big O Notation to describe the time complexity of an algorithm that takes $4N + 16 steps.$- **1 pt**
When working with Big O, you drop the constants and coeffecients, so the time complexity just becomes O(N)


## 2. Use Big O Notation to describe the time complexity of an algorithm that takes $2N^2$. **1 pt**
Just like the first question, drop the constant and I'm left with N^2. You always keep the highest power of N, so in this case it's O(N^2)

## 3. Use Big O Notation to describe the time complexity of the following function, which returns the sum of all numbers of an array after the numbers have been doubled: - **2 pt**
```
def double_then_sum(array) 
	doubled_array = []

	array.each do |number| 
		doubled_array << number *= 2
	end

	sum = 0

	doubled_array.each do |number| 
		sum += number
	end
	return sum 
end

```
There are 2 parts of this function that go through every element in the array, so it's O(N) + O(N), which is just O(N).

## 4. Use Big O Notation to describe the time complexity of the following function, which accepts an array of strings and prints each string in multiple cases: - **2 pts**
```
def multiple_cases(array) 
	array.each do |string|
		puts string.upcase 
		puts string.downcase 
		puts string.capitalize
	end 
end
```
Each operation (uppercase, downcase, and capitalize) are constant time operations. This is just 3N, which simplifies to O(N)

## 5. The next function iterates over an array of numbers, and for each number whose index is even, it prints the sum of that number plus every number in the array. What is this function’s efficiency in terms of Big O Notation? - **4 pts**
```
def every_other(array) 
	array.each_with_index do |number, index|
		if index.even?
			array.each do |other_number|
            	puts number + other_number
			end 
		end
	end 
end
```
There's an inner loop and an outer loop. The inner loop will only run half the time, but even so, we drop constants in big O notation. Since there are two iterations of every element in the array, the time complexity is O(N^2)
