Link to GitHub: https://github.com/jtfox142/OS-1

This is the first project in my Operating Systems course. It's pretty simple. A parent process forks off into a user-determined number of child processes.
The child processes don't do anything too special. They loop through themselves for a user-determined number of iterations, outputting their own process id,
their parent's process id, and the current iteration that they're on. After a one second sleep, they output the same information, but with an "after sleep"
label on the end.

To run, first use the "make" command. This will compile all neccessary files. To run, call ./oss with the appropriate flags.
There are four flags total. "-h" will output a help message that contains similar information to this readme file.
The other available flags are [-n proc], [-s simul], and [-t iter].
The value of proc will determine the total number of child processes to be created.
The value of simul will determine the number of child processes that can run at one time.
The value of iter will detemine the number of times each child will loop before terminating.

An example entry would look like: "./oss -n 5 -s 3 -t 2".

I do not know of any outstanding problems with my code. During my testing, it seemed to compile, run, and terminate just as it should.

For a brief while, I had a small problem where certain flag inputs would cause the parent to terminate before the final child.
I added a waitpid function at the end that looks for the final process id, and I haven't experienced any more trouble.

MADE BY JACOB (JT) FOX
September 14th, 2023 
