10. Реалізуйте систему обміну повідомленнями між двома процесами,
де кожне повідомлення кодується у sigval.sival_int, і процес отримує повідомлення через sigqueue.

![image](https://github.com/user-attachments/assets/39e77164-c1a1-4f64-8551-4a77e9963484)

![image](https://github.com/user-attachments/assets/71c1d86b-46bf-4027-b3e3-0634fe5a8870)

![image](https://github.com/user-attachments/assets/4445bca5-56c9-44b1-9ae1-21edd7a916eb)

Програма receiver.c реєструє обробник сигналу SIGRTMIN, який при отриманні сигналу через sigqueue виводить передане число.
На початку програма виводить свій PID, щоб інший процес міг знати, куди надсилати сигнал.
У головній функції через sigaction встановлюється обробник, який читає значення з si_value.sival_int.
Основний цикл чекає на сигнал через pause().
Коли надходить сигнал SIGRTMIN, викликається обробник, який друкує отримане повідомлення.


Програма sender.c приймає два аргументи: PID процесу-отримувача та ціле число — повідомлення. 
Вона перетворює ці значення з рядків у числа, готує структуру sigval, в яку записує передане число, 
і надсилає його процесу з вказаним PID за допомогою функції sigqueue з сигналом SIGRTMIN.
Якщо все добре то виводить повідомлення про те , що повідомлення надіслано
