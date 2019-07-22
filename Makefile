
Chortke: Makefile
	gcc -o Chortke Chortke.c Libs/Processing.c Libs/Processing.h Libs/Stack.c Libs/Stack.h Libs/UI.c Libs/UI.h Libs/bitmap_ploter.c Libs/bitmap_ploter.h -lm

clean:
	rm -f Chortke *~
