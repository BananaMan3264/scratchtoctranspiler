# A Scratch to C Compiler

## Details

This project aims to optimise Scratch projects by converting them directly to C Code.

This project is currently unfinished, but is mostly feature complete. The list of features yet to be added, or fully added can be found in documentation/todo.md.

So far, some Scratch projects will work, but many won't. There are a lot of edge cases and various other behaviours that have not been accounted for.

## Installation / Developement Workflow

To convert the `.sb3` file, `Project.sb3`, into the correct format, you must decompress it using a `.zip` decompression tool
into the folder `scratch/Project/`. `fix.bat` does this automatically for Windows users, but for now it must be done manually
on Linux systems.

The scratchcompiler executable takes the project files found at `scratch/Project/` and generates from that the contents of `output/generated/`.
All other files in `output/` were manually created.

The scratchruntime executable runs the generated files from `output/generated/` using the runtime located in the rest of `output/`.

Both executables are configured using CMake, and their packages are managed using vcpkg.

Although this project is designed to be cross-platfrom, this has not been tested. Theoretically, however, none of the features should be 
plaform specific.