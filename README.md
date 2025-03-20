# Elementary Cellular Automaton

This is a project associated with a Algorithms and Data Structures I pratical assignment. This is a redone version in Go, the original was in C++. It has been done to get a first look into Go and it's syntax and way thing are structured.

# Overview

Elementary Cellular Automaton are part of the simplest class of one-dimensional cellular automata. Each cell is in one of two states, dead or alive, we may call dead 0 and alive 1. Each row of the automaton, called a generation, is composed of some number of cells. The next generation is _evolves_ based on the previous generation. The first generation is, usually, a row of dead cells with a single alive cell in the middle. The way the generations evolve is given through a number called _rule_, it is a number between $`0`$ and $`255`$, i.e, a 8-bit number.

The state of the $`n`$-th cell in the $`m`$-th generation is decided, excluding edge-cases, by its three neighbors from the previous generation, that is, decided by the state of the cells $`n - 1`$, $`n`$, $`n + 1`$ from the $`m - 1`$-th generation. From that, take the number $`4 \cdot G_{m - 1, n + 1} + 2 \cdot G_{m - 1, n} + G_{m - 1, n + 1}`$ as a position, this is a three bit number, enough to address 8 positions. Now, get the rule's binary representation and look to whether, at that position, the bit is 1 or 0, the cell $`G_{m, n}`$ is set to the value of this bit.

# Example

## Rule 90

The binary representation of $`90`$ is $`01011010_2`$, let's have a default first generation. For edge-cases, we're gonna wrap around the other side. Dead is represented as white (▀) and alive as black ( ).

```
▀▀▀▀▀▀▀▀▀▀▀ ▀▀▀▀▀▀▀▀▀▀▀
```

Given that, we see that most places all neighbors as $`0`$'s, an the $`0`$-th bit of $`90`$ is $`0`$. So, at those places, the cells evolve to $`0`$. The middle piece is more interesting, we have the top neighbor configurations (▀▀ ), (▀ ▀), and ( ▀▀), which respectively evaluate to the positions $`1`$, $`2`$ and $`4`$, in $`90`$, those bit are, respectively, $`1`$, $`0`$, and $`1`$. So the next generation, along with the last, will look:

```
██████████▀▄▀██████████
```

Now, for the next generation, the top neighbor configurations are (▀▀▀), (▀▀ ), (▀ ▀), ( ▀ ), and ( ▀▀), those correspond respectively to the bits $`0`$, $`1`$, $`0`$, $`0`$, and $`1`$, this means:

```
██████████▀▄▀██████████
▀▀▀▀▀▀▀▀▀ ▀▀▀ ▀▀▀▀▀▀▀▀▀
```

Doing this process more times, you'll arrive at:

```
██████████▀▄▀██████████
████████▀▄▀█▀▄▀████████
██████▀▄▀█████▀▄▀██████
████▀▄▀█▀▄▀█▀▄▀█▀▄▀████
██▀▄▀█████████████▀▄▀██
▀▄▀█▀▄▀█████████▀▄▀█▀▄▀
```

# References

- https://mathworld.wolfram.com/ElementaryCellularAutomaton.html