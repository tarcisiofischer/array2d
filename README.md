array2d
===

Header-only implementation of a contiguous 2d array with `std::array` backend.

### Example

```C++
auto arr = array2d<int, 2, 3>{{
    1, 2, 3,
    4, 5, 6
}};
REQUIRE(arr.lines() == 2);
REQUIRE(arr.cols() == 3);
REQUIRE(arr.size() == 6);

// Element access
REQUIRE(arr[0][1] == 2);

// Fill the first line
arr[0].fill(10);

// Loop through first line only
for (auto& value : arr[0]) {
    value -= 2;
}

// Fill all array
arr.fill(10);

// Loop through all elements
for (auto& value : arr) {
    value += 2;
}
```

