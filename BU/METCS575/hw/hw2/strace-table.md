# Table for strace output

| System Calls                 | C    | C++  | Java | Python | Bash |
|------------------------------|------|------|------|--------|------|
| execve()                     | 1    | 1    | 1    | 1      | 1    |
| open()/openat()              | 2    | 5    | 8    | 27     | 7    |
| close()                      | 2    | 5    | 8    | 22     | 7    |
| read()                       | 1    | 4    | 9    | 22     | 6    |
| write()                      | 1    | 1    | 0    | 1      | 1    |
| mmap()                       | 8    | 22   | 34   | 27     | 14   |
|                              |      |      |      |        |      |
| "strace -e output file size" | 1.3K | 3.3K | 5.5K | 7.7K   | 2.7K |
