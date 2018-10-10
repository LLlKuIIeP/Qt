# Проекты с использованием Qt


## qml_sort
Написать приложение, сортирующее числа, считанные из файла. Числа в файле записаны через пробел. 

Например:
«2312312 321323 42342 3123123 878462734»

Считается, что файл достаточно большой, его содержимое нельзя полностью считать в память.

Рассмотреть возможность распараллеливания алгоритма
сортировки.

Для проверки библиотеки создать GUI приложение. Приложение
должно иметь понятный и интуитивный интерфейс,
позволяющий пользователю выполнять следующие
операции:

Load File - выбрать файл (*.txt) на диске и загрузить его
Run - запустить процесс cортировки
Pause/Resume/Stop - возможность приостановить, снова
запустить, полностью остановить процесс сортировки.

При загрузке файла и сортировки приложение не должно зависать. Пользователю
должна показываться индикация прогресса.

Пользователь может в любой момент приостановить
операцию или вовсе отказаться от неё, закрыв
приложение.

Результат сортировки должен быть сохранен в другой файл, заданный пользователем. Числа записывать также через пробел.

Исходный код приложения должен быть самодостаточным.
Предполагается, что для компиляции достаточно иметь:
Qt 5.10
Visual Studio 2017



## untitled2
Результат должен быть в виде проекта, компилироваться и работать.

Необходимо:

1.заполнить случайными числами от 1 до 9 значения контейнеров
vector[i] и map[i];

2.удалить случайное число элементов (не более 15) в каждом
контейнере;

3.после этого провести синхронизацию, чтобы в vector и map
остались только имеющиеся в обоих контейнерах элементы
(дубликаты не удалять).

Ubuntu 17.10
Qt 5.11 GCC

---

pixmap - установка изображения на фон<br>
scroll - прокрутка(скролл)<br>
cursor - изменение курсора в области виджета<br>
boxLayout1 - растяжение кнопок<br>
boxLayout2 - растяжение между кнопок<br>
hboxLayout - горизонтальное размещение<br>
vhboxLayout - в вертикальном горизонтальное размещение<br>
gridLayout - табличное размещение<br>
calculator - калькулятор<br>
splitter - виджет разделительной черты<br>
labelHTML - вставка HTML текста в label<br>
labelBuddy - поле и ввод, в духе логин/пароль<br>
progress - идикатор прогресса выполнения программы<br>
buttons - варианты кнопок<br>
