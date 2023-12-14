#include <iostream>
#include <list>

bool isNumber(const std::string& str);
int inputNumber (int start, int finish);


int main()
{
    //std::list<int> list1;             // пустой список
    //std::list<int> list2(5);          // список list2 состоит из 5 чисел, каждый элемент имеет значение по умолчанию
    //std::list<int> list3(5, 2);           // список list3 состоит из 5 чисел, каждое число равно 2
    //std::list<int> list4{ 1, 2, 4, 5 };   // список list4 состоит из чисел 1, 2, 4, 5
    //std::list<int> list5 = { 1, 2, 3, 5 }; // список list5 состоит из чисел 1, 2, 4, 5
    //std::list<int> list6(list4);          // список list6 - копия списка list4
    //std::list<int> list7 = list4;         // список list7 - копия списка list4
    std::list<int> myList {5, 4, 1, 2, 3, 4, 5};

    while (true)
    {
        std::cout << "\nВыберите операцию:\n";
        std::cout << "1. Вставка элемента в конец (push_back)\n";
        std::cout << "2. Вставка элемента в начало (push_front)\n";
        std::cout << "3. Вставка элемента в конец (emplace_back)\n";
        std::cout << "4. Вставка элемента в начало (emplace_front)\n";
        std::cout << "5. Удаление последнего элемента (pop_back)\n";
        std::cout << "6. Удаление первого элемента (pop_front)\n";
        std::cout << "7. Изменение размера (resize)\n";
        std::cout << "8. Обмен содержимым (swap)\n";
        std::cout << "9. Слияние двух отсортированных списков (merge)\n";
        std::cout << "10. Перемещение элементов из другого списка (splice)\n";
        std::cout << "11. Удаление элементов (erase)\n";
        std::cout << "12. Удаление элементов по условию (remove_if)\n";
        std::cout << "13. Разворот порядка элементов (reverse)\n";
        std::cout << "14. Удаление последовательных дубликатов (unique)\n";
        std::cout << "15. Сортировка элементов (sort)\n";
        std::cout << "16. Вывод элементов списка\n";
        std::cout << "17. Проверка на пустоту (empty)\n";
        std::cout << "18. Получение размера списка (size)\n";
        std::cout << "19. Максимальный размер списка (max_size)\n";
        std::cout << "20. Получить первый элемент (front)\n";
        std::cout << "21. Получить последний элемент (back)\n";
        std::cout << "22. Заменить список новыми полностью элементами (assign)\n";
        std::cout << "24. Выход\n";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                std::cout << "Введите значение для вставки: ";
                int value;
                value = inputNumber(-10000, 10000);
                myList.push_back(value);
                std::cout << "Элемент добавлен в конец списка.\n";
                break;
            case 2:
                std::cout << "Введите значение для вставки в начало: ";
                value = inputNumber(-10000, 10000);
                myList.push_front(value);
                std::cout << "Элемент добавлен в начало списка.\n";
                break;
            case 3:
                std::cout << "Введите значение для вставки в конец: ";
                value = inputNumber(-10000, 10000);
                myList.emplace_back(value);
                std::cout << "Элемент добавлен в конец списка.\n";
                break;
            case 4:
                std::cout << "Введите значение для вставки в начало: ";
                value = inputNumber(-10000, 10000);
                myList.emplace_front(value);

                // emplace(pos, val) вставляет элемент val на позицию, на которую указывает итератор pos. Возвращает итератор на добавленный элемент

                std::cout << "Элемент добавлен в начало списка.\n";
                break;
            case 5:
                if (!myList.empty())
                {
                    myList.pop_back();
                    std::cout << "Последний элемент удален.\n";
                } else
                {
                    std::cout << "Список пуст.\n";
                }
                break;
            case 6:
                if (!myList.empty())
                {
                    myList.pop_front();
                    std::cout << "Первый элемент удален.\n";
                }
                else
                {
                    std::cout << "Список пуст.\n";
                }
                break;
            case 7:
                std::cout << "Введите новый размер списка: ";
                size_t newSize;
                newSize = inputNumber(1, 10000);
                myList.resize(newSize);
                //myList.resize(newSize, 5); // дополнить пятерками если мы увеличили размер
                std::cout << "Размер списка изменен.\n";
                break;
            case 8:
            {
                std::list<int> anotherList = {10, 20, 30};
                myList.swap(anotherList);
                std::cout << "Содержимое списка обменено.\n";
            }
                break;
            case 9:
            {
                std::list<int> sortedList1 = {1, 3, 5};
                std::list<int> sortedList2 = {2, 4, 6};
                sortedList1.merge(sortedList2);
                std::cout << "Два отсортированных списка объединены.\n";
            }
                break;
            case 10:
            {
                std::list<int> anotherList = {7, 8, 9};
                myList.splice(myList.begin(), anotherList);
                std::cout << "Элементы перемещены из другого списка.\n";
            }
                break;
            case 11:
                std::cout << "Введите значение для удаления: ";
                value = inputNumber(-10000, 10000);
                myList.erase(std::remove(myList.begin(), myList.end(), value), myList.end());
                std::cout << "Элементы с введенным значением удалены.\n";
                break;
            case 12:
                std::cout << "Введите предикат для удаления элементов, больше введенного: ";
                int predicate;
                predicate = inputNumber(-10000, 10000);
                myList.erase(std::remove_if(myList.begin(), myList.end(), [predicate](int x) { return x > predicate; }), myList.end());
                std::cout << "Элементы, удовлетворяющие условию, удалены.\n";
                break;
            case 13:
                myList.reverse();
                std::cout << "Порядок элементов в списке изменен на обратный.\n";
                break;
            case 14:
                myList.unique();
                std::cout << "Последовательные дубликаты удалены.\n";
                break;
            case 15:
                myList.sort();
                std::cout << "Элементы списка отсортированы.\n";
                break;
            case 16:
                if (!myList.empty())
                {
                    std::cout << "Элементы списка: ";
                    for (const auto& element : myList)
                    {
                        std::cout << element << " ";
                    }
                    std::cout << "\n";
                }
                else
                {
                    std::cout << "Список пуст.\n";
                }
                break;
            case 17:
                if (myList.empty())
                {
                    std::cout << "Список пуст.\n";
                }
                else
                {
                    std::cout << "Список не пуст.\n";
                }
                break;
            case 18:
                std::cout << "Размер списка: " << myList.size() << "\n";
                break;
            case 19:
                std::cout << "Максимальный размер списка: " << myList.max_size() << "\n";
                break;
            case 20:
                std::cout << "Первый элемент списка: " << myList.front() << "\n";
                break;
            case 21:
                std::cout << "Последний элемент списка: " << myList.back() << "\n";
                break;
            case 22:
            {
                std::list<int> newList;
                int val, sz;
                std::cout << "Введите размер нового листа:";
                sz = inputNumber(1, 100);
                for (int i = 0; i < sz; ++i)
                {
                    val = inputNumber(-10000, 10000);
                    newList.push_back(val);
                }
                myList.assign(newList.begin(), newList.end());

                //myList.assign({ 21, 22, 23, 24, 25 }); // myList = { 21, 22, 23, 24, 25 }
                //myList.assign(4, 3);                   // myList = {3, 3, 3, 3}

                std::cout << "Список обновлен новыми элементами.\n";
                break;
            }
            case 23:
            {
                int position, val;
                std::cout << "Введите позицию для вставки: ";
                std::cin >> position;
                std::cout << "Введите значение для вставки: ";
                std::cin >> val;

                auto it = myList.begin();
                std::advance(it, position);
                myList.insert(it, val);
                /*
                 insert(pos, val): вставляет элемент val на позицию, на которую
                 указывает итератор pos, аналогично функции emplace. Возвращает итератор на добавленный элемент

                insert(pos, n, val): вставляет n элементов val начиная с позиции, на которую указывает итератор pos.
                Возвращает итератор на первый добавленный элемент. Если n = 0, то возвращается итератор pos.

                insert(pos, begin, end): вставляет начиная с позиции, на которую указывает итератор pos,
                элементы из другого контейнера из диапазона между итераторами begin и end.
                Возвращает итератор на первый добавленный элемент.
                Если между итераторами begin и end нет элементов, то возвращается итератор pos.*/

                std::cout << "Элемент вставлен на позицию " << position << ".\n";
                break;
            }
            case 24:
                myList.clear();
                std::cout << "Выход из программы.\n";
                return 0;
            default:
                std::cout << "Неверный выбор. Пожалуйста, выберите снова.\n";
                break;
        }
    }
}


bool isNumber(const std::string& str)
{
    for (char i : str)
    {
        if ((i < '0' || i > '9') && i != '-')
            return false;
    }
    return true;
}

int inputNumber (int start, int finish)
{
    std::string str;
    int number;
    while (true)
    {
        std::cout << "\nВведите число - ";
        std::cin >> str;
        if (isNumber(str))
        {
            std::cin.ignore(10, '\n');
            number = atoi(str.c_str());
            if (number >= start && number <= finish)
                break;
        }
        std::cout << "\nОшибка ввода числа, введите заново";
        std::cin.ignore(10, '\n');
    }
    return number;
}




