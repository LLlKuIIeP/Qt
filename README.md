# Проекты с использованием Qt

Утилита Artistic Style для форматирования кода, так же можнно встроить плагин в QtCreator.<br>
Дока утилиты http://astyle.sourceforge.net/<br>
Настройка QtCreator http://doc.qt.io/qtcreator/creator-beautifier.html<br>

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
menu - простая кнопка Menu<br>
linesEdit - тоже аккаунт/пароль, аналог labelBuddy<br>
writeODF - запись в odf(open document format) файл<br>
writePDF - запись в pdf<br>
syntaxHighligher - редактор подцветки синтаксиса, главное наследование от QSyntaxHighligher<br>
spinBox - простой счетчик<br>
dateTime - простой элемент ввода даты/времени<br>
nameValidator - валидация вводимых данных пользователем<br>
palette - цветовая палитра<br>
listWidgetItem - список с растровыми изображениями<br>
listWidgetItemMode - список с растровыми изображениями в виде пиктограммы с возможностью редактирования<br>
tree - иерархический список в 2 колонки<br>
table - таблица<br>
comboBox - выпадающий список<br>
tab - вкладки в горизонтальном положении<br>
tool - вертикальные вкладки<br>
palette - простой пример палитры для виджета<br>
mouseObserver - обработчик событий мыши и клавиатуры<br>
resizeObserver - обрабочтик события изменения размера окна<br>
mouseFilter - установка фильтра(тут в примере на мышь)<br>
animationStateMachine - анимационнное переключение между состояниями(22.6)<br>
style - простой пример стилей(26.1)<br>
setStyle - установка стилей для всего приложения(26.2)<br>
styleCSS - работа со тилями через CSS(26.10)<br>
soundPlayer - воспроизведение звука(27.1)<br>
saveSettings - сохранеие настроек программы в специальном месте(28.1)<br>
contextStyle - контекстное меню(по правой кнопки мыши)(31.2)<br>
startDialog - простой собственное диалоговое окно(32.1)<br>
systemTray - иконка и меню в системном трее(35.1)<br>
screenDesktop - скрин экрана через объект экрана QDesktopWidget(35.8)<br>
