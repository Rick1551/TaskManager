#include <iostream>
#include "TaskManager.h"
#include "Utils.h"

int main() {
	TaskManager manager;
	auto tomorrow = std::chrono::system_clock::now() + std::chrono::hours(24);

	manager.addTask(Task("Comprar leche", "Ir al supermercado", tomorrow));
	manager.listTasks();
	manager.saveToFile("data/tasks.txt");

	return 0;
}