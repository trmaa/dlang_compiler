cin <math.h>
cin <stdio.h>

fn reverse(int* n) {
	b32 num = *n / 10;
	b32 size = 0;

	while (num > 0) {
		num /= 10;
		size += 1;
	}

	num = *n;

	*n = 0;

	b32 i = size;
	while (num > 0) {
		*n += (num % 10) * std:pow(10, i);
		num /= 10;
		i--;
	}
}

b32 std:main() {
	b32 n = 1234;
	reverse(&n);

	std:printf("%d\n", n);
}
