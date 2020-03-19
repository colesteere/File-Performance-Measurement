# File-Performance-Measurement
Lab 9 - COEN 177 (Operating Systems)


COEN 177: Operating Systems
Lab assignment 9: File Performance Measurement Objectives

1.   To evaluate file system performance in the face of sequential I/O requests.
2.   To evaluate the impact of multiple competing threads attempting to read/write simultaneously.

Guidelines

The goal of this assignment is to gain experience with simple evaluation of the performance of the file system. Specifically you will be testing the performance of the system under varying conditions. I/O performance can be affected by more than the volume of data being moved. For example it can be affected by the size of the individual requests being made, whether the requests are reading or writing data, and by the degree of contention for access to the disk. It can also be affected dramatically by the pattern of data access (e.g., whether it is sequential or random), but we will only be looking at sequential access in this assignment. 

As a first step, start by creating a collection of test files of varying sizes.  Create a set of files of length 100000, 1000000, 10000000, 100000000, and 10000000000 bytes. These files can be filled with any random data you desire (or all zeroes if you prefer, the actual content of the files does not matter, only their actual size). You can create these files at the command line using the “cat” and “head” commands (where might you find a file of endless zeroes or random numbers to use as a source?).

Now you should create four test programs, and time the running of each one.

1.  Your first program should read a file from beginning to end. It should accept the filename as a parameter. Each read call you make will specify a buffer and a read request size. This program should use a buffer of size 10000 bytes, which you will use for each read. How long does this program take to read through each test file (you may use the “time” command at the shell command line to time the program).

2.  Your second program should accept a numerical parameter at the command line, and should repeat the behavior of your first program, but should now use a buffer of size N (where N is the value accepted at the command line) for each read request. This allows you to re-run the previous timing test but for differently sized I/O operations. Time your second program for read sizes ranging between 100, 1000, 10000 and 10000 bytes.

3.  Your third program should extend your second program by adding one more step. For each read operation, there should now be a corresponding write operation where the data just read is written out to a newly created file. In other words, you should now be timing a program that copies each file that it is run against. You are now testing the speed of sequential reads+writes for files of varying size, and using I/O operations of varying size.

4.  Your fourth and final program will create multiple copies of each file. You will create a number of threads, each of which will read and copy a file (as was done in program 3), but now each thread copies the file to a new file named based on the thread number. Run your timing experiments for all files, using all read/write sizes you used in parts 2 and 3, and for the following number of threads: 2, 8, 32, and 64.
