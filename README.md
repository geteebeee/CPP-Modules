# 42 C++ Modules

 
Each module folder is standalone and can be compiled and tested separately.

---

## ⛷️ Topics
```bash
00 - Namespaces, classes, member functions, stdio streams, initialization lists and some other basic stuff
01 - Memory allocation, pointers to members, references, switch statement
02 - Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form
03 - Inheritance
04 - Subtype polymorphism, abstract classes, interfaces
05 - Repetition and Exceptions
06 - Casts
07 - Templates
08 - Templated containers, iterators, algorithms
09 - STL
```


## ⚙️ Build & Run

Each modules exercises include their own `Makefile`.

### Common commands
```bash
make            # compile the project
make clean      # remove object files
make fclean     # remove binaries + objects
make re         # rebuild everything


# Example usage:
cd cpp04/ex02
make
./Animal
