# B2 Style guide

**Please follow these rules on committing any changes, you will be requested to edit your merge if your code does not comply to the following rules.**

---

# Table of contents
- [B2 Style guide](#b2-style-guide)
- [Table of contents](#table-of-contents)
- [Rules](#rules)
	- [Files](#files)
	- [Language](#language)
	- [Variables](#variables)
	- [Comments](#comments)
	- [Blocks](#blocks)
	- [Methods](#methods)

# Rules
## Files
- Tabs, not spaces. Indent should be equivalent to four spaces.
- LF, not CRLF. Linux and Mac users should be fine on this by default, but programmers on Windows will need to change this in their IDEs.
- Header files use the `#pragma once` directive as opposed to using defines to prevent repeated compilation.
- `#include` directives must be listed at the top of the file in alphabetical order, with any standard library headers being written first. Angle brackets `<>` are always used. The `src` directory should be considered as one of the folders searched by the preprocessor. **There is an exception to this:** Source files that implement methods of a header file must have `#include "myheader.h"` above **all** other `#include` directives.
- Use UTF-8 encoding. It's super unlikely you aren't using this anyway but please make sure it's set properly.
- Divide your code into paragraphs (i.e. put a blank line between different sections of code that perform different stages.)

## Language
- All comments must be written in standard British English. If your native language isn't English or your dialect of English isn't British English, let me know and I'll have a look over your comments and try to make them compliant but please do endeavour to conform to this as best you can.
- The Oxford comma **must** be used in all documentation. This separates items of a list by placing a comma after the penultimate item. An example is shown below:

	```
	// Using Oxford comma:	Alice, Bob, and Cathy
	// No Oxford comma:		Alice, Bob and Cathy
	```

## Variables
- Names don't have to be meaningful if it's a throwaway variable (like for a loop), but should be meaningful if it's used throughout a subroutine or shared between subroutines.
- Variables should all be declared separately of one another with their values explicitly stated.

	```
	// Good
	int x = 0;
	int y = 0;

	// Bad
	int x;
	int y;

	// Also Bad
	int x, y = 0;

	// Supremely bad
	int x, y;
	```
- Normal variables should be given names in **camelCase**. Constants and values given by a `#define` directive use **ALL_CAPS**. Method parameters use camelCase but are prefixed by an underscore, like **_myParameter**.

## Comments
- All comments should have a space between the comment token and the content of the comment. For example:

	```
	// This is a good comment
	/* This is also a good comment */

	//This is a bad comment
	/*This is also a bad comment*/
	//     This comment isn't very good either
	```
- Single line comments are preferred; comments of the form `/* Lorem ipsum dolor */` should only use used if it makes sense to have a comment preceding code on the same line.
- Comments of a paragraph should all be indented to the same level.
- Comments describing *why* a line of code exists go after that line. Comments describing the *function of a paragraph* go above that paragraph.
- Comments do not use full stops/periods/the `.` character at the end of them, but you can use ellipses (`...`) where applicable.


## Blocks
- Put an opening brace on the same line as the statement that requires it:

	```
	for(int x = 0; x < 100; x++){
		// Do something...
	}
	```
- `switch case` statements should be written with the `case` labels indented one level and their corresponding code indented a level further. A blank line should be left between each case. An example is shown below:

	```
	switch(myVar){
		case 1:
			// Do something...
			break;

		case 2:
			// Do something else...
			return;
		
		default:
			// This will fix it
			break;
	}
	```

## Methods
- All methods must be given names in **PascalCase**.
- All methods must be given descriptions like so:

	```
	/// @brief My useless method
	/// @param _a An integer that does nothing
	/// @param _b A completely meaningless character
	/// @return The number 0
	int MyMethod(int _a, char _b){
		int x = 0;
		return x;
	}
	```
- Methods should not be given descriptions in header files, only the source files where they're defined.
