#include <windows.h>

struct file {
	HANDLE handle;
	LARGE_INTEGER size;
	char *memblock;
};

struct count_binary {
	DWORD zero;
	DWORD one;
};

struct power_consumption {
	DWORD *epsilon;
	DWORD *gamma;
};

static DWORD
file_load(struct file *f, const char* file_name)
{
	f->handle = CreateFileA(file_name, GENERIC_READ, FILE_SHARE_READ,
			0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	BOOL getfilesizeex_result = GetFileSizeEx(f->handle, &f->size);
	if (getfilesizeex_result) {
		f->memblock = (char *)VirtualAlloc(0, f->size.QuadPart,
				MEM_COMMIT, PAGE_READWRITE);
	} else {
		f->memblock = 0;
	}
	DWORD bytes_read = 0;
	BOOL readfile_result = ReadFile(f->handle, f->memblock,
			f->size.QuadPart, &bytes_read, 0);
	if (!readfile_result) {
		// LOG cannot load the file in memory buffer
	}
	return bytes_read;
}

/*
 * It counts the number of bits in the binary number given in the input
 * file */
static DWORD
bit_count(char *f)
{
	DWORD result = 0;
	while(*f != 13) {
		result += 1;
		f += 1;
	}
	return result;
}

static void
file_unload(struct file *f)
{
	VirtualFree(f->memblock, 0, MEM_RELEASE);
}

static void
bitsperrow_count(struct file *f, struct count_binary *b, DWORD bytes_read,
		DWORD bits)
{
	DWORD bytes_parsed = 0;
	while(bytes_parsed <= bytes_read) {
		for (DWORD i = 0; i < bits; i += 1) {
			if (f->memblock[bytes_parsed] == '1') {
				b[i].one += 1;
			} else if (f->memblock[bytes_parsed] == '0') {
				b[i].zero += 1;
			}
			bytes_parsed += 1;
		}
		bytes_parsed += 2; // cr + lf
	}
}

static void
calculate_gamma_epsilon(struct power_consumption *p, struct count_binary *b,
		DWORD bits)
{
	for(DWORD i = 0; i < bits; i++)
	{
		if(b[i].one > b[i].zero) {
			p->gamma[i] = 1;
			p->epsilon[i] = 0;
		} else if(b[i].zero > b[i].one) {
			p->gamma[i] = 0;
			p->epsilon[i] = 1;
		}
	}
}

static UINT64
pow_int32(DWORD a, DWORD b)
{
	UINT64 result = 1;
	while(b > 0) {
		if (b & 1) {
			result = result * a;
		}
		a = a * a;
		b = b >> 1;
	}
	return result;
}

static UINT64
convert_bin2int(DWORD *array, DWORD length)
{
	UINT64 result = 0;
	DWORD j = 0;
	for (DWORD i = length; i > 0; i -= 1) {
		result += pow_int32(2, i - 1) * array[j];
		j += 1;
	}
	return result;
}

static UINT64
puzzle_1_solve(struct power_consumption *p, struct count_binary *b, DWORD bits)
{
	UINT64 result;
	p->gamma = (DWORD *)VirtualAlloc(0,
			sizeof(DWORD) * bits, MEM_COMMIT, PAGE_READWRITE);

	p->epsilon = (DWORD *)VirtualAlloc(0,
			sizeof(DWORD) * bits, MEM_COMMIT, PAGE_READWRITE);

	calculate_gamma_epsilon(p, b, bits);
	result = convert_bin2int(p->gamma, bits) * convert_bin2int(p->epsilon, bits);
	VirtualFree(&p, 0, MEM_RELEASE);
	return result;
}

int
main()
{
	struct file f;
	DWORD bytes_read = file_load(&f, "./input.text");
	DWORD bits = bit_count(f.memblock);

	struct count_binary *b =
		(struct count_binary *)VirtualAlloc(0,
				sizeof(struct count_binary) * bits,
				MEM_COMMIT, PAGE_READWRITE);
	bitsperrow_count(&f, b, bytes_read, bits);

	struct power_consumption p;
	UINT64 puzzle_1_ans = puzzle_1_solve(&p, b, bits);

	VirtualFree(b, 0, MEM_RELEASE);
	file_unload(&f);
}
