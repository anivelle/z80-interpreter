z80:
	clang Z80Interpreter.c -o z80

convert:
	clang Converter.c -o converter

clean:
	rm converter ROMTest ROMTest2 convertout z80 out.txt