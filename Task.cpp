#include "Task.h"
#include <format>

Task::Task(std::string title, std::string description, std::chrono::system_clock::time_point dueDate)
    : title(std::move(title)), description(std::move(description)), dueDate(dueDate) {
}

// Getters
const std::string& Task::getTitle() const noexcept { return title; }
const std::string& Task::getDescription() const noexcept { return description; }

std::string Task::getDueDateString() const {
    auto in_time_t = std::chrono::system_clock::to_time_t(dueDate);
    std::tm tm{};
    localtime_s(&tm, &in_time_t);  // Windows-safe (en Linux usa localtime_r)
    return std::format("{:%Y-%m-%d %H:%M:%S}", tm);  // C++20 <format>
}

// Setters
void Task::setCompleted(bool completed) noexcept { this->completed = completed; }
bool Task::isCompleted() const noexcept { return completed; }