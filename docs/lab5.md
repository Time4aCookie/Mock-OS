# Lab 5

## Team Members & Work Split:
- Rohan Tatikonda (r.s.tatikonda@wustl.edu)
	- rm, cp
- Evan Tompkins (e.b.tompkins@wustl.edu)
	- ls, touch password functionality, edit & display macro
- Grayson Martin (g.p.martin@wustl.edu)
	- ds, rn, extra credit

## Part 9 - Edit & Display Macro incomplete - but the macro command
We chose to implement a macro command to edit a file and display the contents of the file immediately once editing is finihsed. To call this command, we only need one argument, which is the name of the file that we will both be editing and displaying, and optionally, -a can be included to edit the file by appending it instead of rewriting it. To test the method, I made sure that the only way the commmand can be invoked is with the 1-2 arguments. I made sure that this worked with text files and image files, with or without the optional append, and only in the order that I specified. Once the command was running, I cross references the display with what I entered to make sure that the two matched up.

## Extra Credit
We implemented a fully interactive shell, adding a command history which can be used by pressing the up and down arrow keys. On macOS and Linux systems, pressing the tab key to auto-complete a file name in the file system is also supported. This auto-complete functionality isn't available on windows due to limitations with the underlying cmd.exe prompt.
