# Лабораторная работа 11

Алгоритмы STL, xrange, zip

## Задача

Реализовать набор stl-совместимых алгоритмов, генератор xrange и zip. Покрыть тестами.

### Алгоритмы

- **all_of** - возвращает true, если все элементы диапазона удовлетворяют некоторому предикату. Иначе false
- **any_of** - возвращает true, если хотя бы один из элементов диапазона удовлетворяет некоторому предикату. Иначе false
- **none_of** - возвращает true, если все элементы диапазона не удовлетворяют некоторому предикату. Иначе false
- **one_of** - возвращает true, если ровно один элемент диапазона удовлетворяет некоторому предикату. Иначе false
- **is_sorted** - возвращает true, если все элементы диапазона находятся в отсортированном порядке относительно некоторого критерия
- **is_partitioned** - возвращает true, если в диапазоне есть элемент, делящий все элементы на удовлетворяющие и не удовлетворяющие - некоторому предикату. Иначе false.
- **find_not** - находит первый элемент, не равный заданному
- **find_backward** - находит первый элемент, равный заданному, с конца
- **is_palindrome** - возвращает true, если заданная последовательность является палиндромом относительно некоторого условия. Иначе false.

### xrange

В питоне есть весьма полезная функция [xrange](https://docs.python.org/2/library/functions.html#xrange). Требуется реализовать ее аналог за O(1) по памяти. Функция помогает генерировать значение из определенного диапазона с некоторым шагом.
Должно быть реализованы три. сигнатуры
- xrange(start, end)
- xrange(end)
- xrange(start, end, step)

Например:

```cpp
auto x = xrange(1.5, 5.5);
std::vector<float> v{x.begin(), x.end()}; // 1.5 2.5 3.5 4.5
```

```cpp
auto x = xrange(4);
std::vector<int> v{x.begin(), x.end()}; // 0 1 2 3
```

```cpp
// 1 3 5
for(auto i : xrange(1, 6, 2)) {
    std::cout << i <<  " ";
}
```

Без указания шага, на каждой итерации генерируется инкремент к предыдущему значению, при трех параметрах - увеличивается на указанных шаг


### zip

Так же в питоне есть стандартная [функция zip](https://docs.python.org/2/library/functions.html#zip), которую вам также надо реализовать для 2 аргументов за O(1) по памяти. Функция генерирует пары, где i-я пара состоит из i-го числа первой и второй последовательности. Если одна последовательность короче второй, то после достижения последнего элемента более короткой последовательности генерация заканчивается, Функция должна поддерживать работу с любым контейнерами поддерживающими однонаправленные итераторы.

Пример:
```c++
std::list l = {1, 2, 3, 4, 5};
std::vector v = {'a', 'b, 'c', 'd'};
/*
1 a
2 b
3 c
4 d
*/
for(auto value : zip(l, v)) {
  std::cout << value.first << " " << value.second << std::endl;
}
```


## NB
Часть из алгоритмов реализовано в stl, однако настоятельно рекомендуется придумать решение самостоятельно.

## Deadline

1. 01.05.23 0.85
2. 08.05.23 0.65
3. 15.05.23. 0.5
