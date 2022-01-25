#include <windows.h>

struct position {
	DWORD horizontal;
	DWORD depth;
};

struct position_aim {
	DWORD horizontal;
	DWORD depth;
	DWORD aim;
};

static BOOL
is_number(char c)
{
	if(c >= '0' && c <= '9') {
		return 1;
	}
	return 0;
}

static BOOL
is_alphabet(char c)
{
	if((c >= 'a' && c <= 'z')
			&& (c >= 'A' && c <= 'Z')) {
		return 1;
	}
	return 0;
}

static DWORD
str_to_int32(char *start, char *end)
{
	DWORD32 result = 0;
	for (char *i = start; i <= end; i+=1) {
		if (is_number(*i)) {
			result = (result * 10) + (*i - '0');
		}
	}
	return result;
}

static char*
get_instruction_endpoint(char *start, char* end)
{
	char *instruction_end = 0;
	for (char *i = start; i <= end; i += 1) {
		if (*i == ' ') {
			instruction_end = i - 1;
		}
	}
	return instruction_end;
}

static BOOL
string_compare(char *string_1, char *string_2, DWORD length) {
	BOOL is_equal = 1;
	for (DWORD i = 0; i <= length; i++) {
		if (*string_1 != *string_2) {
			is_equal = 0;
		}
		string_1 += 1;
		string_2 += 1;
	}
	return is_equal;
}

static void
puzzle_1(char *start, char *end, struct position *p)
{
	char *command_end = get_instruction_endpoint(start, end);
	DWORD magnitude = str_to_int32(command_end + 2, end);
	if(string_compare(start, "forward", command_end - start)) {
		p->horizontal = p->horizontal + magnitude;
	}
	if(string_compare(start, "down", command_end - start)) {
		p->depth = p->depth + magnitude;
	}
	if(string_compare(start, "up", command_end - start)) {
		p->depth = p->depth - magnitude;
	}
}

static void
puzzle_2(char *start, char *end, struct position_aim *p)
{
	char *command_end = get_instruction_endpoint(start, end);
	DWORD magnitude = str_to_int32(command_end + 2, end);
	if(string_compare(start, "forward", command_end - start)) {
		p->horizontal += magnitude;
		p->depth += p->aim * magnitude;
	}
	if(string_compare(start, "down", command_end - start)) {
		p->aim += magnitude;
	}
	if(string_compare(start, "up", command_end - start)) {
		p->aim -= magnitude;
	}
}

int
main()
{
	HANDLE file = CreateFileA(".\\input.text", GENERIC_READ,
			FILE_SHARE_READ, 0, OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL, 0);

	if (file == INVALID_HANDLE_VALUE) {
		// TODO LOG: CreateFileA failed
		return 0;
	}

	LARGE_INTEGER file_size;
	BOOL getfilesizeex_success = GetFileSizeEx(file, &file_size);
	if(!getfilesizeex_success) {
		// TODO: LOG: GetFileSizeEx failed
	}

	char* memblock = VirtualAlloc(0, file_size.QuadPart, MEM_COMMIT,
			PAGE_READWRITE);

	DWORD num_bytes_read = 0;
	BOOL readfilesize_success =
		ReadFile(file, memblock, file_size.QuadPart,
			&num_bytes_read, 0);

	if(!readfilesize_success) {
		// TODO: LOG: ReadFile function failed.
	}

	char *instruction_start = memblock;
	char *instruction_end = 0;
	struct position p = {
		.horizontal = 0,
		.depth = 0
	};
	struct position_aim pa = {
		.horizontal = 0,
		.depth = 0,
		.aim = 0
	};
	DWORD bytes_parsed = 0;
	while(bytes_parsed <= num_bytes_read) {
		if(memblock[bytes_parsed] == 13) {
			instruction_end = &memblock[bytes_parsed - 1];
			puzzle_1(instruction_start, instruction_end, &p);
			puzzle_2(instruction_start, instruction_end, &pa);
			instruction_start = &memblock[bytes_parsed] + 2;
			bytes_parsed += 2;
		}
		bytes_parsed += 1;
	}

	VirtualFree(memblock, 0, MEM_RELEASE);
}
