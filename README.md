# trim-and-trace-memory-references
[![GitHub license](https://img.shields.io/github/license/jellycsc/trim-and-trace-memory-references.svg)](https://github.com/jellycsc/trim-and-trace-memory-references/blob/master/LICENSE)

Trim and trace the memory usage of a simple matmul program and count the number of accesses to different parts of memory.

## Getting Started

### Prerequisites

* GCC
* Shell (Bash is recommended)

### Download source code and compile
The following instructions are presented using Bash in macOS:
```
# Change to HOME directory
$ cd ~

# Clone this repo and 'cd' into it
$ git clone https://github.com/jellycsc/trim-and-trace-memory-references.git
$ cd trim-and-trace-memory-references/

# Let's compile.
$ make
gcc -Wall -std=gnu99 -g -c life.c
gcc -Wall -std=gnu99 -g -c life_helpers.c
gcc -Wall -std=gnu99 -g -o life life.o life_helpers.o
```

### Usage
```
Usage: trim tracefile markerfile
Usage: trcount [tracefile]
```

## Examples
```
$ ./trim sample-full-simple.tr sample-marker-simple
I,0x400769
S,0x601070
I,0x400773
S,0x60106c
I,0x40077d
L,0x601070
I,0x400783
L,0x60106c
I,0x400789
I,0x40078b
S,0xfff00090c
I,0x40078e
$ ./trcount sample-trim-output
Reference Counts by Type:
    Instructions: 7
    Modifications: 0
    Loads: 2
    Stores: 3
Data Reference Counts by Location:
    Globals: 4
    Heap: 0
    Stack: 1
```

## Auto test
```
$ make test_trim
Compiled and trim check passed :)
$ make test_trcount
Compiled and trcount check passed :)
```

## Author(s)

| Name                    | GitHub                                     | Email
| ----------------------- | ------------------------------------------ | -------------------------
| Chenjie (Jack) Ni       | [jellycsc](https://github.com/jellycsc)    | nichenjie2013@gmail.com

## Thoughts and future improvements

* Since this is a rather simple beginner's project, no further improvements will be made.

## Contributing to this project

1. Fork it [![GitHub forks](https://img.shields.io/github/forks/jellycsc/trim-and-trace-memory-references.svg?style=social&label=Fork&maxAge=2592000&)](https://github.com/jellycsc/trim-and-trace-memory-references/fork)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -m 'Add some feature'`)
4. Push to your feature branch (`git push origin my-new-feature`)
5. Create a new Pull Request

Details are described [here](https://git-scm.com/book/en/v2/GitHub-Contributing-to-a-Project).

## Bug Reporting [![GitHub issues](https://img.shields.io/github/issues/jellycsc/trim-and-trace-memory-references.svg?)](https://github.com/jellycsc/trim-and-trace-memory-references/issues/)

Please click `issue` button above↑ to report any issues related to this project  
OR you can shoot an email to <nichenjie2013@gmail.com>

## License
This project is released under GNU General Public License v3.0 - see [LICENSE](LICENSE) file for more details.
