#pragma once
#include <vector>
#include <filesystem>
#include "Task.h"

namespace fs = std::filesystem;

class TaskManager
{
public:
	void addTask(const Task& task);
	void listTasks() const;
	void saveToFile(const fs::path& filePath) const;
	void loadFromFile(const fs::path& filePath);

private:
	std::vector<Task> tasks;
};

TaskManager::TaskManager()
{
}

TaskManager::~TaskManager()
{
}