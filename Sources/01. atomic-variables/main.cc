#include <iostream>
#include <atomic>

const char* get_message_by_bool(const bool success) {
    return success ? "is_lock_free" : "is_not_lock_free";
}

constexpr int some_test() noexcept {
    return 1;
}

int main() {
    std::atomic<int> atomicInteger { 0 };
    std::cout << get_message_by_bool(atomicInteger.is_lock_free());

    atomicInteger = 1;
    std::cout << some_test();

    return 0;
}

void just_use_atomic_flag() {
    std::atomic_flag flag;

    flag.clear();  // to false
    flag.test_and_set();  // to bool with memory_ordering
}