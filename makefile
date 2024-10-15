exeAVL: AVLMain.o AVLFunctions.o
	gcc -o exeAVL AVLMain.o AVLFunctions.o 
AVLMain.o: AVLMain.c
	gcc -c AVLMain.c
AVLFunctions.o: AVLFunctions.c
	gcc -c AVLFunctions.c