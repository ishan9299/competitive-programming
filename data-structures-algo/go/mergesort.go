// O(n) = (n*log(n))
package main

import "fmt"

func mergeSort(leftHalf []int, rightHalf []int) []int {
	array := make([]int, len(leftHalf) + len(rightHalf))
	i := 0
	j := 0

	for i < len(leftHalf) && j < len(rightHalf) {
		if leftHalf[i] <= rightSplitSlice[j] {
			array[i + j] = leftHalf[i]
			i = i + 1
		} else {
			array[i + j] = rightHalf[j]
			j = j + 1
		}
	}

	for i < len(leftHalf) {
		array[i + j] = leftHalf[i]
		i = i + 1
	}

	for j < len(rightHalf) {
		array[i + j] = rightHalf[j]
		j = j + 1
	}
	return array
}

func merge(array []int) []int {
	size := len(array)
	midindex := size/2
	if size < 2 {
		return array
	}
	var leftHalf = array[:midindex]
	var rightHalf = array[midindex:]
	return mergeSort(merge(leftHalf), merge(rightHalf))
}

func main() {
	fmt.Println(merge([]int{ 2, 4, 1, 3, 8, 6, 5, 7 }))
}
