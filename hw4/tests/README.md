# Время выполнения программы для различных наборов заданных данных
### test #0

real    0m0,003s
user    0m0,002s
sys     0m0,000s

### test #1

real    0m0,001s
user    0m0,001s
sys     0m0,000s

### test #2

real    0m0,001s
user    0m0,001s
sys     0m0,000s

### test #3

real    0m0,506s
user    0m0,499s
sys     0m0,007s

### test #4

real    0m0,030s
user    0m0,030s
sys     0m0,000s

### test #5

real    0m0,003s
user    0m0,002s
sys     0m0,000s

### test #6 (random)

real    0m0,518s
user    0m0,518s
sys     0m0,000s

Тест\Язык               | C     | C++   | Python| Nasm + C  
---                     | ---   | ---   | ---   | ---   
#0                      |0.002  |0.006  |0.052  |0.003
#1                      |0.001  |0.004  |0.065  |0.001
#2                      |0.001  |0.004  |0.061  |0.001
#3                      |0.969  |0.869  |16.335 |0.506
#4                      |0.069  |0.106  |0.040  |0.030
#5                      |0.004  |0.006  |0.026  |0.003
#6 (random)             |1.045  |0.793  |13.948 |0.518
Размер исходных кодов   |9.3КБ  |12.4КБ |4.8КБ  |11КБ

Как видно, скорость работы с использованием ассемблерных функций оказалась выше чем у предыдущих реализаций
