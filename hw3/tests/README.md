# Время выполнения программы для различных наборов заданных данных
### test #0

real    0m0,052s
user    0m0,038s
sys     0m0,014s

### test #1

real    0m0,065s
user    0m0,053s
sys     0m0,011s

### test #2

real    0m0,061s
user    0m0,040s
sys     0m0,020s

### test #3

real    0m16,335s
user    0m16,287s
sys     0m0,020s

### test #4

real    0m0,040s
user    0m0,037s
sys     0m0,004s

### test #5

real    0m0,026s
user    0m0,021s
sys     0m0,005s

### test #6 (random)

real    0m13,948s
user    0m13,909s
sys     0m0,014s

### Сравнение

test 0 - Python в 8.66 раз медленнее C++

test 1 - Python в 16.25 раз медленнее C++

test 2 - Python в 15.25 раз медленнее C++

test 3 - Python в 18.79 раз медленнее C++

test 4 - Python в 2.65 раз быстрее C++ о_О

test 5 - Python в 4.33 раз медленнее C++

test 6 (random) - Python в 17.58 раз медленнее C++

Время работы значительно выросло во всех тестах, кроме 4 (вероятно, из-за сравнения строк по хэшам в питоне)

Размер исходных кодов сократился в 2.6 раз