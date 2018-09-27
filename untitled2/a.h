#ifndef A_H
#define A_H

#include <vector>
#include <map>


class A
{
public:
    A() = delete;
    explicit A(size_t, size_t left = 1, size_t right = 9);  //  конструкотр для простоты инициализации
    explicit A(const A &a) = delete;                        //  обойдемся без них в этой реализации
    A & operator=(const A &a) = delete;                     //  хотя если надо можно их реализовать

    void PrintVector();                                     //  выводит вектор в ofstream(STDOUT)
    void PrintMap();                                        //  выводит map в ofstream

    void DeleteElevents();                                  //  чисто для внешнего доспута к началу процесса удаления элементов

    void Synchronize();                                     //  синхронизует контейнеры
private:
    std::vector<size_t> m_vector;
    std::map<size_t, size_t> m_map;
    size_t m_delete_elements;

    void DeleteEleventsVector();                            //  удаляет m_delete_elements из контейнера std::vector
    void DeleteEleventsMap();                               //  удаляет m_delete_elements из контейнера std::map
};

#endif // A_H
