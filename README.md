<h1 align="center">
	Push_swap
</h1>

<p align="center">
	<b><i>Data sorting on a stack.</i></b><br>
</p>
<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/ogonzi/push_swap?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/ogonzi/push_swap?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/ogonzi/push_swap?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/ogonzi/push_swap?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/ogonzi/push_swap?color=green" />
</p>

<h3 align="center">
	<a href="#about">About</a>
	<span> · </span>
	<a href="#features">Features</a>
	<span> · </span>
	<a href="#usage">Usage</a>
</h3>

---

## About

This project is about sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed various types of sorting algorithms must be manipulated and chosen for optimized data sorting.

For stacks of size smaller or equal than 5 the instructions are hardcoded, while for stacks larger then 5 a bucket sort algorithm is used. An optimization is added to bucket sort if the stack size is larger than 125, where each bucket is divided into quarters to minimize the number of moves further along the line.

<p align="center">
	<img src="https://github.com/ogonzi/push_swap/blob/dev/visual.gif" />
</p>

## Features

### Mandatory

- Sorts 5 numbers in a maximum of 8 instructions.
- Sorts 100 numbers with ~650 instructions.
- Sorts 500 numbers in ~5300 instructions.

### Bonus

- Executes the sorting instructions.
- Checks if stack a is sorted and stack b is empty, displays "OK" or "KO" accordingly.

## Usage

To sort a stack, compile:

```shell
$ make
```

set the arguments:
```shell
$ ARG="3 -4 0 -12 13 16"
```

and run:
```shell
$ ./push_swap $ARG
```
To verify the set of instructions is correct, compile bonus:

```shell
$ make bonus
```

and run:
```shell
$ ./push_swap $ARG | ./checker $ARG
```

## Authors

- [@ogonzi](https://www.github.com/ogonzi)

