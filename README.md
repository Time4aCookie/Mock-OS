# Mock OS
I have created a static library that
implements a mock operating system.
A user of this mock operating system will be able to
create and interact with files using commands.

## Directory structure

The idea is to separate the public interface from its implementation.

- [include/](./include)
  - This directory contains the public header files for the static library.
- [lib/](./lib)
  - This directory contains the source files for the implementation of the static library.
- [src/](./src)
  - This directory contains the source files for the executable code.
- [tests/](./tests)
  - This directory contains the unit tests.
 
