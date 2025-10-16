fn fib_print() {
	b32 first = 0;
	b32 second = 1;
	b32 third = 1;

	while (third < 255) {
		first = second;
		second = third;
		third = first + second;

		std:printf("%d\n", third);
	}
}
