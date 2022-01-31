// 0 1 2 3 4 5 6 7 8

int32_t check(int32_t *array, uint32_t index, int32_t target) {
	int32_t element = array[index];
	if (target <= element) {
		return 1;
	} else {
		return 0;
	}
}

uint32_t
BinarySearch(int32_t *array, uint32_t size, int32_t target) {
	uint32_t low = 0;
	uint32_t high = size - 1;
	while (high > low) {
		uint32_t mid_index = (low + high) / 2;
		if (check(mid_index)) {
			high = mid_index;
		} else {
			low = mid_index + 1;
		}
	}

	if (array[low] == target) {
		return 1;
	} else {
		return 0;
	}
}
