cin <math.h>
cin <stdio.h>

fn reverse(b32* n) {
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
		*n += (num % 10) * pow(10, i);
		num /= 10;
		i--;
	}
}

b32 main() {
	b32 n;
	scanf("%d", &n);

	reverse(&n);

	printf("%d\n", n);
}
