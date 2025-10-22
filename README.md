# 42 C++ Modules

 
Each module folder is standalone and can be compiled and tested separately.

---

## ⚙️ Build & Run

Each module includes its own `Makefile`.

### Common commands
```bash
make            # compile the project
make clean      # remove object files
make fclean     # remove binaries + objects
make re         # rebuild everything
Example usage
bash

cd cpp04/ex02
make
./Animal
