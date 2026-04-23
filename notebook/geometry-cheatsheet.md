# Geometry Cheatsheet

## Core Primitives

- point subtraction
- dot product
- cross product
- orientation sign

## Orientation

```text
cross(b - a, c - a) > 0  => counterclockwise
cross(b - a, c - a) < 0  => clockwise
cross(b - a, c - a) = 0  => collinear
```

## Safety

- prefer integers when possible
- use `__int128` for large cross products
- define whether boundary counts as inside

## Convex Hull

- sort points
- build lower hull
- build upper hull
- choose collinear policy once and keep it consistent
