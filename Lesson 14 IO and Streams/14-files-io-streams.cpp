/*
! Files, Streams and I/O
? C++ uses streams as an interface between the program and input and output devices
? Independent of the actual device
? Sequence of bytes
? Input stream provides data to the program
? Output stream receives data from the program

* Outline
Input Device -> Input Stream -> Program -> Output Stream -> Output Device

* Common header files
Header File   Description
iostream      Provides definitions for formatted input and output from/to streams
fstream       Provides definitions for formatted input and output from/to file streams
iomanip       Provides definitions for manipulatros used to format stream I/O

* Commonly used stream classes
Class         Description
ios           Provides basic support for formatted and unformatted I/O operations. Base class for most other classes
ifstream      Provides for high-level input operations on file based streams (reads from file)
ofstream      Provides for high-level output operations on file based streams (writes to file)
fstream       Provides for high-level I/O operations on file based streams. Derived from ofstream and ifstream
stringstream  Provides for high-level I/O operations on memory based strings. Derived from istringstream and ostringstream

* Global stream objects
Object    Description
cin       Standard input stream - by default 'connected' to the standard input device(keyboard). Instance of istream
cout      Standard output stream - by default 'connected' to the standard output device(console). Instance of ostream
cerr      Standard error stream - by default 'connected' to the standard error device(console). Instance of ostream (unbuffered)
clog      Standard log stream - by default 'connected' to the standard log device(console). Instance of ostream (unbuffered)

* Global objects - initialized before main executes
* Best practice is to use cerr for error messages and clog for log messages.

! I/O Redirection
? I/O redirection allows changing the source of input or the destination of output.
? Instead of reading input from the keyboard and writing output to the terminal,
? I/O redirection lets us work with files or other input/output streams.

* Standard Output Redirection
Symbol  Purpose                           Example Usage
>       Redirect output to a file         ./program > output.txt
<       Redirect input from a file        ./program < input.txt
>>      Append output to a file           ./program >> log.txt
2>      Redirect errors to a file         ./ program 2> errors.txt
2>&1    Combine std::cout and std::cerr   ./ program > all_output.txt 2>&1
*/