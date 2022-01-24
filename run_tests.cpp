#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <array2d.hpp>

TEST_CASE("empty array2d") {
    auto arr = array2d<int, 0, 0>{};
    REQUIRE(arr.empty());
}

TEST_CASE("array2d of ints") {
    auto arr = array2d<int, 2, 3>{};
    REQUIRE(arr.lines() == 2);
    REQUIRE(arr.cols() == 3);
    REQUIRE(arr.size() == 6);

    arr[0][0] = 1; arr[0][1] = 2; arr[0][2] = 3;
    arr[1][0] = 4; arr[1][1] = 5; arr[1][2] = 6;
    REQUIRE(!arr.empty());

    REQUIRE(arr[0][0] == 1);
    REQUIRE(arr[1][1] == 5);

    arr.fill(12);
    for (auto const& v : arr) {
        REQUIRE(v == 12);
    }
    for (auto& v : arr[0]) {
        v = 7;
    }
    REQUIRE(arr[0][0] == 7);
    REQUIRE(arr[0][1] == 7);
    REQUIRE(arr[0][2] == 7);
    REQUIRE(arr[1][0] == 12);
    REQUIRE(arr[1][1] == 12);
    REQUIRE(arr[1][2] == 12);

    REQUIRE_THROWS_AS(arr.at(9), std::out_of_range);
    REQUIRE_THROWS_AS(arr[0].at(9), std::out_of_range);
}

struct some_struct {
    int a;
    float b;
};

TEST_CASE("array2d of struct") {
    auto arr = array2d<some_struct, 2, 2>{};
    REQUIRE(arr.lines() == 2);
    REQUIRE(arr.cols() == 2);
    REQUIRE(arr.size() == 4);

    arr[0][0] = {1, 2.1}; arr[0][1] = {2, 3.2};
    arr[1][0] = {3, 4.3}; arr[1][1] = {4, 4.5};
    REQUIRE(!arr.empty());

    REQUIRE(arr[0][0].a == 1);
    REQUIRE(arr[0][0].b == 2.1f);

    arr.fill({7, 8.8});
    for (auto const& v : arr) {
        REQUIRE(v.a == 7);
        REQUIRE(v.b == 8.8f);
    }
    for (auto& v : arr[0]) {
        v = {5, 1.2};
    }
    REQUIRE(arr[0][0].a == 5);
    REQUIRE(arr[0][1].a == 5);
}
