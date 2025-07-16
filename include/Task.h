#pragma once
#include <string>
#include <chrono>
#include <format>

class Task
{
public:
	Task(std::string title, std::string description, std::chrono::system_clock::time_point dueDate);

	//Getters
	const std::string& getTitle() const noexcept;
	const std::string& getDescription() const noexcept;
	std::string getDueDateString() const; //fecha formateada

	//Setters
	void setCompleted(bool completed) noexcept;
	bool isCompleted() const noexcept;

private:
	std::string title;
	std::string description;
	std::chrono::system_clock::time_point dueDate;
	bool completed{ false };
};


