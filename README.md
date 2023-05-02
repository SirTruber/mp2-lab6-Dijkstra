# ЛР 6. Алгоритм Дейкстры

## Цели и задачи

__Цель работы:__ 
Разработать программу, которая позволяет осуществлять следующие действия:

1)Задания графа с весами ребер в ручном и автоматическом (случайная генерация) режиме.

2)Алгоритм Дейкстры с использованием приоритетной очереди написанной на следующий структурах данных: стандартный поиск (АВЛ-дерево, красно-черное дерево), d-куча и сложные кучи (Биномиальная куча или Фибоначчиева куча - на выбор). Распределение структур по таблицы.


__Особенности реализации:__

1. Должна быть проверка на односвязаность графа, и удволетворение условиям для Алгоритма Дейкстры.
1. Пользователь может задавать начальную точку для всего алгоритма.
1. После работы алгоритма пользователь может запросить кратчайший путь и стоимость до любой точки.
1. Пользователь может запросить вывод графа на экран, в любом удобном для вас виде.

## Используемые инструменты

  - Система контроля версий [Git](https://git-scm.com/book/ru/v2). Рекомендуется использовать один из
    следующих клиентов на выбор студента:
    - [Git](https://git-scm.com/downloads)
    - [GitHub Desktop](https://desktop.github.com)
  - Фреймворк для написания автоматических тестов [Google Test](https://github.com/google/googletest). Не
    требует установки, идет вместе с проектом-шаблоном.
    
## Общая структура проекта

Структура проекта:

  - `gtest` — библиотека Google Test.
  - `samples` — каталог с пользовательским приложением (Необходимо создать собственный файл кода).
  - `test` — каталог с проектом с модульными тестами (Необходимо создать собственные файлы с тестами).
  - `include` `src` - каталоги с основными файлами ЛР (Необходимо создать собственные файлы кода).
  - `sln` - каталог с файлами с решениями (solution) для Microsoft Visual Studio (Необходимо добавить настроенный проект).
  - `README.md` — информация о проекте, которую вы сейчас читаете.
  - Служебные файлы
    - `.gitignore` — перечень расширений файлов, игнорируемых Git при добавлении файлов в репозиторий.
