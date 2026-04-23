# String Cheatsheet

## Choose Fast

- one exact pattern in one text: KMP or Z
- many substring equality checks: hashing
- many patterns in one text: Aho-Corasick
- suffix-order / distinct-substring style tasks: suffix array

## KMP

```text
pi[i] = longest proper prefix that is also a suffix for s[0..i]
```

## Z-Function

```text
z[i] = longest prefix match starting at i
```

## Hashing Checklist

- normalize substring hashes
- use double hash or strong 64-bit style hashing
- remember it is probabilistic

## Trie Checklist

- pass count
- end count
- alphabet representation
