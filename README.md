# push_swap

## Goal

In this project the goal was to create a program that takes string of ints as an argument and sorts them with as little operations as possible. You have to use 2 stacks called A and B. The numbers start in the A stack and need to end sorted in the A stack. The program only prints what operations it used. The following operations were allowed:

```
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time.
```

## Algorithm

This is a pretty straight-forward algorithm. 

In general, you will be pushing almost all numbers from stack `A` to `B` once and then back to `A`

The idea is to sort the numbers into `B` with the smallest numbers in the centre, and then placing the next partition of n smallest numbers on the bottom and top of the stack.

Visualization of `B` stack after everything is moved into `B` (https://github.com/o-reo/push_swap_visualizer)

![txt](Bstack.png)

### Step 1: Moving numbers from `A` to `B`

How it works is by taking partitions from `A` and moving them to `B`. The partition will always have the next n smallest numbers from stack `A`.

Here's how to determine the partition size:
- Case 1: A.size < 120 numbers
     Partition size is half of the number count in stack `A`

- Case 2: A.size > 120 numbers
    Partition size is 60

#### Step 1.2
After getting the partition size, you rotate through A until you find a number from that partition. Push to `B`.

After pushing to `B`, you need to check if the number you pushed is from the smaller or bigger half of it's own partition or bigger.

If the number is from the smaller half, you rotate it to the bottom of `B`.

If the number is from the bigger half it stays on top of `B`. Also, if the 2nd topmost number in `B` is bigger than the current top, you can do swap.

Repeat step 1.2 until all numbers of the partition are in `B`.

Repeat step 1 until the `A` stack has 3 or less numbers left.

Sort the last 2 or 3 numbers in `A`.

### Step 2: Moving the numbers back from `B` to `A`

The moving is done by finding biggest numbers in `B` and moving them the shortest way back to `A`.

First you find the position of biggest and 2nd biggest numbers in `B`.

Calculate how many moves it would take to move them back to `A`.

If the biggest number requires less or equal moves: 
- Rotate it the shortest way to top of `B`
- Push to `A`

If the 2nd biggest requires less moves:
- Rotate it the shortest way to top of `B`
- Push to `A`
- Rotate the biggest number shortest way to top of `B`
- Push to `A`
- Swap `A`

Repeat step 2 until all the numbers are in `A`.

Good job 👍. You have sorted the stack.

## Optimization for step 2

To optimize the moving of the numbers back to `B` efficiently we are gonna use `A` stacks bottom as temporary storage.

When looking for the next biggest number in `B` and it is not the topmost number in the stack, we can then do the following.

Check if storage is empty OR if the top number is bigger than the last number placed at the bottom of `A`:
    - Push to `A`
    - Rotate `A`

Then everytime we are looking for the biggest or the second biggest in `B` we have to check if they are at the bottom of `A`.

If the biggest is at the bottom of `A` we can just reverse rotate `A` and if it is the second biggest we can just move the biggest to `A` and then reverse rotate `A`.

And if `B` is empty check that the storage is empty. If not just reverse rotate all numbers from storage.