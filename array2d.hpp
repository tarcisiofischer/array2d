#ifndef __LIBARRAY_2D_H
#define __LIBARRAY_2D_H

template<typename T, std::size_t LINES, std::size_t COLS>
class array2d {
public:
    using inner_array_t = std::array<T, LINES * COLS>;
    using pointer = typename inner_array_t::pointer;
    using const_pointer = typename inner_array_t::const_pointer;
    using inner_reference = typename inner_array_t::reference;
    using inner_const_reference = typename inner_array_t::const_reference;
    using size_type = typename inner_array_t::size_type;
    using iterator = typename inner_array_t::iterator;
    using const_iterator = typename inner_array_t::const_iterator;

    class _line {
    public:
        _line(inner_array_t& inner, size_type offset) : inner(inner), offset(offset) {};

        constexpr inner_reference operator[](size_type j) { return inner[offset + j]; }
        constexpr inner_const_reference operator[](size_type j) const { return inner[offset + j]; }

        constexpr inner_reference at(size_type col) {
            if (col >= COLS) {
                std::__throw_out_of_range_fmt("array2d::at: col (which is %zu) "
                                              ">= COLS (which is %zu)",
                                              col, COLS);
            }
            return (*this)[col];
        }

        constexpr inner_const_reference at(size_type col) const {
            if (col >= COLS) {
                std::__throw_out_of_range_fmt("array2d::at: col (which is %zu) "
                                              ">= COLS (which is %zu)",
                                              col, COLS);
            }
            return (*this)[col];
        }

        constexpr void fill(inner_const_reference value) { std::fill(begin(), end(), value); }

        constexpr iterator begin() noexcept { return inner.begin() + offset; };
        constexpr const_iterator begin() const noexcept { return inner.begin() + offset; };
        constexpr const_iterator cbegin() const noexcept { return inner.cbegin() + offset; };

        constexpr iterator end() noexcept { return begin() + COLS; };
        constexpr const_iterator end() const noexcept { return begin() + COLS; };
        constexpr const_iterator cend() const noexcept { return cbegin() + COLS; };

        constexpr iterator rbegin() noexcept { return inner.rbegin() - offset; };
        constexpr const_iterator rbegin() const noexcept { return inner.rbegin() - offset; };
        constexpr const_iterator crbegin() const noexcept { return inner.crbegin() - offset; };

        constexpr iterator rend() noexcept { return rbegin() - COLS; };
        constexpr const_iterator rend() const noexcept { return rbegin() - COLS; };
        constexpr const_iterator crend() const noexcept { return crbegin() - COLS; };

    private:
        inner_array_t& inner;
        size_type offset;
    };

    array2d(inner_array_t const& arr) : inner(arr) {}
    array2d() = default;

    _line operator[](size_type i) { return _line{inner, COLS * i}; }
    _line operator[](size_type i) const { return _line{inner, COLS * i}; }

    constexpr pointer data() noexcept { return inner.data(); }
    constexpr const_pointer data() const noexcept { return inner.data(); }

    constexpr _line at(size_type line) {
        if (line >= LINES) {
            std::__throw_out_of_range_fmt("array2d::at: line (which is %zu) "
                                          ">= LINES (which is %zu)",
                                          line, LINES);
        }
        return (*this)[line];
    }

    constexpr _line at(size_type line) const {
        if (line >= LINES) {
            std::__throw_out_of_range_fmt("array2d::at: line (which is %zu) "
                                          ">= LINES (which is %zu)",
                                          line, LINES);
        }
        return (*this)[line];
    }

    constexpr size_type lines() const noexcept { return LINES; }
    constexpr size_type cols() const noexcept { return COLS; }
    constexpr size_type size() const noexcept { return LINES * COLS; }
    [[nodiscard]] constexpr bool empty() const noexcept { return inner.empty(); }

    constexpr void fill(inner_const_reference value) { std::fill(begin(), end(), value); }

    constexpr iterator begin() noexcept { return inner.begin(); };
    constexpr const_iterator begin() const noexcept { return inner.begin(); };
    constexpr const_iterator cbegin() noexcept { return inner.cbegin(); };

    constexpr iterator end() noexcept { return inner.end(); };
    constexpr const_iterator end() const noexcept { return inner.end(); };
    constexpr const_iterator cend() noexcept { return inner.cend(); };

    constexpr iterator rbegin() noexcept { return inner.rbegin(); };
    constexpr const_iterator rbegin() const noexcept { return inner.rbegin(); };
    constexpr const_iterator crbegin() noexcept { return inner.crbegin(); };

    constexpr iterator rend() noexcept { return inner.rend(); };
    constexpr const_iterator rend() const noexcept { return inner.rend(); };
    constexpr const_iterator crend() noexcept { return inner.crend(); };

private:
    inner_array_t inner;
};

#endif
