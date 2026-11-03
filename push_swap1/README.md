*This project has been created as part of the 42 curriculum by kasen, onaktas.*

# push_swap

## Description

`push_swap` sorts a list of unique signed 32-bit integers with two stacks and
the eleven operations allowed by the subject. The input starts in stack `a`,
stack `b` is empty, and the program prints an operation sequence that leaves
`a` sorted in ascending order.

The mandatory project contains four runtime-selectable strategies:

- Simple: an O(n^2) minimum-extraction strategy.
- Medium: an O(n * sqrt(n)) chunk-based strategy.
- Complex: an O(n log n) binary radix strategy.
- Adaptive: selects a strategy from the measured disorder.

The project also handles quoted input, signed values, duplicate detection,
32-bit range validation and benchmark reporting.

## Instructions

### Compilation

Build the project in a Unix-like 42 environment with:

```sh
make
```

The Makefile provides the required targets:

```sh
make all
make clean
make fclean
make re
```

Compilation uses:

```text
-Wall -Wextra -Werror
```

### Execution

Run the program with separate integer arguments:

```sh
./push_swap 3 2 1
```

Quoted groups and mixed arguments are accepted:

```sh
./push_swap "3 2 -1"
./push_swap "3 2" 1
```

Strategy selectors:

```text
--simple    force the O(n^2) strategy
--medium    force the O(n * sqrt(n)) strategy
--complex   force the O(n log n) strategy
--adaptive  select a strategy from disorder; this is the default
```

Examples:

```sh
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
./push_swap 5 4 3 2 1
```

Already sorted input and an invocation without parameters produce no output.

### Error handling

Invalid tokens, duplicate values, malformed options and integers outside the
signed 32-bit range print `Error` followed by a newline to standard error and
return status 1. Normal Push_swap operations are written only to standard
output, one operation per line.

Examples:

```sh
./push_swap 1 2 1
./push_swap 1 abc 3
./push_swap 2147483648
./push_swap -2147483649
```

### Benchmark mode

`--bench` keeps the operation stream on standard output and writes measurements
to standard error:

```sh
./push_swap --bench --adaptive 5 4 3 2 1 \
    1>operations.txt 2>benchmark.txt
```

The report includes the disorder percentage with two decimal places, the
strategy and complexity class, the total operation count and the individual
counts for `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb` and
`rrr`.

## Design and algorithms

### Stack representation

Both stacks are singly linked lists. A node stores its original integer value,
its normalized rank (`index`) and a pointer to the next node. Operations move
or reconnect existing nodes instead of copying their values.

### Parsing

`param_parser.c` reads the optional strategy and benchmark flags before the
integer arguments. `input_parser.c` walks each argument and appends validated
values to stack `a`. `input_parser_utils.c` handles whitespace, optional signs,
digit-by-digit conversion and signed 32-bit overflow checks.

The parser can read separate arguments, quoted groups or a mixture of both
without creating a temporary split array. Duplicate values are rejected before
they are added to the stack.

### Rank preparation

The input values may be negative or very large, so the sorting strategies use
their positions in the globally sorted order instead of their raw values.

`rank_stack.c` performs the following steps:

1. Copy the values to a temporary array.
2. Sort the array with heap sort.
3. Find each node's position with binary search.
4. Store that position in the node's `index` field.

The resulting indices are in the compact range `0..n-1`. This preserves the
ordering of the original values and makes binary radix sorting possible.

### Disorder metric

Before any sorting operation is emitted, `disorder.c` counts inversion pairs.
For every pair `(i, j)` with `i < j`, the pair is a mistake when `a[i] > a[j]`.

```text
disorder = wrong_pairs / total_pairs
total_pairs = n * (n - 1) / 2
```

Sorted input has disorder `0.0`; reverse-sorted input has disorder `1.0`.
The calculation is performed before the first move so that adaptive selection
uses the original input configuration.

### Simple strategy

`sort_simple.c` repeatedly finds the minimum index in stack `a`, rotates it to
the top using the shorter direction and pushes it to `b`. Once all values have
been extracted, they are pushed back to `a`.

The minimum search and the required rotations can each inspect O(n) nodes, and
the process is repeated for O(n) values. Therefore the strategy belongs to the
O(n^2) operation class.

### Medium strategy

`sort_medium.c` divides the normalized indices into logical ranges called
chunks. A chunk is not a separate stack; it is the current index interval being
processed.

Values in the current range are pushed from `a` to `b`. Smaller values in that
range are rotated deeper into `b`, keeping larger values closer to the top.
The largest remaining index is then rotated to the top of `b` and pushed back
to `a`.

The chunk width is selected around `2 * sqrt(n)`, giving the intended
O(n * sqrt(n)) operation class.

### Complex strategy

`sort_complex.c` uses a least-significant-bit binary radix sort over the
normalized indices. For each bit position:

- a zero bit is pushed from `a` to `b`;
- a one bit is rotated inside `a`;
- all values in `b` are pushed back to `a`.

The number of bit passes is logarithmic in the number of values, and each pass
processes the stack linearly. This gives the O(n log n) operation class.

### Small inputs

For five or fewer values, `sort_small.c` is used because explicit small cases
produce fewer and more predictable operations. It moves minimum values to `b`,
solves the remaining two- or three-value case with explicit cases, and restores
the saved values to `a`.

### Adaptive strategy

`push_swap.c` selects the strategy using these thresholds:

```text
disorder < 0.20         Simple
0.20 <= disorder < 0.50 Medium
disorder >= 0.50        Complex
```

Low-disorder inputs are close to sorted, medium-disorder inputs benefit from
range grouping, and high-disorder inputs benefit from binary radix passes.

## Contributions

The project was completed by exactly two learners. `kasen` and `onaktas` made
equal contributions, reviewed the complete codebase together and both
participated in implementation, integration, testing and documentation.

### kasen

- Program control in `push_swap.c`:
  `run_parsers`, `select_method`, `run_sort`, `init_bench`, `main`.
- Option handling in `param_parser.c`:
  `param_cmp`, `method_number`, `set_method_value`, `set_method`,
  `parse_params`.
- Input parsing in `input_parser.c`:
  `already_exists`, `parse_argument`, `parse_input`.
- Number parsing in `input_parser_utils.c`:
  `is_space`, `get_sign`, `read_digits`, `skip_spaces`, `parse_number`.
- Stack lifetime helpers in `stack_utils.c`:
  `create_node`, `add_to_stack`, `clear_stack`, `stack_size`.
- Rank preparation in `rank_stack.c`:
  `sift_down`, `heap_sort`, `find_rank`, `copy_values`, `rank_stack`.

### onaktas

- Disorder and benchmark functions:
  `count_wrong_pairs`, `get_disorder`, `write_complexity`, `write_strategy`,
  `set_total`, `write_disorder`, `write_bench`.
- Formatted output functions in `ft_printf.c`:
  `ft_print_chr`, `ft_print_str`, `ft_print_num`, `format_check`,
  `ft_printf`.
- Small-input sorting functions in `sort_small.c`:
  `min_position`, `push_min_to_b`, `small_sort`.
- Three-element sorting functions in `sort_three.c`:
  `sort_three_a_first`, `sort_three_b_first`, `sort_three`.
- Other sorting functions:
  `find_min_pos`, `move_min_top`, `simple_sort`,
  `get_chunk_size`, `position_of_max`, `rotate_max_to_top`, `push_chunks`,
  `medium_sort`, `count_bits`, `radix_pass`, `complex_sort`, `is_sorted`.
- Stack operation functions:
  `push_stack`, `pa`, `pb`, `swap_stack`, `sa`, `sb`, `ss`, `rotate_stack`,
  `ra`, `rb`, `rr`, `reverse_rotate_stack`, `rra`, `rrb`, `rrr`.

## Resources and AI usage

Resources used for the project:

- The official `push_swap` subject and its mandatory requirements.
- Radix sort references for the binary-pass strategy.
- Heap data structure references for rank preparation.
- Inversion-pair references for the disorder metric.
- The platform-specific checker supplied for development validation.

AI assistance was used for the following development tasks:

- translating the subject requirements into an implementation checklist;
- discussing parsing design, whitespace handling, signs and overflow checks;
- explaining and reviewing heap sort, binary search, chunk sorting and radix
  sorting;
- reviewing edge cases such as duplicates, empty input, `INT_MIN`, `INT_MAX`
  and malformed arguments;
- proposing test cases and reviewing operation-count and disorder results;
- reviewing memory cleanup and documentation wording.

AI assistance was not used as a substitute for understanding the project.
Both contributors reviewed the implementation, understand the complete
codebase and take responsibility for the submitted work.

## Verification

The project was verified with:

- Norminette on all C source and header files;
- compilation with `-Wall -Wextra -Werror`;
- compilation with an additional `-D BUFFER_SIZE` definition;
- valid and invalid parsing cases, including duplicates, signs, quoted input,
  `INT_MIN`, `INT_MAX` and out-of-range values;
- all four strategy selectors and default adaptive behavior;
- already sorted, small, medium, 100-value and 500-value inputs;
- benchmark disorder values and operation counters;
- an operation-stream simulator confirming that `a` is sorted and `b` is
  empty after the generated operations.

Reference measurements from the project verification included 1084 operations
for a descending 100-value input and 6784 operations for a descending
500-value input, both below the mandatory subject limits.

This repository contains the mandatory `push_swap` implementation only. The
checker program and other bonus files are not included.
