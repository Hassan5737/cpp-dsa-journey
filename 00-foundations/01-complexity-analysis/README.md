# Complexity Analysis

## Table of Contents

1. Introduction
2. What Is Complexity Analysis?
3. Why Complexity Analysis Matters
4. Time Complexity
5. Space Complexity
6. Best, Average, and Worst Cases
7. Big O Notation
8. Big Omega Notation
9. Big Theta Notation
10. Common Complexity Classes
11. Rules for Analyzing Code
12. Practical Examples
13. Summary

## Introduction

Complexity analysis is one of the fundamental concepts in computer science and software engineering. It provides a systematic way to evaluate the efficiency of algorithms by measuring how their resource consumption grows as the input size increases.

Understanding complexity analysis allows developers to compare different solutions, predict scalability, and make informed decisions when designing efficient software. Rather than focusing on execution time on a specific machine, complexity analysis evaluates an algorithm based on its growth rate, making it independent of hardware and implementation details.

This chapter introduces the core concepts of complexity analysis, including time complexity, space complexity, asymptotic notation, and practical techniques for analyzing algorithms.

## What Is Complexity Analysis?

Complexity analysis is the process of evaluating how efficiently an algorithm uses computational resources as the input size grows.

The two primary resources measured are:

- **Time Complexity** – The number of operations an algorithm performs.
- **Space Complexity** – The amount of additional memory an algorithm requires.

Instead of measuring execution time in seconds, complexity analysis focuses on the growth rate of an algorithm, making the evaluation independent of hardware, programming language, and compiler optimizations.

## Why Complexity Analysis Matters

Choosing the correct algorithm is often more important than choosing a faster computer.

An algorithm that performs well on small inputs may become impractical as the input size grows. Complexity analysis helps developers evaluate scalability, compare multiple solutions, and predict how an algorithm will behave with large datasets.

Since complexity analysis focuses on growth rate rather than execution time, it provides a reliable and hardware-independent way to measure algorithm efficiency.

## Time Complexity

Time complexity describes how the number of operations performed by an algorithm grows as the input size increases.

It does not measure execution time in seconds. Instead, it measures the algorithm's growth rate, making the analysis independent of hardware, compiler optimizations, and programming languages.

For example, accessing an array element by its index always takes constant time.

```cpp
int value = arr[7];
```

**Time Complexity:** `O(1)`

Traversing an entire array requires processing every element once.

```cpp
for (int i = 0; i < n; i++)
{
    cout << arr[i];
}
```

**Time Complexity:** `O(n)`

## Space Complexity

Space complexity measures the amount of additional memory an algorithm requires while executing.

Besides execution time, memory usage is another important factor when evaluating an algorithm. Some algorithms trade additional memory for better performance, while others minimize memory usage at the cost of increased execution time.

Understanding both time and space complexity helps developers choose the most appropriate solution for a given problem.

## Best, Average, and Worst Cases

Algorithms may perform differently depending on the input.

### Best Case

The minimum amount of work required.

Example:

Finding an element at the first position during a linear search.

### Average Case

The expected amount of work for a typical input.

### Worst Case

The maximum amount of work required.

Example:

Searching for the last element (or an element that does not exist) in a linear search.

When analyzing algorithms, the worst case is commonly used because it guarantees an upper bound on the algorithm's performance.

## Big O Notation

Big O notation describes the upper bound of an algorithm's growth rate.

It represents how an algorithm performs in the worst-case scenario as the input size increases.

Big O ignores constant factors and lower-order terms, focusing only on the dominant term that determines scalability.

Examples:

- `O(2n)` → `O(n)`
- `O(5n)` → `O(n)`
- `O(n² + n)` → `O(n²)`

## Big Omega Notation

Big Omega (Ω) describes the lower bound of an algorithm.

It represents the best-case performance and indicates the minimum amount of work required by an algorithm.

## Big Theta Notation

Big Theta (Θ) describes the tight bound of an algorithm.

It is used when both the upper and lower bounds grow at the same rate, providing the most accurate asymptotic description of an algorithm.

## Common Complexity Classes

| Complexity | Description |
|------------|-------------|
| `O(1)` | Constant Time |
| `O(log n)` | Logarithmic Time |
| `O(n)` | Linear Time |
| `O(n log n)` | Linearithmic Time |
| `O(n²)` | Quadratic Time |

## Rules for Analyzing Code

- Ignore constant factors.
- Ignore lower-order terms.
- Consecutive loops add their complexities.
- Nested loops multiply their complexities.
- Loops that repeatedly multiply or divide their iterator are typically logarithmic.
- Focus on the dominant growth rate.

## Practical Examples

| Code Pattern | Complexity |
|--------------|------------|
| Array indexing | `O(1)` |
| Single loop | `O(n)` |
| Nested loops | `O(n²)` |
| Doubling loop (`i *= 2`) | `O(log n)` |
| Nested loop with logarithmic outer loop | `O(n log n)` |

## Summary

Complexity analysis provides a systematic way to evaluate algorithm efficiency independent of hardware and implementation details.

Understanding time complexity, space complexity, asymptotic notation, and common growth patterns is essential for designing scalable algorithms and making informed engineering decisions.

