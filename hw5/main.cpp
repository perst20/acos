#include <iostream>
#include <thread>
#include <cstring>
#include <vector>
#include <future>
#include <random>
#include <algorithm>
#include <chrono>
#include <sstream>

using namespace std::chrono_literals;

// Модель студентки
class Woman {
private:
    std::atomic<int> counter_ = 0;
    bool is_rand_calculated_ = false;
    std::mutex is_rand_calc_mutex_;
    int ans_ = -1;

    // Вычисление наиболее заманчивого предложения
    int rand() {
        std::lock_guard<std::mutex> lck(is_rand_calc_mutex_);
        if (!is_rand_calculated_) {
            is_rand_calculated_ = true;
            std::random_device rnd;
            std::mt19937 rng(rnd());
            std::uniform_int_distribution<int> dist(0, counter_ - 1);
            return ans_ = dist(rng);
        } else {
            return ans_;
        }
    }

public:
    // Метод, имитирующий отправку валентинки и ожидание
    bool tryValentine() {
        auto temp = counter_++;
        std::stringstream str;
        str << "Student number " << temp << " has sent valentine\n";
        std::cout << str.str();
        std::this_thread::sleep_for(5s);
        return (rand() == temp);
    }
};

// Помощь
void helpMessage() {
    std::cout << "Usage:\n"
                 "  a.out <number of clients>\n";
}

// Неправильный запуск программы
void argumentErrorMessage() {
    std::cout << "Invalid argument!\n";
    helpMessage();
}

int main(int argc, char **argv) {
    if (argc != 2) {
        argumentErrorMessage();
        return 1;
    }
    if (strcmp("--help", argv[1]) == 0) {
        helpMessage();
        return 0;
    }
    int n = std::stoi(argv[1]);
    if (n < 1) {
        argumentErrorMessage();
        return 1;
    }
    std::cout << "Wait for 5 seconds...\n";
    Woman woman;
    std::vector<std::future<bool>> clients;
    clients.reserve(n);
for (int i = 0; i < n; ++i) {
        clients.emplace_back(std::async([&woman]() { return woman.tryValentine(); }));
    }
    for (int i = 0; i < n; ++i) {
        if (clients[i].get()) {
            std::cout << "Student number " << i << " is a winner\n";
            break;
        }
    }
    return 0;
}
