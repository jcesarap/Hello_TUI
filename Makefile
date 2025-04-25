# Makefile - For compiling
# A Makefile automates building executables from source code by defining rules and dependencies

# Main target - links object files to create executable
# Linking combines compiled object files and libraries into a final executable
# Here we link our test program with both our custom library and ncurses
# -L. looks for libraries in current directory, -l specifies library names
default: src/bibtela.c libbibtela.a
	gcc tstbibtela.c -o tstbibtela -L. -l bibtela -l ncursesw
#	gcc $< -o $@ -L. -l bibtela -l ncursesw

# Creates static library from object file
# Static libraries (.a files) are archives of object files that get copied into executables
# 'ar rc' creates/updates the library (r=replace, c=create) with the object file
libbibtela.a: src/bibtela.o
	ar rc libbibtela.a src/bibtela.o

# Compiles source file into object file
# Object files contain machine code but aren't directly executable
# -c flag compiles without linking, -o specifies output file
src/bibtela.o: src/bibtela.c src/bibtela.h
	gcc -c src/bibtela.c -o src/bibtela.o 

# Cleanup target - removes generated files
# Important for reproducible builds and removing temporary build artifacts
# Removes the executable, all object files, and library files
clean:
	rm -f tstbibtela src/*.o *.a
