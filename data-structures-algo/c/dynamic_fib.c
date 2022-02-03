int32_t fibonacci(int32_t n) {
	if (n != 0) {
		int32_t prev = 0;
		int32_t curr = 1;
		for (int32_t i = 2; i < (n + 1); i++) {
			int32_t new = curr + prev;
			prev = curr;
			curr = new;
		}
		return curr;
	}
	return 0;
}
