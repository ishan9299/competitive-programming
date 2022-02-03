void
SwapElements(int32_t *x, int32_t *y)
{
	int32_t temp = *x;
	*x = *y;
	*y = temp;
}

void
SelectionSortI32(int32_t *array, uint32_t size)
{
	for (uint32_t i = 0; i < size; i++) {
		int32_t minimum = array[i];
		for (uint32_t j = i + 1; j < size; j++) {
			if (minimum > array[j]) {
				minimum = array[j];
				SwapElements(&array[i], &array[j]);
			}
		}
	}
}

void
BubbleSortI32(int32_t *array, uint32_t size)
{
	for (uint32_t i = 0; i < size - 1; i++) {
		for (uint32_t j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				SwapElements(&array[j], &array[j + 1]);
			}
		}
	}
}

void
InsertionSortI32(int32_t *array, uint32_t size)
{
	for (uint32_t i = 1; i < size; i++) {
		int32_t value = array[i];
		uint32_t hole = i;
		while (hole > 0 && array[hole - 1] > value) {
			array[hole] = array[hole - 1];
			hole--;
		}
		array[hole] = value;
	}
}

void
Merge()
{
}

void
MergeSort(int *array, uint32_t size)
{
}

uint32_t
Partition(int32_t *array, uint32_t high, uint32_t low)
{
	int32_t pivot = array[low];
	uint32_t lesser_side_index = low - 1;
	uint32_t greater_side_index = high + 1;

	while (1) {
		do {
			lesser_side_index++;
		} while(array[lesser_side_index] < pivot);

		do {
			greater_side_index--;
		} while(array[greater_side_index] > pivot);

		if (lesser_side_index >= greater_side_index) {
			return greater_side_index;
		}

		int32_t temp = array[lesser_side_index];
		array[lesser_side_index] = array[greater_side_index];
		array[greater_side_index] = temp;
	}
}

void
QuickSortI32(int32_t *array, uint32_t high, uint32_t low)
{
	if (high > low) {
		uint32_t p = Partition(array, high, low);
		QuickSortI32(array, p, low);
		QuickSortI32(array, high, p + 1);
	}
}
