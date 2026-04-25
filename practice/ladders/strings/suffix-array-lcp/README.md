# Suffix Array And LCP Ladder

## Who This Is For

Use this ladder when you already know hashing/KMP-level string tools and need a heavier exact structure for suffix order, repeated substrings, and lexicographic queries.

This lane is still thin inside the repo, so the intended loop is:

- hot sheet for retrieval
- one flagship repo note
- topic page when you need the full doubling/Kasai refresher

## Warm-Up

- build suffix array with doubling
- Kasai LCP

## Core

- distinct substrings
- lexicographic suffix problems

## Retrieval Layer

- exact quick sheet -> [Suffix Array / LCP hot sheet](../../../../notebook/suffix-array-lcp-hot-sheet.md)
- suffix-array plus Kasai starter -> [suffix-array.cpp](https://github.com/mtuann/competitive-programming-cpp/blob/main/templates/strings/suffix-array.cpp)
- flagship repo note -> [Repeating Substring](repeatingsubstring.md)

## Exit Criteria

You are ready to move on when you can:

- explain what `sa`, `rank`, and `lcp` each mean
- build suffix array and LCP from memory with only light reference
- derive the distinct-substring formula from `lcp`
- recognize when suffix array is the right exact static-string tool

## External Practice

- [CP-Algorithms - Suffix Array](https://cp-algorithms.com/string/suffix-array.html)
- [USACO Guide - Suffix Arrays](https://usaco.guide/adv/suffix-array?lang=cpp)

## Tutorial Link

- [Suffix Array And LCP](../../../../topics/strings/suffix-array-lcp/README.md)
