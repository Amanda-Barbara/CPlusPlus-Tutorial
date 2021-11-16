//
// Created by amanda on 2021/11/16.
//

#include <barrier>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

int main() {
    const auto workers = { "anil", "busara", "carl" };

    auto on_completion = []() noexcept {
        // locking not needed here
        static auto phase = "... 123done\n" "Cleaning123 up...\n";
        std::cout << phase;
        phase = "... done\n";
    };
    std::barrier sync_point(std::ssize(workers), on_completion);

    auto work = [&](std::string name) {
        std::string product = "  " + name + " worked1\n";
        std::cout << product;  // ok, op<< call is atomic
        // sync_point.arrive_and_wait();

        product = "  " + name + " cleaned2\n";
        std::cout << product;
        // sync_point.arrive_and_wait();

        product = "  " + name + " worked3\n";
        std::cout << product;  // ok, op<< call is atomic
        // sync_point.arrive_and_wait();
        for(int i = 0; i < 1000;++i){std::string s = "1";}

    };

    std::cout << "Starting...\n";
    std::vector<std::thread> threads;
    for (auto const& worker : workers) {
        threads.emplace_back(work, worker);
    }
    for (auto& thread : threads) {
        thread.join();
    }
}