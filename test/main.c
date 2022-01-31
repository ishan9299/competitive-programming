#include <stdbool.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>

int divide(int dividend, int divisor){
	int ans = 0;
	if ((divisor < 0 && dividend < 0)
			|| (divisor > 0 && dividend > 0)) {
		if (dividend > INT_MAX) {
			return INT_MAX;
		}
		for (;;) {
			dividend -= divisor;
			ans++;
			if (ans == INT_MAX) {
				return INT_MAX;
			}
			if (dividend == 0) {
				break;
			} else if (dividend < 0) {
				ans--;
				break;
			}
		}
	} else if ((divisor < 0 && dividend > 0)
			|| (divisor > 0 && dividend < 0)) {
		if (dividend < INT_MIN) {
			return INT_MIN;
		}
		for (;;) {
			dividend += divisor;
			ans--;
			if (ans == INT_MIN) {
				return INT_MIN;
			}
			if (dividend == 0) {
				break;
			} else if (dividend < 0) {
				ans++;
				break;
			}
		}
	}
	return ans;
}

int main() {
	int ans;
	ans = divide(-4, -1);
}
