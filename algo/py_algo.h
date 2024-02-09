#ifndef PY_ALGO_H
#define PY_ALGO_H

#include <memory>
#include <iterator>
#include <tuple>

namespace py_algo {
#if __cplusplus < 201703L

    template<typename InputIt, typename UnaryPredicate>
    bool all_of(InputIt first, InputIt last, UnaryPredicate p) {
        for (; first != last; ++first) {
            if (!p(*first))
                return false;
        }

        return true;
    }

#else

    /**
     * Checks that all elements fit the condition
     *
     * @tparam InputIt Forward iterator
     * @tparam UnaryPredicate Type of predicator
     * @param first first input iterator
     * @param last second input iterator
     * @param p predicator
     * @return bool value
     */
    template<
        typename InputIt,
        typename = std::enable_if_t<std::is_base_of_v<std::input_iterator_tag,
            typename std::iterator_traits<InputIt>::iterator_category>>,
        typename UnaryPredicate>
    constexpr bool all_of(InputIt first, InputIt last, UnaryPredicate p) {
        for (; first != last; ++first) {
            if (!p(*first))
                return false;
        }

        return true;
    }

#endif

#if __cplusplus < 201703L

    template<typename InputIt, typename UnaryPredicate>
    bool any_of(InputIt first, InputIt last, UnaryPredicate p) {
        for (; first != last; ++first) {
            if (p(*first))
                return true;
        }

        return false;
    }

#else

    template<
        typename InputIt,
        typename = std::enable_if_t<std::is_base_of_v<std::input_iterator_tag,
            typename std::iterator_traits<InputIt>::iterator_category>>,
        typename UnaryPredicate>
    constexpr bool any_of(InputIt first, InputIt last, UnaryPredicate p) {
        for (; first != last; ++first) {
            if (p(*first))
                return true;
        }

        return false;
    }

#endif

#if __cplusplus < 201703L

    template<typename InputIt, typename UnaryPredicate>
    bool none_of(InputIt first, InputIt last, UnaryPredicate p) {
        for (; first != last; ++first) {
            if (p(*first))
                return false;
        }

        return true;
    }

#else

    template<
        typename InputIt,
        typename = std::enable_if_t<std::is_base_of_v<std::input_iterator_tag,
            typename std::iterator_traits<InputIt>::iterator_category>>,
        typename UnaryPredicate>
    constexpr bool none_of(InputIt first, InputIt last, UnaryPredicate p) {
        for (; first != last; ++first) {
            if (p(*first))
                return false;
        }

        return true;
    }

#endif

#if __cplusplus < 201703L

    template<typename InputIt, typename UnaryPredicate>
    bool one_of(InputIt first, InputIt last, UnaryPredicate p) {
        bool one_found = false;
        for (; first != last; ++first) {
            if (p(*first)) {
                if (one_found)
                    return false;
                else
                    one_found = true;
            }
        }

        return one_found;
    }

#else

    template<
        typename InputIt,
        typename = std::enable_if_t<std::is_base_of_v<std::input_iterator_tag,
            typename std::iterator_traits<InputIt>::iterator_category>>,
        typename UnaryPredicate>
    constexpr bool one_of(InputIt first, InputIt last, UnaryPredicate p) {
        bool one_found = false;
        for (; first != last; ++first) {
            if (p(*first)) {
                if (one_found)
                    return false;
                else
                    one_found = true;
            }
        }

        return one_found;
    }

#endif

#if __cplusplus < 201703L

    template<typename ForwardIt>
    bool is_sorted(ForwardIt first, ForwardIt last) {
        if (first == last)
            return true;

        for (ForwardIt second = first + 1; second != last; second++, first++) {
            if (*second < *first)
                return false;
        }

        return true;
    }

#else

    template<
        typename ForwardIt,
        typename = std::enable_if_t<std::is_base_of_v<std::forward_iterator_tag,
            typename std::iterator_traits<ForwardIt>::iterator_category>>>
    constexpr bool is_sorted(ForwardIt first, ForwardIt last) {
        if (first == last)
            return true;

        for (auto second = first + 1; second != last; second++, first++) {
            if (*second < *first)
                return false;
        }

        return true;
    }

#endif

#if __cplusplus < 201703L

    template<typename ForwardIt, typename Compare>
    bool is_sorted(ForwardIt first, ForwardIt last, Compare comp) {
        if (first == last)
            return true;

        for (ForwardIt second = first + 1; second != last; second++, first++) {
            if (comp(*second, *first))
                return false;
        }

        return true;
    }

#else

    template<
        typename ForwardIt,
        typename = std::enable_if_t<std::is_base_of_v<std::forward_iterator_tag,
            typename std::iterator_traits<ForwardIt>::iterator_category>>,
        typename Compare>
    constexpr bool is_sorted(ForwardIt first, ForwardIt last, Compare comp) {
        if (first == last)
            return true;

        for (auto second = first + 1; second != last; second++, first++) {
            if (comp(*second, *first))
                return false;
        }

        return true;
    }

#endif

#if __cplusplus < 201703L

    template<typename ForwardIt, typename UnaryPredicate>
    bool is_partitioned(ForwardIt first, ForwardIt last, UnaryPredicate p) {
        for (; first != last; first++) {
            if (!p(*first))
                break;
        }
        for (; first != last; first++) {
            if (p(*first))
                return false;
        }

        return true;
    }

#else

    template<
        typename ForwardIt,
        typename = std::enable_if_t<std::is_base_of_v<std::forward_iterator_tag,
            typename std::iterator_traits<ForwardIt>::iterator_category>>,
        typename UnaryPredicate>
    constexpr bool is_partitioned(ForwardIt first, ForwardIt last, UnaryPredicate p) {
        for (; first != last; first++) {
            if (!p(*first))
                break;
        }
        for (; first != last; first++) {
            if (p(*first))
                return false;
        }

        return true;
    }

#endif

#if __cplusplus < 201703L

    template<typename InputIt, typename T>
    InputIt find_not(InputIt first, InputIt last, const T& x) {
        for (; first != last; first++) {
            if (*first != x)
                return first;
        }

        return first;
    }

#else

    template<
        typename InputIt,
        typename = std::enable_if_t<std::is_base_of_v<std::input_iterator_tag,
            typename std::iterator_traits<InputIt>::iterator_category>>,
        typename T>
    constexpr InputIt find_not(InputIt first, InputIt last, const T& x) {
        for (; first != last; first++) {
            if (*first != x)
                return first;
        }

        return first;
    }

#endif

#if __cplusplus < 201703L

    template<typename BiDirIt, typename T>
    BiDirIt find_backward(BiDirIt first, BiDirIt last, const T& x) {
        while (last-- != first) {
            if (*last == x)
                return last;
        }

        return last;
    }

#else

    /**
     * Finds first element from end that is equal to some value
     *
     * @tparam InputIt Bidirectional iterator
     * @tparam T Type of comparable variable
     * @param first first input iterator
     * @param last second input iterator
     * @param x comparable variable
     * @return Iterator
     */
    template<
        typename BiDirIt,
        typename = std::enable_if_t<std::is_base_of_v<std::bidirectional_iterator_tag,
            typename std::iterator_traits<BiDirIt>::iterator_category>>,
        typename T>
    constexpr BiDirIt find_backward(BiDirIt first, BiDirIt last, const T& x) {
        auto saved_last = last;
        while (last-- != first) {
            if (*last == x)
                return last;
        }

        return saved_last;
    }

#endif

#if __cplusplus < 201703L

    template<typename BiDirIt>
    bool is_palindrome(BiDirIt first, BiDirIt last) {
        if (first == last)
            return true;

        while (first < --last) {
            if (*first != *last)
                return false;
            first++;
        }

        return true;
    }

#else

    template<
        typename BiDirIt,
        typename = std::enable_if_t<std::is_base_of_v<std::bidirectional_iterator_tag,
            typename std::iterator_traits<BiDirIt>::iterator_category>>>
    constexpr bool is_palindrome(BiDirIt first, BiDirIt last) {
        if (first == last)
            return true;

        while (first < --last) {
            if (*first != *last)
                return false;
            first++;
        }

        return true;
    }

#endif


#if __cplusplus >= 201103L

    // Declaring templates

    template<typename T>
    class xrange;

    template<typename T>
    class xrange_iterator;

    template<typename T>
    bool operator==(const xrange_iterator<T>& _l, const xrange_iterator<T>& _r);

    template<typename T>
    bool operator!=(const xrange_iterator<T>& _l, const xrange_iterator<T>& _r);

    template<typename T>
    bool operator<(const xrange_iterator<T>& _l, const xrange_iterator<T>& _r);

    template<typename T>
    bool operator>(const xrange_iterator<T>& _l, const xrange_iterator<T>& _r);

    template<typename T>
    bool operator<=(const xrange_iterator<T>& _l, const xrange_iterator<T>& _r);

    template<typename T>
    bool operator>=(const xrange_iterator<T>& _l, const xrange_iterator<T>& _r);

    // Implementation

    template<typename T>
    class xrange_iterator {
    public:
        typedef T value_type;
        typedef value_type* pointer;
        typedef typename std::iterator_traits<pointer>::reference reference;
        [[maybe_unused]] typedef typename std::iterator_traits<pointer>::difference_type difference_type;
        typedef const xrange<value_type>* range_const_pointer;
        [[maybe_unused]] typedef std::input_iterator_tag iterator_category;

    private:
        value_type stored_value;
        range_const_pointer stored_xrange;

    public:
        explicit xrange_iterator() noexcept
            : stored_value(), stored_xrange() {}

        xrange_iterator(const xrange_iterator& _iter) noexcept
            : stored_value(_iter.stored_value), stored_xrange(_iter.stored_xrange) {}

        xrange_iterator& operator=(const xrange_iterator& _iter) noexcept {
            stored_value = _iter.stored_value;
            stored_xrange = _iter.stored_xrange;

            return *this;
        }

        explicit xrange_iterator(value_type _value, range_const_pointer _xrange) noexcept {
            stored_value = _value;
            stored_xrange = _xrange;
        }

        reference operator*() noexcept {
            return stored_value;
        }

        pointer operator->() noexcept {
            return &stored_value;
        }

        xrange_iterator& operator++() noexcept {
            if (stored_xrange->has_step)
                if (stored_xrange->finish - stored_value >= stored_xrange->step)
                    stored_value += stored_xrange->step;
                else
                    stored_value = stored_xrange->finish;
            else if (stored_value < stored_xrange->finish)
                stored_value++;

            return *this;
        }

        xrange_iterator operator++(int) noexcept {
            auto old_value = stored_value;
            if (stored_xrange->has_step)
                if (stored_xrange->finish - stored_value >= stored_xrange->step)
                    stored_value += stored_xrange->step;
                else
                    stored_value = stored_xrange->finish;
            else if (stored_value < stored_xrange->finish)
                stored_value++;

            return xrange_iterator(old_value, stored_xrange);
        }

        friend bool operator== <value_type>(const xrange_iterator<value_type>& _l, const xrange_iterator<value_type>& _r);

        friend bool operator!= <value_type>(const xrange_iterator<value_type>& _l, const xrange_iterator<value_type>& _r);

        friend bool operator< <value_type>(const xrange_iterator<value_type>& _l, const xrange_iterator<value_type>& _r);

        friend bool operator> <value_type>(const xrange_iterator<value_type>& _l, const xrange_iterator<value_type>& _r);

        friend bool operator<= <value_type>(const xrange_iterator<value_type>& _l, const xrange_iterator<value_type>& _r);

        friend bool operator>= <value_type>(const xrange_iterator<value_type>& _l, const xrange_iterator<value_type>& _r);
    };

    template<typename T>
    class xrange {
    public:
        typedef T value_type;
        typedef const value_type const_value_type;
        typedef xrange_iterator<value_type> iterator;
        typedef xrange_iterator<const_value_type> const_iterator;
    private:
        const_value_type start;
        const_value_type finish;
        const_value_type step;
        bool has_step{false};
    public:
        explicit xrange(const_value_type& _end)
            : start(), finish(_end), step() {}

        explicit xrange(const_value_type& start, const_value_type& _end)
            : start(start), finish(_end), step() {}

        explicit xrange(const_value_type& start, const_value_type& _end, const_value_type& step)
            : start(start), finish(_end), step(step), has_step(true) {}

        iterator begin() noexcept {
            return iterator(start, this);
        }

        const_iterator begin() const noexcept {
            return const_iterator(start, this);
        }

        [[maybe_unused]] const_iterator cbegin() const noexcept {
            return const_iterator(start, this);
        }

        iterator end() noexcept {
            return iterator(finish, this);
        }

        const_iterator end() const noexcept {
            return const_iterator(finish, this);
        }

        [[maybe_unused]] const_iterator cend() const noexcept {
            return const_iterator(finish, this);
        }

        friend class xrange_iterator<value_type>;

        friend class xrange_iterator<const_value_type>;

        friend bool operator== <value_type>(const xrange_iterator<value_type>& _l, const xrange_iterator<value_type>& _r);

        friend bool operator!= <value_type>(const xrange_iterator<value_type>& _l, const xrange_iterator<value_type>& _r);

        friend bool operator< <value_type>(const xrange_iterator<value_type>& _l, const xrange_iterator<value_type>& _r);

        friend bool operator> <value_type>(const xrange_iterator<value_type>& _l, const xrange_iterator<value_type>& _r);

        friend bool operator<= <value_type>(const xrange_iterator<value_type>& _l, const xrange_iterator<value_type>& _r);

        friend bool operator>= <value_type>(const xrange_iterator<value_type>& _l, const xrange_iterator<value_type>& _r);
    };

    template<typename T>
    bool operator==(const xrange_iterator<T>& _l, const xrange_iterator<T>& _r) {
        if (_l.stored_value >= _l.stored_xrange->finish && _r.stored_value >= _r.stored_xrange->finish)
            return true;

        return _l.stored_value == _r.stored_value;
    }

    template<typename T>
    bool operator!=(const xrange_iterator<T>& _l, const xrange_iterator<T>& _r) {
        if (_l.stored_value >= _l.stored_xrange->finish && _r.stored_value >= _r.stored_xrange->finish)
            return false;

        return _l.stored_value != _r.stored_value;
    }

    template<typename T>
    bool operator<(const xrange_iterator<T>& _l, const xrange_iterator<T>& _r) {
        return _l.stored_value < _r.stored_value;
    }

    template<typename T>
    bool operator>(const xrange_iterator<T>& _l, const xrange_iterator<T>& _r) {
        return _l.stored_value > _r.stored_value;
    }

    template<typename T>
    bool operator<=(const xrange_iterator<T>& _l, const xrange_iterator<T>& _r) {
        if (_l.stored_value >= _l.stored_xrange->finish && _r.stored_value >= _r.stored_xrange->finish)
            return true;

        return _l.stored_value <= _r.stored_value;
    }

    template<typename T>
    bool operator>=(const xrange_iterator<T>& _l, const xrange_iterator<T>& _r) {
        if (_l.stored_value >= _l.stored_xrange->finish && _r.stored_value >= _r.stored_xrange->finish)
            return true;

        return _l.stored_value >= _r.stored_value;
    }

#endif

#if __cplusplus >= 201103L

    // Declaring templates

    template<class Container1, class Container2>
    class zip;

    template<class Container1, class Container2>
    class zip_iterator;

    template<typename T, typename U>
    bool operator==(const zip_iterator<T, U>& _l, const zip_iterator<T, U>& _r);

    template<typename T, typename U>
    bool operator!=(const zip_iterator<T, U>& _l, const zip_iterator<T, U>& _r);

    template<typename T, typename U>
    bool operator<(const zip_iterator<T, U>& _l, const zip_iterator<T, U>& _r);

    template<typename T, typename U>
    bool operator>(const zip_iterator<T, U>& _l, const zip_iterator<T, U>& _r);

    template<typename T, typename U>
    bool operator<=(const zip_iterator<T, U>& _l, const zip_iterator<T, U>& _r);

    template<typename T, typename U>
    bool operator>=(const zip_iterator<T, U>& _l, const zip_iterator<T, U>& _r);

    // Implementation

    template<class Container1, class Container2>
    class zip_iterator {
    public:
        typedef Container1 first_container;
        typedef Container2 second_container;
        typedef typename first_container::const_iterator iterator_first_ctr;
        typedef typename second_container::const_iterator iterator_second_ctr;
        typedef const typename first_container::value_type value_type_first_ctr;
        typedef const typename second_container::value_type value_type_second_ctr;
        typedef std::pair<value_type_first_ctr, value_type_second_ctr> value_type;
        typedef value_type* pointer;
        [[maybe_unused]] typedef typename std::iterator_traits<pointer>::difference_type difference_type;
        [[maybe_unused]] typedef std::input_iterator_tag iterator_category;

    private:
        const first_container* container1;
        const second_container* container2;
        iterator_first_ctr iter1;
        iterator_second_ctr iter2;

    public:
        explicit zip_iterator() noexcept
            : container1(), container2(), iter1(), iter2() {}

        zip_iterator(const zip_iterator& _iter) noexcept
            : container1(_iter.container1), container2(_iter.container2), iter1(_iter.iter1), iter2(_iter.iter2) {}

        zip_iterator& operator=(const zip_iterator& _iter) noexcept {
            if (&_iter == this)
                return *this;
            container1 = _iter.container1;
            container2 = _iter.container2;
            iter1 = _iter.iter1;
            iter2 = _iter.iter2;

            return *this;
        }

        explicit zip_iterator(const first_container& _container1,
                              const second_container& _container2,
                              iterator_first_ctr _iter1, iterator_second_ctr _iter2) noexcept {

            container1 = &_container1;
            container2 = &_container2;
            iter1 = _iter1;
            iter2 = _iter2;
        }

        value_type operator*() noexcept {
            return std::make_pair(*iter1, *iter2);
        }

        zip_iterator& operator++() noexcept {
            if (iter1 < container1->end() &&
                iter2 < container2->end()) {
                iter1++;
                iter2++;
            }

            return *this;
        }

        zip_iterator operator++(int) noexcept {
            auto old_iter1 = iter1;
            auto old_iter2 = iter2;
            if (iter1 < container1->end() &&
                iter2 < container2->end()) {
                iter1++;
                iter2++;
            }

            return zip_iterator(*container1, *container2, old_iter1, old_iter2);
        }

        friend bool operator== <first_container, second_container>(const zip_iterator<first_container, second_container>& _l,
                                                                   const zip_iterator<first_container, second_container>& _r);

        friend bool operator!= <first_container, second_container>(const zip_iterator<first_container, second_container>& _l,
                                                                   const zip_iterator<first_container, second_container>& _r);

        friend bool operator< <first_container, second_container>(const zip_iterator<first_container, second_container>& _l,
                                                                   const zip_iterator<first_container, second_container>& _r);

        friend bool operator> <first_container, second_container>(const zip_iterator<first_container, second_container>& _l,
                                                                   const zip_iterator<first_container, second_container>& _r);

        friend bool operator<= <first_container, second_container>(const zip_iterator<first_container, second_container>& _l,
                                                                   const zip_iterator<first_container, second_container>& _r);

        friend bool operator>= <first_container, second_container>(const zip_iterator<first_container, second_container>& _l,
                                                                   const zip_iterator<first_container, second_container>& _r);
    };

    template<class Container1, class Container2>
    class zip {
    public:
        typedef Container1 first_container;
        typedef Container2 second_container;
        typedef typename first_container::value_type value_type_first_ctr;
        typedef typename second_container::value_type value_type_second_ctr;
        typedef std::pair<value_type_first_ctr, value_type_second_ctr> value_type;
        [[maybe_unused]] typedef const value_type const_value_type;
        typedef zip_iterator<first_container, second_container> iterator;
    private:
        const first_container* container1;
        const second_container* container2;
    public:
        explicit zip(const first_container& _container1, const second_container& _container2)
            : container1(&_container1), container2(&_container2) {}

        iterator begin() noexcept {
            return iterator(*container1, *container2, container1->begin(), container2->begin());
        }

        iterator end() noexcept {
            return iterator(*container1, *container2, container1->end(), container2->end());
        }

        friend class zip_iterator<first_container, second_container>;

        friend bool operator== <first_container, second_container>(const zip_iterator<first_container, second_container>& _l,
                                                                   const zip_iterator<first_container, second_container>& _r);

        friend bool operator!= <first_container, second_container>(const zip_iterator<first_container, second_container>& _l,
                                                                   const zip_iterator<first_container, second_container>& _r);

        friend bool operator< <first_container, second_container>(const zip_iterator<first_container, second_container>& _l,
                                                                  const zip_iterator<first_container, second_container>& _r);

        friend bool operator> <first_container, second_container>(const zip_iterator<first_container, second_container>& _l,
                                                                  const zip_iterator<first_container, second_container>& _r);

        friend bool operator<= <first_container, second_container>(const zip_iterator<first_container, second_container>& _l,
                                                                   const zip_iterator<first_container, second_container>& _r);

        friend bool operator>= <first_container, second_container>(const zip_iterator<first_container, second_container>& _l,
                                                                   const zip_iterator<first_container, second_container>& _r);
    };

    template<typename T, typename U>
    bool operator==(const zip_iterator<T, U>& _l, const zip_iterator<T, U>& _r) {
        if ((_l.iter1 == _l.container1->end() ||
             _l.iter2 == _l.container2->end()) &&
            (_r.iter1 == _r.container1->end() ||
             _l.iter2 == _l.container2->end()))
            return true;

        return _l.iter1 == _r.iter1;
    }

    template<typename T, typename U>
    bool operator!=(const zip_iterator<T, U>& _l, const zip_iterator<T, U>& _r) {
        if ((_l.iter1 == _l.container1->end() ||
             _l.iter2 == _l.container2->end()) &&
            (_r.iter1 == _r.container1->end() ||
             _l.iter2 == _l.container2->end()))
            return false;

        return _l.iter1 != _r.iter1;
    }

    template<typename T, typename U>
    bool operator<(const zip_iterator<T, U>& _l, const zip_iterator<T, U>& _r) {
        return _l.iter1 < _r.iter1;
    }

    template<typename T, typename U>
    bool operator>(const zip_iterator<T, U>& _l, const zip_iterator<T, U>& _r) {
        return _l.iter1 > _r.iter1;
    }

    template<typename T, typename U>
    bool operator<=(const zip_iterator<T, U>& _l, const zip_iterator<T, U>& _r) {
        if ((_l.iter1 == _l.container1->end() ||
             _l.iter2 == _l.container2->end()) &&
            (_r.iter1 == _r.container1->end() ||
             _l.iter2 == _l.container2->end()))
            return true;

        return _l.iter1 <= _r.iter1;
    }

    template<typename T, typename U>
    bool operator>=(const zip_iterator<T, U>& _l, const zip_iterator<T, U>& _r) {
        if ((_l.iter1 == _l.container1->end() ||
             _l.iter2 == _l.container2->end()) &&
            (_r.iter1 == _r.container1->end() ||
             _l.iter2 == _l.container2->end()))
            return true;

        return _l.iter1 >= _r.iter1;
    }

#endif

} // namespace py_algo

#endif //PY_ALGO_H
