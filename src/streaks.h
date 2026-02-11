#include <iostream>
#include <chrono>

struct streak {
    std::chrono::year_month_day last_completion_date;
    int streak_count = 0;

    std::chrono::year_month_day get_completion() {
        auto now = std::chrono::system_clock::now();
        auto today = std::chrono::floor<std::chrono::days>(now);
        std::chrono::year_month_day ymd{today};

        return ymd;
    }
};
