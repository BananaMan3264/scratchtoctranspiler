# Style Guide for the Project

- Always use tabs for indentation.
- Whenever possible, British English spellings of words should be used (eg. Colour as opposed to Color)
- All changes should be made as portable and cross platform as possible.
- All code should be written in pure C, no C++ or other code is acceptable.
- No compiler specific extensions are allowed, all code must be able to be compiled using any mainstream C Compiler.
	- This also means all features must be compatible with MSVC, and therefore that many modern C features cannot be used.
- Braces style
	- There are two acceptable ways for doing functions
	- The former is used for normal length code, while the latter is for code that can fit in ~1 line.
	- This doesn't really matter that much, but it is prefered to use the following methods.
```c
void function() 
{
	// Code
}
```


```c
void function() { /* Code */ }
```

