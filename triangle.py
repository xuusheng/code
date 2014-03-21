def pascals_triangle(n):
    if n == 0:
        return [[1]]
    prev_triangle = pascals_triangle(n-1)
    prev_row = prev_triangle[n-1]
    this_row = map(sum, zip([0] + prev_row, prev_row + [0]))
    return prev_triangle + [this_row]
return pascals_triangle(n)

print pascals_triangle(10)
