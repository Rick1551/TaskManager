#include "TaskManager.h"
#include <fstream>
#include <iostream>
#include <format>

void TaskManager::addTask(const Task& task) {
    tasks.push_back(task);
}

void TaskManager::listTasks() const {
    for (const auto& task : tasks) {
        std::cout << std::format(
            "Título: {}\nDescripción: {}\nFecha: {}\nEstado: {}\n\n",
            task.getTitle(),
            task.getDescription(),
            task.getDueDateString(),
            task.isCompleted() ? "Completada" : "Pendiente"
        );
    }
}

void TaskManager::saveToFile(const fs::path& filePath) const {
    std::ofstream file(filePath);
    if (!file) {
        throw std::runtime_error("No se pudo abrir el archivo para escritura.");
    }

    for (const auto& task : tasks) {
        file << std::format(
            "{}\n{}\n{}\n{}\n",
            task.getTitle(),
            task.getDescription(),
            task.getDueDateString(),
            task.isCompleted()
        );
    }
}

void TaskManager::loadFromFile(const fs::path& filePath) {
    std::ifstream file(filePath);
    if (!file) {
        throw std::runtime_error("No se pudo abrir el archivo para lectura.");
    }

    tasks.clear();
    std::string title, description, dateStr;
    bool completed;

    while (std::getline(file, title) && std::getline(file, description) && std::getline(file, dateStr)) {
        file >> completed;
        file.ignore();  // Para ignorar el '\n' después del bool

        // Parsear fecha (simplificado)
        std::tm tm{};
        std::istringstream dateStream(dateStr);
        dateStream >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
        auto dueDate = std::chrono::system_clock::from_time_t(std::mktime(&tm));

        tasks.emplace_back(title, description, dueDate).setCompleted(completed);
    }
}