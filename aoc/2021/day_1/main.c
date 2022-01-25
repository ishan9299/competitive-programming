#include <windows.h>

/*
 * NOTE that instead of allocating memory for 2000 int's use
 * a linked list */

/* this function converts str to integer
 * for now we assume the string to be decimal 
 * format */
static DWORD32
str_to_int(char *str_start, char *str_end) {
	DWORD32 result = 0;
	for(char *i = str_start; i <= str_end; i++) {
		result = (result * 10) + (*i - '0');
	}
	return result;
}

static DWORD32
puzzle_1(DWORD32 *array, DWORD32 total)
{
	BOOL initial_reading = 1;
	DWORD32 result = 0;
	for(DWORD32 i = 0; i < total; i++) {
		if(initial_reading) {
			initial_reading = 0;
		}
		else {
			if (array[i] > array[i-1]) {
				result += 1;
			}
		}
	}
	return result;
}

static DWORD32
puzzle_2(DWORD32 *array, DWORD32 total)
{
	BOOL initial_reading = 1;
	DWORD32 current_sum = 0;
	DWORD32 prev_sum = 0;
	DWORD32 result = 0;
	for (DWORD32 i = 0; i < total-2; i++) {
		if (initial_reading) {
			prev_sum = array[i] + array[i+1] + array[i+2];
			initial_reading = 0;
		}
		else {
			current_sum = array[i] + array[i+1] + array[i+2];
			if (current_sum > prev_sum) {
				result += 1;
			}
			prev_sum = current_sum;
		}
	}
	return result;
}

int
main()
{
	HANDLE file =
		CreateFileA(".\\input.txt", GENERIC_READ, FILE_SHARE_READ, 0,
				OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	LARGE_INTEGER file_size;
	BOOL file_size_result = GetFileSizeEx(file, &file_size);

	if (file_size_result) {
		char *mem_block = 0;
		mem_block = (char *)VirtualAlloc(0, file_size.QuadPart,
				MEM_COMMIT, PAGE_READWRITE);

		DWORD num_of_bytes_read = 0;
		ReadFile(file, mem_block, file_size.QuadPart,
				&num_of_bytes_read, 0);

		DWORD32 start_index = 0;
		DWORD32 end_index = 0;
		DWORD32 integer_index = 0;
		static const DWORD32 total_integers = 2000;
		DWORD32 integers[2000];
		while(end_index <= num_of_bytes_read) {

			if (!(mem_block[end_index] >= '0'
					 && mem_block[end_index] <= '9')) {
				DWORD number = str_to_int(&mem_block[start_index],
						&mem_block[end_index-1]);

				integers[integer_index] = number;
				integer_index += 1;
				start_index = end_index + 2;
				end_index = end_index + 2;

				continue;
			}

			end_index += 1;
		}

		DWORD32 puzzle1_sol = puzzle_1(integers, total_integers);
		DWORD32 puzzle2_sol = puzzle_2(integers, total_integers);

		VirtualFree(mem_block, file_size.QuadPart, MEM_RELEASE);
	}
}
